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
    
    /// Shows output on visible console.
    /// - Parameters:
    ///     - text: Text to print.
    @objc static func print(_ text: String) {
        var text_ = text
        
        #if MAIN
        text_ = text_.replacingOccurrences(of: URL(fileURLWithPath: "/private").appendingPathComponent(DocumentBrowserViewController.localContainerURL.path).path, with: "Documents")
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
                var attributes: [NSAttributedString.Key : AnyHashable] = [.font : UIFont(name: "Menlo", size: 13) ?? UIFont.systemFont(ofSize: 12)]
                #if MAIN
                attributes[.foregroundColor] = ConsoleViewController.choosenTheme.sourceCodeTheme.color(for: .plain)
                #endif
                mutable.append(NSAttributedString(string: text_, attributes: attributes))
                ConsoleViewController.visible.textView.attributedText = mutable
                ConsoleViewController.visible.textView.scrollToBottom()
            }
        }
    }
    
    /// Shows error on visible console.
    ///
    /// - Parameters:
    ///     - text: Text to print.
    @objc static func printError(_ text: String) {
        var text_ = text
        
        #if MAIN
        text_ = text_.replacingOccurrences(of: URL(fileURLWithPath: "/private").appendingPathComponent(DocumentBrowserViewController.localContainerURL.path).path, with: "Documents")
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
                ConsoleViewController.visible.textView.scrollToBottom()
            }
        }
    }
    
    /// Shows warning on visible console.
    ///
    /// - Parameters:
    ///     - text: Text to print.
    @objc static func printWarning(_ text: String) {
        var text_ = text
        
        #if MAIN
        text_ = text_.replacingOccurrences(of: URL(fileURLWithPath: "/private").appendingPathComponent(DocumentBrowserViewController.localContainerURL.path).path, with: "Documents")
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
                mutable.append(NSAttributedString(string: text_, attributes: [.font : UIFont(name: "Menlo", size: 13) ?? UIFont.systemFont(ofSize: 12), .foregroundColor : #colorLiteral(red: 0.7254902124, green: 0.4784313738, blue: 0.09803921729, alpha: 1)]))
                ConsoleViewController.visible.textView.attributedText = mutable
                ConsoleViewController.visible.textView.scrollToBottom()
            }
        }
    }
}
