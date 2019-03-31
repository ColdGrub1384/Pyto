"""
A password can be asked using the Python `getpass` builtin module so it's not shown.
"""

from getpass import getpass

password = getpass("Password: ")
