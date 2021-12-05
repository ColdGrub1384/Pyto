#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

source environment.sh

python3 -m pip install pybind11
python3 -m pip install pythran

export LDFLAGS="$LDFLAGS -L$(pwd) -L$(pwd)/../numpy/build/temp.iphoneos-arm64-3.10"

if ! [ -d fortran-ios ]; then
curl -L https://github.com/ColdGrub1384/fortran-ios/releases/download/v2.3/fortran-ios-macos-$(uname -m).zip -o fortran-ios.zip
unzip fortran-ios.zip
rm -rf __MACOSX
rm -rf fortran-ios.zip
fi

rm fortran-ios/bin/gfortran
cp gfortran fortran-ios/bin

cd ../scipy

rm scipy/ndimage/src/ni_morphology.c
cp ../tools/ni_morphology.c scipy/ndimage/src/

git submodule update --init

python3 setup.py bdist --force
yes | cp -f scipy/misc/*.dat build/lib*/scipy/misc
python3 ../tools/make_frameworks.py scipy SciPy ios_flang_runtime scipy-deps
../tools/copy-scripts.sh build/lib*/* ../../../downloadable-site-packages/compiled/scipy
