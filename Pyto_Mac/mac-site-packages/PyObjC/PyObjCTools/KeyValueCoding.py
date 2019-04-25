"""
Support for Key-Value Coding in Python. This provides a simple functional
interface to Cocoa's Key-Value coding that also works for regular Python
objects.

Public API:

    setKey(obj, key, value) -> None
    setKeyPath (obj, keypath, value) -> None

    getKey(obj, key) -> value
    getKeyPath (obj, keypath) -> value

A keypath is a string containing a sequence of keys seperated by dots. The
path is followed by repeated calls to 'getKey'. This can be used to easily
access nested attributes.

This API is mirroring the 'getattr' and 'setattr' APIs in Python, this makes
it more natural to work with Key-Value coding from Python. It also doesn't
require changes to existing Python classes to make use of Key-Value coding,
making it easier to build applications as a platform independent core with
a Cocoa GUI layer.

See the Cocoa documentation on the Apple developer website for more
information on Key-Value coding. The protocol is basicly used to enable
weaker coupling between the view and model layers.
"""
from __future__ import unicode_literals
import sys

__all__ = ("getKey", "setKey", "getKeyPath", "setKeyPath")
if sys.version_info[0] == 2:  # pragma: no 3.x cover; pragma: no branch
    __all__ = tuple(str(x) for x in __all__)


import objc
import types
import sys
import warnings

if sys.version_info[0] == 2:  # pragma: no 3.x cover
    from itertools import imap as map
    import collections as collections_abc

else:   # pragma: no cover (py3k)
    basestring = str
    import collections.abc as collections_abc

_null = objc.lookUpClass('NSNull').null()

def keyCaps(s):
    return s[:1].capitalize() + s[1:]

# From http://aspn.activestate.com/ASPN/Cookbook/Python/Recipe/393090
# Title: Binary floating point summation accurate to full precision
# Version no: 2.2

def msum(iterable):
    "Full precision summation using multiple floats for intermediate values"
    # sorted, non-overlapping partial sums
    partials = []
    for x in iterable:
        i = 0
        for y in partials:
            if abs(x) < abs(y):
                x, y = y, x
            hi = x + y
            lo = y - (hi - x)
            if lo:
                partials[i] = lo
                i += 1
            x = hi
        partials[i:] = [x]
    return sum(partials, 0.0)

class _ArrayOperators (object):

    @staticmethod
    def avg(obj, segments):
        path = '.'.join(segments)
        lst = getKeyPath(obj, path)
        count = len(lst)
        if count == 0:
            return 0.0
        return msum(float(x) if x is not _null else 0.0 for x in lst) / count

    @staticmethod
    def count(obj, segments):
        return len(obj)

    @staticmethod
    def distinctUnionOfArrays(obj, segments):
        path = '.'.join(segments)
        rval = []
        s = set()
        r = []
        for lst in obj:
            for item in (getKeyPath(item, path) for item in lst):
                try:
                    if item in s or item in r:
                        continue
                    rval.append(item)
                    s.add(item)

                except TypeError:
                    if item in rval:
                        continue

                    rval.append(item)
                    r.append(item)
        return rval

    @staticmethod
    def distinctUnionOfSets(obj, segments):
        path = '.'.join(segments)
        rval = set()
        for lst in obj:
            for item in (getKeyPath(item, path) for item in lst):
                rval.add(item)
        return rval

    @staticmethod
    def distinctUnionOfObjects(obj, segments):
        path = '.'.join(segments)
        rval = []
        s = set()
        r = []
        for item in (getKeyPath(item, path) for item in obj):
            try:
                if item in s or item in r:
                    continue

                rval.append(item)
                s.add(item)

            except TypeError:
                if item in rval:
                    continue

                rval.append(item)
                r.append(item)
        return rval


    @staticmethod
    def max(obj, segments):
        path = '.'.join(segments)
        return max(x for x in getKeyPath(obj, path) if x is not _null)

    @staticmethod
    def min(obj, segments):
        path = '.'.join(segments)
        return min(x for x in getKeyPath(obj, path) if x is not _null)

    @staticmethod
    def sum(obj, segments):
        path = '.'.join(segments)
        lst = getKeyPath(obj, path)
        return msum(float(x) if x is not _null else 0.0 for x in lst)

    @staticmethod
    def unionOfArrays(obj, segments):
        path = '.'.join(segments)
        rval = []
        for lst in obj:
            rval.extend(getKeyPath(item, path) for item in lst)
        return rval


    @staticmethod
    def unionOfObjects(obj, segments):
        path = '.'.join(segments)
        return [ getKeyPath(item, path) for item in obj]


