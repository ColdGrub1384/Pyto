import collections.abc
import platform
import struct
from ctypes import (
    POINTER, Array, Structure, Union, c_bool, c_byte, c_char, c_char_p,
    c_double, c_float, c_int, c_long, c_longdouble, c_longlong, c_short,
    c_ubyte, c_uint, c_ulong, c_ulonglong, c_ushort, c_void_p, c_wchar,
    c_wchar_p, py_object, sizeof,
)

__all__ = [
    'CFIndex',
    'CFRange',
    'CGFloat',
    'CGGlyph',
    'CGPoint',
    'CGPointMake',
    'CGRect',
    'CGRectMake',
    'CGSize',
    'CGSizeMake',
    'NSEdgeInsets',
    'NSEdgeInsetsMake',
    'NSInteger',
    'NSIntegerMax',
    'NSMakePoint',
    'NSMakeRect',
    'NSMakeSize',
    'NSNotFound',
    'NSPoint',
    'NSRange',
    'NSRect',
    'NSSize',
    'NSTimeInterval',
    'NSUInteger',
    'NSZeroPoint',
    'UIEdgeInsets',
    'UIEdgeInsetsMake',
    'UIEdgeInsetsZero',
    'UniChar',
    'UnknownPointer',
    '__LP64__',
    '__arm64__',
    '__arm__',
    '__i386__',
    '__x86_64__',
    'compound_value_for_sequence',
    'c_ptrdiff_t',
    'ctype_for_encoding',
    'ctype_for_type',
    'ctypes_for_method_encoding',
    'encoding_for_ctype',
    'get_ctype_for_encoding_map',
    'get_ctype_for_type_map',
    'get_encoding_for_ctype_map',
    'register_ctype_for_type',
    'register_encoding',
    'register_preferred_encoding',
    'split_method_encoding',
    'unichar',
    'unregister_ctype',
    'unregister_ctype_all',
    'unregister_ctype_for_type',
    'unregister_encoding',
    'unregister_encoding_all',
    'with_encoding',
    'with_preferred_encoding',
]

__LP64__ = (8*struct.calcsize("P") == 64)

# platform.machine() indicates the machine's physical architecture,
# which means that on a 64-bit Intel machine it is always "x86_64",
# even if Python is built as 32-bit.
_any_x86 = (platform.machine() in ('i386', 'x86_64'))
__i386__ = (_any_x86 and not __LP64__)
__x86_64__ = (_any_x86 and __LP64__)

# On iOS, platform.machine() is a device identifier like "iPhone9,4",
# but the platform.version() string contains the architecture.
_any_arm = ('ARM' in platform.version())
__arm64__ = (_any_arm and __LP64__)
__arm__ = (_any_arm and not __LP64__)


_ctype_for_type_map = {
    int: c_int,
    float: c_double,
    bool: c_bool,
    bytes: c_char_p,
    object: py_object,
}


def ctype_for_type(tp):
    """Look up the ctype corresponding to the given Python type.

    This conversion is applied to types used in :class:`objc_method` signatures, :class:`objc_ivar` types, etc.
    This function translates Python built-in types and :mod:`rubicon.objc` classes to their :mod:`ctypes` equivalents.
    Unregistered types (including types that are already ctypes) are returned unchanged.
    """

    return _ctype_for_type_map.get(tp, tp)


def register_ctype_for_type(tp, ctype):
    """Register a conversion from a Python type to a ctype."""

    _ctype_for_type_map[tp] = ctype


def unregister_ctype_for_type(tp):
    """Unregister a conversion from a Python type to a ctype."""

    del _ctype_for_type_map[tp]


def get_ctype_for_type_map():
    """Get a copy of all currently registered type-to-ctype conversions as a mapping."""

    return dict(_ctype_for_type_map)


_ctype_for_encoding_map = {}
_encoding_for_ctype_map = {}


