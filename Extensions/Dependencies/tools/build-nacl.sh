#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

source environment.sh

cd ../nacl
mv setup.py setup.py.old
cp ../tools/nacl-setup.py setup.py
python3 setup.py build
rm setup.py
mv setup.py.old setup.py
python3 ../tools/make_frameworks.py nacl PyNacl
../tools/copy-scripts.sh build/lib*/* ../../../downloadable-site-packages/compiled/nacl
