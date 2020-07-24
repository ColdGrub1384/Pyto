"""
Store values returned from Shortcuts actions.
"""

import random
import importlib.util


def get_random_string(length):
    """
    https://pynative.com/python-generate-random-string/
    """

    chars = ["1", "2", "3", "4", "5", "6", "7", "8", "9", "0"]
    result_str = ''.join(random.choice(chars) for i in range(length))
    return result_str


objects = {}


def import_module(name):
    id = get_random_string(10)
    mod = __import__(name)
    objects[id] = mod
    return (id, str(mod))


def import_script(path):
    id = get_random_string(10)
    spec = importlib.util.spec_from_file_location(path.split(".")[-1], path)
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)

    objects[id] = mod

    return (id, str(mod))


def get_property(name, object_id):
    id = get_random_string(10)
    obj = objects[object_id]
    attr = getattr(obj, name)
    objects[id] = attr
    return (id, str(attr))


def call_function(id, parameters):
    return_value_id = get_random_string(10)

    params = ()

    for param in parameters:
        try:
            if param.stringValue is not None:
                params += (str(param.stringValue),)
            elif param.address is not None:
                params += (objects[str(param.address)],)
        except AttributeError:
            params += (str(param),)

    ret = objects[id](*params)
    objects[return_value_id] = ret
    return (return_value_id, str(ret))