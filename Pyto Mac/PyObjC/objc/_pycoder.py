"""
Implementation of NSCoding for OC_PythonObject and friends

A minor problem with NSCoding support is that NSCoding restores
graphs recusively while Pickle does so depth-first (more of less).
This can cause problems when the object state contains the
object itself, which is why we need a 'setValue' callback for the
load_* functions below.
"""
from __future__ import unicode_literals
import sys
import objc
from types import *

if sys.version_info[0] == 2:
    import copy_reg as copyreg
else:
    import copyreg

import copy

from pickle import PicklingError, UnpicklingError

if sys.version_info[0] == 2:
    import __builtin__ as _builtins
else:
    import builtins as _builtins

# _getattribute and whichmodule are adapted from the
# same function's in Python 3.4's pickle module. The
# primary difference is that the functions below
# behave as if 'allow_qualname' is true)

def _getattribute(obj, name):
    dotted_path = name.split(".")
    for subpath in dotted_path:
        if subpath == '<locals>':
            raise AttributeError("Can't get local attribute %r on %r" % (
                name, obj))
        try:
            obj = getattr(obj, subpath)
        except AttributeError:
            raise AttributeError("Can't get attribute %r on %r" % (
                name, obj))
    return obj

def whichmodule(obj, name):
    module_name = getattr(obj, '__module__', None)
    if module_name is not None:
        return module_name

    for module_name, module in list(sys.modules.items()):
        if module_name == "__main__" or module is None:
            continue

        try:
            if _getattribute(module, name) is obj:
                return module_name

        except AttributeError as exc:
            pass

    return '__main__'



if sys.version_info[0] == 2:  # pragma: no 3.x cover
    bltin_intern = intern

    def intern(value):
        if isinstance(value, objc.pyobjc_unicode):
            return bltin_intern(value.encode('utf-8'))
        elif isinstance(value, basestring):
            return bltin_intern(value)
        else:
            return value

    def import_module(name):
        if name == 'copyreg':
            name = 'copy_reg'
        __import__(name, level=0)
        return sys.modules[name]

else:   # pragma: no 2.x cover
    unicode = str
    long = int
    bltin_intern = sys.intern

    def intern(value):
        if isinstance(value, objc.pyobjc_unicode):
            return bltin_intern(str(value))
        elif isinstance(value, str):
            return bltin_intern(value)
        else:
            return value

    def import_module(name):
        if name == 'copy_reg':
            name = 'copyreg'
        __import__(name, level=0)
        return sys.modules[name]


NSArray = objc.lookUpClass("NSArray")
NSMutableArray = objc.lookUpClass("NSMutableArray")
NSDictionary = objc.lookUpClass("NSDictionary")
NSString = objc.lookUpClass("NSString")
NSSet = objc.lookUpClass("NSSet")
NSMutableSet = objc.lookUpClass("NSMutableSet")

kOP_REDUCE=0
kOP_INST=1
kOP_GLOBAL=2
kOP_NONE=3
kOP_BOOL=4
kOP_INT=5
kOP_LONG=6
kOP_FLOAT=7
kOP_UNICODE=8
kOP_STRING=9
kOP_TUPLE=10
kOP_LIST=11
kOP_DICT=12
kOP_GLOBAL_EXT=13
kOP_FLOAT_STR=14

kKIND = NSString.stringWithString_("kind")
kFUNC = NSString.stringWithString_("func")
kARGS = NSString.stringWithString_("args")
kLIST = NSString.stringWithString_("list")
kDICT = NSString.stringWithString_("dict")
kSTATE = NSString.stringWithString_("state")
kCLASS = NSString.stringWithString_("class")
kVALUE = NSString.stringWithString_("value")
kNAME = NSString.stringWithString_("name")
kMODULE = NSString.stringWithString_("module")
kCODE = NSString.stringWithString_("code")

class _EmptyClass:
    pass

encode_dispatch = {}

# Code below tries to mirror the implementation in pickle.py, with
# adaptations because we're not saving to a byte stream but to another
# serializer.

