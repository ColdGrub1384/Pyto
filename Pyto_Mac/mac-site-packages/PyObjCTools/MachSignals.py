"""
Substitute for the signal module when using a CFRunLoop.

This module is generally only used to support:
    PyObjCTools.AppHelper.installMachInterrupt()

A mach port is opened and registered to the CFRunLoop.
When a signal occurs the signal number is sent in a mach
message to the CFRunLoop.  The handler then causes Python
code to get executed.

In other words, Python's signal handling code does not wake
reliably when not running Python code, but this does.
"""

from objc import _machsignals
__all__ = ['getsignal', 'signal']

def getsignal(signum):
    """
    Return the signal handler for signal ``signum``. Returns ``None`` when
    there is no signal handler for the signal.
    """
    return _machsignals._signalmapping.get(signum)

def signal(signum, handler):
    """
    Install a new signal handler for ``signum``. Returns the old signal
    handler (``None`` when there is no previous handler.
    """
    rval = getsignal(signum)
    _machsignals._signalmapping[signum] = handler
    _machsignals.handle_signal(signum)
    return rval
