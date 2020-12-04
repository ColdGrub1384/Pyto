#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

find . -name "build-*.sh" -exec sh {} \;