def _end_of_encoding(encoding, start):
    """Find the end index of the encoding starting at index start.
    The encoding is not validated very extensively. There are no guarantees what happens for invalid encodings;
    an error may be raised, or a bogus end index may be returned.
    """

    if start < 0 or start >= len(encoding):
        raise ValueError('Start index {} not in range({})'.format(start, len(encoding)))

    paren_depth = 0

    i = start
    while i < len(encoding):
        c = encoding[i:i+1]
        if c in b'([{<':
            # Opening parenthesis of some type, wait for a corresponding closing paren.
            # This doesn't check that the parenthesis *types* match (only the *number* of closing parens has to match).
            paren_depth += 1
            i += 1
        elif paren_depth > 0:
            if c in b')]}>':
                # Closing parentheses of some type.
                paren_depth -= 1
            i += 1
            if paren_depth == 0:
                # Final closing parenthesis, end of this encoding.
                return i
        elif c in b'*:#?BCDILQSTcdfilqstv':
            # Encodings with exactly one character.
            return i+1
        elif c in b'^ANORVjnor':
            # Simple prefix (qualifier, pointer, etc.), skip it but count it towards the length.
            i += 1
        elif c == b'@':
            if encoding[i+1:i+3] == b'?<':
                # Encoding @?<...> (block with signature).
                # Skip the @? and continue at the < which is treated as an opening paren.
                i += 2
            elif encoding[i+1:i+2] == b'?':
                # Encoding @? (block).
                return i+2
            elif encoding[i+1:i+2] == b'"':
                # Encoding @"..." (object pointer with class name).
                return encoding.index(b'"', i+2)+1
            else:
                # Encoding @ (untyped object pointer).
                return i+1
        elif c == b'b':
            # Bit field, followed by one or more digits.
            for j in range(i+1, len(encoding)):
                if encoding[j] not in b'0123456789':
                    # Found a non-digit, stop here.
                    return j
            # Reached end of string without finding a non-digit, stop.
            return len(encoding)
        else:
            raise ValueError('Unknown encoding {} at index {}: {}'.format(c, i, encoding))

    if paren_depth > 0:
        raise ValueError('Incomplete encoding, missing {} closing parentheses: {}'.format(paren_depth, encoding))
    else:
        raise ValueError('Incomplete encoding, reached end of string too early: {}'.format(encoding))


def _create_structish_type_for_encoding(encoding, *, base):
    """Create a structish type from the given encoding. ("structish" = "structure or union")
    The base kwarg controls which base class is used. It should be either ctypes.Structure or ctypes.Union.
    """

    # Split name and fields.
    begin = encoding[0:1]
    end = encoding[-1:len(encoding)]
    name, eq, fields = encoding[1:-1].partition(b'=')

    if not eq:
        # If the fields are not present, we can't create a meaningful structish.
        # We also know that there is no known structish with this name,
        # because in that case that structish would have been found by ctype_for_encoding.
        # So we pretend that this structish is a void (None).
        # This causes pointers to it to become void pointers.
        return None

    if name == b'?':
        # Anonymous structish, has no name.
        name = None

    # Create the subclass. The _fields_ are not set yet, this is done later.
    # The structish is already registered here, so that pointers to this structish type in itself are typed correctly.
    py_name = '_Anonymous' if name is None else name.decode('utf-8')
    structish_type = type(py_name, (base,), {})
    # Register the structish for its own encoding, so the same type is used in the future.
    register_encoding(encoding, structish_type)
    if name is not None:
        # If not anonymous, also register for the corresponding name-only encoding.
        register_encoding(begin + name + end, structish_type)

    # Convert the field encodings to a sequence of tuples, as needed for the _fields_ attribute.
    ctypes_fields = []
    start = 0  # Start of the next field.
    i = 0  # Field counter, used when naming unnamed fields.
    while start < len(fields):
        if fields[start:start+1] == b'"':
            # If a name is present, use it.
            field_name_end = fields.index(b'"', start+2)
            field_name = fields[start+1:field_name_end].decode('utf-8')
            start = field_name_end+1
        else:
            # If no name is present, make one based on the field index.
            field_name = 'field_{}'.format(i)
        end = _end_of_encoding(fields, start)
        field_encoding = fields[start:end]
        if field_encoding.startswith(b'b'):
            # Bit field, extract the number of bits.
            bit_field_size = int(field_encoding[1:])
            ctypes_fields.append((field_name, c_uint, bit_field_size))
        else:
            # Regular field, decode the encoding normally.
            field_type = ctype_for_encoding(field_encoding)
            ctypes_fields.append((field_name, field_type))
        start = end
        i += 1

    structish_type._fields_ = ctypes_fields

    return structish_type


