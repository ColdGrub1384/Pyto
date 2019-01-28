"""
This module implements a callback function that is used by the C code to
add Python special methods to Objective-C classes with a suitable interface.
"""
from objc._objc import selector, lookUpClass, currentBundle, repythonify, splitSignature, _block_call, options
from objc._objc import registerMetaDataForSelector, _updatingMetadata, _rescanClass
import sys
import warnings
import collections

__all__ = ( 'addConvenienceForClass', 'registerABCForClass')

CLASS_METHODS = {}
CLASS_ABC = {}

def register(f):
    options._class_extender = f

# XXX: interface is too wide (super_class is not needed, can pass actual class)
@register
def add_convenience_methods(cls, type_dict):
    """
    Add additional methods to the type-dict of subclass 'name' of
    'super_class'.

    CLASS_METHODS is a global variable containing a mapping from
    class name to a list of Python method names and implementation.

    Matching entries from both mappings are added to the 'type_dict'.
    """
    for nm, value in CLASS_METHODS.get(cls.__name__, ()):
        type_dict[nm] = value

    try:
        for cls in CLASS_ABC[cls.__name__]:
            cls.register(cls)
        del CLASS_ABC[cls.__name__]
    except KeyError:
        pass

def register(f):
    options._make_bundleForClass = f

@register
def makeBundleForClass():
    cb = currentBundle()
    def bundleForClass(cls):
        return cb
    return selector(bundleForClass, isClassMethod=True)

def registerABCForClass(classname, *abc_class):
    """
    Register *classname* with the *abc_class*-es when
    the class becomes available.
    """
    try:
        CLASS_ABC += tuple(abc_class)
    except KeyError:
        CLASS_ABC = tuple(abc_class)

    options._mapping_count += 1
    _rescanClass(classname)


def addConvenienceForClass(classname, methods):
    """
    Add the list with methods to the class with the specified name
    """
    try:
        CLASS_METHODS[classname] += tuple(methods)
    except KeyError:
        CLASS_METHODS[classname] = tuple(methods)

    options._mapping_count += 1
    _rescanClass(classname)


#
# Helper functions for converting data item to/from a representation
# that is usable inside Cocoa data structures.
#
# In particular:
#
# - Python "None" is stored as +[NSNull null] because Cocoa containers
#   won't store NULL as a value (and this transformation is undone when
#   retrieving data)
#
# - When a getter returns NULL in Cocoa the queried value is not present,
#   that's converted to an exception in Python.
#

_NULL = lookUpClass('NSNull').null()

def container_wrap(v):
    if v is None:
        return _NULL
    return v

def container_unwrap(v, exc_type, *exc_args):
    if v is None:
        raise exc_type(*exc_args)
    elif v is _NULL:
        return None
    return v

#
#
# Misc. small helpers
#
#

if sys.version_info[0] == 2:  # pragma: no 3.x cover
    addConvenienceForClass('NSNull', (
        ('__nonzero__',  lambda self: False ),
    ))

    addConvenienceForClass('NSEnumerator', (
        ('__iter__', lambda self: self),
        ('next',    lambda self: container_unwrap(self.nextObject(), StopIteration)),
    ))

else:  # pragma: no 2.x cover
    addConvenienceForClass('NSNull', (
        ('__bool__',  lambda self: False ),
    ))

    addConvenienceForClass('NSEnumerator', (
        ('__iter__', lambda self: self),
        ('__next__',    lambda self: container_unwrap(self.nextObject(), StopIteration)),
    ))


def __call__(self, *args, **kwds):
    return _block_call(self, self.__block_signature__, args, kwds)


addConvenienceForClass('NSBlock', (
    ('__call__', __call__),
))
