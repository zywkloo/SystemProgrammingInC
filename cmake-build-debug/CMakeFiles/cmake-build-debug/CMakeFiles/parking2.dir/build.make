# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/a41181/Desktop/Yiwei_Study_CS/COMP2401/A3/cmake-build-debug/CMakeFiles

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/a41181/Desktop/Yiwei_Study_CS/COMP2401/A3/cmake-build-debug/CMakeFiles/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/parking2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/parking2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/parking2.dir/flags.make

CMakeFiles/parking2.dir/Users/a41181/Desktop/Yiwei_Study_CS/COMP2401/A3/simulator2.c.o: CMakeFiles/parking2.dir/flags.make
CMakeFiles/parking2.dir/Users/a41181/Desktop/Yiwei_Study_CS/COMP2401/A3/simulator2.c.o: /Users/a41181/Desktop/Yiwei_Study_CS/COMP2401/A3/simulator2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/a41181/Desktop/Yiwei_Study_CS/COMP2401/A3/cmake-build-debug/CMakeFiles/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/parking2.dir/Users/a41181/Desktop/Yiwei_Study_CS/COMP2401/A3/simulator2.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/parking2.dir/Users/a41181/Desktop/Yiwei_Study_CS/COMP2401/A3/simulator2.c.o   -c /Users/a41181/Desktop/Yiwei_Study_CS/COMP2401/A3/simulator2.c

CMakeFiles/parking2.dir/Users/a41181/Desktop/Yiwei_Study_CS/COMP2401/A3/simulator2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/parking2.dir/Users/a41181/Desktop/Yiwei_Study_CS/COMP2401/A3/simulator2.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/a41181/Desktop/Yiwei_Study_CS/COMP2401/A3/simulator2.c > CMakeFiles/parking2.dir/Users/a41181/Desktop/Yiwei_Study_CS/COMP2401/A3/simulator2.c.i

CMakeFiles/parking2.dir/Users/a41181/Desktop/Yiwei_Study_CS/COMP2401/A3/simulator2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/parking2.dir/Users/a41181/Desktop/Yiwei_Study_CS/COMP2401/A3/simulator2.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/a41181/Desktop/Yiwei_Study_CS/COMP2401/A3/simulator2.c -o CMakeFiles/parking2.dir/Users/a41181/Desktop/Yiwei_Study_CS/COMP2401/A3/simulator2.c.s

# Object files for target parking2
parking2_OBJECTS = \
"CMakeFiles/parking2.dir/Users/a41181/Desktop/Yiwei_Study_CS/COMP2401/A3/simulator2.c.o"

# External object files for target parking2
parking2_EXTERNAL_OBJECTS =

parking2: CMakeFiles/parking2.dir/Users/a41181/Desktop/Yiwei_Study_CS/COMP2401/A3/simulator2.c.o
parking2: CMakeFiles/parking2.dir/build.make
parking2: CMakeFiles/parking2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/a41181/Desktop/Yiwei_Study_CS/COMP2401/A3/cmake-build-debug/CMakeFiles/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable parking2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/parking2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/parking2.dir/build: parking2

.PHONY : CMakeFiles/parking2.dir/build

CMakeFiles/parking2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/parking2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/parking2.dir/clean

CMakeFiles/parking2.dir/depend:
	cd /Users/a41181/Desktop/Yiwei_Study_CS/COMP2401/A3/cmake-build-debug/CMakeFiles/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/a41181/Desktop/Yiwei_Study_CS/COMP2401/A3/cmake-build-debug/CMakeFiles /Users/a41181/Desktop/Yiwei_Study_CS/COMP2401/A3/cmake-build-debug/CMakeFiles /Users/a41181/Desktop/Yiwei_Study_CS/COMP2401/A3/cmake-build-debug/CMakeFiles/cmake-build-debug /Users/a41181/Desktop/Yiwei_Study_CS/COMP2401/A3/cmake-build-debug/CMakeFiles/cmake-build-debug /Users/a41181/Desktop/Yiwei_Study_CS/COMP2401/A3/cmake-build-debug/CMakeFiles/cmake-build-debug/CMakeFiles/parking2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/parking2.dir/depend
