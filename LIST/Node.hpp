/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/19 15:55:10 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/19 15:55:10 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

namespace ft {

    template<typename T>
    class Node {

    public:
        Node*   _prev;
        Node*   _next;
        T       _data;

        explicit Node() : _prev(NULL), _next(NULL), _data() {};
        explicit Node(const T &data) : _prev(NULL), _next(NULL), _data(data) {};
        ~Node() {};

        Node& operator=(Node const &rhs) {
            if (this != rhs) {
                this->_prev = rhs._prev;
                this->_next = rhs._next;
                this->_data = rhs._data;
            }
            return (*this);
        };

        Node *getNext() { return (this->_next); };
        Node *getPrev() { return (this->_prev); };
    };
};

#endif //FT_CONTAINERS_NODE_HPP
