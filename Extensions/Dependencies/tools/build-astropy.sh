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
cp cds_lextab.py cds_lextab
cp cds_parsetab.py cds_parsetab
cp cds.py cds
cp generic_lextab.py generic_lextab
cp generic_parsetab.py generic_parsetab
cp generic.py generic
cp ogip_lextab.py ogip_lextab
cp ogip_parsetab.py ogip_parsetab
cp ogip.py ogip

popd


python3 ../tools/make_frameworks.py astropy Astropy
../tools/copy-scripts.sh build/lib*/* ../../../downloadable-site-packages/compiled/astropy
find ../../../downloadable-site-packages/compiled/astropy -name .hidden_file.txt -delete
