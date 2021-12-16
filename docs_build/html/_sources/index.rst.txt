.. Pyto documentation master file, created by
   sphinx-quickstart on Sun Jul 21 17:54:15 2019.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

.. image:: Icon.png
   :width: 100px

|

Welcome to Pyto's documentation!
================================

Pyto is an open source app to code and run Python code locally on an iPad or iPhone.
The app uses the Python C API to run Python code in the same process of the app, due to iOS restrictions. Third party pure Python modules can be installed from PyPi and some libraries with C extensions are bundled in the app. For a list of included libraries, see `Third Party <third_party.html>`__.

The Python 3.10 binary that comes with the app is from the `Python-Apple-support <https://github.com/beeware/Python-Apple-support/tree/3.10>`__ project by beeware. `Toga <https://toga.readthedocs.io/en/latest/>`__, a cross platform UI library is also included.

Other modules were built specifically for this app, allowing access to some of the OS APIs.

Frequently asked
----------------

*How to use external files in a script?*
****************************************

See `Accessing external files <external.html>`__.

*Why can't I install xxx package?*
**********************************

Some libraries contain native code (C extensions). They cannot be installed because iOS / iPadOS apps must be self contained. That's why libraries like Numpy, Pandas, Matplotlib or OpenCV are included in the app and cannot be updated.

*How to run a web server?*
**************************

Use the `background <background.html>`__ module to run a script in background. See `Using Django <django.html>`__ for an example.


Documents
---------

.. toctree::
   :maxdepth: 2

   automation
   external
   opencv
   django
   third_party

API Reference
-------------

The following modules are integrated with Pyto.

.. toctree::
   :maxdepth: 2
   :caption: ObjC Runtime
   
   Objective-C

.. toctree::
   :maxdepth: 2
   :caption: User Interface

   pyto_ui
   widgets
   watch
   sound
   sf_symbols
   sharing
   mainthread
   htmpy
   pyto_core

.. toctree::
   :maxdepth: 2
   :caption: OS Technologies

   notifications
   remote_notifications
   background
   bookmarks
   music
   photos
   location
   motion
   multipeer
   speech

.. toctree::
   :maxdepth: 2
   :caption: Sharing data

   pasteboard
   userkeys
   xcallback
   apps
