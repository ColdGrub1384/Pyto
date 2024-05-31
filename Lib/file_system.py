"""
iOS file system

Import, export, and preview files and directories outside or inside the app's sandbox.
"""

import os
import _sharing as sharing
import userkeys
import warnings
import threading
from __check_type__ import check
from contextlib import contextmanager
from pyto import QuickLookHelper, PySharingHelper

try:
    from rubicon.objc import ObjCClass
except ValueError:

    def ObjCClass(class_name):
        return None


NSURL = ObjCClass("NSURL")
NSData = ObjCClass("NSData")

class FilePickerCancellation(Exception):
    """
    The file picker was closed without selecting a file.
    """

    def __init__(self):
        self.message = "no item selected"

# MARK: - Exporting / Importing

def import_file(multiple_selection: bool = False,
                file_extension: tuple[str] | list[str] | str = None, 
                mime_type: tuple[str] | list[str] | str = None, 
                type_identifier: tuple[str] | list[str] | str = None) -> list[str] | str:
    """
    Opens the file picker to import one or more files.
    Returns the file path of all the selected files as a list if 'multiple_selection' is 'True' or a string if it's 'False'.
    Raises :class:`~files.FilePickerCancellation` if no file is selected.

    If no file type was specified, the file picker will allow the selection of any file type.

    :param multiple_selection: A boolean indicating whether multiple selection is allowed.
    :param file_extension: A string or a list of allowed file extensions.
    :param mime_type: A string or a list of allowed mime types.
    :param type_identifier: A string or a list of allowed Uniform Type Identifiers (UTI).
    
    :rtype: list[str] | str    
    """

    if file_extension is None and mime_type is None and type_identifier is None:
        type_identifier = "public.item"

    if file_extension is None:
        file_extension = []
    
    if mime_type is None:
        mime_type = []

    if type_identifier is None:
        type_identifier = []

    if isinstance(file_extension, str):
        file_extension = (file_extension,)

    if isinstance(mime_type, str):
        mime_type = (mime_type,)

    if isinstance(type_identifier, str):
        type_identifier = (type_identifier,)

    file_extension = list(file_extension)
    mime_type = list(mime_type)
    type_identifier = list(mime_type)

    file_picker = sharing.FilePicker()
    file_picker.allows_multiple_selection = multiple_selection
    file_picker.file_extensions = file_extension
    file_picker.mime_types = mime_type
    file_picker.file_types = type_identifier

    sharing.pick_documents(file_picker)
    picked = sharing.picked_files()
    if len(picked) == 0:
        raise FilePickerCancellation()

    if multiple_selection:
        return picked
    else:
        return picked[0]


def pick_directory() -> str:
    """
    Opens the file picker to select a directory.
    Returns the path of the selected directory.
    Raises :class:`~file_system.FilePickerCancellation` if no directory was picked.

    :rtype: str
    """

    file_picker = sharing.FilePicker()
    file_picker.file_types = ["public.folder"]
    sharing.pick_documents(file_picker)
    picked = sharing.picked_files()
    if len(picked) == 0:
        raise FilePickerCancellation()
    return picked[0]


@contextmanager
def open_directory():
    """
    A context manager that temporarily changes the current directory to a folder selected from a file picker.
    Yields picked directory or 'None' if no directory was selected.
    """

    cwd = os.getcwd()

    try:
        directory = pick_directory()
    except FilePickerCancellation:
        directory = None

    if directory is not None:
        os.chdir(directory)
        
    try:
        yield directory
    finally:
        os.chdir(cwd)


def save_as(path: str) -> str:
    """
    Opens a save panel to export a file as a copy.
    Returns the path of the exported file or raises :class:`~file_system.FilePickerCancellation` if no folder was selected.

    :param path: The file path to export.

    :rtype: str
    """

    check(path, "path", [str])

    try:
        script_path = threading.current_thread().script_path
    except AttributeError:
        script_path = None

    PySharingHelper.export(os.path.abspath(path), scriptPath=script_path)
    
    try:
        return sharing.picked_files()[0]
    except IndexError:
        raise FilePickerCancellation()


# MARK: - Sharing


def share_text(*text: str):
    """
    Opens the Share Sheet to share one or more strings.

    :param text: The strings to share.
    """
    
    sharing.share_items(list(text))


def share_files(*path: str):
    """
    Opens the Share Sheet to share one or more files.

    :param path: The file paths to share.
    """

    _path = []
    for file in path:
        check(file, "path", [str])
        _path.append(NSURL.fileURLWithPath(file))
    
    sharing.share_items(_path)


# MARK: - Quick look


def quick_look(*path: str):
    """
    Opens Quick Look to preview one or more files.

    :param path: The file paths to preview.
    """

    _path = []
    for file in path:
        check(file, "path", [str])
        _path.append(os.path.abspath(file))
    path = _path

    try:
        script_path = threading.current_thread().script_path
    except AttributeError:
        script_path = None

    QuickLookHelper.quickLook(path, scriptPath=script_path)


# MARK: - Bookmarks

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
    Instead, use :class:`~file_system.FileBookmark` or :class:`~file_system.FolderBookmark`.
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
                raise ValueError("No file was selected")
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

__all__ = ["FilePickerCancellation", "import_file", "pick_directory", "open_directory", "save_as", "share_text", "share_files", "quick_look", "FileBookmark", "FolderBookmark"]
