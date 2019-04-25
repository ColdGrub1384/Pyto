'''
Python mapping for the QuartzCore framework.

This module does not contain docstrings for the wrapped code, check Apple's
documentation for details on how to use these functions and classes.
'''
import sys
import objc
import Foundation

from Quartz.QuartzCore import _metadata
import Quartz.QuartzCore._quartzcore

# XXX: addConvenienceFor... should be metadata
def CIVector__getitem__(self, idx):
    if isinstance(idx, slice):
        start, stop, step = idx.indices(self.count())
        return [self[i] for i in range(start, stop, step)]

    if idx < 0:
        new = self.count() + idx
        if new < 0:
            raise IndexError(idx)
        idx = new

    return self.valueAtIndex_(idx)

objc.addConvenienceForClass('CIVector', (
    ('__len__',     lambda self: self.count()),
    ('__getitem__', CIVector__getitem__),
))


objc.addConvenienceForClass('CIContext', (
    ('__getitem__',     lambda self, key: self.objectForKey_(key)),
    ('__setitem__',     lambda self, key, value: self.setObject_forKey_(value, key)),
))
objc.addConvenienceForClass('CIContextImpl', (
    ('__getitem__',     lambda self, key: self.objectForKey_(key)),
    ('__setitem__',     lambda self, key, value: self.setObject_forKey_(value, key)),
))

objc.addConvenienceForBasicSequence('QCStructure', True)


sys.modules['Quartz.QuartzCore'] = mod = objc.ObjCLazyModule('Quartz.QuartzCore',
    "com.apple.QuartzCore",
    objc.pathForFramework("/System/Library/Frameworks/QuartzCore.framework"),
    _metadata.__dict__, None, {
       '__doc__': __doc__,
       '__path__': __path__,
       '__loader__': globals().get('__loader__', None),
       'objc': objc,
    }, (Foundation,))

import sys
del sys.modules['Quartz.QuartzCore._metadata']
