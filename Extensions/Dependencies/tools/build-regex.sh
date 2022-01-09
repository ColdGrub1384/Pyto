#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

source environment.sh

cd ../regex
python3 setup.py bdist
python3 ../tools/make_frameworks.py regex Regex
../tools/copy-scripts.sh build/lib*/* ../../../site-packages/regex
