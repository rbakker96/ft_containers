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

#include "listNode.hpp"

namespace ft {

    template<typename T, typename Node>
    class BidirectionalIterator {

    public:
        // MEMBER TYPES
        typedef std::bidirectional_iterator_tag         iterator_category;
        typedef Node                                    *iterator_type;
        typedef T                                       value_type;
        typedef std::ptrdiff_t                          difference_type;
        typedef T                                       *pointer;
        typedef T                                       &reference;

    private:
        iterator_type   _ptr;

    public:
        // MEMBER FUNCTIONS
        // ----------------------------------------- CONSTRUCTOR / DESTRUCTOR -----------------------------------------
        BidirectionalIterator() : _ptr(NULL) {};
        explicit BidirectionalIterator (iterator_type it) : _ptr(it) {};
        BidirectionalIterator (const BidirectionalIterator& it) {*this = it;};
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
        BidirectionalIterator& operator++() {_ptr = _ptr->getNext(); return (*this);};

        BidirectionalIterator  operator++(int) {
            BidirectionalIterator temp(*this);

            _ptr = _ptr->getNext();
            return (temp);
        };

        // --------------------------------------------- -- OPERATOR ---------------------------------------------------
        BidirectionalIterator& operator--() {_ptr = _ptr->getPrev(); return (*this);};

        BidirectionalIterator  operator--(int) {
            BidirectionalIterator temp(*this);

            _ptr = _ptr->getPrev();
            return (temp);
        };

        // ----------------------------------------- RELATIONAL OPERATORS  ---------------------------------------------
        template<typename T2, typename Node2>
        friend bool operator== (const BidirectionalIterator<T2, Node2>& lhs, const BidirectionalIterator<T2, Node2>& rhs) {return (lhs._ptr == rhs._ptr);};

        template<typename T2, typename Node2>
        friend bool operator!= (const BidirectionalIterator<T2, Node2>& lhs, const BidirectionalIterator<T2, Node2>& rhs) {return !(lhs == rhs);;};

        // -----------------------------------------------  GETTER  ---------------------------------------------------
        const iterator_type&   get_ptr() const {return (_ptr);};
    };



    template<typename T, typename Node>
    class ConstBidirectionalIterator {

    public:
        // MEMBER TYPES
        typedef std::bidirectional_iterator_tag     iterator_category;
        typedef Node                                *iterator_type;
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
        ConstBidirectionalIterator (const ConstBidirectionalIterator& it) {*this = it;};
        ConstBidirectionalIterator (const BidirectionalIterator<T, Node>& it) {_ptr = it.get_ptr();};
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
        ConstBidirectionalIterator& operator++() {_ptr = _ptr->getNext(); return (*this);};

        ConstBidirectionalIterator  operator++(int) {
            ConstBidirectionalIterator temp(*this);

            _ptr = _ptr->getNext();
            return (temp);
        };

        // --------------------------------------------- -- OPERATOR ---------------------------------------------------
        ConstBidirectionalIterator& operator--() {_ptr = _ptr->getPrev(); return (*this);};

        ConstBidirectionalIterator  operator--(int) {
            ConstBidirectionalIterator temp(*this);

            _ptr = _ptr->getPrev();
            return (temp);
        };

        // ----------------------------------------- RELATIONAL OPERATORS  ---------------------------------------------
        template<typename T2, typename Node2>
        friend bool operator== (const ConstBidirectionalIterator<T2, Node2>& lhs,
                                const ConstBidirectionalIterator<T2, Node2>& rhs) {return (lhs._ptr == rhs._ptr);};

        template<typename T2, typename Node2>
        friend bool operator!= (const ConstBidirectionalIterator<T2, Node2>& lhs,
                                const ConstBidirectionalIterator<T2, Node2>& rhs) {return !(lhs == rhs);;};

    };



    template<typename T, typename Node>
    class RevBidirectionalIterator {

    public:
        // MEMBER TYPES
        typedef std::bidirectional_iterator_tag     iterator_category;
        typedef Node                                *iterator_type;
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
        RevBidirectionalIterator (const RevBidirectionalIterator& it) {*this = it;};
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
        RevBidirectionalIterator& operator++() {_ptr = _ptr->getPrev(); return (*this);};

        RevBidirectionalIterator  operator++(int) {
            RevBidirectionalIterator temp(*this);

            _ptr = _ptr->getPrev();
            return (temp);
        };

        // --------------------------------------------- -- OPERATOR ---------------------------------------------------
        RevBidirectionalIterator& operator--() {_ptr = _ptr->getNext(); return (*this);};

        RevBidirectionalIterator  operator--(int) {
            RevBidirectionalIterator temp(*this);

            _ptr = _ptr->getNext();
            return (temp);
        };

        // ----------------------------------------- RELATIONAL OPERATORS  ---------------------------------------------
        template<typename T2, typename Node2>
        friend bool operator== (const RevBidirectionalIterator<T2, Node2>& lhs,
                                const RevBidirectionalIterator<T2, Node2>& rhs) {return (lhs._ptr == rhs._ptr);};

        template<typename T2, typename Node2>
        friend bool operator!= (const RevBidirectionalIterator<T2, Node2>& lhs,
                                const RevBidirectionalIterator<T2, Node2>& rhs) {return !(lhs == rhs);;};

        // -----------------------------------------------  GETTER  ---------------------------------------------------
        const iterator_type&   get_ptr() const {return(_ptr);};
    };



    template<typename T, typename Node>
    class ConstRevBidirectionalIterator {

    public:
        // MEMBER TYPES
        typedef std::bidirectional_iterator_tag     iterator_category;
        typedef Node                                *iterator_type;
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
        ConstRevBidirectionalIterator (const ConstRevBidirectionalIterator& it) {*this = it;};
        ConstRevBidirectionalIterator (const RevBidirectionalIterator<T, Node>& it) {_ptr = it.get_ptr();};
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
        ConstRevBidirectionalIterator& operator++() {_ptr = _ptr->getPrev(); return (*this);};

        ConstRevBidirectionalIterator  operator++(int) {
            ConstRevBidirectionalIterator temp(*this);

            _ptr = _ptr->getPrev();
            return (temp);
        };

        // --------------------------------------------- -- OPERATOR ---------------------------------------------------
        ConstRevBidirectionalIterator& operator--() {_ptr = _ptr->getNext(); return (*this);};

        ConstRevBidirectionalIterator  operator--(int) {
            ConstRevBidirectionalIterator temp(*this);

            _ptr = _ptr->getNext();
            return (temp);
        };

        // ----------------------------------------- RELATIONAL OPERATORS  ---------------------------------------------
        template<typename T2, typename Node2>
        friend bool operator== (const ConstRevBidirectionalIterator<T2, Node2>& lhs,
                         const ConstRevBidirectionalIterator<T2, Node2>& rhs) {return (lhs._ptr == rhs._ptr);};

        template<typename T2, typename Node2>
        friend bool operator!= (const ConstRevBidirectionalIterator<T2, Node2>& lhs,
                         const ConstRevBidirectionalIterator<T2, Node2>& rhs) {return !(lhs == rhs);;};

    };

};

#endif //FT_CONTAINERS_ITERATOR_HPP
