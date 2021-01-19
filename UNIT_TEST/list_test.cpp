#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include <string>
#include <list>

#include "../LIST/List.hpp"
#include "../LIST/Iterator.hpp"
#include "../LIST/node.hpp"

//clang++ -std=c++14 list_test.cpp catch.cpp -g -fsanitize=address

TEST_CASE( "BASIC ITERATORS", "[list]" ) {
    ft::list<std::string> my_list;
    std::list<std::string> original_list;

    std::string str_one = "one";
    std::string str_two = "two";
    std::string str_three = "three";

    my_list.push_front(str_one);
    original_list.push_front(str_one);
    my_list.push_front(str_two);
    original_list.push_front(str_two);
    my_list.push_front(str_three);
    original_list.push_front(str_three);

    ft::list<std::string>::iterator my_begin = my_list.begin();
    std::list<std::string>::iterator original_begin = original_list.begin();
    SECTION( "first element" ) {
        REQUIRE( *my_begin == *original_begin );
    }
    SECTION( "Prefix increment" ) {
        ++my_begin;
        ++original_begin;
        REQUIRE( *my_begin == *original_begin );
    }
    SECTION( "Postfix increment" ) {
        my_begin++;
        original_begin++;
        REQUIRE( *my_begin == *original_begin );
    }

    ft::list<std::string>::iterator my_end = my_list.end();
    std::list<std::string>::iterator original_end = original_list.end();
    SECTION( "last element" ) {
        REQUIRE( *my_end == *my_end );
    }
    SECTION( "Prefix increment" ) {
        --my_end;
        --original_end;
        REQUIRE( *my_end == *original_end );
    }
    SECTION( "Postfix increment" ) {
        my_end--;
        original_end--;
        REQUIRE( *my_end == *original_end );
    }
}

TEST_CASE( "CONST ITERATORS", "[list]" ) {}

TEST_CASE( "REVERSE ITERATORS", "[list]" ) {}

TEST_CASE( "CONST REVERSE ITERATORS", "[list]" ) {}

TEST_CASE( "CAPACITY", "[list]" ) {}

TEST_CASE( "ELEMENT ACCESS", "[list]" ) {}

TEST_CASE( "MODIFIERS", "[list]" ) {}

TEST_CASE( "OPERATIONS", "[list]" ) {}

TEST_CASE( "RELATION OPERATORS", "[list]" ) {}
