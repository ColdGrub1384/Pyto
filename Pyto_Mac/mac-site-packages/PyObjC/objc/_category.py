__all__ = ['classAddMethod', 'Category']

from objc._objc import selector, classAddMethods, objc_class, ivar

from types import FunctionType, MethodType

def classAddMethod(cls, name, method):
    """
    Add a single method to a class. 'name' is the ObjC selector
    """
    if isinstance(method, selector):
        sel = selector(method.callable,
                    selector=name,
                    signature=method.signature,
                    isClassMethod=method.isClassMethod)
    else:
        sel = selector(method, selector=name)

    return classAddMethods(cls, [sel])


#
# Syntactic support for categories
#

class _CategoryMeta(type):
    """
    Meta class for categories.
    """
    __slots__ = ()
    _IGNORENAMES = ('__module__', '__name__', '__doc__')
    def _newSubclass(cls, name, bases, methods):
        return type.__new__(cls, name, bases, methods)
    _newSubclass = classmethod(_newSubclass)

    def __new__(cls, name, bases, methods):
        if len(bases) != 1:
            raise TypeError("Cannot have multiple inheritance with Categories")

        c = bases[0].real_class

        if c.__name__ != name:
            raise TypeError("Category name must be same as class name")


        m = [ x[1] for x in methods.items() if x[0] not in cls._IGNORENAMES  and isinstance(x[1], (FunctionType, MethodType, selector, classmethod))]
        vars = [ x for x in methods.items() if x[0] not in cls._IGNORENAMES  and not isinstance(x[1], (FunctionType, MethodType, selector, classmethod))]
        for k, v in vars:
            if isinstance(v, ivar):
                raise TypeError("Cannot add instance variables in a Category")

        classAddMethods(c, m)
        for k, v in vars:
            setattr(c, k, v)
        return c

def Category(cls):
    """
    Create a category on ``cls``.

    Usage:
        class SomeClass (Category(SomeClass)):
            def method(self):
                pass

    ``SomeClass`` is an existing class that will be rebound to the same
    value. The side-effect of this class definition is that the methods
    in the class definition will be added to the existing class.
    """
    if not isinstance(cls, objc_class):
        raise TypeError("Category can only be used on Objective-C classes")
    retval = _CategoryMeta._newSubclass('Category', (), dict(real_class=cls))
    return retval
