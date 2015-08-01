# The set of languages for which implicit dependencies are needed:
set(CMAKE_DEPENDS_LANGUAGES
  "ASM"
  "C"
  )
# The set of files for implicit dependencies of each language:
set(CMAKE_DEPENDS_CHECK_ASM
  "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/bn/rsaz-avx2.S" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/bn/CMakeFiles/bn.dir/rsaz-avx2.S.o"
  "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/bn/rsaz-x86_64.S" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/bn/CMakeFiles/bn.dir/rsaz-x86_64.S.o"
  "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/bn/x86_64-mont.S" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/bn/CMakeFiles/bn.dir/x86_64-mont.S.o"
  "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/bn/x86_64-mont5.S" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/bn/CMakeFiles/bn.dir/x86_64-mont5.S.o"
  )
set(CMAKE_ASM_COMPILER_ID "Clang")
set(CMAKE_DEPENDS_CHECK_C
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/bn/add.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/bn/CMakeFiles/bn.dir/add.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/bn/asm/x86_64-gcc.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/bn/CMakeFiles/bn.dir/asm/x86_64-gcc.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/bn/bn.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/bn/CMakeFiles/bn.dir/bn.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/bn/cmp.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/bn/CMakeFiles/bn.dir/cmp.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/bn/convert.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/bn/CMakeFiles/bn.dir/convert.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/bn/ctx.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/bn/CMakeFiles/bn.dir/ctx.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/bn/div.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/bn/CMakeFiles/bn.dir/div.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/bn/exponentiation.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/bn/CMakeFiles/bn.dir/exponentiation.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/bn/gcd.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/bn/CMakeFiles/bn.dir/gcd.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/bn/generic.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/bn/CMakeFiles/bn.dir/generic.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/bn/kronecker.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/bn/CMakeFiles/bn.dir/kronecker.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/bn/montgomery.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/bn/CMakeFiles/bn.dir/montgomery.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/bn/mul.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/bn/CMakeFiles/bn.dir/mul.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/bn/prime.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/bn/CMakeFiles/bn.dir/prime.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/bn/random.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/bn/CMakeFiles/bn.dir/random.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/bn/rsaz_exp.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/bn/CMakeFiles/bn.dir/rsaz_exp.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/bn/shift.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/bn/CMakeFiles/bn.dir/shift.c.o"
  "/Users/caw/Projects/transport-test/src/quic/boringssl/crypto/bn/sqrt.c" "/Users/caw/Projects/transport-test/src/quic/build/boringssl/crypto/bn/CMakeFiles/bn.dir/sqrt.c.o"
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
  "../boringssl/crypto/bn/."
  "../boringssl/crypto/bn/.."
  "../boringssl/crypto/bn/../../include"
  )
set(CMAKE_CXX_TARGET_INCLUDE_PATH ${CMAKE_C_TARGET_INCLUDE_PATH})
set(CMAKE_Fortran_TARGET_INCLUDE_PATH ${CMAKE_C_TARGET_INCLUDE_PATH})
set(CMAKE_ASM_TARGET_INCLUDE_PATH ${CMAKE_C_TARGET_INCLUDE_PATH})
