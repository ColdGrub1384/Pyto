#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

source environment.sh
export CC=""
export CXX="/usr/bin/xcrun --sdk iphoneos clang++ -arch arm64"

cd ../pyzmq
python3 setup.py build --zmq=bundled
python3 ../tools/make_frameworks.py pyzmq Zmq
../tools/copy-scripts.sh build/lib*/* ../../../downloadable-site-packages/compiled/zmq
