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
include boringssl/crypto/err/CMakeFiles/err_test.dir/depend.make

# Include the progress variables for this target.
include boringssl/crypto/err/CMakeFiles/err_test.dir/progress.make

# Include the compile flags for this target's objects.
include boringssl/crypto/err/CMakeFiles/err_test.dir/flags.make

boringssl/crypto/err/CMakeFiles/err_test.dir/err_test.c.o: boringssl/crypto/err/CMakeFiles/err_test.dir/flags.make
boringssl/crypto/err/CMakeFiles/err_test.dir/err_test.c.o: ../boringssl/crypto/err/err_test.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/caw/Projects/transport-test/src/quic/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object boringssl/crypto/err/CMakeFiles/err_test.dir/err_test.c.o"
	cd /Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/err && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/err_test.dir/err_test.c.o   -c /Users/caw/Projects/transport-test/src/quic/boringssl/crypto/err/err_test.c

boringssl/crypto/err/CMakeFiles/err_test.dir/err_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/err_test.dir/err_test.c.i"
	cd /Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/err && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /Users/caw/Projects/transport-test/src/quic/boringssl/crypto/err/err_test.c > CMakeFiles/err_test.dir/err_test.c.i

boringssl/crypto/err/CMakeFiles/err_test.dir/err_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/err_test.dir/err_test.c.s"
	cd /Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/err && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /Users/caw/Projects/transport-test/src/quic/boringssl/crypto/err/err_test.c -o CMakeFiles/err_test.dir/err_test.c.s

boringssl/crypto/err/CMakeFiles/err_test.dir/err_test.c.o.requires:
.PHONY : boringssl/crypto/err/CMakeFiles/err_test.dir/err_test.c.o.requires

boringssl/crypto/err/CMakeFiles/err_test.dir/err_test.c.o.provides: boringssl/crypto/err/CMakeFiles/err_test.dir/err_test.c.o.requires
	$(MAKE) -f boringssl/crypto/err/CMakeFiles/err_test.dir/build.make boringssl/crypto/err/CMakeFiles/err_test.dir/err_test.c.o.provides.build
.PHONY : boringssl/crypto/err/CMakeFiles/err_test.dir/err_test.c.o.provides

boringssl/crypto/err/CMakeFiles/err_test.dir/err_test.c.o.provides.build: boringssl/crypto/err/CMakeFiles/err_test.dir/err_test.c.o

# Object files for target err_test
err_test_OBJECTS = \
"CMakeFiles/err_test.dir/err_test.c.o"

# External object files for target err_test
err_test_EXTERNAL_OBJECTS =

boringssl/crypto/err/err_test: boringssl/crypto/err/CMakeFiles/err_test.dir/err_test.c.o
boringssl/crypto/err/err_test: boringssl/crypto/err/CMakeFiles/err_test.dir/build.make
boringssl/crypto/err/err_test: boringssl/crypto/libcrypto.a
boringssl/crypto/err/err_test: boringssl/crypto/err/CMakeFiles/err_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable err_test"
	cd /Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/err && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/err_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
boringssl/crypto/err/CMakeFiles/err_test.dir/build: boringssl/crypto/err/err_test
.PHONY : boringssl/crypto/err/CMakeFiles/err_test.dir/build

boringssl/crypto/err/CMakeFiles/err_test.dir/requires: boringssl/crypto/err/CMakeFiles/err_test.dir/err_test.c.o.requires
.PHONY : boringssl/crypto/err/CMakeFiles/err_test.dir/requires

boringssl/crypto/err/CMakeFiles/err_test.dir/clean:
	cd /Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/err && $(CMAKE_COMMAND) -P CMakeFiles/err_test.dir/cmake_clean.cmake
.PHONY : boringssl/crypto/err/CMakeFiles/err_test.dir/clean

boringssl/crypto/err/CMakeFiles/err_test.dir/depend:
	cd /Users/caw/Projects/transport-test/src/quic/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/caw/Projects/transport-test/src/quic /Users/caw/Projects/transport-test/src/quic/boringssl/crypto/err /Users/caw/Projects/transport-test/src/quic/build /Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/err /Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/err/CMakeFiles/err_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : boringssl/crypto/err/CMakeFiles/err_test.dir/depend

