#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include <string>
#include <list>

#include "../LIST/List.hpp"
#include "../LIST/Iterator.hpp"
#include "../LIST/Node.hpp"

//clang++ -std=c++14 list_test.cpp catch.cpp -g -fsanitize=address

//TEST_CASE("List: Iterator", "[List]") {
//    ft::list<std::string> myList;
//    std::list<std::string> sysList;
//    ft::list<int> myIntList;
//    std::string str = "Hello, world!";
//    myList.push_back(str);
//    sysList.push_back(str);
//    myList.push_back("I'm the next King");
//    sysList.push_back("I'm the next King");
//    myList.push_back("Welcome yourself to the next chapter");
//    sysList.push_back("Welcome yourself to the next chapter");
//    ft::list<std::string>::iterator myIt = myList.begin();
//    std::list<std::string>::iterator sysIt = sysList.begin();
//
//    SECTION("Increment") {
//        myIt++;
//        sysIt++;
//        REQUIRE(*myIt == *sysIt);
//        ++myIt;
//        ++sysIt;
//        REQUIRE(*myIt == *sysIt);
//    }
//    SECTION("Decrement") {
//        myIt++;
//        sysIt++;
//        REQUIRE(*myIt == *sysIt);
//        myIt--;
//        sysIt--;
//        REQUIRE(*myIt == *sysIt);
//    }
//    SECTION("-> overload") {
//        myIt++;
//        sysIt++;
//        REQUIRE(*myIt->data() == *sysIt->data());
//    }
//    SECTION("* overload") {
//        myIt++;
//        sysIt++;
//        REQUIRE(*myIt == *sysIt);
//    }
//    SECTION("== overload") {
//        bool res;
//        res = (myIt == myList.begin());
//        REQUIRE(res == true);
//        myIt++;
//        myIt++;
//        myIt++;
//        res = (myIt == myList.end());
//        REQUIRE(res == true);
//        res = (myIt == myList.begin());
//        REQUIRE(res == false);
//    }
//    SECTION("!= overload") {
//        bool res;
//        res = (myIt != myList.end());
//        REQUIRE(res == true);
//        myIt++;
//        myIt++;
//        res = (myIt != myList.begin());
//        REQUIRE(res == true);
//        myIt++;
//        res = (myIt != myList.end());
//        REQUIRE(res == false);
//    }
//    SECTION("Test (*it)++") {
//        myIntList.push_back(1);
//        ft::list<int>::iterator myIntIt = myIntList.begin();
//        REQUIRE(*myIntIt == 1);
//        (*myIntIt)++;
//        REQUIRE(*myIntIt == 2);
//        *myIntIt++;
//        bool res = (myIntIt == myIntList.end());
//        REQUIRE(res == true);
//    }
//    SECTION("Test (*it)--") {
//        myIntList.push_back(2);
//        ft::list<int>::iterator myIntIt = myIntList.begin();
//        REQUIRE(*myIntIt == 2);
//        (*myIntIt)--;
//        REQUIRE(*myIntIt == 1);
//        *myIntIt--;
//        bool res = (myIntIt != myIntList.begin());
//        REQUIRE(res == true);
//    }
//    SECTION("Test assignemt with iterator") {
//        myIntList.push_back(1);
//        myIntList.push_back(8);
//        ft::list<int>::iterator myIntIt = myIntList.begin();
//        REQUIRE(*myIntIt == 1);
//        *myIntIt = 5;
//        REQUIRE(*myIntIt == 5);
//    }
//    SECTION("Test dereference as lvalue") {
//        myIntList.push_back(1);
//        myIntList.push_back(8);
//        ft::list<int>::iterator myIntIt = myIntList.begin();
//        *myIntIt++ = 5;
//        REQUIRE(*myIntIt == 8);
//        myIntIt--;
//        REQUIRE(*myIntIt == 5);
//    }
//    SECTION("Reverse iterator") {
//        ft::list<int> mylist;
//        for (int i=1; i<=5; ++i) mylist.push_back(i);
//
//        ft::list<int>::reverse_iterator rit=mylist.rbegin();
//        REQUIRE(*rit == 5);
//        rit++;
//        REQUIRE(*rit == 4);
//        rit--;
//        REQUIRE(*rit == 5);
//        *rit = 10;
//        REQUIRE(*rit == 10);
//    }
//}

