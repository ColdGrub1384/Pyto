//
//  PyOutputHelper.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/9/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit

/// A class accessible by Rubicon to print without writting to the stdout.
@objc class PyOutputHelper: NSObject {
    
    /// Appends text to all `ConsoleViewController`s instances. Sends `"DidReceiveOutput"` notification with given parameter.
    ///
    /// - Parameters:
    ///     - text: Text to print.
    @objc static func print(_ text: String) {
        var text_ = text
        
        #if MAIN
        text_ = text_.replacingOccurrences(of: DocumentBrowserViewController.localContainerURL.path, with: "Documents")
        if let iCloudDrive = DocumentBrowserViewController.iCloudContainerURL?.path {
            text_ = text_.replacingOccurrences(of: iCloudDrive, with: "iCloud")
        }
        
        text_ = text_.replacingOccurrences(of: Bundle.main.bundlePath, with: "Pyto.app")
        #endif
        
        Python.shared.output += text_
        NotificationCenter.default.post(name: .init("DidReceiveOutput"), object: text_)
    }
    
    /// Shows error on visible console.
    ///
    /// - Parameters:
    ///     - text: Text to print.
    @objc static func printError(_ text: String) {
        var text_ = text
        
        #if MAIN
        text_ = text_.replacingOccurrences(of: DocumentBrowserViewController.localContainerURL.path, with: "Documents")
        if let iCloudDrive = DocumentBrowserViewController.iCloudContainerURL?.path {
            text_ = text_.replacingOccurrences(of: iCloudDrive, with: "iCloud")
        }
        text_ = text_.replacingOccurrences(of: Bundle.main.bundlePath, with: "Pyto.app")
        #endif
        
        Python.shared.output += text_
        
        DispatchQueue.main.async {
            if let attrStr = ConsoleViewController.visible.textView.attributedText {
                let mutable = NSMutableAttributedString(attributedString: attrStr)
                mutable.append(NSAttributedString(string: text_, attributes: [.font : UIFont(name: "Menlo", size: 13) ?? UIFont.systemFont(ofSize: 12), .foregroundColor : #colorLiteral(red: 0.6743632277, green: 0.1917540668, blue: 0.1914597603, alpha: 1)]))
                ConsoleViewController.visible.textView.attributedText = mutable
            }
        }
    }
}
