#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

source environment.sh

cd ../biopython
python3 setup.py bdist
python3 ../tools/make_frameworks.py biopython Biopython
../tools/copy-scripts.sh build/lib*/Bio ../../../downloadable-site-packages/compiled/Bio
rm -rf ../../../site-packages/BioSQL
cp -r build/lib*/BioSQL ../../../site-packages/BioSQL
