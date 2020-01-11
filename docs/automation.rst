Automation with Shortcuts and x-callback URLs
=============================================

Shortcuts
---------

Pyto provides Shortcuts for running scripts and code. Shortcuts will open Pyto to execute the code and it's not possible to retrieve the result. See `x-callback URLs <#x-callback URLs>`_ for getting callbacks.

``Run Code with Arguments`` will execute the given code with the given arguments. Code can be executed in app or without leaving Shortcuts. If you uncheck ``Run In App``, the Shortcut will return the output of the code (stdout + stderr). When ``Run In App`` is unchecked, the code will only have access to the standard library and ``stdin`` cannot be sent.

``Run Script with Arguments`` will execute the given script with the given arguments. Note that ``Script`` is a file, and Shortcuts doesn't provide a way to pick a file as a value. So the only ways to have a valid value passed to this Shortcut are by sharing a file with the Share Sheet and passing the input or by picking each time a script with the ``Get file`` system Shortcut.

Pyto also provides a Shortcut for each script used with the app.

x-callback URLs
---------------

Pyto supports `x-callback URLs <http://x-callback-url.com>`__ for running scripts from other apps and getting the result.

Use x-callback URLs instead of Shortcuts if you need to get the output of the executed code. With this method you can only run code and not a script but you can use the `runpy <https://docs.python.org/3/library/runpy.html>`__ module for running scripts in a location like ``~/Documents`` or ``~/Documents/site-packages``.

This is the structure that should be used for running code:

``pyto://x-callback/?code=[code]&x-success=[x-success]&x-error=[x-error]&x-cancel=[x-cancel]``

``code`` is the code to execute.

``x-success`` is the URL to open when a script was executed successfully. Passes the output (stdout + stderr) to a ``result`` parameter.

``x-error`` is the URL to open when a script raised an exception. Passes the exception message to a ``errorMessage`` parameter.

``x-cancel`` is the URL to open when a script was stopped by the user or when the script raised ``SystemExit`` or ``KeyboardInterrupt``.


The Shortcuts app supports opening x-callback URLs. `Here <https://www.icloud.com/shortcuts/b85b8afe92e54dc9b54be5ab1495995f>`__ is an example of a Shortcut that shows the current Python version.

Pyto can also open external x-callback URLs with the `xcallback <xcallback.html>`__ module.
