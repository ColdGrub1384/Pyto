//
//  PyMainThread.swift
//  Pyto
//
//  Created by Adrian Labbé on 2/7/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import Foundation

@objc class PyMainThread: NSObject {
    
    @objc static func runAsync(_ code: @escaping (() -> Void)) {
        let code_ = code
        DispatchQueue.main.async {
            print("Will run code")
            code_()
            print("Ran")
        }
    }
    
    @objc static func runSync(_ code: @escaping (() -> Void)) {
        let code_ = code
        DispatchQueue.main.sync {
            print("Will run code")
            code_()
            print("Ran")
        }
    }
}
