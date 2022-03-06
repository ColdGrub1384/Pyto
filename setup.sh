#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
cd "$DIR"

python3 -m pip install Cython
python3 -m pip install numpy
python3 -m pip install jinja2
python3 -m pip install wheel
brew install zlib

# Python

curl -L https://briefcase-support.org/python\?platform\=iOS\&version\=3.10 -o Python-3.10-iOS-support.b1.tar.gz
mkdir python-apple-support
cd python-apple-support

tar -xzvf Python-3.10-iOS-support.b1.tar.gz
rm ../Python-3.10-iOS-support.b1.tar.gz

cp OpenSSL/libOpenSSL.a ../
cp OpenSSL/libOpenSSL.a ../python3_ios/Python3_ios/libOpenSSL.a
cp libFFI/libFFI.a ../python3_ios/Python3_ios/
cp BZip2/libbzip2.a ../python3_ios/Python3_ios/libbz2.a
cp XZ/libxz.a ../python3_ios/Python3_ios/liblzma.a
cp Python/libPython.a ../python3_ios/Python3_ios/libPython3.10.a
cp -r Python/Resources/lib/python3.10 ../site-packages/python3.10

cd ../
rm -rf python-apple-support

# LLVM

pushd Extensions/Dependencies/ios_system

curl -L -O https://github.com/ColdGrub1384/llvm-project/releases/download/v.1.0.0-python/llvm-project-ios-arm64.zip -o llvm-project
unzip llvm-project-ios-arm64.zip
rm -rf __MACOSX
rm llvm-project-ios-arm64.zip

popd

# OpenCV

rm -rf opencv2.framework
curl -L -O https://github.com/ColdGrub1384/OpenCV-Contrib-iOS/releases/download/4.3.0/opencv2.framework.zip
unzip opencv2.framework.zip
rm -rf opencv2.framework.zip
rm -rf __MACOSX

# OpenBlas and everything Fortran related

curl -L https://github.com/ColdGrub1384/lapack-ios/releases/download/v1.4/lapack-ios.zip -o lapack-ios.zip
mkdir Extensions/SciPy/
unzip lapack-ios.zip
yes | cp -rf lapack-ios/openblas.framework Extensions/OpenBlas
cp -r lapack-ios/lapack.framework Extensions/SciPy
yes | cp -rf lapack-ios/ios_flang_runtime.framework Extensions/SciPy
rm -rf Extensions/SciPy/scipy-deps.framework
mv Extensions/SciPy/lapack.framework Extensions/SciPy/scipy-deps.framework
rm -rf __MACOSX
rm -rf lapack-ios

# Cocoapods and submodules

pod install
git submodule update --init --recursive

# CFFI

cd Extensions/Dependencies
curl https://files.pythonhosted.org/packages/cb/ae/380e33d621ae301770358eb11a896a34c34f30db188847a561e8e39ee866/cffi-1.14.3.tar.gz --output cffi.tar.gz
tar -xzvf cffi.tar.gz
rm cffi.tar.gz
rm -rf cffi
mv cffi* cffi

cd ../../

# Dependencies

cd site-packages
./install.sh
