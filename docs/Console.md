# console

This module gives access to the console.

## `clear()`

Clears the console.

### I/O

## `input(prompt)`

Requests input with given prompt.

- prompt: Text printed before the user's input without a newline.


## `print(*objects, sep, end)`

Prints to the Pyto console, not to the stdout. Works as the builtin `print` function but does not support printing to a custom file. Pyto catches by default the stdout and the stderr, so use the builtin function instead. This function is mainly for internal use.
