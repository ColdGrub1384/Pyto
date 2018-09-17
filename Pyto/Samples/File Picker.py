"""
Asks the user for selecting files and shares them.
"""

import pyto

# Code here

def filesPicked() -> None:
  pyto.shareItems(pyto.pickedFiles())

filePicker = pyto.FilePicker.new()
filePicker.fileTypes = ["public.data"]
filePicker.completion = filesPicked
pyto.pickDocumentsWithFilePicker(filePicker)
