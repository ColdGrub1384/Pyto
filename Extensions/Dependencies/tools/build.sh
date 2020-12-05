#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

for f in build-*.sh; do

echo $f
echo
sh $f

done
