# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.1

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.1.1_1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.1.1_1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/caw/Projects/transport-test/src/quic

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/caw/Projects/transport-test/src/quic/build

# Include any dependencies generated for this target.
include boringssl/crypto/conf/CMakeFiles/conf.dir/depend.make

# Include the progress variables for this target.
include boringssl/crypto/conf/CMakeFiles/conf.dir/progress.make

# Include the compile flags for this target's objects.
include boringssl/crypto/conf/CMakeFiles/conf.dir/flags.make

boringssl/crypto/conf/CMakeFiles/conf.dir/conf.c.o: boringssl/crypto/conf/CMakeFiles/conf.dir/flags.make
boringssl/crypto/conf/CMakeFiles/conf.dir/conf.c.o: ../boringssl/crypto/conf/conf.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/caw/Projects/transport-test/src/quic/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object boringssl/crypto/conf/CMakeFiles/conf.dir/conf.c.o"
	cd /Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/conf && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/conf.dir/conf.c.o   -c /Users/caw/Projects/transport-test/src/quic/boringssl/crypto/conf/conf.c

boringssl/crypto/conf/CMakeFiles/conf.dir/conf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/conf.dir/conf.c.i"
	cd /Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/conf && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /Users/caw/Projects/transport-test/src/quic/boringssl/crypto/conf/conf.c > CMakeFiles/conf.dir/conf.c.i

boringssl/crypto/conf/CMakeFiles/conf.dir/conf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/conf.dir/conf.c.s"
	cd /Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/conf && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /Users/caw/Projects/transport-test/src/quic/boringssl/crypto/conf/conf.c -o CMakeFiles/conf.dir/conf.c.s

boringssl/crypto/conf/CMakeFiles/conf.dir/conf.c.o.requires:
.PHONY : boringssl/crypto/conf/CMakeFiles/conf.dir/conf.c.o.requires

boringssl/crypto/conf/CMakeFiles/conf.dir/conf.c.o.provides: boringssl/crypto/conf/CMakeFiles/conf.dir/conf.c.o.requires
	$(MAKE) -f boringssl/crypto/conf/CMakeFiles/conf.dir/build.make boringssl/crypto/conf/CMakeFiles/conf.dir/conf.c.o.provides.build
.PHONY : boringssl/crypto/conf/CMakeFiles/conf.dir/conf.c.o.provides

boringssl/crypto/conf/CMakeFiles/conf.dir/conf.c.o.provides.build: boringssl/crypto/conf/CMakeFiles/conf.dir/conf.c.o

conf: boringssl/crypto/conf/CMakeFiles/conf.dir/conf.c.o
conf: boringssl/crypto/conf/CMakeFiles/conf.dir/build.make
.PHONY : conf

# Rule to build all files generated by this target.
boringssl/crypto/conf/CMakeFiles/conf.dir/build: conf
.PHONY : boringssl/crypto/conf/CMakeFiles/conf.dir/build

boringssl/crypto/conf/CMakeFiles/conf.dir/requires: boringssl/crypto/conf/CMakeFiles/conf.dir/conf.c.o.requires
.PHONY : boringssl/crypto/conf/CMakeFiles/conf.dir/requires

boringssl/crypto/conf/CMakeFiles/conf.dir/clean:
	cd /Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/conf && $(CMAKE_COMMAND) -P CMakeFiles/conf.dir/cmake_clean.cmake
.PHONY : boringssl/crypto/conf/CMakeFiles/conf.dir/clean

boringssl/crypto/conf/CMakeFiles/conf.dir/depend:
	cd /Users/caw/Projects/transport-test/src/quic/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/caw/Projects/transport-test/src/quic /Users/caw/Projects/transport-test/src/quic/boringssl/crypto/conf /Users/caw/Projects/transport-test/src/quic/build /Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/conf /Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/conf/CMakeFiles/conf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : boringssl/crypto/conf/CMakeFiles/conf.dir/depend

