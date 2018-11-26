# PyAlert
```swift
@objc public class PyAlert: NSObject
```

A class representing an alert to be used from the Python API.

```swift
@objc public var title: String?
```
The alert's title.

```swift
@objc public var message: String?
```
The alert's message.

```swift
@objc public static func alertWithTitle(_ title: String?, message: String?) -> PyAlert
```
Initialize a new alert.

- title: The alert's title.
- message: The alert's message.

```swift
@objc public func show() -> String
```
Show an alert with set parameters.

- Returns: The title of the pressed action.

## Setters

```swift
@objc public func addAction(title: String)
```
Add an action with given tilte and handler.

- title: The title of the action.
- handler: The action's handler.

```swift
@objc public func addDestructiveAction(title: String)
```
Add a destructive action with given tilte and handler.

- title: The title of the action.
- handler: The action's handler.

```swift@objc public func addCancelAction(title: String)
```
Add a cancel action with given tilte and handler.

- title: The title of the action.
- handler: The action's handler.
