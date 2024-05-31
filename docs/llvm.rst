LLVM Environment
================

Several Python modules built from C or other compiled languages are included in the application bundle due to iOS restrictions on loading external binaries.

However, there is limited support for C and C++ code compilation via ``clang`` and interpretation via ``lli``.

Compilation
-----------

To compile a C file, use clang with ``-S -emit-llvm`` arguments.
That will generate an LLVM Intermediate Representation file (``.ll``), or bitcode basically.

The headers for the C and C++ Standard Libraries, as well as the Python C API are automatically included by clang, through the ``C_INCLUDE_PATH`` and ``CPLUS_INCLUDE_PATH`` environment variables. ``SYSROOT`` is set to ``~/Documents``, so ``~/Documents/include`` is also in the search paths. The content of ``python3.10``, ``stdlib`` and ``clang`` is replaced on each launch of Pyto.

.. code-block::

    $ clang -S -emit-llvm main.c -o main.ll


Use ``llvm-link`` to link multiple IR files:

.. code-block::

    $ llvm-link main.ll extra.ll -o main.bc


Interpretation
--------------

To interprete clang emitted bitcode, just use the ``lli`` command.

.. code-block::

    $ lli main.bc
    Hello World!


Files ending with .bc or .ll located in ``~/Documents/bin`` can be executed directtly from the shell, ``os.system`` and ``subprocess.Popen`` without its path extension.

Projects created with Pyto use `build_cproj <library/build_cproj.html>`__, which provides a project structure for C and C++ command line tools.


Python C Extensions
-------------------

Compilation and importation of Python C extensions is also possible, and should work normally with ``setuptools``.

So, how is the compilation behind the scene?

.. code-block::

    $ clang -S -emit-llvm mycext.c -o mycext.o
    $ clang -S -emit-llvm ~/Documents/lib/cext_glue.c -DPy_BUILD_CORE=1 -DPy_BUILD_CORE_BUILTIN=1 -DPYINIT_FUNCTION=PyInit_mycext -o cext_glue.o
    $ llvm-link cext_glue.o mycext.o -o mycext.cpython-310-darwin.so
    $ python
    >>> import mycext
    >>> mycext.main()
    Hello World!


``~/Documents/lib/cext_glue.c`` is a C source file that needs to be glued to the extension for Pyto to recognize it. It inserts a ``main`` function that will communicate with the rest of the app.

``cext_glue.c`` needs to be compiled for each module because it needs the name of the ``PyInit`` function. It set in the example above with ``-DPYINIT_FUNCTION=PyInit_mycext``. ``PYINIT_FUNCTION`` is the macro that needs to be set.

(Extensions for bitcode files don't really matter, as a convention we use ``.ll`` for single sources and ``.bc`` for a merged binary. Setuptools will produce binaries with ``.o`` and ``.so`` extensions as if they were normal libraries.)


``setuptools`` will automatize this process. Cython is also supported. See `Building Extension Modules <https://setuptools.pypa.io/en/latest/userguide/ext_modules.html>`_.
