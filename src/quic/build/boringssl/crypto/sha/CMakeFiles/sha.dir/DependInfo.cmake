# The set of languages for which implicit dependencies are needed:
set(CMAKE_DEPENDS_LANGUAGES
  "ASM"
  "C"
  )
# The set of files for implicit dependencies of each language:
set(CMAKE_DEPENDS_CHECK_ASM
  "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/sha/sha1-x86_64.S" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/sha/CMakeFiles/sha.dir/sha1-x86_64.S.o"
  "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/sha/sha256-x86_64.S" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/sha/CMakeFiles/sha.dir/sha256-x86_64.S.o"
  "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/sha/sha512-x86_64.S" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/sha/CMakeFiles/sha.dir/sha512-x86_64.S.o"
  )
set(CMAKE_ASM_COMPILER_ID "Clang")
set(CMAKE_DEPENDS_CHECK_C
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/sha/sha1.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/sha/CMakeFiles/sha.dir/sha1.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/sha/sha256.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/sha/CMakeFiles/sha.dir/sha256.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/sha/sha512.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/sha/CMakeFiles/sha.dir/sha512.c.o"
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
  "../boringssl/crypto/sha/."
  "../boringssl/crypto/sha/.."
  "../boringssl/crypto/sha/../../include"
  )
set(CMAKE_CXX_TARGET_INCLUDE_PATH ${CMAKE_C_TARGET_INCLUDE_PATH})
set(CMAKE_Fortran_TARGET_INCLUDE_PATH ${CMAKE_C_TARGET_INCLUDE_PATH})
set(CMAKE_ASM_TARGET_INCLUDE_PATH ${CMAKE_C_TARGET_INCLUDE_PATH})
