#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

source environment.sh

export STATIC_DEPS=false
export CPPFLAGS="-I/usr/local/opt/libxslt/include"

cd ../libxml2
./autogen.sh --build=x86_64-apple-darwin --host=aarch64-apple-darwin13 --disable-dependency-tracking
make
rm -f ../../Lxml/libxml2.a
cp .libs/libxml2.a ../../Lxml

cd ../libxslt
xcodebuild ARCHS=arm64 ONLY_ACTIVE_ARCH=NO -scheme libxslt -sdk iphoneos build SYMROOT=build
mv build/Debug-iphoneos/liblibxslt.a build/Debug-iphoneos/libxslt.a
rm -f ../../Lxml/libxslt.a
cp build/Debug-iphoneos/libxslt.a ../../Lxml

OLD_PWD="$(pwd)"
cd ../../Lxml/
mkdir dependencies
mv *.a dependencies
cd dependencies
ar x libxml2.a
ar x libxslt.a
cd ../
xcrun -sdk iphoneos clang -shared -fpic dependencies/*.o -arch arm64 -undefined dynamic_lookup -o dependencies/lxml
rm -rf "dependencies/__.SYMDEF SORTED"
rm -rf dependencies/*.o
mkdir dependencies/lxml.framework
mv dependencies/lxml dependencies/lxml.framework
cp ../Dependencies/tools/lxml-Info.plist dependencies/lxml.framework/Info.plist
mv dependencies/lxml.framework dependencies/lxml-deps.framework
cd $OLD_PWD

cd ../lxml
python3 setup.py build
python3 ../tools/make_frameworks.py lxml Lxml
../tools/copy-scripts.sh build/lib*/* ../../../downloadable-site-packages/compiled/lxml
