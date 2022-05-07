#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

source environment.sh

cd ../pyrsistent
python3 setup.py bdist
python3 ../tools/make_frameworks.py pyrsistent PyRsistent
rm -rf ../../../site-packages/pyrsistent
cp -r build/lib*/pyrsistent ../../../site-packages
