import collections.abc
import decimal
import enum
import inspect
import weakref
from ctypes import (
    CFUNCTYPE, POINTER, Array, Structure, Union, addressof, byref, c_bool, c_char_p, c_int, c_uint,
    c_uint8, c_ulong, c_void_p, cast, sizeof, string_at, py_object,
)

from .types import (
    compound_value_for_sequence, ctype_for_type, ctypes_for_method_encoding, encoding_for_ctype,
    register_ctype_for_type
)
from .runtime import (
    Class, SEL, add_ivar, add_method, ensure_bytes, get_class, get_ivar, libc, libobjc, objc_block, objc_id,
    objc_property_attribute_t, object_isClass, set_ivar, send_message, send_super,
)

__all__ = [
    'Block',
    'NSArray',
    'NSData',
    'NSDecimalNumber',
    'NSDictionary',
    'NSMutableArray',
    'NSMutableDictionary',
    'NSNumber',
    'NSObject',
    'NSObjectProtocol',
    'NSString',
    'ObjCBlock',
    'ObjCClass',
    'ObjCInstance',
    'ObjCMetaClass',
    'ObjCProtocol',
    'Protocol',
    'at',
    'for_objcclass',
    'get_type_for_objcclass_map',
    'ns_from_py',
    'objc_classmethod',
    'objc_const',
    'objc_ivar',
    'objc_method',
    'objc_property',
    'objc_rawmethod',
    'py_from_ns',
    'register_type_for_objcclass',
    'type_for_objcclass',
    'unregister_type_for_objcclass',
]

# Dictionary to keep references to Python objects which are stored in declared
# properties or dynamically created attributes of Objective-C objects. This ensures that
# the Python objects are not destroyed if they are otherwise no Python references left.
_keep_alive_objects = {}


def encoding_from_annotation(f, offset=1):
    argspec = inspect.getfullargspec(inspect.unwrap(f))

    encoding = [argspec.annotations.get('return', ObjCInstance), ObjCInstance, SEL]

    for varname in argspec.args[offset:]:
        encoding.append(argspec.annotations.get(varname, ObjCInstance))

    return encoding


class ObjCMethod(object):
    """An unbound Objective-C method. This is Rubicon's high-level equivalent of :class:`~rubicon.objc.runtime.Method`.

    :class:`ObjCMethod` objects normally don't need to be used directly. To call a method on an Objective-C object,
    you should use the method call syntax supported by :class:`ObjCInstance`,
    or the :func:`~rubicon.objc.runtime.send_message` function.

    .. note::

        This is *not* the same class as the one used for *bound* Objective-C methods,
        as returned from :meth:`ObjCInstance.__getattr__`. Currently, Rubicon doesn't provide any documented way
        to get an unbound :class:`ObjCMethod` object for an instance method of an :class:`ObjCClass`.
    """

    def __init__(self, method):
        """The constructor takes a :class:`~rubicon.objc.runtime.Method` object,
        whose information is used to create an :class:`ObjCMethod`.
        This can be used to call or introspect a :class:`~rubicon.objc.runtime.Method` pointer
        received from the Objective-C runtime.
        """

        self.selector = libobjc.method_getName(method)
        self.name = self.selector.name
        self.encoding = libobjc.method_getTypeEncoding(method)
        self.restype, *self.imp_argtypes = ctypes_for_method_encoding(self.encoding)
        assert self.imp_argtypes[:2] == [objc_id, SEL]
        self.method_argtypes = self.imp_argtypes[2:]

    def __repr__(self):
        return "<ObjCMethod: %s %s>" % (self.name, self.encoding)

    def __call__(self, receiver, *args, convert_args=True, convert_result=True):
        """Call the method on an object with the given arguments.

        The passed arguments are automatically converted to the expected argument types as needed:

        * :class:`enum.Enum` objects are replaced by their :attr:`~enum.Enum.value` before further conversion
        * For parameters that expect a block, Python callables are converted to :class:`Block`\\s
        * For parameters that expect an Objective-C object, Python objects are converted using :func:`ns_from_py`
        * For parameters that expect a C structure, Python sequences are converted
          using :func:`~rubicon.objc.types.compound_value_for_sequence`.
        * Finally, :mod:`ctypes` applies its normal function argument conversions.

        The above argument conversions (except those performed by :mod:`ctypes`) can be disabled
        by setting the ``convert_args`` keyword argument to ``False``.

        If the method returns an Objective-C object, it is automatically converted to an :class:`ObjCInstance`.
        This conversion can be disabled by setting the ``convert_result`` keyword argument to ``False``,
        in which case the object is returned as a raw :class:`~rubicon.objc.runtime.objc_id` value.

        The ``_cmd`` selector argument does *not* need to be passed in manually ---
        the method's :attr:`selector` is automatically added between the receiver and the method arguments.
        """

        if len(args) != len(self.method_argtypes):
            raise TypeError(
                'Method {} takes {} arguments, but got {} arguments'
                .format(self.name, len(args), len(self.method_argtypes))
            )

        if convert_args:
            converted_args = []
            for argtype, arg in zip(self.method_argtypes, args):
                if isinstance(arg, enum.Enum):
                    # Convert Python enum objects to their values
                    arg = arg.value

                if issubclass(argtype, objc_block):
                    if arg is None:
                        # allow for 'nil' block args, which some objc methods accept
                        arg = ns_from_py(arg)
                    elif (callable(arg)
                          and not isinstance(arg, Block)):  # <-- guard against someone someday making Block callable
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
                elif isinstance(arg, collections.abc.Sequence) and issubclass(argtype, (Structure, Array)):
                    arg = compound_value_for_sequence(arg, argtype)

                converted_args.append(arg)
        else:
            converted_args = args

        result = send_message(
            receiver, self.selector, *converted_args,
            restype=self.restype, argtypes=self.method_argtypes,
        )

        if not convert_result:
            return result

        # Convert result to python type if it is a instance or class pointer.
        if self.restype is not None and issubclass(self.restype, objc_id):
            result = ObjCInstance(result)

        # Mark for release if we acquire ownership of an object. Do not autorelease here because
        # we might retain a Python reference while the Obj-C reference goes out of scope.
        if self.name.startswith((b'alloc', b'new', b'copy', b'mutableCopy')):
            result._needs_release = True

        return result


class ObjCPartialMethod(object):
    _sentinel = object()

    def __init__(self, name_start):
        super().__init__()

        self.name_start = name_start
        self.methods = {}  # Initialized in ObjCClass._load_methods

    def __repr__(self):
        return "{cls.__module__}.{cls.__qualname__}({self.name_start!r})".format(cls=type(self), self=self)

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
            name, order = self.methods[rest]
        except KeyError:
            raise ValueError(
                "No method was found starting with {!r} and with keywords {}\nKnown keywords are:\n{}"
                .format(self.name_start, set(kwargs), "\n".join(repr(keywords) for keywords in self.methods))
            )

        meth = receiver.objc_class._cache_method(name)
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
        return '{cls.__module__}.{cls.__qualname__}({self.method}, {self.receiver})'.format(
            cls=type(self), self=self)

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
            new_args.append(ObjCInstance(a))
        else:
            new_args.append(a)
    return new_args


class objc_method(object):
    """Exposes the decorated method as an Objective-C instance method in a custom class or protocol.

    In a custom Objective-C class, decorating a method with :func:`@objc_method <objc_method>`
    makes it available to Objective-C: a corresponding Objective-C method is created in the new Objective-C class,
    whose implementation calls the decorated Python method. The Python method receives all arguments
    (including ``self``) from the Objective-C method call, and its return value is passed back to Objective-C.

    In a custom Objective-C protocol, the behavior is similar, but the method body is ignored,
    since Objective-C protocol methods have no implementations. By convention, the method body in this case
    should be empty (``pass``). (Since the method is never called, you could put any other code there as well,
    but doing so is misleading and discouraged.)
    """

    def __init__(self, py_method):
        super().__init__()

        self.py_method = py_method
        self.encoding = encoding_from_annotation(py_method)

    def __call__(self, objc_self, objc_cmd, *args):
        py_self = ObjCInstance(objc_self)
        args = convert_method_arguments(self.encoding, args)
        result = self.py_method(py_self, *args)
        if self.encoding[0] is not None and issubclass(self.encoding[0], (objc_id, ObjCInstance)):
            result = ns_from_py(result)
            if result is not None:
                result = result.ptr
        if isinstance(result, c_void_p):
            return result.value
        else:
            return result

    def class_register(self, class_ptr, attr_name):
        name = attr_name.replace("_", ":")
        add_method(class_ptr, name, self, self.encoding)

    def protocol_register(self, proto_ptr, attr_name):
        name = attr_name.replace('_', ':')
        types = b''.join(encoding_for_ctype(ctype_for_type(tp)) for tp in self.encoding)
        libobjc.protocol_addMethodDescription(proto_ptr, SEL(name), types, True, True)


