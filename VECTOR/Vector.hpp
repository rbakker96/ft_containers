/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 10:38:49 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/12 10:38:49 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <memory>
#include <limits>

#include "../UTILS/RandomAccesIterator.hpp"
#include "../UTILS/Traits.hpp"

namespace ft {

    template<class T, class Alloc = std::allocator<T> >
    class vector {

    public:
        // MEMBER TYPES
        typedef T                                   value_type;
        typedef Alloc                               allocator_type;
        typedef T&                                  reference;
        typedef const T&                            const_reference;
        typedef T*                                  pointer;
        typedef const T*                            const_pointer;
        typedef RandomAccesIterator<T>              iterator;
        typedef ConstRandomAccesIterator<T>         const_iterator;
        typedef RevRandomAccesIterator<T>           reverse_iterator;
        typedef ConstRevRandomAccesIterator<T>      const_reverse_iterator;
        typedef std::ptrdiff_t                      difference_type;
        typedef size_t                              size_type;

    private:
        pointer         _array;
        allocator_type  _allocator;
        size_type       _used;
        size_type       _capacity;

        void reallocation(size_type size)
        {
            pointer temp = new value_type[size];
            for (size_type i = 0; i < _used; i++)
                temp[i] = _array[i];
            _capacity = size;
            delete[] _array;
            _array = temp;
        }

    public:
        // ----------------------------------------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------
        //-> Constructs an empty container, with no elements.
        explicit vector (const allocator_type& alloc = allocator_type()) : _array(NULL), _allocator(alloc), _used(0), _capacity(0) {};

        //-> Constructs a container with n elements. Each element is a copy of val.
        explicit vector (size_type n, const value_type& val = value_type(),
                         const allocator_type& alloc = allocator_type()) : _allocator(alloc), _used(0), _capacity(n) {
            _array = new value_type[n];
            assign(n, val);
        };

        //-> Constructs a container with as many elements as the range [first,last), with each element
        //   constructed from its corresponding element in that range, in the same order.
        template <class InputIterator>
        vector (typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last,
                const allocator_type& alloc = allocator_type()) : _allocator(alloc), _used(0), _capacity(0) {
            assign(first, last);
        };

        //-> Constructs a container with a copy of each of the elements in x, in the same order.
        vector (const vector& x) : _allocator(x._allocator), _used(0), _capacity(x._capacity) {
            _array = new value_type[x._capacity];
            assign(x.begin(), x.end());
        };

        //-> Destroys the container object.
        ~vector() {clear();};

        //-> Assigns new contents to the container, replacing its current contents, and modifying its size accordingly.
        vector& operator= (const vector& x) {
            clear();
            _array = new value_type[x._capacity];
            _allocator = x._allocator;
            _used = 0;
            _capacity = x._capacity;
            assign(x.begin(), x.end());
            return (*this);
        };

        // ------------------------------------------------- ITERATORS -------------------------------------------------
        //-> Returns an iterator pointing to the first element in the vector.
        iterator begin() {return iterator(_array);};
        const_iterator begin() const {return const_iterator(_array);};

        //-> Returns an iterator referring to the past-the-end element in the vector container.
        //iterator end() {return iterator(&_array[_used]);};
        iterator end() {return iterator(&_array[_used]);};
        const_iterator end() const {return const_iterator(&_array[_used]);};

        //-> Returns a reverse iterator pointing to the last element in the vector.
        reverse_iterator rbegin() {return reverse_iterator(&_array[_used - 1]);};
        const_reverse_iterator rbegin() const {return const_reverse_iterator (&_array[_used - 1]);};

        //-> Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector.
        reverse_iterator rend() {return reverse_iterator(_array - 1);};
        const_reverse_iterator rend() const {return const_reverse_iterator (_array - 1);};


        // -------------------------------------------------- CAPACITY -------------------------------------------------
        //-> Returns the number of elements in the vector.
        size_type size() const {return (_used);};

        //-> Returns the maximum number of elements that the vector can hold.
        size_type max_size() const {return((std::numeric_limits<size_type>::max() / sizeof(value_type)));};

