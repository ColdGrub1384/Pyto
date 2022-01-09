#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

python3 -m pip install scipy

source environment.sh

cd ../statsmodels

export LDFLAGS="-L'../numpy/build/temp.iphoneos-arm64-3.10/'"

python3 setup.py bdist
python3 ../tools/make-statsmodels-dylibs.py
python3 ../tools/make_frameworks.py statsmodels Statsmodels
../tools/copy-scripts.sh build/lib*/* ../../../site-packages/statsmodels
