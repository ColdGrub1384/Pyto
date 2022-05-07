Frequently asked
================

*How to use external files in a script?*
****************************************

See `Accessing external files <external.html>`__.

*Why can't I install xxx package?*
**********************************

Some libraries contain native code (C extensions). They cannot be installed because iOS / iPadOS apps must be self contained. That's why libraries like Numpy, Pandas, Matplotlib or OpenCV are included in the app and cannot be updated.

*How to run a web server?*
**************************

Use the `background <background.html>`__ module to run a script in background. See `Using Django <django.html>`__ for an example.
