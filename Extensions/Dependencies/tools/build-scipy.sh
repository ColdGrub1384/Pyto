#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

source environment.sh

export LDFLAGS="$LDFLAGS -L$(pwd) -L$(pwd)/../numpy/build/temp.iphoneos-arm64-3.8"

if ! [ -d fortran-ios ]; then
curl -L https://github.com/ColdGrub1384/fortran-ios/releases/download/v2.2/fortran-ios-macos-$(uname -m).zip -o fortran-ios.zip
unzip fortran-ios.zip
rm -rf __MACOSX
rm -rf fortran-ios.zip
fi

cd ../scipy
python3 setup.py bdist --force
yes | cp -f scipy/misc/*.dat build/lib*/scipy/misc
python3 ../tools/make_frameworks.py scipy SciPy ios_flang_runtime scipy-deps
../tools/copy-scripts.sh build/lib*/* ../../../downloadable-site-packages/compiled/scipy
