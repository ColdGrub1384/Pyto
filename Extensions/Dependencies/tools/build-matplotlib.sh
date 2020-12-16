#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

echo "int main() {}" > a.c
xcrun -sdk macosx clang -arch x86_64 -shared a.c -o libfreetype.dylib

source environment.sh
export CFLAGS="$CFLAGS -I$PWD/../../../freetype2-ios/include "
export LDFLAGS="$LDFLAGS -L$PWD"

cd ../matplotlib
rm -f setup.cfg
cp ../tools/matplotlib-setup.cfg setup.cfg

python3 setup.py bdist
python3 ../tools/make_frameworks.py matplotlib Matplotlib
grep -qxF "# Code implemented by Pyto for showing images with the AGG backend" build/lib*/matplotlib/backends/backend_agg.py || cat ../tools/agg.py >> build/lib*/matplotlib/backends/backend_agg.py
../tools/copy-scripts.sh build/lib*/matplotlib ../../../downloadable-site-packages/compiled/matplotlib

rm -f ../../../site-packages/pyblab.py
rm -rf ../../../site-packages/mpl_toolkits
rm -rf ../../../site-packages/mpl-data

cp -r build/lib*/mpl_toolkits ../../../site-packages/
cp -r build/lib*/matplotlib/mpl-data ../../../site-packages/
cp build/lib*/pylab.py ../../../site-packages/

rm ../tools/libfreetype.dylib
rm ../tools/a.c

find ../../../downloadable-site-packages/compiled/matplotlib -name ".*" -delete
