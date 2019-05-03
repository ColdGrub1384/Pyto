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
    
    /// Set to `true` for running pip.
    var pip = false
    
    /// Set to `true` when Python is started.
    private(set) var startedPython = false
    
    // MARK: - Process
    
    /// The process running the REPL.
    let process = Process()
    
    /// The pipe used for output.
    let outputPipe = Pipe()
    
    /// The pipe used for input.
    let inputPipe = Pipe()
    
    /// Starts Python.
    ///
    /// - Parameters:
    ///     - script: The script to run. Default is the REPL.
    func startPython(script: URL? = nil) {
        guard let startupURL = Bundle(for: Python.self).url(forResource: "Startup", withExtension: "py"), let src = try? String(contentsOf: startupURL) else {
            return
        }
        
        guard let url = script ?? Bundle.main.url(forResource: "REPL", withExtension: "py") else {
            return
        }
        
        guard let code = String(format: src, url.path).data(using: .utf8) else {
            return
        }
        
        let tmpFile = NSTemporaryDirectory()+"/script.py"
        
        if FileManager.default.fileExists(atPath: tmpFile) {
            try? FileManager.default.removeItem(atPath: tmpFile)
        }
        
        FileManager.default.createFile(atPath: tmpFile, contents: code, attributes: [:])
        
        let pythonPath = [
            Bundle.main.resourcePath ?? "",
            Bundle.main.path(forResource: "site-packages", ofType: nil) ?? "",
            Bundle.main.path(forResource: "python3.7", ofType: nil) ?? "",
            zippedSitePackages ?? "",
            url.deletingLastPathComponent().path,
            sitePackagesDirectory,
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
        
        process.executableURL = Python.shared.pythonExecutable
        process.arguments = ["-u", tmpFile]
        
        var environment               = ProcessInfo.processInfo.environment
        environment["TMP"]            = NSTemporaryDirectory()
        environment["MPLBACKEND"]     = "TkAgg"
        environment["NSUnbufferedIO"] = "YES"
        environment["PYTHONUNBUFFERED"] = "1"
        if Python.shared.pythonExecutable == Python.shared.bundledPythonExecutable {
            environment["PIP_TARGET"] = sitePackagesDirectory
            environment["PYTHONHOME"] = Bundle.main.resourcePath ?? ""
            environment["PYTHONPATH"] = pythonPath
        }
        process.environment          = environment
        
        process.terminationHandler = { _ in
            if !self.pip {
                DispatchQueue.main.async {
                    self.view.window?.close()
                }
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
    }
    
    override func viewWillAppear() {
        super.viewWillAppear()
        
        if !startedPython {
            if pip, let installer = Bundle.main.url(forResource: "installer", withExtension: "py") {
                startPython(script: installer)
            } else {
                startPython()
            }
            startedPython = true
        }
        
        view.window?.delegate = self
    }
    
    // MARK: - Window delegate
    
    func windowWillClose(_ notification: Notification) {
        process.terminationHandler = nil
        process.terminate()
    }
}
