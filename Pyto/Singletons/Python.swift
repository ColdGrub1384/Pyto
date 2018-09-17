
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
    
    private var output = ""
    private override init() {}
    
    /// The queue running scripts.
    @objc let queue = DispatchQueue.global()
    
    /// The version catched passed from `"sys.version"`.
    @objc public var version = ""
    
    /// Run script at given URL.
    ///
    /// - Parameters:
    ///     - url: URL of the Python script to run.
    @objc func runScript(at url: URL) {
        queue.async {
            PyRun_SimpleStringFlags("""
                import pyto as __Pyto__
                from importlib.machinery import SourceFileLoader
                
                __builtins__.input = __Pyto__.input
                __builtins__.print = __Pyto__.print
                
                try:
                    SourceFileLoader("main", "\(url.path)").load_module()
                except Exception as e:
                    print(e)
                """, nil)
        }
    }
}
