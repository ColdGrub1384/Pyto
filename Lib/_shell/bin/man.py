"""
Show the help text of the given program.

usage: man program
"""

import sys
import runpy
import os


class Path:
    
    def __init__(self, path):
        self.path = path
        self.old_path = sys.path
    
    def __enter__(self):
        sys.path = self.path
    
    def __exit__(self, exc_type, exc, tb):
        sys.path = self.old_path
        if exc is not None and exc_type is not SystemExit:
            raise exc


def main():
    
    if len(sys.argv) != 2:
        print(__doc__)
        raise SystemExit
    
    script_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), sys.argv[1]+".py")
    documents_bin_script_path = os.path.join(os.path.expanduser("~/Documents/bin"), sys.argv[1]+".py")
    
    if os.path.isfile(script_path):
        with Path(sys.path+[os.path.dirname(script_path)]) as _:
            mod = runpy.run_path(script_path, run_name=sys.argv[1])
    elif os.path.isfile(documents_bin_script_path):
        with Path(sys.path+[os.path.dirname(documents_bin_script_path)]) as _:
            mod = runpy.run_path(documents_bin_script_path, run_name=sys.argv[1])
    else:
        mod = runpy.run_module(sys.argv[1], run_name=sys.argv[1])
    
    doc = mod["__doc__"]
    while doc.startswith("\n"):
        doc = doc[1:]
    
    while doc.endswith("\n"):
        doc = doc[:-1]

    print(doc)

if __name__ == "__main__":
    main()
