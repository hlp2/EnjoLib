#!/bin/bash

MAKE=make
GEN="MSYS Makefiles"
BUILD_DIR="build/mingw"

GCC_PREFIX=x86_64-w64-mingw32
CMAKE_C_COMPILER="${GCC_PREFIX}-gcc"
CMAKE_CXX_COMPILER="${GCC_PREFIX}-g++"

mkdir -p $BUILD_DIR && cd $BUILD_DIR

cmake -G "${GEN}" ../.. \
-DCMAKE_C_COMPILER="${CMAKE_C_COMPILER}" \
-DCMAKE_CXX_COMPILER="${CMAKE_CXX_COMPILER}" \
-DUSE_STATIC="ON" \
-DUSE_UNITY="ON" \
&& ${MAKE} -j `nproc` || ${MAKE} && ${MAKE} -j `nproc` install
ctest --verbose -R EnjoLibTest
ctest --output-on-failure -j `nproc`

# USE_STATIC="OFF" doesn't work, because the execs can't find the DLL.

