#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

source environment.sh
export CC="clang.sh"
export CXX="clang.sh"

cd ../pyzmq
python3 setup.py bdist --zmq=bundled
python3 ../tools/make_frameworks.py pyzmq Zmq
../tools/copy-scripts.sh build/lib*/* ../../../downloadable-site-packages/compiled/zmq
