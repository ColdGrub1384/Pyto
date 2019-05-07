from objc._objc import *
from objc import _objc
import struct
import sys
import datetime

if sys.version_info[0] == 2:
    import collections as collections_abc
else:
    import collections.abc as collections_abc

__all__ = [ 'registerListType', 'registerMappingType', 'registerSetType', 'registerDateType' ]

def registerListType(type):
    """
    Register 'type' as a list-like type that will be proxied
    as an NSMutableArray subclass.
    """
    if options._sequence_types is None:
        options._sequence_types = ()

    options._sequence_types += (type,)

def registerMappingType(type):
    """
    Register 'type' as a dictionary-like type that will be proxied
    as an NSMutableDictionary subclass.
    """
    if options._mapping_types is None:
        options._mapping_types = ()

    options._mapping_types += (type,)

def registerSetType(type):
    """
    Register 'type' as a set-like type that will be proxied
    as an NSMutableSet subclass.
    """
    if options._set_types is None:
        options._set_types = ()

    options._set_types += (type,)

def registerDateType(type):
    """
    Register 'type' as a date-like type that will be proxied
    as an NSDate subclass.
    """
    if options._date_types is None:
        options._date_types = ()

    options._date_types += (type,)


registerListType(collections_abc.Sequence)
registerListType(xrange if sys.version_info[0] == 2 else range)
registerMappingType(collections_abc.Mapping)
registerMappingType(dict)
registerSetType(set)
registerSetType(frozenset)
registerSetType(collections_abc.Set)
registerDateType(datetime.date)
registerDateType(datetime.datetime)
