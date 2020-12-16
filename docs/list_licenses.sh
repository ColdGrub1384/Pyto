#!/bin/zsh

cd "$(dirname "${BASH_SOURCE[0]}")"
cd ../

echo "Licenses"
echo "========"

echo

for i in **/LICENSE*; do
LEN=$(echo ${#i})

echo ".. raw:: html"
echo
echo "   <details>"
echo "   <summary><b>$i</b></summary>"
echo

echo
echo
echo ".. code-block:: text"
echo
cat $i | sed 's/^/   /'
echo

echo ".. raw:: html"
echo
echo "   </details>"

echo

echo ".. raw:: html"
echo
echo "   <br/>"

done
