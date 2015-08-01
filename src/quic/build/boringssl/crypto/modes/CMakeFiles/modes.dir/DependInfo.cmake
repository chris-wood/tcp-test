# The set of languages for which implicit dependencies are needed:
set(CMAKE_DEPENDS_LANGUAGES
  "ASM"
  "C"
  )
# The set of files for implicit dependencies of each language:
set(CMAKE_DEPENDS_CHECK_ASM
  "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/modes/aesni-gcm-x86_64.S" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/modes/CMakeFiles/modes.dir/aesni-gcm-x86_64.S.o"
  "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/modes/ghash-x86_64.S" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/modes/CMakeFiles/modes.dir/ghash-x86_64.S.o"
  )
set(CMAKE_ASM_COMPILER_ID "Clang")
set(CMAKE_DEPENDS_CHECK_C
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/modes/cbc.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/modes/CMakeFiles/modes.dir/cbc.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/modes/cfb.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/modes/CMakeFiles/modes.dir/cfb.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/modes/ctr.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/modes/CMakeFiles/modes.dir/ctr.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/modes/gcm.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/modes/CMakeFiles/modes.dir/gcm.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/modes/ofb.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/modes/CMakeFiles/modes.dir/ofb.c.o"
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
  "../boringssl/crypto/modes/."
  "../boringssl/crypto/modes/.."
  "../boringssl/crypto/modes/../../include"
  )
set(CMAKE_CXX_TARGET_INCLUDE_PATH ${CMAKE_C_TARGET_INCLUDE_PATH})
set(CMAKE_Fortran_TARGET_INCLUDE_PATH ${CMAKE_C_TARGET_INCLUDE_PATH})
set(CMAKE_ASM_TARGET_INCLUDE_PATH ${CMAKE_C_TARGET_INCLUDE_PATH})
