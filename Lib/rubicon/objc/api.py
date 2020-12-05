import collections.abc
import decimal
import enum
import inspect
from ctypes import (
    CFUNCTYPE,
    POINTER,
    ArgumentError,
    Array,
    Structure,
    Union,
    addressof,
    byref,
    c_bool,
    c_char_p,
    c_int,
    c_uint,
    c_uint8,
    c_ulong,
    c_void_p,
    cast,
    sizeof,
    string_at,
)

from .types import (
    compound_value_for_sequence,
    ctype_for_type,
    ctypes_for_method_encoding,
    encoding_for_ctype,
    register_ctype_for_type,
)
from .runtime import (
    Class,
    SEL,
    add_ivar,
    add_method,
    ensure_bytes,
    get_class,
    get_ivar,
    libc,
    libobjc,
    objc_block,
    objc_id,
    objc_property_attribute_t,
    object_isClass,
    set_ivar,
    send_message,
    send_super,
)

__all__ = [
    "Block",
    "NSArray",
    "NSData",
    "NSDecimalNumber",
    "NSDictionary",
    "NSMutableArray",
    "NSMutableDictionary",
    "NSNumber",
    "NSObject",
    "NSObjectProtocol",
    "NSString",
    "ObjCBlock",
    "ObjCClass",
    "ObjCInstance",
    "ObjCMetaClass",
    "ObjCMethod",
    "ObjCProtocol",
    "Protocol",
    "at",
    "for_objcclass",
    "get_type_for_objcclass_map",
    "ns_from_py",
    "objc_classmethod",
    "objc_const",
    "objc_ivar",
    "objc_method",
    "objc_property",
    "objc_rawmethod",
    "py_from_ns",
    "register_type_for_objcclass",
    "type_for_objcclass",
    "unregister_type_for_objcclass",
]


def encoding_from_annotation(f, offset=1):
    argspec = inspect.getfullargspec(inspect.unwrap(f))

    encoding = [argspec.annotations.get("return", ObjCInstance), ObjCInstance, SEL]

    for varname in argspec.args[offset:]:
        encoding.append(argspec.annotations.get(varname, ObjCInstance))

    return encoding


class ObjCMethod(object):
    """This represents an unbound Objective-C method (really an IMP)."""

    def __init__(self, method):
        """Initialize with an Objective-C Method pointer.  We then determine
        the return type and argument type information of the method."""
        self.selector = libobjc.method_getName(method)
        self.name = self.selector.name
        self.pyname = self.name.replace(b":", b"_")
        self.encoding = libobjc.method_getTypeEncoding(method)
        self.restype, *self.argtypes = ctypes_for_method_encoding(self.encoding)
        self.imp = libobjc.method_getImplementation(method)
        self.func = None

    def get_prototype(self):
        """Returns a ctypes CFUNCTYPE for the method."""
        return CFUNCTYPE(self.restype, *self.argtypes)

    def __repr__(self):
        return "<ObjCMethod: %s %s>" % (self.name, self.encoding)

    def get_callable(self):
        """Returns a python-callable version of the method's IMP."""
        if not self.func:
            self.func = cast(self.imp, self.get_prototype())
            self.func.restype = self.restype
            self.func.argtypes = self.argtypes
        return self.func

    def __call__(self, receiver, *args, convert_args=True, convert_result=True):
        """Call the method with the given id and arguments.  You do not need
        to pass in the selector as an argument since it will be automatically
        provided."""
        f = self.get_callable()

        if convert_args:
            converted_args = []
            for argtype, arg in zip(self.argtypes[2:], args):
                if isinstance(arg, enum.Enum):
                    # Convert Python enum objects to their values
                    arg = arg.value

                if issubclass(argtype, objc_block):
                    if arg is None:
                        # allow for 'nil' block args, which some objc methods accept
                        arg = ns_from_py(arg)
                    elif callable(arg) and not isinstance(
                        arg, Block
                    ):  # <-- guard against someone someday making Block callable
                        # Note: We need to keep the temp. Block instance
                        # around at least until the objc method is called.
                        # _as_parameter_ is used in the actual ctypes marshalling below.
                        arg = Block(arg)
                    # ^ For blocks at this point either arg is a Block instance
                    # (making use of _as_parameter_), is None, or if it isn't either of
                    # those two, an ArgumentError will be raised below.
                elif issubclass(argtype, objc_id):
                    # Convert Python objects to Foundation objects
                    arg = ns_from_py(arg)
                elif isinstance(arg, collections.abc.Iterable) and issubclass(
                    argtype, (Structure, Array)
                ):
                    arg = compound_value_for_sequence(arg, argtype)

                converted_args.append(arg)
        else:
            converted_args = args

        try:
            result = f(receiver, self.selector, *converted_args)
        except ArgumentError as error:
            # Add more useful info to argument error exceptions, then reraise.
            error.args = (
                error.args[0]
                + " (selector = {self.name}, argtypes = {self.argtypes}, encoding = {self.encoding})".format(
                    self=self
                ),
            )
            raise
        else:
            if not convert_result:
                return result

            # Convert result to python type if it is a instance or class pointer.
            if self.restype is not None and issubclass(self.restype, objc_id):
                result = py_from_ns(result, _auto=True)
            return result


class ObjCPartialMethod(object):
    _sentinel = object()

    def __init__(self, name_start):
        super().__init__()

        self.name_start = name_start
        self.methods = {}

    def __repr__(self):
        return "{cls.__module__}.{cls.__qualname__}({self.name_start!r})".format(
            cls=type(self), self=self
        )

    def __call__(self, receiver, first_arg=_sentinel, **kwargs):
        if first_arg is ObjCPartialMethod._sentinel:
            if kwargs:
                raise TypeError("Missing first (positional) argument")

            args = []
            rest = frozenset()
        else:
            args = [first_arg]
            # Add "" to rest to indicate that the method takes arguments
            rest = frozenset(kwargs) | frozenset(("",))

        try:
            meth, order = self.methods[rest]
        except KeyError:
            raise ValueError(
                "No method was found starting with {!r} and with selector parts {}\nKnown selector parts are:\n{}".format(
                    self.name_start,
                    set(kwargs),
                    "\n".join(repr(parts) for parts in self.methods),
                )
            )

        meth = ObjCMethod(meth)
        args += [kwargs[name] for name in order]
        return meth(receiver, *args)


