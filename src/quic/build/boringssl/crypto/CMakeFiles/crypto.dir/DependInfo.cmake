# The set of languages for which implicit dependencies are needed:
set(CMAKE_DEPENDS_LANGUAGES
  "ASM"
  "C"
  )
# The set of files for implicit dependencies of each language:
set(CMAKE_DEPENDS_CHECK_ASM
  "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/cpu-x86_64-asm.S" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/CMakeFiles/crypto.dir/cpu-x86_64-asm.S.o"
  )
set(CMAKE_ASM_COMPILER_ID "Clang")
set(CMAKE_DEPENDS_CHECK_C
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/cpu-intel.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/CMakeFiles/crypto.dir/cpu-intel.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/crypto.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/CMakeFiles/crypto.dir/crypto.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/directory_posix.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/CMakeFiles/crypto.dir/directory_posix.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/directory_win.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/CMakeFiles/crypto.dir/directory_win.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/ex_data.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/CMakeFiles/crypto.dir/ex_data.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/ex_data_impl.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/CMakeFiles/crypto.dir/ex_data_impl.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/mem.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/CMakeFiles/crypto.dir/mem.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/thread.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/CMakeFiles/crypto.dir/thread.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/time_support.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/CMakeFiles/crypto.dir/time_support.c.o"
  )
set(CMAKE_C_COMPILER_ID "Clang")

# Preprocessor definitions for this target.
set(CMAKE_TARGET_DEFINITIONS
  "BORINGSSL_IMPLEMENTATION"
  "USE_OPENSSL"
  )

# Targets to which this target links.
set(CMAKE_TARGET_LINKED_INFO_FILES
  )

# The include file search paths:
set(CMAKE_C_TARGET_INCLUDE_PATH
  "../src"
  "../src/third_party/modp_b64"
  "../boringssl/include"
  "../src/third_party/protobuf/src"
  "../boringssl/crypto/."
  "../boringssl/crypto/../include"
  )
set(CMAKE_CXX_TARGET_INCLUDE_PATH ${CMAKE_C_TARGET_INCLUDE_PATH})
set(CMAKE_Fortran_TARGET_INCLUDE_PATH ${CMAKE_C_TARGET_INCLUDE_PATH})
set(CMAKE_ASM_TARGET_INCLUDE_PATH ${CMAKE_C_TARGET_INCLUDE_PATH})
