#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

source environment.sh

python3 -m pip install Cython==3.0.0a9 # Fails on a10

cd ../pyyaml
python3 setup.py --without-libyaml bdist
python3 ../tools/make_frameworks.py pyyaml PyYaml
rm -rf ../../../site-packages/yaml
rm -rf ../../../site-packages/_yaml
cp -r build/lib*/yaml ../../../site-packages
cp -r build/lib*/_yaml ../../../site-packages
