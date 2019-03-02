from objc import _objc
import sys

__all__ = []


class OC_PythonFloat(float):
    __slots__=('__pyobjc_object__',)


    def __new__(cls, obj, value):
        self = float.__new__(cls, value)
        self.__pyobjc_object__ = obj
        return self

    __class__ = property(lambda self: self.__pyobjc_object__.__class__)

    def __getattr__(self, attr):
        return getattr(self.__pyobjc_object__, attr)

    def __reduce__(self):
        return (float, (float(self),))

base_class = int if sys.version_info[0] >= 3 else long

class OC_PythonLong(base_class):

    def __new__(cls, obj, value):
        self = base_class.__new__(cls, value)
        self.__pyobjc_object__ = obj
        return self

    __class__ = property(lambda self: self.__pyobjc_object__.__class__)

    def __getattr__(self, attr):
        return getattr(self.__pyobjc_object__, attr)

    # The long type doesn't support __slots__ on subclasses, fake
    # one part of the effect of __slots__: don't allow setting of attributes.
    def __setattr__(self, attr, value):
        if attr != '__pyobjc_object__':
            raise AttributeError("'%s' object has no attribute '%s')"%(self.__class__.__name__, attr))
        self.__dict__['__pyobjc_object__'] = value

    def __reduce__(self):
        return (base_class, (base_class(self),))


if sys.version_info[0] == 2:  # pragma: no 3.x cover; pragma: no branch
    class OC_PythonInt(int):
        __slots__=('__pyobjc_object__',)

        def __new__(cls, obj, value):
            self = int.__new__(cls, value)
            self.__pyobjc_object__ = obj
            return self

        __class__ = property(lambda self: self.__pyobjc_object__.__class__)

        def __getattr__(self, attr):
            return getattr(self.__pyobjc_object__, attr)

        def __reduce__(self):
            return (int, (int(self),))


NSNumber = _objc.lookUpClass('NSNumber')
NSDecimalNumber = _objc.lookUpClass('NSDecimalNumber')

def numberWrapper(obj):
    if isinstance(obj, NSDecimalNumber):
        return obj

    try:
        tp = obj.objCType()
    except AttributeError:
        import warnings
        warnings.warn("NSNumber instance doesn't implement objCType? %r" % (obj,), RuntimeWarning)
        return obj

    if tp in b'qQLfd':
        if tp == b'q':
            return OC_PythonLong(obj, obj.longLongValue())
        elif tp in b'QL':
            return OC_PythonLong(obj, obj.unsignedLongLongValue())
        else:
            return OC_PythonFloat(obj, obj.doubleValue())
    elif sys.version_info[0] == 2:  # pragma: no 3.x cover
        return OC_PythonInt(obj, obj.longValue())
    else: # pragma: no 2.x cover
        return OC_PythonLong(obj, obj.longValue())

_objc.options._nsnumber_wrapper = numberWrapper
