#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

source environment.sh

cd ../gensim
python3 setup.py bdist
python3 ../tools/make_frameworks.py gensim Gensim
../tools/copy-scripts.sh build/lib*/* ../../../downloadable-site-packages/compiled/gensim
