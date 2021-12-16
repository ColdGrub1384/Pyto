# -*- coding: utf-8 -*-
"""
Pasteboard Access

This module gives access to the pasteboard.
"""

from UIKit import UIPasteboard
from Foundation import NSURL
from typing import List, Union
from __check_type__ import check
from __image__ import __ui_image_from_pil_image__, __pil_image_from_ui_image__
from pyto import __Class__
from PIL import Image
import os
from contextlib import contextmanager
import warnings

try:
    from rubicon.objc import ObjCClass, ObjCInstance
except ValueError:

    def ObjCClass(class_name):
        return None


NSURL = ObjCClass("NSURL")

NSItemProvider = ObjCClass("NSItemProvider")

PyItemProvider = __Class__("PyItemProvider")

def general_pasteboard():
    return UIPasteboard.generalPasteboard


# MARK: - Item Provider


class ItemProvider:
    """
    A bridge to Foundation's ``NSItemProvider`` class.
    An :class:`~pasteboard.ItemProvider` object can load data as one or more type of data.
    Instances of this class are returned by :func:`~pasteboard.item_provider` and :func:`~pasteboard.shortcuts_attachments`.
    """

    __py_item__ = None

    def get_file_path(self) -> str:
        """
        Returns the file path if the item is a file.
        If it returns ``None``, you can load its content from :meth:`~pasteboard.ItemProvider.data` or :meth:`~pasteboard.ItemProvider.open`
        """

        path = self.__py_item__.path
        if path is not None:
            return str(path)

    def get_type_identifiers(self) -> List[str]:
        """
        Returns a list of type identifiers (UTI) that can be loaded.
        """

        types = []
        for type in list(self.__py_item__.types):
            types.append(str(type))
        return types
    
    def get_suggested_name(self) -> str:
        """
        Returns the name of the file from which the receiver was created or ``None``.
        """

        name = self.__py_item__.suggestedName
        if name is not None:
            return str(name)
    
    def data(self, type_identifier: str) -> bytes:
        """
        Returns the data for the given type identifier as bytes.

        :param type_identifier: An UTI. Can be returned from :meth:`~pasteboard.ItemProvider.get_type_identifiers`.
        """

        path = self.__py_item__.loadDataForTypeIdentifier(type_identifier)
        if path is None:
            return
        
        data = None
        with open(str(path), "rb") as f:
            data = f.read()
        
        os.remove(str(path))

        return data

    @contextmanager
    def open(self):
        """
        Opens the receiver as a file in ``'rb'`` mode with the first item item returned by :meth:`~pasteboard.ItemProvider.get_type_identifiers` as the type identifier.
        You must use this function with the ``with`` keyword:

        .. highlight:: python
        .. code-block:: python

           with item_provider.open() as f:
               f.read()
        """

        path = self.__py_item__.loadDataForTypeIdentifier(self.get_type_identifiers()[0])
        if path is None:
            return
        
        f = None
        try:
            f = open(str(path), "rb")
            yield f
        finally:
            f.close()
            os.remove(str(path))

    def __init__(self, foundation_item_provider: NSItemProvider):
        self.__py_item__ = PyItemProvider.alloc().initWithManaged(foundation_item_provider)


def shortcuts_attachments() -> List[ItemProvider]:
    """
    If the script is running from Shortcuts, returns a list of files passed to the ``Attachments`` parameter as :class:`~pasteboard.ItemProvider` objects.
    """

    array = []
    for item_provider in list(PyItemProvider.shortcutItemProviders):
        array.append(ItemProvider(item_provider))
    
    return array


def item_provider() -> ItemProvider:
    """
    Returns an :class:`~pasteboard.ItemProvider` instance storing the data from the pasteboard, if there is any.
    """

    array = []
    for item_provider in list(general_pasteboard().itemProviders):
        array.append(ItemProvider(item_provider))

    if len(array) == 0:
        return None
    
    return array[-1]


# MARK: - Text


def string() -> str:
    """
    Returns the text contained in the pasteboard.
    """
    string = general_pasteboard().string
    if string is not None:
        return str(string)


def strings() -> List[str]:
    """
    Returns all strings contained in the pasteboard.
    """
    return general_pasteboard().strings


def set_string(text: Union[str, List[str]]):
    """
    Copies the given text to the pasteboard.

    :param text: A string or a list of strings.
    """

    check(text, "text", [str, list, None])

    if isinstance(text, list):
        general_pasteboard().strings = text
    else:
        general_pasteboard().string = text


def set_strings(array: List[str]):

    _warning = "set_strings() is deprecated in favor of set_string(), which now supports a list as a parameter."
    warnings.warn(_warning, DeprecationWarning)

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


def set_image(image: Union[Image.Image, List[Image.Image]]):
    """
    Copies the given image to the pasteboard.

    :param image: A PIL image or a list of PIL images.
    """

    check(image, "image", [Image.Image, None])

    if isinstance(image, list):
        _set_images(image)
    else:
        general_pasteboard().image = __ui_image_from_pil_image__(image)

def _set_images(array):
    images = []
    if array is not None:
        for image in array:
            images.append(__ui_image_from_pil_image__(image))

    general_pasteboard().images = images

def set_images(array: List[Image.Image]):
    
    _warning = "set_images() is deprecated in favor of set_image(), which now supports a list as a parameter."
    warnings.warn(_warning, DeprecationWarning)

    check(array, "array", [list, None])
    _set_images(array)

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


def set_url(url: Union[str, List[str]]):
    """
    Copies the given URL to the pasteboard.

    :param url: A string or a list of strings.
    """

    check(url, "url", [str, None])

    if isinstance(url, list):
        _set_urls(url)
    else:
        general_pasteboard().URL = NSURL.alloc().initWithString(url)


def _set_urls(array):
    urls = []
    if array is not None:
        for url in array:
            urls.append(NSURL.alloc().initWithString(url))

    general_pasteboard().URLs = urls

def set_urls(array: List[str]):

    _warning = "set_urls() is deprecated in favor of set_url(), which now supports a list as a parameter."
    warnings.warn(_warning, DeprecationWarning)

    check(array, "array", [list, None])

    _set_urls(array)
