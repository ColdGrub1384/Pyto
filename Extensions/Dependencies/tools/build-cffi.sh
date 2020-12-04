#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

source environment.sh
export CFLAGS="$CFLAGS -DHAVE_FFI_PREP_CIF_VAR=1"
export CPPFLAGS="$CPPFLAGS -DHAVE_FFI_PREP_CIF_VAR=1"

cd ../cffi
python3 setup.py build
python3 ../tools/make_frameworks.py cffi CFFI
