"""
Helper code for implementing unittests.

This module is unsupported and is primairily used in the PyObjC
testsuite.
"""
from __future__ import print_function
import plistlib as _pl
import unittest as _unittest
import objc
import os as _os
import gc as _gc
import subprocess as _subprocess
import sys as _sys
import struct as _struct
from distutils.sysconfig import get_config_var as _get_config_var
import re as _re
import warnings
import contextlib

# Ensure that methods in this module get filtered in the tracebacks
# from unittest
__unittest = False

# Have a way to disable the autorelease pool behaviour
_usepool = not _os.environ.get('PYOBJC_NO_AUTORELEASE')

# Python 2/3 Compatibility for the PyObjC Test Suite
try:
    unicode
except NameError:
    unicode = str

try:
    long
except NameError:
    long = int

try:
    basestring
except NameError:
    basestring = str

try:
    bytes
except NameError:
    bytes = str

try:
    unichr
except NameError:
    unichr = chr

def _typemap(tp): # XXX: Is this needed?
    if tp is None: return None
    return tp.replace(b'_NSRect', b'CGRect').replace(b'_NSPoint', b'CGPoint').replace(b'_NSSize', b'CGSize')

@contextlib.contextmanager
def pyobjc_options(**kwds):
    orig = {}
    try:
        for k in kwds:
            orig[k] = getattr(objc.options, k)
            setattr(objc.options, k, kwds[k])

        yield

    finally:
        for k in orig:
            setattr(objc.options, k, orig[k])


def sdkForPython(_cache=[]):
    """
    Return the SDK version used to compile Python itself,
    or None if no framework was used
    """
    if not _cache:

        cflags = _get_config_var('CFLAGS')
        m = _re.search('-isysroot\s+([^ ]*)(\s|$)', cflags)
        if m is None:
            _cache.append(None)
            return None


        path = m.group(1)
        if path == '/':
            result = tuple(map(int, os_release().split('.')))
            _cache.append(result)
            return result

        bn = _os.path.basename(path)
        version = bn[6:-4]
        if version.endswith('u'):
            version = version[:-1]


        result =  tuple(map(int, version.split('.')))
        _cache.append(result)
        return result

    return _cache[0]

def fourcc(v):
    """
    Decode four-character-code integer definition

    (e.g. 'abcd')
    """
    return _struct.unpack('>i', v)[0]

def cast_int(value):
    """
    Cast value to 32bit integer

    Usage:
        cast_int(1 << 31) == -1

    (where as: 1 << 31 == 2147483648)
    """
    value = value & 0xffffffff
    if value & 0x80000000:
        value =   ~value + 1 & 0xffffffff
        return -value
    else:
        return value

def cast_longlong(value):
    """
    Cast value to 64bit integer

    Usage:
        cast_longlong(1 << 63) == -1
    """
    value = value & 0xffffffffffffffff
    if value & 0x8000000000000000:
        value =   ~value + 1 & 0xffffffffffffffff
        return -value
    else:
        return value

def cast_uint(value):
    """
    Cast value to 32bit integer

    Usage:
        cast_int(1 << 31) == 2147483648

    """
    value = value & 0xffffffff
    return value

def cast_ulonglong(value):
    """
    Cast value to 64bit integer
    """
    value = value & 0xffffffffffffffff
    return value

_os_release = None
def os_release():
    """
    Returns the release of macOS (for example 10.5.1).
    """
    global _os_release
    if _os_release is not None:
        return _os_release

    if hasattr(_pl, 'load'):
        with open('/System/Library/CoreServices/SystemVersion.plist', 'rb') as fp:
            pl = _pl.load(fp)
    else:
        pl = _pl.readPlist('/System/Library/CoreServices/SystemVersion.plist')
    v = pl['ProductVersion']
    return '.'.join(v.split('.'))


def is32Bit():
    """
    Return True if we're running in 32-bit mode
    """
    if _sys.maxsize > 2 ** 32:
        return False
    return True

