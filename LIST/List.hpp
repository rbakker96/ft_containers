/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   List.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 10:38:29 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/12 10:38:29 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include <cstddef>
#include <memory>
#include <limits>

#include "Iterator.hpp"
#include "Node.hpp"
#include "../Traits.hpp"

namespace ft {

    template<class T, class Alloc = std::allocator<T> >
    class list {

    public:
        // MEMBER TYPES
        typedef T                                   value_type;
        typedef Alloc                               allocator_type;
        typedef T&                                  reference;
        typedef const T&                            const_reference;
        typedef T*                                  pointer;
        typedef const T*                            const_pointer;
        typedef Node<T>*                            node_pointer;
        typedef BidirectionalIterator<T>            iterator;
        typedef ConstBidirectionalIterator<T>       const_iterator;
        typedef RevBidirectionalIterator<T>         reverse_iterator;
        typedef ConstRevBidirectionalIterator<T>    const_reverse_iterator;
        typedef std::ptrdiff_t                      difference_type;
        typedef size_t                              size_type;

    private:
        node_pointer    _head;
        node_pointer    _tail;
        allocator_type  _allocator;
        size_type       _size;

        void relocate(iterator it_one, iterator it_two) {
            node_pointer list = it_one.get_ptr();
            node_pointer addition = it_two.get_ptr();

            addition->_prev->_next = addition->_next;
            addition->_next->_prev = addition->_prev;
            addition->_prev = list->_prev;
            addition->_next = list;

            list->_prev->_next = addition;
            list->_prev = addition;
        }

        void flip (node_pointer it) {
            node_pointer zero = it->_prev->_prev;
            node_pointer first = it->_prev;
            node_pointer second = it;
            node_pointer third = it->_next;

            zero->_next = second;
            first->_next = third;
            first->_prev = second;
            second->_next = first;
            second->_prev = zero;
            third->_prev = first;
        }

    public:
        // ----------------------------------------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------
        //-> default - Constructs an empty container, with no elements.
        explicit list(const allocator_type &alloc = allocator_type()) : _allocator(alloc), _size(0) {
            _head = new Node<value_type>();
            _tail = new Node<value_type>();
            _head->_next = _tail;
            _tail->_prev = _head;
        }

        //-> fill constructor - Constructs a container with n elements. Each element is a copy of val.
        explicit list(size_type n, const value_type &val = value_type(),
                      const allocator_type &alloc = allocator_type()) : _allocator(alloc), _size(0) {
            _head = new Node<value_type>();
            _tail = new Node<value_type>();
            _head->_next = _tail;
            _tail->_prev = _head;
            assign(n, val);
        }

        //-> range constructor - Constructs a container with as many elements as the range [first,last),
        //   with each element constructed from its corresponding element in that range, in the same order.
        template <class InputIterator>
        list (typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type& alloc = allocator_type()) : _allocator(alloc), _size(0) {
            _head = new Node<value_type>();
            _tail = new Node<value_type>();
            _head->_next = _tail;
            _tail->_prev = _head;
            assign(first, last);
        }

        //-> copy constructor - Constructs a container with a copy of each of the elements in x, in the same order.
        list(const list &x) : _size(0) {
            _head = new Node<value_type>();
            _tail = new Node<value_type>();
            _head->_next = _tail;
            _tail->_prev = _head;
            assign(x.begin(), x.end());
        }

        //-> This destroys all container elements, and deallocates all the storage capacity allocated by the list container using its allocator.
        ~list(){
            clear();
            delete _head;
            delete _tail;
        };

        //-> Assigns new contents to the container, replacing its current contents, and modifying its size accordingly.
        list& operator= (const list& x){
            clear();
            _head->_next = _tail;
            _tail->_prev = _head;
            assign(x.begin(), x.end());
            return(*this);
        };


        // ------------------------------------------------- ITERATORS -------------------------------------------------
        //-> Returns an iterator pointing to the first element in the list container.
        iterator begin(){return(iterator(_head->_next));};
        const_iterator begin() const {return(const_iterator(_head->_next));};

        //-> Returns an iterator referring to the past-the-end element in the list container.
        iterator end(){return(iterator(_tail));};
        const_iterator end() const {return(const_iterator(_tail));};

        //-> Returns a reverse iterator pointing to the last element in the container (i.e., its reverse beginning).
        reverse_iterator rbegin(){return(reverse_iterator(_tail->_prev));};
        const_reverse_iterator rbegin() const {return(const_reverse_iterator(_tail->_prev));};

        //-> Returns a reverse iterator pointing to the theoretical element preceding the first element in the list container
        //   (which is considered its reverse end).
        reverse_iterator rend(){return(reverse_iterator(_head));};
        const_reverse_iterator rend() const {return(const_reverse_iterator(_head));};


