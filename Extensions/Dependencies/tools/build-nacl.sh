#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

python3 -m pip install cffi

source environment.sh

cd ../nacl
mv setup.py setup.py.old
cp ../tools/nacl-setup.py setup.py
python3 setup.py bdist
rm setup.py
mv setup.py.old setup.py

pushd build/temp*
rm ../lib*/nacl/_sodium.abi3.so
xcrun --sdk iphoneos clang -arch arm64 build/temp*/_sodium.o lib/libsodium.a -undefined dynamic_lookup -shared -o _sodium.abi3.so
mv _sodium.abi3.so ../lib*/nacl/
popd

python3 ../tools/make_frameworks.py nacl PyNacl
../tools/copy-scripts.sh build/lib*/* ../../../downloadable-site-packages/compiled/nacl
