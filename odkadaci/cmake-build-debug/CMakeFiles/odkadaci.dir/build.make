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
CMAKE_COMMAND = /home/kvitajin/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.7319.72/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/kvitajin/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.7319.72/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kvitajin/CLionProjects/vsb/pa/odkadaci

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kvitajin/CLionProjects/vsb/pa/odkadaci/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/odkadaci.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/odkadaci.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/odkadaci.dir/flags.make

CMakeFiles/odkadaci.dir/main.cpp.o: CMakeFiles/odkadaci.dir/flags.make
CMakeFiles/odkadaci.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kvitajin/CLionProjects/vsb/pa/odkadaci/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/odkadaci.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/odkadaci.dir/main.cpp.o -c /home/kvitajin/CLionProjects/vsb/pa/odkadaci/main.cpp

CMakeFiles/odkadaci.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/odkadaci.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kvitajin/CLionProjects/vsb/pa/odkadaci/main.cpp > CMakeFiles/odkadaci.dir/main.cpp.i

CMakeFiles/odkadaci.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/odkadaci.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kvitajin/CLionProjects/vsb/pa/odkadaci/main.cpp -o CMakeFiles/odkadaci.dir/main.cpp.s

# Object files for target odkadaci
odkadaci_OBJECTS = \
"CMakeFiles/odkadaci.dir/main.cpp.o"

# External object files for target odkadaci
odkadaci_EXTERNAL_OBJECTS =

odkadaci: CMakeFiles/odkadaci.dir/main.cpp.o
odkadaci: CMakeFiles/odkadaci.dir/build.make
odkadaci: CMakeFiles/odkadaci.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kvitajin/CLionProjects/vsb/pa/odkadaci/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable odkadaci"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/odkadaci.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/odkadaci.dir/build: odkadaci

.PHONY : CMakeFiles/odkadaci.dir/build

CMakeFiles/odkadaci.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/odkadaci.dir/cmake_clean.cmake
.PHONY : CMakeFiles/odkadaci.dir/clean

CMakeFiles/odkadaci.dir/depend:
	cd /home/kvitajin/CLionProjects/vsb/pa/odkadaci/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kvitajin/CLionProjects/vsb/pa/odkadaci /home/kvitajin/CLionProjects/vsb/pa/odkadaci /home/kvitajin/CLionProjects/vsb/pa/odkadaci/cmake-build-debug /home/kvitajin/CLionProjects/vsb/pa/odkadaci/cmake-build-debug /home/kvitajin/CLionProjects/vsb/pa/odkadaci/cmake-build-debug/CMakeFiles/odkadaci.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/odkadaci.dir/depend

