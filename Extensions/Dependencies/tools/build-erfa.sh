#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

python3 -m pip install packaging
python3 -m pip install --upgrade setuptools_scm

source environment.sh

cd ../erfa

rm -rf setup.py
cp ../tools/erfa-setup.py setup.py

git submodule init 
git submodule update

export CPPFLAGS="-arch arm64 -mios-version-min=12.0 -isysroot $SDK -UHAVE_FEATURES_H"
export CFLAGS="-arch arm64 -mios-version-min=12.0 -isysroot $SDK -UHAVE_FEATURES_H"
export CFLAGS="$CFLAGS -I'liberfa/erfa' -I'$NUMPY1' -I'$NUMPY2'"
export CPPFLAGS="$CPPFLAGS -I'liberfa/erfa' -I'$NUMPY1' -I'$NUMPY2'"

python3 setup.py bdist
python3 ../tools/make_frameworks.py erfa Erfa
../tools/copy-scripts.sh build/lib*/* ../../../downloadable-site-packages/compiled/erfa
