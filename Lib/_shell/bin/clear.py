"""
Clears the shell.
"""

def main():
    print(u"{}[2J{}[;H".format(chr(27), chr(27)), end="")

if __name__ == "__main__":
    main()