def onlyIf(expr, message=None):
    """
    Usage::

        class Tests (unittest.TestCase):

            @onlyIf(1 == 2)
            def testUnlikely(self):
                pass

    The test only runs when the argument expression is true
    """
    def callback(function):
        if not expr:
            if hasattr(_unittest, 'skip'):
                return _unittest.skip(message)(function)
            return lambda self: None  # pragma: no cover (py2.6)
        else:
            return function
    return callback

def onlyPython2(function):
    """
    Usage:
        class Tests (unittest.TestCase):

            @onlyPython2
            def testPython2(self):
                pass

    The test is only executed for Python 2.x
    """
    return onlyIf(_sys.version_info[0] == 2, "python2.x only")(function)

def onlyPython3(function):
    """
    Usage:
        class Tests (unittest.TestCase):

            @onlyPython3
            def testPython3(self):
                pass

    The test is only executed for Python 3.x
    """
    return onlyIf(_sys.version_info[0] == 3, "python3.x only")(function)

def onlyOn32Bit(function):
    """
    Usage::

        class Tests (unittest.TestCase):

            @onlyOn32Bit
            def test32BitOnly(self):
                pass

    The test runs only on 32-bit systems
    """
    return onlyIf(is32Bit(), "32-bit only")(function)

def onlyOn64Bit(function):
    """
    Usage::

        class Tests (unittest.TestCase):

            @onlyOn64Bit
            def test64BitOnly(self):
                pass

    The test runs only on 64-bit systems
    """
    return onlyIf(not is32Bit(), "64-bit only")(function)

def min_python_release(version):
    """
    Usage::

        class Tests (unittest.TestCase):

            @min_python_release('3.2')
            def test_python_3_2(self):
                pass
    """
    parts = tuple(map(int, version.split('.')))
    return onlyIf(_sys.version_info[:2] >= parts, "Requires Python %s or later"%(version,))

def _sort_key(version):
    parts = version.split('.')
    if len(parts) == 2:
      parts.append('0')

    if len(parts) != 3:
       raise ValueError("Invalid version: %r"%(version,))

    return tuple(int(x) for x in parts)


def os_level_key(release):
    """
    Return an object that can be used to compare two releases.
    """
    return _sort_key(release)


