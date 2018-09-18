//
//  PyOutputHelper.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/9/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import Foundation

/// A class accessible by Rubicon to print without writting to the stdout.
@objc class PyOutputHelper: NSObject {
    
    /// Appends text to all `ConsoleViewController`s instances. Sends `"DidReceiveOutput"` notification with given parameter.
    ///
    /// - Parameters:
    ///     - text: Text to print.
    @objc static func print(_ text: String) {
        NotificationCenter.default.post(name: .init("DidReceiveOutput"), object: text)
    }
}