def _ctype_for_unknown_encoding(encoding):
    if encoding.startswith(b'^'):
        # Resolve pointer types recursively.
        pointer_type = POINTER(ctype_for_encoding(encoding[1:]))
        register_encoding(encoding, pointer_type)
        return pointer_type
    elif encoding.startswith(b'[') and encoding.endswith(b']'):
        # Resolve array types recursively.
        for i, c in enumerate(encoding[1:], start=1):
            if c not in b'0123456789':
                break
        assert i != 1
        array_length = int(encoding[1:i].decode('utf-8'))
        array_type = ctype_for_encoding(encoding[i:-1]) * array_length
        register_encoding(encoding, array_type)
        return array_type
    elif encoding.startswith(b'{') and encoding.endswith(b'}'):
        # Create ctypes.Structure subclasses for unknown structures.
        return _create_structish_type_for_encoding(encoding, base=Structure)
    elif encoding.startswith(b'(') and encoding.endswith(b')'):
        # Create ctypes.Union subclasses for unknown unions.
        return _create_structish_type_for_encoding(encoding, base=Union)
    elif encoding.startswith(b'@?<') and encoding.endswith(b'>'):
        # Ignore block signature encoding if present.
        return ctype_for_encoding(b'@?')
    elif encoding.startswith(b'@"') and encoding.endswith(b'"'):
        # Ignore object pointer class names if present.
        return ctype_for_encoding(b'@')
    elif encoding.startswith(b'b'):
        raise ValueError('A bit field encoding cannot appear outside a structure: %s' % (encoding,))
    elif encoding.startswith(b'?'):
        raise ValueError('An unknown encoding cannot appear outside of a pointer: %s' % (encoding,))
    elif encoding.startswith(b'T') or encoding.startswith(b't'):
        raise ValueError('128-bit integers are not supported by ctypes: %s' % (encoding,))
    elif encoding.startswith(b'j'):
        raise ValueError('Complex numbers are not supported by ctypes: %s' % (encoding,))
    elif encoding.startswith(b'A'):
        raise ValueError('Atomic types are not supported by ctypes: %s' % (encoding,))
    else:
        raise ValueError('Unknown encoding: %s' % (encoding,))


def ctype_for_encoding(encoding):
    """Return the ctype corresponding to an Objective-C type encoding.

    If a ctype has been registered for the encoding, that type is returned. Otherwise, if the type encoding represents
    a compound type (pointer, array, structure, or union), the contained types are converted recursively. A new ctype
    is then created from the converted ctypes, and is registered for the encoding (so that future conversions of the
    same encoding return the same ctype).

    For example, the type encoding ``{spam=ic}`` is not registered by default. However, the contained types ``i`` and
    ``c`` are registered, so they are converted individually and used to create a new :class:`~ctypes.Structure` with
    two fields of the correct types. The new structure type is then registered for the original encoding ``{spam=ic}``
    and returned.

    :raises ValueError: if the conversion fails at any point
    """

    # Remove qualifiers, as documented in Table 6-2 here:
    # https://developer.apple.com/library/content/documentation/Cocoa/Conceptual/ObjCRuntimeGuide/Articles/ocrtTypeEncodings.html
    encoding = encoding.lstrip(b"NORVnor")

    try:
        # Look up known type encodings directly.
        return _ctype_for_encoding_map[encoding]
    except KeyError:
        return _ctype_for_unknown_encoding(encoding)


def encoding_for_ctype(ctype):
    """Return the Objective-C type encoding for the given ctypes type.

    If a type encoding has been registered for the ctype, that encoding is returned. Otherwise, if the ctype is a
    pointer type, its pointed-to type is encoded and used to construct the pointer type encoding.

    Automatic encoding of other compound types (arrays, structures, and unions) is currently not supported. To encode
    such types, a type encoding must be manually provided for them using :func:`register_preferred_encoding` or
    :func:`register_encoding`.

    :raises ValueError: if the conversion fails at any point
    """

    try:
        return _encoding_for_ctype_map[ctype]
    except KeyError:
        try:
            return b'^' + encoding_for_ctype(ctype._type_)
        except KeyError:
            raise ValueError('No type encoding known for ctype {}'.format(ctype))