class ObjCBoundMethod(object):
    """This represents an Objective-C method (an IMP) which has been bound
    to some id which will be passed as the first parameter to the method."""

    def __init__(self, method, receiver):
        """Initialize with a method and ObjCInstance or ObjCClass object."""
        self.method = method
        if type(receiver) == Class:
            self.receiver = cast(receiver, objc_id)
        else:
            self.receiver = receiver

    def __repr__(self):
        return "{cls.__module__}.{cls.__qualname__}({self.method}, {self.receiver})".format(
            cls=type(self), self=self
        )

    def __call__(self, *args, **kwargs):
        """Call the method with the given arguments."""
        return self.method(self.receiver, *args, **kwargs)


def convert_method_arguments(encoding, args):
    """Used to convert Objective-C method arguments to Python values
    before passing them on to the Python-defined method.
    """
    new_args = []
    for e, a in zip(encoding[3:], args):
        if issubclass(e, (objc_id, ObjCInstance)):
            new_args.append(py_from_ns(a, _auto=True))
        else:
            new_args.append(a)
    return new_args


class objc_method(object):
    def __init__(self, py_method):
        super().__init__()

        self.py_method = py_method
        self.encoding = encoding_from_annotation(py_method)

    def __call__(self, objc_self, objc_cmd, *args):
        py_self = ObjCInstance(objc_self)
        args = convert_method_arguments(self.encoding, args)
        result = self.py_method(py_self, *args)
        if self.encoding[0] is not None and issubclass(
            self.encoding[0], (objc_id, ObjCInstance)
        ):
            result = ns_from_py(result)
            if result is not None:
                result = result.ptr
        if isinstance(result, c_void_p):
            return result.value
        else:
            return result

    def register(self, cls, attr):
        name = attr.replace("_", ":")
        cls.imp_keep_alive_table[name] = add_method(cls, name, self, self.encoding)

    def protocol_register(self, proto, attr):
        name = attr.replace("_", ":")
        types = b"".join(encoding_for_ctype(ctype_for_type(tp)) for tp in self.encoding)
        libobjc.protocol_addMethodDescription(proto, SEL(name), types, True, True)


class objc_classmethod(object):
    def __init__(self, py_method):
        super().__init__()

        self.py_method = py_method
        self.encoding = encoding_from_annotation(py_method)

    def __call__(self, objc_cls, objc_cmd, *args):
        py_cls = ObjCClass(objc_cls)
        args = convert_method_arguments(self.encoding, args)
        result = self.py_method(py_cls, *args)
        if self.encoding[0] is not None and issubclass(
            self.encoding[0], (objc_id, ObjCInstance)
        ):
            result = ns_from_py(result)
            if result is not None:
                result = result.ptr
        if isinstance(result, c_void_p):
            return result.value
        else:
            return result

    def register(self, cls, attr):
        name = attr.replace("_", ":")
        cls.imp_keep_alive_table[name] = add_method(
            cls.objc_class, name, self, self.encoding
        )

    def protocol_register(self, proto, attr):
        name = attr.replace("_", ":")
        types = b"".join(encoding_for_ctype(ctype_for_type(tp)) for tp in self.encoding)
        libobjc.protocol_addMethodDescription(proto, SEL(name), types, True, False)


class objc_ivar(object):
    """Add an instance variable of type vartype to the subclass.
    vartype is a ctypes type.
    The class must be registered AFTER adding instance variables.
    """

    def __init__(self, vartype):
        self.vartype = vartype

    def pre_register(self, ptr, attr):
        return add_ivar(ptr, attr, self.vartype)

    def protocol_register(self, proto, attr):
        raise TypeError("Objective-C protocols cannot have ivars")


class objc_property(object):
    """Add a property to an Objective-C class.

    An ivar, a getter and a setter are automatically generated.
    If the property's type is objc_id or a subclass, the generated setter keeps the stored object retained, and
    releases it when it is replaced.
    """

    def __init__(self, vartype=objc_id):
        super().__init__()

        self.vartype = ctype_for_type(vartype)

    def _get_property_attributes(self):
        attrs = [
            objc_property_attribute_t(
                b"T", encoding_for_ctype(self.vartype)
            ),  # Type: vartype
        ]
        if issubclass(self.vartype, objc_id):
            attrs.append(objc_property_attribute_t(b"&", b""))  # retain
        return (objc_property_attribute_t * len(attrs))(*attrs)

    def pre_register(self, ptr, attr):
        add_ivar(ptr, "_" + attr, self.vartype)

    def register(self, cls, attr):
        def _objc_getter(objc_self, _cmd):
            value = get_ivar(objc_self, "_" + attr)
            # ctypes complains when a callback returns a "boxed" primitive type, so we have to manually unbox it.
            # If the data object has a value attribute and is not a structure or union, assume that it is
            # a primitive and unbox it.
            if not isinstance(value, (Structure, Union)):
                try:
                    value = value.value
                except AttributeError:
                    pass

            return value

        def _objc_setter(objc_self, _cmd, new_value):
            if not isinstance(new_value, self.vartype):
                # If vartype is a primitive, then new_value may be unboxed. If that is the case, box it manually.
                new_value = self.vartype(new_value)
            old_value = get_ivar(objc_self, "_" + attr)
            if issubclass(self.vartype, objc_id) and new_value:
                # If the new value is a non-null object, retain it.
                send_message(new_value, "retain", restype=objc_id, argtypes=[])
            set_ivar(objc_self, "_" + attr, new_value)
            if issubclass(self.vartype, objc_id) and old_value:
                # If the old value is a non-null object, release it.
                send_message(old_value, "release", restype=None, argtypes=[])

        setter_name = "set" + attr[0].upper() + attr[1:] + ":"

        cls.imp_keep_alive_table[attr] = add_method(
            cls.ptr, attr, _objc_getter, [self.vartype, ObjCInstance, SEL],
        )
        cls.imp_keep_alive_table[setter_name] = add_method(
            cls.ptr, setter_name, _objc_setter, [None, ObjCInstance, SEL, self.vartype],
        )

        attrs = self._get_property_attributes()
        libobjc.class_addProperty(cls, ensure_bytes(attr), attrs, len(attrs))

    def protocol_register(self, proto, attr):
        attrs = self._get_property_attributes()
        libobjc.protocol_addProperty(
            proto, ensure_bytes(attr), attrs, len(attrs), True, True
        )


class objc_rawmethod(object):
    def __init__(self, py_method):
        super().__init__()

        self.py_method = py_method
        self.encoding = encoding_from_annotation(py_method, offset=2)

    def __call__(self, *args, **kwargs):
        return self.py_method(*args, **kwargs)

    def register(self, cls, attr):
        name = attr.replace("_", ":")
        cls.imp_keep_alive_table[name] = add_method(cls, name, self, self.encoding)

    def protocol_register(self, proto, attr):
        raise TypeError(
            "Protocols cannot have method implementations, use objc_method instead of objc_rawmethod"
        )


