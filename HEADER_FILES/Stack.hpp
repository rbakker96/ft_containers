/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Stack.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 10:39:18 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/12 10:39:18 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "List.hpp"
#include "UTILS/listNode.hpp"
#include "UTILS/BiDirectionalIterator.hpp"
#include "UTILS/Traits.hpp"

namespace ft {

    template<class T, class Container = ft::list<T> >
    class stack {

    public:
        // MEMBER TYPES
        typedef T value_type;
        typedef Container container_type;
        typedef size_t size_type;

    protected:
        container_type _ctnr;

    public:
        // ---------------------------------------------- MEMBER FUNCTIONS -------------------------------------------------
        //-> Constructs a stack container adaptor object.
        explicit stack (const container_type& ctnr = container_type()) : _ctnr(ctnr) {}

        //-> Returns whether the stack is empty
        bool empty() const {return (_ctnr.empty());}

        //-> Returns the number of elements in the stack.
        size_type size() const {return (_ctnr.size());}

        //-> Returns a reference to the top element in the stack.
        value_type& top() {return (_ctnr.back());}
        const value_type& top() const {return (_ctnr.back());}

        //-> Inserts a new element at the top of the stack, above its current top element.
        void push (const value_type& val) {return (_ctnr.push_back(val));}

        //-> Removes the element on top of the stack, effectively reducing its size by one.
        void pop() {return (_ctnr.pop_back());}

        // -------------------------------------------- RELATION OPERATORS  --------------------------------------------
        template <class value_type, class ctnr>
        friend bool operator== (const stack<value_type,ctnr>& lhs, const stack<value_type,ctnr>& rhs)
        {return (lhs._ctnr == rhs._ctnr);}

        template <class value_type, class ctnr>
        friend bool operator!= (const stack<value_type,ctnr>& lhs, const stack<value_type,ctnr>& rhs)
        {return (lhs._ctnr != rhs._ctnr);}

        template <class value_type, class ctnr>
        friend bool operator<  (const stack<value_type,ctnr>& lhs, const stack<value_type,ctnr>& rhs)
        {return (lhs._ctnr < rhs._ctnr);}

        template <class value_type, class ctnr>
        friend bool operator<= (const stack<value_type,ctnr>& lhs, const stack<value_type,ctnr>& rhs)
        {return (lhs._ctnr <= rhs._ctnr);}

        template <class value_type, class ctnr>
        friend bool operator>  (const stack<value_type,ctnr>& lhs, const stack<value_type,ctnr>& rhs)
        {return (lhs._ctnr > rhs._ctnr);}

        template <class value_type, class ctnr>
        friend bool operator>= (const stack<value_type,ctnr>& lhs, const stack<value_type,ctnr>& rhs)
        {return (lhs._ctnr >= rhs._ctnr);}

    };

};

#endif //FT_CONTAINERS_STACK_HPP