def register_preferred_encoding(encoding, ctype):
    """Register a preferred conversion between an Objective-C type encoding and a ctype.

    "Preferred" means that any existing conversions in each direction are overwritten with the new conversion.
    To register an encoding without overwriting existing conversions, use :func:`register_encoding`.
    """

    _ctype_for_encoding_map[encoding] = ctype
    _encoding_for_ctype_map[ctype] = encoding


def with_preferred_encoding(encoding):
    """Register a preferred conversion between an Objective-C type encoding and the decorated ctype.

    This is equivalent to calling :func:`register_preferred_encoding` on the decorated ctype.
    """

    def _with_preferred_encoding_decorator(ctype):
        register_preferred_encoding(encoding, ctype)
        return ctype

    return _with_preferred_encoding_decorator


def register_encoding(encoding, ctype):
    """Register an additional conversion between an Objective-C type encoding and a ctype.

    "Additional" means that any existing conversions in either direction are *not* overwritten with the new conversion.
    To register an encoding and overwrite existing conversions, use :func:`register_preferred_encoding`.
    """

    _ctype_for_encoding_map.setdefault(encoding, ctype)
    _encoding_for_ctype_map.setdefault(ctype, encoding)


def with_encoding(encoding):
    """Register an additional conversion between an Objective-C type encoding and the decorated ctype.

    This is equivalent to calling :func:`register_encoding` on the decorated ctype.
    """

    def _with_encoding_decorator(ctype):
        register_encoding(encoding, ctype)
        return ctype

    return _with_encoding_decorator


def unregister_encoding(encoding):
    """Unregister the conversion from an Objective-C type encoding to its corresponding ctype.

    Note that this does not remove any conversions in the other direction (from a ctype to this encoding). These
    conversions may be replaced with :func:`register_encoding`, or unregistered with :func:`unregister_ctype`.
    To remove all ctypes for an encoding, use :func:`unregister_encoding_all`.

    If the encoding was not registered previously, nothing happens.
    """

    _ctype_for_encoding_map.pop(encoding, None)


def unregister_encoding_all(encoding):
    """Unregister all conversions between an Objective-C type encoding and all corresponding ctypes.

    All conversions from any ctype to this encoding are removed recursively using :func:`unregister_ctype_all`.

    If the encoding was not registered previously, nothing happens.
    """

    _ctype_for_encoding_map.pop(encoding, None)
    for ct, enc in list(_encoding_for_ctype_map.items()):
        if enc == encoding:
            unregister_ctype_all(ct)


def unregister_ctype(ctype):
    """Unregister the conversion from a ctype to its corresponding Objective-C type encoding.

    Note that this does not remove any conversions in the other direction (from an encoding to this ctype). These
    conversions may be replaced with :func:`register_encoding`, or unregistered with :func:`unregister_encoding`.
    To remove all encodings for a ctype, use :func:`unregister_ctype_all`.

    If the ctype was not registered previously, nothing happens.
    """

    _encoding_for_ctype_map.pop(ctype, default=None)


def unregister_ctype_all(ctype):
    """Unregister all conversions between a ctype and all corresponding Objective-C type encodings.

    All conversions from any type encoding to this ctype are removed recursively using :func:`unregister_encoding_all`.

    If the ctype was not registered previously, nothing happens.
    """

    _encoding_for_ctype_map.pop(ctype, default=None)
    for enc, ct in list(_ctype_for_encoding_map.items()):
        if ct == ctype:
            unregister_encoding_all(enc)


def get_ctype_for_encoding_map():
    """Get a copy of all currently registered encoding-to-ctype conversions as a map."""

    return dict(_ctype_for_encoding_map)


def get_encoding_for_ctype_map():
    """Get a copy of all currently registered ctype-to-encoding conversions as a map."""

    return dict(_encoding_for_ctype_map)


