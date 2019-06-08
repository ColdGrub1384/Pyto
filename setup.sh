#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
cd "$DIR"

# Download and setup ios_system

curl -L $ios_system -o ios_system.tar.gz
tar -xzf ios_system.tar.gz -Cios_system_builds/
mv ios_system_builds/release/* ios_system_builds/
rm -rf ios_system_builds/release
rm ios_system.tar.gz

# Download and setup Python Apple Support for iOS

curl -L "https://s3-us-west-2.amazonaws.com/pybee-briefcase-support/Python-Apple-support/3.7/iOS/Python-3.7-iOS-support.b1.tar.gz" -o python.tar.gz
tar -xzf python.tar.gz -C.
mv Support/* .
rm VERSIONS
rm python.tar.gz
rm -rf Support
mv Python/Resources/lib/python37.zip .

# Download and setup Python Apple Support for macOS

curl -L "https://s3-us-west-2.amazonaws.com/pybee-briefcase-support/Python-Apple-support/3.7/macOS/Python-3.7-macOS-support.b1.tar.gz" -o "Pyto_Mac/python.tar.gz"
tar -xzf "Pyto_Mac/python.tar.gz" -C"Pyto_Mac"
rm "Pyto_Mac/VERSIONS"
rm "Pyto_Mac/python.tar.gz"

# Cocoapods and submodules

pod install
git submodule update --init --recursive
