import objc
from AppKit import __bundle__

class _NSApp (object):
    """
    Helper class to emulate NSApp in Python.
    """
    def __getrealapp(self):
        d = {}
        objc.loadBundleVariables(__bundle__, d, [ ('NSApp', b'@' ) ])
        return d.get('NSApp')

    __class__ = property(lambda self: self.__getrealapp().__class__)

    def __getattr__(self, name):
        return getattr(self.__getrealapp(), name)

    def __setattr__(self, name, value):
        return setattr(self.__getrealapp(), name, value)

    def __call__(self):
        # Compatibility with previous versions.
        return self.__getrealapp()

NSApp = _NSApp()
del _NSApp
