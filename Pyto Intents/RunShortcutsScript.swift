//
//  RunShortcutsScript.swift
//  Pyto Intents
//
//  Created by Adrian Labbé on 28-06-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import UIKit

/// Runs the script passed to Shortcuts.
func RunShortcutsScript(at url: URL, arguments: [String], sendOutput: Bool = true) {
    var task: UIBackgroundTaskIdentifier!
    task = UIApplication.shared.beginBackgroundTask(expirationHandler: {
        UIApplication.shared.endBackgroundTask(task)
    })
    
    checkIfUnlocked(on: nil)
    
    Python.shared.currentWorkingDirectory = EditorViewController.directory(for: url).path
    
    AppDelegate.shared.shortcutScript = url.path
    Python.shared.args = NSMutableArray(array: arguments)
    
    QuickLookHelper.images = []
    PyOutputHelper.output = ""
    
    if #available(iOS 14.0, *) {
        if let code = try? String(contentsOf: url) {
            PyWidget.widgetCode = code
        }
    }
    
    var code = """
    from rubicon.objc import ObjCClass
    from pyto import PyOutputHelper, Python
    import runpy
    import sys
    import os

    path = str(Python.shared.currentWorkingDirectory)
    os.chdir(path)

    if path not in sys.path:
        sys.path.append(path)

    error_message = None

    try:
        script = str(ObjCClass("Pyto.AppDelegate").shared.shortcutScript) # Get the script to run
        
        # Set arguments
        args = []
        for arg in Python.shared.args:
            args.append(str(arg))

        sys.argv = [sys.argv[0]]+args

        runpy.run_path(script)
    except SystemExit:
        pass
    except KeyboardInterrupt:
        pass
    except Exception as e:
        error_message = str(e)

    if path in sys.path:
        sys.path.remove(path)

    
    """
    
    if sendOutput {
        code += "PyOutputHelper.sendOutputToShortcuts(error_message)"
    }
    
    if !Python.shared.isSetup {
        _ = Timer.scheduledTimer(withTimeInterval: 0.5, repeats: true, block: { (timer) in
            if Python.shared.isSetup {
                Python.shared.run(code: code)
                timer.invalidate()
            }
        })
    } else {
        Python.shared.run(code: code)
    }
}
