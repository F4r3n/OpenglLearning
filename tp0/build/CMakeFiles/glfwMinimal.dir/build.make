# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/guillaume/Documents/tp/opengl/opengl/tp0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/guillaume/Documents/tp/opengl/opengl/tp0/build

# Include any dependencies generated for this target.
include CMakeFiles/glfwMinimal.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/glfwMinimal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/glfwMinimal.dir/flags.make

CMakeFiles/glfwMinimal.dir/glfwMinimal.cpp.o: CMakeFiles/glfwMinimal.dir/flags.make
CMakeFiles/glfwMinimal.dir/glfwMinimal.cpp.o: ../glfwMinimal.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/guillaume/Documents/tp/opengl/opengl/tp0/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/glfwMinimal.dir/glfwMinimal.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/glfwMinimal.dir/glfwMinimal.cpp.o -c /home/guillaume/Documents/tp/opengl/opengl/tp0/glfwMinimal.cpp

CMakeFiles/glfwMinimal.dir/glfwMinimal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glfwMinimal.dir/glfwMinimal.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/guillaume/Documents/tp/opengl/opengl/tp0/glfwMinimal.cpp > CMakeFiles/glfwMinimal.dir/glfwMinimal.cpp.i

CMakeFiles/glfwMinimal.dir/glfwMinimal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glfwMinimal.dir/glfwMinimal.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/guillaume/Documents/tp/opengl/opengl/tp0/glfwMinimal.cpp -o CMakeFiles/glfwMinimal.dir/glfwMinimal.cpp.s

CMakeFiles/glfwMinimal.dir/glfwMinimal.cpp.o.requires:
.PHONY : CMakeFiles/glfwMinimal.dir/glfwMinimal.cpp.o.requires

CMakeFiles/glfwMinimal.dir/glfwMinimal.cpp.o.provides: CMakeFiles/glfwMinimal.dir/glfwMinimal.cpp.o.requires
	$(MAKE) -f CMakeFiles/glfwMinimal.dir/build.make CMakeFiles/glfwMinimal.dir/glfwMinimal.cpp.o.provides.build
.PHONY : CMakeFiles/glfwMinimal.dir/glfwMinimal.cpp.o.provides

CMakeFiles/glfwMinimal.dir/glfwMinimal.cpp.o.provides.build: CMakeFiles/glfwMinimal.dir/glfwMinimal.cpp.o

CMakeFiles/glfwMinimal.dir/camera.cpp.o: CMakeFiles/glfwMinimal.dir/flags.make
CMakeFiles/glfwMinimal.dir/camera.cpp.o: ../camera.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/guillaume/Documents/tp/opengl/opengl/tp0/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/glfwMinimal.dir/camera.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/glfwMinimal.dir/camera.cpp.o -c /home/guillaume/Documents/tp/opengl/opengl/tp0/camera.cpp

CMakeFiles/glfwMinimal.dir/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glfwMinimal.dir/camera.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/guillaume/Documents/tp/opengl/opengl/tp0/camera.cpp > CMakeFiles/glfwMinimal.dir/camera.cpp.i

CMakeFiles/glfwMinimal.dir/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glfwMinimal.dir/camera.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/guillaume/Documents/tp/opengl/opengl/tp0/camera.cpp -o CMakeFiles/glfwMinimal.dir/camera.cpp.s

CMakeFiles/glfwMinimal.dir/camera.cpp.o.requires:
.PHONY : CMakeFiles/glfwMinimal.dir/camera.cpp.o.requires

CMakeFiles/glfwMinimal.dir/camera.cpp.o.provides: CMakeFiles/glfwMinimal.dir/camera.cpp.o.requires
	$(MAKE) -f CMakeFiles/glfwMinimal.dir/build.make CMakeFiles/glfwMinimal.dir/camera.cpp.o.provides.build
.PHONY : CMakeFiles/glfwMinimal.dir/camera.cpp.o.provides

CMakeFiles/glfwMinimal.dir/camera.cpp.o.provides.build: CMakeFiles/glfwMinimal.dir/camera.cpp.o

CMakeFiles/glfwMinimal.dir/gameObject.cpp.o: CMakeFiles/glfwMinimal.dir/flags.make
CMakeFiles/glfwMinimal.dir/gameObject.cpp.o: ../gameObject.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/guillaume/Documents/tp/opengl/opengl/tp0/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/glfwMinimal.dir/gameObject.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/glfwMinimal.dir/gameObject.cpp.o -c /home/guillaume/Documents/tp/opengl/opengl/tp0/gameObject.cpp

CMakeFiles/glfwMinimal.dir/gameObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glfwMinimal.dir/gameObject.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/guillaume/Documents/tp/opengl/opengl/tp0/gameObject.cpp > CMakeFiles/glfwMinimal.dir/gameObject.cpp.i

