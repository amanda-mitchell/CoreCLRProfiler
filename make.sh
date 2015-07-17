#!/bin/sh

[ -z "${CORECLR_PATH:-}" ] && CORECLR_PATH=~/coreclr
[ -z "${CORECLR_PLATFORM}:-" ] && CORECLR_PLATFORM=OSX
[ -z "${CORECLR_ARCH}:-" ] && CORECLR_ARCH=x64
[ -z "${CORECLR_CONFIG}:-" ] && CORECLR_CONFIG=Debug

CXX_FLAGS="$CXX_FLAGS -fPIC -lexpat -fms-extensions -DPLATFORM_UNIX -std=c++11"
INCLUDES="-I $CORECLR_PATH/src/pal/inc/rt -I $CORECLR_PATH/src/pal/prebuilt/inc -I $CORECLR_PATH/src/pal/inc -I $CORECLR_PATH/src/inc -I $CORECLR_PATH/bin/Product/$CORECLR_PLATFORM.$CORECLR_ARCH.$CORECLR_CONFIG/inc"

clang++ -shared -o profiler.dylib $CXX_FLAGS $INCLUDES profiler.cpp log.cpp classfactory.cpp guids.cpp
