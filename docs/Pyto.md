# pyto

This module allows you to interact with Pyto with a Pythonic API.

### I/O

## `input(prompt)`

Requests input with given prompt.

- prompt: Text printed before the user's input without a newline.

### Output

## `print(*objects, sep, end)`

Prints to the Pyto console, not to the stdout. Works as the builtin `print` function but does not support printing to a custom file. Pyto catches by default the stdout and the stderr, so use the builtin function instead. This function is mainly for internal use.

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

## `extensionItems()`
Returns the items shared trough the share sheet. Loaded with `NSExtensionContext`.

### Importing

## `module(name)`
Returns the given module located in the app's Documents directory.

- The name of the script without the extension located in the Documents directory.
