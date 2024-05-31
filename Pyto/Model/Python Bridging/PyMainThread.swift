//
//  PyMainThread.swift
//  Pyto
//
//  Created by Emma Labbé on 2/7/19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import Foundation

@objc class PyMainThread: NSObject {
    
    @objc static func runAsync(_ code: @escaping (() -> Void)) {
        let code_ = code
        DispatchQueue.main.async {
            code_()
        }
    }
    
    @objc static func runSync(_ code: @escaping (() -> Void)) {
        if !Thread.isMainThread {
            let code_ = code
            let semaphore = Python.Semaphore(value: 0)
            DispatchQueue.main.async {
                code_()
                semaphore.signal()
            }
            semaphore.wait()
        } else {
            code()
        }
    }
}
