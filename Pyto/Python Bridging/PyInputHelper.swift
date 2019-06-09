//
//  PyInputHelper.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/9/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import Foundation

/// A helperaccessible by Rubicon to request user's input.
@objc class PyInputHelper: NSObject {
    
    /// The user's input. Set its value while Python script is waiting for input to pass the input.
    @objc static var userInput: String?
    
    /// Requests for input.
    ///
    /// - Parameters:
    ///     - prompt: The prompt sent by Python function.
    @objc static func showAlert(prompt: String?) {
        let prompt_ = prompt
        DispatchQueue.main.sync {
            #if !WIDGET
            for console in ConsoleViewController.visibles {
                console.input(prompt: prompt_ ?? "")
            }
            #endif
        }
    }
    
    /// Requests for a password.
    ///
    /// - Parameters:
    ///     - prompt: The prompt sent by Python function.
    @objc static func getPass(prompt: String?) {
        let prompt_ = prompt
        DispatchQueue.main.sync {
            #if !WIDGET
            for console in ConsoleViewController.visibles {
                console.getpass(prompt: prompt_ ?? "")
            }
            #endif
        }
    }
}
