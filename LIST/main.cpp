//
// Created by Roy Bakker on 19/01/2021.
//

#include "List.hpp"
#include "Node.hpp"
#include "Iterator.hpp"

int main()
{
    ft::list<std::string> my_list;
    std::list<std::string> original_list;

    std::string str = "Normal input string";
    my_list.push_back(str);
    original_list.push_back(str);

    ft::list<std::string>::iterator my_it;
    std::list<std::string>::iterator original_it;

    my_it++;
    original_it++;
    REQUIRE( *my_it == *original_it );
}