# PyFilePicker
```swift
@objc public class PyFilePicker: NSObject, UIDocumentPickerDelegate
```

A class for representing an `UIDocumentPickerViewController` settings to be used by the Python API.

```swift
@objc public var completion: (() -> Void)?
````
The code to execute when files where picked.

```swift
@objc public var fileTypes = [NSString]()
```
 Document types that can be opened.

```swift
@objc public var allowsMultipleSelection = false
```
Allow multiple selection or not.
