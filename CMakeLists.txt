cmake_minimum_required(VERSION 3.17)
project(ft_containers)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES UNIT_TEST/catch.cpp
            UNIT_TEST/catch.hpp
            UNIT_TEST/list_test.cpp
            Traits.hpp
            LIST/Iterator.hpp
            LIST/List.hpp
            LIST/Node.hpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

add_executable(unit_test ${SOURCES})