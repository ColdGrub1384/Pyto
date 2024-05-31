import pyto_ui as ui
import os.path


LAYOUT_PATH = os.path.join(os.path.dirname(__file__), "layout.pytoui")


def main():
    global view # for debugging
    
    view = ui.read(LAYOUT_PATH)
    view.become_first_responder()
    view.size = ui.SheetSize.IPHONE_MEDIUM
    ui.show_view(view, ui.PresentationMode.SHEET)


if __name__ == "__main__":
    main()