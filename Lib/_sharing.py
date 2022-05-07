import sharing
import warnings

functions = ["share_items", "quick_look", "pick_documents", "picked_files", "open_url"]

FilePicker = sharing.FilePicker

class SharingFunction:

    def __init__(self, name):
        self.name = name
    
    def __call__(self, *args, **kwargs):
        value = None
        with warnings.catch_warnings():
            warnings.filterwarnings(
                action='ignore',
                category=DeprecationWarning,
            )
            value = getattr(sharing, self.name)(*args, **kwargs)
        return value

for function in functions:
    globals()[function] = SharingFunction(function)
