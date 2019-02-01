"""
This script is an example of how importing files from other apps.
"""

import sharing

filePicker = sharing.FilePicker.new()
filePicker.fileTypes = ["public.data"] # UTI types to import
filePicker.allowsMultipleSelection = True # Set to `False` if you want to import just one file.

def files_picked() -> None:
    """
    This function is called when files are picked.
    """

    files = sharing.picked_files() # Picked files as NSURLs

    for file in files:
        print("Do something with", file.path)

filePicker.completion = files_picked
sharing.pick_documents(filePicker)
