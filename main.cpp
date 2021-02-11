//
// Created by Roy Bakker on 19/01/2021.
//

#include <iostream>
#include <vector>
#include "HEADER_FILES/Vector.hpp"

int main ()
{
    std::vector<int> myvector;
    std::vector<int>::iterator it;

    // set some values (from 1 to 10)
    for (int i=1; i<=10; i++) myvector.push_back(i);

    // erase the 6th element
    myvector.erase (myvector.begin());

//    // erase the first 3 elements:
    myvector.erase (myvector.begin(),myvector.begin()+3);

    std::cout << "myvector contains:";
    for (unsigned i=0; i<myvector.size(); ++i)
        std::cout << ' ' << myvector[i];
    std::cout << '\n';

    return 0;
}