/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapUtils.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/17 19:58:39 by roybakker     #+#    #+#                 */
/*   Updated: 2021/02/17 19:58:39 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPUTILS_HPP
#define MAPUTILS_HPP


namespace ft {

    class mapUtils {

        node_pointer   tree_minimum(node_pointer x) {
            while (x->_left != NULL)
                x = x->_left;
            return (x);
        }

        node_pointer   tree_maximum(node_pointer x) {
            while (x->_right != NULL)
                x = x->_right;
            return (x);
        }

        node_pointer    tree_successor(node_pointer x) {
            node_pointer temp;
            if (x._right)
                return (tree_minimum(x._right););
            temp = x._parent;
            while (temp && temp == x._right) {
                x = temp;
                temp = temp._parent;
            }
            return (temp);
        }

        node_pointer    tree_predecessor(node_pointer x) {
            node_pointer temp;
            if (x._left)
                return (tree_maximum(x._left););
            temp = x._parent;
            while (temp && temp == x._left) {
                x = temp;
                temp = temp._parent;
            }
            return (temp);
        }

    };

};

#endif //FT_CONTAINERS_MAPUTILS_HPP
