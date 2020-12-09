#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

echo "Third Party Libraries"
echo "====================="

echo "Pyto can install third party libraries from PyPI. However, the Full Version includes also some popular libraries with compiled code in them. It's not possible to install them at runtime because iOS doesn't allow loading compiled plugins not included by the developer."

echo "Pyto also provides some pure Python libraries as dependencies."

echo

echo "Full Version Exclusive"
echo "----------------------"
echo

INFOS=$(echo ../Extensions/Dependencies/*/*.egg-info)

for i in $INFOS; do

NAME=$(cat "$i/PKG-INFO" | grep "^Name:" | awk -F'Name: ' '{print $2}')
VERSION=$(cat "$i/PKG-INFO" | grep "^Version:" | awk -F'Version: ' '{print $2}')
HOMEPAGE=$(cat "$i/PKG-INFO" | grep "^Home-page:" | awk -F'Home-page: ' '{print $2}')

echo "- \`$NAME <$HOMEPAGE>\`_ $VERSION"

done;

OPENCV=../site-packages/opencv_python-*.dist-info/METADATA
OPENCV_NAME=$(cat $OPENCV | grep "^Name:" | awk -F'Name: ' '{print $2}')
OPENCV_VERSION=$(cat $OPENCV | grep "^Version:" | awk -F'Version: ' '{print $2}')
OPENCV_HOMEPAGE=$(cat $OPENCV | grep "^Home-page:" | awk -F'Home-page: ' '{print $2}')

echo "- \`$OPENCV_NAME <$OPENCV_HOMEPAGE>\`_ $OPENCV_VERSION"

echo

echo "Other dependencies"
echo "------------------"

INFOS=$(echo ../site-packages/*.dist-info)

for i in $INFOS; do

NAME=$(cat "$i/METADATA" | grep "^Name:" | awk -F'Name: ' '{print $2}')
VERSION=$(cat "$i/METADATA" | grep "^Version:" | awk -F'Version: ' '{print $2}')
HOMEPAGE=$(cat "$i/METADATA" | grep "^Home-page:" | awk -F'Home-page: ' '{print $2}')

if [ "$NAME" != "opencv-python" ]; then
if ! [[ "$NAME" =~ ^distro ]]; then # WTF its name and version
echo "- \`$NAME <$HOMEPAGE>\`_ $VERSION"
fi
fi

done;

echo
echo
echo "See \`licenses <licenses.html>\`_."