_type_for_objcclass_map = {}


def type_for_objcclass(objcclass):
    """Look up the ObjCInstance subclass used to represent instances of the given Objective-C class in Python.

    If the exact Objective-C class is not registered, each superclass is also checked, defaulting to ObjCInstance
    if none of the classes in the superclass chain is registered. Afterwards, all searched superclasses are registered
    for the ObjCInstance subclass that was found.
    """

    if isinstance(objcclass, ObjCClass):
        objcclass = objcclass.ptr

    superclass = objcclass
    traversed_classes = []
    pytype = ObjCInstance
    while superclass.value is not None:
        try:
            pytype = _type_for_objcclass_map[superclass.value]
        except KeyError:
            traversed_classes.append(superclass)
            superclass = libobjc.class_getSuperclass(superclass)
        else:
            break

    for cls in traversed_classes:
        register_type_for_objcclass(pytype, cls)

    return pytype


def register_type_for_objcclass(pytype, objcclass):
    """Register a conversion from an Objective-C class to an ObjCInstance subclass."""

    if isinstance(objcclass, ObjCClass):
        objcclass = objcclass.ptr

    _type_for_objcclass_map[objcclass.value] = pytype


def unregister_type_for_objcclass(objcclass):
    """Unregister a conversion from an Objective-C class to an ObjCInstance subclass"""

    if isinstance(objcclass, ObjCClass):
        objcclass = objcclass.ptr

    del _type_for_objcclass_map[objcclass.value]


def get_type_for_objcclass_map():
    """Get a copy of all currently registered ObjCInstance subclasses as a mapping.
    Keys are Objective-C class addresses as integers.
    """

    return dict(_type_for_objcclass_map)


def for_objcclass(objcclass):
    """Decorator for registering a conversion from an Objective-C class to an ObjCInstance subclass.
    This is equivalent to calling register_type_for_objcclass.
    """

    def _for_objcclass(pytype):
        register_type_for_objcclass(pytype, objcclass)
        return pytype

    return _for_objcclass


class ObjCInstance(object):
    """Python wrapper for an Objective-C instance."""

    _cached_objects = {}

    @property
    def objc_class(self):
        return ObjCClass(libobjc.object_getClass(self))

    def __new__(cls, object_ptr, _name=None, _bases=None, _ns=None):
        """Create a new ObjCInstance or return a previously created one
        for the given object_ptr which should be an Objective-C id."""
        # Make sure that object_ptr is wrapped in an objc_id.
        if not isinstance(object_ptr, objc_id):
            object_ptr = cast(object_ptr, objc_id)

        # If given a nil pointer, return None.
        if not object_ptr.value:
            return None

        # Check if we've already created a Python ObjCInstance for this
        # object_ptr id and if so, then return it.  A single ObjCInstance will
        # be created for any object pointer when it is first encountered.
        # This same ObjCInstance will then persist until the object is
        # deallocated.
        if object_ptr.value in cls._cached_objects:
            return cls._cached_objects[object_ptr.value]

        # If the given pointer points to a class, return an ObjCClass instead (if we're not already creating one).
        if not issubclass(cls, ObjCClass) and object_isClass(object_ptr):
            return ObjCClass(object_ptr)

        # Otherwise, create a new ObjCInstance.
        if issubclass(cls, type):
            # Special case for ObjCClass to pass on the class name, bases and namespace to the type constructor.
            self = super().__new__(cls, _name, _bases, _ns)
        else:
            if isinstance(object_ptr, objc_block):
                cls = ObjCBlockInstance
            else:
                cls = type_for_objcclass(libobjc.object_getClass(object_ptr))
            self = super().__new__(cls)
        super(ObjCInstance, type(self)).__setattr__(self, "ptr", object_ptr)
        super(ObjCInstance, type(self)).__setattr__(self, "_as_parameter_", object_ptr)
        if isinstance(object_ptr, objc_block):
            super(ObjCInstance, type(self)).__setattr__(
                self, "block", ObjCBlock(object_ptr)
            )
        # Store new object in the dictionary of cached objects, keyed
        # by the (integer) memory address pointed to by the object_ptr.
        cls._cached_objects[object_ptr.value] = self

        # Classes are never deallocated, so they don't need a DeallocationObserver.
        # This is also necessary to make the definition of DeallocationObserver work -
        # otherwise creating the ObjCClass for DeallocationObserver would try to
        # instantiate a DeallocationObserver itself.
        if not object_isClass(object_ptr):
            # Create a DeallocationObserver and associate it with this object.
            # When the Objective-C object is deallocated, the observer will remove
            # the ObjCInstance corresponding to the object from the cached objects
            # dictionary, effectively destroying the ObjCInstance.
            observer = send_message(
                send_message(
                    "DeallocationObserver", "alloc", restype=objc_id, argtypes=[]
                ),
                "initWithObject:",
                self,
                restype=objc_id,
                argtypes=[objc_id],
            )
            libobjc.objc_setAssociatedObject(self, observer, observer, 0x301)

            # The observer is retained by the object we associate it to.  We release
            # the observer now so that it will be deallocated when the associated
            # object is deallocated.
            send_message(observer, "release")

        return self

    def __str__(self):
        desc = self.description
        if desc is None:
            raise ValueError("{self.name}.description returned nil".format(self=self))
        return str(desc)

    def __repr__(self):
        return "<%s.%s %#x: %s at %#x: %s>" % (
            type(self).__module__,
            type(self).__qualname__,
            id(self),
            self.objc_class.name,
            self.ptr.value,
            self.debugDescription,
        )

    def __getattr__(self, name):
        """Returns a callable method object with the given name."""
        # Search for named instance method in the class object and if it
        # exists, return callable object with self as hidden argument.
        # Note: you should give self and not self.ptr as a parameter to
        # ObjCBoundMethod, so that it will be able to keep the ObjCInstance
        # alive for chained calls like MyClass.alloc().init() where the
        # object created by alloc() is not assigned to a variable.

        # If there's a property with this name; return the value directly.
        # If the name ends with _, we can shortcut this step, because it's
        # clear that we're dealing with a method call.
        if not name.endswith("_"):
            method = self.objc_class._cache_property_accessor(name)
            if method:
                return ObjCBoundMethod(method, self)()

        # See if there's a partial method starting with the given name,
        # either on self's class or any of the superclasses.
        cls = self.objc_class
        while cls is not None:
            # Load the class's methods if we haven't done so yet.
            if cls.methods_ptr is None:
                cls._load_methods()

            try:
                method = cls.partial_methods[name]
                break
            except KeyError:
                cls = cls.superclass
        else:
            method = None

        if method is not None:
            # If the partial method can only resolve to one method that takes no arguments,
            # return that method directly, instead of a mostly useless partial method.
            if set(method.methods) == {frozenset()}:
                method, _ = method.methods[frozenset()]
                method = ObjCMethod(method)

            return ObjCBoundMethod(method, self)

        # See if there's a method whose full name matches the given name.
        method = self.objc_class._cache_method(name.replace("_", ":"))
        if method:
            return ObjCBoundMethod(method, self)
        else:
            raise AttributeError(
                "%s.%s %s has no attribute %s"
                % (
                    type(self).__module__,
                    type(self).__qualname__,
                    self.objc_class.name,
                    name,
                )
            )

    def __setattr__(self, name, value):
        if name in self.__dict__:
            # For attributes already in __dict__, use the default __setattr__.
            super(ObjCInstance, type(self)).__setattr__(self, name, value)
        else:
            method = self.objc_class._cache_property_mutator(name)
            if method:
                # Convert enums to their underlying values.
                if isinstance(value, enum.Enum):
                    value = value.value
                ObjCBoundMethod(method, self)(value)
            else:
                super(ObjCInstance, type(self)).__setattr__(self, name, value)


