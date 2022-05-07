#!/usr/bin/env python3

from pbxproj import XcodeProject

def main():
    with open("index.rst", "r") as f:
        index = f.read()
    
    project = XcodeProject.load("../Pyto.xcodeproj/project.pbxproj")
    for conf in project.objects.get_project_configurations():
        version = conf["buildSettings"]["VERSION"]
        build = conf["buildSettings"]["BUILD_NUMBER"]
        break
    
    with open("../python3_ios/Python-3.10/Include/patchlevel.h", "r") as f:
        for line in f.read().split("\n"):
            if "#define PY_VERSION" in line:
                python_version = line.split('"')[-2]
                break

    new_index = []
    for line in index.split("\n"):
        if line.startswith("Pyto version:"):
            line = "Pyto version: "+version+" ("+build+")"
        elif line.startswith("Python version:"):
            line = "Python version: "+python_version

        new_index.append(line)

    new_index = "\n".join(new_index)
    
    with open("index.rst", "w") as f:
        f.write(new_index)

if __name__ == "__main__":
    main()