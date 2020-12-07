#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

source environment.sh

cd ../erfa

git submodule init 
git submodule update

python3 setup.py bdist
python3 ../tools/make_frameworks.py erfa Erfa
../tools/copy-scripts.sh build/lib*/* ../../../downloadable-site-packages/compiled/erfa