# The inheritance order is important here.
# type must come after ObjCInstance, so super() refers to ObjCInstance.
# This allows the ObjCInstance constructor to receive the class pointer
# as well as the name, bases, attrs arguments.
# The other way around this would not be possible, because then
# the type constructor would be called before ObjCInstance's, and there
# would be no opportunity to pass extra arguments.
class ObjCClass(ObjCInstance, type):
    """Python wrapper for an Objective-C class."""

    @property
    def superclass(self):
        """The superclass of this class, or None if this is a root class (such as NSObject)."""

        super_ptr = libobjc.class_getSuperclass(self)
        if super_ptr.value is None:
            return None
        else:
            return ObjCClass(super_ptr)

    @property
    def protocols(self):
        """The protocols adopted by this class."""

        out_count = c_uint()
        protocols_ptr = libobjc.class_copyProtocolList(self, byref(out_count))
        return tuple(ObjCProtocol(protocols_ptr[i]) for i in range(out_count.value))

    @classmethod
    def _new_from_name(cls, name):
        name = ensure_bytes(name)
        ptr = get_class(name)
        if ptr.value is None:
            raise NameError("ObjC Class '%s' couldn't be found." % name)

        return ptr, name

    @classmethod
    def _new_from_ptr(cls, ptr):
        ptr = cast(ptr, Class)
        if ptr.value is None:
            raise ValueError("Cannot create ObjCClass from nil pointer")
        elif not object_isClass(ptr):
            raise ValueError(
                "Pointer {} ({:#x}) does not refer to a class".format(ptr, ptr.value)
            )
        name = libobjc.class_getName(ptr)

        return ptr, name

    @classmethod
    def _new_from_class_statement(cls, name, bases, attrs, *, protocols):

        exists = False
        if get_class(ensure_bytes(name)).value is not None:
            i = 2
            while get_class(ensure_bytes(name + str(i))).value is not None:
                i += 1

            name = name + str(i)

        name = ensure_bytes(name)

        try:
            (superclass,) = bases
        except ValueError:
            raise ValueError(
                "An Objective-C class must have exactly one base class, not {}".format(
                    len(bases)
                )
            )

        # Check that the superclass is an ObjCClass.
        if not isinstance(superclass, ObjCClass):
            raise TypeError(
                "The superclass of an Objective-C class must be an ObjCClass, "
                "not a {cls.__module__}.{cls.__qualname__}".format(cls=type(superclass))
            )

        # Check that all protocols are ObjCProtocols, and that there are no duplicates.
        for proto in protocols:
            if not isinstance(proto, ObjCProtocol):
                raise TypeError(
                    "The protocols list of an Objective-C class must contain ObjCProtocol objects, "
                    "not {cls.__module__}.{cls.__qualname__}".format(cls=type(proto))
                )
            elif protocols.count(proto) > 1:
                raise ValueError(
                    "Protocol {} is adopted more than once".format(proto.name)
                )

        # Create the ObjC class description
        ptr = libobjc.objc_allocateClassPair(superclass, name, 0)
        if ptr is None:
            raise RuntimeError("Class pair allocation failed")

        # Adopt all the protocols.
        for proto in protocols:
            if not libobjc.class_addProtocol(ptr, proto):
                raise RuntimeError("Failed to adopt protocol {}".format(proto.name))

        # Pre-Register all the instance variables
        for attr, obj in attrs.items():
            if hasattr(obj, "pre_register"):
                obj.pre_register(ptr, attr)

        # Register the ObjC class
        libobjc.objc_registerClassPair(ptr)

        return ptr, name, attrs

    def __new__(cls, name_or_ptr, bases=None, attrs=None, *, protocols=()):
        """Create a new ObjCClass instance or return a previously created instance for the given Objective-C class.

        If called with a single class pointer argument, an ObjCClass for that class pointer is returned.
        If called with a single str or bytes argument, the Objective-C with that name is returned.

        If called with three arguments, they must a name, a superclass list, and a namespace dict. A new Objective-C
        class with those properties is created and returned. This form is usually called implicitly when subclassing
        another ObjCClass.
        In the three-argument form, an optional protocols keyword argument is also accepted. If present, it must be
        a sequence of ObjCProtocol objects that the new class should adopt.
        """

        if (bases is None) ^ (attrs is None):
            raise TypeError("ObjCClass arguments 2 and 3 must be given together")

        if bases is None and attrs is None:
            # A single argument provided. If it's a string, treat it as
            # a class name. Anything else treat as a class pointer.

            if protocols:
                raise ValueError(
                    "protocols kwarg is not allowed for the single-argument form of ObjCClass"
                )

            attrs = {}

            if isinstance(name_or_ptr, (bytes, str)):
                ptr, name = cls._new_from_name(name_or_ptr)
            else:
                ptr, name = cls._new_from_ptr(name_or_ptr)
                if not issubclass(cls, ObjCMetaClass) and libobjc.class_isMetaClass(
                    ptr
                ):
                    return ObjCMetaClass(ptr)
        else:
            ptr, name, attrs = cls._new_from_class_statement(
                name_or_ptr, bases, attrs, protocols=protocols
            )

        objc_class_name = name.decode("utf-8")

        new_attrs = {
            "_class_inited": False,
            "name": objc_class_name,
            "methods_ptr_count": c_uint(0),
            "methods_ptr": None,
            # Mapping of name -> method pointer
            "instance_method_ptrs": {},
            # Mapping of name -> instance method
            "instance_methods": {},
            # Mapping of name -> (accessor method, mutator method)
            "instance_properties": {},
            # Explicitly declared properties
            "forced_properties": set(),
            # Mapping of first selector part -> ObjCPartialMethod instances
            "partial_methods": {},
            # Mapping of name -> CFUNCTYPE callback function
            # This only contains the IMPs of methods created in Python,
            # which need to be kept from being garbage-collected.
            # It does not contain any other methods, do not use it for calling methods.
            "imp_keep_alive_table": {},
        }

        # On Python 3.6 and later, the class namespace may contain a __classcell__ attribute that must be passed on
        # to type.__new__. See https://docs.python.org/3/reference/datamodel.html#creating-the-class-object
        if "__classcell__" in attrs:
            new_attrs["__classcell__"] = attrs["__classcell__"]

        # Create the class object. If there is already a cached instance for ptr,
        # it is returned and the additional arguments are ignored.
        # Logically this can only happen when creating an ObjCClass from an existing
        # name or pointer, not when creating a new class.
        # If there is no cached instance for ptr, a new one is created and cached.
        self = super().__new__(cls, ptr, objc_class_name, (ObjCInstance,), new_attrs)

        if not self._class_inited:
            self._class_inited = True

            # Register all the methods, class methods, etc
            registered_something = False
            for attr, obj in attrs.items():
                if hasattr(obj, "register"):
                    registered_something = True
                    obj.register(self, attr)

            # If anything was registered, reload the methods of this class
            # (and the metaclass, because there may be new class methods).
            if registered_something:
                self._load_methods()
                self.objc_class._load_methods()

        return self

    def __init__(self, *args, **kwargs):
        # Prevent kwargs from being passed on to type.__init__, which does not accept any kwargs in Python < 3.6.
        super().__init__(*args)

    def _cache_method(self, name):
        """Returns a python representation of the named instance method,
        either by looking it up in the cached list of methods or by searching
        for and creating a new method object."""

        supercls = self
        objc_method = None
        while supercls is not None:
            # Load the class's methods if we haven't done so yet.
            if supercls.methods_ptr is None:
                supercls._load_methods()

            try:
                objc_method = supercls.instance_methods[name]
                break
            except KeyError:
                pass

            try:
                objc_method = ObjCMethod(supercls.instance_method_ptrs[name])
                break
            except KeyError:
                pass

            supercls = supercls.superclass

        if objc_method is None:
            return None
        else:
            self.instance_methods[name] = objc_method
            return objc_method

    def _cache_property_methods(self, name):
        """Return the accessor and mutator for the named property.
        """
        if name.endswith("_"):
            # If the requested name ends with _, that's a marker that we're
            # dealing with a method call, not a property, so we can shortcut
            # the process.
            methods = None
        else:
            # Check 1: Does the class respond to the property?
            responds = libobjc.class_getProperty(self, name.encode("utf-8"))

            # Check 2: Does the class have an instance method to retrieve the given name
            accessor = self._cache_method(name)

            # Check 3: Is there a setName: method to set the property with the given name
            mutator = self._cache_method("set" + name[0].title() + name[1:] + ":")

            # Check 4: Is this a forced property on this class or a superclass?
            forced = False
            superclass = self
            while superclass is not None:
                if name in superclass.forced_properties:
                    forced = True
                    break
                superclass = superclass.superclass

            # If the class responds as a property, or it has both an accessor *and*
            # and mutator, then treat it as a property in Python.
            if responds or (accessor and mutator) or forced:
                methods = (accessor, mutator)
            else:
                methods = None
        return methods

    def _cache_property_accessor(self, name):
        """Returns a python representation of an accessor for the named
        property. Existence of a property is done by looking for the write
        selector (set<Name>:).
        """
        try:
            methods = self.instance_properties[name]
        except KeyError:
            methods = self._cache_property_methods(name)
            self.instance_properties[name] = methods
        if methods:
            return methods[0]
        return None

    def _cache_property_mutator(self, name):
        """Returns a python representation of an accessor for the named
        property. Existence of a property is done by looking for the write
        selector (set<Name>:).
        """
        try:
            methods = self.instance_properties[name]
        except KeyError:
            methods = self._cache_property_methods(name)
            self.instance_properties[name] = methods
        if methods:
            return methods[1]
        return None

    def declare_property(self, name):
        self.forced_properties.add(name)

    def declare_class_property(self, name):
        self.objc_class.forced_properties.add(name)

    def __repr__(self):
        return "<%s.%s: %s at %#x>" % (
            type(self).__module__,
            type(self).__qualname__,
            self.name,
            self.ptr.value,
        )

    def __str__(self):
        return "{cls.__name__}({self.name!r})".format(cls=type(self), self=self)

    def __del__(self):
        libc.free(self.methods_ptr)

    def __instancecheck__(self, instance):
        if isinstance(instance, ObjCInstance):
            return bool(instance.isKindOfClass(self))
        else:
            return False

    def __subclasscheck__(self, subclass):
        if isinstance(subclass, ObjCClass):
            return bool(subclass.isSubclassOfClass(self))
        else:
            raise TypeError(
                "issubclass(X, {self!r}) arg 1 must be an ObjCClass, not {tp.__module__}.{tp.__qualname__}".format(
                    self=self, tp=type(subclass)
                )
            )

    def _load_methods(self):
        if self.methods_ptr is not None:
            raise RuntimeError("_load_methods cannot be called more than once")

        self.methods_ptr = libobjc.class_copyMethodList(
            self, byref(self.methods_ptr_count)
        )

        if self.superclass is not None and self.superclass.methods_ptr is None:
            self.superclass._load_methods()

        for i in range(self.methods_ptr_count.value):
            method = self.methods_ptr[i]
            name = libobjc.method_getName(method).name.decode("utf-8")
            self.instance_method_ptrs[name] = method

            first, *rest = name.split(":")
            # Selectors end in a colon iff the method takes arguments.
            # Because of this, rest must either be empty (method takes no arguments)
            # or the last element must be an empty string (method takes arguments).
            assert not rest or rest[-1] == ""

            try:
                partial = self.partial_methods[first]
            except KeyError:
                if self.superclass is None:
                    super_partial = None
                else:
                    super_partial = self.superclass.partial_methods.get(first)

                partial = self.partial_methods[first] = ObjCPartialMethod(first)
                if super_partial is not None:
                    partial.methods.update(super_partial.methods)

            # order is rest without the dummy "" part
            order = rest[:-1]
            partial.methods[frozenset(rest)] = (method, order)


