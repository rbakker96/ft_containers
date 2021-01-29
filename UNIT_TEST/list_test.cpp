#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include <string>
#include <list>

#include "../LIST/List.hpp"
#include "../LIST/Iterator.hpp"
#include "../LIST/Node.hpp"

//clang++ -std=c++14 list_test.cpp catch.cpp -g -fsanitize=address


//->Check test van sam voor die equal operator die niet werkt

//TEST_CASE( "BASIC ITERATOR", "[list]" ) {
//    ft::list<std::string> ft_basic_list;
//    std::list<std::string> std_basic_list;
//
//    ft_basic_list.push_back("Hello world");
//    std_basic_list.push_back("Hello world");
//    ft_basic_list.push_back("Goodbye world");
//    std_basic_list.push_back("Goodbye world");
//    ft_basic_list.push_back("Hello again");
//    std_basic_list.push_back("Hello again");
//    ft_basic_list.push_back("Final goodbye");
//    std_basic_list.push_back("Final goodbye");
//
//    ft::list<std::string>::iterator ft_basic_it = ft_basic_list.begin();
//    std::list<std::string>::iterator std_basic_it = std_basic_list.begin();
//
//    ft::list<std::string>::iterator ft_basic_end_it = ft_basic_list.end();
//    std::list<std::string>::iterator std_basic_end_it = std_basic_list.end();
//
//    SECTION("Increment - prefix and postfix") {
//        REQUIRE(*ft_basic_it == *std_basic_it);
//        ft_basic_it++;
//        std_basic_it++;
//        REQUIRE(*ft_basic_it->data() == *std_basic_it->data());
//        ++ft_basic_it;
//        ++std_basic_it;
//        REQUIRE(*ft_basic_it == *std_basic_it);
//    }
//    SECTION("Decrement - prefix and postfix") {
//        ft_basic_end_it--;
//        std_basic_end_it--;
//        REQUIRE(*ft_basic_end_it->data() == *std_basic_end_it->data());
//        --ft_basic_end_it;
//        --std_basic_end_it;
//        REQUIRE(*ft_basic_end_it == *std_basic_end_it);
//    }
//    SECTION("* overload") {
//        ++ft_basic_it;
//        ++std_basic_it;
//        REQUIRE(*ft_basic_it == *std_basic_it);
//    }
//    SECTION("-> overload") {
//        ft_basic_it--;
//        std_basic_it--;
//        REQUIRE(*ft_basic_it->data() == *std_basic_it->data());
//    }
//    SECTION("== operator") {
//        bool equal;
//        equal = (*ft_basic_it == *std_basic_it);
//        REQUIRE(equal == true);
//        ++ft_basic_it;
//        equal = (*ft_basic_it == *std_basic_it);
//        REQUIRE(equal == false);
//    }
//    SECTION("!= operator") {
//        bool unequal;
//        unequal = (*ft_basic_it != *std_basic_it);
//        REQUIRE(unequal == false);
//        ++std_basic_it;
//        unequal = (*ft_basic_it != *std_basic_it);
//        REQUIRE(unequal == true);
//    }
//}
//
//
//TEST_CASE( "CONST ITERATOR", "[list]" ) {
//    ft::list<std::string> ft_const_list;
//    std::list<std::string> std_const_list;
//
//    ft_const_list.push_back("Hello world");
//    std_const_list.push_back("Hello world");
//    ft_const_list.push_back("Goodbye world");
//    std_const_list.push_back("Goodbye world");
//    ft_const_list.push_back("Hello again");
//    std_const_list.push_back("Hello again");
//    ft_const_list.push_back("Final goodbye");
//    std_const_list.push_back("Final goodbye");
//
//    ft::list<std::string>::const_iterator ft_const_it = ft_const_list.begin();
//    std::list<std::string>::const_iterator std_const_it = std_const_list.begin();
//
//    ft::list<std::string>::const_iterator ft_const_end_it = ft_const_list.end();
//    std::list<std::string>::const_iterator std_const_end_it = std_const_list.end();
//
//    SECTION("Increment - prefix and postfix") {
//        REQUIRE(*ft_const_it == *std_const_it);
//        ft_const_it++;
//        std_const_it++;
//        REQUIRE(*ft_const_it->data() == *std_const_it->data());
//        ++ft_const_it;
//        ++std_const_it;
//        REQUIRE(*ft_const_it == *std_const_it);
//    }
//    SECTION("Decrement - prefix and postfix") {
//        ft_const_end_it--;
//        std_const_end_it--;
//        REQUIRE(*ft_const_end_it->data() == *std_const_end_it->data());
//        --ft_const_end_it;
//        --std_const_end_it;
//        REQUIRE(*ft_const_end_it == *std_const_end_it);
//    }
//    SECTION("* overload") {
//        ++ft_const_it;
//        ++std_const_it;
//        REQUIRE(*ft_const_it == *std_const_it);
//    }
//    SECTION("-> overload") {
//        ft_const_it--;
//        std_const_it--;
//        REQUIRE(*ft_const_it->data() == *std_const_it->data());
//    }
//    SECTION("== operator") {
//        bool equal;
//        equal = (*ft_const_it == *std_const_it);
//        REQUIRE(equal == true);
//        ++ft_const_it;
//        equal = (*ft_const_it == *std_const_it);
//        REQUIRE(equal == false);
//    }
//    SECTION("!= operator") {
//        bool unequal;
//        unequal = (*ft_const_it != *std_const_it);
//        REQUIRE(unequal == false);
//        ++std_const_it;
//        unequal = (*ft_const_it != *std_const_it);
//        REQUIRE(unequal == true);
//    }
//}
//
//
//TEST_CASE( "REV ITERATOR", "[list]" ) {
//    ft::list<std::string> ft_rev_list;
//    std::list<std::string> std_rev_list;
//
//    ft_rev_list.push_back("Hello world");
//    std_rev_list.push_back("Hello world");
//    ft_rev_list.push_back("Goodbye world");
//    std_rev_list.push_back("Goodbye world");
//    ft_rev_list.push_back("Hello again");
//    std_rev_list.push_back("Hello again");
//    ft_rev_list.push_back("Final goodbye");
//    std_rev_list.push_back("Final goodbye");
//
//    ft::list<std::string>::reverse_iterator ft_rev_it = ft_rev_list.rbegin();
//    std::list<std::string>::reverse_iterator std_rev_it = std_rev_list.rbegin();
//
//    ft::list<std::string>::reverse_iterator ft_rev_end_it = ft_rev_list.rend();
//    std::list<std::string>::reverse_iterator std_rev_end_it = std_rev_list.rend();
//
//    SECTION("Increment - prefix and postfix") {
//        REQUIRE(*ft_rev_it == *std_rev_it);
//        ft_rev_it++;
//        std_rev_it++;
//        REQUIRE(*ft_rev_it->data() == *std_rev_it->data());
//        ++ft_rev_it;
//        ++std_rev_it;
//        REQUIRE(*ft_rev_it == *std_rev_it);
//    }
//    SECTION("Decrement - prefix and postfix") {
//        ft_rev_end_it--;
//        std_rev_end_it--;
//        REQUIRE(*ft_rev_end_it->data() == *std_rev_end_it->data());
//        --ft_rev_end_it;
//        --std_rev_end_it;
//        REQUIRE(*ft_rev_end_it == *std_rev_end_it);
//    }
//    SECTION("* overload") {
//        ++ft_rev_it;
//        ++std_rev_it;
//        REQUIRE(*ft_rev_it == *std_rev_it);
//    }
//    SECTION("-> overload") {
//        ft_rev_it--;
//        std_rev_it--;
//        REQUIRE(*ft_rev_it->data() == *std_rev_it->data());
//    }
//    SECTION("== operator") {
//        bool equal;
//        equal = (*ft_rev_it == *std_rev_it);
//        REQUIRE(equal == true);
//        ++ft_rev_it;
//        equal = (*ft_rev_it == *std_rev_it);
//        REQUIRE(equal == false);
//    }
//    SECTION("!= operator") {
//        bool unequal;
//        unequal = (*ft_rev_it != *std_rev_it);
//        REQUIRE(unequal == false);
//        ++std_rev_it;
//        unequal = (*ft_rev_it != *std_rev_it);
//        REQUIRE(unequal == true);
//    }
//}
//
//
//TEST_CASE( "CONST REV ITERATOR", "[list]" ) {
//    ft::list<std::string> ft_const_rev_list;
//    std::list<std::string> std_const_rev_list;
//
//    ft_const_rev_list.push_back("Hello world");
//    std_const_rev_list.push_back("Hello world");
//    ft_const_rev_list.push_back("Goodbye world");
//    std_const_rev_list.push_back("Goodbye world");
//    ft_const_rev_list.push_back("Hello again");
//    std_const_rev_list.push_back("Hello again");
//    ft_const_rev_list.push_back("Final goodbye");
//    std_const_rev_list.push_back("Final goodbye");
//
//    ft::list<std::string>::const_reverse_iterator ft_const_rev_it = ft_const_rev_list.rbegin();
//    std::list<std::string>::const_reverse_iterator std_const_rev_it = std_const_rev_list.rbegin();
//
//    ft::list<std::string>::const_reverse_iterator ft_const_rev_end_it = ft_const_rev_list.rend();
//    std::list<std::string>::const_reverse_iterator std_const_rev_end_it = std_const_rev_list.rend();
//
//    SECTION("Increment - prefix and postfix") {
//        REQUIRE(*ft_const_rev_it == *std_const_rev_it);
//        ft_const_rev_it++;
//        std_const_rev_it++;
//        REQUIRE(*ft_const_rev_it->data() == *std_const_rev_it->data());
//        ++ft_const_rev_it;
//        ++std_const_rev_it;
//        REQUIRE(*ft_const_rev_it == *std_const_rev_it);
//    }
//    SECTION("Decrement - prefix and postfix") {
//        ft_const_rev_end_it--;
//        std_const_rev_end_it--;
//        REQUIRE(*ft_const_rev_end_it->data() == *std_const_rev_end_it->data());
//        --ft_const_rev_end_it;
//        --std_const_rev_end_it;
//        REQUIRE(*ft_const_rev_end_it == *std_const_rev_end_it);
//    }
//    SECTION("* overload") {
//        ++ft_const_rev_it;
//        ++std_const_rev_it;
//        REQUIRE(*ft_const_rev_it == *std_const_rev_it);
//    }
//    SECTION("-> overload") {
//        ft_const_rev_it--;
//        std_const_rev_it--;
//        REQUIRE(*ft_const_rev_it->data() == *std_const_rev_it->data());
//    }
//    SECTION("== operator") {
//        bool equal;
//        equal = (*ft_const_rev_it == *std_const_rev_it);
//        REQUIRE(equal == true);
//        ++ft_const_rev_it;
//        equal = (*ft_const_rev_it == *std_const_rev_it);
//        REQUIRE(equal == false);
//    }
//    SECTION("!= operator") {
//        bool unequal;
//        unequal = (*ft_const_rev_it != *std_const_rev_it);
//        REQUIRE(unequal == false);
//        ++std_const_rev_it;
//        unequal = (*ft_const_rev_it != *std_const_rev_it);
//        REQUIRE(unequal == true);
//    }
//}


