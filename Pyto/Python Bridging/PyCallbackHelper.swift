//
//  PyCallbackHelper.swift
//  Pyto
//
//  Created by Adrian Labbé on 10-01-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import Foundation

/// A class for receiving input from other apps via x-callback urls.
@objc class PyCallbackHelper: NSObject {
    
    /// The result URL sent by an app Pyto opened.
    @objc static var url: String?
    
    /// The URL to open when a script finished running. Passes output to`result` parameter.
    static var successURL: String?
    
    /// The URL to open when there is an exception. Passes the exception message to `errorMessage` parameter.
    static var errorURL: String?
    
    /// The URL to open when a script is closed.
    static var cancelURL: String?
    
    /// The code executed via x-callback URL.
    static var code: String?
    
    /// A boolean indicating whether the code ran from x-callback URL was exited.
    @objc static var cancelled = false
    
    /// The exception raised by the code ran from x-callback URL.
    @objc static var exception: String?
}
