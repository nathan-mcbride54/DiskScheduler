# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nathan/Code/C/DiskScheduler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nathan/Code/C/DiskScheduler/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DiskScheduler.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DiskScheduler.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DiskScheduler.dir/flags.make

CMakeFiles/DiskScheduler.dir/main.c.o: CMakeFiles/DiskScheduler.dir/flags.make
CMakeFiles/DiskScheduler.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nathan/Code/C/DiskScheduler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/DiskScheduler.dir/main.c.o"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/DiskScheduler.dir/main.c.o   -c /home/nathan/Code/C/DiskScheduler/main.c

CMakeFiles/DiskScheduler.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DiskScheduler.dir/main.c.i"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nathan/Code/C/DiskScheduler/main.c > CMakeFiles/DiskScheduler.dir/main.c.i

CMakeFiles/DiskScheduler.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DiskScheduler.dir/main.c.s"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nathan/Code/C/DiskScheduler/main.c -o CMakeFiles/DiskScheduler.dir/main.c.s

# Object files for target DiskScheduler
DiskScheduler_OBJECTS = \
"CMakeFiles/DiskScheduler.dir/main.c.o"

# External object files for target DiskScheduler
DiskScheduler_EXTERNAL_OBJECTS =

DiskScheduler: CMakeFiles/DiskScheduler.dir/main.c.o
DiskScheduler: CMakeFiles/DiskScheduler.dir/build.make
DiskScheduler: CMakeFiles/DiskScheduler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nathan/Code/C/DiskScheduler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable DiskScheduler"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DiskScheduler.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DiskScheduler.dir/build: DiskScheduler

.PHONY : CMakeFiles/DiskScheduler.dir/build

CMakeFiles/DiskScheduler.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DiskScheduler.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DiskScheduler.dir/clean

CMakeFiles/DiskScheduler.dir/depend:
	cd /home/nathan/Code/C/DiskScheduler/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nathan/Code/C/DiskScheduler /home/nathan/Code/C/DiskScheduler /home/nathan/Code/C/DiskScheduler/cmake-build-debug /home/nathan/Code/C/DiskScheduler/cmake-build-debug /home/nathan/Code/C/DiskScheduler/cmake-build-debug/CMakeFiles/DiskScheduler.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DiskScheduler.dir/depend

