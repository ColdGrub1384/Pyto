#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

source environment.sh

export NPY_BLAS_ORDER=""
export NPY_LAPACK_ORDER=""

cd ../numpy

# Edit headers so they don't include features.h
# Update them when you update numpy
rm numpy/core/src/common/npy_config.h
cp ../tools/npy_config.h numpy/core/src/common/
rm numpy/core/include/numpy/npy_common.h
cp ../tools/npy_common.h numpy/core/include/numpy/


python3 setup.py bdist --force
python3 ../tools/make_frameworks.py numpy NumPy
cp build/temp*/*.a ../../NumPy
../tools/copy-scripts.sh build/lib*/* ../../../downloadable-site-packages/compiled/numpy
