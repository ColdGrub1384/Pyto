"""
Specific support for NSData.

NSData needs to be handles specially for correctness reasons,
and is therefore in the core instead of the Foundation
framework wrappers.
"""
from objc._objc import registerMetaDataForSelector
from objc._convenience import addConvenienceForClass
import sys

registerMetaDataForSelector(
    b'NSData', b'dataWithBytes:length:',
    {
        'arguments': {
            2: { 'type': b'^v', 'type_modifier': b'n', 'c_array_length_in_arg': 3 }
        }
    })


def nsdata__new__(cls, value=None):
    if value is None:
        return cls.data()

    else:
        return cls.dataWithBytes_length_(value, len(value))

if sys.version_info[0] == 2:  # pragma: no 3.x cover
    def nsdata__str__(self):
        if len(self) == 0:
            return str(b"")
        return str(self.bytes().tobytes())

else:  # pragma: no 2.x cover
    def nsdata__str__(self):
        if len(self) == 0:
            return str(b"")
        return str(self.bytes().tobytes())

    def nsdata__bytes__(self):
        return bytes(self.bytes())

# XXX: These NSData helpers should use Cocoa method calls,
#      instead of creating a memoryview/buffer object.
def nsdata__getitem__(self, item):
    buff = self.bytes()
    try:
        return buff[item]
    except TypeError:
        return buff[:][item]

def nsmutabledata__setitem__(self, item, value):
    self.mutableBytes()[item] = value

addConvenienceForClass('NSData', (
    ('__new__', staticmethod(nsdata__new__)),
    ('__len__', lambda self: self.length()),
    ('__str__', nsdata__str__),
    ('__getitem__', nsdata__getitem__),
))
addConvenienceForClass('NSMutableData', (
    ('__setitem__', nsmutabledata__setitem__),
))

if sys.version_info[0] == 2:
    def nsdata__getslice__(self, i, j):
        return self.bytes()[i:j]

    def nsmutabledata__setslice__(self, i, j, sequence):
        # XXX - could use replaceBytes:inRange:, etc.
        self.mutableBytes()[i:j] = sequence

    addConvenienceForClass('NSData', (
        ('__getslice__', nsdata__getslice__),
    ))
    addConvenienceForClass('NSMutableData', (
        ('__setslice__', nsmutabledata__setslice__),
    ))



if sys.version_info[0] == 3:  # pragma: no 2.x cover; pragma: no branch
    addConvenienceForClass('NSData', (
        ('__bytes__', nsdata__bytes__),
    ))
