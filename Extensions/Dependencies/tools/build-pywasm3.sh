#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

source environment.sh

cd ../pywasm3
python3 setup.py bdist_wheel
python3 ../tools/make_frameworks.py pywasm3 PyWASM3
