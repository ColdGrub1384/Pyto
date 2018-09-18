"""
Asks the user for selecting files and shares them.
"""

import sharing

# Code here

def filesPicked() -> None:
  sharing.shareItems(sharing.pickedFiles())

filePicker = sharing.FilePicker.new()
filePicker.fileTypes = ["public.data"]
filePicker.completion = filesPicked
sharing.pickDocumentsWithFilePicker(filePicker)
