# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.1.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\lenzer\CLionProjects\treeC++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\lenzer\CLionProjects\treeC++\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/treeC__.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/treeC__.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/treeC__.dir/flags.make

CMakeFiles/treeC__.dir/main.cpp.obj: CMakeFiles/treeC__.dir/flags.make
CMakeFiles/treeC__.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\lenzer\CLionProjects\treeC++\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/treeC__.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\treeC__.dir\main.cpp.obj -c C:\Users\lenzer\CLionProjects\treeC++\main.cpp

CMakeFiles/treeC__.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/treeC__.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\lenzer\CLionProjects\treeC++\main.cpp > CMakeFiles\treeC__.dir\main.cpp.i

CMakeFiles/treeC__.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/treeC__.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\lenzer\CLionProjects\treeC++\main.cpp -o CMakeFiles\treeC__.dir\main.cpp.s

# Object files for target treeC__
treeC___OBJECTS = \
"CMakeFiles/treeC__.dir/main.cpp.obj"

# External object files for target treeC__
treeC___EXTERNAL_OBJECTS =

treeC__.exe: CMakeFiles/treeC__.dir/main.cpp.obj
treeC__.exe: CMakeFiles/treeC__.dir/build.make
treeC__.exe: CMakeFiles/treeC__.dir/linklibs.rsp
treeC__.exe: CMakeFiles/treeC__.dir/objects1.rsp
treeC__.exe: CMakeFiles/treeC__.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\lenzer\CLionProjects\treeC++\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable treeC__.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\treeC__.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/treeC__.dir/build: treeC__.exe

.PHONY : CMakeFiles/treeC__.dir/build

CMakeFiles/treeC__.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\treeC__.dir\cmake_clean.cmake
.PHONY : CMakeFiles/treeC__.dir/clean

CMakeFiles/treeC__.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\lenzer\CLionProjects\treeC++ C:\Users\lenzer\CLionProjects\treeC++ C:\Users\lenzer\CLionProjects\treeC++\cmake-build-debug C:\Users\lenzer\CLionProjects\treeC++\cmake-build-debug C:\Users\lenzer\CLionProjects\treeC++\cmake-build-debug\CMakeFiles\treeC__.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/treeC__.dir/depend