        //-> Resizes the container so that it contains n elements.
        void resize (size_type n, value_type val = value_type()) {
            if (n < _used)
                _used -= (_used - n);
            while (n > _used)
                push_back(val);
        };

        //-> Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
        size_type capacity() const { return (_capacity);};

        //-> Returns whether the vector is empty
        bool empty() const {return (_used == 0);};

        //-> Requests that the vector capacity be at least enough to contain n elements.
        void reserve (size_type n) {
            if (n > _capacity)
                reallocation(n);
        };

        //-> Requests the container to reduce its capacity to fit its size.
        void shrink_to_fit() {
            if (_capacity > _used)
                reallocation(_used);
        };


        // ----------------------------------------------- ELEMENT ACCESS ----------------------------------------------
        //-> Returns a reference to the element at position n in the vector container.
        reference operator[] (size_type n) {return reference(_array[n]);};

        const_reference operator[] (size_type n) const {return const_reference(_array[n]);};

        //-> Returns a reference to the element at position n in the vector.
        reference at (size_type n) {return reference(_array[n]);};
        const_reference at (size_type n) const {return const_reference(_array[n]);};

        //-> Returns a reference to the first element in the vector.
        reference front() {return reference(_array[0]);};
        const_reference front() const {return const_reference(_array[0]);};

        //-> Returns a reference to the last element in the vector.
        reference back() {return reference(_array[_used - 1]);};
        const_reference back() const {return const_reference(_array[_used - 1]);};


        // ------------------------------------------------- MODIFIERS -------------------------------------------------
        //->  the new contents are elements constructed from each of the elements in the range between first and
        //    last, in the same order.
        template <class InputIterator>
        void assign (typename enable_if<is_input_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last) {
            clear();
            while (*first != *last) {
                push_back(*first);
                first++;
            }
        };

        //-> the new contents are n elements, each initialized to a copy of val.
        void assign (size_type n, const value_type& val) {
            clear();
            for (size_type i = 0; i < n; i++)
                push_back(val);
        };

        //-> Adds a new element at the end of the vector, after its current last element.
        void push_back (const value_type& val) {
            if (_capacity == 0){
                _array = new value_type [1];
                _capacity = 1;
            }
            else if (_capacity == _used)
                reallocation((2*_capacity));
            _array[_used] = val;
            _used += 1;
        };

        //-> Removes the last element in the vector, effectively reducing the container size by one.
        void pop_back() {
            _used--;
        };

        //->The vector is extended by inserting new elements before the element at the specified position.
//        iterator insert (iterator position, const value_type& val) {
//            size_type i = 0;
//
//            if (_capacity == _used)
//                reallocation(_capacity + 1);
//            pointer temp =  _array;
//
//            while(_array[i] != *position)
//                i++;
//
//
//
//            for (size_type i = 0; i < _used; i++)
//                temp[i] = _array[i];
//            _capacity = size;
//            delete[] _array;
//            _array = temp;
//        };

//        void insert (iterator position, size_type n, const value_type& val) {};

//        template <class InputIterator>
//        void insert (iterator position, InputIterator first, InputIterator last) {};

        //-> Removes from the vector either a single element (position) or a range of elements ([first,last)).
//        iterator erase (iterator position) {};

//        iterator erase (iterator first, iterator last) {};

        //-> Exchanges the content of the container by the content of x, which is another vector object of the same type.
        //   Sizes may differ.
//        void swap (vector& x) {};

//        //-> Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
        void clear() {
            if(_capacity) {
                delete[] _array;
                _array = NULL;
                _used = 0;
                _capacity = 0;
            }
        };

    };


    // -------------------------------------------- RELATION OPERATORS  --------------------------------------------
//    template <class T, class Alloc>
//    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

//    template <class T, class Alloc>
//    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

//    template <class T, class Alloc>
//    bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

//    template <class T, class Alloc>
//    bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

//    template <class T, class Alloc>
//    bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

//    template <class T, class Alloc>
//    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

};

#endif //FT_CONTAINERS_VECTOR_HPP
