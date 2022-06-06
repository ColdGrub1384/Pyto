"""
Module used internally by Pyto for redirecting output.
"""

import io

def isatty():
    sys = __import__("sys")
    try:
        return (not sys.__is_shortcut__)
    except AttributeError:
        return True

class Reader:
    """
    Class used as file to be passed to `sys.stdout` and `sys.stderr`.
    """

    __handler__ = None

    errors = "surrogateescape"  # ???

    encoding = "utf-8"

    @property
    def buffer(self):
        return self._buffer

    @property
    def encoding(self):
        return "utf-8"

    @property
    def closed(self):
        return False
    
    def close(self):
        pass

    def __init__(self, handler):
        """
        Initializes the file.
        
        Args:
            handler: Block to be called when output is received. The block should receive a String.
        """
        self.__handler__ = handler

    def isatty(self):
        return isatty()

    def writable(self):
        return True

    def readable(self):
        return False

    def flush(self):
        pass

    def read(*args):
        msg = "not readable"
        raise io.UnsupportedOperation(msg)

    def readline(*args):
        msg = "not readable"
        raise io.UnsupportedOperation(msg)

    def write(self, txt):
        if txt.__class__ is str:
            self.__handler__(txt)
        elif txt.__class__ is bytes:
            text = txt.decode()
            self.write(text)

    def detach(self):
        return self

class InputReader:
    """
    Class used as file to be passed to `sys.stdin`.
    """

    errors = "surrogateescape"  # ???

    encoding = "utf-8"

    @property
    def buffer(self):
        return self._buffer

    @property
    def encoding(self):
        return "utf-8"

    @property
    def closed(self):
        return False
    
    def close(self):
        pass

    def __init__(self):
        pass

    def isatty(self):
        return isatty()

    def writable(self):
        return False

    def readable(self):
        return True

    def flush(self):
        pass

    def read(self):
        return input("")
    
    def readline(self):
        return input("")

    def write(self, txt):
        msg = "not writable"
        raise io.UnsupportedOperation(msg)

    def detach(self):
        return self

__all__ = ["Reader", "InputReader"]
