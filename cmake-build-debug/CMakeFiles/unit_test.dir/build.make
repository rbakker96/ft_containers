# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/roybakker/Desktop/ft_containers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/roybakker/Desktop/ft_containers/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/unit_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/unit_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/unit_test.dir/flags.make

CMakeFiles/unit_test.dir/UNIT_TEST/catch.cpp.o: CMakeFiles/unit_test.dir/flags.make
CMakeFiles/unit_test.dir/UNIT_TEST/catch.cpp.o: ../UNIT_TEST/catch.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/roybakker/Desktop/ft_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/unit_test.dir/UNIT_TEST/catch.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unit_test.dir/UNIT_TEST/catch.cpp.o -c /Users/roybakker/Desktop/ft_containers/UNIT_TEST/catch.cpp

CMakeFiles/unit_test.dir/UNIT_TEST/catch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_test.dir/UNIT_TEST/catch.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/roybakker/Desktop/ft_containers/UNIT_TEST/catch.cpp > CMakeFiles/unit_test.dir/UNIT_TEST/catch.cpp.i

CMakeFiles/unit_test.dir/UNIT_TEST/catch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_test.dir/UNIT_TEST/catch.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/roybakker/Desktop/ft_containers/UNIT_TEST/catch.cpp -o CMakeFiles/unit_test.dir/UNIT_TEST/catch.cpp.s

CMakeFiles/unit_test.dir/UNIT_TEST/1_Bidirectionaliterator_test.cpp.o: CMakeFiles/unit_test.dir/flags.make
CMakeFiles/unit_test.dir/UNIT_TEST/1_Bidirectionaliterator_test.cpp.o: ../UNIT_TEST/1_Bidirectionaliterator_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/roybakker/Desktop/ft_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/unit_test.dir/UNIT_TEST/1_Bidirectionaliterator_test.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unit_test.dir/UNIT_TEST/1_Bidirectionaliterator_test.cpp.o -c /Users/roybakker/Desktop/ft_containers/UNIT_TEST/1_Bidirectionaliterator_test.cpp

CMakeFiles/unit_test.dir/UNIT_TEST/1_Bidirectionaliterator_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_test.dir/UNIT_TEST/1_Bidirectionaliterator_test.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/roybakker/Desktop/ft_containers/UNIT_TEST/1_Bidirectionaliterator_test.cpp > CMakeFiles/unit_test.dir/UNIT_TEST/1_Bidirectionaliterator_test.cpp.i

CMakeFiles/unit_test.dir/UNIT_TEST/1_Bidirectionaliterator_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_test.dir/UNIT_TEST/1_Bidirectionaliterator_test.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/roybakker/Desktop/ft_containers/UNIT_TEST/1_Bidirectionaliterator_test.cpp -o CMakeFiles/unit_test.dir/UNIT_TEST/1_Bidirectionaliterator_test.cpp.s

CMakeFiles/unit_test.dir/UNIT_TEST/2_RandomAccessIterator_test.cpp.o: CMakeFiles/unit_test.dir/flags.make
CMakeFiles/unit_test.dir/UNIT_TEST/2_RandomAccessIterator_test.cpp.o: ../UNIT_TEST/2_RandomAccessIterator_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/roybakker/Desktop/ft_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/unit_test.dir/UNIT_TEST/2_RandomAccessIterator_test.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unit_test.dir/UNIT_TEST/2_RandomAccessIterator_test.cpp.o -c /Users/roybakker/Desktop/ft_containers/UNIT_TEST/2_RandomAccessIterator_test.cpp

CMakeFiles/unit_test.dir/UNIT_TEST/2_RandomAccessIterator_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_test.dir/UNIT_TEST/2_RandomAccessIterator_test.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/roybakker/Desktop/ft_containers/UNIT_TEST/2_RandomAccessIterator_test.cpp > CMakeFiles/unit_test.dir/UNIT_TEST/2_RandomAccessIterator_test.cpp.i

CMakeFiles/unit_test.dir/UNIT_TEST/2_RandomAccessIterator_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_test.dir/UNIT_TEST/2_RandomAccessIterator_test.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/roybakker/Desktop/ft_containers/UNIT_TEST/2_RandomAccessIterator_test.cpp -o CMakeFiles/unit_test.dir/UNIT_TEST/2_RandomAccessIterator_test.cpp.s

