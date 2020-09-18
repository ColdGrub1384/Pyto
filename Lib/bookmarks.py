"""
Bookmark files and folders

The ``bookmark`` module is a pythonic API for ``NSURL`` bookmarks.
On iOS and iPadOS, files and folders can often change their path. So hard coding paths isn't a good idea.
Instead, this module saves bookmarks in the disk for selected files.
Also, the OS only gives the permission to read and write external files when manually selected. This module takes care of that.

See `Accessing external files <externals.html>`__ for more information.

Example:

.. highlight:: python
.. code-block:: python

    import pandas as pd
    import bookmarks as bm

    # Pick a csv file for the first time.
    # Then, the previously picked file will be reused.
    csv_file = bm.FileBookmark("my_csv_file").path
    dt = pd.read_csv(csv_file)
"""

import os
import sharing
import userkeys
from __check_type__ import check

try:
    from rubicon.objc import ObjCClass
except ValueError:

    def ObjCClass(class_name):
        return None


NSURL = ObjCClass("NSURL")
NSData = ObjCClass("NSData")

__key__ = "__pyto_bookmarks__"


def __stored_bookmarks__():
    return userkeys.get(__key__)


try:
    __stored_bookmarks__()
except KeyError:
    userkeys.set({}, __key__)


class StoredBookmark:
    """
    A bookmark for storing a file path in the disk.

    The bookmark is identified by its name. When a bookmark is initialized with a name for the first time, a file picker will appear.

    This is a base class and should not be directly used.
    Instead, use :class:`~bookmarks.FileBookmark` or :class:`~bookmarks.FolderBookmark`.
    """

    __type__ = None

    __bookmark_name__ = None

    path: str = None
    """
    The file path stored in the bookmark,
    """

    def delete_from_disk(self):
        """
        Deletes the bookmark from the disk.
        """

        bm = __stored_bookmarks__()
        del bm[self.__bookmark_name__]
        userkeys.set(bm, __key__)

    def __init__(self, name: str = None, path: str = None):

        check(name, "name", [str, None])
        check(path, "path", [str, None])

        self.__bookmark_name__ = name

        if self.__type__ is None:
            raise NotImplementedError(
                "Initialized an instance of StoredBookmark. Use FileBookmark or FolderBookmark instead."
            )

        if name is not None:
            try:
                value = __stored_bookmarks__()[name]
                data = NSData.alloc().initWithBase64EncodedString(value, options=0)
                url = NSURL.URLByResolvingBookmarkData(
                    data,
                    options=0,
                    relativeToURL=None,
                    bookmarkDataIsStale=None,
                    error=None,
                )
                if url is not None:
                    url.startAccessingSecurityScopedResource()
                    self.path = str(url.path)
                    return
                return
            except KeyError:
                pass

        if path is None:
            picker = sharing.FilePicker()
            picker.file_types = [self.__type__]
            picker.allows_multiple_selection = False
            sharing.pick_documents(picker)
            try:
                self.path = sharing.picked_files()[0]
            except IndexError:
                raise ValueError("No file selected")
        else:
            self.path = os.path.abspath(path)

        if name is None:
            return

        bookmark = NSURL.fileURLWithPath(self.path).bookmarkDataWithOptions(
            1024, includingResourceValuesForKeys=[], relativeToURL=None, error=None
        )
        bookmark = bookmark.base64EncodedStringWithOptions(0)
        bookmarks = __stored_bookmarks__()
        bookmarks[name] = str(bookmark)
        userkeys.set(bookmarks, __key__)


class FileBookmark(StoredBookmark):
    """
    A bookmark for storing file paths.
    """

    __type__ = "public.item"


class FolderBookmark(StoredBookmark):
    """
    A bookmark for storing folder paths.
    """

    __type__ = "public.folder"
