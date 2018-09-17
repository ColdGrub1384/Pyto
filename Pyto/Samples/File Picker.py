import Pyto

# Code here

def filesPicked() -> None:
  Pyto.shareItems(Pyto.pickedFiles())

filePicker = Pyto.FilePicker.new()
filePicker.fileTypes = ["public.data"]
filePicker.completion = filesPicked
Pyto.pickDocumentsWithFilePicker(filePicker)
