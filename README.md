If you are reading this after installing the app from the App Store, firstly, thank you! A bug is making impossible to run another script after getting an errror. I submitted a new update but is Waiting For Review since a long time and I cannot request an expedited review due to a previous rejection. Sorry.

# Pyto

[![Download on the App Store](https://pisth.github.io/appstorebadge.svg)](https://itunes.apple.com/us/app/pyto-python-ide/id1436650069?l=fr&ls=1&mt=8)

Pyto is a Python IDE for iOS that uses the Python C API.

![screenshots](docs/screenshots.png)

```
Pyto is a Python 3.6 IDE for iPhone an iPad. You can run code directly on your device and offline.

Features:

  - Python 3.6 with all default libraries like "sys"
  - Pre-installed modules for interacting with the app
  - Full Python REPL
  - Use your own modules on your scripts

Third party libraries:
  - dropbox
  - html5lib
  - numpy
  - paramiko
  - rubicon.objc
```

## Building

### Integrating Python

1. [Download Python for iOS](https://s3-us-west-2.amazonaws.com/pybee-briefcase-support/Python-Apple-support/3.6/iOS/Python-3.6-iOS-support.b6.tar.gz).
2. Unarchive the file.
3. Move `BZip2`, `OpenSSL` , `XZ` and `Python` to the repo.

### Integrating ios_system

1. Download `release.tar.gz` from [ios_system latest release](https://github.com/holzschu/ios_system/releases/latest).
2. Unarchive the file.
3. Move ios_system to the repo. 
4. `$ git submodule update --init --recursive`

## Contributing

If you want to add a package or a module, just add it to the [site-packages](https://github.com/ColdGrub1384/Pyto/tree/master/site-packages) directory.
