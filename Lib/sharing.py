# -*- coding: utf-8 -*-
"""
Sharing Items

This module allows you to share items, to import files and to open URLs.
"""

import pyto
import mainthread
import threading
import base64
import os
from typing import List
try:
    from rubicon.objc import ObjCClass
except ValueError:
    def ObjCClass(class_name):
        return None


__PySharingHelper__ = pyto.PySharingHelper
NSURL = ObjCClass("NSURL")


def share_items(items: object):
    """
    Opens a share sheet with given items.

    :param items: Items to be shared with the sheet.
    """

    __PySharingHelper__.share(items)


if "widget" not in os.environ:

    def quick_look(path: str):
        """
        Previews given file.

        This function doesn't block the current thread. You can call this function multiple times and the file path will be appended to the current Preview controller. Thread safe.

        :param path: Path of the image to preview.
        """

        file = open(path, "rb")  # open binary file in read mode
        file_read = file.read()
        file64_encode = base64.encodestring(file_read).decode("utf-8")

        try:
            pyto.QuickLookHelper.previewFile(
                file64_encode,
                script=threading.current_thread().script_path,
                removePrevious=False,
            )
        except AttributeError:
            pyto.QuickLookHelper.previewFile(
                file64_encode, script=None, removePrevious=False
            )


# MARK: - File picker


class FilePicker:
    """
    A class representing a file picker. Presents an ``UIDocumentPickerViewController``.

    A class representing a file picker.

    Example:

    .. highlight:: python
    .. code-block:: python

        filePicker = sharing.FilePicker()
        filePicker.file_types = ["public.data"]
        filePicker.allows_multiple_selection = True

        def files_picked() -> None:
            files = sharing.picked_files()
            sharing.share_items(files)

        filePicker.completion = files_picked
        sharing.pick_documents(filePicker)
    """

    file_types = []
    """
    Document types that can be opened.
    """

    allows_multiple_selection = False
    """
    Allow multiple selection or not.
    """

    completion = None
    """
    The code to execute when files where picked.
    """

    urls = []
    """
    Picked URLs.
    """

    def __objcFilePicker__(self):
        filePicker = pyto.FilePicker.new()
        filePicker.fileTypes = self.file_types
        filePicker.allowsMultipleSelection = self.allows_multiple_selection
        filePicker.completion = self.completion

        return filePicker

    @staticmethod
    def new():
        return FilePicker()


def pick_documents(filePicker: FilePicker):
    """
    Pick documents with given parameters as a ``FilePicker``.

    :param filePicker: The parameters of the file picker to be presented.
    """

    script_path = None
    try:
        script_path = threading.current_thread().script_path
    except AttributeError:
        pass

    __PySharingHelper__.presentFilePicker(
        filePicker.__objcFilePicker__(), scriptPath=script_path
    )


def picked_files() -> List[str]:
    """
    Returns paths of files picked with ``pickDocumentsWithFilePicker``.
    """

    urls = pyto.FilePicker.urls
    if len(urls) == 0:
        return []
    else:
        py_urls = []
        for url in urls:
            py_urls.append(str(url.path))
        return py_urls


# MARK: - URLs


def open_url(url: str):
    """
    Opens the given URL.

    :param url: URL to open. Can be a String or an Objective-C ``NSURL``.
    """

    __url__ = None       

    if type(url) is str:
        __url__ = NSURL.URLWithString(url)
    elif __PySharingHelper__.isURL(url):
        __url__ = url
    else:
        raise ValueError("url musts be a String or an Objective-C ``NSURL``.")

    __PySharingHelper__.openURL(__url__)