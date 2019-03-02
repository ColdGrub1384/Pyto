"""
Convenience interface for NSString
"""
from objc._convenience import addConvenienceForClass

__all__ = ()

_no_value = object()

def nsstring_new(cls, value=_no_value):
    if value is _no_value:
        return cls.alloc().init()
    else:
        return cls.alloc().initWithString_(value)

addConvenienceForClass('NSString', (
    ('__len__',     lambda self: self.length() ),
    ('endswith',    lambda self, pfx: self.hasSuffix_(pfx)),
    ('startswith',  lambda self, pfx: self.hasPrefix_(pfx)),
    ('__new__',     staticmethod(nsstring_new)),
))