TEST_CASE( "CONSTRUCTORS", "[list]" ) {
    ft::list<std::string> ft_list_one;

    ft_list_one.push_front("hallo");
    ft_list_one.push_front("world");
    ft_list_one.push_back("!");

    SECTION("Empty constructor") {
        REQUIRE(ft_list_one.size() == 3);
    }
    SECTION("Copy constructor") {
        ft::list<std::string> ft_list_two(ft_list_one);
        REQUIRE(ft_list_one.size() == ft_list_two.size());
    }
    SECTION("Given size constructor") {
        size_t x = 4;
        ft::list<int> first(x,100);
        std::list<int> second(4,100);
        REQUIRE(4 == second.size());
    }
    SECTION("Iterator range constructor") {
        std::list<int> first(4,100);
        ft::list<int> second (first.begin(), first.end());
        REQUIRE(first.size() == second.size());
    }
    SECTION("Assignement operator") {
        ft::list<int> first (3);
        ft::list<int> second (5);
        second = first;
        REQUIRE(first.size() == second.size());
    }
}

//->Check test van sam voor die equal operator die niet werkt

TEST_CASE( "BASIC ITERATOR", "[list]" ) {
    ft::list<std::string> ft_basic_list;
    std::list<std::string> std_basic_list;

    ft_basic_list.push_back("Hello world");
    std_basic_list.push_back("Hello world");
    ft_basic_list.push_back("Goodbye world");
    std_basic_list.push_back("Goodbye world");
    ft_basic_list.push_back("Hello again");
    std_basic_list.push_back("Hello again");
    ft_basic_list.push_back("Final goodbye");
    std_basic_list.push_back("Final goodbye");

    ft::list<std::string>::iterator ft_basic_it = ft_basic_list.begin();
    std::list<std::string>::iterator std_basic_it = std_basic_list.begin();

    ft::list<std::string>::iterator ft_basic_end_it = ft_basic_list.end();
    std::list<std::string>::iterator std_basic_end_it = std_basic_list.end();

    SECTION("Increment - prefix and postfix") {
        REQUIRE(*ft_basic_it == *std_basic_it);
        ft_basic_it++;
        std_basic_it++;
        REQUIRE(*ft_basic_it->data() == *std_basic_it->data());
        ++ft_basic_it;
        ++std_basic_it;
        REQUIRE(*ft_basic_it == *std_basic_it);
    }
    SECTION("Decrement - prefix and postfix") {
        ft_basic_end_it--;
        std_basic_end_it--;
        REQUIRE(*ft_basic_end_it->data() == *std_basic_end_it->data());
        --ft_basic_end_it;
        --std_basic_end_it;
        REQUIRE(*ft_basic_end_it == *std_basic_end_it);
    }
    SECTION("* overload") {
        ++ft_basic_it;
        ++std_basic_it;
        REQUIRE(*ft_basic_it == *std_basic_it);
    }
    SECTION("-> overload") {
        ft_basic_it--;
        std_basic_it--;
        REQUIRE(*ft_basic_it->data() == *std_basic_it->data());
    }
    SECTION("== operator") {
        bool equal;
        equal = (*ft_basic_it == *std_basic_it);
        REQUIRE(equal == true);
        ++ft_basic_it;
        equal = (*ft_basic_it == *std_basic_it);
        REQUIRE(equal == false);
    }
    SECTION("!= operator") {
        bool unequal;
        unequal = (*ft_basic_it != *std_basic_it);
        REQUIRE(unequal == false);
        ++std_basic_it;
        unequal = (*ft_basic_it != *std_basic_it);
        REQUIRE(unequal == true);
    }
}


