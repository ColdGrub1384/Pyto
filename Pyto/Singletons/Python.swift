
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
    @objc let queue = DispatchQueue.global()
    
    /// The version catched passed from `"sys.version"`.
    @objc var version = ""
    
    /// If set to `true`, scripts will run inside the REPL.
    @objc var isREPLRunning = false
    
    /// Set to `true` while a script is running to prevent user from running one while another is running.
    @objc var isScriptRunning = false {
        didSet {
            print("isScriptRunning: \(isScriptRunning)")
        }
    }
    
    /// All the Python output.
    var output = ""
    
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
            
            DispatchQueue.main.async {
                PyContentViewController.shared?.dismissKeyboard()
            }
        }
    }
}
