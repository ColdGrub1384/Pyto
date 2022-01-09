#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

source environment.sh

export PYTHON_CROSSENV=1
export PYODIDE_PACKAGE_ABI=1
export SKLEARN_NO_OPENMP=TRUE

cd ../sklearn
python3 setup.py bdist
python3 ../tools/make_frameworks.py sklearn SkLearn
../tools/copy-scripts.sh build/lib*/* ../../../site-packages/sklearn

cp -r sklearn/datasets/data ../../../site-packages/sklearn/datasets
cp -r sklearn/datasets/descr ../../../site-packages/sklearn/datasets
cp -r sklearn/datasets/images ../../../site-packages/sklearn/datasets
