"""
Saves the content of the clipboard in a directory.

Can run in background with Picture in Picture.
"""

import pasteboard
from .path import find_available_filename

if pasteboard.string() is not None:
    
    print("\nSaved text")
    
    path = find_available_filename("txt")
    with open(path, "w+") as f:
        f.write(pasteboard.string())

    pasteboard.set_string(None)

if pasteboard.image() is not None:
    
    print("\nSaved image")
    
    path = find_available_filename("png")
    pasteboard.image().save(path, format="png")
    pasteboard.set_image(None)
