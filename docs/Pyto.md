# pyto

This module allows you to interact with Pyto with a Pythonic API.

### Input

## `input(prompt)`

Requests input with given prompt.

- prompt: The title of the shown alert.

### Output

## `print(*objects, sep, end)`

Prints to the Pyto console, not to the stdout. Works as the builtin `print` function but does not support printing to a custom file.

### Sharing

## `FilePicker`
(Wraps [PyFIlePicker](PyFilePicker))

A class representing a file picker.

Example:

```python
filePicker = pyto.FilePicker.new()
filePicker.fileTypes = ["public.data"]
filePicker.allowsMultipleSelection = True

def filesPicked() -> None:
    files = pyto.pickedFiles()
    pyto.shareItems(files)

filePicker.completion = filesPicked
pyto.pickDocumentsWithFilePicker(filePicker)
```

## `shareItems(items)`

Opens a share sheet with given items.

- items: Items to be shared with the sheet.

## `pickedFiles()`

Returns files picked with `pickDocumentsWithFilePicker` as URLs.

## `pickDocumentsWithFilePicker(filePicker)`

Pick documents with given parameters as a `FilePicker`.

- filePicker: The parameters of the file picker to be presented.

### Alerts

## `Alert`
(Wraps [PyAlert](PyAlert))

A class representing an alert.

Example:

```python
def ok() -> None:
    print("Good Bye!")

alert = pyto.Alert.initWithTitle("Hello", message="Hello World!")
alert.addActionWithTitle("Ok", handler=ok)
alert.addCancelActionWithTitle("Cancel", handler=None)
alert.show()
```

### Action extension

## `extensionContext()`
Returns the extension context if the script is ran from the share sheet. Use it like any `NSExtensionContext`.
