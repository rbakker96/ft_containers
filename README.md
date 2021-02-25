<p align="center">
  <img src="https://github.com/rbakker96/images/blob/master/codam_logo.png">
</p>

# ft_containers
***The multiple available containers in C++ all have a very different usage. To make sure you understand them all, let’s re-implement them!***

---

### Project summary
> 5th ring Codam project

In this project you will implement the various container types of the C++ standard template library. For each container, turn in the appropriately named class files. The namespace will always be ft and your containers will be tested using ft::<container>. You need to respect the structure of the reference container. If it’s missing a part of the Coplien form, do not implement it. As a reminder, we are coding in C++98, so any new feature of the containers MUST NOT be implemented, but every old feature (even deprecated) is expected.

---

### Technical considerations
> The project needs to comply with the following rules/functionalities.

- Implement the following containers, and turn in the necessary files <container>.hpp
- You must also provide a main.cpp which tests everything for your evaluations.
- The member function get_allocator is not expected here, the remaining member functions are. Non-member overloads are expected aswell.
- If the container has an iterator system, you must reimplent it.
- You can use https://www.cplusplus.com/ as a reference of what to implement.
- You cannot implement more public functions than the ones offered in the standard containers. Everything else must be private or protected. Each public function/- variable must be justified.
- For non-member overloads, the keyword friend is allowed. Each use of friend must be justified and will be checked during evaluation.

---

### File structure
    ft_containers/
    │
    ├── HEADER_FILES/
    │   ├── UTILS
    │   │   ├── BiDirectionalIterator.hpp
    │   │   ├── listNode.hpp
    │   │   ├── mapNode.hpp
    │   │   ├── RandomAccessIterator.hpp
    │   │   └── Traits.hpp
    │   ├── List.hpp
    │   ├── Map.hpp
    │   ├── Queue.hpp
    │   ├── Stack.hpp
    │   └── Vector.hpp
    │
    ├── UNIT_TEST/
    │   ├── catch.cpp
    │   ├── catch.hpp
    │   ├── 1_Bidirectionaliterator_test.cpp
    │   ├── 2_RandomAccessIterator_test.cpp
    │   ├── 3_list_test.cpp
    │   ├── 4_vector_test.cpp
    │   ├── 5_queue_test.cpp
    │   ├── 6_stack_test.cpp
    │   └── 7_map_test.cpp
    │
    ├── CMakeList.txt
    └── Makefile

---

### Usage
> Run the following commands in the terminal

```shell
$ https://github.com/rbakker96/ft_containers.git ft_containers
$ cd ft_containers

-> Using CMakeList.txt
-> Use 'Run' button to test all testcases at once or edit 
   debug configurations to specify on label ([list], [map], ect.)

-> Using Makefile
$ make
$ ./ft_container                    (test all testcases at once)
$ ./ft_container "[list]"           (test specific container)
$ ./ft_container "[list]" "[map]"   (test specific selection of container)
```

---

### Used resources
> Most noteworthy resources used during this project

- <a href="https://www.cplusplus.com/reference/stl/" target="_blank">Standard Containers reference</a>
- <a href="https://github.com/catchorg/Catch2" target="_blank">Catch2 framework for unit testing</a>
- <a href="https://www.cplusplus.com/reference/iterator/" target="_blank">Iterator reference</a>
- <a href="https://algorithmtutor.com/Data-Structures/Tree/Binary-Search-Trees/" target="_blank">Binary Search Tree documentation</a>
- <a href="https://en.cppreference.com/w/cpp/language/sfinae" target="_blank">SFINAE "Substitution Failure Is Not An Error"</a>
- <a href="https://www.cprogramming.com/tutorial/typedef.html#:~:text=The%20typedef%20keyword%20allows%20the,data%20types%20that%20you%20use." target="_blank">The Typedef Keyword in C and C++</a>
- <a href="http://cppedinburgh.uk/slides/201603-tmp.pdf" target="_blank">An Introduction to Template Metaprogramming</a>
