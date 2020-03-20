pyto_core
=========

.. currentmodule:: pyto_core

.. automodule:: pyto_core

Getting Started
---------------

To run a script at startup, run the :func:`~pyto_core.startup_script` function from the script you want to execute at startup.
Only one startup script at time is supported because only one script can be receive editor's events. But nothing stops you from importing other scripts.

You can then run a while loop in background for example. Or you can also add a button to the code editor's toolbar. See the :class:`~pyto_core.EditorDelegate` class for more information.

API Reference
-------------

.. autofunction:: startup_script

.. autofunction:: show_view

.. toctree::
   :maxdepth: 2

   pyto_core/editor
   pyto_core/themes
