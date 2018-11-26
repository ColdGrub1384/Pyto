# sharing

This module allows you to share items and to import files.

## `shareItems()`

Opens a share sheet with given items.

- items: Items to be shared with the sheet.

## `FilePicker`
(Wraps [PyFilePicker](PyFilePicker))

A class representing a file picker.

Example:

```python
filePicker = sharing.FilePicker.new()
filePicker.fileTypes = ["public.data"]
filePicker.allowsMultipleSelection = True

def filesPicked() -> None:
    files = sharing.pickedFiles()
    sharing.shareItems(files)

filePicker.completion = filesPicked
sharing.pickDocumentsWithFilePicker(filePicker)
```

## `pickDocumentsWithFilePicker(filePicker)`

Pick documents with given parameters as a `FilePicker`.

- filePicker: The parameters of the file picker to be presented.


## `pickedFiles()`

Returns files picked with `pickDocumentsWithFilePicker` as URLs.

### URLs

## `openURL(url)`

Opens the given URL.

- url: URL to open. Can be a String or an Objective-C `NSURL`.
