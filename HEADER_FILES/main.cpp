
#include <iostream>
#include "Map.hpp"
#include <stdio.h>
#include <map>

int     main() {
    ft::map<char,int> map;
    map.insert ( std::pair<char,int>('g',1) );
    map.insert ( std::pair<char,int>('b',2) );
    map.insert ( std::pair<char,int>('c',3) );
    map.insert ( std::pair<char,int>('a',2) );
    map.insert ( std::pair<char,int>('z',3) );
    map.insert ( std::pair<char,int>('f',2) );
    ft::map<char, int>::iterator it = map.begin();

    it++;
    map.erase(it);

    // show content:
    std::cout << '\n';
    for (it=map.begin(); it!=map.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    std::cout << '\n';

    it = map.begin();
    map.erase(it);

    // show content:
    std::cout << '\n';
    for (it=map.begin(); it!=map.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    std::cout << '\n';

    it = map.begin();
    map.erase(it);

    // show content:
    std::cout << '\n';
    for (it=map.begin(); it!=map.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    std::cout << '\n';

    it = map.begin();
    map.erase(it);

    // show content:
    std::cout << '\n';
    for (it=map.begin(); it!=map.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    std::cout << '\n';

    it = map.begin();
    map.erase(it);

    // show content:
    std::cout << '\n';
    for (it=map.begin(); it!=map.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    std::cout << '\n';

    it = map.begin();
    map.erase(it);


//    map.erase(map.begin(), map.end());

//    it = map.begin();
//    it++;
//    it++;
//    map.erase(it);
//
//    // show content:
//    for (it=map.begin(); it!=map.end(); ++it)
//        std::cout << it->first << " => " << it->second << '\n';

    return 0;
}

//cant yet erase first element;
