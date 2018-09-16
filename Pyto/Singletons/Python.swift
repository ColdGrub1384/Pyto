
//
//  Python.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/8/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit

/// A class for interacting with `Cpython`
class Python {
    
    /// The shared and unique instance
    static let shared = Python()
    
    private init() {}
    
    /// The queue running scripts.
    let queue = DispatchQueue.global()
    
    /// Run script at given URL. The only argument passed will be the file path.
    ///
    /// - Parameters:
    ///     - url: URL of the Python script to run.
    func runScript(at url: URL) {
        
        freopen(pythonStderrPath.cValue, "a+", stderr)
        
        queue.async {
            let file = fopen(url.path.cValue, "r")
            PyRun_AnyFileFlags(file, url.path.cValue, nil)
        }
    }
}