CMakeFiles/unit_test.dir/UNIT_TEST/3_list_test.cpp.o: CMakeFiles/unit_test.dir/flags.make
CMakeFiles/unit_test.dir/UNIT_TEST/3_list_test.cpp.o: ../UNIT_TEST/3_list_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/roybakker/Desktop/ft_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/unit_test.dir/UNIT_TEST/3_list_test.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unit_test.dir/UNIT_TEST/3_list_test.cpp.o -c /Users/roybakker/Desktop/ft_containers/UNIT_TEST/3_list_test.cpp

CMakeFiles/unit_test.dir/UNIT_TEST/3_list_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_test.dir/UNIT_TEST/3_list_test.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/roybakker/Desktop/ft_containers/UNIT_TEST/3_list_test.cpp > CMakeFiles/unit_test.dir/UNIT_TEST/3_list_test.cpp.i

CMakeFiles/unit_test.dir/UNIT_TEST/3_list_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_test.dir/UNIT_TEST/3_list_test.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/roybakker/Desktop/ft_containers/UNIT_TEST/3_list_test.cpp -o CMakeFiles/unit_test.dir/UNIT_TEST/3_list_test.cpp.s

CMakeFiles/unit_test.dir/UNIT_TEST/4_vector_test.cpp.o: CMakeFiles/unit_test.dir/flags.make
CMakeFiles/unit_test.dir/UNIT_TEST/4_vector_test.cpp.o: ../UNIT_TEST/4_vector_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/roybakker/Desktop/ft_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/unit_test.dir/UNIT_TEST/4_vector_test.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unit_test.dir/UNIT_TEST/4_vector_test.cpp.o -c /Users/roybakker/Desktop/ft_containers/UNIT_TEST/4_vector_test.cpp

CMakeFiles/unit_test.dir/UNIT_TEST/4_vector_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_test.dir/UNIT_TEST/4_vector_test.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/roybakker/Desktop/ft_containers/UNIT_TEST/4_vector_test.cpp > CMakeFiles/unit_test.dir/UNIT_TEST/4_vector_test.cpp.i

CMakeFiles/unit_test.dir/UNIT_TEST/4_vector_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_test.dir/UNIT_TEST/4_vector_test.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/roybakker/Desktop/ft_containers/UNIT_TEST/4_vector_test.cpp -o CMakeFiles/unit_test.dir/UNIT_TEST/4_vector_test.cpp.s

# Object files for target unit_test
unit_test_OBJECTS = \
"CMakeFiles/unit_test.dir/UNIT_TEST/catch.cpp.o" \
"CMakeFiles/unit_test.dir/UNIT_TEST/1_Bidirectionaliterator_test.cpp.o" \
"CMakeFiles/unit_test.dir/UNIT_TEST/2_RandomAccessIterator_test.cpp.o" \
"CMakeFiles/unit_test.dir/UNIT_TEST/3_list_test.cpp.o" \
"CMakeFiles/unit_test.dir/UNIT_TEST/4_vector_test.cpp.o"

# External object files for target unit_test
unit_test_EXTERNAL_OBJECTS =

unit_test: CMakeFiles/unit_test.dir/UNIT_TEST/catch.cpp.o
unit_test: CMakeFiles/unit_test.dir/UNIT_TEST/1_Bidirectionaliterator_test.cpp.o
unit_test: CMakeFiles/unit_test.dir/UNIT_TEST/2_RandomAccessIterator_test.cpp.o
unit_test: CMakeFiles/unit_test.dir/UNIT_TEST/3_list_test.cpp.o
unit_test: CMakeFiles/unit_test.dir/UNIT_TEST/4_vector_test.cpp.o
unit_test: CMakeFiles/unit_test.dir/build.make
unit_test: CMakeFiles/unit_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/roybakker/Desktop/ft_containers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable unit_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unit_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/unit_test.dir/build: unit_test

.PHONY : CMakeFiles/unit_test.dir/build

CMakeFiles/unit_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/unit_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/unit_test.dir/clean

CMakeFiles/unit_test.dir/depend:
	cd /Users/roybakker/Desktop/ft_containers/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/roybakker/Desktop/ft_containers /Users/roybakker/Desktop/ft_containers /Users/roybakker/Desktop/ft_containers/cmake-build-debug /Users/roybakker/Desktop/ft_containers/cmake-build-debug /Users/roybakker/Desktop/ft_containers/cmake-build-debug/CMakeFiles/unit_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/unit_test.dir/depend