def save_reduce(coder, func, args,
        state=None, listitems=None, dictitems=None, obj=None):

    if not isinstance(args, tuple):
        raise PicklingError("args from reduce() should be a tuple")

    if not callable(func):
        raise PicklingError("func from reduce should be callable")

    if coder.allowsKeyedCoding():
        coder.encodeInt_forKey_(kOP_REDUCE, kKIND)
        coder.encodeObject_forKey_(func, kFUNC)
        coder.encodeObject_forKey_(args, kARGS)
        if listitems is None:
            coder.encodeObject_forKey_(None, kLIST)
        else:
            coder.encodeObject_forKey_(list(listitems), kLIST)

        if dictitems is None:
            coder.encodeObject_forKey_(None, kDICT)
        else:
            coder.encodeObject_forKey_(dict(dictitems), kDICT)
        coder.encodeObject_forKey_(state, kSTATE)

    else:
        coder.encodeValueOfObjCType_at_(objc._C_INT, kOP_REDUCE)
        coder.encodeObject_(func)
        coder.encodeObject_(args)
        if listitems is None:
            coder.encodeObject_(None)
        else:
            coder.encodeObject_(list(listitems))

        if dictitems is None:
            coder.encodeObject_(None)
        else:
            coder.encodeObject_(dict(dictitems))
        coder.encodeObject_(state)

if sys.version_info[0] == 2:  # pragma: no 3.x cover
    def save_inst(coder, obj):
        if hasattr(obj, '__getinitargs__'):
            args = obj.__getinitargs__()
            len(args) # Assert it's a sequence
        else:
            args = ()

        cls = obj.__class__

        if coder.allowsKeyedCoding():
            coder.encodeInt32_forKey_(kOP_INST, kKIND)
            coder.encodeObject_forKey_(cls, kCLASS)
            coder.encodeObject_forKey_(args, kARGS)

        else:
            coder.encodeValueOfObjCType_at_(objc._C_INT, kOP_INST)
            coder.encodeObject_(cls)
            coder.encodeObject_(args)

        try:
            getstate = obj.__getstate__
        except AttributeError:
            state = obj.__dict__

        else:
            state = getstate()

        if coder.allowsKeyedCoding():
            coder.encodeObject_forKey_(state, kSTATE)

        else:
            coder.encodeObject_(state)

    encode_dispatch[InstanceType] = save_inst

if sys.version_info[0] == 2:  # pragma: no 3.x cover
    def save_int(coder, obj):
        if coder.allowsKeyedCoding():
            coder.encodeInt_forKey_(kOP_INT, kKIND)
            coder.encodeInt64_forKey_(obj, kVALUE)
        else:
            coder.encodeValueOfObjCType_at_(objc._C_INT, kOP_INT)
            coder.encodeValueOfObjCType_at_(objc._C_LNG_LNG, obj)
    encode_dispatch[int] = save_int

    def save_long(coder, obj):
        encoded = unicode(repr(obj))
        if encoded.endswith('L'):
            encoded = encoded[:-1]
        if coder.allowsKeyedCoding():
            coder.encodeInt_forKey_(kOP_LONG, kKIND)
            coder.encodeObject_forKey_(encoded, kVALUE)
        else:
            coder.encodeValueOfObjCType_at_(objc._C_INT, kOP_LONG)
            coder.encodeObject_(encoded)

    encode_dispatch[long] = save_long

else: # pragma: no 2.x cover
    def save_int(coder, obj):
        if coder.allowsKeyedCoding():
            coder.encodeInt_forKey_(kOP_LONG, kKIND)
            coder.encodeObject_forKey_(unicode(repr(obj)), kVALUE)
        else:
            coder.encodeValueOfObjCType_at_(objc._C_INT, kOP_LONG)
            coder.encodeObject_(unicode(repr(obj)))
    encode_dispatch[int] = save_int

