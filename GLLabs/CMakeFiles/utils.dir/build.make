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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs

# Include any dependencies generated for this target.
include CMakeFiles/utils.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/utils.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/utils.dir/flags.make

CMakeFiles/utils.dir/utils/utils.cpp.o: CMakeFiles/utils.dir/flags.make
CMakeFiles/utils.dir/utils/utils.cpp.o: utils/utils.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/utils.dir/utils/utils.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/utils.dir/utils/utils.cpp.o -c /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs/utils/utils.cpp

CMakeFiles/utils.dir/utils/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utils.dir/utils/utils.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs/utils/utils.cpp > CMakeFiles/utils.dir/utils/utils.cpp.i

CMakeFiles/utils.dir/utils/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utils.dir/utils/utils.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs/utils/utils.cpp -o CMakeFiles/utils.dir/utils/utils.cpp.s

CMakeFiles/utils.dir/utils/utils.cpp.o.requires:
.PHONY : CMakeFiles/utils.dir/utils/utils.cpp.o.requires

CMakeFiles/utils.dir/utils/utils.cpp.o.provides: CMakeFiles/utils.dir/utils/utils.cpp.o.requires
	$(MAKE) -f CMakeFiles/utils.dir/build.make CMakeFiles/utils.dir/utils/utils.cpp.o.provides.build
.PHONY : CMakeFiles/utils.dir/utils/utils.cpp.o.provides

CMakeFiles/utils.dir/utils/utils.cpp.o.provides.build: CMakeFiles/utils.dir/utils/utils.cpp.o

CMakeFiles/utils.dir/utils/shaders.cpp.o: CMakeFiles/utils.dir/flags.make
CMakeFiles/utils.dir/utils/shaders.cpp.o: utils/shaders.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/utils.dir/utils/shaders.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/utils.dir/utils/shaders.cpp.o -c /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs/utils/shaders.cpp

CMakeFiles/utils.dir/utils/shaders.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utils.dir/utils/shaders.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs/utils/shaders.cpp > CMakeFiles/utils.dir/utils/shaders.cpp.i

CMakeFiles/utils.dir/utils/shaders.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utils.dir/utils/shaders.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs/utils/shaders.cpp -o CMakeFiles/utils.dir/utils/shaders.cpp.s

CMakeFiles/utils.dir/utils/shaders.cpp.o.requires:
.PHONY : CMakeFiles/utils.dir/utils/shaders.cpp.o.requires

CMakeFiles/utils.dir/utils/shaders.cpp.o.provides: CMakeFiles/utils.dir/utils/shaders.cpp.o.requires
	$(MAKE) -f CMakeFiles/utils.dir/build.make CMakeFiles/utils.dir/utils/shaders.cpp.o.provides.build
.PHONY : CMakeFiles/utils.dir/utils/shaders.cpp.o.provides

CMakeFiles/utils.dir/utils/shaders.cpp.o.provides.build: CMakeFiles/utils.dir/utils/shaders.cpp.o

CMakeFiles/utils.dir/utils/vao.cpp.o: CMakeFiles/utils.dir/flags.make
CMakeFiles/utils.dir/utils/vao.cpp.o: utils/vao.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/utils.dir/utils/vao.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/utils.dir/utils/vao.cpp.o -c /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs/utils/vao.cpp

CMakeFiles/utils.dir/utils/vao.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utils.dir/utils/vao.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs/utils/vao.cpp > CMakeFiles/utils.dir/utils/vao.cpp.i

CMakeFiles/utils.dir/utils/vao.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utils.dir/utils/vao.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs/utils/vao.cpp -o CMakeFiles/utils.dir/utils/vao.cpp.s

CMakeFiles/utils.dir/utils/vao.cpp.o.requires:
.PHONY : CMakeFiles/utils.dir/utils/vao.cpp.o.requires

CMakeFiles/utils.dir/utils/vao.cpp.o.provides: CMakeFiles/utils.dir/utils/vao.cpp.o.requires
	$(MAKE) -f CMakeFiles/utils.dir/build.make CMakeFiles/utils.dir/utils/vao.cpp.o.provides.build
.PHONY : CMakeFiles/utils.dir/utils/vao.cpp.o.provides

CMakeFiles/utils.dir/utils/vao.cpp.o.provides.build: CMakeFiles/utils.dir/utils/vao.cpp.o