def getKey(obj, key):
    """
    Get the attribute referenced by 'key'. The key is used
    to build the name of an attribute, or attribute accessor method.

    The following attributes and accesors are tried (in this order):

    - Accessor 'getKey'
    - Accesoor 'get_key'
    - Accessor or attribute 'key'
    - Accessor or attribute 'isKey'
    - Attribute '_key'

    If none of these exist, raise KeyError
    """
    if obj is None:
        return None
    if isinstance(obj, (objc.objc_object, objc.objc_class)):
        return obj.valueForKey_(key)

    # check for dict-like objects
    getitem = getattr(obj, '__getitem__', None)
    if getitem is not None:
        try:
            return getitem(key)
        except (KeyError, IndexError, TypeError):
            pass

    # check for array-like objects
    if isinstance(obj, (collections_abc.Sequence, collections_abc.Set)) and not isinstance(obj, (basestring, collections_abc.Mapping)):
        def maybe_get(obj, key):
            try:
                return getKey(obj, key)
            except KeyError:
                return _null
        return [maybe_get(obj, key) for obj in iter(obj)]

    try:
        m = getattr(obj, "get" + keyCaps(key))
    except AttributeError:
        pass
    else:
        return m()

    try:
        m = getattr(obj, "get_" + key)
    except AttributeError:
        pass
    else:
        return m()

    for keyName in (key, "is" + keyCaps(key)):
        try:
            m = getattr(obj, keyName)
        except AttributeError:
            continue

        if isinstance(m, types.MethodType) and m.__self__ is obj:
            return m()

        elif isinstance(m, types.BuiltinMethodType):
            # Can't access the bound self of methods of builtin classes :-(
            return m()

        elif isinstance(m, objc.selector) and m.self is obj:
            return m()

        else:
            return m

    try:
        return getattr(obj, "_" + key)
    except AttributeError:
        raise KeyError("Key %s does not exist" % (key,))


def setKey(obj, key, value):
    """
    Set the attribute referenced by 'key' to 'value'. The key is used
    to build the name of an attribute, or attribute accessor method.

    The following attributes and accessors are tried (in this order):
    - Mapping access (that is __setitem__ for collection.Mapping instances)
    - Accessor 'setKey_'
    - Accessor 'setKey'
    - Accessor 'set_key'
    - Attribute '_key'
    - Attribute 'key'

    Raises KeyError if the key doesn't exist.
    """
    if obj is None:
        return
    if isinstance(obj, (objc.objc_object, objc.objc_class)):
        obj.setValue_forKey_(value, key)
        return

    if isinstance(obj, collections_abc.Mapping):
        obj[key] = value
        return

    aBase = 'set' + keyCaps(key)
    for accessor in (aBase + '_', aBase, 'set_' + key):
        m = getattr(obj, accessor, None)
        if m is None:
            continue
        try:
            m(value)
            return
        except TypeError:
            pass

    try:
        m = getattr(obj, key)
    except AttributeError:
        pass

    else:
        if isinstance(m, types.MethodType) and m.__self__ is obj:
            # This looks like a getter method, don't call setattr
            pass

        else:
            try:
                setattr(obj, key, value)
                return
            except AttributeError:
                raise KeyError("Key %s does not exist" % (key,))

    try:
        getattr(obj, "_" + key)
    except AttributeError:
        pass
    else:
        setattr(obj, "_" + key, value)
        return

    try:
        setattr(obj, key, value)
    except AttributeError:
        raise KeyError("Key %s does not exist" % (key,))

def getKeyPath(obj, keypath):
    """
    Get the value for the keypath. Keypath is a string containing a
    path of keys, path elements are seperated by dots.
    """
    if not keypath:
        raise KeyError

    if obj is None:
        return None


    if isinstance(obj, (objc.objc_object, objc.objc_class)):
        return obj.valueForKeyPath_(keypath)

    elements = keypath.split('.')
    cur = obj
    elemiter = iter(elements)
    for e in elemiter:
        if e[:1] == '@':
            try:
                oper = getattr(_ArrayOperators, e[1:])
            except AttributeError:
                raise KeyError("Array operator %s not implemented" % (e,))
            return oper(cur, elemiter)
        cur = getKey(cur, e)
    return cur

def setKeyPath(obj, keypath, value):
    """
    Set the value at 'keypath'. The keypath is a string containing a
    path of keys, seperated by dots.
    """
    if obj is None:
        return

    if isinstance(obj, (objc.objc_object, objc.objc_class)):
        return obj.setValue_forKeyPath_(value, keypath)

    elements = keypath.split('.')
    cur = obj
    for e in elements[:-1]:
        cur = getKey(cur, e)

    return setKey(cur, elements[-1], value)


class kvc(object):
    def __init__(self, obj):
        self.__pyobjc_object__ = obj

    def __getattr__(self, attr):
        return getKey(self.__pyobjc_object__, attr)

    def __repr__(self):
        return repr(self.__pyobjc_object__)

    def __setattr__(self, attr, value):
        if not attr.startswith('_'):
            setKey(self.__pyobjc_object__, attr, value)

        else:
            object.__setattr__(self, attr, value)

    def __getitem__(self, item):
        if not isinstance(item, basestring):
            raise TypeError('Keys must be strings')
        return getKeyPath(self.__pyobjc_object__, item)

    def __setitem__(self, item, value):
        if not isinstance(item, basestring):
            raise TypeError('Keys must be strings')
        setKeyPath(self.__pyobjc_object__, item, value)
