#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

source environment.sh

cd ../pyemd
python3 setup.py bdist
python3 ../tools/make_frameworks.py pyemd Emd
rm -rf ../../../site-packages/pyemd
cp -r build/lib*/pyemd ../../../site-packages