class ObjCMetaClass(ObjCClass):
    """Python wrapper for an Objective-C metaclass."""

    def __new__(cls, name_or_ptr):
        if isinstance(name_or_ptr, (bytes, str)):
            name = ensure_bytes(name_or_ptr)
            ptr = libobjc.objc_getMetaClass(name)
            if ptr.value is None:
                raise NameError("Objective-C metaclass {} not found".format(name))
        else:
            ptr = cast(name_or_ptr, Class)
            if ptr.value is None:
                raise ValueError("Cannot create ObjCMetaClass for nil pointer")
            elif not object_isClass(ptr) or not libobjc.class_isMetaClass(ptr):
                raise ValueError(
                    "Pointer {} ({:#x}) does not refer to a metaclass".format(
                        ptr, ptr.value
                    )
                )

        return super().__new__(cls, ptr)


register_ctype_for_type(ObjCInstance, objc_id)
register_ctype_for_type(ObjCClass, Class)


NSObject = ObjCClass("NSObject")
NSObject.declare_property("debugDescription")
NSObject.declare_property("description")
NSNumber = ObjCClass("NSNumber")
NSDecimalNumber = ObjCClass("NSDecimalNumber")
NSString = ObjCClass("NSString")
NSString.declare_property("UTF8String")
NSData = ObjCClass("NSData")
NSArray = ObjCClass("NSArray")
NSMutableArray = ObjCClass("NSMutableArray")
NSDictionary = ObjCClass("NSDictionary")
NSMutableDictionary = ObjCClass("NSMutableDictionary")
Protocol = ObjCClass("Protocol")


