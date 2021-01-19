#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include <string>
#include <list>

#include "../LIST/List.hpp"
#include "../LIST/Iterator.hpp"


TEST_CASE( "Default constructor", "[list]" ) {
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

//clang++ -std=c++14 list_test.cpp catch.cpp