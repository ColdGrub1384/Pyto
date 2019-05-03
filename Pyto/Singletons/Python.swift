
//
//  Python.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/8/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import Foundation
#if MAIN && os(iOS)
import ios_system
#elseif os(iOS) && !WIDGET
@_silgen_name("PyRun_SimpleStringFlags")
func PyRun_SimpleStringFlags(_: UnsafePointer<Int8>!, _: UnsafeMutablePointer<Any>!)

@_silgen_name("Py_DecodeLocale")
func Py_DecodeLocale(_: UnsafePointer<Int8>!, _: UnsafeMutablePointer<Int>!) -> UnsafeMutablePointer<wchar_t>
#elseif os(macOS)
import Cocoa
#endif

/// A class for interacting with `Cpython`
@objc public class Python: NSObject {
    
    #if !MAIN && os(iOS)
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
    
    #if os(iOS)
    /// The bundle containing all Python resources.
    @objc var bundle: Bundle {
        if Bundle.main.bundleIdentifier?.hasSuffix(".ada.Pyto") == true || Bundle.main.bundleIdentifier?.hasSuffix(".ada.Pyto.Pyto-Widget") == true {
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
    
    /// Set to `true` while the REPL is asking for input.
    @objc public var isREPLAskingForInput = false
    
    /// The thread running current thread.
    @objc var currentRunningThreadID = -1
    
    #endif
    
    /// All the Python output.
    public var output = ""
    
    /// The last error's type.
    @objc public var errorType: String?
    
    /// The last error's reason.
    @objc public var errorReason: String?
    
    /// The arguments to pass to scripts.
    @objc public var args = [String]()
    
    #if os(iOS)
    
    /// Returns the environment.
    @objc var environment: [String:String] {
        return ProcessInfo.processInfo.environment
    }
    
    /// Set to `true` when the REPL is ready to run scripts.
    @objc var isSetup = false
    
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
        PyOutputHelper.print("Only supported on main app.")
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
    
    /// The thread running script.
    @objc public var thread: Thread?
    
    /// Run script at given URL.
    ///
    /// - Parameters:
    ///     - url: URL of the Python script to run.
    @objc public func runScript(at url: URL) {
        queue.async {
            
            self.thread = Thread.current
            
            guard !self.isREPLRunning else {
                PyOutputHelper.print(Localizable.Python.alreadyRunning) // Should not be called. When the REPL is running, run the script inside it.
                return
            }
            
            if url.path == Bundle.main.url(forResource: "REPL", withExtension: "py")?.path {
                self.isREPLRunning = true
            }
            
            #if WIDGET
            self.isScriptRunning = true
            PyRun_SimpleFileExFlags(fopen(url.path.cValue, "r"), url.lastPathComponent.cValue, 0, nil)
            #else
            guard let startupURL = Bundle(for: Python.self).url(forResource: "Startup", withExtension: "py"), let src = try? String(contentsOf: startupURL) else {
                PyOutputHelper.print(Localizable.Python.alreadyRunning)
                return
            }
            
            let code = String(format: src, url.path)
            PyRun_SimpleStringFlags(code.cValue, nil)
            #endif
        }
    }
    #endif
    
    #if os(macOS)
    
    /// Pipe used for standard input.
    var inputPipe = Pipe()
    
    /// Pipe used for standard output.
    var outputPipe = Pipe()
    
    /// The process running Python.
    var process: Process?
    
    /// The Python executable URL.
    var pythonExecutable: URL {
        get {
            return UserDefaults.standard.url(forKey: "pythonExecutable") ?? bundledPythonExecutable
        }
        
        set {
            UserDefaults.standard.set(newValue, forKey: "pythonExecutable")
        }
    }
    
    /// The bundled Python executable URL.
    let bundledPythonExecutable = Bundle.main.url(forResource: "python", withExtension: "bundle")!.appendingPathComponent("python3")
    
    /// Run script at given URL in a subprocess.
    ///
    /// - Parameters:
    ///     - url: URL of the Python script to run.
    @objc public func runScript(at url: URL) {
        
        setup()
        
        guard let startupURL = Bundle(for: Python.self).url(forResource: "Startup", withExtension: "py"), let src = try? String(contentsOf: startupURL) else {
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
        
        if process?.isRunning == true {
            process?.terminate()
            process?.standardOutput = nil
            process?.standardError = nil
            process?.standardInput = nil
        }
        
        // Only for bundled Python
        let pythonPath = [
            Bundle.main.path(forResource: "python3.7", ofType: nil) ?? "",
            Bundle.main.path(forResource: "site-packages", ofType: nil) ?? "",
            zippedSitePackages ?? "",
            Bundle.main.resourcePath ?? "",
            url.deletingLastPathComponent().path,
            sitePackagesDirectory,
            "/usr/local/lib/python3.7/site-packages"
            ].joined(separator: ":")
        
        inputPipe = Pipe()
        outputPipe = Pipe()
        
        func read(handle: FileHandle) {
            guard let str = String(data: handle.availableData, encoding: .utf8), !str.isEmpty else {
                return
            }
            
            DispatchQueue.main.async {
                for window in NSApp.windows {
                    if let editor = window.contentViewController as? EditorViewController, !(editor is REPLViewController) {
                        
                        if str.hasPrefix("Pyto.error_at_line;"), (editor.document?.fileURL == url || editor.temporaryFileURL == url) {
                            let components = str.components(separatedBy: ";")
                            guard components.indices.contains(1), let lineNum = Int(components[1]) else {
                                continue
                            }
                            editor.showErrorAtLine(lineNum)
                        } else if str == "Pyto.console.clear" || str == "Pyto.console.clear\n" {
                            editor.consoleTextView?.string = ""
                            editor.console = ""
                        } else {
                            var text = str
                            if let iCloudDrive = FileManager.default.url(forUbiquityContainerIdentifier: nil)?.appendingPathComponent("Documents").path {
                                text = text.replacingOccurrences(of: iCloudDrive, with: "iCloud")
                            }
                            
                            text = text.replacingOccurrences(of: Bundle.main.bundlePath, with: "Pyto.app")
                            
                            editor.consoleTextView?.string += text
                            editor.console += text
                            editor.consoleTextView?.scrollToBottom()
                        }
                    }
                }
            }
        }
        
        outputPipe.fileHandleForReading.readabilityHandler = read
        
        process = Process()
        process?.executableURL = pythonExecutable
        process?.arguments = ["-u", tmpFile]
        
        var environment                 = ProcessInfo.processInfo.environment
        environment["TMP"]              = NSTemporaryDirectory()
        environment["MPLBACKEND"]       = "TkAgg"
        environment["NSUnbufferedIO"]   = "YES"
        environment["PYTHONUNBUFFERED"] = "1"
        if pythonExecutable == bundledPythonExecutable {
            environment["PIP_TARGET"]   = sitePackagesDirectory
            environment["PYTHONHOME"]   = Bundle.main.resourcePath ?? ""
            environment["PYTHONPATH"]   = pythonPath
        }
        process?.environment          = environment
        
        process?.terminationHandler = { _ in
            self.isScriptRunning = false
        }
        process?.standardOutput = outputPipe
        process?.standardError = outputPipe
        process?.standardInput = inputPipe
        isScriptRunning = true
        
        EditorViewController.clear()
        
        do {
            try process?.run()
        } catch {
            NSApp.presentError(error)
        }
    }
    
    /// Setups Python executable and C extensions. Should be called before running any script.
    func setup() {
    
        DispatchQueue.global().async {
            if !FileManager.default.fileExists(atPath: sitePackagesDirectory) {
                try? FileManager.default.createDirectory(at: URL(fileURLWithPath: sitePackagesDirectory), withIntermediateDirectories: true, attributes: nil)
            }
        }
    }
    
    #endif
    
    #if os(iOS)
    
    /// Set to `false` to send `SystemExit`.
    @objc private var _isScriptRunning = false
    
    /// Set to `true` to send `KeyboardInterrupt`.
    @objc private var _interrupt = false
    
    /// Sends `SystemExit`.
    @objc public func stop() {
        _isScriptRunning = false
    }
    
    @objc public func interrupt() {
        _interrupt = true
    }
    
    #endif
    
    /// Set to `true` while a script is running to prevent user from running one while another is running.
    @objc public var isScriptRunning = false {
        didSet {
            #if os(iOS)
            DispatchQueue.main.async {
                #if MAIN
                let contentVC = ConsoleViewController.visible
                
                guard let editor = (contentVC.parent as? EditorSplitViewController)?.editor ?? EditorSplitViewController.visible?.editor else {
                    return
                }
                
                let item = editor.parent?.navigationItem
                
                if self.isScriptRunning {
                    item?.rightBarButtonItem = editor.stopBarButtonItem
                } else {
                    item?.rightBarButtonItem = editor.runBarButtonItem
                }
                item?.rightBarButtonItem?.isEnabled = (self.isScriptRunning == self.isScriptRunning)
                #endif                
            }
            #elseif os(macOS)
            if !isScriptRunning && process?.isRunning == true {
                process?.terminate()
            }
            
            EditorViewController.toggleStopButton()
            #endif
        }
    }
}
