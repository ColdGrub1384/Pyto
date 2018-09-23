# app

This module represents a Home Screen shortcut for your script.

Example:

```python
print("Hello World!")

import app
app.name = "Hello"
app.identifier = "pyto.helloworld"
app.install()
```

## `name`

The title of the icon in the Home Screen.

## `identifier`

The unique identifier of your script.

## `def isAppRunning()`

Returns `True` if the current running script is ran from the Home Screen.

## `def install()`

Installs a Home Screen icon for the current running script with configured name and identifier.

