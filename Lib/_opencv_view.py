import pyto_ui as ui
import pyto_core as pc
import sys
from time import sleep

class OpenCVView(ui.ImageView):

    _presented = False

    _closed = False

    def __init__(self):
        super().__init__()

        self.title = "OpenCV"
        self.background_color = ui.COLOR_SYSTEM_BACKGROUND
        self.content_mode = ui.CONTENT_MODE_CENTER

    def did_disappear(self):
        self._presented = False
        self._closed = True

view = OpenCVView()

def show(img):
    global view

    if view._closed:
        view = OpenCVView()
        sys.exit(0)

    view.image = img
    view.size = img.size

    if not view._presented:
        pc.show_view(view, ui.PRESENTATION_MODE_SHEET)
        view._presented = True
