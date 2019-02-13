//
//  REPLViewController.swift
//  Pyto Mac
//
//  Created by Adrian Labbé on 2/12/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import Cocoa
import SavannaKit

/// A View controller for interacting with the REPL.
class REPLViewController: EditorViewController, NSWindowDelegate {
    
    // MARK: - Process
    
    /// The process running the REPL.
    let process = Process()
    
    /// The pipe used for output.
    let outputPipe = Pipe()
    
    /// The pipe used for input.
    let inputPipe = Pipe()
    
    /// Starts the REPL.
    func startREPL() {
        guard let startupURL = Bundle(for: Python.self).url(forResource: "Startup", withExtension: "py"), let src = try? String(contentsOf: startupURL) else {
            return
        }
        
        guard let url = Bundle.main.url(forResource: "REPL", withExtension: "py") else {
            return
        }
        
        guard let code = String(format: src, url.path).data(using: .utf8) else {
            return
        }
        
        guard let pythonExecutble = Bundle.main.url(forResource: "python3", withExtension: nil) else {
            return
        }
        
        let tmpFile = NSTemporaryDirectory()+"/script.py"
        
        if FileManager.default.fileExists(atPath: tmpFile) {
            try? FileManager.default.removeItem(atPath: tmpFile)
        }
        
        FileManager.default.createFile(atPath: tmpFile, contents: code, attributes: [:])
        
        let pythonPath = [
            Bundle.main.path(forResource: "python3.7", ofType: nil) ?? "",
            Bundle.main.path(forResource: "site-packages", ofType: nil) ?? "",
            Bundle.main.path(forResource: "PyObjc", ofType: nil) ?? "",
            Bundle.main.resourcePath ?? "",
            url.deletingLastPathComponent().path,
            "/usr/local/lib/python3.7/site-packages"
            ].joined(separator: ":")
        
        func read(handle: FileHandle) {
            guard let str = String(data: handle.availableData, encoding: .utf8), !str.isEmpty else {
                return
            }
            
            DispatchQueue.main.async {
                if str != "Pyto.console.clear" && str != "Pyto.console.clear\n" {
                    self.consoleTextView?.string += str
                    self.console += str
                    self.consoleTextView?.scrollToBottom()
                } else {
                    self.consoleTextView?.string = ""
                    self.console = ""
                }
            }
        }
        
        outputPipe.fileHandleForReading.readabilityHandler = read
        
        process.executableURL = pythonExecutble
        process.arguments = ["-u", tmpFile]
        
        var environment               = ProcessInfo.processInfo.environment
        environment["TMP"]            = NSTemporaryDirectory()
        environment["PYTHONHOME"]     = Bundle.main.resourcePath ?? ""
        environment["PYTHONPATH"]     = pythonPath
        environment["MPLBACKEND"]     = "TkAgg"
        environment["NSUnbufferedIO"] = "YES"
        process.environment          = environment
        
        process.terminationHandler = { _ in
            DispatchQueue.main.async {
                self.view.window?.close()
            }
        }
        process.standardOutput = outputPipe
        process.standardError = outputPipe
        process.standardInput = inputPipe
        
        do {
            try process.run()
        } catch {
            NSApp.presentError(error)
        }
    }
    
    // MARK: - Editor view controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        (consoleTextView as? ConsoleTextView)?.interruptionHandler = {
            self.process.interrupt()
        }
        (consoleTextView as? ConsoleTextView)?.eofHandler = {
            self.inputPipe.fileHandleForReading.closeFile()
            self.inputPipe.fileHandleForWriting.closeFile()
        }
        
        startREPL()
    }
    
    override func viewWillAppear() {
        super.viewWillAppear()
        
        view.window?.delegate = self
    }
    
    // MARK: - Window delegate
    
    func windowWillClose(_ notification: Notification) {
        process.terminationHandler = nil
        process.terminate()
    }
}