TEST_CASE( "CONST ITERATOR", "[list]" ) {
    ft::list<std::string> ft_const_list;
    std::list<std::string> std_const_list;

    ft_const_list.push_back("Hello world");
    std_const_list.push_back("Hello world");
    ft_const_list.push_back("Goodbye world");
    std_const_list.push_back("Goodbye world");
    ft_const_list.push_back("Hello again");
    std_const_list.push_back("Hello again");
    ft_const_list.push_back("Final goodbye");
    std_const_list.push_back("Final goodbye");

    ft::list<std::string>::const_iterator ft_const_it = ft_const_list.begin();
    std::list<std::string>::const_iterator std_const_it = std_const_list.begin();

    ft::list<std::string>::const_iterator ft_const_end_it = ft_const_list.end();
    std::list<std::string>::const_iterator std_const_end_it = std_const_list.end();

    SECTION("Increment - prefix and postfix") {
        REQUIRE(*ft_const_it == *std_const_it);
        ft_const_it++;
        std_const_it++;
        REQUIRE(*ft_const_it->data() == *std_const_it->data());
        ++ft_const_it;
        ++std_const_it;
        REQUIRE(*ft_const_it == *std_const_it);
    }
    SECTION("Decrement - prefix and postfix") {
        ft_const_end_it--;
        std_const_end_it--;
        REQUIRE(*ft_const_end_it->data() == *std_const_end_it->data());
        --ft_const_end_it;
        --std_const_end_it;
        REQUIRE(*ft_const_end_it == *std_const_end_it);
    }
    SECTION("* overload") {
        ++ft_const_it;
        ++std_const_it;
        REQUIRE(*ft_const_it == *std_const_it);
    }
    SECTION("-> overload") {
        ft_const_it--;
        std_const_it--;
        REQUIRE(*ft_const_it->data() == *std_const_it->data());
    }
    SECTION("== operator") {
        bool equal;
        equal = (*ft_const_it == *std_const_it);
        REQUIRE(equal == true);
        ++ft_const_it;
        equal = (*ft_const_it == *std_const_it);
        REQUIRE(equal == false);
    }
    SECTION("!= operator") {
        bool unequal;
        unequal = (*ft_const_it != *std_const_it);
        REQUIRE(unequal == false);
        ++std_const_it;
        unequal = (*ft_const_it != *std_const_it);
        REQUIRE(unequal == true);
    }
}


TEST_CASE( "REV ITERATOR", "[list]" ) {
    ft::list<std::string> ft_rev_list;
    std::list<std::string> std_rev_list;

    ft_rev_list.push_back("Hello world");
    std_rev_list.push_back("Hello world");
    ft_rev_list.push_back("Goodbye world");
    std_rev_list.push_back("Goodbye world");
    ft_rev_list.push_back("Hello again");
    std_rev_list.push_back("Hello again");
    ft_rev_list.push_back("Final goodbye");
    std_rev_list.push_back("Final goodbye");

    ft::list<std::string>::reverse_iterator ft_rev_it = ft_rev_list.rbegin();
    std::list<std::string>::reverse_iterator std_rev_it = std_rev_list.rbegin();

    ft::list<std::string>::reverse_iterator ft_rev_end_it = ft_rev_list.rend();
    std::list<std::string>::reverse_iterator std_rev_end_it = std_rev_list.rend();

    SECTION("Increment - prefix and postfix") {
        REQUIRE(*ft_rev_it == *std_rev_it);
        ft_rev_it++;
        std_rev_it++;
        REQUIRE(*ft_rev_it->data() == *std_rev_it->data());
        ++ft_rev_it;
        ++std_rev_it;
        REQUIRE(*ft_rev_it == *std_rev_it);
    }
    SECTION("Decrement - prefix and postfix") {
        ft_rev_end_it--;
        std_rev_end_it--;
        REQUIRE(*ft_rev_end_it->data() == *std_rev_end_it->data());
        --ft_rev_end_it;
        --std_rev_end_it;
        REQUIRE(*ft_rev_end_it == *std_rev_end_it);
    }
    SECTION("* overload") {
        ++ft_rev_it;
        ++std_rev_it;
        REQUIRE(*ft_rev_it == *std_rev_it);
    }
    SECTION("-> overload") {
        ft_rev_it--;
        std_rev_it--;
        REQUIRE(*ft_rev_it->data() == *std_rev_it->data());
    }
    SECTION("== operator") {
        bool equal;
        equal = (*ft_rev_it == *std_rev_it);
        REQUIRE(equal == true);
        ++ft_rev_it;
        equal = (*ft_rev_it == *std_rev_it);
        REQUIRE(equal == false);
    }
    SECTION("!= operator") {
        bool unequal;
        unequal = (*ft_rev_it != *std_rev_it);
        REQUIRE(unequal == false);
        ++std_rev_it;
        unequal = (*ft_rev_it != *std_rev_it);
        REQUIRE(unequal == true);
    }
}


