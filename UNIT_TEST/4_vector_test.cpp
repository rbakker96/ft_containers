#include "catch.hpp"

#include <vector>
#include "../VECTOR/Vector.hpp"

//clang++ -std=c++14 list_test.cpp catch.cpp -g -fsanitize=address

TEST_CASE( "vector - empty container constructor (default constructor)", "[vector]" ) {
    ft::vector<int> first;                                // empty list of ints
    REQUIRE(first.size() == 0);
}

TEST_CASE( "vector - fill constructor", "[vector]" ) {
    ft::vector<int> second (4,100);                // four ints with value 100
    REQUIRE(second.size() == 4);
}

TEST_CASE( "vector - range constructor", "[vector]" ) {
    ft::vector<int> second (5,100);
    ft::vector<int> third (second.begin(),second.end());  // iterating through second
    REQUIRE(third.size() == 5);
}

TEST_CASE( "vector - copy constructor", "[vector]" ) {
    ft::vector<int> second (5,100);
    ft::vector<int> fourth (second);                       // a copy of second
    REQUIRE(fourth.size() == second.size());
}

TEST_CASE( "vector - assignment operator", "[vector]" ) {
    ft::vector<int> second (5,100);

    ft::vector<int> fourth;
    fourth = second;                      // a copy of second

    REQUIRE(fourth.size() == second.size());
}

TEST_CASE( "vector - begin", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;

    for (int i=1; i<=5; i++) ft_vector.push_back(i);
    for (int i=1; i<=5; i++) std_vector.push_back(i);

    REQUIRE(*ft_vector.begin() == *std_vector.begin());
}

TEST_CASE( "vector - rbegin", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;

    for (int i=1; i<=5; i++) ft_vector.push_back(i);
    for (int i=1; i<=5; i++) std_vector.push_back(i);

    REQUIRE(*ft_vector.rbegin() == *std_vector.rbegin());
}

TEST_CASE( "vector - size", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;

    for (int i=1; i<=5; i++) ft_vector.push_back(i);
    for (int i=1; i<=5; i++) std_vector.push_back(i);

    REQUIRE(ft_vector.size() == std_vector.size());
}

TEST_CASE( "vector - max_size", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;

    REQUIRE(ft_vector.max_size() == std_vector.max_size());
}

TEST_CASE( "vector - resize", "[vector]" ) {
    ft::vector<int> ft_vector;
    for (int i=1; i<=10; i++) ft_vector.push_back(i);

    ft_vector.resize(10);
    REQUIRE(ft_vector.size() == 10);

    ft_vector.resize(5);
    REQUIRE(ft_vector.size() == 5);

    ft_vector.resize(15);
    REQUIRE(ft_vector.size() == 15);
}

TEST_CASE( "vector - capacity", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;

    for (int i=1; i<=5; i++) ft_vector.push_back(i);
    for (int i=1; i<=5; i++) std_vector.push_back(i);

    REQUIRE(ft_vector.capacity() == std_vector.capacity());
}

TEST_CASE( "vector - empty", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;

    REQUIRE(ft_vector.empty() == std_vector.empty());

    for (int i=1; i<=5; i++) ft_vector.push_back(i);
    for (int i=1; i<=5; i++) std_vector.push_back(i);

    REQUIRE(ft_vector.empty() == std_vector.empty());
}

TEST_CASE( "vector - reserve", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;

    for (int i=1; i<=5; i++) ft_vector.push_back(i);
    for (int i=1; i<=5; i++) std_vector.push_back(i);

    ft_vector.reserve(25);
    std_vector.reserve(25);

    REQUIRE(ft_vector.capacity() == std_vector.capacity());
}

TEST_CASE( "vector - shrink to fit", "[vector]" ) {
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;

    for (int i=1; i<=5; i++) ft_vector.push_back(i);
    for (int i=1; i<=5; i++) std_vector.push_back(i);

    ft_vector.shrink_to_fit();
    std_vector.shrink_to_fit();

    REQUIRE(ft_vector.capacity() == std_vector.capacity());
    REQUIRE(ft_vector.size() == std_vector.size());
}

TEST_CASE( "vector - operator []", "[vector]" ) {
    ft::vector<int> ft_vector;

    for (int i=0; i<=5; i++) ft_vector.push_back(i);

    REQUIRE(ft_vector[0] == 0);
    REQUIRE(ft_vector[3] == 3);
}

TEST_CASE( "vector - at", "[vector]" ) {
    ft::vector<int> myvector (10);   // 10 zero-initialized ints

    // assign some values:
    for (unsigned i=0; i<myvector.size(); i++)
        myvector.at(i)=i;

    REQUIRE(myvector.at(3) == 3);
    REQUIRE(myvector.at(6) == 6);
}

TEST_CASE( "vector - front", "[vector]" ) {
    ft::vector<int> myvector (10);   // 10 zero-initialized ints

    // assign some values:
    for (unsigned i=0; i<myvector.size(); i++)
        myvector.at(i)=i;

    REQUIRE(myvector.front() == 0);
}

TEST_CASE( "vector - back", "[vector]" ) {
    ft::vector<int> myvector (10);   // 10 zero-initialized ints

    // assign some values:
    for (unsigned i=0; i<myvector.size(); i++)
        myvector.at(i)=i;

    REQUIRE(myvector.back() == 9);
}

TEST_CASE( "vector - assign", "[vector]" ) {

}

TEST_CASE( "vector - insert", "[vector]" ) {

}

//TEST_CASE( "vector - assign", "[vector]" ) {
//
//}
//
//TEST_CASE( "vector - assign", "[vector]" ) {
//
//}
//
//TEST_CASE( "vector - assign", "[vector]" ) {
//
//}