"""
Classes from the 'JavaScriptCore' framework.
"""

try:
    from rubicon.objc import ObjCClass
except ValueError:

    def ObjCClass(name):
        return None


def _Class(name):
    try:
        return ObjCClass(name)
    except NameError:
        return None


JSExport = _Class("JSExport")
WTFWebFileManagerDelegate = _Class("WTFWebFileManagerDelegate")
JSObjCClassInfo = _Class("JSObjCClassInfo")
JSScript = _Class("JSScript")
JSManagedValue = _Class("JSManagedValue")
JSValue = _Class("JSValue")
JSWrapperMap = _Class("JSWrapperMap")
JSVMWrapperCache = _Class("JSVMWrapperCache")
JSVirtualMachine = _Class("JSVirtualMachine")
JSContext = _Class("JSContext")
