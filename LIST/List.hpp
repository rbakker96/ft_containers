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

template <typename T, class Alloc = std::allocator<T> >
class ft_list
{

protected:


public:
    // MEMBER TYPES
    typedef T           value_type;
    typedef Alloc       allocator_type;
    typedef T&          reference;
    typedef const T&    const_reference;
    typedef T*          pointer;
    typedef const T*    const_pointer;
//  typedef iterator
//  typedef const_iterator;
//  typedef reverse_iterator;
//  typedef const_reverse_iterator;
    typedef ptrdiff_t   difference_type;
    typedef size_t      size_type;

    // MEMBER FUNCTIONS
    // ------ CONSTRUCTOR / DESTRUCTOR ------


    // ------ ITERATORS ------


    // ------ CAPACITY ------

    // ------ ELEMENT ACCESS ------

    // ------ MODIFIERS ------

    // ------ OPERATIONS ------


};

#endif //FT_CONTAINERS_LIST_HPP
