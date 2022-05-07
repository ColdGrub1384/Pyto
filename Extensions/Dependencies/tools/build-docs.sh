#!/usr/bin/env bash

cd "$(dirname "${BASH_SOURCE[0]}")"
cd ../

python3 -m pip install sphinx python-docs-theme sphinx_copybutton sphinx_issues sphinx_removed_in sphinxext-opengraph sphinx-tabs sphinx-gallery sphinx-prompt sphinx-material sphinx-panels sphinxcontrib-svg2pdfconverter sphinxcontrib-log-cabinet nbsphinx pydata-sphinx-theme crate sphinx-csv-filter pallets-sphinx-themes colorspacious cppy numpydoc matplotlib pandas seaborn tornado gevent nbconvert pandoc gitpython jupyter plotly myst-parser pooch dask travertino mock furo pyOpenSSL pysocks > /dev/null

function pillow {
    pushd Pillow/docs
    python3 -m pip install Pillow > /dev/null
    make html
    rm -rf ../../../../documentations/pillow
    cp -r _build/html ../../../../documentations/pillow
    popd
}

function cryptography {
    pushd cryptography/docs
    python3 -m pip install cryptography > /dev/null
    make html
    rm -rf ../../../../documentations/cryptography
    cp -r _build/html ../../../../documentations/cryptography
    popd
}

function kiwisolver {
    pushd kiwisolver/docs
    python3 -m pip install kiwisolver > /dev/null
    make html
    rm -rf ../../../../documentations/kiwisolver
    cp -r build/html ../../../../documentations/kiwisolver
    popd
}

function nacl {
    pushd nacl/docs
    python3 -m pip install pynacl > /dev/null
    make html
    rm -rf ../../../../documentations/nacl
    cp -r _build/html ../../../../documentations/nacl
    popd
}

function pywt {
    pushd pywt/doc
    python3 -m pip install PyWavelets > /dev/null
    make html
    rm -rf ../../../../documentations/pywt
    cp -r build/html ../../../../documentations/pywt
    popd
}

function sklearn {
    pushd sklearn/doc
    python3 -m pip install scikit-learn==0.19 > /dev/null
    make html
    rm -rf ../../../../documentations/sklearn
    cp -r _build/html/stable ../../../../documentations/sklearn
    popd
}

function astropy {
    python3 -m pip install astropy sphinx-astropy > /dev/null
    ASTROPY_PATH="$(python3 -c 'import astropy; import os.path; print(os.path.dirname(astropy.__file__))')"
    pushd astropy
    python3 setup.py build
    rm -rf "$ASTROPY_PATH"
    cp -r build/lib.macosx*/astropy "$ASTROPY_PATH"
    pushd doc
    make html
    rm -rf ../../../../documentations/astropy
    cp -r _build/html ../../../../documentations/astropy
    popd
    popd
}

function numpy {
    python3 -m pip install numpy==v1.22.3 > /dev/null
    pushd numpy
    python3 -m pip install -r doc_requirements.txt
    pushd doc
    make html
    rm -rf ../../../../documentations/numpy
    cp -r build/html ../../../../documentations/numpy
    popd
    popd
}

function zmq {
    pushd pyzmq/docs
    python3 -m pip install pyzmq > /dev/null
    make html
    rm -rf ../../../../documentations/zmq
    cp -r build/html ../../../../documentations/zmq
    popd
}

function statsmodels {
    pushd statsmodels/docs
    brew install pandoc
    python3 -m pip install statsmodels > /dev/null
    make html
    rm -rf ../../../../documentations/statsmodels
    cp -r build/html ../../../../documentations/statsmodels
    popd
}

function erfa {
    pushd erfa/docs
    python3 -m pip install pyerfa > /dev/null
    make html
    rm -rf ../../../../documentations/erfa
    cp -r _build/html ../../../../documentations/erfa
    popd
}

function pandas {
    pushd pandas/doc
    python3 -m pip install pandas==1.1.4 > /dev/null
    python3 make.py --python-path ""
    rm -rf ../../../../documentations/pandas
    cp -r build/html ../../../../documentations/pandas
    popd
}

function scipy {
    pushd scipy/doc
    python3 -m pip install scipy==1.7.3 setuptools==59.0.1 > /dev/null
    make html
    python3 -m pip install --upgrade setuptools
    rm -rf ../../../../documentations/scipy
    cp -r build/html ../../../../documentations/scipy
    popd
}

function cffi {
    pushd cffi/doc
    python3 -m pip install cffi > /dev/null
    make html
    rm -rf ../../../../documentations/cffi
    cp -r build/html ../../../../documentations/cffi
    popd
}

function matplotlib {
    pushd matplotlib
    brew install graphviz texlive
    python3 setup.py build
    export PYTHONPATH="$(pwd)"/build/lib*macosx*
    pushd doc
    make html SPHINXBUILD="python3 -msphinx"
    rm -rf ../../../../documentations/matplotlib
    cp -r build/html ../../../../documentations/matplotlib
    popd
    popd
}

function skimage {
    pushd skimage
    export CFLAGS="$CFLAGS -Wno-implicit-function-declaration"
    python3 setup.py build
    export PYTHONPATH="$(pwd)"/build/lib*macosx*
    pushd doc
    make html SPHINXBUILD="python3 -m sphinx"
    rm -rf ../../../../documentations/skimage
    cp -r build/html ../../../../documentations/skimage
    popd
    popd
}


function toga {
    pushd ../../documentations/dependencies/toga/docs
    python3 -m pip install toga > /dev/null
    make html SPHINXBUILD="python3 -m sphinx"
    rm -rf ../../../toga
    cp -r _build/html ../../../toga
    popd
}

function html5lib {
    pushd ../../documentations/dependencies/html5lib-python/doc
    python3 -m pip install html5lib > /dev/null
    make html
    rm -rf ../../../html5lib
    cp -r _build/html ../../../html5lib
    popd
}

function requests {
    pushd ../../documentations/dependencies/requests/docs
    python3 -m pip install requests > /dev/null
    make html
    rm -rf ../../../requests
    cp -r _build/html ../../../requests
    popd
}

function urllib3 {
    pushd ../../documentations/dependencies/urllib3
    pip install . > /dev/null
    pushd docs
    make html SPHINXBUILD="python3 -m sphinx" SPHINXOPTS=""
    rm -rf ../../../urllib3
    cp -r _build/html ../../../urllib3
    popd
    popd
}

function rubicon {
    pushd ../../documentations/dependencies/rubicon-objc/docs
    pip install rubicon-objc > /dev/null
    make html SPHINXBUILD="python3 -m sphinx"
    rm -rf ../../../rubicon-objc
    cp -r _build/html ../../../rubicon-objc
    popd
}

function markupsafe {
    pushd markupsafe/docs
    pip install markupsafe > /dev/null
    make html SPHINXBUILD="python3 -m sphinx"
    rm -rf ../../../../documentations/markupsafe
    cp -r _build/html ../../../../documentations/markupsafe
    popd
}

if [ $# -eq 0 ]
then
    pillow
    cryptography
    kiwisolver
    nacl
    pywt
    sklearn
    astropy
    numpy
    zmq
    statsmodels
    erfa
    pandas
    scipy
    cffi
    matplotlib
    skimage
    toga
    html5lib
    requests
    urllib3
    rubicon
    markupsafe
else
"$1"
fi

../../documentations/compress.py
