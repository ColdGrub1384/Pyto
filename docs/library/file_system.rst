file_system
===========

Import, export, and preview files and directories outside or inside the app's sandbox.


.. currentmodule:: file_system

Importing / Exporting
---------------------

.. autofunction:: import_file

.. autofunction:: pick_directory

.. autofunction:: open_directory

.. autofunction:: save_as

.. autoclass:: FilePickerCancellation

Share Sheet
-----------

.. autofunction:: share_text

.. autofunction:: share_files

Quick Look
----------

.. autofunction:: quick_look

Bookmarks
---------

A Bookmark to a file makes it possible to keep read and write access to a file outside the app's sandbox across launches.

.. autoclass:: StoredBookmark
   :members:

.. autoclass:: FileBookmark
   :members:

.. autoclass:: FolderBookmark
   :members:
