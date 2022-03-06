"""
Module used internally by Pyto for redirecting output.
"""

import sys

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
        return True

    def writable(self):
        return True

    def flush(self):
        pass

    def write(self, txt):
        if txt.__class__ is str:
            self.__handler__(txt)
        elif txt.__class__ is bytes:
            text = txt.decode()
            self.write(text)


__all__ = ["Reader"]
