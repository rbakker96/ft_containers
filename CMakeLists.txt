cmake_minimum_required(VERSION 3.17)
project(ft_containers)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES UNIT_TEST/catch.cpp
            UNIT_TEST/catch.hpp
            UNIT_TEST/1_Bidirectionaliterator_test.cpp
            UNIT_TEST/2_RandomAccessIterator_test.cpp
            UNIT_TEST/3_list_test.cpp
            UNIT_TEST/4_vector_test.cpp
            UNIT_TEST/5_queue_test.cpp
            UNIT_TEST/6_stack_test.cpp
            UNIT_TEST/7_map_test.cpp
            HEADER_FILES/UTILS/Traits.hpp
            HEADER_FILES/UTILS/Pair.hpp
            HEADER_FILES/UTILS/BiDirectionalIterator.hpp
            HEADER_FILES/UTILS/RandomAccessIterator.hpp
            HEADER_FILES/List.hpp
            HEADER_FILES/UTILS/listNode.hpp
            HEADER_FILES/UTILS/mapNode.hpp UNIT_TEST/0_main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

add_executable(UNIT_TEST ${SOURCES})