Make your project
=================

To create a project, press the 'Create' button on the menu, then 'Project'. After filling the information, a directory will be created with a typical project structure.

Project structure
-----------------

- ``<package_name>``: Put your code here
- ``docs``: If you selected 'Sphinx documentation', write your documentation here
- ``README.md``: Readme page
- ``setup.cfg``: Project metadata
- ``setup.py``: The script to build / install your project

By default, the ``setup.cfg`` specifies ``main()`` as an entrypoint for a console script. You can remove ``console_scripts =`` if you don't want a command line tool.

After installing your package:

.. code-block::

    $ pip install .

You can import it and run its console script from the terminal.

C Extensions are supported and taken care of by ``setuptools``. For more information, see `LLVM Environment <llvm.html>`__.

The `build_cproj <library/build_cproj.html>`__ provides a project structure for C and C++ command line tools.

Documentation
-------------

If you selected 'Sphinx documentation' when creating your project, you can write documentation for your project. For more information, go to `https://www.sphinx-doc.org <https://www.sphinx-doc.org>`_.

To build the documentation:

.. code-block::

    $ python setup.py build_docs

or:

.. code-block::

    $ cd docs
    $ python make.py html

After building the documentation, it will be available on the 'Documentations' section of the app and you can also export the HTML.

If you want to create a documentation for a project that doesn't have one, run:

.. code-block::

    $ sphinx-quickstart

Then create the 'make.py' script inside the documentation directory:

.. highlight:: python
.. code-block::

    from make_sphinx_documentation import main

    if __name__ == "__main__":
        main()

If you have a ``setup.py`` file, you can add :py:class:`make_sphinx_documentation.BuildDocsCommand` as a command:

.. highlight:: python
.. code-block::

    from setuptools import setup
    from make_sphinx_documentation import BuildDocsCommand

    BuildDocsCommand.sourcedir = "docs"

    setup(
        cmdclass={
            'build_docs': BuildDocsCommand, # Run to build the documentation
        },
    )


If a project has C Extensions, they must be compiled in place with ``setup.py build_ext`` so sphinx can import them.