CMakeFiles/glfwMinimal.dir/gameObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glfwMinimal.dir/gameObject.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/guillaume/Documents/tp/opengl/opengl/tp0/gameObject.cpp -o CMakeFiles/glfwMinimal.dir/gameObject.cpp.s

CMakeFiles/glfwMinimal.dir/gameObject.cpp.o.requires:
.PHONY : CMakeFiles/glfwMinimal.dir/gameObject.cpp.o.requires

CMakeFiles/glfwMinimal.dir/gameObject.cpp.o.provides: CMakeFiles/glfwMinimal.dir/gameObject.cpp.o.requires
	$(MAKE) -f CMakeFiles/glfwMinimal.dir/build.make CMakeFiles/glfwMinimal.dir/gameObject.cpp.o.provides.build
.PHONY : CMakeFiles/glfwMinimal.dir/gameObject.cpp.o.provides

CMakeFiles/glfwMinimal.dir/gameObject.cpp.o.provides.build: CMakeFiles/glfwMinimal.dir/gameObject.cpp.o

CMakeFiles/glfwMinimal.dir/gameTorus.cpp.o: CMakeFiles/glfwMinimal.dir/flags.make
CMakeFiles/glfwMinimal.dir/gameTorus.cpp.o: ../gameTorus.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/guillaume/Documents/tp/opengl/opengl/tp0/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/glfwMinimal.dir/gameTorus.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/glfwMinimal.dir/gameTorus.cpp.o -c /home/guillaume/Documents/tp/opengl/opengl/tp0/gameTorus.cpp

CMakeFiles/glfwMinimal.dir/gameTorus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glfwMinimal.dir/gameTorus.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/guillaume/Documents/tp/opengl/opengl/tp0/gameTorus.cpp > CMakeFiles/glfwMinimal.dir/gameTorus.cpp.i

CMakeFiles/glfwMinimal.dir/gameTorus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glfwMinimal.dir/gameTorus.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/guillaume/Documents/tp/opengl/opengl/tp0/gameTorus.cpp -o CMakeFiles/glfwMinimal.dir/gameTorus.cpp.s

CMakeFiles/glfwMinimal.dir/gameTorus.cpp.o.requires:
.PHONY : CMakeFiles/glfwMinimal.dir/gameTorus.cpp.o.requires

CMakeFiles/glfwMinimal.dir/gameTorus.cpp.o.provides: CMakeFiles/glfwMinimal.dir/gameTorus.cpp.o.requires
	$(MAKE) -f CMakeFiles/glfwMinimal.dir/build.make CMakeFiles/glfwMinimal.dir/gameTorus.cpp.o.provides.build
.PHONY : CMakeFiles/glfwMinimal.dir/gameTorus.cpp.o.provides

CMakeFiles/glfwMinimal.dir/gameTorus.cpp.o.provides.build: CMakeFiles/glfwMinimal.dir/gameTorus.cpp.o

CMakeFiles/glfwMinimal.dir/stage.cpp.o: CMakeFiles/glfwMinimal.dir/flags.make
CMakeFiles/glfwMinimal.dir/stage.cpp.o: ../stage.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/guillaume/Documents/tp/opengl/opengl/tp0/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/glfwMinimal.dir/stage.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/glfwMinimal.dir/stage.cpp.o -c /home/guillaume/Documents/tp/opengl/opengl/tp0/stage.cpp

CMakeFiles/glfwMinimal.dir/stage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glfwMinimal.dir/stage.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/guillaume/Documents/tp/opengl/opengl/tp0/stage.cpp > CMakeFiles/glfwMinimal.dir/stage.cpp.i

CMakeFiles/glfwMinimal.dir/stage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glfwMinimal.dir/stage.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/guillaume/Documents/tp/opengl/opengl/tp0/stage.cpp -o CMakeFiles/glfwMinimal.dir/stage.cpp.s

CMakeFiles/glfwMinimal.dir/stage.cpp.o.requires:
.PHONY : CMakeFiles/glfwMinimal.dir/stage.cpp.o.requires

CMakeFiles/glfwMinimal.dir/stage.cpp.o.provides: CMakeFiles/glfwMinimal.dir/stage.cpp.o.requires
	$(MAKE) -f CMakeFiles/glfwMinimal.dir/build.make CMakeFiles/glfwMinimal.dir/stage.cpp.o.provides.build
.PHONY : CMakeFiles/glfwMinimal.dir/stage.cpp.o.provides

CMakeFiles/glfwMinimal.dir/stage.cpp.o.provides.build: CMakeFiles/glfwMinimal.dir/stage.cpp.o

