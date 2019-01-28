"""
Python <-> Objective-C bridge (PyObjC)

This module defines the core interfaces of the Python<->Objective-C bridge.
"""
import sys

# Aliases for some common Objective-C constants
nil = None
YES = True
NO = False

# Import the namespace from the _objc extension
def _update(g=globals()):
    import objc._objc as _objc
    for k in _objc.__dict__:
        g.setdefault(k, getattr(_objc, k))
_update()
del _update

from objc._convenience import *
from objc._convenience_nsobject import *
from objc._convenience_nsdecimal import *
from objc._convenience_nsdata import *
from objc._convenience_nsdictionary import *
from objc._convenience_nsset import *
from objc._convenience_nsarray import *
from objc._convenience_nsstring import *
from objc._convenience_mapping import *
from objc._convenience_sequence import *

from objc._bridgesupport import *

from objc._dyld import *
from objc._protocols import *
from objc._descriptors import *
from objc._category import *
from objc._bridges import *
from objc._pythonify import *
from objc._locking import *
from objc._context import *
from objc._properties import *
from objc._lazyimport import *
from objc._compat import *
import objc._callable_docstr

import objc._pycoder as _pycoder

# Helper function for new-style metadata modules
def _resolve_name(name):
    if '.' not in name:
        raise ValueError(name)

    module, name = name.rsplit('.', 1)
    m = __import__(module)
    for k in module.split('.')[1:]:
        m = getattr(m, k)

    return getattr(m, name)



_NSAutoreleasePool = None
class autorelease_pool(object):
    """
    A context manager that implements the same feature as
    @synchronized statements in Objective-C. Locking can also
    be done manually using the ``lock`` and ``unlock`` methods.

    The mutex for object ``anObject`` is represented by
    ``objc.object_lock(anObject)``.
    """
    def __init__(self):
        global _NSAutoreleasePool
        if _NSAutoreleasePool is None:
            _NSAutoreleasePool = objc.lookUpClass('NSAutoreleasePool')

    def __enter__(self):
        self._pool = _NSAutoreleasePool.alloc().init()

    def __exit__(self, type, value, tp):
        del self._pool
