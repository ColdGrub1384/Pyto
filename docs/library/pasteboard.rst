pasteboard
==========

.. currentmodule:: pasteboard

Item Provider
*************

An Item Provider is an object holding data that can be loaded as multiple file types.
It can be returned from :func:`~pasteboard.item_provider` or from :func:`~pasteboard.shortcuts_attachments`.
When you copy text for example, it may have formatting. So an :class:`~pasteboard.ItemProvider` object can in this case retrieve the clipboard as plain text or as an rtf file containing the text format.

.. autoclass:: ItemProvider
   :members:

.. autofunction:: item_provider

.. autofunction:: shortcuts_attachments

Strings
*******

Functions for working with strings.

.. autofunction:: string

.. autofunction:: strings

.. autofunction:: set_string

Images
******

Functions for working with images (as PIL images).

.. autofunction:: image

.. autofunction:: images

.. autofunction:: set_image

URLs
****

Functions for working with URLs.

.. autofunction:: url

.. autofunction:: urls

.. autofunction:: set_url
