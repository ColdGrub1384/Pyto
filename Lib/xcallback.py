"""
Opening x-callback URLs

This module is used to interact with other apps with `x-callback URLs <http://x-callback-url.com>`__.
"""

import webbrowser
from pyto import PyCallbackHelper
from _add_url_params import add_url_params
from urllib.parse import urlparse, parse_qs
from time import sleep


def open_url(url: str) -> str:
    """
    Opens the given x-callback URL. The function will return only if the request was successfully completed.

    Raises: ``RuntimeError`` if there was an error and ``SystemExit`` if the request was cancelled.
    Returns: The result sent by the opened app.

    :param url: The URL to open.
    :rtype: str
    """

    if PyCallbackHelper is None:
        raise NotImplementedError("x-callback urls are only supported on Pyto's main app.")

    params = {"x-success": "pyto://callback/", "x-cancel": "pyto://callback/", "x-error": "pyto://callback/", "x-source": "Pyto"}
    webbrowser.open(add_url_params(url, params))

    while True:
        if PyCallbackHelper.url is not None:
            url = str(PyCallbackHelper.url)
            PyCallbackHelper.url = None

            parsed = urlparse(url)
            params = parse_qs(parsed.query)

            if "errorMessage" in params:
                msg = params["errorMessage"]
                if type(msg) is list:
                    msg = msg[0]
                raise RuntimeError(msg)
            elif "result" in params:
                res = params["result"]
                if type(res) is list:
                    res = res[0]
                return res
            else:
                raise SystemExit()

        sleep(0.2)