def py_from_ns(nsobj, *, _auto=False):
    """Convert a Foundation object into an equivalent Python object if possible.

    Currently supported types:

    * ``objc_id``, ``Class``: Wrapped in an ``ObjCInstance`` and converted as below
    * ``NSString``: Converted to ``str``
    * ``NSData``: Converted to ``bytes``
    * ``NSDecimalNumber``: Converted to ``decimal.Decimal``
    * ``NSDictionary``: Converted to ``dict``, with all keys and values converted recursively
    * ``NSArray``: Converted to ``list``, with all elements converted recursively
    * ``NSNumber``: Converted to a ``bool``, ``int`` or ``float`` based on the type of its contents

    Other objects are returned unmodified as an ``ObjCInstance``.
    """

    if isinstance(nsobj, (objc_id, Class)):
        nsobj = ObjCInstance(nsobj)
    if not isinstance(nsobj, ObjCInstance):
        return nsobj

    if nsobj.isKindOfClass(NSDecimalNumber):
        return decimal.Decimal(str(nsobj.descriptionWithLocale(None)))
    elif nsobj.isKindOfClass(NSNumber):
        # Choose the property to access based on the type encoding. The actual conversion is done by ctypes.
        # Signed and unsigned integers are in separate cases to prevent overflow with unsigned long longs.
        objc_type = nsobj.objCType
        if objc_type == b"B":
            return nsobj.boolValue
        elif objc_type in b"csilq":
            return nsobj.longLongValue
        elif objc_type in b"CSILQ":
            return nsobj.unsignedLongLongValue
        elif objc_type in b"fd":
            return nsobj.doubleValue
        else:
            raise TypeError(
                "NSNumber containing unsupported type {!r} cannot be converted to a Python object".format(
                    objc_type
                )
            )
    elif _auto:
        # If py_from_ns is called implicitly to convert an Objective-C method's return value, only the conversions
        # before this branch are performed. If py_from_ns is called explicitly by hand, the additional conversions
        # below this branch are performed as well.
        # _auto is a private kwarg that is only passed when py_from_ns is called implicitly. In that case, we return
        # early and don't attempt any other conversions.
        return nsobj
    elif nsobj.isKindOfClass(NSString):
        return str(nsobj)
    elif nsobj.isKindOfClass(NSData):
        # Despite the name, string_at converts the data at the address to a bytes object, not str.
        return string_at(
            send_message(nsobj, "bytes", restype=POINTER(c_uint8), argtypes=[]),
            nsobj.length,
        )
    elif nsobj.isKindOfClass(NSDictionary):
        return {py_from_ns(k): py_from_ns(v) for k, v in nsobj.items()}
    elif nsobj.isKindOfClass(NSArray):
        return [py_from_ns(o) for o in nsobj]
    else:
        return nsobj


def ns_from_py(pyobj):
    """Convert a Python object into an equivalent Foundation object. The returned object is autoreleased.

    This function is also available under the name ``at``, because its functionality is very similar to that of the
    Objective-C ``@`` operator and literals.

    Currently supported types:

    * ``None``, ``ObjCInstance``: Returned as-is
    * ``enum.Enum``: Replaced by their ``value`` and converted as below
    * ``str``: Converted to ``NSString``
    * ``bytes``: Converted to ``NSData``
    * ``decimal.Decimal``: Converted to ``NSDecimalNumber``
    * ``dict``: Converted to ``NSDictionary``, with all keys and values converted recursively
    * ``list``: Converted to ``NSArray``, with all elements converted recursively
    * ``bool``, ``int``, ``float``: Converted to ``NSNumber``

    Other types cause a ``TypeError``.
    """

    if isinstance(pyobj, enum.Enum):
        pyobj = pyobj.value

    # Many Objective-C method calls here use the convert_result=False kwarg to disable automatic conversion of
    # return values, because otherwise most of the Objective-C objects would be converted back to Python objects.
    if pyobj is None or isinstance(pyobj, ObjCInstance):
        return pyobj
    elif isinstance(pyobj, str):
        return ObjCInstance(
            NSString.stringWithUTF8String_(pyobj.encode("utf-8"), convert_result=False)
        )
    elif isinstance(pyobj, bytes):
        return ObjCInstance(NSData.dataWithBytes(pyobj, length=len(pyobj)))
    elif isinstance(pyobj, decimal.Decimal):
        return ObjCInstance(
            NSDecimalNumber.decimalNumberWithString_(
                pyobj.to_eng_string(), convert_result=False
            )
        )
    elif isinstance(pyobj, dict):
        dikt = NSMutableDictionary.dictionaryWithCapacity(len(pyobj))
        for k, v in pyobj.items():
            dikt.setObject(v, forKey=k)
        return dikt
    elif isinstance(pyobj, list):
        array = NSMutableArray.arrayWithCapacity(len(pyobj))
        for v in pyobj:
            array.addObject(v)
        return array
    elif isinstance(pyobj, bool):
        return ObjCInstance(NSNumber.numberWithBool_(pyobj, convert_result=False))
    elif isinstance(pyobj, int):
        return ObjCInstance(NSNumber.numberWithLong_(pyobj, convert_result=False))
    elif isinstance(pyobj, float):
        return ObjCInstance(NSNumber.numberWithDouble_(pyobj, convert_result=False))
    else:
        raise TypeError(
            "Don't know how to convert a {cls.__module__}.{cls.__qualname__} to a Foundation object".format(
                cls=type(pyobj)
            )
        )


