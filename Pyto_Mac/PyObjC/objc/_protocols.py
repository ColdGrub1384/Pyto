from objc import _objc
import sys

__all__ = ['protocolNamed', 'ProtocolError']

class ProtocolError(_objc.error):
    __module__ = 'objc'

PROTOCOL_CACHE = {}
def protocolNamed(name):
    """
    Returns a Protocol object for the named protocol. This is the
    equivalent of @protocol(name) in Objective-C.
    Raises objc.ProtocolError when the protocol does not exist.
    """
    if sys.version_info[0] == 2:  # pragma: no 3.x cover; pragma: no branch
        name = unicode(name)

    try:
        return PROTOCOL_CACHE[name]
    except KeyError:
        pass
    for p in _objc.protocolsForProcess():
        pname = p.__name__
        PROTOCOL_CACHE.setdefault(pname, p)
        if pname == name:
            return p
    for cls in _objc.getClassList():
        for p in _objc.protocolsForClass(cls):
            pname = p.__name__
            PROTOCOL_CACHE.setdefault(pname, p)
            if pname == name:
                return p
    raise ProtocolError("protocol %r does not exist" % (name,), name)
