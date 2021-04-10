//
//  PyWrapper.swift
//  Pyto
//
//  Created by Adrian Labbé on 28-06-19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import Foundation

/// A class for wrapping an UIKit object.
@available(iOS 13.0, *) @objc public class PyWrapper: NSObject {
    
    /// The managed object.
    @objc public var managed: NSObject!
    
    public override init() {}
    
    /// Initializes with the given object.
    ///
    /// - Parameters:
    ///     - managed: The wrapped object.
    @objc public init(managed: NSObject! = NSObject()) {
        super.init()
        
        self.managed = managed
    }
    
    /// Gets an object in the main thread.
    ///
    /// - Parameters:
    ///     - code: Code to execute in the main thread. Returns the object to be returned by the function.
    ///
    /// - Returns: The object returned by `code`.
    func get <T: Any>(code: @escaping () -> T) -> T {
        return PyWrapper.get(code: code)
    }
    
    /// Runs code on the main thread. Should be used for setting values.
    ///
    /// - Parameters:
    ///     - code: Code to execute.
    func set(code: @escaping () -> Void) {
        return PyWrapper.set(code: code)
    }
    
    /// Gets an object in the main thread.
    ///
    /// - Parameters:
    ///     - code: Code to execute in the main thread. Returns the object to be returned by the function.
    ///
    /// - Returns: The object returned by `code`.
    class func get <T: Any>(code: @escaping () -> T) -> T {
        
        let semaphore = DispatchSemaphore(value: 0)
        
        var value: T!
        
        if !Thread.current.isMainThread {
            DispatchQueue.main.async {
                value = code()
                semaphore.signal()
            }
        } else {
            value = code()
        }
        
        if !Thread.current.isMainThread {
            semaphore.wait()
        }
        
        return value
    }
    
    /// Runs code on the main thread. Should be used for setting values.
    ///
    /// - Parameters:
    ///     - code: Code to execute.
    class func set(code: @escaping () -> Void) {
        
        let semaphore = DispatchSemaphore(value: 0)
        
        if !Thread.current.isMainThread {
            DispatchQueue.main.async {
                code()
                semaphore.signal()
            }
        } else {
            code()
        }
        
        if !Thread.current.isMainThread {
            semaphore.wait()
        }
    }
    
}
