"""
Convenience interface for NSDictionary/NSMutableDictionary
"""
__all__ = ()

from objc._convenience_mapping import addConvenienceForBasicMapping
from objc._convenience import container_wrap, container_unwrap, addConvenienceForClass
from objc._objc import lookUpClass

import sys, os

if sys.version_info[0] == 2:
    import collections as collections_abc
else:
    import collections.abc as collections_abc

NSDictionary = lookUpClass('NSDictionary')
NSMutableDictionary = lookUpClass('NSMutableDictionary')

addConvenienceForBasicMapping('NSDictionary', True)
addConvenienceForBasicMapping('NSMutableDictionary', False)


def _all_contained_in(inner, outer):
    """
    Return True iff all items in ``inner`` are also in ``outer``.
    """
    for v in inner:
        if v not in outer:
            return False

    return True


def nsdict__len__(self):
    return self.count()


def nsdict__iter__(self):
    return iter(self.keyEnumerator())


class nsdict_view (collections_abc.Set):
    __slots__ = ()

    def __eq__(self, other):
        if not isinstance(other, collections_abc.Set):
            return NotImplemented

        if len(self) == len(other):
            return _all_contained_in(self, other)

        else:
            return False

    def __ne__(self, other):
        if not isinstance(other, collections_abc.Set):
            return NotImplemented

        if len(self) == len(other):
            return not _all_contained_in(self, other)

        else:
            return True

    def __lt__(self, other):
        if not isinstance(other, collections_abc.Set):
            return NotImplemented

        if len(self) < len(other):
            return _all_contained_in(self, other)

        else:
            return False

    def __le__(self, other):
        if not isinstance(other, collections_abc.Set):
            return NotImplemented

        if len(self) <= len(other):
            return _all_contained_in(self, other)

        else:
            return False

    def __gt__(self, other):
        if not isinstance(other, collections_abc.Set):
            return NotImplemented

        if len(self) > len(other):
            return _all_contained_in(other, self)

        else:
            return False

    def __ge__(self, other):
        if not isinstance(other, collections_abc.Set):
            return NotImplemented

        if len(self) >= len(other):
            return _all_contained_in(other, self)

        else:
            return False

    def __and__(self, other):
        if not isinstance(other, collections_abc.Set):
            return NotImplemented
        result = set(self)
        result.intersection_update(other)
        return result

    def __rand__(self, other):
        if not isinstance(other, collections_abc.Set):
            return NotImplemented
        result = set(self)
        result.intersection_update(other)
        return result

    def __or__(self, other):
        if not isinstance(other, collections_abc.Set):
            return NotImplemented
        result = set(self)
        result.update(other)
        return result

    def __ror__(self, other):
        if not isinstance(other, collections_abc.Set):
            return NotImplemented
        result = set(self)
        result.update(other)
        return result

    def __sub__(self, other):
        if not isinstance(other, collections_abc.Set):
            return NotImplemented
        result = set(self)
        result.difference_update(other)
        return result

    def __rsub__(self, other):
        if not isinstance(other, collections_abc.Set):
            return NotImplemented
        result = set(other)
        result.difference_update(self)
        return result

    def __xor__(self, other):
        if not isinstance(other, collections_abc.Set):
            return NotImplemented
        result = set(self)
        result.symmetric_difference_update(other)
        return result

    def __rxor__(self, other):
        if not isinstance(other, collections_abc.Set):
            return NotImplemented
        result = set(self)
        result.symmetric_difference_update(other)
        return result


class nsdict_keys(nsdict_view):
    __slots__ = ('__value', )

    def __init__(self, value):
        self.__value = value

    def __repr__(self):
        keys = list(self.__value)

        return "<nsdict_keys({0})>".format(keys)

    def __len__(self):
        return len(self.__value)

    def __iter__(self):
        return iter(self.__value)

    def __contains__(self, value):
        return value in self.__value


class nsdict_values(nsdict_view):
    __slots__ = ('__value',)

    def __init__(self, value):
        self.__value = value

    def __repr__(self):
        values = list(self)
        values.sort()

        return "<nsdict_values({0})>".format(values)

    def __len__(self):
        return len(self.__value)

    def __iter__(self):
        return iter(self.__value.objectEnumerator())

    def __contains__(self, value):
        for v in iter(self):
            if value == v:
                return True
        return False


class nsdict_items(nsdict_view):
    __slots__ = ('__value',)

    def __init__(self, value):
        self.__value = value

    def __repr__(self):
        values = list(self)
        values.sort()

        return "<nsdict_items({0})>".format(values)

    def __len__(self):
        return len(self.__value)

    def __iter__(self):
        for k in self.__value:
            yield (k, self.__value[k])

    def __contains__(self, value):
        for v in iter(self):
            if value == v:
                return True
        return False


collections_abc.KeysView.register(nsdict_keys)
collections_abc.ValuesView.register(nsdict_values)
collections_abc.ItemsView.register(nsdict_items)

collections_abc.Mapping.register(NSDictionary)
collections_abc.MutableMapping.register(NSMutableDictionary)


