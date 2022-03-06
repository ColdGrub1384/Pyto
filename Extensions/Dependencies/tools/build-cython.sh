#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

source environment.sh

cd ../cython
python3 setup.py bdist_wheel
python3 ../tools/make_frameworks.py cython Cython
../tools/copy-scripts.sh build/lib*/Cython ../../../site-packages/Cython
../tools/copy-scripts.sh build/lib*/cython.py ../../../site-packages/cython.py
../tools/copy-scripts.sh build/lib*/pyximport ../../../site-packages/pyximport