def min_sdk_level(release):
    """
    Usage::

        class Tests (unittest.TestCase):
            @min_sdk_level('10.6')
            def testSnowLeopardSDK(self):
                pass
    """
    v = (objc.PyObjC_BUILD_RELEASE // 100, objc.PyObjC_BUILD_RELEASE % 100, 0)
    return onlyIf(v >= os_level_key(release), "Requires build with SDK %s or later"%(release,))

def max_sdk_level(release):
    """
    Usage::

        class Tests (unittest.TestCase):
            @max_sdk_level('10.5')
            def testUntilLeopardSDK(self):
                pass
    """
    v = (objc.PyObjC_BUILD_RELEASE // 100, objc.PyObjC_BUILD_RELEASE % 100, 0)
    return onlyIf(v <= os_level_key(release), "Requires build with SDK %s or later"%(release,))

def min_os_level(release):
    """
    Usage::

        class Tests (unittest.TestCase):

            @min_os_level('10.6')
            def testSnowLeopardCode(self):
                pass
    """
    return onlyIf(os_level_key(os_release()) >= os_level_key(release), "Requires OSX %s or later"%(release,))

def max_os_level(release):
    """
    Usage::

        class Tests (unittest.TestCase):

            @max_os_level('10.5')
            def testUntilLeopard(self):
                pass
    """
    return onlyIf(os_level_key(os_release()) <= os_level_key(release), "Requires OSX upto %s"%(release,))

def os_level_between(min_release, max_release):
    """
    Usage::

        class Tests (unittest.TestCase):

            @os_level_between('10.5', '10.8')
            def testUntilLeopard(self):
                pass
    """
    return onlyIf(os_level_key(min_release) <= os_level_key(os_release()) <= os_level_key(max_release), "Requires OSX %s upto %s"%(min_release, max_release))

_poolclass = objc.lookUpClass('NSAutoreleasePool')

# NOTE: On at least OSX 10.8 there are multiple proxy classes for CFTypeRef...
_nscftype = tuple(cls for cls in objc.getClassList() if 'NSCFType' in cls.__name__)

_typealias = {}

if not is32Bit():
    _typealias[objc._C_LNG_LNG] = objc._C_LNG
    _typealias[objc._C_ULNG_LNG] = objc._C_ULNG

else: # pragma: no cover (32-bit)
    _typealias[objc._C_LNG] = objc._C_INT
    _typealias[objc._C_ULNG] = objc._C_UINT

class TestCase (_unittest.TestCase):
    """
    A version of TestCase that wraps every test into its own
    autorelease pool.

    This also adds a number of useful assertion methods
    """


    def assertIsCFType(self, tp, message = None):
        if not isinstance(tp, objc.objc_class):
            self.fail(message or "%r is not a CFTypeRef type"%(tp,))

        if any(x is tp for x in _nscftype):
            self.fail(message or "%r is not a unique CFTypeRef type"%(tp,))

        for cls in tp.__bases__:
            if 'NSCFType' in cls.__name__:
                return

        self.fail(message or "%r is not a CFTypeRef type"%(tp,))

        # NOTE: Don't test if this is a subclass of one of the known
        #       CF roots, this tests is mostly used to ensure that the
        #       type is distinct from one of those roots.
        #  XXX: With the next two lines enabled there are spurious test
        #       failures when a CF type is toll-free bridged to an
        #       (undocumented) Cocoa class. It might be worthwhile to
        #       look for these, but not in the test suite.
        #if not issubclass(tp, _nscftype):
        #    self.fail(message or "%r is not a CFTypeRef subclass"%(tp,))


    def assertIsOpaquePointer(self, tp, message = None):
        if not hasattr(tp, "__pointer__"):
            self.fail(message or "%r is not an opaque-pointer"%(tp,))

        if not hasattr(tp, "__typestr__"):
            self.fail(message or "%r is not an opaque-pointer"%(tp,))


    def assertResultIsNullTerminated(self, method, message = None):
        info = method.__metadata__()
        if not info.get('retval', {}).get('c_array_delimited_by_null'):
            self.fail(message or "result of %r is not a null-terminated array"%(method,))

    def assertIsNullTerminated(self, method, message = None):
        info = method.__metadata__()
        if not info.get('c_array_delimited_by_null') or not info.get('variadic'):
            self.fail(message or "%s is not a variadic function with a null-terminated list of arguments"%(method,))

    def assertArgIsNullTerminated(self, method, argno, message = None):
        if isinstance(method, objc.selector):
            offset = 2
        else:
            offset = 0
        info = method.__metadata__()
        try:
            if not info['arguments'][argno+offset].get('c_array_delimited_by_null'):
                self.fail(message or "argument %d of %r is not a null-terminated array"%(argno, method))
        except (KeyError, IndexError):
            self.fail(message or "argument %d of %r is not a null-terminated array"%(argno, method))

    def assertArgIsVariableSize(self, method, argno, message = None):
        if isinstance(method, objc.selector):
            offset = 2
        else:
            offset = 0
        info = method.__metadata__()
        try:
            if not info['arguments'][argno+offset].get('c_array_of_variable_length'):
                self.fail(message or "argument %d of %r is not a variable sized array"%(argno, method,))
        except (KeyError, IndexError):
            self.fail(message or "argument %d of %r is not a variable sized array"%(argno, method,))

    def assertResultIsVariableSize(self, method, message = None):
        info = method.__metadata__()
        if not info.get('retval', {}).get('c_array_of_variable_length', False):
            self.fail(message or "result of %r is not a variable sized array"%(method,))

    def assertArgSizeInResult(self, method, argno, message = None):
        if isinstance(method, objc.selector):
            offset = 2
        else:
            offset = 0
        info = method.__metadata__()
        try:
            if not info['arguments'][argno+offset].get('c_array_length_in_result'):
                self.fail(message or "argument %d of %r does not have size in result"%(argno, method))
        except (KeyError, IndexError):
            self.fail(message or "argument %d of %r does not have size in result"%(argno, method))

    def assertArgIsPrintf(self, method, argno, message = None):
        if isinstance(method, objc.selector):
            offset = 2
        else:
            offset = 0
        info = method.__metadata__()
        if not info.get('variadic'):
            self.fail(message or "%r is not a variadic function"%(method,))

        try:
            if not info['arguments'][argno+offset].get('printf_format'):
                self.fail(message or "%r argument %d is not a printf format string"%(method, argno))
        except (KeyError, IndexError):
            self.fail(message or "%r argument %d is not a printf format string"%(method, argno))

    def assertArgIsCFRetained(self, method, argno, message = None):
        if isinstance(method, objc.selector):
            offset = 2
        else:
            offset = 0
        info = method.__metadata__()

        try:
            if not info['arguments'][argno+offset]['already_cfretained']:
                self.fail(message or "%r is not cfretained"%(method,))
        except (KeyError, IndexError):
            self.fail(message or "%r is not cfretained"%(method,))

    def assertArgIsNotCFRetained(self, method, argno, message = None):
        if isinstance(method, objc.selector):
            offset = 2
        else:
            offset = 0
        info = method.__metadata__()
        try:
            if info['arguments'][argno+offset]['already_cfretained']:
                self.fail(message or "%r is cfretained"%(method,))
        except (KeyError, IndexError):
            pass

    def assertResultIsCFRetained(self, method, message = None):
        info = method.__metadata__()

        if not info.get('retval', {}).get('already_cfretained', False):
            self.fail(message or "%r is not cfretained"%(method,))

    def assertResultIsNotCFRetained(self, method, message = None):
        info = method.__metadata__()
        if info.get('retval', {}).get('already_cfretained', False):
            self.fail(message or "%r is cfretained"%(method,))

    def assertArgIsRetained(self, method, argno, message = None):
        if isinstance(method, objc.selector):
            offset = 2
        else:
            offset = 0
        info = method.__metadata__()

        try:
            if not info['arguments'][argno+offset]['already_retained']:
                self.fail(message or "%r is not retained"%(method,))
        except (KeyError, IndexError):
            self.fail(message or "%r is not retained"%(method,))

    def assertArgIsNotRetained(self, method, argno, message = None):
        if isinstance(method, objc.selector):
            offset = 2
        else:
            offset = 0
        info = method.__metadata__()
        try:
            if info['arguments'][argno+offset]['already_retained']:
                self.fail(message or "%r is retained"%(method,))
        except (KeyError, IndexError):
            pass

    def assertResultIsRetained(self, method, message = None):
        info = method.__metadata__()
        if not info.get('retval', {}).get('already_retained', False):
            self.fail(message or "%r is not retained"%(method,))

    def assertResultIsNotRetained(self, method, message = None):
        info = method.__metadata__()
        if info.get('retval', {}).get('already_retained', False):
            self.fail(message or "%r is retained"%(method,))

    def assertResultHasType(self, method, tp, message=None):
        info = method.__metadata__()
        type = info.get('retval').get('type', b'v')
        if type != tp and _typemap(type) != _typemap(tp) \
                and _typealias.get(type, type) != _typealias.get(tp, tp):
            self.fail(message or "result of %r is not of type %r, but %r"%(
                method, tp, type))

    def assertArgHasType(self, method, argno, tp, message=None):
        if isinstance(method, objc.selector):
            offset = 2
        else:
            offset = 0
        info = method.__metadata__()
        try:
            i = info['arguments'][argno+offset]

        except (KeyError, IndexError):
            self.fail(message or "arg %d of %s has no metadata (or doesn't exist)"%(argno, method))

        else:
            type = i.get('type', b'@')

        if type != tp and _typemap(type) != _typemap(tp) \
                and _typealias.get(type, type) != _typealias.get(tp, tp):
            self.fail(message or "arg %d of %s is not of type %r, but %r"%(
                argno, method, tp, type))


    def assertArgIsFunction(self, method, argno, sel_type, retained, message=None):
        if isinstance(method, objc.selector):
            offset = 2
        else:
            offset = 0
        info = method.__metadata__()

        try:
            i = info['arguments'][argno+offset]
        except (KeyError, IndexError):
            self.fail(message or "arg %d of %s has no metadata (or doesn't exist)"%(argno, method))

        else:
            type = i.get('type', b'@')

        if type != b'^?':
            self.fail(message or "arg %d of %s is not of type function_pointer"%(
                argno, method))

        st = i.get('callable')
        if st is None:
            self.fail(message or "arg %d of %s is not of type function_pointer"%(
                argno, method))

        try:
            iface = st['retval']['type']
            for a in st['arguments']:
                iface += a['type']
        except KeyError:
            self.fail(message or "arg %d of %s is a function pointer with incomplete type information"%(argno, method))

        if iface != sel_type:
            self.fail(message or "arg %d of %s is not a function_pointer with type %r, but %r"%(argno, method, sel_type, iface))


        st = info['arguments'][argno+offset].get('callable_retained', False)
        if bool(st) != bool(retained):
            self.fail(message or "arg %d of %s; retained: %r, expected: %r"%(
                argno, method, st, retained))

    def assertResultIsFunction(self, method, sel_type, message=None):
        info = method.__metadata__()

        try:
            i = info['retval']
        except (KeyError, IndexError):
            self.fail(message or "result of %s has no metadata (or doesn't exist)"%(method,))

        else:
            type = i.get('type', b'@')

        if type != b'^?':
            self.fail(message or "result of %s is not of type function_pointer"%(
                method, ))

        st = i.get('callable')
        if st is None:
            self.fail(message or "result of %s is not of type function_pointer"%(
                method, ))

        try:
            iface = st['retval']['type']
            for a in st['arguments']:
                iface += a['type']
        except KeyError:
            self.fail(message or "result of %s is a function pointer with incomplete type information"%(method,))

        if iface != sel_type:
            self.fail(message or "result of %s is not a function_pointer with type %r, but %r"%(method, sel_type, iface))


    def assertArgIsBlock(self, method, argno, sel_type, message=None):
        if isinstance(method, objc.selector):
            offset = 2
        else:
            offset = 0
        info = method.__metadata__()
        try:
            type = info['arguments'][argno+offset]['type']
        except (IndexError, KeyError):
            self.fail("arg %d of %s does not exist"%(argno, method))

        if type != b'@?':
            self.fail(message or "arg %d of %s is not of type block: %s"%(
                argno, method, type))

        st = info['arguments'][argno+offset].get('callable')
        if st is None:
            self.fail(message or "arg %d of %s is not of type block: no callable"%(
                argno, method))

        try:
            iface = st['retval']['type']
            if st['arguments'][0]['type'] != b'^v':
                self.fail(message or "arg %d of %s has an invalid block signature %r"%(argno, method, st['arguments'][0]['type']))
            for a in st['arguments'][1:]:
                iface += a['type']
        except KeyError:
            self.fail(message or "result of %s is a block pointer with incomplete type information"%(method,))

        if iface != sel_type:
            self.fail(message or "arg %d of %s is not a block with type %r, but %r"%(argno, method, sel_type, iface))

    def assertResultIsBlock(self, method, sel_type, message=None):
        info = method.__metadata__()

        try:
            type = info['retval']['type']
            if type != b'@?':
                self.fail(message or "result of %s is not of type block: %s"%(
                    method, type))
        except KeyError:
            self.fail(message or "result of %s is not of type block: %s"%(
                method, b'v'))

        st = info['retval'].get('callable')
        if st is None:
            self.fail(message or "result of %s is not of type block: no callable specified"%(
                method))

        try:
            iface = st['retval']['type']
            if st['arguments'][0]['type'] != b'^v':
                self.fail(message or "result %s has an invalid block signature %r"%(method, st['arguments'][0]['type']))
            for a in st['arguments'][1:]:
                iface += a['type']
        except KeyError:
            self.fail(message or "result of %s is a block pointer with incomplete type information"%(method,))

        if iface != sel_type:
            self.fail(message or "result of %s is not a block with type %r, but %r"%(method, sel_type, iface))

    def assertArgIsSEL(self, method, argno, sel_type, message=None):
        if isinstance(method, objc.selector):
            offset = 2
        else:
            offset = 0
        info = method.__metadata__()
        try:
            i = info['arguments'][argno+offset]
        except (KeyError, IndexError):
            self.fail(message or "arg %d of %s has no metadata (or doesn't exist)"%(argno, method))

        type = i.get('type', b'@')
        if type != objc._C_SEL:
            self.fail(message or "arg %d of %s is not of type SEL"%(
                argno, method))

        st = i.get('sel_of_type')
        if st != sel_type and _typemap(st) != _typemap(sel_type):
            self.fail(message or "arg %d of %s doesn't have sel_type %r but %r"%(
                argno, method, sel_type, st))

    def assertResultIsBOOL(self, method, message=None):
        info = method.__metadata__()
        type = info['retval']['type']
        if type != objc._C_NSBOOL:
            self.fail(message or "result of %s is not of type BOOL, but %r"%(
                method, type))

    def assertArgIsBOOL(self, method, argno, message=None):
        if isinstance(method, objc.selector):
            offset = 2
        else:
            offset = 0
        info = method.__metadata__()
        type = info['arguments'][argno+offset]['type']
        if type != objc._C_NSBOOL:
            self.fail(message or "arg %d of %s is not of type BOOL, but %r"%(
                argno, method, type))

    def assertArgIsFixedSize(self, method, argno, count, message=None):
        if isinstance(method, objc.selector):
            offset = 2
        else:
            offset = 0
        info = method.__metadata__()
        try:
            cnt = info['arguments'][argno+offset]['c_array_of_fixed_length']
            if cnt != count:
                self.fail(message or "arg %d of %s is not a C-array of length %d"%(
                    argno, method, count))
        except (KeyError, IndexError):
            self.fail(message or "arg %d of %s is not a C-array of length %d"%(
                argno, method, count))

    def assertResultIsFixedSize(self, method, count, message=None):
        info = method.__metadata__()
        try:
            cnt = info['retval']['c_array_of_fixed_length']
            if cnt != count:
                self.fail(message or "result of %s is not a C-array of length %d"%(
                    method, count))
        except (KeyError, IndexError):
            self.fail(message or "result of %s is not a C-array of length %d"%(
                method, count))

    def assertArgSizeInArg(self, method, argno, count, message=None):
        if isinstance(method, objc.selector):
            offset = 2
        else:
            offset = 0
        info = method.__metadata__()
        try:
            cnt = info['arguments'][argno+offset]['c_array_length_in_arg']
        except (KeyError, IndexError):
            self.fail(message or "arg %d of %s is not a C-array of with length in arg %s"%(
                argno, method, count))

        if isinstance(count, (list, tuple)):
            count2 = tuple(x + offset for x in count)
        else:
            count2 = count + offset
        if cnt != count2:
            self.fail(message or "arg %d of %s is not a C-array of with length in arg %s"%(
                argno, method, count))

    def assertResultSizeInArg(self, method, count, message=None):
        if isinstance(method, objc.selector):
            offset = 2
        else:
            offset = 0
        info = method.__metadata__()
        cnt = info['retval']['c_array_length_in_arg']
        if cnt != count + offset:
            self.fail(message or "result %s is not a C-array of with length in arg %d"%(
                method, count))


    def assertArgIsOut(self, method, argno, message=None):
        if isinstance(method, objc.selector):
            offset = 2
        else:
            offset = 0
        info = method.__metadata__()
        type = info['arguments'][argno+offset]['type']
        if not type.startswith(b'o^') and not type.startswith(b'o*'):
            self.fail(message or "arg %d of %s is not an 'out' argument"%(
                argno, method))

    def assertArgIsInOut(self, method, argno, message=None):
        if isinstance(method, objc.selector):
            offset = 2
        else:
            offset = 0
        info = method.__metadata__()
        type = info['arguments'][argno+offset]['type']
        if not type.startswith(b'N^') and not type.startswith(b'N*'):
            self.fail(message or "arg %d of %s is not an 'inout' argument"%(
                argno, method))

    def assertArgIsIn(self, method, argno, message=None):
        if isinstance(method, objc.selector):
            offset = 2
        else:
            offset = 0
        info = method.__metadata__()
        type = info['arguments'][argno+offset]['type']
        if not type.startswith(b'n^') and not type.startswith(b'n*'):
            self.fail(message or "arg %d of %s is not an 'in' argument"%(
                argno, method))


    #
    # Addition assert methods, all of them should only be necessary for
    # python 2.7 or later
    #

    if not hasattr(_unittest.TestCase, 'assertItemsEqual'): # pragma: no cover
        def assertItemsEqual(self, seq1, seq2, message=None):
            # This is based on unittest.util._count_diff_all_purpose from
            # Python 2.7
            s, t = list(seq1), list(seq2)
            m, n = len(s), len(t)
            NULL = object()
            result = []
            for i, elem in enumerate(s):
                if elem is NULL:
                    continue

                cnt_s = cnt_t = 0
                for j in range(i, m):
                    if s[j] == elem:
                        cnt_s += 1
                        s[j] = NULL

                for j, other_elem in enumerate(t):
                    if other_elem == elem:
                        cnt_t += 1
                        t[j] = NULL

                if cnt_s != cnt_t:
                    result.append((cnt_s, cnt_t, elem))
            for i, elem in enumerate(t):
                if elem is NULL:
                    continue
                cnt_t = 0
                for j in range(i, n):
                    if t[j] == elem:
                        cnt_t += 1
                        t[j] = NULL

                result.append((0, cnt_t, elem))

            if result:
                for actual, expected, value in result:
                    print("Seq1 %d, Seq2: %d  value: %r"%(actual, expected, value))

                self.fail(message or ("sequences do not contain the same items:"  +
                    "\n".join(["Seq1 %d, Seq2: %d  value: %r"%(item) for item in result])))



    if not hasattr(_unittest.TestCase, 'assertStartswith'):
        def assertStartswith(self, value, test, message = None): # pragma: no cover
            if not value.startswith(test):
                self.fail(message or "%r does not start with %r"%(value, test))

    if not hasattr(_unittest.TestCase, 'assertIs'): # pragma: no cover
        def assertIs(self, value, test, message = None):
            if value is not test:
                self.fail(message or  "%r (id=%r) is not %r (id=%r) "%(value, id(value), test, id(test)))

    if not hasattr(_unittest.TestCase, 'assertIsNot'): # pragma: no cover
        def assertIsNot(self, value, test, message = None):
            if value is test:
                self.fail(message or  "%r is %r"%(value, test))

    if not hasattr(_unittest.TestCase, 'assertIsNone'): # pragma: no cover
        def assertIsNone(self, value, message = None):
            self.assertIs(value, None)

    if not hasattr(_unittest.TestCase, 'assertIsNotNone'): # pragma: no cover
        def assertIsNotNone(self, value, message = None):
            if value is None:
                sel.fail(message, "%r is not %r"%(value, test))

    if not hasattr(_unittest.TestCase, 'assertStartsWith'): # pragma: no cover
        def assertStartswith(self, value, check, message=None):
            if not value.startswith(check):
                self.fail(message or "not %r.startswith(%r)"%(value, check))

    if not hasattr(_unittest.TestCase, 'assertHasAttr'): # pragma: no cover
        def assertHasAttr(self, value, key, message=None):
            if not hasattr(value, key):
                self.fail(message or "%s is not an attribute of %r"%(key, value))

    if not hasattr(_unittest.TestCase, 'assertNotHasAttr'): # pragma: no cover
        def assertNotHasAttr(self, value, key, message=None):
            if hasattr(value, key):
                self.fail(message or "%s is an attribute of %r"%(key, value))

    def assertIsSubclass(self, value, types, message=None):
        if not issubclass(value, types):
            self.fail(message or "%s is not a subclass of %r"%(value, types))

    def assertIsNotSubclass(self, value, types, message=None):
        if issubclass(value, types):
            self.fail(message or "%s is a subclass of %r"%(value, types))

    if not hasattr(_unittest.TestCase, 'assertIsInstance'): # pragma: no cover
        def assertIsInstance(self, value, types, message=None):
            if not isinstance(value, types):
                self.fail(message or "%s is not an instance of %r but %s"%(value, types, type(value)))

    if not hasattr(_unittest.TestCase, 'assertIsNotInstance'): # pragma: no cover
        def assertIsNotInstance(self, value, types, message=None):
            if isinstance(value, types):
                self.fail(message or "%s is an instance of %r"%(value, types))

    if not hasattr(_unittest.TestCase, 'assertIn'): # pragma: no cover
        def assertIn(self, value, seq, message=None):
            if value not in seq:
                self.fail(message or "%r is not in %r"%(value, seq))

    if not hasattr(_unittest.TestCase, 'assertNotIn'): # pragma: no cover
        def assertNotIn(self, value, seq, message=None):
            if value in seq:
                self.fail(message or "%r is in %r"%(value, seq))


    if not hasattr(_unittest.TestCase, 'assertGreaterThan'): # pragma: no cover
        def assertGreaterThan(self, val, test, message=None):
            if not (val > test):
                self.fail(message or '%r <= %r'%(val, test))

    if not hasattr(_unittest.TestCase, 'assertGreaterEqual'): # pragma: no cover
        def assertGreaterEqual(self, val, test, message=None):
            if not (val >= test):
                self.fail(message or '%r < %r'%(val, test))

    if not hasattr(_unittest.TestCase, 'assertLessThan'): # pragma: no cover
        def assertLessThan(self, val, test, message=None):
            if not (val < test):
                self.fail(message or '%r >= %r'%(val, test))

    if not hasattr(_unittest.TestCase, 'assertLessEqual'): # pragma: no cover
        def assertLessEqual(self, val, test, message=None):
            if not (val <= test):
                self.fail(message or '%r > %r'%(val, test))

    if not hasattr(_unittest.TestCase, "assertAlmostEquals"): # pragma: no cover
        def assertAlmostEquals(self, val1, val2, message=None):
            self.failUnless(abs (val1 - val2) < 0.00001,
                    message or 'abs(%r - %r) >= 0.00001'%(val1, val2))


    def run(self, *args):
        """
        Run the test, same as unittest.TestCase.run, but every test is
        run with a fresh autorelease pool.
        """
        if _usepool:
            p = _poolclass.alloc().init()
        else:
            p = 1

        try:
            _unittest.TestCase.run(self, *args)
        finally:
            _gc.collect()
            del p
            _gc.collect()


main = _unittest.main

if hasattr(_unittest, 'expectedFailure'):
    expectedFailure = _unittest.expectedFailure

else: # pragma: no cover (py2.6)

    def expectedFailure(func):
        def test(self):
            try:
                func(self)

            except AssertionError:
                return

            self.fail("test unexpectedly passed")
        test.__name__ == func.__name__

        return test

def expectedFailureIf(condition):
    if condition:
        return expectedFailure
    else:
        return lambda func: func
