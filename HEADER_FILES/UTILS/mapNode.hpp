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

#include <algorithm>
#include <cstddef>

namespace ft {

    template<typename T>
    class mapNode {

    public:
        mapNode *_parent;
        mapNode *_left;
        mapNode *_right;
        T _data;

        explicit mapNode() : _parent(NULL), _left(NULL), _right(NULL), _data() {};

        explicit mapNode(const T &data) : _parent(NULL), _left(NULL), _right(NULL), _data(data) {};

        mapNode(const mapNode &x) : _parent(x._parent), _left(x._left), _right(x._right), _data(x._data) {};

        ~mapNode() {};

        mapNode &operator=(mapNode const &rhs) {
            if (this != rhs) {
                this->_parent = rhs._parent;
                this->_left = rhs._left;
                this->_right = rhs._right;
                this->_data = rhs._data;
            }
            return (*this);
        };

        mapNode *getNext() {
            mapNode *traverser = this;
            mapNode *temp;
            if (traverser->_right) {
                traverser = traverser->_right;
                while (traverser->_left != NULL)
                    traverser = traverser->_left;
                return (traverser);
            }
            temp = traverser->_parent;
            while (temp && traverser == temp->_right) {
                traverser = temp;
                temp = temp->_parent;
            }
            if (!temp) {
                while (traverser->_left != NULL)
                    traverser = traverser->_left;
                temp = traverser->_left;
            }
            return (temp);
        }

        mapNode *getPrev() {
            mapNode *traverser = this;
            mapNode *temp;
            if (traverser->_left) {
                traverser = traverser->_left;
                while (traverser->_right != NULL)
                    traverser = traverser->_right;
                return (traverser);
            }
            temp = traverser->_parent;
            while (temp && traverser == temp->_left) {
                traverser = temp;
                temp = temp->_parent;
            }
            if (!temp) {
                while (traverser->_right != NULL)
                    traverser = traverser->_right;
                temp = traverser->_right;
            }
            return (temp);
        }

    };

};

#endif //FT_CONTAINERS_MAPNODE_HPP
