#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

source environment.sh

# Rust will fail anyway but it doesn't matter
python3 -m pip install setuptools_rust
brew install openssl
mv cargo _cargo
source $HOME/.cargo/env
cargo --version || curl https://sh.rustup.rs -sSf | sh
mv _cargo cargo
source $HOME/.cargo/env

export PATH="$(pwd):$PATH"

rustup target add aarch64-apple-ios
cargo install cargo-lipo

export CFLAGS="$CFLAGS -I'$(pwd)' -I/opt/homebrew/opt/openssl@3/include"
export LDFLAGS="$LDFLAGS -L'$(pwd)'/../../../python3_ios/Python3_ios"

export PYO3_CROSS_LIB_DIR"=/Users/emma/Developer/Pyto/python3_ios/Python3_ios"

cd ../cryptography
rm setup.py
cp ../tools/cryptography-setup.py setup.py
python3 setup.py bdist
rm src/rust/Cargo.toml
cp ../tools/Cargo.toml src/rust
pushd src/rust
cargo build --target aarch64-apple-ios
mkdir objects
PUSHD objects
python3 ../../../../tools/extract_objects.py ../target/aarch64-apple-ios/debug/libcryptography_rust.a
xcrun --sdk iphoneos clang -shared -arch arm64 -undefined dynamic_lookup -o _rust.abi3.so *.o
mv _rust.abi3.so ../../../build/lib.iphoneos-arm64-3.10/cryptography/hazmat/bindings/
popd
rm -rf object
popd
python3 ../tools/make_frameworks.py cryptography Cryptography
../tools/copy-scripts.sh build/lib*/cryptography ../../../downloadable-site-packages/compiled/cryptography