at = ns_from_py


@for_objcclass(Protocol)
class ObjCProtocol(ObjCInstance):
    """Python wrapper for an Objective-C protocol."""

    @property
    def name(self):
        """The name of this protocol."""

        return libobjc.protocol_getName(self).decode("utf-8")

    @property
    def protocols(self):
        """The superprotocols of this protocol."""

        out_count = c_uint()
        protocols_ptr = libobjc.protocol_copyProtocolList(self, byref(out_count))
        return tuple(ObjCProtocol(protocols_ptr[i]) for i in range(out_count.value))

    def __new__(cls, name_or_ptr, bases=None, ns=None):
        if (bases is None) ^ (ns is None):
            raise TypeError("ObjCProtocol arguments 2 and 3 must be given together")

        if bases is None and ns is None:
            if isinstance(name_or_ptr, (bytes, str)):
                name = ensure_bytes(name_or_ptr)
                ptr = libobjc.objc_getProtocol(name)
                if ptr.value is None:
                    raise NameError("Objective-C protocol {} not found".format(name))
            else:
                ptr = cast(name_or_ptr, objc_id)
                if ptr.value is None:
                    raise ValueError("Cannot create ObjCProtocol for nil pointer")
                elif not send_message(
                    ptr, "isKindOfClass:", Protocol, restype=c_bool, argtypes=[objc_id]
                ):
                    raise ValueError(
                        "Pointer {} ({:#x}) does not refer to a protocol".format(
                            ptr, ptr.value
                        )
                    )
        else:
            name = ensure_bytes(name_or_ptr)

            if libobjc.objc_getProtocol(name).value is not None:
                raise RuntimeError(
                    "An Objective-C protocol named {!r} already exists".format(name)
                )

            # Check that all bases are protocols.
            for base in bases:
                if not isinstance(base, ObjCProtocol):
                    raise TypeError(
                        "An Objective-C protocol can only extend ObjCProtocol objects, "
                        "not {cls.__module__}.{cls.__qualname__}".format(cls=type(base))
                    )

            # Allocate the protocol object.
            ptr = libobjc.objc_allocateProtocol(name)
            if ptr is None:
                raise RuntimeError("Protocol allocation failed")

            # Adopt all the protocols.
            for proto in bases:
                libobjc.protocol_addProtocol(ptr, proto)

            # Register all methods and properties.
            for attr, obj in ns.items():
                if hasattr(obj, "protocol_register"):
                    obj.protocol_register(ptr, attr)

            # Register the protocol object
            libobjc.objc_registerProtocol(ptr)

        return super().__new__(cls, ptr)

    def __repr__(self):
        return "<{cls.__module__}.{cls.__qualname__}: {self.name} at {self.ptr.value:#x}>".format(
            cls=type(self), self=self
        )

    def __instancecheck__(self, instance):
        if isinstance(instance, ObjCInstance):
            return bool(instance.conformsToProtocol(self))
        else:
            return False

    def __subclasscheck__(self, subclass):
        if isinstance(subclass, ObjCClass):
            return bool(subclass.conformsToProtocol(self))
        elif isinstance(subclass, ObjCProtocol):
            return bool(libobjc.protocol_conformsToProtocol(subclass, self))
        else:
            raise TypeError(
                "issubclass(X, {self!r}) arg 1 must be an ObjCClass or ObjCProtocol, "
                "not {tp.__module__}.{tp.__qualname__}".format(
                    self=self, tp=type(subclass)
                )
            )


# Need to use a different name to avoid conflict with the NSObject class.
# NSObjectProtocol is also the name that Swift uses when importing the NSObject protocol.
NSObjectProtocol = ObjCProtocol("NSObject")


# Instances of DeallocationObserver are associated with every
# Objective-C object that gets wrapped inside an ObjCInstance.
# Their sole purpose is to watch for when the Objective-C object
# is deallocated, and then remove the object from the dictionary
# of cached ObjCInstance objects kept by the ObjCInstance class.
#
# The methods of the class defined below are decorated with
# rawmethod() instead of method() because DeallocationObservers
# are created inside of ObjCInstance's __new__ method and we have
# to be careful to not create another ObjCInstance here (which
# happens when the usual method decorator turns the self argument
# into an ObjCInstance), or else get trapped in an infinite recursion.

# Try to reuse an existing DeallocationObserver class.
# This allows reloading the module without having to restart
# the interpreter, although any changes to DeallocationObserver
# itself are only applied after a restart of course.
try:
    DeallocationObserver = ObjCClass("DeallocationObserver")
except NameError:

    class DeallocationObserver(NSObject):

        observed_object = objc_ivar(objc_id)

        @objc_rawmethod
        def initWithObject_(self, cmd, anObject):
            self = send_message(self, "init", restype=objc_id, argtypes=[])
            if self is not None:
                set_ivar(self, "observed_object", anObject)
            return self.value

        @objc_rawmethod
        def dealloc(self, cmd) -> None:
            anObject = get_ivar(self, "observed_object")
            ObjCInstance._cached_objects.pop(anObject.value, None)
            send_super(__class__, self, "dealloc", restype=None, argtypes=[])

        @objc_rawmethod
        def finalize(self, cmd) -> None:
            # Called instead of dealloc if using garbage collection.
            # (which would have to be explicitly started with
            # objc_startCollectorThread(), so probably not too much reason
            # to have this here, but I guess it can't hurt.)
            anObject = get_ivar(self, "observed_object")
            ObjCInstance._cached_objects.pop(anObject.value, None)
            send_super(__class__, self, "finalize", restype=None, argtypes=[])


def objc_const(dll, name):
    """Create an ObjCInstance from a global pointer variable in a DLL."""

    return ObjCInstance(objc_id.in_dll(dll, name))


_cfunc_type_block_invoke = CFUNCTYPE(c_void_p, c_void_p)
_cfunc_type_block_dispose = CFUNCTYPE(c_void_p, c_void_p)
_cfunc_type_block_copy = CFUNCTYPE(c_void_p, c_void_p, c_void_p)