TEST_CASE( "CONST REV ITERATOR", "[list]" ) {
    ft::list<std::string> ft_const_rev_list;
    std::list<std::string> std_const_rev_list;

    ft_const_rev_list.push_back("Hello world");
    std_const_rev_list.push_back("Hello world");
    ft_const_rev_list.push_back("Goodbye world");
    std_const_rev_list.push_back("Goodbye world");
    ft_const_rev_list.push_back("Hello again");
    std_const_rev_list.push_back("Hello again");
    ft_const_rev_list.push_back("Final goodbye");
    std_const_rev_list.push_back("Final goodbye");

    ft::list<std::string>::const_reverse_iterator ft_const_rev_it = ft_const_rev_list.rbegin();
    std::list<std::string>::const_reverse_iterator std_const_rev_it = std_const_rev_list.rbegin();

    ft::list<std::string>::const_reverse_iterator ft_const_rev_end_it = ft_const_rev_list.rend();
    std::list<std::string>::const_reverse_iterator std_const_rev_end_it = std_const_rev_list.rend();

    SECTION("Increment - prefix and postfix") {
        REQUIRE(*ft_const_rev_it == *std_const_rev_it);
        ft_const_rev_it++;
        std_const_rev_it++;
        REQUIRE(*ft_const_rev_it->data() == *std_const_rev_it->data());
        ++ft_const_rev_it;
        ++std_const_rev_it;
        REQUIRE(*ft_const_rev_it == *std_const_rev_it);
    }
    SECTION("Decrement - prefix and postfix") {
        ft_const_rev_end_it--;
        std_const_rev_end_it--;
        REQUIRE(*ft_const_rev_end_it->data() == *std_const_rev_end_it->data());
        --ft_const_rev_end_it;
        --std_const_rev_end_it;
        REQUIRE(*ft_const_rev_end_it == *std_const_rev_end_it);
    }
    SECTION("* overload") {
        ++ft_const_rev_it;
        ++std_const_rev_it;
        REQUIRE(*ft_const_rev_it == *std_const_rev_it);
    }
    SECTION("-> overload") {
        ft_const_rev_it--;
        std_const_rev_it--;
        REQUIRE(*ft_const_rev_it->data() == *std_const_rev_it->data());
    }
    SECTION("== operator") {
        bool equal;
        equal = (*ft_const_rev_it == *std_const_rev_it);
        REQUIRE(equal == true);
        ++ft_const_rev_it;
        equal = (*ft_const_rev_it == *std_const_rev_it);
        REQUIRE(equal == false);
    }
    SECTION("!= operator") {
        bool unequal;
        unequal = (*ft_const_rev_it != *std_const_rev_it);
        REQUIRE(unequal == false);
        ++std_const_rev_it;
        unequal = (*ft_const_rev_it != *std_const_rev_it);
        REQUIRE(unequal == true);
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

TEST_CASE( "MODIFIERS", "[list]" ) {
    ft::list<int> ft_list;
    std::list<int> std_list;

    ft_list.push_front(1);
    std_list.push_front(1);
    ft_list.push_front(2);
    std_list.push_front(2);
    ft_list.push_front(3);
    std_list.push_front(3);

    ft::list<int>::iterator ft_it = ft_list.begin();
    std::list<int>::iterator std_it = std_list.begin();

    SECTION("Assign") {

    }
    SECTION( "Push front" ) {
        ft_list.push_front(3);
        std_list.push_front(3);
        ft_it++;
        std_it++;
        REQUIRE(*ft_it == *std_it);
        REQUIRE(ft_list.size() == 4);
    }
    SECTION( "Pop front" ) {
        ft_list.pop_front();
        std_list.pop_front();
        REQUIRE(ft_list.size() == 2);
    }
    SECTION( "Push back" ) {
        ft_list.push_back(3);
        std_list.push_back(3);
        ft_it++;
        std_it++;
        REQUIRE(*ft_it == *std_it);
        REQUIRE(ft_list.size() == 4);
    }
    SECTION( "Pop back" ) {
        ft_list.pop_back();
        std_list.pop_back();
        REQUIRE(ft_list.size() == 2);
    }
    SECTION( "Insert" ) {
        ft_it++;
        std_it++;
        ft_list.insert(ft_it, 55);
        std_list.insert(std_it, 55);
        REQUIRE(*ft_it == *std_it);
        REQUIRE(ft_list.size() == 4);
        ft_it++;
        std_it++;
        ft_list.insert(ft_it, 3, 66);
        std_list.insert(std_it, 3, 66);
        REQUIRE(*ft_it == *std_it);
        REQUIRE(ft_list.size() == 7);
    }
}

TEST_CASE( "OPERATIONS", "[list]" ) {}

TEST_CASE( "RELATION OPERATORS", "[list]" ) {}
