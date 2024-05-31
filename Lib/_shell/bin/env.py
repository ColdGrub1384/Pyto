"""
Print environment variables.

usage: env [name=value ...]
"""

import os
import sys

def main():
    if len(sys.argv) > 1:
        for arg in sys.argv[1:]:
            name = arg.split("=")[0]
            value = arg.split("=")[1]
            os.environ[name] = value
        
    for (key, value) in os.environ.items():
            print(f"{key}={value}")

if __name__ == "__main__":
    main()