class objc_classmethod(object):
    """Exposes the decorated method as an Objective-C class method in a custom class or protocol.

    This decorator behaves exactly like :func:`@objc_method <objc_method>`, except that the decorated method
    becomes a class method, so it is exposed on the Objective-C class rather than its instances.
    """

    def __init__(self, py_method):
        super().__init__()

        self.py_method = py_method
        self.encoding = encoding_from_annotation(py_method)

    def __call__(self, objc_cls, objc_cmd, *args):
        py_cls = ObjCClass(objc_cls)
        args = convert_method_arguments(self.encoding, args)
        result = self.py_method(py_cls, *args)
        if self.encoding[0] is not None and issubclass(self.encoding[0], (objc_id, ObjCInstance)):
            result = ns_from_py(result)
            if result is not None:
                result = result.ptr
        if isinstance(result, c_void_p):
            return result.value
        else:
            return result

    def class_register(self, class_ptr, attr_name):
        name = attr_name.replace("_", ":")
        add_method(libobjc.object_getClass(class_ptr), name, self, self.encoding)

    def protocol_register(self, proto_ptr, attr_name):
        name = attr_name.replace('_', ':')
        types = b''.join(encoding_for_ctype(ctype_for_type(tp)) for tp in self.encoding)
        libobjc.protocol_addMethodDescription(proto_ptr, SEL(name), types, True, False)


class objc_ivar(object):
    """Defines an ivar in a custom Objective-C class.

    If you want to store additional data on a custom Objective-C class, it is recommended to use properties
    (:func:`objc_property`) instead of ivars. Properties are a more modern and high-level Objective-C feature,
    which automatically deal with reference counting for objects, and creation of getters and setters.

    The ivar type may be any :mod:`ctypes` type.

    Unlike properties, the contents of an ivar cannot be accessed or modified using Python attribute syntax.
    Instead, the :func:`get_ivar` and :func:`set_ivar` functions need to be used.
    """

    def __init__(self, vartype):
        self.vartype = vartype

    def class_register(self, class_ptr, attr_name):
        return add_ivar(class_ptr, attr_name, self.vartype)

    def protocol_register(self, proto_ptr, attr_name):
        raise TypeError('Objective-C protocols cannot have ivars')


class objc_property(object):
    """Defines a property in a custom Objective-C class or protocol.

    This class should be called in the body of an Objective-C subclass or protocol, for example:

    .. code-block:: python

        class MySubclass(NSObject):
            counter = objc_property(NSInteger)

    The property type may be any :mod:`ctypes` type, as well as any of the Python types
    accepted by :func:`~rubicon.objc.types.ctype_for_type`.

    Defining a property automatically defines a corresponding getter and setter.
    Following standard Objective-C naming conventions, for a property ``name`` the getter is called ``name``
    and the setter is called ``setName:``.

    In a custom Objective-C class, implementations for the getter and setter are also generated,
    which store the property's value in an ivar called ``_name``. If the property has an object type,
    the generated setter keeps the stored object retained, and releases it when it is replaced.

    In a custom Objective-C protocol, only the metadata for the property is generated.

    If ``weak`` is ``True``, the property will be created as a weak property. When assigning an object to it,
    the reference count of the object will not be increased. When the object is deallocated, the property
    value is set to None. Weak properties are only supported for Objective-C or Python object types.
    """

    def __init__(self, vartype=objc_id, weak=False):
        super().__init__()

        self.vartype = ctype_for_type(vartype)

        self.weak = weak

        self._is_py_object = issubclass(self.vartype, py_object)
        self._is_objc_object = issubclass(self.vartype, objc_id)

        # Weakly referenced Python objects are still stored in strong ivars.
        # Check here if we need a weak or strong ivar.
        self._ivar_weak = self.weak and not self._is_py_object

        if self.weak and not (self._is_py_object or self._is_objc_object):
            raise TypeError(
                "Incompatible type for ivar {!r}: Weak properties are only supported "
                "for Objective-C or Python object types".format(vartype)
            )

    def _get_property_attributes(self):
        attrs = [
            objc_property_attribute_t(b'T', encoding_for_ctype(self.vartype)),  # Type: vartype
        ]
        if self._is_objc_object:
            reference = b'W' if self.weak else b'&'
            attrs.append(objc_property_attribute_t(reference, b''))
        return (objc_property_attribute_t * len(attrs))(*attrs)

    def class_register(self, class_ptr, attr_name):

        ivar_name = '_' + attr_name

        add_ivar(class_ptr, ivar_name, self.vartype)

        # Implementation note:
        # 1. Objective-C objects are stored as strong or weak references in the ivar if the property was declared as
        #    strong or weak, respectively. In case of strong properties, we retain the object when storing it in the
        #    ivar and release it when the ivar is changed.
        # 2. Python objects are wrapped as `ctypes.py_object` which are then always stored as a strong reference in
        #    the ivar. Since this does not increase the reference count of the Python object itself, we keep a
        #    reference to it in `_keep_alive_objects`. For weak properties, we store a Python `wearef` to the object
        #    instead. This weakref is similarly kept alive.

        def _objc_getter(objc_self, _cmd):
            value = get_ivar(objc_self, ivar_name, weak=self._ivar_weak)

            # ctypes complains when a callback returns a "boxed" primitive type, so we have to manually unbox it.
            # If the data object has a value attribute and is not a structure or union, assume that it is
            # a primitive and unbox it.
            if not isinstance(value, (Structure, Union)):
                try:
                    value = value.value
                except AttributeError:
                    pass

            if self.weak and self._is_py_object:
                # Unpack the Python weakref.
                value = value()

            return value

        def _objc_setter(objc_self, _cmd, new_value):

            if self._is_py_object and self.weak:
                # Don't store the object itself but only a Python weakref.
                new_value = weakref.ref(new_value)

            if not isinstance(new_value, self.vartype):
                # If vartype is a primitive, then new_value may be unboxed. If that is the case, box it manually.
                new_value = self.vartype(new_value)

            if self._is_objc_object and not self.weak:
                # If vartype is objc_id, retrieve the old object stored in the ivar to release it later.
                old_value = get_ivar(objc_self, ivar_name, weak=self.weak)

                if new_value.value == old_value.value:
                    # Old and new value are the same, nothing to do.
                    return

            set_ivar(objc_self, ivar_name, new_value, weak=self._ivar_weak)

            # Perform reference management.

            if self._is_objc_object and not self.weak:
                if old_value:
                    # If the old value is a non-null Objective-C object, release it.
                    send_message(old_value, 'release', restype=None, argtypes=[])

                if new_value:
                    # Retain the object on the Objective-C side.
                    send_message(new_value, 'retain', restype=objc_id, argtypes=[])

            elif self._is_py_object:
                # Retain the Python object in dictionary, this replaces any previous entry for this property.
                _keep_alive_objects[(objc_self.value, self)] = new_value.value

        setter_name = 'set' + attr_name[0].upper() + attr_name[1:] + ':'

        add_method(
            class_ptr, attr_name, _objc_getter,
            [self.vartype, ObjCInstance, SEL],
        )
        add_method(
            class_ptr, setter_name, _objc_setter,
            [None, ObjCInstance, SEL, self.vartype],
        )

        attrs = self._get_property_attributes()
        libobjc.class_addProperty(class_ptr, ensure_bytes(attr_name), attrs, len(attrs))

    def dealloc_callback(self, objc_self, attr_name):

        ivar_name = '_' + attr_name

        if self._ivar_weak:
            # Clean up weak reference.
            set_ivar(objc_self, ivar_name, self.vartype(None), weak=True)
        elif self._is_objc_object:
            # If the old value is a non-null object, release it. There is no need to set the actual ivar to nil.
            old_value = get_ivar(objc_self, ivar_name, weak=self.weak)
            send_message(old_value, 'release', restype=None, argtypes=[])

        # Remove any Python objects that are kept alive.
        _keep_alive_objects.pop((objc_self.value, self), None)

    def protocol_register(self, proto_ptr, attr_name):
        attrs = self._get_property_attributes()
        libobjc.protocol_addProperty(proto_ptr, ensure_bytes(attr_name), attrs, len(attrs), True, True)


