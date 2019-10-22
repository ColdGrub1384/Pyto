#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
cd "$DIR"

# libffi

cd libffi
autoreconf -i
python2 generate-darwin-source-and-headers.py --only-ios
cd ../

# Cocoapods and submodules

pod install
git submodule update --init --recursive
