#!/bin/bash

cloc . --exclude-dir=Pods,site-packages,downloadable-site-packages,docs_build,libpng,TextKit_LineNumbers,Samples,_includes,_layouts,_sass,assets,InputAssistant,python3_ios,Extensions,objc,libjpeg,libfreetype,Python,Other --exclude-lang="HTML,Sass,D,YAML,make,DOS Batch"
