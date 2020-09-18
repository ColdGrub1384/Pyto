"""
Accessing photos and the camera

Use this library to pick and take photos.
"""

from PIL import Image
from pyto import PyPhotosHelper
from __image__ import __ui_image_from_pil_image__
from __check_type__ import check
import threading
import base64
import io
import os


def pick_photo() -> Image.Image:
    """
    Pick a photo from the photos library. Returns the picked image as a PIL Image.

    :rtype: PIL.Image.Image
    """

    if "widget" in os.environ:
        raise NotImplementedError("Cannot pick a photo from a widget.")

    try:
        msg = PyPhotosHelper.pickPhotoWithScriptPath(
            threading.current_thread().script_path
        )
    except AttributeError:
        msg = PyPhotosHelper.pickPhotoWithScriptPath(None)

    if msg is None:
        return None

    msg = str(msg)
    msg = base64.b64decode(msg)
    buf = io.BytesIO(msg)
    img = Image.open(buf)

    return img


def take_photo() -> Image.Image:
    """
    Take a photo from the camera. Returns the taken image as a PIL Image.

    :rtype: PIL.Image.Image
    """

    if "widget" in os.environ:
        raise NotImplementedError("Cannot take a photo from a widget.")

    try:
        msg = PyPhotosHelper.takePhotoWithScriptPath(
            threading.current_thread().script_path
        )
    except AttributeError:
        msg = PyPhotosHelper.takePhotoWithScriptPath(None)

    if msg is None:
        return None

    msg = str(msg)
    msg = base64.b64decode(msg)
    buf = io.BytesIO(msg)
    img = Image.open(buf)

    return img


def save_image(image: Image.Image):
    """
    Saves the given image to the photos library.

    :param image: A ``PIL`` image to save.
    """

    check(image, "image", [Image.Image])

    PyPhotosHelper.saveImage(__ui_image_from_pil_image__(image))
