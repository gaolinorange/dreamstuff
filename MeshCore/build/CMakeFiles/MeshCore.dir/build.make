# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.6

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /opt/local/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mac/MeshDeformer/trunk/MeshCore

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mac/MeshDeformer/trunk/MeshCore/build

# Include any dependencies generated for this target.
include CMakeFiles/MeshCore.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MeshCore.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MeshCore.dir/flags.make

CMakeFiles/MeshCore.dir/MeshCore.cpp.o: CMakeFiles/MeshCore.dir/flags.make
CMakeFiles/MeshCore.dir/MeshCore.cpp.o: ../MeshCore.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/mac/MeshDeformer/trunk/MeshCore/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/MeshCore.dir/MeshCore.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/MeshCore.dir/MeshCore.cpp.o -c /Users/mac/MeshDeformer/trunk/MeshCore/MeshCore.cpp

CMakeFiles/MeshCore.dir/MeshCore.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MeshCore.dir/MeshCore.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/mac/MeshDeformer/trunk/MeshCore/MeshCore.cpp > CMakeFiles/MeshCore.dir/MeshCore.cpp.i

CMakeFiles/MeshCore.dir/MeshCore.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MeshCore.dir/MeshCore.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/mac/MeshDeformer/trunk/MeshCore/MeshCore.cpp -o CMakeFiles/MeshCore.dir/MeshCore.cpp.s

CMakeFiles/MeshCore.dir/MeshCore.cpp.o.requires:
.PHONY : CMakeFiles/MeshCore.dir/MeshCore.cpp.o.requires

CMakeFiles/MeshCore.dir/MeshCore.cpp.o.provides: CMakeFiles/MeshCore.dir/MeshCore.cpp.o.requires
	$(MAKE) -f CMakeFiles/MeshCore.dir/build.make CMakeFiles/MeshCore.dir/MeshCore.cpp.o.provides.build
.PHONY : CMakeFiles/MeshCore.dir/MeshCore.cpp.o.provides

CMakeFiles/MeshCore.dir/MeshCore.cpp.o.provides.build: CMakeFiles/MeshCore.dir/MeshCore.cpp.o
.PHONY : CMakeFiles/MeshCore.dir/MeshCore.cpp.o.provides.build

# Object files for target MeshCore
MeshCore_OBJECTS = \
"CMakeFiles/MeshCore.dir/MeshCore.cpp.o"

# External object files for target MeshCore
MeshCore_EXTERNAL_OBJECTS =

libMeshCore.a: CMakeFiles/MeshCore.dir/MeshCore.cpp.o
libMeshCore.a: CMakeFiles/MeshCore.dir/build.make
libMeshCore.a: CMakeFiles/MeshCore.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libMeshCore.a"
	$(CMAKE_COMMAND) -P CMakeFiles/MeshCore.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MeshCore.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MeshCore.dir/build: libMeshCore.a
.PHONY : CMakeFiles/MeshCore.dir/build

CMakeFiles/MeshCore.dir/requires: CMakeFiles/MeshCore.dir/MeshCore.cpp.o.requires
.PHONY : CMakeFiles/MeshCore.dir/requires

CMakeFiles/MeshCore.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MeshCore.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MeshCore.dir/clean

CMakeFiles/MeshCore.dir/depend:
	cd /Users/mac/MeshDeformer/trunk/MeshCore/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mac/MeshDeformer/trunk/MeshCore /Users/mac/MeshDeformer/trunk/MeshCore /Users/mac/MeshDeformer/trunk/MeshCore/build /Users/mac/MeshDeformer/trunk/MeshCore/build /Users/mac/MeshDeformer/trunk/MeshCore/build/CMakeFiles/MeshCore.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MeshCore.dir/depend

