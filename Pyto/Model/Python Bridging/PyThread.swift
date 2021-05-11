//
//  PyThread.swift
//  Pyto
//
//  Created by Emma Labbé on 11/24/18.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import Foundation

/// A class representing the script's thread for the Python API.
@objc class PyThread: NSObject {
    
    /// Execute the given code async on the Python thread.
    @objc static func runAsync(_ code: @escaping (() -> Void)) {
        let code_ = code
        Python.shared.queue.async(execute: code_)
    }
    
    /// Execute the given code sync on the Python thread.
    @objc static func runSync(_ code: @escaping (() -> Void)) {
        let code_ = code
        Python.shared.queue.sync(execute: code_)
    }
}

