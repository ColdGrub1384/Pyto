#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

source environment.sh

if ! [ -d fortran-ios ]; then
curl -L https://github.com/ColdGrub1384/fortran-ios/releases/download/v1.0/fortran-ios-macos-x86_64.zip -o fortran-ios.zip
unzip fortran-ios.zip
rm -rf __MACOSX
rm -rf fortran-ios.zip
fi

cd ../scipy
python3 setup.py bdist --force
yes | cp -f scipy/misc/*.dat build/lib*/scipy/misc
python3 ../tools/make_frameworks.py scipy SciPy ios_flang_runtime scipy-deps
../tools/copy-scripts.sh build/lib*/* ../../../downloadable-site-packages/compiled/scipy
