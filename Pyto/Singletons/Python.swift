
//
//  Python.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/8/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import Foundation
import ios_system

/// A class for interacting with `Cpython`
@objc class Python: NSObject {
    
    /// The shared and unique instance
    @objc static let shared = Python()
    
    private override init() {}
    
    /// The bundle containing all Python resources.
    @objc var bundle: Bundle {
        if Bundle.main.bundleIdentifier == "ch.marcela.ada.Pyto" {
            return Bundle(identifier: "ch.ada.Python")!
        } else {
            return Bundle(path: Bundle.main.path(forResource: "Python.framework", ofType: nil)!)!
        }
    }
    
    /// The queue running scripts.
    @objc let queue = DispatchQueue.global(qos: .userInteractive)
    
    /// The version catched passed from `"sys.version"`.
    @objc var version = ""
    
    /// If set to `true`, scripts will run inside the REPL.
    @objc var isREPLRunning = false
    
    /// Set to `true` while a script is running to prevent user from running one while another is running.
    @objc var isScriptRunning = false {
        didSet {
            DispatchQueue.main.async {
                let contentVC = ConsoleViewController.visible
                
                guard let editor = (contentVC.parent as? EditorSplitViewController)?.firstChild as? EditorViewController else {
                    return
                }
                
                let item = contentVC.parent?.navigationItem
                
                if self.isScriptRunning {
                    item?.rightBarButtonItem = editor.stopBarButtonItem
                } else {
                    item?.rightBarButtonItem = editor.runBarButtonItem
                }
            }
        }
    }
    
    /// All the Python output.
    var output = ""
    
    /// Values caught by a Python script.
    @objc var values = [String]() {
        didSet {
            DispatchQueue.main.async {
                ConsoleViewController.visible.inputAssistant.reloadData()
            }
        }
    }
    
    /// The last error's type.
    @objc var errorType: String?
    
    /// The last error's reason.
    @objc var errorReason: String?
    
    /// The arguments to pass to scripts.
    @objc var args = [String]()
    
    /// Runs given command with `ios_system`.
    ///
    /// - Parameters:
    ///     - cmd: Command to run.
    ///
    /// - Returns: The result code.
    @objc func system(_ cmd: String) -> Int32 {
        ios_switchSession(IO.shared.ios_stdout)
        ios_setDirectoryURL(FileManager.default.urls(for: .documentDirectory, in: .allDomainsMask)[0])
        ios_setStreams(IO.shared.ios_stdin, IO.shared.ios_stdout, IO.shared.ios_stderr)
        return ios_system(cmd.cValue)
    }
    
    /// Exposes Pyto modules to Pyhon.
    @objc func importPytoLib() {
        guard let newLibURL = FileManager.default.urls(for: .libraryDirectory, in: .allDomainsMask).first?.appendingPathComponent("pylib") else {
            fatalError("WHY IS THAT HAPPENING????!!!!!!! HOW THE LIBRARY DIR CANNOT BE FOUND!!!!???")
        }
        guard let libURL = Bundle.main.url(forResource: "site-packages", withExtension: "") else {
            fatalError("The Pyto library was not found.")
        }
        do {
            if FileManager.default.fileExists(atPath: newLibURL.path) {
                try FileManager.default.removeItem(at: newLibURL)
            }
            try FileManager.default.copyItem(at: libURL, to: newLibURL)
        } catch {
            fatalError(error.localizedDescription)
        }
    }
    
    /// Run script at given URL.
    ///
    /// - Parameters:
    ///     - url: URL of the Python script to run.
    @objc func runScript(at url: URL) {
        queue.async {
            
            guard !self.isREPLRunning else {
                PyOutputHelper.print(Localizable.Python.alreadyRunning) // Should not be called. When the REPL is running, run the script inside it.
                return
            }
            
            if url.path == Bundle.main.url(forResource: "REPL", withExtension: "py")?.path {
                self.isREPLRunning = true
            }
            
            guard let startupURL = Bundle.main.url(forResource: "Startup", withExtension: "py"), let src = try? String(contentsOf: startupURL) as NSString else {
                PyOutputHelper.print(Localizable.Python.alreadyRunning)
                return
            }
            
            let code = NSString(format: src, url.path) as String
            PyRun_SimpleStringFlags(code.cValue, nil)
        }
    }
}