class objc_rawmethod(object):
    """Exposes the decorated method as an Objective-C instance method in a custom class,
    with fewer convenience features than :func:`objc_method`.

    This decorator behaves similarly to :func:`@objc_method <objc_method>`. However, unlike with :func:`objc_method`,
    no automatic conversions are performed (aside from those by :mod:`ctypes`).
    This means that all parameter and return types must be provided as :mod:`ctypes` types
    (no :func:`~rubicon.objc.types.ctype_for_type` conversion is performed), all arguments are passed in their raw form
    as received from :mod:`ctypes`, and the return value must be understood by :mod:`ctypes`.

    In addition, the implicit ``_cmd`` parameter is exposed to the Python method, which is not the case
    when using :func:`objc_method`. This means that the decorated Python method must always have
    an additional ``_cmd`` parameter after ``self``; if it is missing, there will be errors at runtime
    due to mismatched argument counts. Like ``self``, ``_cmd`` never needs to be annotated,
    and any annotations on it are ignored.
    """

    def __init__(self, py_method):
        super().__init__()

        self.py_method = py_method
        self.encoding = encoding_from_annotation(py_method, offset=2)

    def __call__(self, *args, **kwargs):
        return self.py_method(*args, **kwargs)

    def class_register(self, class_ptr, attr_name):
        name = attr_name.replace("_", ":")
        add_method(class_ptr, name, self, self.encoding)

    def protocol_register(self, proto_ptr, attr_name):
        raise TypeError('Protocols cannot have method implementations, use objc_method instead of objc_rawmethod')


_type_for_objcclass_map = {}


