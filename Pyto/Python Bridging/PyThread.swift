//
//  PyThread.swift
//  Pyto
//
//  Created by Adrian Labbe on 11/24/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import Foundation

/// A class representing the script's thread for the Python API.
@objc class PyThread: NSObject {
    
    /// Execute the given code async on the Python thread.
    @objc static func runAsync(_ code: @escaping (() -> Void)) {
        Python.shared.queue.async {
            code()
        }
    }
    
    /// Execute the given code sync on the Python thread.
    @objc static func runSync(_ code: @escaping (() -> Void)) {
        Python.shared.queue.sync {
            code()
        }
    }
}

