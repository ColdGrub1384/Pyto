//
//  Code Completion.swift
//  Pyto Mac
//
//  Created by Adrian Labbé on 2/9/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import Cocoa

/// Taken from https://stackoverflow.com/a/30480777/7515957
fileprivate func convertToDictionary(text: String) -> [String: Any]? {
    if let data = (text.replacingOccurrences(of: "'", with: "\"")).data(using: .utf8) {
        do {
            return try JSONSerialization.jsonObject(with: data, options: []) as? [String: Any]
        } catch {
            print(error.localizedDescription)
        }
    }
    return nil
}

fileprivate var processes = [Process:Bool]()

/// Completes code on current window.
func completeCode() {
    
    if Thread.current.isMainThread {
        
        for (process, _) in processes {
            if process.isRunning {
                processes[process] = false
                process.terminate()
            }
        }
        
        return DispatchQueue.global().async(execute: completeCode)
    }
    
    guard let pythonExecutble = Bundle.main.url(forResource: "python3", withExtension: nil) else {
        return
    }
    
    var text = ""
    var filePath = ""
    
    let semaphore = DispatchSemaphore(value: 0)
    DispatchQueue.main.async {
        for window in NSApp.windows {
            if window.isKeyWindow, let editor = window.contentViewController as? EditorViewController, !(editor is REPLViewController) {
                let range = NSRange(location: 0, length: editor.textView.contentTextView.selectedRange().location)
                if editor.textView.contentTextView.rangeExists(range) {
                    text = (editor.textView.text as NSString).substring(with: range)
                } else {
                    text = ""
                }
                filePath = editor.document?.fileURL?.path ?? ""
                editor.suggestions = []
                editor.completions = []
                editor.suggestionsCollectionView?.reloadData()
            }
        }
        semaphore.signal()
    }
    semaphore.wait()
    
    let code = [
        "__builtins__.deprecated = ['runAsync', 'runSync', 'generalPasteboard', 'setString', 'setStrings', 'setImage', 'setImages', 'setURL', 'setURLs','showViewController', 'closeViewController', 'mainLoop', 'openURL', 'shareItems', 'pickDocumentsWithFilePicker']",
        "from _codecompletion import suggestionsForCode",
        "source = '''",
        text.replacingOccurrences(of: "'", with: "\\'"),
        "'''",
        "print(suggestionsForCode(source, '\(filePath)'))"
        ].joined(separator: ";")
    
    let scriptPath = (NSTemporaryDirectory() as NSString).appendingPathComponent("code_completion.py")
    
    if FileManager.default.fileExists(atPath: scriptPath) {
        try? FileManager.default.removeItem(at: URL(fileURLWithPath: scriptPath))
    }
    
    FileManager.default.createFile(atPath: scriptPath, contents: code.data(using: .utf8), attributes: nil)
    
    let outputPipe = Pipe()
    
    let pythonPath = [
        Bundle.main.resourcePath ?? "",
        Bundle.main.path(forResource: "site-packages", ofType: nil) ?? "",
        Bundle.main.path(forResource: "python3.7", ofType: nil) ?? "",
        Bundle.main.path(forResource: "lib/python3.7/site-packages", ofType: nil) ?? "",
        Bundle.main.path(forResource: "PyObjc", ofType: nil) ?? "",
        sitePackagesDirectory ?? "",
        "/usr/local/lib/python3.7/site-packages"
        ].joined(separator: ":")
    
    var environment               = ProcessInfo.processInfo.environment
    environment["PYTHONHOME"]     = Bundle.main.resourcePath ?? ""
    environment["PYTHONPATH"]     = pythonPath
    
    let process = Process()
    processes[process] = true
    process.executableURL = pythonExecutble
    process.arguments = [scriptPath]
    process.standardOutput = outputPipe
    process.environment = environment
    
    try? process.run()
    process.waitUntilExit()
    
    if processes[process] == false {
        return
    }
    
    if let str = String(data: outputPipe.fileHandleForReading.readDataToEndOfFile(), encoding: .utf8), let dict = convertToDictionary(text: str) as? [String:String] {
        DispatchQueue.main.async {
            for window in NSApp.windows {
                if window.isKeyWindow, let editor = window.contentViewController as? EditorViewController, !(editor is REPLViewController) {
                    editor.completions = []
                    editor.suggestions = []
                    for (key, value) in dict {
                        editor.suggestions.append(key)
                        editor.completions.append(value)
                    }
                    editor.suggestionsCollectionView?.reloadData()
                }
            }
        }
    }
}