CMakeFiles/glfwMinimal.dir/game.cpp.o: CMakeFiles/glfwMinimal.dir/flags.make
CMakeFiles/glfwMinimal.dir/game.cpp.o: ../game.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/guillaume/Documents/tp/opengl/opengl/tp0/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/glfwMinimal.dir/game.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/glfwMinimal.dir/game.cpp.o -c /home/guillaume/Documents/tp/opengl/opengl/tp0/game.cpp

CMakeFiles/glfwMinimal.dir/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glfwMinimal.dir/game.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/guillaume/Documents/tp/opengl/opengl/tp0/game.cpp > CMakeFiles/glfwMinimal.dir/game.cpp.i

CMakeFiles/glfwMinimal.dir/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glfwMinimal.dir/game.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/guillaume/Documents/tp/opengl/opengl/tp0/game.cpp -o CMakeFiles/glfwMinimal.dir/game.cpp.s

CMakeFiles/glfwMinimal.dir/game.cpp.o.requires:
.PHONY : CMakeFiles/glfwMinimal.dir/game.cpp.o.requires

CMakeFiles/glfwMinimal.dir/game.cpp.o.provides: CMakeFiles/glfwMinimal.dir/game.cpp.o.requires
	$(MAKE) -f CMakeFiles/glfwMinimal.dir/build.make CMakeFiles/glfwMinimal.dir/game.cpp.o.provides.build
.PHONY : CMakeFiles/glfwMinimal.dir/game.cpp.o.provides

CMakeFiles/glfwMinimal.dir/game.cpp.o.provides.build: CMakeFiles/glfwMinimal.dir/game.cpp.o

CMakeFiles/glfwMinimal.dir/gameSphere.cpp.o: CMakeFiles/glfwMinimal.dir/flags.make
CMakeFiles/glfwMinimal.dir/gameSphere.cpp.o: ../gameSphere.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/guillaume/Documents/tp/opengl/opengl/tp0/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/glfwMinimal.dir/gameSphere.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/glfwMinimal.dir/gameSphere.cpp.o -c /home/guillaume/Documents/tp/opengl/opengl/tp0/gameSphere.cpp

CMakeFiles/glfwMinimal.dir/gameSphere.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glfwMinimal.dir/gameSphere.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/guillaume/Documents/tp/opengl/opengl/tp0/gameSphere.cpp > CMakeFiles/glfwMinimal.dir/gameSphere.cpp.i

CMakeFiles/glfwMinimal.dir/gameSphere.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glfwMinimal.dir/gameSphere.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/guillaume/Documents/tp/opengl/opengl/tp0/gameSphere.cpp -o CMakeFiles/glfwMinimal.dir/gameSphere.cpp.s

CMakeFiles/glfwMinimal.dir/gameSphere.cpp.o.requires:
.PHONY : CMakeFiles/glfwMinimal.dir/gameSphere.cpp.o.requires

CMakeFiles/glfwMinimal.dir/gameSphere.cpp.o.provides: CMakeFiles/glfwMinimal.dir/gameSphere.cpp.o.requires
	$(MAKE) -f CMakeFiles/glfwMinimal.dir/build.make CMakeFiles/glfwMinimal.dir/gameSphere.cpp.o.provides.build
.PHONY : CMakeFiles/glfwMinimal.dir/gameSphere.cpp.o.provides

CMakeFiles/glfwMinimal.dir/gameSphere.cpp.o.provides.build: CMakeFiles/glfwMinimal.dir/gameSphere.cpp.o

CMakeFiles/glfwMinimal.dir/textures.cpp.o: CMakeFiles/glfwMinimal.dir/flags.make
CMakeFiles/glfwMinimal.dir/textures.cpp.o: ../textures.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/guillaume/Documents/tp/opengl/opengl/tp0/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/glfwMinimal.dir/textures.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/glfwMinimal.dir/textures.cpp.o -c /home/guillaume/Documents/tp/opengl/opengl/tp0/textures.cpp

CMakeFiles/glfwMinimal.dir/textures.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glfwMinimal.dir/textures.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/guillaume/Documents/tp/opengl/opengl/tp0/textures.cpp > CMakeFiles/glfwMinimal.dir/textures.cpp.i

CMakeFiles/glfwMinimal.dir/textures.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glfwMinimal.dir/textures.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/guillaume/Documents/tp/opengl/opengl/tp0/textures.cpp -o CMakeFiles/glfwMinimal.dir/textures.cpp.s

CMakeFiles/glfwMinimal.dir/textures.cpp.o.requires:
.PHONY : CMakeFiles/glfwMinimal.dir/textures.cpp.o.requires

