/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BidirectionalIterator.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 15:48:28 by roybakker     #+#    #+#                 */
/*   Updated: 2021/02/02 15:48:28 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "../LIST/Node.hpp"

namespace ft {

    template<typename T>
    class BidirectionalIterator {

    public:
        // MEMBER TYPES
        typedef std::bidirectional_iterator_tag     iterator_category;
        typedef Node<T>                             *iterator_type;
        typedef T                                   value_type;
        typedef std::ptrdiff_t                      difference_type;
        typedef T                                   *pointer;
        typedef T                                   &reference;

    private:
        iterator_type                               _ptr;

    public:
        // MEMBER FUNCTIONS
        // ----------------------------------------- CONSTRUCTOR / DESTRUCTOR -----------------------------------------
        BidirectionalIterator() : _ptr(NULL) {};
        explicit BidirectionalIterator (iterator_type it) : _ptr(it) {};
        BidirectionalIterator (const BidirectionalIterator<T>& it) {*this = it;};
        BidirectionalIterator & operator=(const BidirectionalIterator& rhs) {
            if (this != &rhs)
                _ptr = rhs._ptr;
            return (*this);
        };

        ~BidirectionalIterator() {};

        // --------------------------------------------- * OPERATOR ---------------------------------------------------
        reference operator*() {return(_ptr->_data);};

        // --------------------------------------------- -> OPERATOR ---------------------------------------------------
        pointer operator->() {return(&_ptr->_data);};

        // --------------------------------------------- ++ OPERATOR ---------------------------------------------------
        BidirectionalIterator& operator++() { //prefix
            _ptr = _ptr->_next;
            return (*this);
        };

        BidirectionalIterator  operator++(int) { //postfix
            BidirectionalIterator<T> temp(*this);

            _ptr = _ptr->_next;
            return (temp);
        };

        // --------------------------------------------- -- OPERATOR ---------------------------------------------------
        BidirectionalIterator& operator--() {
            _ptr = _ptr->_prev;
            return (*this);
        };

        BidirectionalIterator  operator--(int) {
            BidirectionalIterator<T> temp(*this);

            _ptr = _ptr->_prev;
            return (temp);
        };

        // ----------------------------------------- RELATIONAL OPERATORS  ---------------------------------------------
        bool operator== (const BidirectionalIterator<value_type>& rhs) {
            return (_ptr == rhs._ptr);
        };

        template <class Iterator>
        bool operator!= (const BidirectionalIterator<value_type>& rhs) {
            return (_ptr != rhs._ptr);
        };

        // -----------------------------------------------  GETTER  ---------------------------------------------------
        const iterator_type&   get_ptr() const {return (_ptr);};
    };


    template<typename T>
    class ConstBidirectionalIterator {

    public:
        // MEMBER TYPES
        typedef std::bidirectional_iterator_tag     iterator_category;
        typedef Node<T>                             *iterator_type;
        typedef T                                   value_type;
        typedef std::ptrdiff_t                      difference_type;
        typedef  T                                  *pointer;
        typedef  T                                  &reference;
        typedef const T                             *const_pointer;
        typedef const T                             &const_reference;

    private:
        iterator_type                               _ptr;

    public:
        // MEMBER FUNCTIONS
        // ----------------------------------------- CONSTRUCTOR / DESTRUCTOR -----------------------------------------
        ConstBidirectionalIterator() : _ptr(NULL) {};
        explicit ConstBidirectionalIterator (iterator_type it) : _ptr(it) {};
        ConstBidirectionalIterator (const ConstBidirectionalIterator<T>& it) {*this = it;};
        ConstBidirectionalIterator (const BidirectionalIterator<T>& it) {_ptr = it.get_ptr();};
        const ConstBidirectionalIterator& operator=(const ConstBidirectionalIterator& rhs) {
            if (this != &rhs)
                _ptr = rhs._ptr;
            return (*this);
        };

        ~ConstBidirectionalIterator() {};

        // --------------------------------------------- * OPERATOR ---------------------------------------------------
        const_reference operator*() {return(_ptr->_data);};

        // --------------------------------------------- -> OPERATOR ---------------------------------------------------
        const_pointer operator->() {return(&_ptr->_data);};

        // --------------------------------------------- ++ OPERATOR ---------------------------------------------------
        ConstBidirectionalIterator& operator++() { //prefix
            _ptr = _ptr->_next;
            return (*this);
        };

        ConstBidirectionalIterator  operator++(int) { //postfix
            ConstBidirectionalIterator<T> temp(*this);

            _ptr = _ptr->_next;
            return (temp);
        };

        // --------------------------------------------- -- OPERATOR ---------------------------------------------------
        ConstBidirectionalIterator& operator--() {
            _ptr = _ptr->_prev;
            return (*this);
        };

        ConstBidirectionalIterator  operator--(int) {
            ConstBidirectionalIterator<T> temp(*this);

            _ptr = _ptr->_prev;
            return (temp);
        };

        // ----------------------------------------- RELATIONAL OPERATORS  ---------------------------------------------
        bool operator== (const ConstBidirectionalIterator<value_type>& rhs) {
            return (_ptr == rhs._ptr);
        };

        bool operator!= (const ConstBidirectionalIterator<value_type>& rhs) {
            return (_ptr != rhs._ptr);
        };

    };


    template<typename T>
    class RevBidirectionalIterator {

    public:
        // MEMBER TYPES
        typedef std::bidirectional_iterator_tag     iterator_category;
        typedef Node<T>                             *iterator_type;
        typedef T                                   value_type;
        typedef std::ptrdiff_t                      difference_type;
        typedef T                                   *pointer;
        typedef T                                   &reference;

    private:
        iterator_type                               _ptr;

    public:
        // MEMBER FUNCTIONS
        // ----------------------------------------- CONSTRUCTOR / DESTRUCTOR -----------------------------------------
        RevBidirectionalIterator() : _ptr(NULL) {};
        explicit RevBidirectionalIterator (iterator_type it) : _ptr(it) {};
        RevBidirectionalIterator (const RevBidirectionalIterator<T>& it) {*this = it;};
        RevBidirectionalIterator & operator=(const RevBidirectionalIterator& rhs) {
            if (this != &rhs)
                _ptr = rhs._ptr;
            return (*this);
        };

        ~RevBidirectionalIterator() {};

        // --------------------------------------------- * OPERATOR ---------------------------------------------------
        reference operator*() {return(_ptr->_data);};

        // --------------------------------------------- -> OPERATOR ---------------------------------------------------
        pointer operator->() {return(&_ptr->_data);};

        // --------------------------------------------- ++ OPERATOR ---------------------------------------------------
        RevBidirectionalIterator& operator++() { //prefix
            _ptr = _ptr->_prev;
            return (*this);
        };

        RevBidirectionalIterator  operator++(int) { //postfix
            RevBidirectionalIterator<T> temp(*this);

            _ptr = _ptr->_prev;
            return (temp);
        };

        // --------------------------------------------- -- OPERATOR ---------------------------------------------------
        RevBidirectionalIterator& operator--() {
            _ptr = _ptr->_next;
            return (*this);
        };

        RevBidirectionalIterator  operator--(int) {
            RevBidirectionalIterator<T> temp(*this);

            _ptr = _ptr->_next;
            return (temp);
        };

        // ----------------------------------------- RELATIONAL OPERATORS  ---------------------------------------------
        bool operator== (const RevBidirectionalIterator<value_type>& rhs) {
            return (_ptr == rhs._ptr);
        };

        template <class Iterator>
        bool operator!= (const RevBidirectionalIterator<value_type>& rhs) {
            return (_ptr != rhs._ptr);
        };

        // -----------------------------------------------  GETTER  ---------------------------------------------------
        const iterator_type&   get_ptr() const {return(_ptr);};
    };

    template<typename T>
    class ConstRevBidirectionalIterator {

    public:
        // MEMBER TYPES
        typedef std::bidirectional_iterator_tag     iterator_category;
        typedef Node<T>                             *iterator_type;
        typedef T                                   value_type;
        typedef std::ptrdiff_t                      difference_type;
        typedef T                                   *pointer;
        typedef T                                   &reference;
        typedef const T                             *const_pointer;
        typedef const T                             &const_reference;

    private:
        iterator_type                               _ptr;

    public:
        // MEMBER FUNCTIONS
        // ----------------------------------------- CONSTRUCTOR / DESTRUCTOR -----------------------------------------
        ConstRevBidirectionalIterator() : _ptr(NULL) {};
        explicit ConstRevBidirectionalIterator (iterator_type it) : _ptr(it) {};
        ConstRevBidirectionalIterator (const ConstRevBidirectionalIterator<T>& it) {*this = it;};
        ConstRevBidirectionalIterator (const RevBidirectionalIterator<T>& it) {_ptr = it.get_ptr();};
        ConstRevBidirectionalIterator & operator=(const ConstRevBidirectionalIterator& rhs) {
            if (this != &rhs)
                _ptr = rhs._ptr;
            return (*this);
        };

        ~ConstRevBidirectionalIterator() {};

        // --------------------------------------------- * OPERATOR ---------------------------------------------------
        const_reference operator*() {return(_ptr->_data);};

        // --------------------------------------------- -> OPERATOR ---------------------------------------------------
        const_pointer operator->() {return(&_ptr->_data);};

        // --------------------------------------------- ++ OPERATOR ---------------------------------------------------
        ConstRevBidirectionalIterator& operator++() { //prefix
            _ptr = _ptr->_prev;
            return (*this);
        };

        ConstRevBidirectionalIterator  operator++(int) { //postfix
            ConstRevBidirectionalIterator<T> temp(*this);

            _ptr = _ptr->_prev;
            return (temp);
        };

        // --------------------------------------------- -- OPERATOR ---------------------------------------------------
        ConstRevBidirectionalIterator& operator--() {
            _ptr = _ptr->_next;
            return (*this);
        };

        ConstRevBidirectionalIterator  operator--(int) {
            ConstRevBidirectionalIterator<T> temp(*this);

            _ptr = _ptr->_next;
            return (temp);
        };

        // ----------------------------------------- RELATIONAL OPERATORS  ---------------------------------------------
        bool operator== (const ConstRevBidirectionalIterator<value_type>& rhs) {
            return (_ptr == rhs._ptr);
        };

        template <class Iterator>
        bool operator!= (const ConstRevBidirectionalIterator<value_type>& rhs) {
            return (_ptr != rhs._ptr);
        };
    };

};

#endif //FT_CONTAINERS_ITERATOR_HPP
