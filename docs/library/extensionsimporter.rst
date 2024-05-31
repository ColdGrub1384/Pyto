extensionsimporter
==================

.. currentmodule:: extensionsimporter

.. automodule:: extensionsimporter

Dynamic Loading
---------------

Given the following module's fullname: `pywt._extensions-_pywt`, Pyto will look for a framework called `pywt-_extensions-_pywt.framework`. The binary will be loaded, no matter its name.

A framework can also contain all of the `PyInit` functions of a library. For example, given the module `scipy.odr.__odrpack`, the framework named `scipy-.framework` will be loaded if it exists and  `PyInit___odrpack` will be called.
This method of loading extensions only work for embedded in app ones.

So, for a module called `a.b._c`, one of the 2 frameworks will be loaded:

- `a-b-_c.framework`
- `a-.framework`

No matter the name of the framework, the function `PyInit__c` needs to be present in the binary.

.. autoclass:: FrameworksImporter
   :members:

.. autoclass:: FrameworkLoader
   :members:

.. autoclass:: Extension
   :members:

.. autoclass:: BuiltinLoader
   :members:

Bitcode Interpretation
----------------------

(Full version exclusive)

C Extensions can also be loaded from LLVM IR code. They are interpreted with the 'lli' interpreter. They can be placed in a package like any OS, but a main() function must be injected.

The app cannot call functions from the interpreter without crashing, so the interpreter waits for the app to send a pointer of a function and its arguments and run it itself. The arguments and the return value are sent through global variables.

.. autoclass:: BitcodeImporter
   :members:
   
.. autoclass:: BitcodeLoader
   :members:

.. autoclass:: BitcodeValue
   :members:

.. autoclass:: BitcodeClass
   :members:
   
.. autoclass:: BitcodeFunction
   :members:

.. autoclass:: BitcodeCythonFunction
   :members:

.. autoclass:: BitcodeModule
   :members:
