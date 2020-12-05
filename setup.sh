#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
cd "$DIR"

# OpenCV

rm -rf opencv2.framework
curl -L -O https://github.com/ColdGrub1384/OpenCV-Contrib-iOS/releases/download/4.3.0/opencv2.framework.zip
unzip opencv2.framework.zip
rm -rf opencv2.framework.zip
rm -rf __MACOSX

# OpenBlas and everything Fortran related

curl -L https://github.com/ColdGrub1384/lapack-ios/releases/download/v1.2/lapack-ios.zip -o lapack-ios.zip
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

# Pure Python dependencies

cd site-packages
./install.sh

# And C Extensions

cd ../
Extensions/Dependencies/tools/build.sh
