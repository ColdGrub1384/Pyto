from types import ModuleType
import sys
import threading
import weakref
from types import ModuleType

def get_script_path():
    try:
        return threading.current_thread().script_path
    except AttributeError:
        pass

def get_main():
    try:
        main = sys.__class__.main[get_script_path()]
        if isinstance(main, weakref.ref):
            main = main()

        if main is None:
            raise KeyError()

        return main
    except KeyError:
        return ModuleType("__main__")

class Main(ModuleType):

    def __getattribute__(self, name):
        main = get_main()
        try:
            return getattr(main, name)
        except (KeyError, AttributeError):
            return super().__getattribute__(name)
    
    def __setattr__(self, name, value):
        setattr(get_main(), name, value)

sys.modules[__name__] = Main(__name__)