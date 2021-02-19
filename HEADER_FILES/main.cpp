
#include <iostream>
#include "Map.hpp"
#include <stdio.h>
#include <map>

int     main() {
    ft::map<char,int> mymap;

    // first insert function version (single parameter):
    mymap.insert ( std::pair<char,int>('a',100) );
    mymap.insert ( std::pair<char,int>('z',200) );

    std::pair<ft::map<char,int>::iterator,bool> ret;
    ret = mymap.insert ( std::pair<char,int>('z',500) );

    // second insert function version (with hint position):
    ft::map<char,int>::iterator it = mymap.begin();
    mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
    mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting


    // third insert function version (range insertion):
    ft::map<char,int> anothermap;
    anothermap.insert(mymap.begin(),mymap.end());
    ft::map<char, int>::iterator secondit = anothermap.begin();


}