        // -------------------------------------------------- CAPACITY -------------------------------------------------
        //-> Returns whether the list container is empty (i.e. whether its size is 0).
        bool empty() const {return(_size == 0);};

        //-> Returns the number of elements in the list container.
        size_type size() const {return(_size);};

        //-> Returns the maximum number of elements that the list container can hold.
        size_type max_size() const {return((std::numeric_limits<size_type>::max() / sizeof(Node<T>)));};


        // ----------------------------------------------- ELEMENT ACCESS ----------------------------------------------
        //-> Returns a reference to the first element in the list container.
        reference front() {return(reference(_head->_next->_data));};
        const_reference front() const {return(const_reference(_head->_next->_data));};

        //-> Returns a reference to the last element in the list container.
        reference back() {return(reference(_tail->_prev->_data));};
        const_reference back() const {return(const_reference(_tail->_prev->_data));};


        // ------------------------------------------------- MODIFIERS -------------------------------------------------
        //-> The new contents are elements constructed from each of the elements in the range between first and last, in the same order.
        template <class InputIterator>
        void assign (typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last) {
            clear();
            while (*first != *last) {
                push_back(*first);
                first++;
            }
        };

        //-> The new contents are n elements, each initialized to a copy of val.
        void assign (size_type n, const value_type& val) {
            clear();
            while(n) {
                push_back(val);
                n--;
            }
        };

        //-> Inserts a new element at the beginning of the list, right before its current first element.
        //   The content of val is copied (or moved) to the inserted element.
        void push_front (const value_type& val) {
            node_pointer new_node = new Node<value_type>(val);

            new_node->_prev = _head;
            new_node->_next = _head->_next;
            _head->_next->_prev = new_node;
            _head->_next = new_node;
            _size += 1;
        };

        //-> Removes the first element in the list container, effectively reducing its size by one.
        void pop_front() {
            if (_size) {
                node_pointer old_node = _head->_next;

                _head->_next->_next->_prev = _head;
                _head->_next = _head->_next->_next;
                _size -= 1;
                delete old_node;
            }
        };

        //-> Adds a new element at the end of the list container, after its current last element.
        void push_back (const value_type& val) { //checked
            node_pointer new_node = new Node<value_type>(val);

            new_node->_next = _tail;
            _tail->_prev->_next = new_node;
            new_node->_prev = _tail->_prev;
            _tail->_prev = new_node;
            _size += 1;
        };

        //-> Removes the last element in the list container, effectively reducing the container size by one.
        void pop_back() {
            if (_size) {
                node_pointer old_node = _tail->_prev;

                _tail->_prev->_prev->_next = _tail;
                _tail->_prev = _tail->_prev->_prev;
                _size -= 1;
                delete old_node;
            }
        };

        //-> The container is extended by inserting new elements before the element at the specified position.
        iterator insert (iterator position, const value_type& val) {
            node_pointer new_node = new Node<value_type>(val);
            node_pointer pos = position.get_ptr();

            new_node->_next = pos;
            new_node->_prev = pos->_prev;
            pos->_prev->_next = new_node;
            pos->_prev = new_node;

            _size++;

            position--;
            return (position);
        };

        void insert (iterator position, size_type n, const value_type& val) {
            while (n) {
                insert(position, val);
                n--;
            }
        };

        template <class InputIterator>
        void insert (iterator position, typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first,
                     InputIterator last) {
            while (*first != *last) {
                insert(position, *first);
                first++;
            }
        };

        //-> Removes from the list container either a single element (position) or a range of elements ([first,last)).
        iterator erase (iterator position) {
            node_pointer pos = position.get_ptr();

            pos->_next->_prev = pos->_prev;
            pos->_prev->_next = pos->_next;

            _size--;
            position++;

            delete pos;
            return (position);
        };

        iterator erase (iterator first, iterator last) {
            while (*first != *last) {
                first = erase(first);
            }
            return (first);
        };

        //-> Exchanges the content of the container by the content of x, which is another list of the same type. Sizes may differ.
        void swap (list& x) {
            node_pointer temp_head = x._head;
            node_pointer temp_tail = x._tail;
            size_type temp_size = x._size;

            x._head = _head;
            x._tail = _tail;
            x._size = _size;
            _head = temp_head;
            _tail = temp_tail;
            _size = temp_size;
        };

        //-> Resizes the container so that it contains n elements.
        void resize (size_type n, value_type val = value_type()) {
            while (n > _size)
                push_back(val);
            while (n < _size)
                pop_back();
        };

        //-> Removes all elements from the list container (which are destroyed), and leaving the container with a size of 0.
        void clear() {
            while (_size) {
                pop_back();
            }
        };

        // ------------------------------------------------- OPERATIONS ------------------------------------------------
        //-> Transfers all the elements of x into the container.
        void splice (iterator position, list& x) {
            while (x.size()) {
                relocate(position, x.begin());
                _size++;
                x._size--;
            }
        };

