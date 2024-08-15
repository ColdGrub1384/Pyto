name: Build Pyto

on:
  push:
    branches:
      - main
  pull_request:

jobs:
  build:
    runs-on: macos-latest
    steps:
      - name: Checkout code
        uses: actions/checkout@v2

      - name: Set up Xcode
        run: sudo xcode-select -switch /Applications/Xcode.app/Contents/Developer

      - name: Install dependencies
        run: ./setup.sh

      - name: Build
        run: xcodebuild -workspace Pyto.xcworkspace -scheme Pyto -configuration Release
