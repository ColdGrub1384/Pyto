# ui

This module gives you access to the UI.

Pyto supports showing a custom UI for your scripts. To do that, you can directly use UIKit! The `ui` modules allows you to show an `UIViewController`. To import UIKit classes, write `from UIKit import *`. For an example, see the `User Interface` example.

## `mainLoop()`

This runs a loop while the UI is shown to keep the program running. You should always call this function after showing an interactive UI.

## `showViewController(viewController)`

Shows the given View controller.

- viewController: An `UIViewController` to show.
