/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Queue.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 10:38:02 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/12 10:38:02 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "List.hpp"
#include "UTILS/listNode.hpp"
#include "UTILS/BiDirectionalIterator.hpp"
#include "UTILS/Traits.hpp"

namespace ft {

    template<class T, class Container = ft::list<T> >
    class queue {

    public:
        // MEMBER TYPES
        typedef T               value_type;
        typedef Container       container_type;
        typedef size_t          size_type;

    protected:
        container_type      _ctnr;

    public:
        // ---------------------------------------------- MEMBER FUNCTIONS -------------------------------------------------
        //-> Constructs a queue container adaptor object.
        explicit queue (const container_type& ctnr = container_type()) : _ctnr(ctnr) {}

        //-> Returns whether the queue is empty: i.e. whether its size is zero.
        bool empty() const {return (_ctnr.empty()); }

        //-> Returns the number of elements in the queue.
        size_type size() const {return (_ctnr.size());}

        //-> Returns a reference to the next element in the queue.
        value_type& front() {return (_ctnr.front());}
        const value_type& front() const {return (_ctnr.front());}

        //-> Returns a reference to the last element in the queue.
        value_type& back() {return (_ctnr.back());}
        const value_type& back() const {return (_ctnr.back());}

        //-> Inserts a new element at the end of the queue, after its current last element.
        void push (const value_type& val) {return (_ctnr.push_back(val));}

        //-> Removes the next element in the queue, effectively reducing its size by one.
        void pop() {return (_ctnr.pop_front());}

        // -------------------------------------------- RELATION OPERATORS  --------------------------------------------
        template <class value_type, class ctnr>
        friend bool operator== (const queue<value_type,ctnr>& lhs, const queue<value_type,ctnr>& rhs)
        {return (lhs._ctnr == rhs._ctnr);}

        template <class value_type, class ctnr>
        friend bool operator!= (const queue<value_type,ctnr>& lhs, const queue<value_type,ctnr>& rhs)
        {return (lhs._ctnr != rhs._ctnr);}

        template <class value_type, class ctnr>
        friend bool operator<  (const queue<value_type,ctnr>& lhs, const queue<value_type,ctnr>& rhs)
        {return (lhs._ctnr < rhs._ctnr);}

        template <class value_type, class ctnr>
        friend bool operator<= (const queue<value_type,ctnr>& lhs, const queue<value_type,ctnr>& rhs)
        {return (lhs._ctnr <= rhs._ctnr);}

        template <class value_type, class ctnr>
        friend bool operator>  (const queue<value_type,ctnr>& lhs, const queue<value_type,ctnr>& rhs)
        {return (lhs._ctnr > rhs._ctnr);}

        template <class value_type, class ctnr>
        friend bool operator>= (const queue<value_type,ctnr>& lhs, const queue<value_type,ctnr>& rhs)
        {return (lhs._ctnr >= rhs._ctnr);}

    };

};

#endif //FT_CONTAINERS_QUEUE_HPP
