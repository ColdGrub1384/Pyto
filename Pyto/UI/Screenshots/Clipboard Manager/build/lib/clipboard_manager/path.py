"""
Functions for working with paths.
"""

import os

history_path = "history"
"""
The directory where the clipboard will be saved.
"""

def make_path(i: int, ext: str) -> str:
    """
    Returns a path from the given number and path extension.
    """
    
    return os.path.join(history_path, str(i) + "." + ext)


def find_available_filename(ext: str) -> str:
    """
    Returns an available filename with the given path extension.
    """
    
    i = 1
    while os.path.isfile(make_path(i, ext)):
        i += 1

    return make_path(i, ext)