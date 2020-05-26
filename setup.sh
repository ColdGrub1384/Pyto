#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
cd "$DIR"

# OpenCV

cd OpenCV

curl -L -O https://github.com/ColdGrub1384/OpenCV-Contrib-iOS/releases/download/4.3.0/opencv2.framework.zip
unzip opencv2.framework.zip
rm -rf opencv2.framework.zip
rm -rf __MACOSX

cd ../

# Cocoapods and submodules

pod install
git submodule update --init --recursive