def type_for_objcclass(objcclass):
    """Look up the :class:`ObjCInstance` subclass used to represent instances of the given Objective-C class in Python.

    If the exact Objective-C class is not registered, each superclass is also checked,
    defaulting to :class:`ObjCInstance` if none of the classes in the superclass chain is registered.
    Afterwards, all searched superclasses are registered for the :class:`ObjCInstance` subclass that was found.
    (This speeds up future lookups, and ensures that previously computed mappings are not changed
    by unrelated registrations.)

    This method is mainly intended for internal use by Rubicon, but is exposed in the public API for completeness.
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
    """Register a conversion from an Objective-C class to an :class:`ObjCInstance` subclass.

    After a call of this function, when Rubicon wraps an Objective-C object that is an instance of ``objcclass``
    (or a subclass), the Python object will have the class ``pytype`` rather than :class:`ObjCInstance`.
    See :func:`type_for_objcclass` for a full description of the lookup process.

    .. warning::

        This function should only be called if no instances of ``objcclass`` (or a subclass)
        have been wrapped by Rubicon yet. If the function is called later, it will not fully take effect:
        the types of existing instances do not change, and mappings for subclasses of ``objcclass`` are not updated.
    """

    if isinstance(objcclass, ObjCClass):
        objcclass = objcclass.ptr

    _type_for_objcclass_map[objcclass.value] = pytype


def unregister_type_for_objcclass(objcclass):
    """Unregister a conversion from an Objective-C class to an :class:`ObjCInstance` subclass.

    .. warning::

        This function should only be called if no instances of ``objcclass`` (or a subclass)
        have been wrapped by Rubicon yet. If the function is called later, it will not fully take effect:
        the types of existing instances do not change, and mappings for subclasses of ``objcclass`` are not removed.
    """

    if isinstance(objcclass, ObjCClass):
        objcclass = objcclass.ptr

    del _type_for_objcclass_map[objcclass.value]


def get_type_for_objcclass_map():
    """Get a copy of all currently registered :class:`ObjCInstance` subclasses as a mapping.

    Keys are Objective-C class addresses as :class:`int`\\s.
    """

    return dict(_type_for_objcclass_map)


def for_objcclass(objcclass):
    """Decorator for registering a conversion from an Objective-C class to an :class:`ObjCInstance` subclass.

    This is equivalent to calling :func:`register_type_for_objcclass` on the decorated class.
    """

    def _for_objcclass(pytype):
        register_type_for_objcclass(pytype, objcclass)
        return pytype

    return _for_objcclass


class ObjCInstance(object):
    """Python wrapper for an Objective-C instance."""

    # Cache dictionary containing every currently existing ObjCInstance object,
    # with the key being the memory address (as an integer) of the Objective-C object that it wraps.
    # Because this is a weak value dictionary,
    # entries are automatically removed if the ObjCInstance is no longer referenced from Python.
    # (The object may still have references in Objective-C,
    # and a new ObjCInstance might be created for it if it is wrapped again later.)
    _cached_objects = weakref.WeakValueDictionary()

    @property
    def objc_class(self):
        """The Objective-C object's class, as an :class:`ObjCClass`."""

        # This property is used inside __getattr__, so any attribute accesses must be done through
        # super(...).__getattribute__ to prevent infinite recursion.
        try:
            return super(ObjCInstance, type(self)).__getattribute__(self, "_objc_class")
        except AttributeError:
            # This assumes that objects never change their class after they are seen by Rubicon.
            # Technically this might not always be true, because the Objective-C runtime provides a function
            # object_setClass that can change an object's class after creation, and some code also manipulates objects'
            # isa pointers directly (although the latter is no longer officially supported by Apple).
            # This is only extremely rarely done in practice though, and then usually only during object
            # creation/initialization, so it's basically safe to assume that an object's class will never change
            # after it's been wrapped in an ObjCInstance.
            super(ObjCInstance, type(self)).__setattr__(self, "_objc_class", ObjCClass(libobjc.object_getClass(self)))
            return super(ObjCInstance, type(self)).__getattribute__(self, "_objc_class")

    @staticmethod
    def _associated_attr_key_for_name(name):
        return SEL("rubicon.objc.py_attr.{}".format(name))

    def __new__(cls, object_ptr, _name=None, _bases=None, _ns=None):
        """The constructor accepts an :class:`~rubicon.objc.runtime.objc_id` or anything that can be cast to one,
        such as a :class:`~ctypes.c_void_p`, or an existing :class:`ObjCInstance`.

        :class:`ObjCInstance` objects are cached --- this means that for every Objective-C object
        there can be at most one :class:`ObjCInstance` object at any time. Rubicon will automatically create
        new :class:`ObjCInstance`\\s or return existing ones as needed.

        The returned object's Python class is not always exactly :class:`ObjCInstance`. For example,
        if the passed pointer refers to a class or a metaclass, an instance of :class:`ObjCClass`
        or :class:`ObjCMetaClass` is returned as appropriate. Additional custom :class:`ObjCInstance` subclasses
        may be defined and registered using :func:`register_type_for_objcclass`.
        Creating an :class:`ObjCInstance` from a ``nil`` pointer returns ``None``.

        Rubicon currently does not perform any automatic memory management on the Objective-C object
        wrapped in an :class:`ObjCInstance`. It is the user's responsibility to ``retain`` and ``release``
        wrapped objects as needed, like in Objective-C code without automatic reference counting.
        """

        # Make sure that object_ptr is wrapped in an objc_id.
        if not isinstance(object_ptr, objc_id):
            object_ptr = cast(object_ptr, objc_id)

        # If given a nil pointer, return None.
        if not object_ptr.value:
            return None

        # If an ObjCInstance already exists for the Objective-C object,
        # reuse it instead of creating a second ObjCInstance for the same object.
        try:
            return cls._cached_objects[object_ptr.value]
        except KeyError:
            pass

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
        super(ObjCInstance, type(self)).__setattr__(self, "_needs_release", False)
        if isinstance(object_ptr, objc_block):
            super(ObjCInstance, type(self)).__setattr__(self, "block", ObjCBlock(object_ptr))
        # Store new object in the dictionary of cached objects, keyed
        # by the (integer) memory address pointed to by the object_ptr.
        cls._cached_objects[object_ptr.value] = self

        return self

    def release(self):
        """
        Manually decrement the reference count of the corresponding objc object

        The objc object is sent a dealloc message when its reference count reaches 0. Calling
        this method manually should not be necessary, unless the object was explicitly
        ``retain``\\ed before. Objects returned from ``.alloc().init...(...)`` and similar calls
        are released automatically by Rubicon when the corresponding Python object is deallocated.
        """
        self._needs_release = False
        send_message(self, "release", restype=objc_id, argtypes=[])

    def autorelease(self):
        """
        Decrements the receiver’s reference count at the end of the current autorelease pool block

        The objc object is sent a dealloc message when its reference count reaches 0. If called,
        the object will not be released when the Python object is deallocated.
        """
        self._needs_release = False
        result = send_message(self, "autorelease", restype=objc_id, argtypes=[])
        return ObjCInstance(result)

    def __del__(self):
        """
        Release the corresponding objc instance if we own it, i.e., if it was returned by
        by a method starting with 'alloc', 'new', 'copy', or 'mutableCopy' and it wasn't
        already explicitly released by calling :meth:`release` or :meth:`autorelease`.
        """

        if self._needs_release:
            send_message(self, "release", restype=objc_id, argtypes=[])

    def __str__(self):
        """Get a human-readable representation of ``self``.

        By default, ``self.description`` converted to a Python string is returned.
        If ``self.description`` is ``nil``, ``self.debugDescription`` converted to a Python is returned instead.
        If that is also ``nil``, ``repr(self)`` is returned as a fallback.
        """

        desc = self.description
        if desc is not None:
            return str(desc)

        desc = self.debugDescription
        if desc is not None:
            return str(desc)

        return repr(self)

    def __repr__(self):
        """Get a debugging representation of ``self``, which includes the Objective-C object's address, class,
        and ``debugDescription``.
        """

        return "<%s.%s %#x: %s at %#x: %s>" % (
            type(self).__module__,
            type(self).__qualname__,
            id(self),
            self.objc_class.name,
            self.ptr.value,
            self.debugDescription,
        )

    def __getattr__(self, name):
        """Allows accessing Objective-C properties and methods using Python attribute syntax.

        If ``self`` has a Python attribute with the given name, its value is returned.

        If there is an Objective-C property with the given name, its value is returned using its getter method.
        An attribute is considered a property if any of the following are true:

        * A property with the name is present on the class (i. e. declared using ``@property`` in the source code)
        * There is both a getter and setter method for the name
        * The name has been declared as a property using :meth:`ObjCClass.declare_property`

        Otherwise, a method matching the given name is looked up. :class:`ObjCInstance` understands two syntaxes
        for calling Objective-C methods:

        * "Flat" syntax: the Objective-C method name is spelled out in the attribute name,
          with all colons replaced with underscores, and all arguments are passed as positional arguments.
          For example, the Objective-C method call ``[self initWithWidth:w height:h]``
          translates to ``self.initWithWidth_height_(w, h)``.
        * "Interleaved" syntax: the Objective-C method name is split up between the attribute name
          and the keyword arguments passed to the returned method. For example, the Objective-C method call
          ``[self initWithRed:r green:g blue:b]`` translates to ``self.initWithRed(r, green=g, blue=b)``.

        The "interleaved" syntax is usually preferred, since it looks more similar to normal Objective-C syntax.
        However, the "flat" syntax is also fully supported. Certain method names require the "flat" syntax,
        for example if two arguments have the same label (e. g. ``performSelector:withObject:withObject:``),
        which is not supported by Python's keyword argument syntax.

        .. warning::

            The "interleaved" syntax currently ignores the ordering of its keyword arguments.
            However, in the interest of readability, the keyword arguments should always be passed
            in the same order as they appear in the method name.

            This also means that two methods whose names which differ only in the ordering of their keywords
            will conflict with each other, and can only be called reliably using "flat" syntax.

            As of Python 3.6, the order of keyword arguments passed to functions is preserved (:pep:`468`).
            In the future, once Rubicon requires Python 3.6 or newer, "interleaved" method calls
            will respect keyword argument order. This will fix the kind of conflict described above,
            but will also disallow specifying the keyword arguments out of order.
        """

        # Search for named instance method in the class object and if it
        # exists, return callable object with self as hidden argument.
        # Note: you should give self and not self.ptr as a parameter to
        # ObjCBoundMethod, so that it will be able to keep the ObjCInstance
        # alive for chained calls like MyClass.alloc().init() where the
        # object created by alloc() is not assigned to a variable.

        # If there's a property with this name; return the value directly.
        # If the name ends with _, we can shortcut this step, because it's
        # clear that we're dealing with a method call.
        if not name.endswith('_'):
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

        if method is None or set(method.methods) == {frozenset()}:
            # Find a method whose full name matches the given name if no partial method was found,
            # or the partial method can only resolve to a single method that takes no arguments.
            # The latter case avoids returning partial methods in cases where a regular method works just as well.
            method = self.objc_class._cache_method(name.replace("_", ":"))

        if method:
            return ObjCBoundMethod(method, self)

        # Check if the attribute name corresponds to an instance attribute defined at
        # runtime from Python. Return it if yes, raise an AttributeError otherwise.
        key = self._associated_attr_key_for_name(name)
        pyo_wrapper = libobjc.objc_getAssociatedObject(self, key)

        if pyo_wrapper.value is None:
            raise AttributeError('%s.%s %s has no attribute %s' % (
                type(self).__module__, type(self).__qualname__, self.objc_class.name, name)
            )
        address = get_ivar(pyo_wrapper, "wrapped_pointer")
        pyo = cast(address.value, py_object)

        return pyo.value

    def __setattr__(self, name, value):
        """Allows modifying Objective-C properties using Python syntax.

        If ``self`` has a Python attribute with the given name, it is set. Otherwise, the name should refer
        to an Objective-C property, whose setter method is called with ``value``.
        """

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

                # Wrap the Python object in a WrappedPyObject instance.
                # A reference will be retained as long as the WrappedPyObject is alive.

                wrapper = send_message(
                    send_message(get_class('WrappedPyObject'), 'alloc',
                                 restype=objc_id, argtypes=[]),
                    'initWithObjectId:', id(value), restype=objc_id, argtypes=[objc_id]
                )

                # Set the Python value as an associated object. This will release
                # any previous wrapper object with the same key.
                key = self._associated_attr_key_for_name(name)
                libobjc.objc_setAssociatedObject(self, key, wrapper, 0x301)

                # Release the wrapper object, it will be retained by the association.
                send_message(wrapper, 'release', restype=objc_id, argtypes=[])

    def __delattr__(self, name):
        if name in self.__dict__:
            # For attributes already in __dict__, use the default __delattr__.
            super(ObjCInstance, type(self)).__delattr__(self, name)
        else:
            key = self._associated_attr_key_for_name(name)
            # Check for instance attributes defined at runtime.
            pyo_wrapper = libobjc.objc_getAssociatedObject(self, key)
            if pyo_wrapper.value is None:
                raise AttributeError('%s.%s %s has no attribute %s' % (
                    type(self).__module__, type(self).__qualname__, self.objc_class.name, name)
                )
            # If set, clear the instance attribute / associated object.
            libobjc.objc_setAssociatedObject(self, key, None, 0x301)


