#!/bin/bash

export PATH="/Users/adrianlabbe/Desktop/fortran-ios:$PATH"

source tools/environment.sh

cd OpenBlas
SDKROOT="$(xcrun --sdk iphoneos --show-sdk-path)"
make TARGET=ARMV8 BINARY=64 HOSTCC=_clang CC="_clang" CFLAGS="-isysroot $SDKROOT -arch arm64" NOFORTRAN=1 libs
