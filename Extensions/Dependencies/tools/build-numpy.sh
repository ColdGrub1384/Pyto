#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

source environment.sh

export NPY_BLAS_ORDER=""
export NPY_LAPACK_ORDER=""

cd ../numpy
python3 setup.py bdist --force
python3 ../tools/make_frameworks.py numpy NumPy
cp build/temp*/*.a ../../NumPy
../tools/copy-scripts.sh build/lib*/* ../../../downloadable-site-packages/compiled/numpy