# The inheritance order is important here.
# type must come after ObjCInstance, so super() refers to ObjCInstance.
# This allows the ObjCInstance constructor to receive the class pointer
# as well as the name, bases, attrs arguments.
# The other way around this would not be possible, because then
# the type constructor would be called before ObjCInstance's, and there
# would be no opportunity to pass extra arguments.
class ObjCClass(ObjCInstance, type):
    """Python wrapper for an Objective-C class.

    :class:`ObjCClass` is a subclass of :class:`ObjCInstance` and supports the same syntaxes for calling methods
    and accessing properties.
    """

    @property
    def superclass(self):
        """The superclass of this class, or ``None`` if this is a root class (such as :class:`NSObject`)."""

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
            raise ValueError("Pointer {} ({:#x}) does not refer to a class".format(ptr, ptr.value))
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
            raise ValueError('An Objective-C class must have exactly one base class, not {}'.format(len(bases)))

        # Check that the superclass is an ObjCClass.
        if not isinstance(superclass, ObjCClass):
            raise TypeError(
                'The superclass of an Objective-C class must be an ObjCClass, '
                'not a {cls.__module__}.{cls.__qualname__}'
                .format(cls=type(superclass))
            )

        # Check that all protocols are ObjCProtocols, and that there are no duplicates.
        for proto in protocols:
            if not isinstance(proto, ObjCProtocol):
                raise TypeError(
                    'The protocols list of an Objective-C class must contain ObjCProtocol objects, '
                    'not {cls.__module__}.{cls.__qualname__}'
                    .format(cls=type(proto))
                )
            elif protocols.count(proto) > 1:
                raise ValueError('Protocol {} is adopted more than once'.format(proto.name))

        # Create the ObjC class description
        ptr = libobjc.objc_allocateClassPair(superclass, name, 0)
        if ptr is None:
            raise RuntimeError('Class pair allocation failed')

        # Adopt all the protocols.
        for proto in protocols:
            if not libobjc.class_addProtocol(ptr, proto):
                raise RuntimeError('Failed to adopt protocol {}'.format(proto.name))

        # Register all methods, properties, ivars, etc.
        for attr_name, obj in attrs.items():
            if attr_name != "dealloc":
                try:
                    class_register = obj.class_register
                except AttributeError:
                    pass
                else:
                    class_register(ptr, attr_name)

        # Register any user-defined dealloc method. We treat dealloc differently to
        # inject our own cleanup code for properties, ivars, etc.

        user_dealloc = attrs.get("dealloc", None)

        def _new_delloc(objc_self, _cmd):

            # Invoke user-defined dealloc.
            if user_dealloc:
                user_dealloc(objc_self, _cmd)

            # Invoke dealloc callback of each attribute. Currently
            # defined for properties only.
            for attr_name, obj in attrs.items():
                try:
                    dealloc_callback = obj.dealloc_callback
                except AttributeError:
                    pass
                else:
                    dealloc_callback(objc_self, attr_name)

            # Invoke super dealloc.
            send_super(ptr, objc_self, "dealloc", restype=None, argtypes=[], _allow_dealloc=True)

        add_method(ptr, "dealloc", _new_delloc, [None, ObjCInstance, SEL])

        # Register the ObjC class
        libobjc.objc_registerClassPair(ptr)

        return ptr, name, attrs

    def __new__(cls, name_or_ptr, bases=None, attrs=None, *, protocols=()):
        """The constructor accepts either the name of an Objective-C class to look up
        (as :class:`str` or :class:`bytes`), or a pointer to an existing class object
        (in any form accepted by :class:`ObjCInstance`).

        If given a pointer, it must refer to an Objective-C class; pointers to other objects are not accepted.
        (Use :class:`ObjCInstance` to wrap a pointer that might also refer to other kinds of objects.)
        If the pointer refers to a metaclass, an instance of :class:`ObjCMetaClass` is returned instead.
        Creating an :class:`ObjCClass` from a ``Nil`` pointer returns ``None``.

        :class:`ObjCClass` can also be called like :class:`type`, with three arguments
        (name, bases list, namespace mapping). This form is called implicitly by Python's ``class`` syntax,
        and is used to create a new Objective-C class from Python (see :ref:`custom-classes-and-protocols`).
        The bases list must contain exactly one :class:`ObjCClass` to be extended by the new class.
        An optional ``protocols`` keyword argument is also accepted,
        which must be a sequence of :class:`ObjCProtocol`\\s for the new class to adopt.
        """

        if (bases is None) ^ (attrs is None):
            raise TypeError('ObjCClass arguments 2 and 3 must be given together')

        if bases is None and attrs is None:
            # A single argument provided. If it's a string, treat it as
            # a class name. Anything else treat as a class pointer.

            if protocols:
                raise ValueError('protocols kwarg is not allowed for the single-argument form of ObjCClass')

            attrs = {}

            if isinstance(name_or_ptr, (bytes, str)):
                ptr, name = cls._new_from_name(name_or_ptr)
            else:
                ptr, name = cls._new_from_ptr(name_or_ptr)
                if not issubclass(cls, ObjCMetaClass) and libobjc.class_isMetaClass(ptr):
                    return ObjCMetaClass(ptr)
        else:
            ptr, name, attrs = cls._new_from_class_statement(name_or_ptr, bases, attrs, protocols=protocols)

        objc_class_name = name.decode('utf-8')

        new_attrs = {
            'name': objc_class_name,
            'methods_ptr_count': c_uint(0),
            'methods_ptr': None,
            # Mapping of name -> method pointer
            'instance_method_ptrs': {},
            # Mapping of name -> instance method
            'instance_methods': {},
            # Mapping of name -> (accessor method, mutator method)
            'instance_properties': {},
            # Explicitly declared properties
            'forced_properties': set(),
            # Mapping of first keyword -> ObjCPartialMethod instances
            'partial_methods': {},
        }

        # On Python 3.6 and later, the class namespace may contain a __classcell__ attribute that must be passed on
        # to type.__new__. See https://docs.python.org/3/reference/datamodel.html#creating-the-class-object
        if '__classcell__' in attrs:
            new_attrs['__classcell__'] = attrs['__classcell__']

        # Create the class object. If there is already a cached instance for ptr,
        # it is returned and the additional arguments are ignored.
        # Logically this can only happen when creating an ObjCClass from an existing
        # name or pointer, not when creating a new class.
        # If there is no cached instance for ptr, a new one is created and cached.
        self = super().__new__(cls, ptr, objc_class_name, (ObjCInstance,), new_attrs)

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
        if name.endswith('_'):
            # If the requested name ends with _, that's a marker that we're
            # dealing with a method call, not a property, so we can shortcut
            # the process.
            methods = None
        else:
            # Check 1: Does the class respond to the property?
            responds = libobjc.class_getProperty(self, name.encode('utf-8'))

            # Check 2: Does the class have an instance method to retrieve the given name
            accessor = self._cache_method(name)

            # Check 3: Is there a setName: method to set the property with the given name
            mutator = self._cache_method('set' + name[0].title() + name[1:] + ':')

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
        """Declare the instance method ``name`` to be a property getter.

        This causes the attribute named ``name`` on instances of this class to be treated as a property
        rather than a method --- accessing it returns the property's value, without requiring an explicit method call.
        See :class:`ObjCInstance.__getattr__` for a full description of how attribute access behaves for properties.

        Most properties do not need to be declared explicitly using this method, as they are detected automatically
        by :class:`ObjCInstance.__getattr__`. This method only needs to be used for properties that are read-only
        and don't have a ``@property`` declaration in the source code, because Rubicon cannot tell such properties
        apart from normal zero-argument methods.

        .. note::

            In the standard Apple SDKs, some properties are introduced as regular methods in one system version,
            and then declared as properties in a later system version. For example, the ``description`` method/property
            of :class:`NSObject` was declared as a regular method `up to OS X 10.9
            <https://github.com/phracker/MacOSX-SDKs/blob/9fc3ed0ad0345950ac25c28695b0427846eea966/MacOSX10.9.sdk/usr/include/objc/NSObject.h#L40>`__,
            but changed to a property `as of OS X 10.10
            <https://github.com/phracker/MacOSX-SDKs/blob/9fc3ed0ad0345950ac25c28695b0427846eea966/MacOSX10.10.sdk/usr/include/objc/NSObject.h#L43>`__.

            Such properties cause compatibility issues when accessed from Rubicon: ``obj.description()`` works on 10.9
            but is a :class:`TypeError` on 10.10, whereas ``obj.description`` works on 10.10
            but returns a method object on 10.9. To solve this issue, the property can be declared explicitly
            using ``NSObject.declare_property('description')``, so that it can always be accessed
            using ``obj.description``.
        """  # noqa: E501 # The links in the docstring above are too long to wrap to 120 chars.

        self.forced_properties.add(name)

    def declare_class_property(self, name):
        """Declare the class method ``name`` to be a property getter.

        This is equivalent to ``self.objc_class.declare_property(name)``.
        """

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
        """Check whether the given object is an instance of this class.

        If the given object is not an Objective-C object, ``False`` is returned.

        This method allows using :class:`ObjCClass`\\es as the second argument of :func:`isinstance`:
        ``isinstance(obj, NSString)`` is equivalent to ``obj.isKindOfClass(NSString)``.
        """

        if isinstance(instance, ObjCInstance):
            return bool(instance.isKindOfClass(self))
        else:
            return False

    def __subclasscheck__(self, subclass):
        """Check whether the given class is a subclass of this class.

        If the given object is not an Objective-C class, :class:`TypeError` is raised.

        This method allows using :class:`ObjCClass`\\es as the second argument of :func:`issubclass`:
        ``issubclass(cls, NSValue)`` is equivalent to ``obj.isSubclassOfClass(NSValue)``.
        """

        if isinstance(subclass, ObjCClass):
            return bool(subclass.isSubclassOfClass(self))
        else:
            raise TypeError(
                'issubclass(X, {self!r}) arg 1 must be an ObjCClass, not {tp.__module__}.{tp.__qualname__}'
                .format(self=self, tp=type(subclass))
            )

    def _load_methods(self):
        if self.methods_ptr is not None:
            raise RuntimeError("_load_methods cannot be called more than once")

        self.methods_ptr = libobjc.class_copyMethodList(self, byref(self.methods_ptr_count))

        if self.superclass is not None:
            if self.superclass.methods_ptr is None:
                self.superclass._load_methods()

            # Prime this class' partials list with a list from the superclass.
            for first, superpartial in self.superclass.partial_methods.items():
                partial = self.partial_methods[first] = ObjCPartialMethod(first)
                partial.methods.update(superpartial.methods)

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
                partial = self.partial_methods[first] = ObjCPartialMethod(first)

            # order is rest without the dummy "" part
            order = rest[:-1]
            partial.methods[frozenset(rest)] = (name, order)