//TEST_CASE( "empty container constructor (default constructor)", "[list]" ) {
//    ft::list<int> first;                                // empty list of ints
//    REQUIRE(first.size() == 0);
//}
//
//TEST_CASE( "fill constructor", "[list]" ) {
//    ft::list<int> second (4,100);                // four ints with value 100
//    REQUIRE(second.size() == 4);
//}
//
//TEST_CASE( "range constructor", "[list]" ) {
//    ft::list<int> second (4,100);
//    ft::list<int> third (second.begin(),second.end());  // iterating through second
//    REQUIRE(third.size() == 4);
//}
//
//TEST_CASE( "copy constructor", "[list]" ) {
//    ft::list<int> second (4,100);
//    ft::list<int> fourth (second);                       // a copy of second
//    REQUIRE(fourth.size() == second.size());
//}

//TEST_CASE( "empty", "[list]" ) {
//    ft::list<int> my_list;
//    REQUIRE(my_list.empty() == true);
//    my_list.push_front(1);
//    REQUIRE(my_list.empty() == false);
//}
//
//TEST_CASE( "size", "[list]" ) {
//    ft::list<int> my_list;
//    my_list.push_front(1);
//    REQUIRE(my_list.size() == 1);
//    my_list.push_front(1);
//    REQUIRE(my_list.size() == 2);
//}
//
//TEST_CASE( "max_size", "[list]" ) {
//    ft::list<int> my_list;
//    std::list<int> original_list;
//    REQUIRE(my_list.max_size() == original_list.max_size());
//}
//
//TEST_CASE( "front", "[list]" ) {
//    ft::list<int> mylist;
//
//    mylist.push_back(77);
//    mylist.push_back(22);
//
//    // now front equals 77, and back 22
//    REQUIRE(mylist.front() == 77);
//}
//
//TEST_CASE( "back", "[list]" ) {
//    ft::list<int> mylist;
//
//    mylist.push_back(77);
//    mylist.push_back(22);
//
//    // now front equals 77, and back 22
//    REQUIRE(mylist.back() == 22);
//}
//
//TEST_CASE( "assign", "[list]" ) {
//    ft::list<int> first;
//    ft::list<int> second;
//
//    first.assign (7,100);                      // 7 ints with value 100
//    REQUIRE(first.size() == 7);
//    REQUIRE(first.begin() == 100);