        //-> Transfers only the element pointed by i from x into the container.
        void splice (iterator position, list& x, iterator i) {
            relocate(position, i);
            _size++;
            x._size--;
        };

        //-> Transfers the range [first,last) from x into the container.
        void splice (iterator position, list& x, iterator first, iterator last) {
            while (*first != *last) {
                iterator temp = iterator(first.get_ptr()->_next);

                relocate(position, first);

                _size++;
                x._size--;

                first = temp;
            }
        };

        //-> Removes from the container all the elements that compare equal to val.
        void remove (const value_type& val) {
            iterator first = begin();

            while (*first != *end())
            {
                if (first.get_ptr()->_data == val)
                    first = erase(first);
                else
                    first++;
            }
        };

        //-> Removes from the container all the elements for which Predicate pred returns true.
        template <class Predicate>
        void remove_if (Predicate pred) {
            iterator first = begin();

            while (*first != *end())
            {
                if (pred(*first) == true)
                    first = erase(first);
                else
                    first++;
            }
        };

        //-> Removes all but the first element from every consecutive group of equal elements in the container.
        void unique() {
            iterator first = begin();

            while (*first != *end())
            {
                if (first.get_ptr()->_data == first.get_ptr()->_next->_data)
                    first = erase(first);
                else
                    first++;
            }
        };

        //-> Takes as argument a specific comparison function that determine the "uniqueness" of an element.
        template <class BinaryPredicate>
        void unique (BinaryPredicate binary_pred) {
            iterator first = begin();

            while (*first != *end())
            {
                if (binary_pred(first.get_ptr()->_data, first.get_ptr()->_next->_data) == true)
                    first = erase(first);
                else
                    first++;
            }
        };

        //-> Merges x into the list by transferring all of its elements at their respective ordered positions
        //   into the container (both containers shall already be ordered).
        void merge (list& x) {
            splice(begin(), x);
            sort();
        };

        //-> Have the same behavior, but take a specific predicate (comp) to perform the comparison operation between elements.
        template <class Compare>
        void merge (list& x, Compare comp) {
            iterator it = end();
            it--;

            splice(it, x);
            sort(comp);
        };

        //-> Sorts the elements in the list, altering their position within the container.
        void sort() {
            iterator it = begin();

            while (*it != *end()) {
                if (it.get_ptr()->_data < it.get_ptr()->_prev->_data) {
                    flip(it.get_ptr());
                    it = begin();
                }
                else
                    it++;
            }
        };

        template <class Compare>
        void sort (Compare comp) {
            iterator it = begin();

            while (*it != *end()) {
                if (comp(it.get_ptr()->_data, it.get_ptr()->_prev->_data) == true) {
                    flip(it.get_ptr());
                    it = begin();
                }
                else
                    it++;
            }
        };

        //-> Reverses the order of the elements in the list container.
        void reverse() {
            node_pointer current = _head;
            node_pointer temp;

            while (current != NULL) {
                temp = current->_next;
                current->_next = current->_prev;
                current->_prev = temp;

                current = temp;
            }
            temp = _head;
            _head = _tail;
            _tail = temp;
        };
    };

        // -------------------------------------------- RELATION OPERATORS  --------------------------------------------
    template <class value_type, class allocator_type>
    bool operator== (const list<value_type,allocator_type>& lhs, const list<value_type,allocator_type>& rhs) {
        typename ft::list<value_type>::const_iterator it_lhs = lhs.begin();
        typename ft::list<value_type>::const_iterator it_rhs = rhs.begin();

        if (lhs.size() != rhs.size())
            return (false);
        while (*it_lhs != *lhs.end()) {
            if (*it_lhs != *it_rhs)
                return (false);
            it_lhs++;
            it_rhs++;
        }
        return (true);
    }

    template <class value_type, class allocator_type>
    bool operator!= (const list<value_type,allocator_type>& lhs, const list<value_type,allocator_type>& rhs) {return !(lhs == rhs);}

    template <class value_type, class allocator_type>
    bool operator<  (const list<value_type,allocator_type>& lhs, const list<value_type,allocator_type>& rhs) {
        return (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));}

    template <class value_type, class allocator_type>
    bool operator<= (const list<value_type,allocator_type>& lhs, const list<value_type,allocator_type>& rhs) {return !(rhs < lhs);}

    template <class value_type, class allocator_type>
    bool operator>  (const list<value_type,allocator_type>& lhs, const list<value_type,allocator_type>& rhs) {return (rhs<lhs);}

    template <class value_type, class allocator_type>
    bool operator>= (const list<value_type,allocator_type>& lhs, const list<value_type,allocator_type>& rhs) {return !(lhs < rhs);}

};
#endif //FT_CONTAINERS_LIST_HPP