def save_float(coder, obj):  # pragma: no cover
    # NOTE: 'no cover' because floats are encoded as OC_PythonNumber
    # and that doesn't call back to this code for basic C types.
    # TODO: full review the code path and remove this function.

    # Encode floats as strings, this seems to be needed to get
    # 100% reliable round-trips.
    if coder.allowsKeyedCoding():
        coder.encodeInt_forKey_(kOP_FLOAT_STR, kKIND)
        coder.encodeObject_forKey_(unicode(repr(obj)), kVALUE)
    else:
        coder.encodeValueOfObjCType_at_(objc._C_INT, kOP_FLOAT_STR)
        coder.encodeObject_(unicode(repr(obj)))

encode_dispatch[float] = save_float

def save_global(coder, obj, name=None):
    if name is None:
        name = getattr(obj, '__qualname__', None)
    if name is None:
        name = obj.__name__

    module_name = whichmodule(obj, name)
    try:
        module = import_module(module_name)
        obj2 = _getattribute(module, name)

    except (ImportError, KeyError, AttributeError):
        raise PicklingError(
                  "Can't pickle %r: it's not found as %s.%s" %
                  (obj, module_name, name))
    else:
        if obj2 is not obj:
            raise PicklingError(
                "Can't pickle %r: it's not the same object as %s.%s" %
                (obj, module_name, name))

    code = copyreg._extension_registry.get((module_name, name))

    if coder.allowsKeyedCoding():
        if code:
            coder.encodeInt_forKey_(kOP_GLOBAL_EXT, kKIND)
            coder.encodeInt_forKey_(code, kCODE)

        else:
            coder.encodeInt_forKey_(kOP_GLOBAL, kKIND)
            coder.encodeObject_forKey_(unicode(module_name), kMODULE)
            coder.encodeObject_forKey_(unicode(name), kNAME)

    else:
        if code:
            coder.encodeValueOfObjCType_at_(objc._C_INT, kOP_GLOBAL_EXT)
            coder.encodeValueOfObjCType_at_(objc._C_INT, code)

        else:
            coder.encodeValueOfObjCType_at_(objc._C_INT, kOP_GLOBAL)
            coder.encodeObject_(unicode(module_name))
            coder.encodeObject_(unicode(name))

if sys.version_info[0] == 2:  # pragma: no 3.x cover
    encode_dispatch[ClassType] = save_global
encode_dispatch[type(save_global)] = save_global
try:
    dir.__reduce__()
except TypeError:
    encode_dispatch[type(dir)] = save_global

def save_type(coder, obj):
    if obj is type(None):
        return save_reduce(coder, type, (None,), obj=obj)
    elif obj is type(NotImplemented):
        return save_reduce(coder, type, (NotImplemented,), obj=obj)
    elif obj is type(Ellipsis):
        return save_reduce(coder, type, (Ellipsis,), obj=obj)
    return save_global(coder, obj)
encode_dispatch[type] = save_type


def save_ellipsis(coder, obj):
    save_global(coder, Ellipsis, 'Ellipsis')
encode_dispatch[type(Ellipsis)] = save_ellipsis

def save_notimplemented(coder, obj):
    save_global(coder, NotImplemented, 'NotImplemented')
encode_dispatch[type(NotImplemented)] = save_notimplemented




decode_dispatch = {}

def load_int(coder, setValue):
    if coder.allowsKeyedCoding():
        return int(coder.decodeInt64ForKey_(kVALUE))
    else:
        return int(coder.decodeValueOfObjCType_at_(objc._C_LNG_LNG, None))
decode_dispatch[kOP_INT] = load_int

def load_long(coder, setValue):
    if coder.allowsKeyedCoding():
        return long(coder.decodeObjectForKey_(kVALUE))
    else:
        return long(coder.decodeObject())
decode_dispatch[kOP_LONG] = load_long

def load_float(coder, setValue): # pragma: no cover
    # Only used with old versions of PyObjC (before 2.3), keep
    # for backward compatibility.
    if coder.allowsKeyedCoding():
        return coder.decodeFloatForKey_(kVALUE)
    else:
        raise RuntimeError("Unexpected encoding")
