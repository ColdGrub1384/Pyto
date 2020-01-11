xcallback
=========

.. currentmodule:: xcallback

.. automodule:: xcallback
   :members:

Example with Shortcuts
----------------------

.. highlight:: python
.. code-block:: python

    """
    Opens a Shortcut and retrieves the result.
    """

    import xcallback
    from urllib.parse import quote

    shortcut_name = input("The name of the shortcut to open: ")
    shortcut_input = input("What would you like to send to the Shortcut? ")

    # https://support.apple.com/guide/shortcuts/apdcd7f20a6f/ios
    url = f"shortcuts://x-callback-url/run-shortcut?name={quote(shortcut_name)}&input=text&text={quote(shortcut_input)}"

    try:
        res = xcallback.open_url(url) # If successed, returns the result
        print("Result:\n"+res)
    except RuntimeError as e:
        print("Error: "+str(e)) # If failed, raises ``RuntimeError``
    except SystemExit:
        print("Cancelled") # If cancelled, raises ``SystemExit``