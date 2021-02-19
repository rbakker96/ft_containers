/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Map.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 10:39:03 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/12 10:39:03 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <stdio.h>

#include <algorithm>
#include <utility>
#include <cstddef>
#include <memory>
#include <limits>

#include "UTILS/mapNode.hpp"
#include "UTILS/BiDirectionalIterator.hpp"
#include "UTILS/Traits.hpp"


namespace ft {

    template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator <std::pair<const Key, T> > >
    class map {

    public:
        // MEMBER TYPES
        typedef Key                                                 key_type;
        typedef T                                                   mapped_type;
        typedef std::pair<const Key, T>                             value_type;
        typedef Compare                                             key_compare;
        typedef Alloc                                               allocator_type;
        typedef T&                                                  reference;
        typedef const T&                                            const_reference;
        typedef T*                                                  pointer;
        typedef const T*                                            const_pointer;
        typedef mapNode<value_type>*                                node_pointer;
        typedef mapNode<value_type>                                 node;
        typedef BidirectionalIterator<value_type, node>             iterator;
        typedef ConstBidirectionalIterator<value_type, node>        const_iterator;
        typedef RevBidirectionalIterator<value_type, node>          reverse_iterator;
        typedef ConstRevBidirectionalIterator<value_type, node>     const_reverse_iterator;
        typedef std::ptrdiff_t                                      difference_type;
        typedef size_t                                              size_type;

    private:
        node_pointer 	_root;
        node_pointer 	_first;
        node_pointer 	_last;
        size_type		_size;
        key_compare		_comp;
        allocator_type 	_alloc;

        void    set_boundaries() {
            node_pointer traverser = _root;
            while (traverser->_left != NULL && traverser->_left != _first)
                traverser = traverser->_left;
            _first = traverser;
            traverser = _root;
            while (traverser->_right != NULL)
                traverser = traverser->_right;
            _last = traverser->_right;
        }

        node_pointer   insert_left(const value_type& val, node_pointer position) {
            node_pointer new_leaf = new node(val);

            position->_left = new_leaf;
            new_leaf->_parent = position;
            _size++;
            set_boundaries();
            printf("firsedfst = %c\n", _first->_data.first);
            return (new_leaf);
        }


        node_pointer   insert_right(const value_type& val, node_pointer position) {
            node_pointer new_leaf = new node(val);

            position->_right = new_leaf;
            new_leaf->_parent = position;
            _size++;
            set_boundaries();
            printf("first = %c\n", _first->_data.first);
            return (new_leaf);
        }

    public:
        // ---------------------------------------------- VALUE COMPARE ------------------------------------------------

        class value_compare
        {
            friend class map;
        protected:
            Compare comp;
            value_compare (Compare c) : comp(c) {}
        public:
            typedef bool result_type;
            typedef value_type first_argument_type;
            typedef value_type second_argument_type;
            bool operator() (const value_type& x, const value_type& y) const
            {
                return comp(x.first, y.first);
            }
        };

        // ----------------------------------------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------
        //-> Constructs an empty container, with no elements.
        explicit map (const key_compare& comp = key_compare(),
                      const allocator_type& alloc = allocator_type()) : _root(NULL), _size(0), _comp(comp), _alloc(alloc) {
            _first = new node;
            _last = new node;
            _first->_parent = _last;
            _last->_parent = _first;
        }

        //-> Constructs a container with as many elements as the range [first,last), with each element constructed from its
        //   corresponding element in that range.
        template <class InputIterator>
        map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
             const allocator_type& alloc = allocator_type()) : _root(new node), _size(0), _comp(comp), _alloc(alloc) {
            insert(first, last);
            set_boundaries();
        }

        //-> Constructs a container with a copy of each of the elements in x.
//        map (const map& x) {}

        //-> Destroys the container object.
        ~map() {}

        //-> Assigns new contents to the container, replacing its current content.
        map& operator= (const map& x) {
            if (this != x) {
                this->_root = x._root;
                this->_first = x._first;
                this->_last = x._last;
                this->_size = x._size;
                this->_comp = x._comp;
                this->_alloc = x._alloc;
            }
            return (*this);
        }

        // ------------------------------------------------- ITERATORS -------------------------------------------------
        //-> Returns an iterator referring to the first element in the map container.
        iterator begin() {return iterator(_first->_parent);}
        const_iterator begin() const {return const_iterator(_first->_parent);}

