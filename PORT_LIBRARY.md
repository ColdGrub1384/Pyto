# Porting Python library to iOS

## Pure Python modules

To add a pure Python module to this app, add it to the [`site-packages`](https://github.com/ColdGrub1384/Pyto/tree/master/site-packages) directory. Make sure to add dependencies.

## Embedding library with C code

If a module contains C code, it's harder. It has to be embedded in the app as dynamic libraries.

NOTE: This text assumes the library you want to compile has only C, Cython or Python code. `Scipy` contains `Fortran` code, so it's harder to compile it.

### Step 1: Compiling

The first step is compiling. To do so, you can use [this tool](https://github.com/ColdGrub1384/compile_ios). It's a command line tool to compile C projects to iOS. Clone it and install it.

    $ git clone https://github.com/ColdGrub1384/compile_ios
    ...
    $ cd compile_ios
    $ ./install.sh
    
Then, download a release of the repository you want to compile, for example, `Numpy`. `cd` into the repo.

    $ cd numpy-1.16.1
    
Then, run `iosenv`, this will open a shell with environment for compiling the library.

    $ iosenv
    ...
    
To configure the repo, you may create a `setup.cfg` file with settings. For example, while compiling `Matplotlib`, that would be useful to not compile `macOS` support.
While compiling `Numpy`, you should set these environment variables to disable Blas, Lapack and Atlas: `BLAS=None LAPACK=None ATLAS=None`.
    
Run `setup.py` to build the extension.

    $ python3 setup.py build_ext
    ...

Probably, many errors will be displayed. Check for the line where errors occurred and see if the code compiled because of a compilation condition.
For example:

```c
#ifdef CONDITION
code <- Error
#endif
```
   
In that case, try to undefine or set to `0` `CONDITION`.

```c
#undef CONDITION
#ifdef CONDITION
code <- Error
#endif
```
    
You may also get errors like `'exc_[..]' undefined. Did you mean 'curexc_[..]'`
In that case, just replace `exc` by `curexc`.

Make sure the extension compiled with no error, they can be hidden. You can redirect `stdout` to hide not useful output and just show errors and warnings.

When the extension compiled, see the content of the `build/lib[..]`. You should see some `.so` files.

### Embedding on app bundle

Now, if you have many `.so` files, this will be hard. `.so` files cannot be directly embedded on the app bundle because the App Store will automatically reject that.
We have to make frameworks from those binaries.

`cd` into the Pyto repo and create a folder named as the library you compiled with a capital. Then, create a `.framework` folder with an `Info.plist` inside it for each `.so` file you have. 

    $ cd Pyto
    $ mkdir NumPy
    $ cd NumPy
    $ mkdir _umath_linalg.framework fftpack_lite.framework lapack_lite.framework mtrand.framework _multiarray_umath.framework
    $ for FRAMEWORK in *.framework
    do
    touch $FRAMEWORK/Info.plist
    done
    $
    
Also, create an `Info.plist` file inside the folder containing frameworks. The content can be anything. It's just for the Xcode project.

    $ touch Info.plist
    
Now, copy every `.so` file into its corresponding framework.
    
Then, on all `Info.plist` files inside frameworks, write this:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
	<key>CFBundleDevelopmentRegion</key>
	<string>en</string>
	<key>CFBundleExecutable</key>
	<string>[FILE NAME]</string>
	<key>CFBundleIdentifier</key>
	<string>[BUNDLE IDENTIFIER]</string>
	<key>CFBundleInfoDictionaryVersion</key>
	<string>6.0</string>
	<key>CFBundleName</key>
	<string>[BUNDLE NAME]</string>
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
</plist>
```

NOTE: Here, by library name, I mean the name of the `.so` file and not the entire library.

Replace `[FILE NAME]` by the `.so` contained on the framework file name (include the extension), replace `[BUNDLE NAME]` by the name of the library, without extensions. And replace `[BUNDLE IDENTIFIER]` by the bundle identifier. For example: "com.yourcompany.libraryname". It cannot contain underscores.

Add the folder you created to the Xcode project (as group and NOT folder reference!). Then, add each `Info.plist` file contained in frameworks on the just created group. Make sure to UNCHECK "Copy Items if Needed" .

Then, select Xcode project on sidebar and select "Pyto" target. Go to Build Phases and add all frameworks you added on "Embed Frameworks" if they are not already added.

For each framework, add a Copy Files Phase. Set "Frameworks" as destination. Drag a `.so` file and the corresponding `Info.plist`. Type the corresponding framework file name with extension on "Subpath". Make sure "Code Sign On Copy" is checked for the `.so` file.

Run on device to check it works.

### Importing module

Now the module is embedded, this is the funny part. We have to import the module.

Open the `main.m` file under `Pyto` folder. Type this code:

```c
[..]

PyMODINIT_FUNC (*PyInit__multiarray_umath)(void);
PyMODINIT_FUNC (*PyInit_fftpack_lite)(void);
PyMODINIT_FUNC (*PyInit__umath_linalg)(void);
PyMODINIT_FUNC (*PyInit_lapack_lite)(void);
PyMODINIT_FUNC (*PyInit_mtrand)(void);

void *_multiarray_umath = NULL; // _multiarray_umath.cpython-37m-darwin.so
void *fftpack_lite = NULL; // fftpack_lite.cpython-37m-darwin.so
void *umath_linalg = NULL; // umath_linalg.cpython-37m-darwin.so
void *lapack_lite = NULL; // lapack_lite.cpython-37m-darwin.so
void *mtrand = NULL; // mtrand.cpython-37m-darwin.so

void init_numpy() {
}

[..]

void init_python() {

[..]

// MARK: - Init builtins
#if MAIN
init_numpy();

[..]

```

Replace "numpy" by the library you compiled name. 

Each `void` pointer name corresponds to a `.so` file name. They represent libraries. 

Each `PyMODINIT_FUNC` variable is a `PyInit` function from the C extension. Find the function by typing this:

    $ nm -g [.so file] | grep PyInit
    ...
    
So, on the example, `PyInit__multiarray_umath` is a function from `_multiarray_umath` module. 

They are uninitialized, so write this on the init function:

```c
NSError *error;
for (NSURL *bundle in [NSFileManager.defaultManager contentsOfDirectoryAtURL:mainBundle().privateFrameworksURL includingPropertiesForKeys:NULL options:NSDirectoryEnumerationSkipsHiddenFiles error:&error]) {
        
    NSURL *file = [bundle URLByAppendingPathComponent:[bundle.URLByDeletingPathExtension URLByAppendingPathExtension:@"cpython-37m-darwin.so"].lastPathComponent];
        
    NSString *name = file.URLByDeletingPathExtension.URLByDeletingPathExtension.lastPathComponent;
        
    void *handle;
        
    if ([name isEqualToString:@"_multiarray_umath"]) {
       load(_multiarray_umath);
    } else if ([name isEqualToString:@"fftpack_lite"]) {
        load(fftpack_lite);
    } else if ([name isEqualToString:@"_umath_linalg"]) {
        load(umath_linalg);
    } else if ([name isEqualToString:@"lapack_lite"]) {
        load(lapack_lite);
    } else if ([name isEqualToString:@"mtrand"]) {
        load(mtrand);
    } else {
        continue;
    }
        
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
    }
}
    
*(void **) (&PyInit__multiarray_umath) = dlsym(_multiarray_umath, "PyInit__multiarray_umath");
*(void **) (&PyInit_fftpack_lite) = dlsym(fftpack_lite, "PyInit_fftpack_lite");
*(void **) (&PyInit__umath_linalg) = dlsym(umath_linalg, "PyInit__umath_linalg");
*(void **) (&PyInit_lapack_lite) = dlsym(lapack_lite, "PyInit_lapack_lite");
*(void **) (&PyInit_mtrand) = dlsym(mtrand, "PyInit_mtrand");
    
PyImport_AppendInittab("__numpy_core__multiarray_umath", PyInit__multiarray_umath);
PyImport_AppendInittab("__numpy_fft_fftpack_lite", PyInit_fftpack_lite);
PyImport_AppendInittab("__numpy_linalg__umath_linalg", PyInit__umath_linalg);
PyImport_AppendInittab("__numpy_linalg_lapack_lite", PyInit_lapack_lite);
PyImport_AppendInittab("__numpy_random_mtrand", PyInit_mtrand);
```

This code looks for all frameworks and finds libraries used by Numpy. For each C extension, write:

```c
 else if ([name isEqualToString:@"<LIBRARY NAME>"]) {
     load(<LIBRARY NAME>);
 ```
 
 Then, initialize all `PyInit` functions:
 
 ```c
 *(void **) (&<NAME OF PyInit FUNCTION>) = dlsym(<C EXTENSION>, "<NAME OF PYINIT FUNCTION>");
 ```
 
 Now, the most important thing:
 
 ```c
 PyImport_AppendInittab("__numpy_core__multiarray_umath", PyInit__multiarray_umath);
 ```
 
`__numpy_core__multiarray_umath` corresponds to `numpy.core._multiarray_umath`. Replace values with yours.

`cd` into the library repo and build the entire library (`iosenv` isn't needed).

    $ cd numpy-1.16.1
    $ python3 setup.py build
    ...
    
Then, remove all `.so` files from the build.

    $ find build -name "*.so" -delete
    
Copy the folder under `build/lib*` to `site-packages`.

Run the app and try to import your libraries. Errors will be displayed. Try to look paths of libraries that failed to import. 

For example: `numpy.core._multiarray_umath`. Then write:

```c
PyImport_AppendInittab("__numpy_core__multiarray_umath", PyInit__multiarray_umath);
```
 
Open `site-packages/extensionsimporter.py`. Before `# MARK: - All`, write this:
 
```python
 
[..]
 
# MARK: - NumPy

class NumpyImporter(object):
    """
    Meta path for importing NumPy to be added to `sys.meta_path`.
    """
    
    __is_importing__ = False
    
    def find_module(self, fullname, mpath=None):
        if fullname in ('numpy.core._multiarray_umath', 'numpy.fft.fftpack_lite', 'numpy.linalg._umath_linalg', 'numpy.linalg.lapack_lite', 'numpy.random.mtrand'):
            return self
        
        if fullname == 'numpy' and not self.__is_importing__:
            return self
        
        return
    
    def load_module(self, fullname):
        f = fullname
        if f != 'numpy':
            f = '__' + fullname.replace('.', '_')
        mod = sys.modules.get(f)
        if mod is None:
            def importMod():
                mod = importlib.__import__(f)
                sys.modules[fullname] = mod
            
            if fullname != 'numpy' or __host__ is widget:
                importMod()
            else:
                try:
                    self.__is_importing__ = True
                    importMod()
                    self.__is_importing__ = False
                except KeyboardInterrupt:
                    pass
                except SystemExit:
                    pass
                except Exception as e:
                    print(e)
                    report_error('Numpy', traceback.format_exc())
                    raise
                finally:
                    self.__is_importing__ = False

            return mod
        
        return mod

[..]

# MARK: - All

__all__ = ['NumpyImporter', 'MatplotlibImporter', 'PandasImporter'] # Add here the name of the function you created.
```
 
Replace "Numpy" by the name of the library you're trying to add.
 
Replace
 
```python
('numpy.core._multiarray_umath', 'numpy.fft.fftpack_lite', 'numpy.linalg._umath_linalg', 'numpy.linalg.lapack_lite', 'numpy.random.mtrand')
```

by the name of the builtin C extensions the library will import. Include the name of the library.

Open `Startup.py` from Xcode project on `Pyto > Resources > Startup.py`.

Then, add your importer function name here:

```python
for importer in (NumpyImporter, MatplotlibImporter, PandasImporter):
```
