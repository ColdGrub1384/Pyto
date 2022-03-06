#!/bin/bash

LIBRARY=$1
OUTPUT=$2

rm -rf $OUTPUT
cp -r $LIBRARY $OUTPUT