        //-> Returns an iterator referring to the past-the-end element in the map container.
        iterator end() {return iterator(_last);}
        const_iterator end() const {return iterator(_last);}

        //-> Returns a reverse iterator pointing to the last element in the container.
        reverse_iterator rbegin() {}
        const_reverse_iterator rbegin() const {}

        //-> Returns a reverse iterator pointing to the theoretical element right before the first element in the map container.
        reverse_iterator rend() {}
        const_reverse_iterator rend() const {}

        // -------------------------------------------------- CAPACITY -------------------------------------------------
        //-> Returns whether the map container is empty.
        bool empty() const {return (_size == 0);}

        //-> Returns the number of elements in the map container.
        size_type size() const {return (_size);}

        //-> Returns the maximum number of elements that the map container can hold.
        size_type max_size() const {}

        // ----------------------------------------------- ELEMENT ACCESS ----------------------------------------------
        //-> If k matches the key of an element in the container, the function returns a reference to its mapped value.
        mapped_type& operator[] (const key_type& k) {
           return ((*((this->insert(std::make_pair(k,mapped_type()))).first)).second);
        }

        // ------------------------------------------------- MODIFIERS -------------------------------------------------
        //-> Extends the container by inserting new elements, effectively increasing the container size by the number of elements inserted.
        std::pair<iterator,bool> insert (const value_type& val) {
            node_pointer traverser = _root;
            if (_size == 0) {
                _root = new node(val);
                _root->_left = _first;
                _root->_right = _last;

                _first->_parent = _root;
                _last->_parent = _root;

                _size++;
//                set_boundaries();
                return (std::make_pair(iterator(_root), true));
            }
            while (traverser->_left || traverser->_right) {
                if (traverser->_data.first == val.first)
                    return (std::make_pair(iterator(traverser), false));
                if (value_compare(_comp)(traverser->_data, val)) {
                    if (traverser->_left != NULL)
                        traverser = traverser->_left;
                    else
                        break ;
                }
                else {
                    if (traverser->_right != NULL)
                        traverser = traverser->_right;
                    else
                        break ;
                }
            }
            if (!value_compare(_comp)(traverser->_data, val))
                traverser = insert_left(val, traverser);
            else
                traverser = insert_right(val, traverser);
            return (std::make_pair(iterator(traverser), true));
        }

//        iterator insert (iterator position, const value_type& val) {}
//
//        template <class InputIterator>
//        void insert (InputIterator first, InputIterator last) {}

        //-> Removes from the map container either a single element or a range of elements ([first,last)).
//        void erase (iterator position) {}

//        size_type erase (const key_type& k){}

//        void erase (iterator first, iterator last) {}

        //-> Exchanges the content of the container by the content of x, which is another map of the same type.
//        void swap (map& x) {}

        //-> Removes all elements from the map container (which are destroyed), leaving the container with a size of 0.
        void clear() {}

        // ------------------------------------------------- OBSERVERS -------------------------------------------------
        //-> Returns a copy of the comparison object used by the container to compare keys.
//        key_compare key_comp() const {}

        //-> Returns a comparison object that can be used to compare two elements to get whether the key of the first one goes before the second.
//        value_compare value_comp() const {}

        // ------------------------------------------------- OPERATIONS -------------------------------------------------
        //-> Searches the container for an element with a key equivalent to k and returns an iterator to it if found, otherwise it returns an iterator to map::end.
//        iterator find (const key_type& k) {}
//        const_iterator find (const key_type& k) const {}

        //-> Searches the container for elements with a key equivalent to k and returns the number of matches.
//        size_type count (const key_type& k) const {}

        //-> Returns an iterator pointing to the first element in the container whose key is not considered to go before k (i.e., either it is equivalent or goes after).
//        iterator lower_bound (const key_type& k) {}
//        const_iterator lower_bound (const key_type& k) const {}

        //-> Returns an iterator pointing to the first element in the container whose key is considered to go after k.
//        iterator upper_bound (const key_type& k) {}
//        const_iterator upper_bound (const key_type& k) const {}

        //-> Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k.
//        std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const {}
//        std::pair<iterator,iterator>             equal_range (const key_type& k) {}

    };

};

#endif //FT_CONTAINERS_MAP_HPP
