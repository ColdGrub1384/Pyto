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
    if let data = (text.replacingOccurrences(of: "{u'", with: "{'").replacingOccurrences(of: ", u'", with: ", '").replacingOccurrences(of: "'", with: "\"")).data(using: .utf8) {
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
        "__builtins__.deprecated = ['runAsync', 'runSync', 'generalPasteboard', 'setString', 'setStrings', 'setImage', 'setImages', 'setURL', 'setURLs','showViewController', 'closeViewController', 'mainLoop', 'openURL', 'shareItems', 'pickDocumentsWithFilePicker', '_get_variables_hierarchy']",
        "import sys",
        "sys.path.insert(0, '\(Bundle.main.path(forResource: "site-packages", ofType: nil) ?? "")')",
        "from _codecompletion import suggestionsForCode",
        "del sys.path[0]",
        "source = '''",
        "macOS = 'macOS'",
        "iOS = 'iOS'",
        "__platform__ = macOS",
        "",
        text.replacingOccurrences(of: "'", with: "\\'"),
        "'''",
        "suggestions = repr(suggestionsForCode(source, '\(filePath)'))",
        "sys.stderr.write(suggestions+'\\n')",
        "sys.stdout.write(suggestions+'\\n')"
        ].joined(separator: ";")
    
    let scriptPath = (NSTemporaryDirectory() as NSString).appendingPathComponent("code_completion.py")
    
    if FileManager.default.fileExists(atPath: scriptPath) {
        try? FileManager.default.removeItem(at: URL(fileURLWithPath: scriptPath))
    }
    
    FileManager.default.createFile(atPath: scriptPath, contents: code.data(using: .utf8), attributes: nil)
    
    let outputPipe = Pipe()
    
    let pythonPath: String
    if Python.shared.pythonExecutable == Python.shared.bundledPythonExecutable {
        pythonPath = [
            Bundle.main.resourcePath ?? "",
            Bundle.main.path(forResource: "site-packages", ofType: nil) ?? "",
            Bundle.main.path(forResource: "python3.7", ofType: nil) ?? "",
            zippedSitePackages ?? "",
            sitePackagesDirectory,
            ].joined(separator: ":")
    } else {
        pythonPath = [
            sitePackagesDirectory,
            ].joined(separator: ":")
    }
    
    var environment                   = ProcessInfo.processInfo.environment
    environment["NSUnbufferedIO"]     = "YES"
    environment["PYTHONUNBUFFERED"]   = "1"
    environment["PYTHONPATH"]         = pythonPath
    if Python.shared.pythonExecutable == Python.shared.bundledPythonExecutable {
        environment["PYTHONHOME"]     = Bundle.main.resourcePath ?? ""
    }
    
    let process = Process()
    processes[process] = true
    process.executableURL = Python.shared.pythonExecutable
    process.arguments = ["-u", scriptPath]
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
