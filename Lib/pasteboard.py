# -*- coding: utf-8 -*-
"""
Pasteboard Access

This module gives access to the pasteboard.
"""

<<<<<<< HEAD
from UIKit import UIPasteboard
from Foundation import NSURL
from typing import List
from __check_type__ import check
from __image__ import __ui_image_from_pil_image__, __pil_image_from_ui_image__
from PIL import Image
=======
from UIKit import UIPasteboard as __UIPasteboard__, UIImage
from typing import List
from __check_type__ import check
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619

try:
    from rubicon.objc import ObjCClass, ObjCInstance
except ValueError:

    def ObjCClass(class_name):
        return None


NSURL = ObjCClass("NSURL")


def general_pasteboard():
<<<<<<< HEAD
    return UIPasteboard.generalPasteboard
=======
    return __UIPasteboard__.generalPasteboard
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619


# MARK: - Text


def string() -> str:
    """
    Returns the text contained in the pasteboard.
    """
    return str(general_pasteboard().string)


def strings() -> List[str]:
    """
    Returns all strings contained in the pasteboard.
    """
    return general_pasteboard().strings


def set_string(text: str):
    """
    Copy the given text to the pasteboard.

    :param text: The text to copy.
    """

    check(text, "text", [str, None])

    general_pasteboard().string = text


def set_strings(array: List[str]):
    """
    Copy the given strings to the pasteboard.

    :param array: A list of strings to copy.
    """

    check(array, "array", [list, None])

    general_pasteboard().strings = array


# MARK: - Images


<<<<<<< HEAD
def image() -> Image.Image:
    """
    Returns the image contained in the pasteboard as PIL images.
    """

    image = general_pasteboard().image
    if image is None:
        return None
    return __pil_image_from_ui_image__(image)


def images() -> List[Image.Image]:
    """
    Returns all images contained in the pasteboard as PIL images.
    """

    images = general_pasteboard().images
    if images is None:
        return []

    pil_images = []
    for image in images:
        pil_images.append(__pil_image_from_ui_image__(image))

    return pil_images


def set_image(image: Image.Image):
=======
def image() -> UIImage:
    """
    Returns the image contained in the pasteboard as an Objective-C ``UIImage``.
    """
    return general_pasteboard().image


def images() -> List[UIImage]:
    """
    Returns all images contained in the pasteboard as Objective-C ``UIImage`` s.
    """
    return general_pasteboard().images


def set_image(image: ObjCInstance):
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
    """
    Copy the given image to the pasteboard.

    :param image: The image to copy.
    """

<<<<<<< HEAD
    check(image, "image", [Image.Image, None])

    general_pasteboard().image = __ui_image_from_pil_image__(image)


def set_images(array: List[Image.Image]):
=======
    check(image, "image", [ObjCInstance, None])

    general_pasteboard().image = image


def set_images(array: List[UIImage]):
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
    """
    Copy the given images to the pasteboard.

    :param array: A list of images to copy.
    """

    check(array, "array", [list, None])

<<<<<<< HEAD
    images = []
    if array is not None:
        for image in array:
            images.append(__ui_image_from_pil_image__(image))

    general_pasteboard().images = images
=======
    general_pasteboard().images = array
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619


# MARK: - URLs


<<<<<<< HEAD
def url() -> str:
    """
    Returns the URL contained in the pasteboard as a string.
    """
    url = general_pasteboard().URL
    if url is not None:
        url = str(url.absoluteString)
    return url


def urls() -> List[str]:
    """
    Returns all URLs contained in the pasteboard as strings.
    """

    urls = general_pasteboard().URLs
    str_urls = []

    if urls is not None:
        for url in urls:
            str_urls.append(str(url.absoluteString))

    return str_urls


def set_url(url: str):
    """
    Copy the given URL to the pasteboard.

    :param url: The string to copy as an URL.
    """

    check(url, "url", [str, None])

    general_pasteboard().URL = NSURL.alloc().initWithString(url)


def set_urls(array: List[str]):
    """
    Copy the given URLs to the pasteboard.

    :param array: A list of strings to copy as URLs.
=======
def url() -> NSURL:
    """
    Returns the URL contained in the pasteboard as an Objective-C ``NSURL``.
    """
    return general_pasteboard().url


def urls() -> List[NSURL]:
    """
    Returns all URLs contained in the pasteboard as Objective-C ``NSURL`` s.
    """
    return general_pasteboard().urls


def set_url(url: NSURL):
    """
    Copy the given URL to the pasteboard.

    :param url: The Objective-C ``NSURL`` to copy.
    """

    check(url, "url", [ObjCInstance, None])

    general_pasteboard().url = url


def set_urls(array: List[NSURL]):
    """
    Copy the given URLs to the pasteboard.

    :param array: A list of Objective-C ``NSURL`` s to copy.
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
    """

    check(array, "array", [list, None])

<<<<<<< HEAD
    urls = []
    if array is not None:
        for url in array:
            urls.append(NSURL.alloc().initWithString(url))

    general_pasteboard().URLs = urls
=======
    general_pasteboard().urls = array
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
