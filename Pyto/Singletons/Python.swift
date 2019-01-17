
//
//  Python.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/8/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import Foundation
#if MAIN
import ios_system
#else
@_silgen_name("PyRun_SimpleStringFlags")
func PyRun_SimpleStringFlags(_: UnsafePointer<Int8>!, _: UnsafeMutablePointer<Any>!)

@_silgen_name("Py_DecodeLocale")
func Py_DecodeLocale(_: UnsafePointer<Int8>!, _: UnsafeMutablePointer<Int>!) -> UnsafeMutablePointer<wchar_t>
#endif

/// A class for interacting with `Cpython`
@objc public class Python: NSObject {
    
    #if !MAIN
    /// Throws a fatal error.
    ///
    /// - Parameters:
    ///     - message: Message describing error.
    @objc func fatalError(_ message: String) -> Never {
        return Swift.fatalError(message)
    }
    #endif
    
    /// The shared and unique instance
    @objc public static let shared = Python()
    
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
    @objc public let queue = DispatchQueue.global(qos: .userInteractive)
    
    /// The version catched passed from `"sys.version"`.
    @objc public var version = ""
    
    /// If set to `true`, scripts will run inside the REPL.
    @objc public var isREPLRunning = false
    
    /// Set to `true` while a script is running to prevent user from running one while another is running.
    @objc public var isScriptRunning = false {
        didSet {
            #if MAIN
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
            #endif
        }
    }
    
    /// All the Python output.
    public var output = ""
    
    /// Values caught by a Python script.
    @objc public var values = [String]() {
        didSet {
            #if MAIN
            DispatchQueue.main.async {
                ConsoleViewController.visible.inputAssistant.reloadData()
            }
            #endif
        }
    }
    
    /// The last error's type.
    @objc public var errorType: String?
    
    /// The last error's reason.
    @objc public var errorReason: String?
    
    /// The arguments to pass to scripts.
    @objc public var args = [String]()
    
    /// Runs given command with `ios_system`.
    ///
    /// - Parameters:
    ///     - cmd: Command to run.
    ///
    /// - Returns: The result code.
    @objc func system(_ cmd: String) -> Int32 {
        #if MAIN
        ios_switchSession(IO.shared.ios_stdout)
        ios_setDirectoryURL(FileManager.default.urls(for: .documentDirectory, in: .allDomainsMask)[0])
        ios_setStreams(IO.shared.ios_stdin, IO.shared.ios_stdout, IO.shared.ios_stderr)
        let retValue = ios_system(cmd.cValue)
        sleep(1)
        return retValue
        #else
        PyOutputHelper.print("Unsupported on native app.")
        return 1
        #endif
    }
    
    /// Exposes Pyto modules to Pyhon.
    @available(*, deprecated, message: "The Library is now located on app bundle.")
    @objc public func importPytoLib() {
        guard let newLibURL = FileManager.default.urls(for: .libraryDirectory, in: .allDomainsMask).first?.appendingPathComponent("pylib") else {
            fatalError("WHY IS THAT HAPPENING????!!!!!!! HOW THE LIBRARY DIR CANNOT BE FOUND!!!!???")
        }
        if FileManager.default.fileExists(atPath: newLibURL.path) {
            try? FileManager.default.removeItem(at: newLibURL)
        }
    }
    
    /// Run script at given URL.
    ///
    /// - Parameters:
    ///     - url: URL of the Python script to run.
    @objc public func runScript(at url: URL) {
        queue.async {
            
            guard !self.isREPLRunning else {
                PyOutputHelper.print(Localizable.Python.alreadyRunning) // Should not be called. When the REPL is running, run the script inside it.
                return
            }
            
            if url.path == Bundle.main.url(forResource: "REPL", withExtension: "py")?.path {
                self.isREPLRunning = true
            }
            
            guard let startupURL = Bundle(for: Python.self).url(forResource: "Startup", withExtension: "py"), let src = try? String(contentsOf: startupURL) else {
                PyOutputHelper.print(Localizable.Python.alreadyRunning)
                return
            }
            
            let code = String(format: src, url.path)
            PyRun_SimpleStringFlags(code.cValue, nil)
        }
    }
}
