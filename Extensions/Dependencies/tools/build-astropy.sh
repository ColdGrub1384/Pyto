#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

CURDIR="$PWD"

source environment.sh

python3 -m pip install extension_helpers

cd ../astropy
python3 setup.py bdist

pushd build/lib*/*/units/format
rm base.py
cp "$CURDIR/astropy-base.py" base.py
popd


python3 ../tools/make_frameworks.py astropy Astropy
../tools/copy-scripts.sh build/lib*/* ../../../downloadable-site-packages/compiled/astropy
find ../../../downloadable-site-packages/compiled/astropy -name .hidden_file.txt -delete
find ../../../downloadable-site-packages/compiled/astropy -name "*.sh" -delete