decode_dispatch[kOP_FLOAT] = load_float

def load_float_str(coder, setValue):
    if coder.allowsKeyedCoding():
        return float(coder.decodeObjectForKey_(kVALUE))
    else:
        return float(coder.decodeObject())
decode_dispatch[kOP_FLOAT_STR] = load_float_str


def load_global_ext(coder, setValue):
    if coder.allowsKeyedCoding():
        code = coder.decodeIntForKey_(kCODE)
    else:
        code = coder.decodeValueOfObjCType_at_(objc._C_INT, None)
    nil = []
    obj = copyreg._extension_cache.get(code, nil)
    if obj is not nil:
        return obj
    key = copyreg._inverted_registry.get(code)
    if not key:
        raise ValueError("unregistered extension code %d" % code)

    module, name = key
    mod = import_module(module)
    klass = _getattribute(mod, name)
    copyreg._extension_cache[code] = klass
    return klass
decode_dispatch[kOP_GLOBAL_EXT] = load_global_ext


def load_global(coder, setValue):
    if coder.allowsKeyedCoding():
        module_name = coder.decodeObjectForKey_(kMODULE)
        name = coder.decodeObjectForKey_(kNAME)
    else:
        module_name = coder.decodeObject()
        name = coder.decodeObject()

    mod = import_module(module_name)
    return _getattribute(mod, name)

decode_dispatch[kOP_GLOBAL] = load_global


def load_inst(coder, setValue):
    if coder.allowsKeyedCoding():
        cls = coder.decodeObjectForKey_(kCLASS)
        initargs = coder.decodeObjectForKey_(kARGS)
    else:
        cls = coder.decodeObject()
        initargs = coder.decodeObject()


    if (sys.version_info[0] == 2 and not initargs and
            type(cls) is ClassType and
            not hasattr(cls, "__getinitargs__")):  # pragma: no 3.x cover
        value = _EmptyClass()
        value.__class__ = cls

    else:
        try:
            value = cls(*initargs)
        except TypeError as err:
            raise TypeError("in constructor for %s: %s" % (
                cls.__name__, str(err)), sys.exc_info()[2])


    # We now have the object, but haven't set the correct
    # state yet.  Tell the bridge about this value right
    # away, that's needed because `value` might be part
    # of the object state which we'll retrieve next.
    setValue(value)

    if coder.allowsKeyedCoding():
        state = coder.decodeObjectForKey_(kSTATE)
    else:
        state = coder.decodeObject()
        if isinstance(state, NSArray):
            state = tuple(state)

    setstate = getattr(value, "__setstate__", None)
    if setstate is not None:
        setstate(state)
        return value

    slotstate = None
    if isinstance(state, tuple) and len(state) == 2:
        state, slotstate = state

    if state:
        # Note: pickle.py catches RuntimeError here,
        # that's for supporting restricted mode and
        # is not relevant for PyObjC.
        inst_dict = value.__dict__
        for k in state:
            v = state[k]
            if type(k) == objc.pyobjc_unicode:
                inst_dict[intern(str(k))] = v
            elif type(k) == str:
                inst_dict[intern(k)] = v
            else:
                inst_dict[k] = v


    if slotstate:
        for k, v in slotstate.items():
            if isinstance(k, objc.pyobjc_unicode):
                k = k.encode('utf-8')
            setattr(value, intern(k), v)

    return value
decode_dispatch[kOP_INST] = load_inst


