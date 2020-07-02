//
//  RunShortcutsScript.swift
//  Pyto Intents
//
//  Created by Adrian Labbé on 28-06-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import UIKit

/// Runs the script passed to Shortcuts.
func RunShortcutsScript(at url: URL, arguments: [String]) {
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
    
    Python.shared.run(code: """
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

    PyOutputHelper.sendOutputToShortcuts(error_message) # Send output to Shortcuts
    """)
}