//    second.assign (first.begin(),first.end());          // a copy of first
//    REQUIRE(second.size() == 7);
//    REQUIRE(second.front() == 100);

//    int myints[]={1776,7,4};
//    first.assign (myints,myints+3);                 // assigning from array
//    REQUIRE(first.size() == 3);
//    REQUIRE(first.front() == 1776);
//}
//
//TEST_CASE( "push_front", "[list]" ) {
//    std::list<int> mylist (2,100);         // two ints with a value of 100
//    mylist.push_front (200);
//    mylist.push_front (300);
//
//    // mylist: 300 200 100 100
//    REQUIRE(mylist.size() == 4);
//    REQUIRE(*mylist.begin() == 300);
//}
//
//TEST_CASE( "pop_front", "[list]" ) {
//    std::list<int> mylist;
//    mylist.push_back (100);
//    mylist.push_back (200);
//    mylist.push_back (300);
//
//    REQUIRE(mylist.size() == 3);
//
//    while (!mylist.empty())
//        mylist.pop_front();
//
//    REQUIRE(mylist.size() == 0);
//}
//
//TEST_CASE( "push_back", "[list]" ) {
//    std::list<int> mylist (2,100);         // two ints with a value of 100
//    mylist.push_back(200);
//    mylist.push_back(300);
//
//    // mylist: 100 100 200 300
//    REQUIRE(mylist.size() == 4);
//    REQUIRE(*mylist.begin() == 100);
//}
//
//TEST_CASE( "pop_back", "[list]" ) {
//    std::list<int> mylist;
//    mylist.push_back (100);
//    mylist.push_back (200);
//    mylist.push_back (300);
//
//    REQUIRE(mylist.size() == 3);
//
//    while (!mylist.empty())
//        mylist.pop_back();
//
//    REQUIRE(mylist.size() == 0);
//}
//
//TEST_CASE( "insert", "[list]" ) {
//    ft::list<int> mylist;
//    ft::list<int>::iterator it;
//                                                          // set some initial values:
//    for (int i=1; i<=5; ++i) mylist.push_back(i);         // 1 2 3 4 5
//
//    it = mylist.begin();
//    ++it;                                                 // it points now to number 2
//
//    mylist.insert (it,10);                           // 1 10 2 3 4 5
//    REQUIRE(*it == 2);                                   // "it" still points to number 2
//
//    mylist.insert (it,2,20);                      // 1 10 20 20 2 3 4 5
//    REQUIRE(mylist.size() == 8);
//
//    --it;                                                 // it points now to the second 20
//
//    std::vector<int> myvector (2,30);
//    mylist.insert (it,myvector.begin(),myvector.end());   // 1 10 20 30 30 20 2 3 4 5
//    REQUIRE(mylist.size() == 10);
//}
//
//TEST_CASE( "erase", "[list]" ) {
//    ft::list<int> mylist;
//    ft::list<int>::iterator it1,it2;
//
//    for (int i=1; i<10; ++i) mylist.push_back(i*10); // 10 20 30 40 50 60 70 80 90
//    it1 = it2 = mylist.begin();
//    std::advance (it2,6);
//    ++it1;
//
//    it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
//    REQUIRE(mylist.size() == 8);
//    REQUIRE(*it1 == 30);
//    it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
//    REQUIRE(mylist.size() == 7);
//    REQUIRE(*it2 == 80);
//
//    ++it1;
//    --it2;
//
//    mylist.erase (it1,it2);     // 10 30 60 80 90
//    REQUIRE(mylist.size() == 5);
//    REQUIRE(*it2 == 60);
//}
//
//TEST_CASE( "swap", "[list]" ) {
//    ft::list<int> first (3,100);   // three ints with a value of 100
//    ft::list<int> second (5,200);  // five ints with a value of 200
//
//    first.swap(second);
//    REQUIRE(first.size() == 5);
//    REQUIRE(second.size() == 3);
//}
//
//TEST_CASE( "resize", "[list]" ) {
//    ft::list<int> mylist;
//
//    // set some initial content:
//    for (int i=1; i<10; ++i) mylist.push_back(i);
//
//    mylist.resize(5);
//    REQUIRE(mylist.size() == 5);
//
//    mylist.resize(8,100);
//    REQUIRE(mylist.size() == 8);
//
//    mylist.resize(12);
//    REQUIRE(mylist.size() == 12);
//}
//
//TEST_CASE( "splice", "[list]" ) {
//    ft::list<int> mylist1, mylist2;
//    ft::list<int>::iterator it;
//
//    // set some initial values:
//    for (int i=1; i<=4; ++i)
//        mylist1.push_back(i);      // mylist1: 1 2 3 4
//
//    for (int i=1; i<=3; ++i)
//        mylist2.push_back(i*10);                     // mylist2: 10 20 30
//
//    it = mylist1.begin();
//    ++it;                                               // points to 2
//
//    mylist1.splice (it, mylist2);                    // mylist1: 1 10 20 30 2 3 4
//    REQUIRE(mylist1.size() == 7);                       // mylist2 (empty)
//    REQUIRE(mylist1.size() == 7);
//    REQUIRE(*it == 2);                                  // "it" still points to 2 (the 5th element)
//
//    mylist2.splice (mylist2.begin(),mylist1, it);
//    REQUIRE(mylist1.size() == 6);                       // mylist1: 1 10 20 30 3 4
//    REQUIRE(mylist2.size() == 1);                       // mylist2: 2
//    REQUIRE(*mylist2.begin() == 2);
//
//    it = mylist1.begin();
//    std::advance(it,3);                           // "it" points now to 30
//
//    mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end()); // mylist1: 30 3 4 1 10 20
//    REQUIRE(mylist1.size() == 6);
//}

