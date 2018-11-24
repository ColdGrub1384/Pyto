//
//  PyMainThread.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/15/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import Foundation

/// A class representing the main thread for the Python API.
@objc class PyMainThread: NSObject {
    
    /// Execute the given code async on the main thread.
    @objc static func runAsync(_ code: @escaping (() -> Void)) {
        DispatchQueue.main.async {
            code()
        }
    }
    
    /// Execute the given code sync on the main thread.
    @objc static func runSync(_ code: @escaping (() -> Void)) {
        DispatchQueue.main.sync {
            code()
        }
    }
}
