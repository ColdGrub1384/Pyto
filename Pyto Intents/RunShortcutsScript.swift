//
//  RunShortcutsScript.swift
//  Pyto Intents
//
//  Created by Adrian Labbé on 28-06-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import UIKit

/// Runs the script passed to Shortcuts.
func RunShortcutsScript(at url: URL, arguments: [String], sendOutput: Bool = true, triedDownloading: Bool = false) {
    
    if !FileManager.default.fileExists(atPath: url.path) && !triedDownloading { // Try downloading
        let doc = PyDocument(fileURL: url)
        doc.open { (_) in
            RunShortcutsScript(at: doc.fileURL, arguments: arguments, sendOutput: sendOutput, triedDownloading: true)
        }
        return
    }
    
    var task: UIBackgroundTaskIdentifier!
    task = UIApplication.shared.beginBackgroundTask(expirationHandler: {
        UIApplication.shared.endBackgroundTask(task)
    })
    
    checkIfUnlocked(on: nil)
    
    Python.shared.currentWorkingDirectory = directory(for: url).path
    
    AppDelegate.shared.shortcutScript = url.path
    Python.shared.args = NSMutableArray(array: arguments)
    
    QuickLookHelper.images = []
    PyOutputHelper.output = ""
    
    if #available(iOS 14.0, *) {
        if let code = try? String(contentsOf: url) {
            PyWidget.widgetCode = code
        }
    }
    
    let code = """
    from rubicon.objc import ObjCClass
    from pyto import PyOutputHelper, Python
    from threading import Thread
    import sys
    import os

    path = str(Python.shared.currentWorkingDirectory)
    os.chdir(path)

    if path not in sys.path:
        sys.path.append(path)

    script = str(ObjCClass("Pyto.AppDelegate").shared.shortcutScript) # Get the script to run

    class ScriptThread(Thread):
        script_path = None

    def run(script, path):
        from console import __clear_mods__
        from pyto import PyOutputHelper, Python
        import runpy
        import sys

        error_message = None

        try:
            # Set arguments
            args = []
            for arg in Python.shared.args:
                args.append(str(arg))

            sys.argv = [sys.argv[0]]+args

            __clear_mods__()
            runpy.run_path(script)
        except SystemExit:
            pass
        except KeyboardInterrupt:
            pass
        except Exception as e:
            error_message = str(e)

        __clear_mods__()

        if path in sys.path:
            sys.path.remove(path)

        \(sendOutput ? "PyOutputHelper.sendOutputToShortcuts(error_message)" : "")

    thread = Thread(target=run, args=(script, path))
    thread.script_path = script
    thread.start()
    thread.join()
    """
    
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
