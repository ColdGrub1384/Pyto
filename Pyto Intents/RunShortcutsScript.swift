//
//  RunShortcutsScript.swift
//  Pyto Intents
//
//  Created by Emma Labbé on 28-06-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit

/// Runs the script passed to Shortcuts.
func RunShortcutsScript(at url: URL, arguments: [String], sendOutput: Bool = true, triedDownloading: Bool = false, input: String, workingDirectory: URL?) {
    
    if !FileManager.default.fileExists(atPath: url.path) && !triedDownloading { // Try downloading
        let doc = PyDocument(fileURL: url)
        doc.open { (_) in
            RunShortcutsScript(at: doc.fileURL, arguments: arguments, sendOutput: sendOutput, triedDownloading: true, input: input, workingDirectory: workingDirectory)
        }
        return
    }
    
    var task: UIBackgroundTaskIdentifier!
    task = UIApplication.shared.beginBackgroundTask(expirationHandler: {
        UIApplication.shared.endBackgroundTask(task)
    })
    
    checkIfUnlocked(on: nil)
        
    AppDelegate.shared.shortcutScript = url.path
    
    QuickLookHelper.images = []
    PyOutputHelper.output = ""
    
    if #available(iOS 14.0, *) {
        if let code = try? String(contentsOf: url) {
            PyWidget.widgetCode = code
        }
    }
    
    func run() {
        _ = workingDirectory?.startAccessingSecurityScopedResource()
        DispatchQueue.global().async {
            Python.pythonShared?.perform(#selector(PythonRuntime.runShortcut(_:withInput:)), with: Python.Script(path: url.path, args: arguments as NSArray, workingDirectory: workingDirectory?.path ?? directory(for: url).path, debug: false, runREPL: false), with: input)
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
