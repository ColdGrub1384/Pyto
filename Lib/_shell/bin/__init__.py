from os.path import dirname, basename, isfile, join
import glob
import importlib
import sys

modules = glob.glob(join(dirname(__file__), "*.py"))
__all__ = [ basename(f)[:-3] for f in modules if isfile(f) and not f.endswith('__init__.py')]

for module in modules:
    name = module.split("/")[-1].split(".py")[0]
    
    if name == "__init__":
        continue
    
    spec = importlib.util.spec_from_file_location(name, module)
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    
    exec(f"""def {name}(*args):
    import sys
    import runpy
    import inspect
        
    name = inspect.currentframe().f_code.co_name
        
    sys.argv = [name]+list(args)
    try:
        runpy.run_module(name, run_name="__main__")
    except SystemExit:
        pass
    except Exception as e:
        print(type(e).__name__+":", e)
    """)

    setattr(sys.modules[__name__], name, eval(name))

del modules, dirname, basename, isfile, join, glob, importlib, sys