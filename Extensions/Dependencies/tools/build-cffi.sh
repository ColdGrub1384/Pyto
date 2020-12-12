#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

echo "int a() { return 0; }" > a.c
clang -arch x86_64 -shared a.c -o libffi.dylib
rm a.c

source environment.sh

export CFLAGS="$CFLAGS -DHAVE_FFI_PREP_CIF_VAR=1 -I$PWD/../../../python3_ios/libffi -L$PWD"
export CPPFLAGS="$CPPFLAGS -DHAVE_FFI_PREP_CIF_VAR=1 -L$PWD"

cd ../cffi
python3 setup.py bdist
python3 ../tools/make_frameworks.py cffi CFFI

rm ../tools/libffi.dylib
