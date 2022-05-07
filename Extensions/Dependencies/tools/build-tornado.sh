#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

source environment.sh

cd ../tornado
python3 setup.py bdist
python3 ../tools/make_frameworks.py tornado Tornado
rm -rf ../../../site-packages/tornado
cp -r build/lib*/tornado ../../../site-packages