CMakeFiles/utils.dir/utils/textures.cpp.o: CMakeFiles/utils.dir/flags.make
CMakeFiles/utils.dir/utils/textures.cpp.o: utils/textures.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/utils.dir/utils/textures.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/utils.dir/utils/textures.cpp.o -c /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs/utils/textures.cpp

CMakeFiles/utils.dir/utils/textures.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utils.dir/utils/textures.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs/utils/textures.cpp > CMakeFiles/utils.dir/utils/textures.cpp.i

CMakeFiles/utils.dir/utils/textures.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utils.dir/utils/textures.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs/utils/textures.cpp -o CMakeFiles/utils.dir/utils/textures.cpp.s

CMakeFiles/utils.dir/utils/textures.cpp.o.requires:
.PHONY : CMakeFiles/utils.dir/utils/textures.cpp.o.requires

CMakeFiles/utils.dir/utils/textures.cpp.o.provides: CMakeFiles/utils.dir/utils/textures.cpp.o.requires
	$(MAKE) -f CMakeFiles/utils.dir/build.make CMakeFiles/utils.dir/utils/textures.cpp.o.provides.build
.PHONY : CMakeFiles/utils.dir/utils/textures.cpp.o.provides

CMakeFiles/utils.dir/utils/textures.cpp.o.provides.build: CMakeFiles/utils.dir/utils/textures.cpp.o

CMakeFiles/utils.dir/utils/objloader.cpp.o: CMakeFiles/utils.dir/flags.make
CMakeFiles/utils.dir/utils/objloader.cpp.o: utils/objloader.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/utils.dir/utils/objloader.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/utils.dir/utils/objloader.cpp.o -c /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs/utils/objloader.cpp

CMakeFiles/utils.dir/utils/objloader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utils.dir/utils/objloader.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs/utils/objloader.cpp > CMakeFiles/utils.dir/utils/objloader.cpp.i

CMakeFiles/utils.dir/utils/objloader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utils.dir/utils/objloader.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs/utils/objloader.cpp -o CMakeFiles/utils.dir/utils/objloader.cpp.s

CMakeFiles/utils.dir/utils/objloader.cpp.o.requires:
.PHONY : CMakeFiles/utils.dir/utils/objloader.cpp.o.requires

CMakeFiles/utils.dir/utils/objloader.cpp.o.provides: CMakeFiles/utils.dir/utils/objloader.cpp.o.requires
	$(MAKE) -f CMakeFiles/utils.dir/build.make CMakeFiles/utils.dir/utils/objloader.cpp.o.provides.build
.PHONY : CMakeFiles/utils.dir/utils/objloader.cpp.o.provides

CMakeFiles/utils.dir/utils/objloader.cpp.o.provides.build: CMakeFiles/utils.dir/utils/objloader.cpp.o

CMakeFiles/utils.dir/utils/tangentspace.cpp.o: CMakeFiles/utils.dir/flags.make
CMakeFiles/utils.dir/utils/tangentspace.cpp.o: utils/tangentspace.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/utils.dir/utils/tangentspace.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/utils.dir/utils/tangentspace.cpp.o -c /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs/utils/tangentspace.cpp

CMakeFiles/utils.dir/utils/tangentspace.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utils.dir/utils/tangentspace.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs/utils/tangentspace.cpp > CMakeFiles/utils.dir/utils/tangentspace.cpp.i

CMakeFiles/utils.dir/utils/tangentspace.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utils.dir/utils/tangentspace.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs/utils/tangentspace.cpp -o CMakeFiles/utils.dir/utils/tangentspace.cpp.s

CMakeFiles/utils.dir/utils/tangentspace.cpp.o.requires:
.PHONY : CMakeFiles/utils.dir/utils/tangentspace.cpp.o.requires

CMakeFiles/utils.dir/utils/tangentspace.cpp.o.provides: CMakeFiles/utils.dir/utils/tangentspace.cpp.o.requires
	$(MAKE) -f CMakeFiles/utils.dir/build.make CMakeFiles/utils.dir/utils/tangentspace.cpp.o.provides.build
.PHONY : CMakeFiles/utils.dir/utils/tangentspace.cpp.o.provides

CMakeFiles/utils.dir/utils/tangentspace.cpp.o.provides.build: CMakeFiles/utils.dir/utils/tangentspace.cpp.o

