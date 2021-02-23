#include "catch.hpp"

#include <map>
#include <list>
#include "../HEADER_FILES/Map.hpp"
#include "../HEADER_FILES/List.hpp"

//TEST_CASE("map - ", "[map]") {
//
//}

TEST_CASE( "map - empty container constructor (default constructor)", "[map]" ) {
    ft::map<char,int> mymap;

    // first insert function version (single parameter):
    mymap.insert ( std::pair<char,int>('a',100) );
    mymap.insert ( std::pair<char,int>('z',200) );
    REQUIRE(mymap.size() == 2);

    ft::map<char, int>::iterator it = mymap.begin();
    REQUIRE(it->second == 100);

}

TEST_CASE("map - range constructor", "[map]") {
    ft::map<char,int> map;
    map.insert ( std::pair<char,int>('a',100) );
    map.insert ( std::pair<char,int>('z',200) );
    map.insert ( std::pair<char,int>('c',300) );
    map.insert ( std::pair<char,int>('q',400) );
    ft::map<char, int>::iterator mapit = map.begin();

    ft::map<char, int> rangemap(map.begin(), map.end());
    REQUIRE(rangemap.size() == map.size());

    ft::map<char, int>::iterator rangeit;
    for (rangeit=rangemap.begin(); rangeit!=rangemap.end(); rangeit++) {
        REQUIRE(rangeit->first == mapit->first);
        mapit++;
    }
}

TEST_CASE("map - copy constructor", "[map]") {
    ft::map<char,int> map;
    map.insert ( std::pair<char,int>('a',100) );
    map.insert ( std::pair<char,int>('z',200) );
    map.insert ( std::pair<char,int>('c',300) );
    map.insert ( std::pair<char,int>('q',400) );
    ft::map<char, int>::iterator mapit = map.begin();

    ft::map<char, int> rangemap(map);
    REQUIRE(rangemap.size() == map.size());

    ft::map<char, int>::iterator rangeit;
    for (rangeit=rangemap.begin(); rangeit!=rangemap.end(); rangeit++) {
        REQUIRE(rangeit->first == mapit->first);
        mapit++;
    }
}

//TEST_CASE("map - assignment operator", "[map]") {
//
//}

TEST_CASE("map - begin", "[map]") {
    int i = 1;
    ft::map<char,int> map;
    map.insert ( std::pair<char,int>('a',1) );
    map.insert ( std::pair<char,int>('b',2) );
    map.insert ( std::pair<char,int>('z',3) );
    ft::map<char, int>::iterator it;

    for (it=map.begin(); it!=map.end(); it++) {
        REQUIRE(it->second == i);
        i++;
    }
}

TEST_CASE("map - end", "[map]") {
    std::map<char,int> stdmap;
    stdmap.insert ( std::pair<char,int>('b',100) );
    stdmap.insert ( std::pair<char,int>('a',200) );
    stdmap.insert ( std::pair<char,int>('c',300) );
    std::map<char, int>::iterator stdit = stdmap.end();

    ft::map<char,int> mymap;
    mymap.insert ( std::pair<char,int>('b',100) );
    mymap.insert ( std::pair<char,int>('a',200) );
    mymap.insert ( std::pair<char,int>('c',300) );
    ft::map<char, int>::iterator myit = mymap.end();

    stdit--;
    myit--;
    REQUIRE(stdit->first == myit->first);
}

TEST_CASE("map - rbegin", "[map]") {
    int i = 3;
    ft::map<char,int> map;
    map.insert ( std::pair<char,int>('a',1) );
    map.insert ( std::pair<char,int>('b',2) );
    map.insert ( std::pair<char,int>('z',3) );
    ft::map<char, int>::reverse_iterator it=map.rbegin();

    std::map<char,int> stdmap;
    stdmap.insert ( std::pair<char,int>('a',1) );
    stdmap.insert ( std::pair<char,int>('b',2) );
    stdmap.insert ( std::pair<char,int>('z',3) );
    std::map<char, int>::reverse_iterator stdit=stdmap.rbegin();

    REQUIRE(it->first == stdit->first);

    for (it=map.rbegin(); it!=map.rend(); it++) {
        REQUIRE(it->second == i);
        i--;
    }
}

