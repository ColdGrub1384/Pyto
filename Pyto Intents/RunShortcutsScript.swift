//
//  RunShortcutsScript.swift
//  Pyto Intents
//
//  Created by Emma Labbé on 28-06-20.
//  Copyright © 2020 Emma Labbé. All rights reserved.
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
    
    if !Python.shared.isSetup {
        _ = Timer.scheduledTimer(withTimeInterval: 0.5, repeats: true, block: { (timer) in
            if Python.shared.isSetup {
                Thread.sleep(forTimeInterval: 0.5)
                run()
                timer.invalidate()
            }
        })
    } else {
        run()
    }
}
