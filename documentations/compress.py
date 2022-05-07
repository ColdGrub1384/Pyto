#!/usr/bin/env python3

import os
import subprocess
import glob

def main():
    os.chdir(os.path.dirname(__file__))
    for dir in os.listdir(os.getcwd()):
        if os.path.isdir(dir) and dir != "dependencies":
            try:
                os.remove(dir+".zip")
            except FileNotFoundError:
                pass
            
            subprocess.Popen(["zip", "-r", dir+".zip"]+glob.glob(dir+"/*"))

if __name__ == "__main__":
    main()
