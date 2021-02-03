#include "catch.hpp"

#include <string>
#include <vector>

#include "../VECTOR/Vector.hpp"

TEST_CASE( "RandomAccesIterator", "[vector]") {
    ft::vector<std::string> ft_vector;
    std::vector<std::string> std_vector;

    ft_vector.push_back("hallo");
    std_vector.push_back("hallo");
    ft_vector.push_back("world");
    std_vector.push_back("world");
    ft_vector.push_back("here");
    std_vector.push_back("here");
    ft_vector.push_back("there");
    std_vector.push_back("there");

    ft::vector<std::string>::iterator ft_it = ft_vector.begin();
    std::vector<std::string>::iterator std_it = std_vector.begin();

    ft::vector<std::string>::iterator ft_it_end = ft_vector.end();
    std::vector<std::string>::iterator std_it_end = std_vector.end();

    ft::vector<int> ft_vector_int;
    ft_vector_int.push_back(2);
    ft_vector_int.push_back(4);

    ft::vector<int>::iterator ft_two = ft_vector_int.begin();
    ft::vector<int>::iterator ft_four = ft_vector_int.begin() + 1;

    SECTION("* overload") {
        ft_it++;
        std_it++;
        REQUIRE(*ft_it == *std_it);
    }
    SECTION("-> overload") {
    ft_it++;
    std_it++;
    REQUIRE(*ft_it->data() == *std_it->data());
    }
    SECTION("[] overload") {
        REQUIRE(ft_it[3] == "there");
        REQUIRE(ft_it[3] == std_it[3]);
    }
    SECTION("Increment - prefix and postfix") {
        REQUIRE(*ft_it == *std_it);
        ft_it++;
        std_it++;
        REQUIRE(*ft_it->data() == *std_it->data());
        ++ft_it;
        ++std_it;
        REQUIRE(*ft_it == *std_it);
    }
    SECTION("Decrement - prefix and postfix") {
        ft_it_end--;
        std_it_end--;
        REQUIRE(*ft_it_end->data() == *std_it_end->data());
        --ft_it_end;
        --std_it_end;
        REQUIRE(*ft_it_end == *std_it_end);
    }
    SECTION("+ overload") {
        ft_it = ft_it + 2;
        std_it = std_it + 2;
        REQUIRE(*ft_it == *std_it);
        int res = *ft_two + *ft_two;
        REQUIRE(res == 4);
    }
    SECTION("- overload") {
        ft_it_end = ft_it_end - 3;
        std_it_end = std_it_end - 3;
        REQUIRE(*ft_it_end == *std_it_end);
        int res = *ft_four - *ft_two;
        REQUIRE(res == 2);
    }
    SECTION("+= overload") {
        ft_it += 2;
        std_it += 2;
        REQUIRE(*ft_it == *std_it);
    }
    SECTION("-= overload") {
        ft_it_end -= 3;
        std_it_end -= 3;
        REQUIRE(*ft_it_end == *std_it_end);
    }
    SECTION("< overload") {
        bool res = *ft_two < *ft_four;
        REQUIRE(res == true);
    }
    SECTION("> overload") {
        bool res = *ft_two > *ft_four;
        REQUIRE(res == false);
    }
    SECTION("<= overload") {
        bool res = *ft_four <= *ft_four;
        REQUIRE(res == true);
        res = *ft_two <= *ft_two;
        REQUIRE(res == true);
    }
    SECTION(">= overload") {
        bool res = *ft_two > *ft_four;
        REQUIRE(res == false);
        res = *ft_two >= *ft_two;
        REQUIRE(res == true);
    }
    SECTION("== operator") {
        bool equal;
        equal = (*ft_it == *std_it);
        REQUIRE(equal == true);
        ++ft_it;
        equal = (*ft_it == *std_it);
        REQUIRE(equal == false);
    }
    SECTION("!= operator") {
        bool unequal;
        unequal = (*ft_it != *std_it);
        REQUIRE(unequal == false);
        ++std_it;
        unequal = (*ft_it != *std_it);
        REQUIRE(unequal == true);
    }
}
