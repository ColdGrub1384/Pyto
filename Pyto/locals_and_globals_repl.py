import code
import console
import threading

def main():
    _id = "%ID%"
    line = "%LINE%"

    namespace = console.namespaces[_id]()
    local = namespace.local
    local.update(namespace._global)

    console.__runREPL__(local["__file__"], namespace=local, banner="-> "+line)

if __name__ == "__main__":
    main()
