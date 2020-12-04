//
//  SetupPython.swift
//  WidgetExtension
//
//  Created by Adrian Labbé on 11-07-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import Foundation

var isPythonSetup = false

func SetupPython() {
    
    guard !isPythonSetup else {
        return
    }
    
    isPythonSetup = true
    
    init_python()
    
    for folder in FoldersBrowserViewController.accessibleFoldersShared {
        _ = folder.startAccessingSecurityScopedResource()
    }
    
    let sitePackages: String
    if let url = FoldersBrowserViewController.sitePackages {
        sitePackages = "\"\(url.path.replacingOccurrences(of: "\"", with: "\\\""))\""
    } else {
        sitePackages = "None"
    }
    
    let code = """
<<<<<<< HEAD
    try:
        import os
        import sys
        import builtins
        import traceback
        import ssl
        import threading
        from pyto import __Class__, Python
        from time import sleep
        from extensionsimporter import PillowImporter
        from rubicon.objc import NSObject, objc_method, ObjCClass
        from ctypes import CDLL

        NSAutoreleasePool = ObjCClass("NSAutoreleasePool")

        os.environ["widget"] = "1"

        site_packages = \(sitePackages)
        if site_packages is not None:
            sys.path.append(site_packages)

        PyWidget = __Class__("PyWidget")

        sys.meta_path.append(PillowImporter())
        sys.builtin_module_names += ("__PIL__imaging",)

        ssl._create_default_https_context = ssl._create_unverified_context

        class Thread(threading.Thread):
            def run(self):
                pool = NSAutoreleasePool.alloc().init()
                Python.shared.handleCrashesForCurrentThread()
                super().run()
                pool.release()

        threading.Thread = Thread

        class ScriptThread(threading.Thread):
            script_path = None

        class PythonImplementation(NSObject):

            @objc_method
            def runCode_(self, code):
                try:
                    thread = threading.Thread(target=exec, args=(str(code),))
                    thread.start()
                    thread.join()
                except Exception as e:
                    PyWidget.breakpoint(traceback.format_exc())
                    print(str(e))
            
            @objc_method
            def runWidgetWithCode_andID_(self, code, id):

                Python.shared.handleCrashesForCurrentThread()

                try:
                    del sys.modules["widgets"]
                except KeyError:
                    pass

                try:
                    del sys.modules["ui_constants"]
                except KeyError:
                    pass

                try:
                    exec(str(code))
                    PyWidget.removeWidgetID(str(id))
                except Exception as e:
                    PyWidget.breakpoint(traceback.format_exc())
                    print(traceback.format_exc())

                try:
                    del sys.modules["ui_constants"]
                except KeyError:
                    pass

                try:
                    del sys.modules["pyto_ui"]
                except KeyError:
                    pass
                
                try:
                    del sys.modules["widgets"]
                except KeyError:
                    pass

                try:
                    _values = sys.modules["_values"]
                     
                    for attr in dir(_values):
                        if attr not in _values._dir:
                            delattr(_values, attr)
                except:
                    pass


        Python.pythonShared = PythonImplementation.alloc().init()
        CDLL(None).putenv(b"IS_PYTHON_RUNNING=1")

        Python.shared.handleCrashesForCurrentThread()

        threading.Event().wait()
    except:
        import traceback
        from pyto import __Class__

        __Class__("PyWidget").breakpoint(traceback.format_exc())
=======
    import os
    import sys
    import builtins
    import traceback
    import ssl
    import threading
    from pyto import __Class__, Python
    from time import sleep
    from extensionsimporter import PillowImporter
    from rubicon.objc import NSObject, objc_method
    from ctypes import CDLL

    os.environ["widget"] = "1"

    site_packages = \(sitePackages)
    if site_packages is not None:
        sys.path.append(site_packages)

    PyWidget = __Class__("PyWidget")

    sys.meta_path.append(PillowImporter())
    sys.builtin_module_names += ("__PIL__imaging",)

    ssl._create_default_https_context = ssl._create_unverified_context

    class ScriptThread(threading.Thread):
        script_path = None

    class PythonImplementation(NSObject):

        @objc_method
        def runCode_(self, code):
            try:
                thread = threading.Thread(target=exec, args=(str(code),))
                thread.start()
                thread.join()
            except Exception as e:
                PyWidget.breakpoint(traceback.format_exc())
                print(str(e))
        
        @objc_method
        def runWidgetWithCode_andID_(self, code, id):
            try:
                exec(str(code))
                PyWidget.removeWidgetID(str(id))
            except Exception as e:
                PyWidget.breakpoint(traceback.format_exc())
                print(traceback.format_exc())

            try:
                del sys.modules["pyto_ui"]
            except KeyError:
                pass
            
            try:
                _values = sys.modules["_values"]
                 
                for attr in dir(_values):
                    if attr not in _values._dir:
                        delattr(_values, attr)
            except:
                pass

    Python.pythonShared = PythonImplementation.alloc().init()
    CDLL(None).putenv(b"IS_PYTHON_RUNNING=1")

    threading.Event().wait()
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
    """
    
    let url = FileManager.default.urls(for: .libraryDirectory, in: .allDomainsMask)[0].appendingPathComponent("Startup.py")
    FileManager.default.createFile(atPath: url.path, contents: code.data(using: .utf8), attributes: nil)
    
    Python.shared.runScriptAt(url)
}