if int(os.uname()[2].split('.')[0]) <= 10:
    # Limited functionality on OSX 10.6 and earlier

    def nsdict_fromkeys(cls, keys, value=None):
        keys = [container_wrap(k) for k in keys]
        values = [container_wrap(value)]*len(keys)

        return NSDictionary.dictionaryWithObjects_forKeys_(values, keys)

    # XXX: 'nsdict_fromkeys' doesn't work on OSX 10.5
    def nsmutabledict_fromkeys(cls, keys, value=None):
        value = container_wrap(value)

        result = NSMutableDictionary.alloc().init()
        for k in keys:
           result[container_wrap(k)] = value
        return result

else:
    def nsdict_fromkeys(cls, keys, value=None):
        keys = [container_wrap(k) for k in keys]
        values = [container_wrap(value)]*len(keys)

        return cls.dictionaryWithObjects_forKeys_(values, keys)

    def nsmutabledict_fromkeys(cls, keys, value=None):
        value = container_wrap(value)

        result = cls.alloc().init()
        for k in keys:
           result[container_wrap(k)] = value
        return result


def nsdict_new(cls, *args, **kwds):
    if len(args) == 0:
        pass

    elif len(args) == 1:
        d = dict()
        if isinstance(args[0], collections_abc.Mapping):
            items = args[0].items()
        else:
            items = args[0]
        for k , v in items:
            d[container_wrap(k)] = container_wrap(v)

        for k, v in kwds.items():
            d[container_wrap(k)] = container_wrap(v)

        return cls.dictionaryWithDictionary_(d)

    else:
        raise TypeError(
                "dict expected at most 1 arguments, got {0}".format(
                    len(args)))

    if kwds:
        d = dict()
        for k, v in kwds.items():
            d[container_wrap(k)] = container_wrap(v)

        return cls.dictionaryWithDictionary_(d)

    return cls.dictionary()


def nsdict__eq__(self, other):
    if not isinstance(other, collections_abc.Mapping):
        return False

    return self.isEqualToDictionary_(other)


def nsdict__ne__(self, other):
    return not nsdict__eq__(self, other)


if sys.version_info[0] == 3:  # pragma: no 2.x cover
    def nsdict__lt__(self, other):
        return NotImplemented

    def nsdict__le__(self, other):
        return NotImplemented

    def nsdict__ge__(self, other):
        return NotImplemented

    def nsdict__gt__(self, other):
        return NotImplemented

    addConvenienceForClass('NSDictionary', (
        ('keys', lambda self: nsdict_keys(self)),
        ('values', lambda self: nsdict_values(self)),
        ('items', lambda self: nsdict_items(self)),
    ))

else:  # pragma: no 3.x cover
    def nsdict__cmp__(self, other):
        if not isinstance(other, collections_abc.Mapping):
            return NotImplemented

        if len(self) < len(other):
            return -1

        elif len(self) > len(other):
            return 1

        sentinel = object()

        for a_key in sorted(self):
            try:
                if self[a_key] != other[a_key]:
                    break

            except KeyError:
                break

        else:
            a_key = sentinel

        for b_key in sorted(self):
            try:
                if self[b_key] != other[b_key]:
                    break

            except KeyError:
                break
        else:
            b_key = sentinel

        r = cmp(a_key, b_key)
        if r == 0 and a_key is not sentinel:
            r =  cmp(self[a_key], other[a_key])

        return r

    def nsdict__lt__(self, other):
        return nsdict_cmp(self, other) < 0

    def nsdict__le__(self, other):
        return nsdict_cmp(self, other) <= 0

    def nsdict__ge__(self, other):
        return nsdict_cmp(self, other) >= 0

    def nsdict__gt__(self, other):
        return nsdict_cmp(self, other) > 0


    def nsdict_iterkeys(aDict):
        return iter(aDict.keyEnumerator())

    def nsdict_itervalues(aDict):
        return iter(aDict.objectEnumerator())

    def nsdict_iteritems(aDict):
        for key in aDict:
            yield (key, aDict[key])

    def nsdict_old_items(aDict):
        return [(key, aDict[key]) for key in aDict]

    addConvenienceForClass('NSDictionary', (
        ('__cmp__', nsdict__cmp__),
        ('fromkeys', classmethod(nsdict_fromkeys)),
        ('viewkeys', lambda self: nsdict_keys(self)),
        ('viewvalues', lambda self: nsdict_values(self)),
        ('viewitems', lambda self: nsdict_items(self)),
        ('keys', lambda self: self.allKeys()),
        ('items', nsdict_old_items),
        ('values', lambda self: self.allValues()),
        ('iterkeys', nsdict_iterkeys),
        ('iteritems', nsdict_iteritems),
        ('itervalues', nsdict_itervalues),
    ))

    addConvenienceForClass('NSMutableDictionary', (
        ('fromkeys', classmethod(nsmutabledict_fromkeys)),
    ))


addConvenienceForClass('NSDictionary', (
    ('__new__', staticmethod(nsdict_new)),
    ('fromkeys', classmethod(nsdict_fromkeys)),
    ('__eq__', nsdict__eq__),
    ('__ne__', nsdict__ne__),
    ('__lt__', nsdict__lt__),
    ('__le__', nsdict__le__),
    ('__gt__', nsdict__gt__),
    ('__ge__', nsdict__ge__),
    ('__len__', nsdict__len__),
    ('__iter__', nsdict__iter__),
))


addConvenienceForClass('NSMutableDictionary', (
    ('__new__', staticmethod(nsdict_new)),
    ('fromkeys', classmethod(nsdict_fromkeys)),
    ('clear',     lambda self: self.removeAllObjects()),
))
