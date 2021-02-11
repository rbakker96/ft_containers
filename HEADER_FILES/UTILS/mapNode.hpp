/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapNode.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/11 10:46:11 by roybakker     #+#    #+#                 */
/*   Updated: 2021/02/11 10:46:11 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPNODE_HPP
#define MAPNODE_HPP

namespace ft {

    template<typename T>
    class mapNode {

    public:
        mapNode*   _root;
        mapNode*   _left;
        mapNode*   _right;
        T          _data;

        explicit mapNode() : _root(NULL), _left(NULL), _right(NULL), _data() {};
        explicit mapNode(const T &data) : _root(NULL), _left(NULL), _right(NULL), _data(data) {};
        ~listNode() {};

        mapNode& operator=(mapNode const &rhs) {
            if (this != rhs) {
                this->_root = rhs._root;
                this->_left = rhs._left;
                this->_right = rhs._right;
            }
            return (*this);
        };

//        mapNode *getNext() { return (this->_next); };
//        mapNode *getPrev() { return (this->_prev); };
    };
};

#endif //FT_CONTAINERS_MAPNODE_HPP