def split_method_encoding(encoding):
    """Split a method signature encoding into a sequence of type encodings.

    The first type encoding represents the return type, all remaining type encodings represent the argument types.

    If there are any numbers after a type encoding, they are ignored. On PowerPC, these numbers indicated each
    argument/return value's offset on the stack. These numbers are meaningless on modern architectures.
    """

    encodings = []
    start = 0
    while start < len(encoding):
        # Find the end of the current encoding
        end = _end_of_encoding(encoding, start)
        encodings.append(encoding[start:end])
        start = end
        # Skip the legacy stack offsets
        while start < len(encoding) and encoding[start] in b"0123456789":
            start += 1

    return encodings


def ctypes_for_method_encoding(encoding):
    """Convert a method signature encoding into a sequence of ctypes.

    This is equivalent to first splitting the method signature encoding using :func:`split_method_encoding`, and then
    converting each individual type encoding using :func:`ctype_for_encoding`.
    """

    return [ctype_for_encoding(enc) for enc in split_method_encoding(encoding)]


def _struct_for_sequence(seq, struct_type):
    if len(seq) != len(struct_type._fields_):
        raise ValueError(
            'Struct type {tp.__module__}.{tp.__qualname__} has {fields_len} fields, '
            'but a sequence of length {seq_len} was given'
            .format(tp=struct_type, fields_len=len(struct_type._fields_), seq_len=len(seq))
        )

    values = []
    for value, (field_name, field_type, *_) in zip(seq, struct_type._fields_):
        if issubclass(field_type, (Structure, Array)) and isinstance(value, collections.abc.Iterable):
            values.append(compound_value_for_sequence(value, field_type))
        else:
            values.append(value)

    return struct_type(*values)


def _array_for_sequence(seq, array_type):
    if len(seq) != array_type._length_:
        raise ValueError(
            'Array type {tp.__module__}.{tp.__qualname__} has {array_len} fields, '
            'but a sequence of length {seq_len} was given'
            .format(tp=array_type, array_len=array_type._length_, seq_len=len(seq))
        )

    if issubclass(array_type._type_, (Structure, Array)):
        values = []
        for value in seq:
            if isinstance(value, collections.abc.Iterable):
                values.append(compound_value_for_sequence(value, array_type._type_))
            else:
                values.append(value)
    else:
        values = seq

    return array_type(*values)


def compound_value_for_sequence(seq, tp):
    """Create a C structure or array of type ``tp``, initialized with values from ``seq``.

    If ``tp`` is a :class:`~ctypes.Structure` type, the newly created structure's fields are initialized in declaration
    order with the values from ``seq``. ``seq`` must have as many elements as the structure has fields.

    If ``tp`` is a :class:`~ctypes.Array` type, the newly created array is initialized with the values from ``seq``.
    ``seq`` must have as many elements as the array type.

    In both cases, if a structure field type or the array element type is itself a structure or array type, the
    corresponding value from ``seq`` is recursively converted as well.
    """

    if issubclass(tp, Structure):
        return _struct_for_sequence(seq, tp)
    elif issubclass(tp, Array):
        return _array_for_sequence(seq, tp)
    else:
        raise TypeError("Don't know how to convert a sequence to a {tp.__module__}.{tp.__qualname__}".format(tp=tp))


# Register all type encoding mappings.

register_preferred_encoding(b'v', None)
register_preferred_encoding(b'B', c_bool)

register_preferred_encoding(b'c', c_byte)
register_preferred_encoding(b'C', c_ubyte)

register_preferred_encoding(b's', c_short)
register_preferred_encoding(b'S', c_ushort)
register_preferred_encoding(b'l', c_long)
register_preferred_encoding(b'L', c_ulong)

# Do not register c_int or c_longlong as preferred.
# If c_int or c_longlong is the same size as c_long, ctypes makes it an alias
# for c_long. If we would register c_int and c_longlong as preferred, this
# could cause c_long to be encoded as b'i' or b'q', instead of b'l'.
# The same applies to the unsigned versions.
register_encoding(b'i', c_int)
register_encoding(b'I', c_uint)
register_encoding(b'q', c_longlong)
register_encoding(b'Q', c_ulonglong)

register_preferred_encoding(b'f', c_float)
register_preferred_encoding(b'd', c_double)
# As above, c_longdouble may be c_double, so do not make it preferred.
register_encoding(b'D', c_longdouble)

