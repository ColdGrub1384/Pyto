#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

yes | find ../ -name "*.egg-info" -exec cp -rf {} ../../../site-packages \;
#yes | find ../ -name "*.dist-info" -exec cp -rf {} ../../../site-packages \;
