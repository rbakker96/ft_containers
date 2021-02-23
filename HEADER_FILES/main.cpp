
#include <iostream>
#include "Map.hpp"
#include <stdio.h>
#include <map>

int     main() {
    int i = 1;
    ft::map<char,int> map;
    map.insert ( std::pair<char,int>('a',1) );
    map.insert ( std::pair<char,int>('a',2) );
    map.insert ( std::pair<char,int>('z',3) );
    ft::map<char, int>::iterator it;

    // show content:
    for (it=map.begin(); it!=map.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    return 0;
}

//cant yet erase first element;