TEST_CASE( "remove", "[list]" ) {
    int myints[]= {17,89,7,14};
    ft::list<int> mylist (myints,myints+4);
    ft::list<int>::iterator it = mylist.begin();

    mylist.remove(89);
    REQUIRE(mylist.size() == 3);
    REQUIRE(*it == 17);
    it++;
    REQUIRE(*it == 7);
    it++;
    REQUIRE(*it == 14);
}

// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
    bool operator() (const int& value) { return (value%2)==1; }
};

TEST_CASE( "remove if", "[list]" ) {
    int myints[]= {15,36,7,17,20,39,4,1};
    ft::list<int> mylist (myints,myints+8);   // 15 36 7 17 20 39 4 1

    mylist.remove_if (single_digit);           // 15 36 17 20 39
    REQUIRE(mylist.size() == 5);

    mylist.remove_if (is_odd());               // 36 20
    REQUIRE(mylist.size() == 2);
}

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
    bool operator() (double first, double second)
    { return (fabs(first-second)<5.0); }
};

TEST_CASE( "unique", "[list]" ) {
    double mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
                         12.77, 73.35, 72.25, 15.3,  72.25 };
    ft::list<double> mylist (mydoubles,mydoubles+10);

    mylist.sort();              //  2.72, 3.14, 12.15, 12.77, 12.77, 15.3, 72.25, 72.25, 73.0, 73.35
    REQUIRE(mylist.size() == 10);

    mylist.unique();           //  2.72, 3.14, 12.15, 12.77, 15.3, 72.25, 73.0, 73.35
    REQUIRE(mylist.size() == 8);

    mylist.unique (same_integral_part);  //  2.72, 3.14, 12.15, 15.3, 72.25, 73.0
    REQUIRE(mylist.size() == 6);

    mylist.unique (is_near());           //  2.72, 12.15, 72.25
    REQUIRE(mylist.size() == 3);
}

TEST_CASE( "", "[list]" ) {

    REQUIRE();
}

TEST_CASE( "", "[list]" ) {

    REQUIRE();
}

TEST_CASE( "", "[list]" ) {

    REQUIRE();
}

TEST_CASE( "", "[list]" ) {

    REQUIRE();
}

TEST_CASE( "", "[list]" ) {

    REQUIRE();
}
