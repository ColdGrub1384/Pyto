"""
Low level debugging helper for PyObjC.

Allows you to log Python and ObjC (via atos) stack traces for NSExceptions
raised.

General guidelines for use:

- It's typically only useful when you log EVERY exception, because Foundation
  and AppKit will swallow most of them.  This means that you should never
  use this module in a release build.

- Typical use involves only calling installExceptionHandler or
  installVerboseExceptionHandler.  It may be removed at any time by calling
  removeDebuggingHandler.
"""
from __future__ import print_function

from Foundation import NSObject, NSLog
import objc
import os
import sys

import traceback
from ExceptionHandling import NSExceptionHandler, NSLogUncaughtExceptionMask, NSLogAndHandleEveryExceptionMask, NSStackTraceKey

DEFAULTMASK = NSLogUncaughtExceptionMask
EVERYTHINGMASK = NSLogAndHandleEveryExceptionMask


__all__ = [
    'LOGSTACKTRACE', 'DEFAULTVERBOSITY', 'DEFAULTMASK', 'EVERYTHINGMASK',
    'installExceptionHandler', 'installVerboseExceptionHandler',
    'installPythonExceptionHandler', 'removeExceptionHandler',
    'handlerInstalled',
]

def isPythonException(exception):
    if hasattr(exception, '_pyobjc_info_'):
        return False

    if not hasattr(exception, 'userInfo'):
        return True

    return (exception.userInfo() or {}).get('__pyobjc_exc_type__') is not None

def nsLogPythonException(exception):
    userInfo = exception.userInfo()
    NSLog('%@', '*** Python exception discarded!\n' +
        ''.join(traceback.format_exception(
        userInfo['__pyobjc_exc_type__'],
        userInfo['__pyobjc_exc_value__'],
        userInfo['__pyobjc_exc_traceback__'],
    )))
    # we logged it, so don't log it for us
    return False


_atos_command = None

def _run_atos(stack):
    global _atos_command
    if _atos_command is None:
        if os.path.exists('/usr/bin/atos'):
            _atos_command = '/usr/bin/atos'

            if os.uname()[2].startswith('13.'):
                # The atos command on OSX 10.9 gives a usage
                # warning that's surpressed with the "-d" option.
                _atos_command += ' -d'

        elif os.path.exists('/usr/bin/xcrun'):
            _atos_command = '/usr/bin/xcrun atos'

        else:
            return None

    return os.popen('%s -p %s %s'%(_atos_command, os.getpid(), stack))

def nsLogObjCException(exception):
    stacktrace = None

    try:
        stacktrace = exception.callStackSymbols()

    except AttributeError:
        pass

    if stacktrace is None:
        stack = exception.callStackReturnAddresses()
        if stack:
            pipe = _run_atos(" ".join(hex(v) for v in stack))
            if pipe is None:
                return True

            stacktrace = pipe.readlines()
            stacktrace.reverse()
            pipe.close()

    if stacktrace is None:
        userInfo = exception.userInfo()
        stack = userInfo.get(NSStackTraceKey)
        if not stack:
            return True

        pipe = _run_atos(stack)
        if pipe is None:
            return True

        stacktrace = pipe.readlines()
        stacktrace.reverse()
        pipe.close()

    NSLog("%@", "*** ObjC exception '%s' (reason: '%s') discarded\n" % (
            exception.name(), exception.reason(),
        ) +
        'Stack trace (most recent call last):\n' +
        ''.join([('  '+line) for line in stacktrace])
    )
    return False

LOGSTACKTRACE = 1 << 0
DEFAULTVERBOSITY = 0

class PyObjCDebuggingDelegate(NSObject):
    verbosity = objc.ivar('verbosity', b'i')

    def initWithVerbosity_(self, verbosity):
        self = self.init()
        self.verbosity = verbosity
        return self

    @objc.typedSelector(b'c@:@@I')
    def exceptionHandler_shouldLogException_mask_(self, sender, exception, aMask):
        try:
            if isPythonException(exception):
                if self.verbosity & LOGSTACKTRACE:
                    nsLogObjCException(exception)
                return nsLogPythonException(exception)
            elif self.verbosity & LOGSTACKTRACE:
                return nsLogObjCException(exception)
            else:
                return False
        except:
            print("*** Exception occurred during exception handler ***",
                    file=sys.stderr)
            traceback.print_exc(sys.stderr)
            return True

    @objc.typedSelector(b'c@:@@I')
    def exceptionHandler_shouldHandleException_mask_(self, sender, exception, aMask):
        return False

def installExceptionHandler(verbosity=DEFAULTVERBOSITY, mask=DEFAULTMASK):
    """
    Install the exception handling delegate that will log every exception
    matching the given mask with the given verbosity.
    """
    # we need to retain this, cause the handler doesn't
    global _exceptionHandlerDelegate
    delegate = PyObjCDebuggingDelegate.alloc().initWithVerbosity_(verbosity)
    NSExceptionHandler.defaultExceptionHandler().setExceptionHandlingMask_(mask)
    NSExceptionHandler.defaultExceptionHandler().setDelegate_(delegate)
    _exceptionHandlerDelegate = delegate

def installPythonExceptionHandler():
    """
    Install a verbose exception handling delegate that logs every exception
    raised.

    Will log only Python stack traces, if available.
    """
    installExceptionHandler(verbosity=DEFAULTVERBOSITY, mask=EVERYTHINGMASK)

def installVerboseExceptionHandler():
    """
    Install a verbose exception handling delegate that logs every exception
    raised.

    Will log both Python and ObjC stack traces, if available.
    """
    installExceptionHandler(verbosity=LOGSTACKTRACE, mask=EVERYTHINGMASK)

def removeExceptionHandler():
    """
    Remove the current exception handler delegate
    """
    NSExceptionHandler.defaultExceptionHandler().setDelegate_(None)
    NSExceptionHandler.defaultExceptionHandler().setExceptionHandlingMask_(0)

def handlerInstalled():
    """
    Is an exception handler delegate currently installed?
    """
    return NSExceptionHandler.defaultExceptionHandler().delegate() is not None
