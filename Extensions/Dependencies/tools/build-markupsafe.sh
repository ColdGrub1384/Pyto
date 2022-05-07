#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

source environment.sh

cd ../markupsafe
python3 setup.py bdist
python3 ../tools/make_frameworks.py markupsafe MarkupSafe
rm -rf ../../../site-packages/markupsafe
cp -r build/lib*/markupsafe ../../../site-packages
