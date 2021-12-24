import code
import console
import threading

def main():
    _id = "%ID%"
    line = "%LINE%"

    namespace = console.namespaces[_id]()
    _global = namespace._global
    local = namespace.local

    console.__runREPL__(_global["__file__"], namespace=dict(_global, **local), banner="-> "+line+"\n(Read-only namespace)")

if __name__ == "__main__":
    main()
