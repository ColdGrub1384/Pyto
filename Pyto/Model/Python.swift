//
//  Python.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/8/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import Foundation
import AVFoundation
#if MAIN
import UIKit
import Dynamic
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
        
        var code = """
        import traceback
        import threading
        from pyto import PyOutputHelper, Python, ignored_threads_on_crash

        stack = traceback.format_stack()
        stack.insert(-3, "\\n")
        stack = "".join(stack)
        stack = "Traceback (most recent call last):\\n"+stack
        stack += f"\\n\\n{threading.current_thread().name}\(" crashed with signal: \(signalString)")\\n"

        if threading.current_thread() not in ignored_threads_on_crash:

            try:

                if Python.shared.shouldPrintCrashTraceback(threading.current_thread().script_path):
                    PyOutputHelper.printError(stack, script=None)

                Python.shared.removeScriptFromList(threading.current_thread().script_path)
            except AttributeError:
                PyOutputHelper.printError(stack, script=None)


        """
        
        if !Thread.current.isMainThread {
            code += "threading.Event().wait()"
        } else {
            code = """
            import notifications as nc

            notif = nc.Notification()
            notif.message = stack
            nc.send_notification(notif)
            """
        }
        
        Python.pythonShared?.perform(#selector(PythonRuntime.runCode(_:)), with: code)
        #endif
    }
    
    /// Handles crashes for the current thread.
    @objc public func handleCrashesForCurrentThread() {
        
        print("Handle crashes for: \(Thread.current)")
        
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
    
    /// Returns paths for on demand libraries that are already downloaded.
    @objc public var accessibleOnDemandPaths: NSArray {
        
        #if MAIN
        if isLiteVersion.boolValue {
            return NSArray(array: [])
        }
        #endif
        
        guard let libsURL = Bundle.main.url(forResource: "OnDemandLibraries", withExtension: "plist") else {
            return NSArray(array: [])
        }
        
        guard let libs = NSDictionary(contentsOf: libsURL) else {
            return NSArray(array: [])
        }
        
        var paths = [String]()
        
        for _key in libs.allKeys {
            guard let key = _key as? String else {
                continue
            }
            
            let semaphore = DispatchSemaphore(value: 0)
            DispatchQueue.main.async {
                let request = NSBundleResourceRequest(tags: Set([key.replacingOccurrences(of: "Bio", with: "bio")]))
                request.conditionallyBeginAccessingResources { (success) in
                    
                    if success, let path = request.bundle.url(forResource: key.replacingOccurrences(of: "bio", with: "Bio"), withExtension: nil)?.deletingLastPathComponent().path {
                        paths.append(path)
                        if !self.downloadedModules.contains(path) {
                            self.downloadedModules.append(path)
                        }
                    }
                    
                    semaphore.signal()
                }
            }
            semaphore.wait()
        }
        
        return NSArray(array: paths)
    }
    
    /// Downloaded on demand modules paths.
    public var downloadedModules = [String]()
    
    #if !WIDGET
    /// Access downloadable library and its dependencies.
    ///
    /// - Parameters:
    ///     - module_: The library to download (or not if it's already downloaded).
    ///
    /// - Returns: An array of paths to add to `sys.path`.
    @objc public func access(_ module: String) -> NSArray {
        
        #if MAIN
        
        // Pure Python modules included in Pyto because it's required by a library with C extensions.
        let purePython = [
            "dask",
            "jmespath",
            "joblib",
            "smart_open",
            "boto",
            "boto3",
            "botocore"
        ]
        
        if isLiteVersion.boolValue, !purePython.contains(module) {
            return NSArray(array: ["error", "Purchase the full Pyto version to import \(module).", "upgrade"])
        }
        
        DispatchQueue.main.async {
            if !UserDefaults.standard.bool(forKey: "downloadedModule") {
                UserDefaults.standard.setValue(true, forKey: "downloadedModule")
                
                if #available(iOS 13.0, *) {
                    let alert = UIAlertController(title: module, message: Localizable.Python.DownloadingModuleAlert.explaination(module: module), preferredStyle: .alert)
                    alert.addAction(UIAlertAction(title: Localizable.Python.DownloadingModuleAlert.iUnderstand, style: .default, handler: nil))
                    for scene in UIApplication.shared.connectedScenes {
                        let window = (scene as? UIWindowScene)?.windows.first
                        if window?.isKeyWindow == true {
                            window?.topViewController?.present(alert, animated: true, completion: nil)
                            break
                        }
                    }
                }
            }
        }
        #endif
        
        var modules = [module]
        
        let path = Bundle.main.resourcePath ?? Bundle.main.bundlePath
        
        guard let libsURL = Bundle.main.url(forResource: "OnDemandLibraries", withExtension: "plist") else {
            return NSArray(array: [path])
        }
        
        guard let libs = NSDictionary(contentsOf: libsURL) else {
            return NSArray(array: [path])
        }
        
        if let dependencies = libs[module] as? [String] {
            modules.append(contentsOf: dependencies)
        }
        
        var paths = [String]()
        
        var finished = false
        
        let semaphore = DispatchSemaphore(value: 0)
        DispatchQueue.main.async {
            let request = NSBundleResourceRequest(tags: Set(modules))
            request.loadingPriority = 1
                        
            request.conditionallyBeginAccessingResources { (downloaded) in
                if downloaded {
                    for module in modules {
                        if let path = request.bundle.url(forResource: module.replacingOccurrences(of: "bio", with: "Bio"), withExtension: nil)?.deletingLastPathComponent().path, !paths.contains(path) {
                            paths.append(path)
                            if !self.downloadedModules.contains(path) {
                                self.downloadedModules.append(path)
                            }
                        }
                    }
                    
                    semaphore.signal()
                } else {
                                        
                    request.beginAccessingResources { (error) in
                        if let error = error {
                            paths = ["error", error.localizedDescription]
                        } else {
                            for module in modules {
                                if let path = request.bundle.url(forResource: module.replacingOccurrences(of: "bio", with: "Bio"), withExtension: nil)?.deletingLastPathComponent().path, !paths.contains(path) {
                                    paths.append(path)
                                    if !self.downloadedModules.contains(path) {
                                        self.downloadedModules.append(path)
                                    }
                                }
                            }
                        }
                        semaphore.signal()
                    }
                }
            }
            
            request.progress.resume()
            
            _ = Timer.scheduledTimer(withTimeInterval: 0.1, repeats: true, block: { (timer) in
                
                var newline = ""
                if finished {
                    newline = "\n"
                }
                
                PyOutputHelper.print("\r\(Localizable.Python.downloading(module: module, completedPercentage: Int(request.progress.fractionCompleted*100)))\(newline)", script: nil)
                
                if finished {
                    return timer.invalidate()
                }
            })
        }
        
        _ =  semaphore.wait(timeout: .now()+600)
        
        finished = true
                
        return NSArray(array: paths)
    }
    #endif
    
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
    
    /// The arguments to pass to scripts.
    @objc public var args = NSMutableArray()

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
        
        @objc public var breakpoints: NSArray
        
        /// Initializes the script.
        ///
        /// - Parameters:
        ///     - path: The path of the script.
        ///     - debug: Set to `true` if the script should  be debugged with `pdb`.
        ///     - runREPL: If set to `true`, the REPL will run after executing the script.
        ///     - breakpoints: Line numbers where breakpoints should be placed if the script should be debugged.
        @objc public init(path: String, debug: Bool, runREPL: Bool, breakpoints: NSArray = NSArray()) {
            self.path = path
            self.debug = debug
            self.runREPL = runREPL
            self.breakpoints = breakpoints
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
        init(code: String) {
            let url = Python.watchScriptURL
            FileManager.default.createFile(atPath: url.path, contents: nil, attributes: nil)
            try? code.write(to: url, atomically: true, encoding: .utf8)
            
            super.init(path: url.path, debug: false, runREPL: false)
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
            pythonInstance.performSelector(inBackground: #selector(PythonRuntime.runCode(_:)), with: code)
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
                    
                    if isiOSAppOnMac { // Reload toolbar
                        let toolbarItem = Dynamic(editor.runToolbarItem)
                        
                        toolbarItem.label = self.runningScripts.contains(scriptPath) ? Localizable.interrupt : Localizable.MenuItems.run
                        toolbarItem.image = self.runningScripts.contains(scriptPath) ? UIImage(systemName: "xmark") : UIImage(systemName: "play")
                        toolbarItem.target = editor
                        toolbarItem.action = NSSelectorFromString(self.runningScripts.contains(scriptPath) ? "stop" : "run")
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
                            #if !Xcode11
                            if #available(iOS 14.0, *) {
                                splitVC?.container?.update()
                            }
                            #endif
                        } else {
                            item?.rightBarButtonItem = editor.runBarButtonItem
                            #if !Xcode11
                            if #available(iOS 14.0, *) {
                                splitVC?.container?.update()
                            }
                            #endif
                            
                            if contentVC.editorSplitViewController?.editor?.textView.text == PyCallbackHelper.code {
                                // Run callback
                                
                                if PyCallbackHelper.cancelled, let cancel = PyCallbackHelper.cancelURL, let url = URL(string: cancel) {
                                    UIApplication.shared.open(url, options: [:], completionHandler: nil)
                                } else if let msg = PyCallbackHelper.exception, let error = PyCallbackHelper.errorURL, let url = URL(string: error)?.appendingParameters(params: ["errorMessage": msg]) {
                                    UIApplication.shared.open(url, options: [:], completionHandler: nil)
                                } else if let success = PyCallbackHelper.successURL, let url = URL(string: success)?.appendingParameters(params: ["result":contentVC.textView.text]) {
                                    UIApplication.shared.open(url, options: [:], completionHandler: nil)
                                }
                                
                                PyCallbackHelper.cancelURL = nil
                                PyCallbackHelper.errorURL = nil
                                PyCallbackHelper.successURL = nil
                                PyCallbackHelper.cancelled = false
                                PyCallbackHelper.exception = nil
                            }
                            
                            var images = [UIImage]()
                            splitVC?.console?.textView.textStorage.enumerateAttributes(in: NSRange(location: 0, length: splitVC?.console?.textView.textStorage.length ?? 0)) { (attr, range, _) in
                                if let plot = (attr[NSAttributedString.Key.attachment] as? NSTextAttachment)?.image {
                                    images.append(plot)
                                }
                            }
                            
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
                                    try ("\(prefix)\n"+contentVC.textView.text).write(to: group.appendingPathComponent("ShortcutOutput.txt"), atomically: true, encoding: .utf8)
                                } catch {
                                    print(error.localizedDescription)
                                }
                                #endif
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
    
    private var _cwd = FileManager.default.urls(for: .documentDirectory, in: .allDomainsMask)[0].path
    
    /// The directory from which the script is executed.
    @objc public var currentWorkingDirectory: String {
        get {
            var cwd = ""
            let semaphore = DispatchSemaphore(value: 0)
            queue.async {
                cwd = self._cwd
                semaphore.signal()
            }
                semaphore.wait()
            return cwd
        }
        
        set {
            queue.async {
                self._cwd = newValue
            }
        }
    }
    
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
        
        #if MAIN
        currentWorkingDirectory = directory(for: URL(fileURLWithPath: script.path)).path
        #endif
        
        if let pythonInstance = Python.pythonShared {
            DispatchQueue.global().async {
                pythonInstance.performSelector(inBackground: #selector(PythonRuntime.runScript(_:)), with: script)
            }
        } else {
            scriptToRun = script
        }
    }
    
    /// Runs a blank script.
    @objc public func runBlankScript() {
        guard let scriptURL = Bundle.main.url(forResource: "_blank", withExtension: "py") else {
            return
        }
        
        run(script: Script(path: scriptURL.path, debug: false, runREPL: false))
    }
    
    /// Run script at given URL. Will be ran with Python C API directly. Call it once!
    ///
    /// - Parameters:
    ///     - url: URL of the Python script to run.
    @objc public func runScriptAt(_ url: URL) {
        queue.async {
            
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
        }
    }
    
    private var scriptThreads = [String:pthread_t]()

    private var scriptsAboutToExit = [String]()
    
    @objc public func registerThread(_ script: String) {
        scriptThreads[script] = pthread_self()
    }
    
    @objc public func interruptInput(script: String) {
        #if MAIN
        PyInputHelper.userInput[script] = "<WILL INTERRUPT>"
        #endif
    }
 
    /// Sends `SystemExit`.
    ///
    /// - Parameters:
    ///     - script: The path of the script to stop.
    @objc public func stop(script: String) {
        if let thread = scriptThreads[script], !Python.shared.tooMuchUsedMemory {
            scriptsAboutToExit.append(script)
            
            #if MAIN
            PyInputHelper.userInput[script] = "<WILL INTERRUPT>"
            #endif
            
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
        }
        
        #if MAIN
        PyInputHelper.userInput[script] = ""
        #endif
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

