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
CMAKE_COMMAND = "C:\Program Files (x86)\cmake-3.16.0-rc3-win32-x86\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\cmake-3.16.0-rc3-win32-x86\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\RickyLi\Documents\GitHub\c-learning\trytrywater\QuickStart

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\RickyLi\Documents\GitHub\c-learning\trytrywater\QuickStart\build

# Include any dependencies generated for this target.
include CMakeFiles/QuickStart.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/QuickStart.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/QuickStart.dir/flags.make

CMakeFiles/QuickStart.dir/QuickStart.cpp.obj: CMakeFiles/QuickStart.dir/flags.make
CMakeFiles/QuickStart.dir/QuickStart.cpp.obj: ../QuickStart.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\RickyLi\Documents\GitHub\c-learning\trytrywater\QuickStart\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/QuickStart.dir/QuickStart.cpp.obj"
	C:\MinGW\mingw64\bin\x86_64-w64-mingw32-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\QuickStart.dir\QuickStart.cpp.obj -c C:\Users\RickyLi\Documents\GitHub\c-learning\trytrywater\QuickStart\QuickStart.cpp

CMakeFiles/QuickStart.dir/QuickStart.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QuickStart.dir/QuickStart.cpp.i"
	C:\MinGW\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\RickyLi\Documents\GitHub\c-learning\trytrywater\QuickStart\QuickStart.cpp > CMakeFiles\QuickStart.dir\QuickStart.cpp.i

CMakeFiles/QuickStart.dir/QuickStart.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QuickStart.dir/QuickStart.cpp.s"
	C:\MinGW\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\RickyLi\Documents\GitHub\c-learning\trytrywater\QuickStart\QuickStart.cpp -o CMakeFiles\QuickStart.dir\QuickStart.cpp.s

# Object files for target QuickStart
QuickStart_OBJECTS = \
"CMakeFiles/QuickStart.dir/QuickStart.cpp.obj"

# External object files for target QuickStart
QuickStart_EXTERNAL_OBJECTS =

libQuickStart.a: CMakeFiles/QuickStart.dir/QuickStart.cpp.obj
libQuickStart.a: CMakeFiles/QuickStart.dir/build.make
libQuickStart.a: CMakeFiles/QuickStart.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\RickyLi\Documents\GitHub\c-learning\trytrywater\QuickStart\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libQuickStart.a"
	$(CMAKE_COMMAND) -P CMakeFiles\QuickStart.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\QuickStart.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/QuickStart.dir/build: libQuickStart.a

.PHONY : CMakeFiles/QuickStart.dir/build

CMakeFiles/QuickStart.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\QuickStart.dir\cmake_clean.cmake
.PHONY : CMakeFiles/QuickStart.dir/clean

CMakeFiles/QuickStart.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\RickyLi\Documents\GitHub\c-learning\trytrywater\QuickStart C:\Users\RickyLi\Documents\GitHub\c-learning\trytrywater\QuickStart C:\Users\RickyLi\Documents\GitHub\c-learning\trytrywater\QuickStart\build C:\Users\RickyLi\Documents\GitHub\c-learning\trytrywater\QuickStart\build C:\Users\RickyLi\Documents\GitHub\c-learning\trytrywater\QuickStart\build\CMakeFiles\QuickStart.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/QuickStart.dir/depend
