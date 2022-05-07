.. Pyto documentation master file, created by
   sphinx-quickstart on Sun Jul 21 17:54:15 2019.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.


Pyto documentation
==================

Welcome to the Pyto's documentation!

Pyto version: 18.0 (407)
Python version: 3.10.0+

Pyto is an open source app to code and run Python code locally on an iPad or iPhone.
The app uses the Python C API to run Python code in the same process of the app, due to iOS restrictions. Third party pure Python modules can be installed from PyPI and some libraries with C extensions are bundled in the app. For a list of included libraries, see `Third Party <third_party.html>`__.

The Python 3.10 binary that comes with the app is from the `Python-Apple-support <https://github.com/beeware/Python-Apple-support/tree/3.10>`__ project by beeware. `Toga <https://toga.readthedocs.io/en/latest/>`__, a cross platform UI library is also included.

Documents
---------

.. toctree::
   :maxdepth: 1
   
   library/index
   third_party

.. toctree::
   :maxdepth: 2
   
   terminal
   automation
   projects
   external
   faq
