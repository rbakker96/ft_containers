//
// Created by Roy Bakker on 27/01/2021.
//

TEST_CASE( "", "[list]" ) {

REQUIRE();
}



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
