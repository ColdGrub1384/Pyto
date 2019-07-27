#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
cd "$DIR"

# Download and setup Python Apple Support for iOS

curl -L "https://s3-us-west-2.amazonaws.com/pybee-briefcase-support/Python-Apple-support/3.7/iOS/Python-3.7-iOS-support.b1.tar.gz" -o python.tar.gz
tar -xzf python.tar.gz -C.
mv Support/* .
rm VERSIONS
rm python.tar.gz
rm -rf Support
mv Python/Resources/lib/python37.zip .

# Download and setup Python Apple Support for macOS

curl -L "https://s3-us-west-2.amazonaws.com/pybee-briefcase-support/Python-Apple-support/3.7/macOS/Python-3.7-macOS-support.b1.tar.gz" -o "Python3_Mac/python.tar.gz"
tar -xzf "Python3_Mac/python.tar.gz" -C"Python3_Mac"
rm "Python3_Mac/VERSIONS"
rm "Python3_Mac/python.tar.gz"

# Cocoapods and submodules

pod install
git submodule update --init --recursive
