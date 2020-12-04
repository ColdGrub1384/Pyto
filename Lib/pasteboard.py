# -*- coding: utf-8 -*-
"""
Pasteboard Access

This module gives access to the pasteboard.
"""

from UIKit import UIPasteboard
from Foundation import NSURL
from typing import List
from __check_type__ import check
from __image__ import __ui_image_from_pil_image__, __pil_image_from_ui_image__
from PIL import Image

try:
    from rubicon.objc import ObjCClass, ObjCInstance
except ValueError:

    def ObjCClass(class_name):
        return None


NSURL = ObjCClass("NSURL")


def general_pasteboard():
    return UIPasteboard.generalPasteboard


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
    """
    Copy the given image to the pasteboard.

    :param image: The image to copy.
    """

    check(image, "image", [Image.Image, None])

    general_pasteboard().image = __ui_image_from_pil_image__(image)


def set_images(array: List[Image.Image]):
    """
    Copy the given images to the pasteboard.

    :param array: A list of images to copy.
    """

    check(array, "array", [list, None])

    images = []
    if array is not None:
        for image in array:
            images.append(__ui_image_from_pil_image__(image))

    general_pasteboard().images = images


# MARK: - URLs


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
    """

    check(array, "array", [list, None])

    urls = []
    if array is not None:
        for url in array:
            urls.append(NSURL.alloc().initWithString(url))

    general_pasteboard().URLs = urls