CMakeFiles/glfwMinimal.dir/textures.cpp.o.provides: CMakeFiles/glfwMinimal.dir/textures.cpp.o.requires
	$(MAKE) -f CMakeFiles/glfwMinimal.dir/build.make CMakeFiles/glfwMinimal.dir/textures.cpp.o.provides.build
.PHONY : CMakeFiles/glfwMinimal.dir/textures.cpp.o.provides

CMakeFiles/glfwMinimal.dir/textures.cpp.o.provides.build: CMakeFiles/glfwMinimal.dir/textures.cpp.o

# Object files for target glfwMinimal
glfwMinimal_OBJECTS = \
"CMakeFiles/glfwMinimal.dir/glfwMinimal.cpp.o" \
"CMakeFiles/glfwMinimal.dir/camera.cpp.o" \
"CMakeFiles/glfwMinimal.dir/gameObject.cpp.o" \
"CMakeFiles/glfwMinimal.dir/gameTorus.cpp.o" \
"CMakeFiles/glfwMinimal.dir/stage.cpp.o" \
"CMakeFiles/glfwMinimal.dir/game.cpp.o" \
"CMakeFiles/glfwMinimal.dir/gameSphere.cpp.o" \
"CMakeFiles/glfwMinimal.dir/textures.cpp.o"

# External object files for target glfwMinimal
glfwMinimal_EXTERNAL_OBJECTS =

glfwMinimal: CMakeFiles/glfwMinimal.dir/glfwMinimal.cpp.o
glfwMinimal: CMakeFiles/glfwMinimal.dir/camera.cpp.o
glfwMinimal: CMakeFiles/glfwMinimal.dir/gameObject.cpp.o
glfwMinimal: CMakeFiles/glfwMinimal.dir/gameTorus.cpp.o
glfwMinimal: CMakeFiles/glfwMinimal.dir/stage.cpp.o
glfwMinimal: CMakeFiles/glfwMinimal.dir/game.cpp.o
glfwMinimal: CMakeFiles/glfwMinimal.dir/gameSphere.cpp.o
glfwMinimal: CMakeFiles/glfwMinimal.dir/textures.cpp.o
glfwMinimal: CMakeFiles/glfwMinimal.dir/build.make
glfwMinimal: /usr/lib/x86_64-linux-gnu/libGLU.so
glfwMinimal: /usr/lib/x86_64-linux-gnu/libGL.so
glfwMinimal: /usr/lib/x86_64-linux-gnu/libSM.so
glfwMinimal: /usr/lib/x86_64-linux-gnu/libICE.so
glfwMinimal: /usr/lib/x86_64-linux-gnu/libX11.so
glfwMinimal: /usr/lib/x86_64-linux-gnu/libXext.so
glfwMinimal: CMakeFiles/glfwMinimal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable glfwMinimal"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glfwMinimal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/glfwMinimal.dir/build: glfwMinimal
.PHONY : CMakeFiles/glfwMinimal.dir/build

CMakeFiles/glfwMinimal.dir/requires: CMakeFiles/glfwMinimal.dir/glfwMinimal.cpp.o.requires
CMakeFiles/glfwMinimal.dir/requires: CMakeFiles/glfwMinimal.dir/camera.cpp.o.requires
CMakeFiles/glfwMinimal.dir/requires: CMakeFiles/glfwMinimal.dir/gameObject.cpp.o.requires
CMakeFiles/glfwMinimal.dir/requires: CMakeFiles/glfwMinimal.dir/gameTorus.cpp.o.requires
CMakeFiles/glfwMinimal.dir/requires: CMakeFiles/glfwMinimal.dir/stage.cpp.o.requires
CMakeFiles/glfwMinimal.dir/requires: CMakeFiles/glfwMinimal.dir/game.cpp.o.requires
CMakeFiles/glfwMinimal.dir/requires: CMakeFiles/glfwMinimal.dir/gameSphere.cpp.o.requires
CMakeFiles/glfwMinimal.dir/requires: CMakeFiles/glfwMinimal.dir/textures.cpp.o.requires
.PHONY : CMakeFiles/glfwMinimal.dir/requires

CMakeFiles/glfwMinimal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/glfwMinimal.dir/cmake_clean.cmake
.PHONY : CMakeFiles/glfwMinimal.dir/clean

CMakeFiles/glfwMinimal.dir/depend:
	cd /home/guillaume/Documents/tp/opengl/opengl/tp0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/guillaume/Documents/tp/opengl/opengl/tp0 /home/guillaume/Documents/tp/opengl/opengl/tp0 /home/guillaume/Documents/tp/opengl/opengl/tp0/build /home/guillaume/Documents/tp/opengl/opengl/tp0/build /home/guillaume/Documents/tp/opengl/opengl/tp0/build/CMakeFiles/glfwMinimal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/glfwMinimal.dir/depend