# c_char encodes the same as c_byte.
# ctypes converts c_char values to a one-character bytestring, which is
# usually not the desired behavior, especially since BOOL is c_byte on
# 32-bit, and truth tests work differently for bytestrings than for numbers.
# So we do not make this mapping preferred.
register_encoding(b'c', c_char)

# Strictly speaking, c_char_p is only appropriate for actual C strings
# (null-terminated pointers to char without explicit signedness).
# However, all char pointers encode to b'*', regardless of signedness, and
# they might point to non-null-terminated data.
# Despite this, we prefer to map b'*' to c_char_p, because its most common
# use is for C strings.
register_preferred_encoding(b'*', c_char_p)
# Register the other char pointers, so they are all correctly mapped to b'*'.
# The compiler never generates encodings b'^c' or b'^C'.
register_encoding(b'*', POINTER(c_char))
register_encoding(b'*', POINTER(c_byte))
register_encoding(b'*', POINTER(c_ubyte))

# c_wchar encodes the same as c_int, and c_wchar_p the same as POINTER(c_int).
# wchar_t is rarely used in Objective-C, so we do not make c_wchar or
# c_wchar_p preferred.
register_encoding(b'i', c_wchar)
register_encoding(b'^i', c_wchar_p)
# Register POINTER(c_int) as preferred so it takes precedence over c_wchar_p.
# (Other pointer types are resolved automatically by ctype_for_encoding and
# encoding_for_ctype.)
register_preferred_encoding(b'^i', POINTER(c_int))

register_preferred_encoding(b'^v', c_void_p)


# Note CGBase.h located at
# /System/Library/Frameworks/ApplicationServices.framework/Frameworks/CoreGraphics.framework/Headers/CGBase.h
# defines CGFloat as double if __LP64__, otherwise it's a float.
if __LP64__:
    c_ptrdiff_t = c_long
    NSInteger = c_long
    NSUInteger = c_ulong
    CGFloat = c_double
    _NSPointEncoding = _CGPointEncoding = b'{CGPoint=dd}'
    _NSSizeEncoding = _CGSizeEncoding = b'{CGSize=dd}'
    _NSRectEncoding = _CGRectEncoding = b'{CGRect={CGPoint=dd}{CGSize=dd}}'
    _NSRangeEncoding = b'{_NSRange=QQ}'
    _UIEdgeInsetsEncoding = b'{UIEdgeInsets=dddd}'
    _NSEdgeInsetsEncoding = b'{NSEdgeInsets=dddd}'
    _PyObjectEncoding = b'^{_object=q^{_typeobject}}'
else:
    c_ptrdiff_t = c_int
    NSInteger = c_int
    NSUInteger = c_uint
    CGFloat = c_float
    _NSPointEncoding = b'{_NSPoint=ff}'
    _CGPointEncoding = b'{CGPoint=ff}'
    _NSSizeEncoding = b'{_NSSize=ff}'
    _CGSizeEncoding = b'{CGSize=ff}'
    _NSRectEncoding = b'{_NSRect={_NSPoint=ff}{_NSSize=ff}}'
    _CGRectEncoding = b'{CGRect={CGPoint=ff}{CGSize=ff}}'
    _NSRangeEncoding = b'{_NSRange=II}'
    _UIEdgeInsetsEncoding = b'{UIEdgeInsets=ffff}'
    _NSEdgeInsetsEncoding = b'{NSEdgeInsets=ffff}'
    _PyObjectEncoding = b'^{_object=i^{_typeobject}}'

register_preferred_encoding(_PyObjectEncoding, py_object)


@with_preferred_encoding(b'^?')
# Anonymous structs/unions with unknown fields can't be decoded meaningfully,
# so we treat pointers to them as unknown pointers.
@with_encoding(b'^{?}')
@with_encoding(b'^(?)')
class UnknownPointer(c_void_p):
    """Placeholder for the "unknown pointer" types ``^?``, ``^{?}`` and ``^(?)``.

    Not to be confused with a ``^v`` void pointer.

    Usually a ``^?`` is a function pointer, but because the encoding doesn't contain the function signature,
    you need to manually create a CFUNCTYPE with the proper types, and cast this pointer to it.

    ``^{?}`` and ``^(?)`` are pointers to a structure or union (respectively) with unknown name and fields. Such a type
    also cannot be used meaningfully without casting it to the correct pointer type first.
    """


