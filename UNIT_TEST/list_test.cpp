#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include <string>
#include <list>

#include "../LIST/List.hpp"
#include "../LIST/Iterator.hpp"
#include "../LIST/Node.hpp"

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
    SECTION( "Initialize iterator" ) {
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
    SECTION( "Initialize iterator" ) {
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

TEST_CASE( "CONST ITERATORS", "[list]" ) {
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

    ft::list<std::string>::const_iterator my_begin = my_list.begin();
    std::list<std::string>::const_iterator original_begin = original_list.begin();
    SECTION( "Initialize iterator" ) {
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

    ft::list<std::string>::const_iterator my_end = my_list.end();
    std::list<std::string>::const_iterator original_end = original_list.end();
    SECTION( "Initialize iterator" ) {
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

TEST_CASE( "REVERSE ITERATORS", "[list]" ) {
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

    ft::list<std::string>::reverse_iterator my_begin = my_list.rbegin();
    std::list<std::string>::reverse_iterator original_begin = original_list.rbegin();
    SECTION( "Initialize iterator" ) {
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

    ft::list<std::string>::reverse_iterator my_end = my_list.rend();
    std::list<std::string>::reverse_iterator original_end = original_list.rend();
    SECTION( "Initialize iterator" ) {
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

TEST_CASE( "CONST REVERSE ITERATORS", "[list]" ) {
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

    ft::list<std::string>::reverse_iterator my_begin = my_list.rbegin();
    std::list<std::string>::reverse_iterator original_begin = original_list.rbegin();
    SECTION( "Initialize iterator" ) {
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

    ft::list<std::string>::reverse_iterator my_end = my_list.rend();
    std::list<std::string>::reverse_iterator original_end = original_list.rend();
    SECTION( "Initialize iterator" ) {
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

TEST_CASE( "CAPACITY", "[list]" ) {
    ft::list<int> my_list;
    std::list<int> original_list;

    SECTION( "Empty list bool" ) {
        REQUIRE( my_list.empty() == original_list.empty() );

        my_list.push_front(1);
        original_list.push_front(2);

        REQUIRE( my_list.empty() == original_list.empty() );
    }
    SECTION( "Size of the list" ) {
        my_list.push_back(3);
        original_list.push_back(4);

        REQUIRE( my_list.size() == original_list.size() );
    }
    SECTION( "Max size of the list" ) {
        REQUIRE( my_list.max_size() == original_list.max_size() );
    }

}

TEST_CASE( "ELEMENT ACCESS", "[list]" ) {
    ft::list<std::string> my_list;
    std::list<std::string> original_list;

    my_list.push_front("one");
    original_list.push_front("one");
    my_list.push_front("two");
    original_list.push_front("two");

    SECTION( "Access first element" ) {
        REQUIRE( my_list.front() == original_list.front() );
    }
    SECTION( "Access last element" ) {
        REQUIRE( my_list.back() == original_list.back() );
    }
}

TEST_CASE( "MODIFIERS", "[list]" ) {}

TEST_CASE( "OPERATIONS", "[list]" ) {}

TEST_CASE( "RELATION OPERATORS", "[list]" ) {}
