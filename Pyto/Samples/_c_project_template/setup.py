"""
usage: setup.py [-h] {build,install,clean} ...

Compile project

positional arguments:
  {build,install,clean}
    build               build and link sources
    install             build everything and install to ~/Documents
    clean               remove the build directory

options:
  -h, --help            show this help message and exit
"""

import build_cproj as build
import os.path


# The name of the built executable
PRODUCT_NAME = "{cmd}"

# Prevent these sources from compiling
# (Relative to SRC_DIR, can contain asterisks (*))
EXCLUDE_SOURCES = []

# Copy these headers to build/include
# (Relative to SRC_DIR, can contain asterisks (*))
PUBLIC_HEADERS = ["**/*.h", "**/*.hpp"]

# Additional flags passed to the compiler
# A dictionary of paths and their respective flags as a list of strings
# File paths can contain asterisks (*) and are relative to SRC_DIR
ADDITIONAL_FLAGS = {
    "**/*.c": [],
    "**/*.cpp": []
}

# A list of directories. Will link everything inside these directories.
# Relative to ~/Documents/lib
LINK_LIBRARIES = []


# Compiler and linker
CC = "clang"
LD = "llvm-link"

# Compile everything here
SRC_DIR = "src/"

# Link everything here that ends with .ll or .bc
LIB_DIR = "lib/"

# Include as a header search path and copy content as public headers
INCLUDE_DIR = "include/"

# Place product here
BUILD_DIR = "build/"
OBJECTS_DIR = os.path.join(BUILD_DIR, "lib", PRODUCT_NAME)
PUBLIC_HEADERS_PATH = os.path.join(BUILD_DIR, "include")
EXE_PATH = os.path.join(BUILD_DIR, "bin", PRODUCT_NAME+".bc")
CACHE_DIR = os.path.join(os.path.dirname(OBJECTS_DIR), ".cache")


build.main(globals())
