"""
Saves the content of the clipboard in a directory.

Can run in background with Picture in Picture.
"""

import pasteboard
from .path import find_available_filename

def main():
    
    if pasteboard.string() is not None:
        
        print("Saved text")
        
        path = find_available_filename("txt")
        with open(path, "w+") as f:
            f.write(pasteboard.string())
    
        pasteboard.set_string(None)
    
    if pasteboard.image() is not None:
        
        print("Saved image")
        
        path = find_available_filename("png")
        pasteboard.image().save(path, format="png")
        pasteboard.set_image(None)


if __name__ == "__main__":
    main()