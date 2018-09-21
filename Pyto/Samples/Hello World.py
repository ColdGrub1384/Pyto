"""
Asks for the user's name, says hello and says good bye 2 seconds after.
"""

from time import sleep

# Code here

name = input("What's your name? ")
print("Hello "+name+"!")

sleep(2)

print("Good Bye!")