class ObjCBlockStruct(Structure):
    _fields_ = [
        ("isa", c_void_p),
        ("flags", c_int),
        ("reserved", c_int),
        ("invoke", _cfunc_type_block_invoke),
        ("descriptor", c_void_p),
    ]


class BlockDescriptor(Structure):
    _fields_ = [
        ("reserved", c_ulong),
        ("size", c_ulong),
        ("copy_helper", _cfunc_type_block_copy),
        ("dispose_helper", _cfunc_type_block_dispose),
        ("signature", c_char_p),
    ]


class BlockLiteral(Structure):
    _fields_ = [
        ("isa", c_void_p),
        ("flags", c_int),
        ("reserved", c_int),
        ("invoke", c_void_p),  # NB: this must be c_void_p due to variadic nature
        ("descriptor", c_void_p),
    ]


def create_block_descriptor_struct(has_helpers, has_signature):
    descriptor_fields = [
        ("reserved", c_ulong),
        ("size", c_ulong),
    ]
    if has_helpers:
        descriptor_fields.extend(
            [
                ("copy_helper", _cfunc_type_block_copy),
                ("dispose_helper", _cfunc_type_block_dispose),
            ]
        )
    if has_signature:
        descriptor_fields.extend(
            [("signature", c_char_p),]
        )
    return type("ObjCBlockDescriptor", (Structure,), {"_fields_": descriptor_fields})


def cast_block_descriptor(block):
    descriptor_struct = create_block_descriptor_struct(
        block.has_helpers, block.has_signature
    )
    return cast(block.struct.contents.descriptor, POINTER(descriptor_struct))


AUTO = object()


class BlockConsts:
    HAS_COPY_DISPOSE = 1 << 25
    HAS_CTOR = 1 << 26
    IS_GLOBAL = 1 << 28
    HAS_STRET = 1 << 29
    HAS_SIGNATURE = 1 << 30


class ObjCBlock:
    def __init__(self, pointer, return_type=AUTO, *arg_types):
        if isinstance(pointer, ObjCInstance):
            pointer = pointer.ptr
        self.pointer = pointer
        self.struct = cast(self.pointer, POINTER(ObjCBlockStruct))
        self.has_helpers = self.struct.contents.flags & BlockConsts.HAS_COPY_DISPOSE
        self.has_signature = self.struct.contents.flags & BlockConsts.HAS_SIGNATURE
        self.descriptor = cast_block_descriptor(self)
        self.signature = (
            self.descriptor.contents.signature if self.has_signature else None
        )
        if return_type is AUTO:
            if arg_types:
                raise ValueError("Cannot use arg_types with return_type AUTO")
            if not self.has_signature:
                raise ValueError("Cannot use AUTO types for blocks without signatures")
            return_type, *arg_types = ctypes_for_method_encoding(self.signature)
        self.struct.contents.invoke.restype = ctype_for_type(return_type)
        self.struct.contents.invoke.argtypes = (objc_id,) + tuple(
            ctype_for_type(arg_type) for arg_type in arg_types
        )

    def __repr__(self):
        representation = "<ObjCBlock@{}".format(hex(addressof(self.pointer)))
        if self.has_helpers:
            representation += ",has_helpers"
        if self.has_signature:
            representation += ",has_signature:" + self.signature
        representation += ">"
        return representation

    def __call__(self, *args):
        return self.struct.contents.invoke(self.pointer, *args)


class ObjCBlockInstance(ObjCInstance):
    def __call__(self, *args):
        return self.block(*args)


_NSConcreteStackBlock = (c_void_p * 32).in_dll(libc, "_NSConcreteStackBlock")


NOTHING = object()


class Block:

    _keep_alive_blocks_ = {}

    def __init__(self, func, restype=NOTHING, *arg_types):
        if not callable(func):
            raise TypeError("Blocks must be callable")

        self.func = func

        argspec = inspect.getfullargspec(inspect.unwrap(func))

        if restype is NOTHING:
            try:
                restype = argspec.annotations["return"]
            except KeyError:
                raise ValueError(
                    "Block callables must be fully annotated or an explicit "
                    "return type must be specified."
                )

        if not arg_types:
            try:
                arg_types = list(
                    argspec.annotations[varname] for varname in argspec.args
                )
            except KeyError:
                raise ValueError(
                    "Block callables must be fully annotated or explicit "
                    "argument types must be specified."
                )
        signature = tuple(ctype_for_type(tp) for tp in arg_types)

        restype = ctype_for_type(restype)

        self.cfunc_type = CFUNCTYPE(restype, c_void_p, *signature)

        self.literal = BlockLiteral()
        self.literal.isa = addressof(_NSConcreteStackBlock)
        self.literal.flags = (
            BlockConsts.HAS_STRET
            | BlockConsts.HAS_SIGNATURE
            | BlockConsts.HAS_COPY_DISPOSE
        )
        self.literal.reserved = 0
        self.cfunc_wrapper = self.cfunc_type(self.wrapper)
        self.literal.invoke = cast(self.cfunc_wrapper, c_void_p)
        self.descriptor = BlockDescriptor()
        self.descriptor.reserved = 0
        self.descriptor.size = sizeof(BlockLiteral)

        self.cfunc_copy_helper = _cfunc_type_block_copy(self.copy_helper)
        self.cfunc_dispose_helper = _cfunc_type_block_dispose(self.dispose_helper)
        self.descriptor.copy_helper = self.cfunc_copy_helper
        self.descriptor.dispose_helper = self.cfunc_dispose_helper

        self.descriptor.signature = (
            encoding_for_ctype(restype)
            + b"@?"
            + b"".join(encoding_for_ctype(arg) for arg in signature)
        )
        self.literal.descriptor = cast(byref(self.descriptor), c_void_p)
        self.block = cast(byref(self.literal), objc_block)
        self._as_parameter_ = self.block

    def wrapper(self, instance, *args):
        _args = ()
        for arg in args:
            if isinstance(arg, objc_id):
                _args += (ObjCInstance(arg),)
            else:
                _args += (arg,)

        return self.func(*_args)

    def dispose_helper(self, dst):
        Block._keep_alive_blocks_.pop(dst, None)

    def copy_helper(self, dst, src):
        # Update our keepalive table because objc just informed us that it
        # took ownership of a block/copied a block we are concerned with.
        # Note that sometime later we can expect calls to dispose_helper
        # for each of the 'dst' blocks objc told us about, but until then we
        # need to make sure the python code they reference stays in memory,
        # so basically put self in a class variable dictionary so it is
        # guaranteed to stay around until dispose_helper tells us they are all
        # gone.
        Block._keep_alive_blocks_[dst] = self
