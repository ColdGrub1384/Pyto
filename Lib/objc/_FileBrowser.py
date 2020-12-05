"""
Classes from the 'FileBrowser' framework.
"""

try:
    from rubicon.objc import ObjCClass
except ValueError:

    def ObjCClass(name):
        return None


def _Class(name):
    try:
        return ObjCClass(name)
    except NameError:
        return None


FileParser = _Class("FileBrowser.FileParser")
PreviewItem = _Class("FileBrowser.PreviewItem")
PreviewManager = _Class("FileBrowser.PreviewManager")
FBFile = _Class("FileBrowser.FBFile")
PodsDummy_FileBrowser = _Class("PodsDummy_FileBrowser")
WebviewPreviewViewContoller = _Class("FileBrowser.WebviewPreviewViewContoller")
PreviewTransitionViewController = _Class("FileBrowser.PreviewTransitionViewController")
FileListViewController = _Class("FileBrowser.FileListViewController")
FileBrowser = _Class("FileBrowser.FileBrowser")
