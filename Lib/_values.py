from pyto import __Class__
import random
import string
import sys
import threading

_dir = []

_PyValue = __Class__("PyValue")


def random_string(string_length=10):
    """
    Generate a random string of fixed length.
    Taken from 'https://pynative.com/python-generate-random-string/'.
    """

    letters = string.ascii_lowercase
    return "".join(random.choice(letters) for i in range(string_length))


def value(object):

    if object in list(globals().values()):
        for (key, item) in list(globals().items()):
            if item is object:
                _value = _PyValue.alloc().initWithIdentifier(key)
                try:
                    _value.scriptPath = threading.current_thread().script_path
                except AttributeError:
                    pass
                return _value

    id = random_string()
    while id in locals():
        id = random_string()

    globals()[id] = object

    _value = _PyValue.alloc().initWithIdentifier(id)
    try:
        _value.scriptPath = threading.current_thread().script_path
    except AttributeError:
        pass
    return _value


_dir = dir(sys.modules["_values"])
