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



namespace ft {

    template<class Key, class T, class Compare = less <Key>, class Alloc = std::allocator <std::pair<const Key, T>>>
    class map {

    public:
        // MEMBER TYPES
        typedef Key                     key_type;
        typedef T                       mapped_type;
        typedef pair<const Key, T>      value_type;
        typedef Compare                 key_compare;
        typedef                         value_compare;
        typedef Alloc                   allocator_type;
        typedef T&                      reference;
        typedef const T&                const_reference;
        typedef T*                      pointer;
        typedef const T*                const_pointer;
//        typedef                         iterator;
//        typedef                         const_iterator;
//        typedef                         reverse_iterator;
//        typedef                         const_reverse_iterator;
        typedef std::ptrdiff_t          difference_type;
        typedef size_t                  size_type;

    protected:
        key_type        _key;
        mapped_type     _data;

    public:
        // ----------------------------------------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------
        //-> Constructs an empty container, with no elements.
        explicit map (const key_compare& comp = key_compare(),
                      const allocator_type& alloc = allocator_type()) {}

        //-> Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range.
        template <class InputIterator>
        map (InputIterator first, InputIterator last,
             const key_compare& comp = key_compare(),
             const allocator_type& alloc = allocator_type()) {}

        //-> Constructs a container with a copy of each of the elements in x.
        map (const map& x) {}

        //-> Destroys the container object.
        ~map();~map() {}

        //-> Assigns new contents to the container, replacing its current content.
        map& operator= (const map& x) {}

        // ------------------------------------------------- ITERATORS -------------------------------------------------
        //-> Returns an iterator referring to the first element in the map container.
        iterator begin() {}
        const_iterator begin() const {}

        //-> Returns an iterator referring to the past-the-end element in the map container.
        iterator end() {}
        const_iterator end() const {}

        //-> Returns a reverse iterator pointing to the last element in the container.
        reverse_iterator rbegin() {}
        const_reverse_iterator rbegin() const {}

        //-> Returns a reverse iterator pointing to the theoretical element right before the first element in the map container.
        reverse_iterator rend() {}
        const_reverse_iterator rend() const {}

        // -------------------------------------------------- CAPACITY -------------------------------------------------
        //-> Returns whether the map container is empty.
        bool empty() const {}

        //-> Returns the number of elements in the map container.
        size_type size() const {}

        //-> Returns the maximum number of elements that the map container can hold.
        size_type max_size() const {}

        // ----------------------------------------------- ELEMENT ACCESS ----------------------------------------------
        //-> If k matches the key of an element in the container, the function returns a reference to its mapped value.
        mapped_type& operator[] (const key_type& k) {}

        // ------------------------------------------------- MODIFIERS -------------------------------------------------
        //-> Extends the container by inserting new elements, effectively increasing the container size by the number of elements inserted.
        pair<iterator,bool> insert (const value_type& val) {}

        iterator insert (iterator position, const value_type& val) {}

        template <class InputIterator>
        void insert (InputIterator first, InputIterator last) {}

        //-> Removes from the map container either a single element or a range of elements ([first,last)).
        void erase (iterator position) {}

        size_type erase (const key_type& k){}

        void erase (iterator first, iterator last) {}

        //-> Exchanges the content of the container by the content of x, which is another map of the same type.
        void swap (map& x) {}

        //-> Removes all elements from the map container (which are destroyed), leaving the container with a size of 0.
        void clear() {}

        // ------------------------------------------------- OBSERVERS -------------------------------------------------
        //-> Returns a copy of the comparison object used by the container to compare keys.
        key_compare key_comp() const {}

        //-> Returns a comparison object that can be used to compare two elements to get whether the key of the first one goes before the second.
        value_compare value_comp() const {}

        // ------------------------------------------------- OPERATIONS -------------------------------------------------
        //-> Searches the container for an element with a key equivalent to k and returns an iterator to it if found, otherwise it returns an iterator to map::end.
        iterator find (const key_type& k) {}
        const_iterator find (const key_type& k) const {}

        //-> Searches the container for elements with a key equivalent to k and returns the number of matches.
        size_type count (const key_type& k) const {}

        //-> Returns an iterator pointing to the first element in the container whose key is not considered to go before k (i.e., either it is equivalent or goes after).
        iterator lower_bound (const key_type& k) {}
        const_iterator lower_bound (const key_type& k) const {}

        //-> Returns an iterator pointing to the first element in the container whose key is considered to go after k.
        iterator upper_bound (const key_type& k) {}
        const_iterator upper_bound (const key_type& k) const {}

        //-> Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k.
        pair<const_iterator,const_iterator> equal_range (const key_type& k) const {}
        pair<iterator,iterator>             equal_range (const key_type& k) {}

    };

};

#endif //FT_CONTAINERS_MAP_HPP
