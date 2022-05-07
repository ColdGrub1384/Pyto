import code
import console
import threading

def main():
    _id = "%ID%"
    line = "%LINE%"
    index = %INDEX%

    if index == -1:
        namespace = console.namespaces[_id]()
        readonly = "\n(Read-only namespace)"
    else:
        namespace = console.namespaces[_id][index]()
        readonly = ""
    
    _global = namespace._global
    local = namespace.local

    console.__runREPL__(_global["__file__"], namespace=dict(_global, **local), banner="-> "+line+readonly)

if __name__ == "__main__":
    main()