CMakeFiles/utils.dir/utils/vboindexer.cpp.o: CMakeFiles/utils.dir/flags.make
CMakeFiles/utils.dir/utils/vboindexer.cpp.o: utils/vboindexer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/utils.dir/utils/vboindexer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/utils.dir/utils/vboindexer.cpp.o -c /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs/utils/vboindexer.cpp

CMakeFiles/utils.dir/utils/vboindexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utils.dir/utils/vboindexer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs/utils/vboindexer.cpp > CMakeFiles/utils.dir/utils/vboindexer.cpp.i

CMakeFiles/utils.dir/utils/vboindexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utils.dir/utils/vboindexer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs/utils/vboindexer.cpp -o CMakeFiles/utils.dir/utils/vboindexer.cpp.s

CMakeFiles/utils.dir/utils/vboindexer.cpp.o.requires:
.PHONY : CMakeFiles/utils.dir/utils/vboindexer.cpp.o.requires

CMakeFiles/utils.dir/utils/vboindexer.cpp.o.provides: CMakeFiles/utils.dir/utils/vboindexer.cpp.o.requires
	$(MAKE) -f CMakeFiles/utils.dir/build.make CMakeFiles/utils.dir/utils/vboindexer.cpp.o.provides.build
.PHONY : CMakeFiles/utils.dir/utils/vboindexer.cpp.o.provides

CMakeFiles/utils.dir/utils/vboindexer.cpp.o.provides.build: CMakeFiles/utils.dir/utils/vboindexer.cpp.o

# Object files for target utils
utils_OBJECTS = \
"CMakeFiles/utils.dir/utils/utils.cpp.o" \
"CMakeFiles/utils.dir/utils/shaders.cpp.o" \
"CMakeFiles/utils.dir/utils/vao.cpp.o" \
"CMakeFiles/utils.dir/utils/textures.cpp.o" \
"CMakeFiles/utils.dir/utils/objloader.cpp.o" \
"CMakeFiles/utils.dir/utils/tangentspace.cpp.o" \
"CMakeFiles/utils.dir/utils/vboindexer.cpp.o"

# External object files for target utils
utils_EXTERNAL_OBJECTS =

libutils.a: CMakeFiles/utils.dir/utils/utils.cpp.o
libutils.a: CMakeFiles/utils.dir/utils/shaders.cpp.o
libutils.a: CMakeFiles/utils.dir/utils/vao.cpp.o
libutils.a: CMakeFiles/utils.dir/utils/textures.cpp.o
libutils.a: CMakeFiles/utils.dir/utils/objloader.cpp.o
libutils.a: CMakeFiles/utils.dir/utils/tangentspace.cpp.o
libutils.a: CMakeFiles/utils.dir/utils/vboindexer.cpp.o
libutils.a: CMakeFiles/utils.dir/build.make
libutils.a: CMakeFiles/utils.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libutils.a"
	$(CMAKE_COMMAND) -P CMakeFiles/utils.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/utils.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/utils.dir/build: libutils.a
.PHONY : CMakeFiles/utils.dir/build

CMakeFiles/utils.dir/requires: CMakeFiles/utils.dir/utils/utils.cpp.o.requires
CMakeFiles/utils.dir/requires: CMakeFiles/utils.dir/utils/shaders.cpp.o.requires
CMakeFiles/utils.dir/requires: CMakeFiles/utils.dir/utils/vao.cpp.o.requires
CMakeFiles/utils.dir/requires: CMakeFiles/utils.dir/utils/textures.cpp.o.requires
CMakeFiles/utils.dir/requires: CMakeFiles/utils.dir/utils/objloader.cpp.o.requires
CMakeFiles/utils.dir/requires: CMakeFiles/utils.dir/utils/tangentspace.cpp.o.requires
CMakeFiles/utils.dir/requires: CMakeFiles/utils.dir/utils/vboindexer.cpp.o.requires
.PHONY : CMakeFiles/utils.dir/requires

CMakeFiles/utils.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/utils.dir/cmake_clean.cmake
.PHONY : CMakeFiles/utils.dir/clean

CMakeFiles/utils.dir/depend:
	cd /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs /home/eleves/promo16/info/kotulski/Documents/TP/opengl/2/GLLabs/CMakeFiles/utils.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/utils.dir/depend
