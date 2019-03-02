'''
Python mapping for the CoreWLAN framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''

import objc
import sys
import Foundation

from CoreWLAN import _metadata, _CoreWLAN

def _CW8021XProfile__eq__(self, other):
    if not isinstance(other, type(self)):
        return False

    return self.isEqualToProfile_(other)

def _CW8021XProfile__ne__(self, other):
    if not isinstance(other, type(self)):
        return True

    return not self.isEqualToProfile_(other)

objc.addConvenienceForClass('CW8021XProfile', (
    ('__eq__', _CW8021XProfile__eq__),
    ('__ne__', _CW8021XProfile__ne__),
))


def _CWChannel__eq__(self, other):
    if not isinstance(other, type(self)):
        return False

    return self.isEqualToChannel_(other)

def _CWChannel__ne__(self, other):
    if not isinstance(other, type(self)):
        return True

    return not self.isEqualToChannel_(other)

objc.addConvenienceForClass('CWChannel', (
    ('__eq__', _CWChannel__eq__),
    ('__ne__', _CWChannel__ne__),
))

def _CWConfiguration__eq__(self, other):
    if not isinstance(other, type(self)):
        return False

    return self.isEqualToConfiguration_(other)

def _CWConfiguration__ne__(self, other):
    if not isinstance(other, type(self)):
        return True

    return not self.isEqualToConfiguration_(other)

objc.addConvenienceForClass('CWConfiguration', (
    ('__eq__', _CWConfiguration__eq__),
    ('__ne__', _CWConfiguration__ne__),
))

def _CWNetwork__eq__(self, other):
    if not isinstance(other, type(self)):
        return False

    return self.isEqualToNetwork_(other)

def _CWNetwork__ne__(self, other):
    if not isinstance(other, type(self)):
        return True

    return not self.isEqualToNetwork_(other)

objc.addConvenienceForClass('CWNetwork', (
    ('__eq__', _CWNetwork__eq__),
    ('__ne__', _CWNetwork__ne__),
))

def _CWNetworkProfile__eq__(self, other):
    if not isinstance(other, type(self)):
        return False

    return self.isEqualToNetworkProfile_(other)

def _CWNetworkProfile__ne__(self, other):
    if not isinstance(other, type(self)):
        return True

    return not self.isEqualToNetworkProfile_(other)

objc.addConvenienceForClass('CWNetworkProfile', (
    ('__eq__', _CWNetworkProfile__eq__),
    ('__ne__', _CWNetworkProfile__ne__),
))


sys.modules['CoreWLAN'] = mod = objc.ObjCLazyModule(
            "CoreWLAN",
            "com.apple.framework.CoreWLAN",
            objc.pathForFramework("/System/Library/Frameworks/CoreWLAN.framework"),
            _metadata.__dict__, None, {
                '__doc__': __doc__,
                'objc': objc,
                '__path__': __path__,
                '__loader__': globals().get('__loader__', None),
            }, (Foundation,))

import sys
del sys.modules['CoreWLAN._metadata']
del sys.modules['CoreWLAN._CoreWLAN']
