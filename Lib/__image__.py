import base64
from rubicon.objc import ObjCClass
from UIKit import UIImage
from io import BytesIO

NSData = ObjCClass("NSData")

def __ui_image_from_pil_image__(image):

    if image is None:
        return None

    with BytesIO() as buffered:
        image.save(buffered, format='PNG')
        img_str = base64.b64encode(buffered.getvalue())

    data = NSData.alloc().initWithBase64EncodedString(img_str, options=0)
    image = UIImage.alloc().initWithData(data)
    data.release()
    return image