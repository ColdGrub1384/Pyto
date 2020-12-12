#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

source environment.sh

cd ../pywt
python3 setup.py bdist --force
python3 ../tools/make_frameworks.py pywt Pywt
../tools/copy-scripts.sh build/lib*/* ../../../downloadable-site-packages/compiled/pywt
