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
    
    let code = """
    import os
    import sys
    import builtins
    import traceback
    import ssl
    from pyto import __Class__, Python
    from time import sleep
    from extensionsimporter import PillowImporter

    os.environ["widget"] = "1"

    PyWidget = __Class__("PyWidget")

    sys.meta_path.append(PillowImporter())
    sys.builtin_module_names += ("__PIL__imaging",)


    ssl._create_default_https_context = ssl._create_unverified_context

    while True:

        for code in PyWidget.codeToRun:
            try:
                exec(str(code[0]))
                PyWidget.removeWidgetID(code[1])
            except Exception as e:
                PyWidget.breakpoint(traceback.format_exc())
                print(e)
        
        PyWidget.codeToRun = []
     
        try: # Run code
            code = str(Python.shared.codeToRun)
            exec(code)
            if code == Python.shared.codeToRun:
                Python.shared.codeToRun = None
        except:
            pass

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

        sleep(0.2)
    """
    
    let url = FileManager.default.urls(for: .libraryDirectory, in: .allDomainsMask)[0].appendingPathComponent("Startup.py")
    FileManager.default.createFile(atPath: url.path, contents: code.data(using: .utf8), attributes: nil)
    
    Python.shared.runScriptAt(url)
}