class ObjCMetaClass(ObjCClass):
    """Python wrapper for an Objective-C metaclass.

    :class:`ObjCMetaClass` is a subclass of :class:`ObjCClass` and supports almost exactly the same operations
    and methods. However, there is usually no need to look up a metaclass manually.
    The main reason why :class:`ObjCMetaClass` is a separate class is to differentiate it from :class:`ObjCClass`
    in the :func:`repr`. (Otherwise there would be no way to tell classes and metaclasses apart,
    since metaclasses are also classes, and have exactly the same name as their corresponding class.)
    """

    def __new__(cls, name_or_ptr):
        """The constructor accepts either the name of an Objective-C metaclass to look up
        (as :class:`str` or :class:`bytes`), or a pointer to an existing metaclass object
        (in any form accepted by :class:`ObjCInstance`).

        If given a pointer, it must refer to an Objective-C metaclass; pointers to other objects are not accepted.
        (Use :class:`ObjCInstance` to wrap a pointer that might also refer to other kinds of objects.)
        Creating an :class:`ObjCMetaClass` from a ``Nil`` pointer returns ``None``.
        """

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
                raise ValueError("Pointer {} ({:#x}) does not refer to a metaclass".format(ptr, ptr.value))

        return super().__new__(cls, ptr)


register_ctype_for_type(ObjCInstance, objc_id)
register_ctype_for_type(ObjCClass, Class)


NSObject = ObjCClass('NSObject')
NSObject.declare_property('debugDescription')
NSObject.declare_property('description')
NSNumber = ObjCClass('NSNumber')
NSDecimalNumber = ObjCClass('NSDecimalNumber')
NSString = ObjCClass('NSString')
NSString.declare_property('UTF8String')
NSData = ObjCClass('NSData')
NSArray = ObjCClass('NSArray')
NSMutableArray = ObjCClass('NSMutableArray')
NSDictionary = ObjCClass('NSDictionary')
NSMutableDictionary = ObjCClass('NSMutableDictionary')
Protocol = ObjCClass('Protocol')