# from /System/Library/Frameworks/Foundation.framework/Headers/NSGeometry.h
@with_preferred_encoding(_NSPointEncoding)
class NSPoint(Structure):
    _fields_ = [
        ("x", CGFloat),
        ("y", CGFloat)
    ]


if _CGPointEncoding == _NSPointEncoding:
    CGPoint = NSPoint
else:
    @with_preferred_encoding(_CGPointEncoding)
    class CGPoint(Structure):
        _fields_ = [
            ("x", CGFloat),
            ("y", CGFloat)
        ]


@with_preferred_encoding(_NSSizeEncoding)
class NSSize(Structure):
    _fields_ = [
        ("width", CGFloat),
        ("height", CGFloat)
    ]


if _CGSizeEncoding == _NSSizeEncoding:
    CGSize = NSSize
else:
    @with_preferred_encoding(_CGSizeEncoding)
    class CGSize(Structure):
        _fields_ = [
            ("width", CGFloat),
            ("height", CGFloat)
        ]


@with_preferred_encoding(_NSRectEncoding)
class NSRect(Structure):
    _fields_ = [
        ("origin", NSPoint),
        ("size", NSSize)
    ]


if _CGRectEncoding == _NSRectEncoding:
    CGRect = NSRect
else:
    @with_preferred_encoding(_CGRectEncoding)
    class CGRect(Structure):
        _fields_ = [
            ("origin", CGPoint),
            ("size", CGSize)
        ]


def NSMakeSize(w, h):
    return NSSize(w, h)


def CGSizeMake(w, h):
    return CGSize(w, h)


def NSMakeRect(x, y, w, h):
    return NSRect(NSPoint(x, y), NSSize(w, h))


def CGRectMake(x, y, w, h):
    return CGRect(CGPoint(x, y), CGSize(w, h))


def NSMakePoint(x, y):
    return NSPoint(x, y)


def CGPointMake(x, y):
    return CGPoint(x, y)


# iOS: /System/Library/Frameworks/UIKit.framework/Headers/UIGeometry.h
@with_preferred_encoding(_UIEdgeInsetsEncoding)
class UIEdgeInsets(Structure):
    _fields_ = [('top', CGFloat),
                ('left', CGFloat),
                ('bottom', CGFloat),
                ('right', CGFloat)]


def UIEdgeInsetsMake(top, left, bottom, right):
    return UIEdgeInsets(top, left, bottom, right)


UIEdgeInsetsZero = UIEdgeInsets(0, 0, 0, 0)


# macOS: /System/Library/Frameworks/AppKit.framework/Headers/NSLayoutConstraint.h
@with_preferred_encoding(_NSEdgeInsetsEncoding)
class NSEdgeInsets(Structure):
    _fields_ = [('top', CGFloat),
                ('left', CGFloat),
                ('bottom', CGFloat),
                ('right', CGFloat)]


def NSEdgeInsetsMake(top, left, bottom, right):
    return NSEdgeInsets(top, left, bottom, right)

# strangely, there is no NSEdgeInsetsZero, neither in public nor in private API.


# NSDate.h
NSTimeInterval = c_double

CFIndex = c_long
UniChar = c_ushort
unichar = c_ushort
CGGlyph = c_ushort


# CFRange struct defined in CFBase.h
# This replaces the CFRangeMake(LOC, LEN) macro.
class CFRange(Structure):
    _fields_ = [
        ("location", CFIndex),
        ("length", CFIndex)
    ]


# NSRange.h  (Note, not defined the same as CFRange)
@with_preferred_encoding(_NSRangeEncoding)
class NSRange(Structure):
    _fields_ = [
        ("location", NSUInteger),
        ("length", NSUInteger)
    ]


NSZeroPoint = NSPoint(0, 0)


if sizeof(c_void_p) == 4:
    NSIntegerMax = 0x7fffffff
elif sizeof(c_void_p) == 8:
    NSIntegerMax = 0x7fffffffffffffff
NSNotFound = NSIntegerMax
