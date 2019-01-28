import JavaScriptCore
import contextlib

@contextlib.contextmanager
def autoreleasing(value):
    try:
        yield value

    finally:
        if isinstance(value, JavaScriptCore.JSContextGroupRef):
            JavaScriptCore.JSContextGroupRelease(value)

        elif isinstance(value, JavaScriptCore.JSGlobalContextRef):
            JavaScriptCore.JSGlobalContextRelease(value)

        elif isinstance(value, JavaScriptCore.JSClassRef):
            JavaScriptCore.JSClassRelease(value)

        elif isinstance(value, JavaScriptCore.JSPropertyNameArrayRef):
            JavaScriptCore.JSPropertyNameArrayRelease(value)

        elif isinstance(value, JavaScriptCore.JSStringRef):
            JavaScriptCore.JSStringRelease(value)


