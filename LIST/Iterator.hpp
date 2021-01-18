/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Iterator.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 14:14:43 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/18 14:14:43 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "List.hpp"

namespace ft {

    template<typename T>
    class BidirectionalIterator {

    public:
        // MEMBER TYPES
        typedef std::bidirectional_iterator_tag     iterator_category;
        typedef Node<T>                             *iterator_type;
        typedef T                                   value_type;
        typedef ptrdiff_t                           difference_type;
        typedef T                                   *pointer;
        typedef T                                   &reference;

    private:
        iterator_type                               _ptr;

    public:
        // MEMBER FUNCTIONS
        // ----------------------------------------- CONSTRUCTOR / DESTRUCTOR -----------------------------------------
        BidirectionalIterator() : _ptr(NULL) {};
        explicit BidirectionalIterator (iterator_type it) : _ptr(it) {};
        template <class Iter>
        BidirectionalIterator (const BidirectionalIterator<Iter>& it) {*this = it;};

        BidirectionalIterator & operator=(const BidirectionalIterator& rhs) {
            if (this != &rhs)
                _ptr = rhs._ptr;
            return (*this);
        };

        virtual ~BidirectionalIterator() {};


        // --------------------------------------------- ++ OPERATOR ---------------------------------------------------
        BidirectionalIterator& operator++() {
            _ptr = _ptr->_next;
            return (*this);
        };

        BidirectionalIterator  operator++(int) {
            iterator_type temp(*this);

            _ptr = _ptr->_next;
            return (temp);
        };


        // --------------------------------------------- -- OPERATOR ---------------------------------------------------
        BidirectionalIterator& operator--() {
            _ptr = _ptr->_prev;
            return (*this);
        };

        BidirectionalIterator  operator--(int) {
            iterator_type temp(*this);

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
    };
};

#endif //FT_CONTAINERS_ITERATOR_HPP
