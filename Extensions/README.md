# Dynamic loading

How C extensions loading work? Simple. Given the following module's fullname: `pywt._extensions-_pywt`, Pyto will look for a framework called `pywt-_extensions-_pywt.framework`. The binary will be loaded, no matter its name.

A framework can also contain all of the `PyInit` functions of a library. For example, given the module `scipy.odr.__odrpack`, the framework named `scipy-.framework` will be loaded if it exists and  `PyInit___odrpack` will be called.
There is no need to declare anywhere the C extensions, just embed the frameworks in the app with one of the naming conventions and it will be dynamically loaded when needed.

So, for a module called `a.b._c`, one of the 2 frameworks will be loaded:

- `a-b-_c.framework`
- `a-.framework`

No matter the name of the framework, the function `PyInit__c` needs to be present in the binary.

## Dependencies

Some libraries like `lxml` have dependencies. The `lxml-deps` framework contains the symbols for `libxml2` and `libxslt`. So, given a module called `a.b._c`, the framework `a-deps.framework` will be loaded.

# Bitcode loading

C Extensions can also be loaded from LLVM IR code. They are interpreted with the 'lli' interpreter. They can be placed in a package like any OS, but a main() function must be injected.

The app cannot call functions from the interpreter without crashing, so the interpreter waits for the app to send a pointer of a function and its arguments and run it itself. The arguments and the return value are send through global variables.
