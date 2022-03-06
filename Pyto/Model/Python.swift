//
//  Python.swift
//  Pyto
//
//  Created by Emma Labbé on 9/8/18.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import Foundation
import AVFoundation
#if MAIN
import UIKit
import Dynamic
import ios_system
#elseif os(iOS) && !WIDGET
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
    #else
    /// The full  Python version
    @objc public var version: String {
        return String(cString: Py_GetVersion())
    }
    #endif
    
    /// The shared and unique instance
    @objc public static var shared = Python()
    
    /// A Python subclass of NSObject that executes and stops scripts.
    @objc public static var pythonShared: NSObject?
    
    /// Capture sessions per threads so they are stopped when its corresponding thread is killed.
    var captureSessionsPerThreads = [Thread:AVCaptureSession]()
    
    private override init() {}
    
    /// The bundle containing all Python resources.
    @objc var bundle: Bundle {
        if Bundle.main.bundleIdentifier?.hasSuffix(".ada.Pyto") == true || Bundle.main.bundleIdentifier?.hasSuffix(".ada.Pyto.Pyto-Widget") == true || Bundle.main.bundleIdentifier?.hasSuffix(".ada.Pyto.Widget") == true {
            return Bundle(identifier: "ch.ada.Python")!
        } else if let bundle = Bundle(path: Bundle.main.path(forResource: "Python.framework", ofType: nil) ?? "") {
            return bundle
        } else if let bundle = Bundle(path: ((Bundle.main.privateFrameworksPath ?? "") as NSString).appendingPathComponent("Python.framework")) {
            return bundle
        } else {
            return Bundle(for: Python.self)
        }
    }
    
    @objc private func shouldPrintCrashTraceback(_ script: String) -> Bool {
        let ret = !scriptsAboutToExit.contains(script)
        if !ret, let i = scriptsAboutToExit.firstIndex(of: script) {
            scriptsAboutToExit.remove(at: i)
        }
        return ret
    }
    
    private func crashHandler(_ signal: Int32) {
        
        guard !Thread.current.isMainThread else {
            return
        }
        
        let signalString: String
        switch signal {
        case SIGKILL:
            signalString = "SIGKILL"
        case SIGABRT:
            signalString = "SIGABRT"
        case SIGFPE:
            signalString = "SIGFPE"
        case SIGILL:
            signalString = "SIGILL"
        case SIGINT:
            signalString = "SIGINT"
        case SIGSEGV:
            signalString = "SIGSEGV"
        case SIGBUS:
            signalString = "SIGBUS"
        default:
            signalString = "UNKNOWN"
        }
        
        captureSessionsPerThreads[Thread.current]?.stopRunning()
        captureSessionsPerThreads[Thread.current] = nil
                
        #if MAIN
        
        let code = """
        import traceback
        import threading
        from pyto import PyOutputHelper, Python, ignored_threads_on_crash

        stack = traceback.format_stack()
        stack.insert(-3, "\\n")
        stack = "".join(stack)
        stack = "Traceback (most recent call last):\\n"+stack
        stack += f"\\n\\n{threading.current_thread().name}\(" crashed with signal: \(signalString)")\\n"

        try:
            Python.shared.removeScriptFromList(threading.current_thread().script_path)
        except AttributeError:
            pass
        
        if threading.current_thread() not in ignored_threads_on_crash:

            try:

                if Python.shared.shouldPrintCrashTraceback(threading.current_thread().script_path):
                    PyOutputHelper.printError(stack, script=None)

                Python.shared.removeScriptFromList(threading.current_thread().script_path)
            except AttributeError:
                PyOutputHelper.printError(stack, script=None)

        threading.Event().wait()
        """
        
        Python.pythonShared?.perform(#selector(PythonRuntime.runCode(_:)), with: code)
        #endif
    }
    
    /// Handles crashes for the current thread.
    @objc public func handleCrashesForCurrentThread() {
                
        signal(SIGKILL, { signal in
            Python.shared.crashHandler(signal)
        })
        signal(SIGABRT, { signal in
            Python.shared.crashHandler(signal)
        })
        signal(SIGFPE, { signal in
            Python.shared.crashHandler(signal)
        })
        signal(SIGILL, { signal in
            Python.shared.crashHandler(signal)
        })
        signal(SIGINT, { signal in
            Python.shared.crashHandler(signal)
        })
        signal(SIGSEGV, { signal in
            Python.shared.crashHandler(signal)
        })
        signal(SIGBUS, { signal in
            Python.shared.crashHandler(signal)
        })
    }
    
    /// The queue running scripts.
    @objc public let queue = DispatchQueue.global(qos: .userInteractive)
    
    /// A string passed by a widget.
    @objc public var widgetLink: String?
    
    /// Additional builtin modules names.
    @objc public var modules = NSMutableArray() {
        didSet {
            #if MAIN
            if modules.count != 0, isLiteVersion.boolValue {
                modules = []
            }
            #endif
        }
    }
    
    /// A boolean indicating whether C extensions can be imported.
    @objc public var canImportExtensions: Bool {
        #if MAIN
        !isLiteVersion.boolValue
        #else
        true
        #endif
    }
    
    /// Libraries requiring the full version to be imported.
    @objc public var fullVersionExclusives: [String] {
        guard let url = Bundle.main.url(forResource: "FullVersionExclusives", withExtension: "json") else {
            return []
        }
        
        guard let data = try? Data(contentsOf: url) else {
            return []
        }
        
        return ((try? JSONSerialization.jsonObject(with: data, options: .fragmentsAllowed)) as? [String]) ?? []
    }
    
    /// Imported builtin modules.
    @objc public var importedModules = NSMutableArray()
    
    /// If set to `true`, scripts will run inside the REPL.
    @objc public var isREPLRunning = false
    
    /// Set to `true` while the REPL is asking for input.
    @objc public var isREPLAskingForInput = false
    
    /// The thread running current thread.
    @objc var currentRunningThreadID = -1
    
    /// All the Python output.
    public var output = ""
    
    /// The last error's type.
    @objc public var errorType: String?
    
    /// The last error's reason.
    @objc public var errorReason: String?

    /// A boolean indicating whether the app is running out of memory.
    @objc public var tooMuchUsedMemory = false
    
    /// A class representing a script to run.
    @objc public class Script: NSObject {
        
        /// The path of the script.
        @objc public var path: String
        
        /// Set to `true` if the script should  be debugged with `pdb`.
        @objc public var debug: Bool
        
        /// If set to `true`, the REPL will run after executing the script.
        @objc public var runREPL: Bool
        
        /// A JSON array of `Breakpoint.PythonBreakpoint`
        @objc public var breakpoints: String
        
        /// Arguments passed to 'sys.argv'
        @objc public var args: NSArray
        
        /// The working directory of the thread running the script.
        @objc public var workingDirectory: String
        
        /// Initializes the script.
        ///
        /// - Parameters:
        ///     - path: The path of the script.
        ///     - args: Arguments passed to 'sys.argv'.
        ///     - workingDirectory: The working directory of the thread running the script.
        ///     - debug: Set to `true` if the script should  be debugged with `pdb`.
        ///     - runREPL: If set to `true`, the REPL will run after executing the script.
        ///     - breakpoints: A list of breakpoints
        init(path: String, args: NSArray, workingDirectory: String, debug: Bool, runREPL: Bool, breakpoints: [Breakpoint] = []) {
            self.path = path
            self.args = args
            self.workingDirectory = workingDirectory
            self.debug = debug
            self.runREPL = runREPL
            do {
                self.breakpoints = String(data: (try JSONEncoder().encode(breakpoints.filter({ $0.isEnabled }).map({ $0.pythonBreakpoint }))), encoding: .utf8) ?? "[]"
            } catch {
                self.breakpoints = "[]"
            }
        }
    }
    
    ///
    @objc public class PyHTMLPage: Script {
        
        /// The path of the page.
        @objc var pagePath: String?
        
        /// Initializes the PyHTML page from the given path.
        ///
        /// - Parameters:
        ///     - path: The path of a PyHTML path.
        ///     - args: The arguments passed to sys.argv.
        ///     - workingDirectory: The working directory of the thread running the script.
        @objc public init(path: String, args: NSArray, workingDirectory: String) {
            let url = FileManager.default.urls(for: .cachesDirectory, in: .allDomainsMask)[0].appendingPathComponent("_pyhtml_page.py")
            
            let code = """
            from htmpy import WebView
            import pyto_ui as ui
            from urllib.parse import quote

            web_view = WebView()
            
            path = "\(path.replacingOccurrences(of: "\"", with: "\\\""))"
            web_view.load_file_path(path)
            
            web_view.background_color = ui.COLOR_SYSTEM_BACKGROUND
            
            ui.show_view(web_view, ui.PRESENTATION_MODE_FULLSCREEN)
            """
            
            try? code.write(to: url, atomically: false, encoding: .utf8)
            
            super.init(path: url.path, args: args, workingDirectory: workingDirectory, debug: false, runREPL: false)
            self.pagePath = path
        }
    }
    
    /// The URL where the Apple Watch script is stored.
    @objc public static let watchScriptURL = URL(fileURLWithPath: NSTemporaryDirectory()).appendingPathComponent("Watch.py")
    
    /// A script to be executed from the Watch app.
    @objc public class WatchScript: Script {
        /// Initilializes the script with given code.
        ///
        /// - Parameters:
        ///     - code: The code to run.
        ///     - workingDirectory: The working directory of the thread running the script.
        init(code: String, workingDirectory: String) {
            let url = Python.watchScriptURL
            FileManager.default.createFile(atPath: url.path, contents: nil, attributes: nil)
            try? code.write(to: url, atomically: true, encoding: .utf8)
            
            super.init(path: url.path, args: NSArray(), workingDirectory: workingDirectory, debug: false, runREPL: false)
        }
    }
    
    /// Python code to run.
    @objc public var codeToRun: String?
    
    /// Runs given code.
    ///
    /// - Parameters:
    ///     - code: Python code to run.
    @objc public func run(code: String) {
        if let pythonInstance = Python.pythonShared {
            Thread {
                pythonInstance.perform(#selector(PythonRuntime.runCode(_:)), with: code)
            }.start()
        } else {
            codeToRun = code
        }
    }
    
    /// The path of the script to run. Set it to run it.
    @objc public var scriptToRun: Script?
    
    @objc private func removeScriptFromList(_ script: String) {
        while runningScripts.index(of: script) != NSNotFound {
            let arr = NSMutableArray(array: runningScripts)
            arr.removeObjects(at: IndexSet(integer: runningScripts.index(of: script)))
            runningScripts = arr
        }
    }
    
    @objc private func addScriptToList(_ script: String) {
        if runningScripts.index(of: script) == NSNotFound {
            let arr = NSMutableArray(array: runningScripts)
            arr.add(script)
            runningScripts = arr
        }
    }
    
    /// The path of the scripts running.
    @objc public var runningScripts = NSArray() {
        didSet {
            DispatchQueue.main.async {
                #if MAIN
                
                NotificationCenter.default.post(name: EditorViewController.didUpdateBarItemsNotificationName, object: nil)
                
                #if WIDGET
                let visibles = [ConsoleViewController.visible ?? ConsoleViewController()]
                #else
                let visibles = ConsoleViewController.visibles
                #endif
                
                for contentVC in visibles {
                    let splitVC = contentVC.editorSplitViewController
                    guard let editor = splitVC?.editor, let scriptPath = editor.document?.fileURL.path else {
                        continue
                    }
                    
                    if #available(iOS 15.0, *) {
                        splitVC?.console?.pipTextView.pictureInPictureController?.invalidatePlaybackState()
                    }
                    
                    guard !(contentVC.editorSplitViewController is REPLViewController) && !(contentVC.editorSplitViewController is RunModuleViewController) && !(contentVC.editorSplitViewController is PipInstallerViewController) else {
                        let installer = contentVC.editorSplitViewController as? PipInstallerViewController
                        installer?.done = !(self.runningScripts.contains(scriptPath))
                        installer?.navigationItem.leftBarButtonItem?.isEnabled = installer?.done ?? false
                        continue
                    }
                    
                    let item = editor.parent?.navigationItem
                    
                    if item?.rightBarButtonItem != contentVC.editorSplitViewController?.closeConsoleBarButtonItem {
                        if self.runningScripts.contains(scriptPath) {
                            item?.rightBarButtonItem = editor.stopBarButtonItem
                        } else {
                            item?.rightBarButtonItem = editor.runBarButtonItem
                            
                            contentVC.getPlainText { text in
                                if contentVC.editorSplitViewController?.editor?.textView.text == PyCallbackHelper.code {
                                    // Run callback
                                    
                                    if PyCallbackHelper.cancelled, let cancel = PyCallbackHelper.cancelURL, let url = URL(string: cancel) {
                                        UIApplication.shared.open(url, options: [:], completionHandler: nil)
                                    } else if let msg = PyCallbackHelper.exception, let error = PyCallbackHelper.errorURL, let url = URL(string: error)?.appendingParameters(params: ["errorMessage": msg]) {
                                        UIApplication.shared.open(url, options: [:], completionHandler: nil)
                                    } else if let success = PyCallbackHelper.successURL, let url = URL(string: success)?.appendingParameters(params: ["result":text]) {
                                        UIApplication.shared.open(url, options: [:], completionHandler: nil)
                                    }
                                    
                                    PyCallbackHelper.cancelURL = nil
                                    PyCallbackHelper.errorURL = nil
                                    PyCallbackHelper.successURL = nil
                                    PyCallbackHelper.cancelled = false
                                    PyCallbackHelper.exception = nil
                                }
                                
                                let images = contentVC.images
                                
                                // Shortcut
                                if editor.isShortcut {
                                    
                                    editor.isShortcut = false
                                    
                                    // Send result to Shortcuts
                                    
                                    guard let group = FileManager.default.containerURL(forSecurityApplicationGroupIdentifier: "group.pyto") else {
                                        return
                                    }
                                    
                                    #if MAIN
                                    let prefix: String
                                    if PyCallbackHelper.exception != nil {
                                        prefix = "Fail"
                                    } else {
                                        prefix = "Success"
                                    }
                                    
                                    do {
                                        let encodedImages = try NSKeyedArchiver.archivedData(withRootObject: images, requiringSecureCoding: true)
                                        try encodedImages.write(to: group.appendingPathComponent("ShortcutPlots"))
                                    } catch {
                                        print(error.localizedDescription)
                                    }
                                    
                                    do {
                                        try ("\(prefix)\n"+text).write(to: group.appendingPathComponent("ShortcutOutput.txt"), atomically: true, encoding: .utf8)
                                    } catch {
                                        print(error.localizedDescription)
                                    }
                                    #endif
                                }
                            }
                        }
                    }
                }
                #endif
            }
        }
    }
    
    /// Add a script here to send `KeyboardInterrupt`to it.
    @objc public var scriptsToInterrupt = NSMutableArray()
    
    /// Add a script here to send `SystemExit`to it.
    @objc public var scriptsToExit = NSMutableArray()
    
    /// Returns the environment.
    @objc var environment: NSDictionary {
        return ProcessInfo.processInfo.environment as NSDictionary
    }
    
    /// Set to `true` when the REPL is ready to run scripts.
    @objc var isSetup: Bool {
        
        #if MAIN
        if !isUnlocked {
            return false
        }
        #endif
        
        return ProcessInfo.processInfo.environment.keys.contains("IS_PYTHON_RUNNING")
    }
    
    /// The thread running script.
    @objc public var thread: Thread?
    
    /// Runs the given script.
    ///
    /// - Parameters:
    ///     - script: Script to run.
    @objc(runScript:) public func run(script: Script) {
        if let pythonInstance = Python.pythonShared {
            Thread(block: {
                pythonInstance.perform(#selector(PythonRuntime.runScript(_:)), with: script)
            }).start()
        } else {
            scriptToRun = script
        }
    }
    
    /// Runs a blank script.
    @objc public func runBlankScript() {
        guard let scriptURL = Bundle.main.url(forResource: "_blank", withExtension: "py") else {
            return
        }
        
        run(script: Script(path: scriptURL.path, args: NSArray(), workingDirectory: FileManager.default.urls(for: .documentDirectory, in: .allDomainsMask)[0].path, debug: false, runREPL: false))
    }
        
    /// Run script at given URL. Will be ran with Python C API directly. Call it once!
    ///
    /// - Parameters:
    ///     - url: URL of the Python script to run.
    @objc public func runScriptAt(_ url: URL) {
        #if targetEnvironment(simulator)
        return Void()
        #else
        self.thread = Thread.current
        
        #if WIDGET && !Xcode11
        #else
        guard !self.isREPLRunning else {
            return
        }
        
        self.isREPLRunning = true
        #endif
        
        #if WIDGET
        let arr = NSMutableArray(array: self.runningScripts)
        arr.add(url.path)
        self.runningScripts = arr
        PyRun_SimpleFileExFlags(fopen(url.path.cValue, "r"), url.lastPathComponent.cValue, 0, nil)
        #else
        guard let startupURL = Bundle(for: Python.self).url(forResource: "Startup", withExtension: "py"), let src = try? String(contentsOf: startupURL) else {
            return
        }
        
        let code = String(format: src, url.path)
        PyRun_SimpleStringFlags(code.cValue, nil)
        NSLog("Will throw fatal error")
        Swift.fatalError()
        #endif
        #endif
    }
    
    /// Threads and their respective script paths.
    var scriptThreads = [String:pthread_t]()

    private var scriptsAboutToExit = [String]()
    
    @objc public func registerThread(_ script: String) {
        scriptThreads[script] = pthread_self()
    }
    
    @objc public func interruptInput(script: String) {
        #if MAIN
        PyInputHelper.userInput[script] = "<WILL INTERRUPT>"
        #endif
    }
 
    /// An alternative to `DispatchSemaphore` that doesn't interrupt the exit of a script.
    class Semaphore: Hashable {
        
        static func == (lhs: Python.Semaphore, rhs: Python.Semaphore) -> Bool {
            lhs.semaphore == rhs.semaphore
        }
        
        func hash(into hasher: inout Hasher) {
            hasher.combine(semaphore)
        }
        
        static var sempahores = [(scriptPath: String, semaphore: Semaphore)]()
        
        private let semaphore: DispatchSemaphore
        
        /// Initializes the semaphore with the given value.
        ///
        /// - Parameters:
        ///     - value: The value passed to the initializer of `DispatchSemaphore`.
        init(value: Int) {
            self.semaphore = DispatchSemaphore(value: value)
        }
        
        /// Wait.
        func wait() {
            if let scriptPath = Python.shared.getScriptPath() {
                Self.sempahores.append((scriptPath: scriptPath, semaphore: self))
            }
            
            self.semaphore.wait()
            
            if let i = Self.sempahores.firstIndex(where: { $0.semaphore == self }) {
                Self.sempahores.remove(at: i)
            }
        }
        
        /// Signal.
        func signal() {
            self.semaphore.signal()
        }
    }
    
    /// Sends `SystemExit`.
    ///
    /// - Parameters:
    ///     - script: The path of the script to stop.
    @objc public func stop(script: String) {
        if let thread = scriptThreads[script], !Python.shared.tooMuchUsedMemory {
            scriptsAboutToExit.append(script)
            
            while let i = Semaphore.sempahores.firstIndex(where: { $0.scriptPath == script }) {
                Self.Semaphore.sempahores[i].semaphore.signal()
                Self.Semaphore.sempahores.remove(at: i)
            }
            
            pthread_kill(thread, SIGSEGV)
            return
        } else if let pythonInstance = Python.pythonShared {
            DispatchQueue.global().async {
                pythonInstance.performSelector(inBackground: #selector(PythonRuntime.exitScript(_:)), with: script)
            }
        } else {
            if scriptsToExit.index(of: script) == NSNotFound {
                scriptsToExit.add(script)
            }
            
            #if MAIN
            PyInputHelper.userInput[script] = ""
            #endif
        }
    }
    
    /// Returns `threading.current_thread().script_path`
    @objc public func getScriptPath() -> String? {
        return Self.pythonShared?.perform(#selector(PythonRuntime.getScriptPath))?.takeUnretainedValue() as? String
    }
    
    /// Sends `KeyboardInterrupt`.
    ///
    /// - Parameters:
    ///     - script: The path of the script to interrupt.
    @objc public func interrupt(script: String) {
                
        if let pythonInstance = Python.pythonShared {
            DispatchQueue.global().async {
                pythonInstance.performSelector(inBackground: #selector(PythonRuntime.interruptScript(_:)), with: script)
            }
        } else {
            if scriptsToInterrupt.index(of: script) == NSNotFound {
                scriptsToInterrupt.add(script)
            }
        }
        
        #if MAIN
        PyInputHelper.userInput[script] = "<WILL INTERRUPT>"
        #endif
    }

    /// Checks if a script is currently running.
    ///
    /// - Parameters:
    ///     - script: Script to check.
    ///
    /// - Returns: `true` if the passed script is currently running.
    @objc public func isScriptRunning(_ script: String) -> Bool {
        return runningScripts.contains(script)
    }
}