def load_reduce(coder, setValue):
    if coder.allowsKeyedCoding():
        func = coder.decodeObjectForKey_(kFUNC)
        args = coder.decodeObjectForKey_(kARGS)

    else:
        func = coder.decodeObject()
        args = coder.decodeObject()


        new_args = []
        for a in args:
            if isinstance(a, NSDictionary):
                new_args.append(dict(a))
            elif isinstance(a, NSMutableArray):
                new_args.append(list(a))
            elif isinstance(a, NSArray):
                new_args.append(tuple(a))
            elif isinstance(a, NSMutableSet):
                new_args.append(set(a))
            elif isinstance(a, NSSet):
                new_args.append(frozenset(a))
            else:
                new_args.append(a)
        args = new_args
        del new_args

    if sys.version_info[0] == 2 and func == copyreg.__newobj__:  # pragma: no 3.x cover
        try:
            value = func(*args)
        except AttributeError:
            # copyreg.__newobj__ failed, almost certainly because
            # there is __new__ method. This happens when a class
            # is serialized in Python 3 and read back in Python 2
            # as a classic class.
            cls = args[0]
            args = args[1:]
            value = cls(*args)

    else:
        value = func(*args)

    # We now have the object, but haven't set the correct
    # state yet.  Tell the bridge about this value right
    # away, that's needed because `value` might be part
    # of the object state which we'll retrieve next.
    setValue(value)

    if coder.allowsKeyedCoding():
        listitems = coder.decodeObjectForKey_(kLIST)
        dictitems = coder.decodeObjectForKey_(kDICT)
        state = coder.decodeObjectForKey_(kSTATE)
    else:
        listitems = coder.decodeObject()
        dictitems = coder.decodeObject()
        state = coder.decodeObject()
        if isinstance(state, NSArray):
            state = tuple(state)

    setstate = getattr(value, "__setstate__", None)
    if setstate:
        setstate(state)
        return value

    slotstate = None
    if isinstance(state, tuple) and len(state) == 2:
        state, slotstate = state

    if state:
        # NOTE: picke.py catches RuntimeError here
        # to support restricted execution, that is not
        # relevant for PyObjC.
        inst_dict = value.__dict__

        for k in state:
            v = state[k]
            if type(k) == objc.pyobjc_unicode:
                inst_dict[intern(k)] = v

            elif type(k) == str:
                inst_dict[intern(k)] = v

            else:
                inst_dict[k] = v


    if slotstate:
        for k, v in slotstate.items():
            setattr(value, intern(k), v)

    if listitems:
        for a in listitems:
            value.append(a)

    if dictitems:
        for k, v in dictitems.items():
            value[k] = v

    return value
decode_dispatch[kOP_REDUCE] = load_reduce


def pyobjectEncode(self, coder):
    t = type(self)

    # Find builtin support
    f = encode_dispatch.get(t)
    if f is not None:
        f(coder, self)
        return

    # Check for a class with a custom metaclass
    # NOTE: pickle.py catches TypeError here, that's for
    #       compatibility with ancient versions of Boost
    #       (before Python 2.2) and is not needed here.
    issc = issubclass(t, type)

    if issc:
        save_global(coder, self)
        return

    # Check copyreg.dispatch_table
    reduce = copyreg.dispatch_table.get(t)
    if reduce is not None:
        rv = reduce(self)

    else:
        reduce = getattr(self, "__reduce_ex__", None)
        rv = reduce(2)

    if type(rv) is str:
        save_global(coder, self, rv)
        return

    if type(rv) is not tuple:
        raise PicklingError("%s must return string or tuple" % reduce)

    l = len(rv)
    if not (2 <= l <= 5):
        raise PicklingError("Tuple returned by %s must have two to "
                "five elements" % reduce)

    save_reduce(coder, *rv)

def pyobjectDecode(coder, setValue):
    if coder.allowsKeyedCoding():
        tp = coder.decodeIntForKey_(kKIND)
    else:
        tp = coder.decodeValueOfObjCType_at_(objc._C_INT, None)
    f = decode_dispatch.get(tp)
    if f is None:
        raise UnpicklingError("Unknown object kind: %s"%(tp,))

    return f(coder, setValue)

# An finally register the coder/decoder
objc.options._nscoding_version = 1
objc.options._nscoding_encoder = pyobjectEncode
objc.options._nscoding_decoder = pyobjectDecode
objc.options._copy = copy.copy
