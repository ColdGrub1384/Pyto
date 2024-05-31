"""
Saves the content of the clipboard in a directory.

Enable PIP and run the script with the play button to save the content of your clipboard.
Run with the argument 'reset' to reset the destination directory.
"""

import pasteboard as pb
import file_system as fs
import sys
import os


history_path = None


def make_path(i: int, ext: str) -> str:
    return os.path.join(history_path, str(i) + "." + ext)


def find_available_filename(ext: str) -> str:
    
    i = 1
    while os.path.isfile(make_path(i, ext)):
        i += 1

    return make_path(i, ext)


def main():
    global history_path
    
    history = fs.FolderBookmark(name="clipboard_history")
    
    if "reset" in sys.argv:
        history.delete_from_disk()
        history = fs.FolderBookmark(name="clipboard_history")
    
    history_path = history.path
    
    if pb.string() is not None:
        
        print("Saved text")
        
        path = find_available_filename("txt")
        with open(path, "w+") as f:
            f.write(pb.string())
    
        pb.set_string(None)
    
    if pb.image() is not None:
        
        print("Saved image")
        
        path = find_available_filename("png")
        pb.image().save(path, format="png")
        pb.set_image(None)


if __name__ == "__main__":
    main()
