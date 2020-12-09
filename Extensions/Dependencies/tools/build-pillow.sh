#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

pushd ../../../

xcodebuild ARCHS=arm64 ONLY_ACTIVE_ARCH=NO -scheme libpng -sdk iphoneos build SYMROOT=Extensions/Dependencies/tools/build_pillow
xcodebuild ARCHS=arm64 ONLY_ACTIVE_ARCH=NO -scheme libjpeg -sdk iphoneos build SYMROOT=Extensions/Dependencies/tools/build_pillow

popd

pushd build_pillow/*

mv libjpeg.framework/libjpeg ../../libjpeg.dylib
mv libpng.framework/libpng ../../libpng.dylib
touch libfreetype ../../libfreetype.dylib

popd

source environment.sh

export CFLAGS="$CFLAGS -I/usr/local/opt/zlib/include -I../../../libjpeg -I../../../libpng -I../../../freetype2-ios/include"
export LDFLAGS="$LDFLAGS -L/usr/local/opt/zlib/lib -L../tools"

cd ../pillow
python3 setup.py build_ext --disable-tiff --disable-jpeg200 --disable-lcms --disable-imagequant --disable-xcb --disable-platform-guessing --enable-jpeg --enable-zlib --enable-freetype
cp -r src/PIL/* build/lib*/PIL/
python3 ../tools/make_frameworks.py Pillow PIL
rm -rf ../../../site-packages/PIL
cp -r build/lib*/* ../../../site-packages/
find ../../../site-packages/ -name "*.so" -delete

cd ../tools

rm -rf build_pillow
rm -f libjpeg.dylib
rm -f libpng.dylib
rm -f libfreetype.dylib