def py_from_ns(nsobj):
    """Convert a Foundation object into an equivalent Python object if possible.

    Currently supported types:

    * :class:`~rubicon.objc.runtime.objc_id`: Wrapped in an :class:`ObjCInstance` and converted as below
    * :class:`NSString`: Converted to :class:`str`
    * :class:`NSData`: Converted to :class:`bytes`
    * :class:`NSDecimalNumber`: Converted to :class:`decimal.Decimal`
    * :class:`NSDictionary`: Converted to :class:`dict`, with all keys and values converted recursively
    * :class:`NSArray`: Converted to :class:`list`, with all elements converted recursively
    * :class:`NSNumber`: Converted to a :class:`bool`, :class:`int` or :class:`float` based on the type of its contents

    Other objects are returned unmodified as an :class:`ObjCInstance`.
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
        if objc_type == b'B':
            return nsobj.boolValue
        elif objc_type in b'csilq':
            return nsobj.longLongValue
        elif objc_type in b'CSILQ':
            return nsobj.unsignedLongLongValue
        elif objc_type in b'fd':
            return nsobj.doubleValue
        else:
            raise TypeError(
                'NSNumber containing unsupported type {!r} cannot be converted to a Python object'
                .format(objc_type)
            )
    elif nsobj.isKindOfClass(NSString):
        return str(nsobj)
    elif nsobj.isKindOfClass(NSData):
        # Despite the name, string_at converts the data at the address to a bytes object, not str.
        return string_at(send_message(nsobj, 'bytes', restype=POINTER(c_uint8), argtypes=[]), nsobj.length)
    elif nsobj.isKindOfClass(NSDictionary):
        return {py_from_ns(k): py_from_ns(v) for k, v in nsobj.items()}
    elif nsobj.isKindOfClass(NSArray):
        return [py_from_ns(o) for o in nsobj]
    else:
        return nsobj


def ns_from_py(pyobj):
    """Convert a Python object into an equivalent Foundation object. The returned object is autoreleased.

    This function is also available under the name :func:`at`, because its functionality is very similar to that of the
    Objective-C ``@`` operator and literals.

    Currently supported types:

    * ``None``, :class:`ObjCInstance`: Returned as-is
    * :class:`enum.Enum`: Replaced by their :attr:`~enum.Enum.value` and converted as below
    * :class:`str`: Converted to :class:`NSString`
    * :class:`bytes`: Converted to :class:`NSData`
    * :class:`decimal.Decimal`: Converted to :class:`NSDecimalNumber`
    * :class:`dict`: Converted to :class:`NSDictionary`, with all keys and values converted recursively
    * :class:`list`: Converted to :class:`NSArray`, with all elements converted recursively
    * :class:`bool`, :class:`int`, :class:`float`: Converted to :class:`NSNumber`

    Other types cause a :class:`TypeError`.
    """

    if isinstance(pyobj, enum.Enum):
        pyobj = pyobj.value

    # Many Objective-C method calls here use the convert_result=False kwarg to disable automatic conversion of
    # return values, because otherwise most of the Objective-C objects would be converted back to Python objects.
    if pyobj is None or isinstance(pyobj, ObjCInstance):
        return pyobj
    elif isinstance(pyobj, str):
        return ObjCInstance(NSString.stringWithUTF8String_(pyobj.encode('utf-8'), convert_result=False))
    elif isinstance(pyobj, bytes):
        return ObjCInstance(NSData.dataWithBytes(pyobj, length=len(pyobj)))
    elif isinstance(pyobj, decimal.Decimal):
        return ObjCInstance(NSDecimalNumber.decimalNumberWithString_(pyobj.to_eng_string(), convert_result=False))
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
            "Don't know how to convert a {cls.__module__}.{cls.__qualname__} to a Foundation object"
            .format(cls=type(pyobj))
        )


at = ns_from_py


@for_objcclass(Protocol)
class ObjCProtocol(ObjCInstance):
    """Python wrapper for an Objective-C protocol."""

    @property
    def name(self):
        """The name of this protocol, as a :class:`str`."""

        return libobjc.protocol_getName(self).decode('utf-8')

    @property
    def protocols(self):
        """The protocols that this protocol extends."""

        out_count = c_uint()
        protocols_ptr = libobjc.protocol_copyProtocolList(self, byref(out_count))
        return tuple(ObjCProtocol(protocols_ptr[i]) for i in range(out_count.value))

    def __new__(cls, name_or_ptr, bases=None, ns=None):
        """The constructor accepts either the name of an Objective-C protocol to look up
        (as :class:`str` or :class:`bytes`), or a pointer to an existing protocol object
        (in any form accepted by :class:`ObjCInstance`).

        If given a pointer, it must refer to an Objective-C protocol; pointers to other objects are not accepted.
        (Use :class:`ObjCInstance` to wrap a pointer that might also refer to other kinds of objects.)
        Creating an :class:`ObjCProtocol` from a ``nil`` pointer returns ``None``.

        :class:`ObjCProtocol` can also be called like :class:`type`, with three arguments
        (name, bases list, namespace mapping). This form is called implicitly by Python's ``class`` syntax,
        and is used to create a new Objective-C protocol from Python (see :ref:`custom-classes-and-protocols`).
        The bases list can contain any number of :class:`ObjCProtocol` objects to be extended by the new protocol.
        """

        if (bases is None) ^ (ns is None):
            raise TypeError('ObjCProtocol arguments 2 and 3 must be given together')

        if bases is None and ns is None:
            if isinstance(name_or_ptr, (bytes, str)):
                name = ensure_bytes(name_or_ptr)
                ptr = libobjc.objc_getProtocol(name)
                if ptr.value is None:
                    raise NameError('Objective-C protocol {} not found'.format(name))
            else:
                ptr = cast(name_or_ptr, objc_id)
                if ptr.value is None:
                    raise ValueError('Cannot create ObjCProtocol for nil pointer')
                elif not send_message(ptr, 'isKindOfClass:', Protocol, restype=c_bool, argtypes=[objc_id]):
                    raise ValueError('Pointer {} ({:#x}) does not refer to a protocol'.format(ptr, ptr.value))
        else:
            name = ensure_bytes(name_or_ptr)

            if libobjc.objc_getProtocol(name).value is not None:
                raise RuntimeError('An Objective-C protocol named {!r} already exists'.format(name))

            # Check that all bases are protocols.
            for base in bases:
                if not isinstance(base, ObjCProtocol):
                    raise TypeError(
                        'An Objective-C protocol can only extend ObjCProtocol objects, '
                        'not {cls.__module__}.{cls.__qualname__}'
                        .format(cls=type(base))
                    )

            # Allocate the protocol object.
            ptr = libobjc.objc_allocateProtocol(name)
            if ptr is None:
                raise RuntimeError('Protocol allocation failed')

            # Adopt all the protocols.
            for proto in bases:
                libobjc.protocol_addProtocol(ptr, proto)

            # Register all methods and properties.
            for attr_name, obj in ns.items():
                if hasattr(obj, 'protocol_register'):
                    obj.protocol_register(ptr, attr_name)

            # Register the protocol object
            libobjc.objc_registerProtocol(ptr)

        return super().__new__(cls, ptr)

    def __repr__(self):
        return '<{cls.__module__}.{cls.__qualname__}: {self.name} at {self.ptr.value:#x}>'.format(
            cls=type(self), self=self)

    def __instancecheck__(self, instance):
        """Check whether the given object conforms to this protocol.

        If the given object is not an Objective-C object, ``False`` is returned.

        This method allows using :class:`ObjCProtocol`\\s as the second argument of :func:`isinstance`:
        ``isinstance(obj, NSCopying)`` is equivalent to ``obj.conformsToProtocol(NSCopying)``.
        """

        if isinstance(instance, ObjCInstance):
            return bool(instance.conformsToProtocol(self))
        else:
            return False

    def __subclasscheck__(self, subclass):
        """Check whether the given class or protocol conforms to this protocol.

        If the given object is not an Objective-C class or protocol, :class:`TypeError` is raised.

        This method allows using :class:`ObjCProtocol`\\s as the second argument of :func:`issubclass`:
        ``issubclass(cls, NSCopying)`` is equivalent to ``cls.conformsToProtocol(NSCopying)``,
        and ``issubclass(proto, NSCopying)`` is equivalent to ``protocol_conformsToProtocol(proto, NSCopying))``.
        """

        if isinstance(subclass, ObjCClass):
            return bool(subclass.conformsToProtocol(self))
        elif isinstance(subclass, ObjCProtocol):
            return bool(libobjc.protocol_conformsToProtocol(subclass, self))
        else:
            raise TypeError(
                'issubclass(X, {self!r}) arg 1 must be an ObjCClass or ObjCProtocol, '
                'not {tp.__module__}.{tp.__qualname__}'
                .format(self=self, tp=type(subclass))
            )


# Need to use a different name to avoid conflict with the NSObject class.
# NSObjectProtocol is also the name that Swift uses when importing the NSObject protocol.
NSObjectProtocol = ObjCProtocol('NSObject')


# When a Python object is assigned to a new ObjCInstance attribute, the Python
# object should be kept alive for the lifetime of the ObjCInstance. This is
# done by wrapping the Python object as a WrappedPyObject that increments
# the reference count during assignment and decrements it when the WrappedPyObject
# and the owning ObjCInstance are deallocated.
#
# The methods of the class defined below are decorated with
# rawmethod() instead of method() because WrappedPyObject
# are created inside of ObjCInstance's __new__ method and we have
# to be careful to not create another ObjCInstance here (which
# happens when the usual method decorator turns the self argument
# into an ObjCInstance), or else get trapped in an infinite recursion.

# Try to reuse an existing WrappedPyObject class.
# This allows reloading the module without having to restart
# the interpreter, although any changes to WrappedPyObject
# itself are only applied after a restart of course.

try:
    WrappedPyObject = ObjCClass("WrappedPyObject")
except NameError:
    class WrappedPyObject(NSObject):

        wrapped_pointer = objc_ivar(c_void_p)

        @objc_rawmethod
        def initWithObjectId_(self, cmd, address):
            self = send_message(self, 'init', restype=objc_id, argtypes=[])
            if self is not None:
                pyo = cast(address, py_object)
                _keep_alive_objects[(self.value, address.value)] = pyo.value
                set_ivar(self, 'wrapped_pointer', address)
            return self.value

        @objc_rawmethod
        def dealloc(self, cmd) -> None:
            address = get_ivar(self, 'wrapped_pointer')
            if address.value:
                del _keep_alive_objects[(self.value, address.value)]

        @objc_rawmethod
        def finalize(self, cmd) -> None:
            # Called instead of dealloc if using garbage collection.
            # (which would have to be explicitly started with
            # objc_startCollectorThread(), so probably not too much reason
            # to have this here, but I guess it can't hurt.)
            address = get_ivar(self, 'wrapped_pointer')
            if address.value:
                del _keep_alive_objects[(self.value, address.value)]
            send_super(__class__, self, 'finalize', restype=None, argtypes=[])


def objc_const(dll, name):
    """Create an :class:`ObjCInstance` from a global pointer variable in a :class:`~ctypes.CDLL`.

    This function is most commonly used to access constant object pointers defined by a library/framework, such as
    `NSCocoaErrorDomain <https://developer.apple.com/documentation/foundation/nscocoaerrordomain?language=objc>`__.
    """

    return ObjCInstance(objc_id.in_dll(dll, name))


_cfunc_type_block_invoke = CFUNCTYPE(c_void_p, c_void_p)
_cfunc_type_block_dispose = CFUNCTYPE(c_void_p, c_void_p)
_cfunc_type_block_copy = CFUNCTYPE(c_void_p, c_void_p, c_void_p)


class ObjCBlockStruct(Structure):
    _fields_ = [
        ('isa', c_void_p),
        ('flags', c_int),
        ('reserved', c_int),
        ('invoke', _cfunc_type_block_invoke),
        ('descriptor', c_void_p),
    ]


class BlockDescriptor(Structure):
    _fields_ = [
        ('reserved', c_ulong),
        ('size', c_ulong),
        ('copy_helper', _cfunc_type_block_copy),
        ('dispose_helper', _cfunc_type_block_dispose),
        ('signature', c_char_p),
    ]


class BlockLiteral(Structure):
    _fields_ = [
        ('isa', c_void_p),
        ('flags', c_int),
        ('reserved', c_int),
        ('invoke', c_void_p),  # NB: this must be c_void_p due to variadic nature
        ('descriptor', c_void_p)
    ]


def create_block_descriptor_struct(has_helpers, has_signature):
    descriptor_fields = [
        ('reserved', c_ulong),
        ('size', c_ulong),
    ]
    if has_helpers:
        descriptor_fields.extend([
            ('copy_helper', _cfunc_type_block_copy),
            ('dispose_helper', _cfunc_type_block_dispose),
        ])
    if has_signature:
        descriptor_fields.extend([
            ('signature', c_char_p),
        ])
    return type(
        'ObjCBlockDescriptor',
        (Structure, ),
        {'_fields_': descriptor_fields}
    )


def cast_block_descriptor(block):
    descriptor_struct = create_block_descriptor_struct(block.has_helpers, block.has_signature)
    return cast(block.struct.contents.descriptor, POINTER(descriptor_struct))


AUTO = object()


class BlockConsts:
    HAS_COPY_DISPOSE = 1 << 25
    HAS_CTOR = 1 << 26
    IS_GLOBAL = 1 << 28
    HAS_STRET = 1 << 29
    HAS_SIGNATURE = 1 << 30


class ObjCBlock:
    """Python wrapper for an Objective-C block object.

    This class is used to manually wrap an Objective-C block so that it can be called from Python. Usually Rubicon will
    do this automatically, if the block object was returned from an Objective-C method whose return type is declared
    to be a block type. If this automatic detection fails, for example if the method's return type is generic ``id``,
    Rubicon has no way to tell that the object in question is a block rather than a regular Objective-C object.
    In that case, the object needs to be manually wrapped using :class:`ObjCBlock`.
    """

    def __init__(self, pointer, restype=AUTO, *argtypes):
        """The constructor takes a block object, which can be either an :class:`ObjCInstance`, or a raw
        :class:`~rubicon.objc.runtime.objc_id` pointer.

        .. note::

            :class:`~rubicon.objc.runtime.objc_block` is also accepted, because it is a subclass of
            :class:`~rubicon.objc.runtime.objc_id`). Normally you do not need to make use of this,
            because in most cases Rubicon will automatically convert :class:`~rubicon.objc.runtime.objc_block`\\s
            to a callable object.

        In most cases, Rubicon can automatically determine the block's return type and parameter types.
        If a block object doesn't have return/parameter type information at runtime, Rubicon will raise an error when
        attempting to convert it. In that case, you need to explicitly pass the correct return type and parameter types
        to :class:`ObjCBlock` using the ``restype`` and ``argtypes`` parameters.
        """

        if isinstance(pointer, ObjCInstance):
            pointer = pointer.ptr
        self.pointer = pointer
        self.struct = cast(self.pointer, POINTER(ObjCBlockStruct))
        self.has_helpers = self.struct.contents.flags & BlockConsts.HAS_COPY_DISPOSE
        self.has_signature = self.struct.contents.flags & BlockConsts.HAS_SIGNATURE
        self.descriptor = cast_block_descriptor(self)
        self.signature = self.descriptor.contents.signature if self.has_signature else None
        if restype is AUTO:
            if argtypes:
                raise ValueError('Cannot use argtypes with restype AUTO')
            if not self.has_signature:
                raise ValueError('Cannot use AUTO types for blocks without signatures')
            restype, *argtypes = ctypes_for_method_encoding(self.signature)
        self.struct.contents.invoke.restype = ctype_for_type(restype)
        self.struct.contents.invoke.argtypes = (objc_id, ) + tuple(ctype_for_type(arg_type) for arg_type in argtypes)

    def __repr__(self):
        representation = '<ObjCBlock@{}'.format(hex(addressof(self.pointer)))
        if self.has_helpers:
            representation += ',has_helpers'
        if self.has_signature:
            representation += ',has_signature:' + self.signature
        representation += '>'
        return representation

    def __call__(self, *args):
        """Invoke the block object with the given arguments.

        The arguments and return value are converted from/to Python objects according to the default ``ctypes`` rules,
        based on the block's return and parameter types.
        """

        return self.struct.contents.invoke(self.pointer, *args)


class ObjCBlockInstance(ObjCInstance):
    def __call__(self, *args):
        return self.block(*args)


_NSConcreteStackBlock = (c_void_p * 32).in_dll(libc, "_NSConcreteStackBlock")


NOTHING = object()


class Block:
    """A wrapper that exposes a Python callable object to Objective-C as a block.

    .. note::

        :class:`Block` instances are currently *not* callable from Python, unlike :class:`ObjCBlock`.
    """

    _keep_alive_blocks_ = {}

    def __init__(self, func, restype=NOTHING, *argtypes):
        """The constructor accepts any Python callable object.

        If the callable has parameter and return type annotations, they are used as the block's parameter and return
        types. This allows using :class:`Block` as a decorator:

        .. code-block:: python

            @Block
            def the_block(arg: NSInteger) -> NSUInteger:
                return abs(arg)

        For callables without type annotations, the parameter and return types need to be passed to the :class:`Block`
        constructor in the ``restype`` and ``argtypes`` arguments:

        .. code-block:: python

            the_block = Block(abs, NSUInteger, NSInteger)
        """

        if not callable(func):
            raise TypeError('Blocks must be callable')

        self.func = func

        if restype is NOTHING:
            if argtypes:
                # This can't happen unless the caller does something hacky, but guard against it just in case.
                raise ValueError('Cannot pass argtypes without a restype')

            # No explicit restype/argtypes were passed into the constructor,
            # so try to extract them from the function's type annotations.

            try:
                signature = inspect.signature(func)
            except (TypeError, ValueError):
                raise ValueError(
                    'Could not retrieve function signature information - '
                    'please pass return and argument types directly into Block'
                )

            if signature.return_annotation == inspect.Signature.empty:
                raise ValueError(
                    'Function has no return type annotation - '
                    'please add one, or pass return and argument types directly into Block'
                )

            restype = signature.return_annotation
            argtypes = []
            for name, param in signature.parameters.items():
                if param.annotation == inspect.Parameter.empty:
                    raise ValueError(
                        'Function has no argument type annotation for parameter ' + repr(name)
                        + ' - please add one, or pass return and argument types directly into Block'
                    )

                argtypes.append(param.annotation)

        signature = tuple(ctype_for_type(tp) for tp in argtypes)

        restype = ctype_for_type(restype)

        self.cfunc_type = CFUNCTYPE(restype, c_void_p, *signature)

        self.literal = BlockLiteral()
        self.literal.isa = addressof(_NSConcreteStackBlock)
        self.literal.flags = BlockConsts.HAS_STRET | BlockConsts.HAS_SIGNATURE | BlockConsts.HAS_COPY_DISPOSE
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

        self.descriptor.signature = encoding_for_ctype(restype) + b'@?' + b''.join(
            encoding_for_ctype(arg) for arg in signature
        )
        self.literal.descriptor = cast(byref(self.descriptor), c_void_p)
        self.block = cast(byref(self.literal), objc_block)
        self._as_parameter_ = self.block

    def wrapper(self, instance, *args):
        return self.func(*args)

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
