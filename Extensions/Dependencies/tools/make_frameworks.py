import sys
import os
import shutil

# First argument: the name of the submodule, e.g: numpy
# Second argument: the name of the directory containing the frameworks, e.g: Numpy
# Other arguments (optional): Frameworks names without extensions to keep

def list_extensions(dir):
    files = list()
    for item in os.listdir(dir):
        abspath = os.path.join(dir, item)
        try:
            if os.path.isdir(abspath):
                files = files + list_extensions(abspath)
            elif abspath.endswith(".so"):
                files.append(abspath)
        except FileNotFoundError as err:
            print('invalid directory\n', 'Error: ', err)
    return files

info = """<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>CFBundleDevelopmentRegion</key>
    <string>en</string>
    <key>CFBundleExecutable</key>
    <string>{}</string>
    <key>CFBundleIdentifier</key>
    <string>ch.ada.Pyto.{}</string>
    <key>CFBundleInfoDictionaryVersion</key>
    <string>6.0</string>
    <key>CFBundleName</key>
    <string>{}</string>
    <key>CFBundlePackageType</key>
    <string>FMWK</string>
    <key>CFBundleShortVersionString</key>
    <string>1.0</string>
    <key>CFBundleVersion</key>
    <string>1</string>
    <key>CFBundleSupportedPlatforms</key>
    <array>
        <string>iPhoneOS</string>
    </array>
    <key>MinimumOSVersion</key>
    <string>12.0</string>
</dict>
</plist>"""

os.chdir(os.path.dirname(__file__)+"/../"+sys.argv[1]+"/build")

for dir in os.listdir("."):
    if dir.startswith("lib."):
        os.chdir(dir)
        break

extensions = list_extensions(".")

frameworks_path = "../../../../"+sys.argv[2]

if not os.path.isdir(frameworks_path):
    os.makedirs(frameworks_path)

for file in os.listdir(frameworks_path):
    if file.endswith(".framework") and not file.split(".")[0] in sys.argv:
        shutil.rmtree(os.path.join(frameworks_path, file))

def remove(framework_path):
    if os.path.isdir(framework_path):
        shutil.rmtree(framework_path)

for extension in extensions:
    parts = extension.split("/")
    del parts[0]
    name = parts[-1].split(".")[0]
    del parts[-1]
    parts.append(name)

    framework_name = "-".join(parts)+".framework"
    framework_path = os.path.join(frameworks_path, framework_name)
 
    remove(framework_path)
 
    os.makedirs(framework_path)

    name = os.path.basename(extension.split("/")[-1].split(".")[0])

    f = open(os.path.join(framework_path, "Info.plist"), "w+")
    f.write(info.format(extension.split("/")[-1], "".join(parts).replace("_", ""), name))
    f.close()
    print(framework_path)
    shutil.copy(extension, framework_path)
