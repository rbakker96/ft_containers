/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Traits.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 16:17:52 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/27 16:17:52 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRAITS_HPP
#define TRAITS_HPP

namespace ft {

    struct output_iterator_tag{};
    struct input_iterator_tag{};
    struct forward_iterator_tag : public input_iterator_tag{};
    struct bidirectional_iterator_tag : public forward_iterator_tag{};
    struct random_access_iterator_tag : public bidirectional_iterator_tag{};

    template<bool B, class T = void>
    struct enable_if {};

    template<class T>
    struct enable_if<true, T>
    { typedef T type; };

    template<typename T, typename C = typename T::iterator_category>
    struct is_input_iterator {
        typedef char yes[1];
        typedef char no[2];

        static yes& test(std::input_iterator_tag);
        static no& test(...);

        static const bool value = (sizeof(test(C())) == sizeof(yes));
    };

}

#endif //FT_CONTAINERS_TRAITS_HPP
