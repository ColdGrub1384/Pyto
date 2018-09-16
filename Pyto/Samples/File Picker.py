import Pyto
__builtins__.input = Pyto.input
__builtins__.print = Pyto.print

# Code here

def filesPicked() -> None:
  Pyto.shareItems(Pyto.pickedFiles())

filePicker = Pyto.FilePicker.new()
filePicker.fileTypes = ["public.data"]
filePicker.completion = filesPicked
Pyto.pickDocumentsWithFilePicker(filePicker)
