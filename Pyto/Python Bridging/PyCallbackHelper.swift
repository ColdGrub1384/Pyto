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
}
