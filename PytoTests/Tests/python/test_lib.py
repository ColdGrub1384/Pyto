from pip import main as pip
from console import clear
import sys
import os
import numpy
print(numpy)

tests = sys.argv[1]

if not "PYTEST_INSTALLED" in os.environ:
    os.environ["PYTEST_INSTALLED"] = "1"

    try:
        pip(["install", "pytest"])
        pip(["install", "hypothesis"])
    except SystemExit:
        pass

    clear()

from pytest import main as pytest

excluded = [
    "test_import_lazy_import",
    "test_numpy_namespace",
    "test_full_reimport",
    "test_api_importable",
    "test_all_modules_are_expected",
    "test_all_modules_are_expected_2",
    "test_numpy_reloading",
    "test_pep338",
]
excluded = " and not ".join(excluded)

pytest([tests, "-k", "not "+excluded])
