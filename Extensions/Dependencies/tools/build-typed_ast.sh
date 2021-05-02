#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

source environment.sh

cd ../typed_ast
python3 setup.py bdist
python3 ../tools/make_frameworks.py typed_ast TypedAST
../tools/copy-scripts.sh build/lib*/* ../../../downloadable-site-packages/compiled/typed_ast