TEST_CASE("map - rend", "[map]") {
    std::map<char,int> stdmap;
    stdmap.insert ( std::pair<char,int>('b',100) );
    stdmap.insert ( std::pair<char,int>('a',200) );
    stdmap.insert ( std::pair<char,int>('c',300) );
    std::map<char, int>::reverse_iterator stdit = stdmap.rend();

    ft::map<char,int> mymap;
    mymap.insert ( std::pair<char,int>('b',100) );
    mymap.insert ( std::pair<char,int>('a',200) );
    mymap.insert ( std::pair<char,int>('c',300) );
    ft::map<char, int>::reverse_iterator myit = mymap.rend();

    stdit--;
    myit--;
    REQUIRE(stdit->first == myit->first);
}

TEST_CASE("map - empty", "[map]") {
    ft::map<char,int> map;
    REQUIRE(map.empty() == true);
    map.insert ( std::pair<char,int>('b',100) );
    REQUIRE(map.empty() == false);
}

TEST_CASE("map - size", "[map]") {
    ft::map<char,int> map;
    REQUIRE(map.size() == 0);
    map.insert ( std::pair<char,int>('b',100) );
    REQUIRE(map.size() == 1);
}

//TEST_CASE("map - max_size", "[map]") { //->nog even naar kijken
//    ft::map<char,int> map;
//    std::map<char,int> stdmap;
//    REQUIRE(map.max_size() == stdmap.max_size());
//}

//TEST_CASE("map - [] operator", "[map]") {
//
//}

TEST_CASE("map - insert", "[map]") {
    ft::map<char,int> mymap;

    // first insert function version (single parameter):
    mymap.insert ( std::pair<char,int>('a',100) );
    mymap.insert ( std::pair<char,int>('z',200) );
    REQUIRE(mymap.size() == 2);

    std::pair<ft::map<char,int>::iterator,bool> ret;
    ret = mymap.insert ( std::pair<char,int>('z',500) );
    REQUIRE(mymap.size() == 2);
    REQUIRE(ret.second == false);

    // second insert function version (with hint position):
    ft::map<char,int>::iterator it = mymap.begin();
    mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
    mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting
    REQUIRE(mymap.size() == 4);

    // third insert function version (range insertion):
    ft::map<char,int> anothermap;
    anothermap.insert(mymap.begin(),mymap.end());
    ft::map<char, int>::iterator secondit = anothermap.begin();

    for (it=mymap.begin(); it!=mymap.end(); it++) {
        REQUIRE(it->first == secondit->first);
        secondit++;
    }
}

TEST_CASE("map - erase", "[map]") {
    ft::map<char,int> mymap;

    // insert some values:
    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;
    mymap['d']=40;
    mymap['e']=50;
    mymap['f']=60;

    ft::map<char,int>::iterator it = mymap.begin();

    it++;
    mymap.erase (it);                   // erasing by iterator

    it = mymap.begin();
    it++;
    it++;

    mymap.erase ('c');                  // erasing by key
    REQUIRE(mymap.size() == 4);
    mymap.erase ('c');                  // erasing by key
    REQUIRE(mymap.size() == 4);

    it = mymap.begin();
    it++;
    it++;
    mymap.erase ( it, mymap.end() );    // erasing by range
    it = mymap.begin();
    REQUIRE(mymap.size() == 2);
    REQUIRE(it->second == 10);
    it++;
    REQUIRE(it->second == 40);
}


//TEST_CASE("stack - relational operator overloads", "[stack]") {
//    ft::stack<int> a;
//    a.push(10);
//    a.push(20);
//    a.push(30);
//    ft::stack<int> b;
//    b.push(10);
//    b.push(20);
//    b.push(30);
//    ft::stack<int> c;
//    c.push(30);
//    c.push(20);
//    c.push(10);
//
//    REQUIRE((a == b) == true);
//    REQUIRE((b != c) == true);
//    REQUIRE((b < c) == true);
//    REQUIRE((c > b) == true);
//    REQUIRE((a <= b) == true);
//    REQUIRE((a >= b) == true);
//
//    REQUIRE((a <= b) == true);
//    REQUIRE((a > b) == false);
//    REQUIRE((a < b) == false);
//    REQUIRE((a != b) == false);
//    REQUIRE((b > c) == false);
//    REQUIRE((b == c) == false);
//    REQUIRE((b != c) == true);
//}