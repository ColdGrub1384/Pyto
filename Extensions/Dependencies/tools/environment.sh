SDK="$(xcrun --sdk iphoneos --show-sdk-path)"
XCRUN="iosxcrun"

export PATH="$(pwd)/fortran-ios/bin:$(pwd):$PATH"

export _PYTHON_HOST_PLATFORM=iphoneos-arm64
export IPHONEOS_DEPLOYMENT_TARGET=12.0
export LD="$XCRUN"
export CC="$XCRUN --sdk iphoneos clang -arch arm64"
export CXX="$XCRUN --sdk iphoneos clang++ -arch arm64"
export LDFLAGS="-arch arm64 -mios-version-min=12.0 -isysroot $SDK"
export CPPFLAGS="-arch arm64 -mios-version-min=12.0 -isysroot $SDK -UHAVE_FEATURES_H"
export CFLAGS="-arch arm64 -mios-version-min=12.0 -isysroot $SDK -UHAVE_FEATURES_H"
export ARCHFLAGS="-arch arm64"
