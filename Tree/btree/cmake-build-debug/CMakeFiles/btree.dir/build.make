# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = "D:\CLion\CLion 2020.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion\CLion 2020.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\liuxu\Desktop\C&learn\Data_Structure\Tree\btree"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\liuxu\Desktop\C&learn\Data_Structure\Tree\btree\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/btree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/btree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/btree.dir/flags.make

CMakeFiles/btree.dir/main.c.obj: CMakeFiles/btree.dir/flags.make
CMakeFiles/btree.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\liuxu\Desktop\C&learn\Data_Structure\Tree\btree\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/btree.dir/main.c.obj"
	"D:\MinGW\x86_64-7.3.0-release-posix-seh-rt_v5-rev0 (1)\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\btree.dir\main.c.obj   -c "C:\Users\liuxu\Desktop\C&learn\Data_Structure\Tree\btree\main.c"

CMakeFiles/btree.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/btree.dir/main.c.i"
	"D:\MinGW\x86_64-7.3.0-release-posix-seh-rt_v5-rev0 (1)\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\liuxu\Desktop\C&learn\Data_Structure\Tree\btree\main.c" > CMakeFiles\btree.dir\main.c.i

CMakeFiles/btree.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/btree.dir/main.c.s"
	"D:\MinGW\x86_64-7.3.0-release-posix-seh-rt_v5-rev0 (1)\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\liuxu\Desktop\C&learn\Data_Structure\Tree\btree\main.c" -o CMakeFiles\btree.dir\main.c.s

# Object files for target btree
btree_OBJECTS = \
"CMakeFiles/btree.dir/main.c.obj"

# External object files for target btree
btree_EXTERNAL_OBJECTS =

btree.exe: CMakeFiles/btree.dir/main.c.obj
btree.exe: CMakeFiles/btree.dir/build.make
btree.exe: CMakeFiles/btree.dir/linklibs.rsp
btree.exe: CMakeFiles/btree.dir/objects1.rsp
btree.exe: CMakeFiles/btree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\liuxu\Desktop\C&learn\Data_Structure\Tree\btree\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable btree.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\btree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/btree.dir/build: btree.exe

.PHONY : CMakeFiles/btree.dir/build

CMakeFiles/btree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\btree.dir\cmake_clean.cmake
.PHONY : CMakeFiles/btree.dir/clean

CMakeFiles/btree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\liuxu\Desktop\C&learn\Data_Structure\Tree\btree" "C:\Users\liuxu\Desktop\C&learn\Data_Structure\Tree\btree" "C:\Users\liuxu\Desktop\C&learn\Data_Structure\Tree\btree\cmake-build-debug" "C:\Users\liuxu\Desktop\C&learn\Data_Structure\Tree\btree\cmake-build-debug" "C:\Users\liuxu\Desktop\C&learn\Data_Structure\Tree\btree\cmake-build-debug\CMakeFiles\btree.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/btree.dir/depend

