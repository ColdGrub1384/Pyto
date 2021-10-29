#!/bin/bash

LIBRARY=$1
OUTPUT=$2

rm -rf $2
cp -r $1 $2
find $2 -name "*.py" -exec $(which python3) -c "from os.path import splitext; from py_compile import compile; compile('{}', splitext('{}')[0]+'.pyc')" \;
find $2 -name "*.py" -delete
find $2 -name "*.pyx" -delete
find $2 -name "*.pxd" -delete
find $2 -name "*.so" -delete
