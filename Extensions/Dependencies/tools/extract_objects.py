from subprocess import check_output
import sys

objects = check_output(["ar", "-t", sys.argv[1]]).decode().split("\n")

for object in objects:
    if not object.endswith(".o") or object.endswith("lso.o"):
        continue
    
    check_output(["ar",  "-xv", sys.argv[1], object])

