# mainthread

This module allows you to run code on the main thread easely. This can be used for modifiying the UI.

**These APIs are available on Pyto 2.4+**

## Example:

```python
import mainthread

def sayHello() -> None:
    print("Hello World!")

mainthread.runSync(sayHello)
```

## `runAsync(code)`

Runs the given code asynchronously on the main thread.

- code: Code to execute in the main thread.

## `runSync(code)`

Runs the given code synchronously on the main thread.

- code: Code to execute in the main thread.
