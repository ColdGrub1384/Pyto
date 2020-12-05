#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

source environment.sh

python3 -m pip install extension_helpers

cd ../astropy
python3 setup.py bdist
python3 ../tools/make_frameworks.py astropy Astropy
../tools/copy-scripts.sh build/lib*/* ../../../downloadable-site-packages/compiled/astropy
