#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

brew install libxslt pkg-config autoconf automake libtool
ln -s /usr/local/bin/glibtoolize /usr/local/bin/libtoolize

cd ../libxslt

mkdir -p ../../Lxml

xcodebuild ARCHS=arm64 ONLY_ACTIVE_ARCH=NO -scheme libxslt -sdk iphoneos build SYMROOT=build
mv build/Debug-iphoneos/liblibxslt.a build/Debug-iphoneos/libxslt.a
rm -f ../../Lxml/libxslt.a
cp build/Debug-iphoneos/libxslt.a ../../Lxml

pushd ../tools
source environment.sh
popd

export STATIC_DEPS=false
export CPPFLAGS="-I/usr/local/opt/libxslt/include"

cd ../libxml2
./autogen.sh --build=x86_64-apple-darwin --host=aarch64-apple-darwin13 --disable-dependency-tracking
make
rm -f ../../Lxml/libxml2.a
cp .libs/libxml2.a ../../Lxml

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
rm -rf dependencies/lxml-deps.framework
mv dependencies/lxml.framework dependencies/lxml-deps.framework
cd $OLD_PWD

cd ../lxml
python3 setup.py bdist
python3 ../tools/make_frameworks.py lxml Lxml
../tools/copy-scripts.sh build/lib*/* ../../../downloadable-site-packages/compiled/lxml
