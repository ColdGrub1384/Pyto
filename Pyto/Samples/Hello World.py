"""
Asks for the user's name, says hello and says goodbye 2 seconds after.
"""

from time import sleep

# Code here

name = input("What's your name? ").strip()
print(f"Hello {name}!")

sleep(2)

print("Goodbye!")
