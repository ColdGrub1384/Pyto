#!/usr/bin/env python3
"""
Generates a script for each downloadable package so code completion detects them even when they are not downloaded.
"""

import os

cwd = os.path.dirname(__file__)

path = os.path.join(cwd, "..", "..", "downloadable-site-packages", "compiled")
packages = os.listdir(path)

for file in os.listdir(cwd):
    if file != __file__.split("/")[-1]:
        os.remove(os.path.join(cwd, file))

for package in packages:
    package_path = os.path.join(path, package)
    if not os.path.isdir(package_path) or package_path.endswith(".dist-info"):
        continue
    
    with open(os.path.join(cwd, package)+".py", "w+") as f:
        f.write("''' Auto generated. Do not import '''")
