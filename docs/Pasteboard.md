# pasteboard

This gives access to the pasteboard.

## `generalPasteboard()`

Returns the Objective-C representation of the general pasteboard.

### Text

## `string()`

Returns the text contained in the pasteboard.

## `strings()`

Returns all strings contained in the pasteboard.

## `setString(text)`

Copy the given text to the pasteboard.

text: The text to copy.

## `setStrings(array)`

Copy the given strings to the pasteboard.

array: A list of strings to copy.

### Images

## `image()`

Returns the image contained in the pasteboard as an Objective-C `UIImage`.

## `images()`

Returns all images contained in the pasteboard as Objective-C `UIImage`s.

## `setImage(image)`

Copy the given image to the pasteboard.

image: The image to copy.

## `setImages(array)`

Copy the given images to the pasteboard.

array: A list of images to copy.

### URLs

## `url()`

Returns the URL contained in the pasteboard as an Objective-C `NSURL`.

## `urls()`

Returns all URLs contained in the pasteboard as Objective-C `NSURL`s.

## `setURL(url)`

Copy the given URL to the pasteboard.

url: The Objective-C `NSURL` to copy.

## `setURLs(array)`

Copy the given URLs to the pasteboard.

array: A list of Objective-C `NSURL`s to copy.

