# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wankun/Desktop/Algorithm/algorithm/Search/codevs1295nqueen

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wankun/Desktop/Algorithm/algorithm/Search/codevs1295nqueen/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/codevs1295nqueen.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/codevs1295nqueen.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/codevs1295nqueen.dir/flags.make

CMakeFiles/codevs1295nqueen.dir/main.cpp.o: CMakeFiles/codevs1295nqueen.dir/flags.make
CMakeFiles/codevs1295nqueen.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wankun/Desktop/Algorithm/algorithm/Search/codevs1295nqueen/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/codevs1295nqueen.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/codevs1295nqueen.dir/main.cpp.o -c /Users/wankun/Desktop/Algorithm/algorithm/Search/codevs1295nqueen/main.cpp

CMakeFiles/codevs1295nqueen.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/codevs1295nqueen.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wankun/Desktop/Algorithm/algorithm/Search/codevs1295nqueen/main.cpp > CMakeFiles/codevs1295nqueen.dir/main.cpp.i

CMakeFiles/codevs1295nqueen.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/codevs1295nqueen.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wankun/Desktop/Algorithm/algorithm/Search/codevs1295nqueen/main.cpp -o CMakeFiles/codevs1295nqueen.dir/main.cpp.s

CMakeFiles/codevs1295nqueen.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/codevs1295nqueen.dir/main.cpp.o.requires

CMakeFiles/codevs1295nqueen.dir/main.cpp.o.provides: CMakeFiles/codevs1295nqueen.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/codevs1295nqueen.dir/build.make CMakeFiles/codevs1295nqueen.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/codevs1295nqueen.dir/main.cpp.o.provides

CMakeFiles/codevs1295nqueen.dir/main.cpp.o.provides.build: CMakeFiles/codevs1295nqueen.dir/main.cpp.o


# Object files for target codevs1295nqueen
codevs1295nqueen_OBJECTS = \
"CMakeFiles/codevs1295nqueen.dir/main.cpp.o"

# External object files for target codevs1295nqueen
codevs1295nqueen_EXTERNAL_OBJECTS =

codevs1295nqueen: CMakeFiles/codevs1295nqueen.dir/main.cpp.o
codevs1295nqueen: CMakeFiles/codevs1295nqueen.dir/build.make
codevs1295nqueen: CMakeFiles/codevs1295nqueen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wankun/Desktop/Algorithm/algorithm/Search/codevs1295nqueen/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable codevs1295nqueen"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/codevs1295nqueen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/codevs1295nqueen.dir/build: codevs1295nqueen

.PHONY : CMakeFiles/codevs1295nqueen.dir/build

CMakeFiles/codevs1295nqueen.dir/requires: CMakeFiles/codevs1295nqueen.dir/main.cpp.o.requires

.PHONY : CMakeFiles/codevs1295nqueen.dir/requires

CMakeFiles/codevs1295nqueen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/codevs1295nqueen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/codevs1295nqueen.dir/clean

CMakeFiles/codevs1295nqueen.dir/depend:
	cd /Users/wankun/Desktop/Algorithm/algorithm/Search/codevs1295nqueen/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wankun/Desktop/Algorithm/algorithm/Search/codevs1295nqueen /Users/wankun/Desktop/Algorithm/algorithm/Search/codevs1295nqueen /Users/wankun/Desktop/Algorithm/algorithm/Search/codevs1295nqueen/cmake-build-debug /Users/wankun/Desktop/Algorithm/algorithm/Search/codevs1295nqueen/cmake-build-debug /Users/wankun/Desktop/Algorithm/algorithm/Search/codevs1295nqueen/cmake-build-debug/CMakeFiles/codevs1295nqueen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/codevs1295nqueen.dir/depend

