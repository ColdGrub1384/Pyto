Automation with Shortcuts and x-callback URLs
=============================================

Shortcuts
---------

Pyto provides Shortcuts for running scripts and code. Shortcuts will open Pyto to execute the code and it's not possible to retrieve the result. See `x-callback URLs <#x-callback URLs>`_ for getting callbacks.

``Run Code`` will execute the given code with the given arguments. Can be executed in app or without leaving Shortcuts.

``Run Script`` will execute the given script with the given arguments. Can be executed in app or without leaving Shortcuts.

``Get Script Output`` will wait for a script to be executed and returns its output.

The code executes asynchronously unless ``Get Script Output`` is ran.
The ``Run Code`` and ``Run Script`` actions support an ``Attachments`` parameter. You can pass files to it and they can be access with the :func:`~pasteboard.shortcuts_attachments()` API.

x-callback URLs
---------------

Pyto supports `x-callback URLs <http://x-callback-url.com>`__ for running scripts from other apps and getting the result.

With this method you can only run code and not a script but you can use the `runpy <https://docs.python.org/3/library/runpy.html>`__ module for running scripts in a location like ``~/Documents`` or ``~/Documents/site-packages``.

This is the structure that should be used for running code:

``pyto://x-callback/?code=[code]&x-success=[x-success]&x-error=[x-error]&x-cancel=[x-cancel]``

``code`` is the code to execute.

``x-success`` is the URL to open when a script was executed successfully. Passes the output (stdout + stderr) to a ``result`` parameter.

``x-error`` is the URL to open when a script raised an exception. Passes the exception message to a ``errorMessage`` parameter.

``x-cancel`` is the URL to open when a script was stopped by the user or when the script raised ``SystemExit`` or ``KeyboardInterrupt``.


The Shortcuts app supports opening x-callback URLs. `Here <https://www.icloud.com/shortcuts/b85b8afe92e54dc9b54be5ab1495995f>`__ is an example of a Shortcut that shows the current Python version.

Pyto can also open external x-callback URLs with the `xcallback <xcallback.html>`__ and `apps <apps.html>`__ module.
