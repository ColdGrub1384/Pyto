# mainthread

This module allows you to run code on the main thread easely. This can be used for modifiying the UI.

## Example:

```python
import mainthread

def sayHello() -> None:
    print("Hello World!")

mainthread.async(sayHello)
```

## `async(code)`

Runs the given code asynchronously on the main thread.

- code: Code to execute in the main thread.

## `sync(code)`

Runs the given code synchronously on the main thread.

- code: Code to execute in the main thread.
