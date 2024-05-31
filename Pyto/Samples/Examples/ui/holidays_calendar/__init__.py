try:
    import holidays
except ModuleNotFoundError as e:
    print(e)
    print("Run 'pip install holidays' to install it")
    exit(1)

from .ui.main_view import CalendarView
import pyto_ui as ui
import os.path


VIEW_PATH = os.path.join(os.path.dirname(__file__), "ui/main.pytoui")

def main():
    view = ui.read(VIEW_PATH)
    view.size = ui.SheetSize.IPHONE_MEDIUM
    ui.show_view(view, ui.PresentationMode.NEW_SCENE)


if __name__ == "__main__":
    main()