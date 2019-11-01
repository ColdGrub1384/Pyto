"""
Encrpypts a password with PyNaCl.
"""

import nacl.secret
import nacl.utils
import sys
import base64
import getpass

key = nacl.utils.random(nacl.secret.SecretBox.KEY_SIZE)
box = nacl.secret.SecretBox(key)

if len(sys.argv) > 1:
    password = " ".join(sys.argv[1:]).encode()
else:
    password = getpass.getpass("Password: ")

password = password.encode()

encrypted = box.encrypt(password)
encrypted = base64.b64encode(encrypted).decode("ascii")
print(encrypted)

decrypted = box.decrypt(base64.b64decode(encrypted)).decode()
