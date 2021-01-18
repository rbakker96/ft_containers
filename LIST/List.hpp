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

#include "iterator.hpp"

namespace ft {

    template <typename T>
    class Node {

    public:
        Node    *_prev;
        Node    *_next;
        T       _data;

        explicit Node() : _prev(NULL), _next(NULL), _data(0) {};
        explicit Node(T data) : _prev(NULL), _next(NULL), _data(data){};
        virtual ~Node(){};

        Node 		&operator=(Node const &rhs) {
            if (this != rhs)
            {
                this->_prev = rhs._prev;
                this->_next = rhs._next;
                this->_data = rhs._data;
            }
            return (*this);
        };

        Node* getNext() {return (this->_next);};
        Node* getPrev() {return (this->_prev);};
    };


    template<class T, class Alloc = std::allocator<T> >
    class list {

    public:
        // MEMBER TYPES
        typedef T                           value_type;
        typedef Alloc                       allocator_type;
        typedef T                           &reference;
        typedef const T                     &const_reference;
        typedef T                           *pointer;
        typedef const T                     *const_pointer;
        typedef Node<T>                     *node_pointer;
        typedef BidirectionalIterator<T>    iterator;
        //  typedef                         const_iterator;
        //  typedef                         reverse_iterator;
        //  typedef                         const_reverse_iterator;
        typedef ptrdiff_t                   difference_type;
        typedef size_t                      size_type;

    private:
        node_pointer    _head;
        node_pointer    _tail;
        size_type       _size;
        allocator_type  _allocator;

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
        list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _allocator(alloc), _size(0) {
            _head = new Node<value_type>();
            _tail = new Node<value_type>();
            _head->_next = _tail;
            _tail->_prev = _head;
            assign(first, last);
        }

        //-> copy constructor - Constructs a container with a copy of each of the elements in x, in the same order.
        list(const list &x) {
            _head = new Node<value_type>();
            _tail = new Node<value_type>();
            _head->_next = _tail;
            _tail->_prev = _head;
            assign(first, last);
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
            //assign(x.begin(), x.end()) pass begin and end itterator
        };


        // ------------------------------------------------- ITERATORS -------------------------------------------------
//        //-> Returns an iterator pointing to the first element in the list container.
//        iterator begin(){};
//        const_iterator begin() const {};
//
//        //-> Returns an iterator referring to the past-the-end element in the list container.
//        iterator end(){};
//        const_iterator end() const {};
//
//        //-> Returns a reverse iterator pointing to the last element in the container (i.e., its reverse beginning).
//        reverse_iterator rbegin(){};
//        const_reverse_iterator rbegin() const {};
//
//        //-> Returns a reverse iterator pointing to the theoretical element preceding the first element in the list container
//        //   (which is considered its reverse end).
//        reverse_iterator rend(){};
//        const_reverse_iterator rend() const {};
//
//        //-> Returns a const_iterator pointing to the first element in the container.
//        const_iterator cbegin() const noexcept {};
//
//        //-> Returns a const_iterator pointing to the past-the-end element in the container.
//        const_iterator cend() const noexcept {};
//
//        //-> Returns a const_reverse_iterator pointing to the last element in the container (i.e., its reverse beginning).
//        const_reverse_iterator crbegin() const noexcept {};
//
//        //-> Returns a const_reverse_iterator pointing to the theoretical element preceding the first element in the container.
//        const_reverse_iterator crend() const noexcept {};


        // -------------------------------------------------- CAPACITY -------------------------------------------------
        //-> Returns whether the list container is empty (i.e. whether its size is 0).
        bool empty() const {return(_size == 0);};

        //-> Returns the number of elements in the list container.
        size_type size() const {return(_size);};

        //-> Returns the maximum number of elements that the list container can hold.
        size_type max_size() const {return(std::numeric_limits<T>::max());};


        // ----------------------------------------------- ELEMENT ACCESS ----------------------------------------------
        //-> Returns a reference to the first element in the list container.
        reference front() {};
        const_reference front() const {};

        //-> Returns a reference to the last element in the list container.
        reference back() {};
        const_reference back() const {};


        // ------------------------------------------------- MODIFIERS -------------------------------------------------
        //-> The new contents are elements constructed from each of the elements in the range between first and last, in the same order.
        template <class InputIterator>
        void assign (InputIterator first, InputIterator last) {
            clear();
            while (first != last) {
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
        void push_back (const value_type& val) {
            node_pointer new_node = new Node<value_type>(val);

            new_node->_next = _tail;
            new_node->_prev = _tail->_prev;
            _tail->_prev->_next = new_node;
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

//        //-> The container is extended by inserting new elements before the element at the specified position.
//        iterator insert (iterator position, const value_type& val) {};
//        void insert (iterator position, size_type n, const value_type& val) {};
//        template <class InputIterator>
//        void insert (iterator position, InputIterator first, InputIterator last) {};
//
//        //-> Removes from the list container either a single element (position) or a range of elements ([first,last)).
//        iterator erase (iterator position) {};
//        iterator erase (iterator first, iterator last) {};

        //-> Exchanges the content of the container by the content of x, which is another list of the same type. Sizes may differ.
        void swap (list& x) {};

        //-> Resizes the container so that it contains n elements.
        void resize (size_type n, value_type val = value_type()) {};

        //-> Removes all elements from the list container (which are destroyed), and leaving the container with a size of 0.
        void clear() {
            while (_size) {
                pop_back();
            }
        };

        // ------------------------------------------------- OPERATIONS ------------------------------------------------
//        //-> Transfers all the elements of x into the container.
//        void splice (iterator position, list& x) {};
//
//        //-> Transfers only the element pointed by i from x into the container.
//        void splice (iterator position, list& x, iterator i) {};
//
//        //-> Transfers the range [first,last) from x into the container.
//        void splice (iterator position, list& x, iterator first, iterator last) {};

        //-> Removes from the container all the elements that compare equal to val.
        void remove (const value_type& val) {};

        //-> Removes from the container all the elements for which Predicate pred returns true.
        template <class Predicate>
        void remove_if (Predicate pred) {};

        //-> Removes all but the first element from every consecutive group of equal elements in the container.
        void unique() {};

        //-> Takes as argument a specific comparison function that determine the "uniqueness" of an element.
        template <class BinaryPredicate>
        void unique (BinaryPredicate binary_pred) {};

        //-> Merges x into the list by transferring all of its elements at their respective ordered positions
        //   into the container (both containers shall already be ordered).
        void merge (list& x) {};

        //-> Have the same behavior, but take a specific predicate (comp) to perform the comparison operation between elements.
        template <class Compare>
        void merge (list& x, Compare comp) {};

        //-> Sorts the elements in the list, altering their position within the container.
        void sort() {};
        template <class Compare>
        void sort (Compare comp) {};

        //-> Reverses the order of the elements in the list container.
        void reverse() {};

        // -------------------------------------------- RELATION OPERATORS  --------------------------------------------
//        template <class T, class Alloc>
//        bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {};
//
//        template <class T, class Alloc>
//        bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {};
//
//        template <class T, class Alloc>
//        bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {};
//
//        template <class T, class Alloc>
//        bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {};
//
//        template <class T, class Alloc>
//        bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {};
//
//        template <class T, class Alloc>
//        bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {};

    };
};
#endif //FT_CONTAINERS_LIST_HPP
