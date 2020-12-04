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
<<<<<<< HEAD
        let doc = PyDocument(fileURL: url)
=======
        let doc = UIDocument(fileURL: url)
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
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
    
<<<<<<< HEAD
    func run() {
        DispatchQueue.global().async {
            Python.pythonShared?.perform(#selector(PythonRuntime.runScript(_:)), with: Python.Script(path: url.path, debug: false, runREPL: false))
        }
        
        _ = Timer.scheduledTimer(withTimeInterval: 0.5, repeats: true, block: { (timer) in
            if !Python.shared.isScriptRunning(url.path) {
                PyOutputHelper.sendOutputToShortcuts(nil)
                timer.invalidate()
            }
        })
    }
=======
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
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
    
    if !Python.shared.isSetup {
        _ = Timer.scheduledTimer(withTimeInterval: 0.5, repeats: true, block: { (timer) in
            if Python.shared.isSetup {
<<<<<<< HEAD
                Thread.sleep(forTimeInterval: 0.5)
                run()
=======
                Python.shared.run(code: code)
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
                timer.invalidate()
            }
        })
    } else {
<<<<<<< HEAD
        run()
=======
        Python.shared.run(code: code)
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
    }
}
