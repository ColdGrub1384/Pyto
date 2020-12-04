#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

source environment.sh

export CFLAGS="$CFLAGS -I/usr/local/opt/zlib/include"
export CPPFLAGS="$CPPFLAGS -I/usr/local/opt/zlib/include"
export LDFLAGS="$LDFLAGS -L/usr/local/opt/zlib/lib"

cd ../pillow
python3 setup.py build_ext --disable-tiff --disable-jpeg200 --disable-lcms --disable-imagequant --disable-xcb --disable-platform-guessing --enable-jpeg --enable-zlib --enable-freetype
cp -r src/PIL/* build/lib*/PIL/
python3 ../tools/make_frameworks.py Pillow PIL
rm -rf ../../../site-packages/PIL
cp -r build/lib*/* ../../../site-packages/
