# The set of languages for which implicit dependencies are needed:
set(CMAKE_DEPENDS_LANGUAGES
  "ASM"
  "C"
  )
# The set of files for implicit dependencies of each language:
set(CMAKE_DEPENDS_CHECK_ASM
  "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/aes/aes-x86_64.S" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/aes/CMakeFiles/aes.dir/aes-x86_64.S.o"
  "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/aes/aesni-x86_64.S" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/aes/CMakeFiles/aes.dir/aesni-x86_64.S.o"
  "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/aes/bsaes-x86_64.S" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/aes/CMakeFiles/aes.dir/bsaes-x86_64.S.o"
  "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/aes/vpaes-x86_64.S" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/aes/CMakeFiles/aes.dir/vpaes-x86_64.S.o"
  )
set(CMAKE_ASM_COMPILER_ID "Clang")
set(CMAKE_DEPENDS_CHECK_C
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/aes/aes.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/aes/CMakeFiles/aes.dir/aes.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/aes/mode_wrappers.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/aes/CMakeFiles/aes.dir/mode_wrappers.c.o"
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
  "../boringssl/crypto/aes/."
  "../boringssl/crypto/aes/.."
  "../boringssl/crypto/aes/../../include"
  )
set(CMAKE_CXX_TARGET_INCLUDE_PATH ${CMAKE_C_TARGET_INCLUDE_PATH})
set(CMAKE_Fortran_TARGET_INCLUDE_PATH ${CMAKE_C_TARGET_INCLUDE_PATH})
set(CMAKE_ASM_TARGET_INCLUDE_PATH ${CMAKE_C_TARGET_INCLUDE_PATH})
