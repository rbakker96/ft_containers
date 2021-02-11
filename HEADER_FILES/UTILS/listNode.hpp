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
    class listNode {

    public:
        listNode*   _prev;
        listNode*   _next;
        T       _data;

        explicit listNode() : _prev(NULL), _next(NULL), _data() {};
        explicit listNode(const T &data) : _prev(NULL), _next(NULL), _data(data) {};
        ~listNode() {};

        listNode& operator=(listNode const &rhs) {
            if (this != rhs) {
                this->_prev = rhs._prev;
                this->_next = rhs._next;
                this->_data = rhs._data;
            }
            return (*this);
        };

        listNode *getNext() { return (this->_next); };
        listNode *getPrev() { return (this->_prev); };
    };
};

#endif //FT_CONTAINERS_NODE_HPP
