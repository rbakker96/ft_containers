/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/15 11:00:27 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/15 11:00:27 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"
#include <iostream>

using namespace ft;

int main ()
{
    // constructors used in the same order as described above:
    list<int> first;                                // empty list of ints
    list<int> second (4,100);                       // four ints with value 100
//    list<int> third (second.begin(),second.end());  // iterating through second
    list<int> fourth (second);                       // a copy of third

    // the iterator constructor can also be used to construct from arrays:
//    int myints[] = {16,2,77,29};
//    list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

    std::cout << "The contents of fourt are: ";
//    for (list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
//        std::cout << *it << ' ';

    std::cout << '\n';

    return 0;
}

