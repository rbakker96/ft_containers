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
//        typedef ConstBidirectionalIterator<T>       const_iterator;
//        typedef RevBidirectionalIterator<T>         reverse_iterator;
//        typedef ConstRevBidirectionalIterator<T>    const_reverse_iterator;
        typedef std::ptrdiff_t                      difference_type;
        typedef size_t                              size_type;

    private:
        pointer         _array;
        allocator_type  _allocator;
        size_type       _used;
        size_type       _capacity;

    public:
        // ----------------------------------------- CONSTRUCTOR / DESTRUCTOR ------------------------------------------
        //-> Constructs an empty container, with no elements.
        explicit vector (const allocator_type& alloc = allocator_type()) : _allocator(alloc), _used(0), _capacity(1) {
            _array = new value_type[1];
        };

        //-> Constructs a container with n elements. Each element is a copy of val.
//        explicit vector (size_type n, const value_type& val = value_type(),
//                         const allocator_type& alloc = allocator_type()) : _allocator(alloc), _used(0), _capacity(n) {
//            _array = new value_type[n];
//            //assign(n, val)
//        };

        //-> Constructs a container with as many elements as the range [first,last), with each element
        //   constructed from its corresponding element in that range, in the same order.
//        template <class InputIterator>
//        vector (InputIterator first, InputIterator last,
//                const allocator_type& alloc = allocator_type()) : _allocator(alloc), _used(0), _capacity(1) {
//            _array = new value_type[1];
//            //assign(first, last);
//        };

        //-> Constructs a container with a copy of each of the elements in x, in the same order.
//        vector (const vector& x) : _allocator(x._allocator), _used(x._used), _capacity(x._capacity) {
//            _array = new value_type[x._capacity];
            //assign(x.begin(), x.end())
//        };

        //-> Destructor
        ~vector() {};

        //-> Assignment operator
//        vector& operator= (const vector& x) {};

        // ------------------------------------------------- ITERATORS -------------------------------------------------
        //-> Returns an iterator pointing to the first element in the vector.
        iterator begin() {return iterator(_array);};
//        const_iterator begin() const {};

        //-> Returns an iterator referring to the past-the-end element in the vector container.
        iterator end() {return iterator(&_array[_used]);};
//        const_iterator end() const {};

        //-> Returns a reverse iterator pointing to the last element in the vector.
//        reverse_iterator rbegin() {};
//        const_reverse_iterator rbegin() const {};

        //-> Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector.
//        reverse_iterator rend() {};
//        const_reverse_iterator rend() const {};


        // -------------------------------------------------- CAPACITY -------------------------------------------------
        //-> Returns the number of elements in the vector.
        size_type size() const {return (_used);};

//        //-> Returns the maximum number of elements that the vector can hold.
//        size_type max_size() const {};
//
//        //-> Resizes the container so that it contains n elements.
//        void resize (size_type n, value_type val = value_type()) {};
//
//        //-> Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
        size_type capacity() const { return (_array + _used);};

//        //-> Returns whether the vector is empty
//        bool empty() const {};
//
//        //-> Requests that the vector capacity be at least enough to contain n elements.
//        void reserve (size_type n) {};
//
//        //-> Requests the container to reduce its capacity to fit its size.
//        void shrink_to_fit() {};


        // ----------------------------------------------- ELEMENT ACCESS ----------------------------------------------
        //-> Returns a reference to the element at position n in the vector container.
//        reference operator[] (size_type n) {};
//        const_reference operator[] (size_type n) const {};
//
//        //-> Returns a reference to the element at position n in the vector.
//        reference at (size_type n) {};
//        const_reference at (size_type n) const {};
//
//        //-> Returns a reference to the first element in the vector.
//        reference front() {};
//        const_reference front() const {};
//
//        //-> Returns a reference to the last element in the vector.
//        reference back() {};
//        const_reference back() const {};


        // ------------------------------------------------- MODIFIERS -------------------------------------------------
        //->  the new contents are elements constructed from each of the elements in the range between first and
        //    last, in the same order.
//        template <class InputIterator>
//        void assign (InputIterator first, InputIterator last) {};
//
//        //-> the new contents are n elements, each initialized to a copy of val.
//        void assign (size_type n, const value_type& val) {};

        //-> Adds a new element at the end of the vector, after its current last element.
        void push_back (const value_type& val) {
            if (_capacity == _used) {
                pointer temp = new value_type[2 * _capacity];
                for (size_type i = 0; i < _used; i++)
                    temp[i] = _array[i];
                _capacity *= 2;
                delete[] _array;
                _array = temp;
            }
            _array[_used] = val;
            _used += 1;
        };

//        //-> Removes the last element in the vector, effectively reducing the container size by one.
//        void pop_back() {};
//
//        //->The vector is extended by inserting new elements before the element at the specified position.
//        iterator insert (iterator position, const value_type& val) {};
//
//        void insert (iterator position, size_type n, const value_type& val) {};
//
//        template <class InputIterator>
//        void insert (iterator position, InputIterator first, InputIterator last) {};
//
//        //-> Removes from the vector either a single element (position) or a range of elements ([first,last)).
//        iterator erase (iterator position) {};
//
//        iterator erase (iterator first, iterator last) {};
//
//        //-> Exchanges the content of the container by the content of x, which is another vector object of the same type.
//        //   Sizes may differ.
//        void swap (vector& x) {};
//
//        //-> Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
//        void clear() {};
//
    };


    // -------------------------------------------- RELATION OPERATORS  --------------------------------------------
//    template <class T, class Alloc>
//    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
//
//    template <class T, class Alloc>
//    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
//
//    template <class T, class Alloc>
//    bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
//
//    template <class T, class Alloc>
//    bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
//
//    template <class T, class Alloc>
//    bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
//
//    template <class T, class Alloc>
//    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

};
#endif //FT_CONTAINERS_VECTOR_HPP
