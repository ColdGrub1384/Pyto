
//
//  Python.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/8/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import Foundation

/// A class for interacting with `Cpython`
@objc class Python: NSObject {
    
    /// The shared and unique instance
    @objc static let shared = Python()
    
    private override init() {}
    
    /// The queue running scripts.
    @objc let queue = DispatchQueue.global()
    
    /// The version catched passed from `"sys.version"`.
    @objc var version = ""
    
    /// If set to `true`, scripts will not be ran because the app would crash.
    @objc var isREPLRunning = false
    
    /// All the Python output.
    var output = ""
    
    /// Run script at given URL.
    ///
    /// - Parameters:
    ///     - url: URL of the Python script to run.
    @objc func runScript(at url: URL) {
        queue.async {
            
            guard !self.isREPLRunning else {
                PyOutputHelper.print("An instance of the REPL is already running and two scripts cannot run at the same time, to kill it, quit the app.") // Should not be called. When the REPL is running, run the script inside it.
                return
            }
            
            guard let startupURL = Bundle.main.url(forResource: "Startup", withExtension: "py"), let src = try? String(contentsOf: startupURL) as NSString else {
                PyOutputHelper.print("Error loading Startup.py")
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
