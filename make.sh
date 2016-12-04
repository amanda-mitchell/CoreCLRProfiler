#!/bin/sh

# This should be the path of the git repo for Core CLR. To the best of my knowledge,
# Microsoft does not yet ship the necessary header files separately from the repo.
[ -z "${CORECLR_PATH:-}" ] && CORECLR_PATH=~/coreclr

# Currently, this has only been tested on OS X.
[ -z "${CORECLR_PLATFORM}:-" ] && CORECLR_PLATFORM=OSX

[ -z "${CORECLR_ARCH}:-" ] && CORECLR_ARCH=x64
[ -z "${CORECLR_CONFIG}:-" ] && CORECLR_CONFIG=Debug

# These flags assume that you're going to be compiling on a 64 bit Unix platform.
CXX_FLAGS="$CXX_FLAGS -fPIC -lexpat -fms-extensions -DPLATFORM_UNIX -DPAL_STDCPP_COMPAT -DBIT64 -std=c++11"

INCLUDES="-I $CORECLR_PATH/src/pal/inc/rt -I $CORECLR_PATH/src/pal/prebuilt/inc -I $CORECLR_PATH/src/pal/inc -I $CORECLR_PATH/src/inc -I $CORECLR_PATH/bin/Product/$CORECLR_PLATFORM.$CORECLR_ARCH.$CORECLR_CONFIG/inc"

clang++ -shared -o profiler.dylib $CXX_FLAGS $INCLUDES profiler.cpp log.cpp classfactory.cpp guids.cpp entrypoint.cpp
