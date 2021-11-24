#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

echo "build-numpy.sh"
echo
sh build-numpy.sh

for f in build-*.sh; do

if [ $f != "build-numpy.sh" ]; then

echo $f
echo
sh $f

fi

done
