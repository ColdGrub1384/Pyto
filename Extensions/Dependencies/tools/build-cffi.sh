#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

# Build ffi!!
LIBFFI="$PWD/../../../python3_ios/Python3_ios/libffi-3.4.2"
TOOLS="$PWD"
pushd "$LIBFFI"
rm "$TOOLS/libFFI.a"
xcodebuild -scheme libffi-iOS -derivedDataPath build -sdk iphoneos -arch arm64 build
cp build/Build/Products/Debug-iphoneos/libffi.a "$TOOLS"
rm -rf build
popd

source environment.sh

export CFLAGS="$CFLAGS -DHAVE_FFI_PREP_CIF_VAR=1 -I$PWD/../../../python3_ios/libffi"
export CPPFLAGS="$CPPFLAGS -DHAVE_FFI_PREP_CIF_VAR=1"
export LDFLAGS="-L'$PWD'"

cd ../cffi
python3 setup.py bdist
python3 ../tools/make_frameworks.py cffi CFFI
