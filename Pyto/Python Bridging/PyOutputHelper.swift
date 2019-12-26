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
    
    #if !WIDGET
    private static var outputParser: Parser!
    #endif
    
    private var script: String?
        
    private static var semaphore: DispatchSemaphore?
    
    private static let queue = DispatchQueue.global(qos: .userInteractive)
    
    /// Shows output on visible console.
    /// - Parameters:
    ///     - text: Text to print.
    ///     - script: Script that printed the output. Set to `nil` to be printed in every console.
    @objc static func print(_ text: String, script: String?) {
        var text_ = text
        
        guard !text_.isEmpty else {
            return
        }
        
        #if MAIN
        text_ = ShortenFilePaths(in: text_)
        #endif
        
        Python.shared.output += text_
        
        #if WIDGET
        let console = ConsoleViewController.visible ?? ConsoleViewController()
        
        DispatchQueue.main.async {
            if let attrStr = console.textView.attributedText {
                let mutable = NSMutableAttributedString(attributedString: attrStr)
                
                let font = UIFont(name: "Menlo", size: 12) ?? UIFont.systemFont(ofSize: 12)
                
                var attributes: [NSAttributedString.Key : AnyHashable] = [.font : font]
                if #available(iOS 13.0, *) {
                    attributes[.foregroundColor] = UIColor.label
                }
                mutable.append(NSAttributedString(string: text_, attributes: attributes))
                console.textView.attributedText = mutable
                console.textView.scrollToBottom()
            }
        }
        #else
        queue.sync {
            outputParser = Parser()
            let delegate = PyOutputHelper()
            delegate.script = script
            outputParser.delegate = delegate
            PyOutputHelper.semaphore = DispatchSemaphore(value: 0)
            outputParser.parse(text_.data(using: .utf8) ?? Data())
            PyOutputHelper.semaphore?.wait()
        }
        #endif
    }
    
    /// Shows error on visible console.
    ///
    /// - Parameters:
    ///     - text: Text to print.
    ///     - script: Script that printed the output. Set to `nil` to be printed in every console.
    @objc static func printError(_ text: String, script: String?) {
        
        var text_ = text
        
        guard !text_.isEmpty else {
            return
        }
        
        #if MAIN
        text_ = ShortenFilePaths(in: text_)
        #endif
        
        Python.shared.output += text_
        
        #if WIDGET
        let visibles = [ConsoleViewController.visible ?? ConsoleViewController()]
        #else
        let visibles = ConsoleViewController.visibles
        #endif
        
        for console in visibles {
            #if !WIDGET && MAIN
            if script != nil {
                guard console.editorSplitViewController?.editor.document?.fileURL.path == script else {
                    continue
                }
            }
            #endif
            
            #if MAIN
            let font = EditorViewController.font.withSize(CGFloat(ThemeFontSize))
            let color = ConsoleViewController.choosenTheme.exceptionColor
            #else
            let font = UIFont(name: "Menlo", size: 12) ?? UIFont.systemFont(ofSize: 12)
            let color = #colorLiteral(red: 0.6745098039, green: 0.1921568627, blue: 0.1921568627, alpha: 1)
            #endif
            
            DispatchQueue.main.async {
                if let attrStr = console.textView.attributedText {
                    let mutable = NSMutableAttributedString(attributedString: attrStr)
                    mutable.append(NSAttributedString(string: text_, attributes: [.font : font, .foregroundColor : color]))
                    console.textView.attributedText = mutable
                    console.textView.scrollToBottom()
                }
            }
        }
    }
    
    /// Shows warning on visible console.
    ///
    /// - Parameters:
    ///     - text: Text to print.
    ///     - script: Script that printed the output. Set to `nil` to be printed in every console.
    @objc static func printWarning(_ text: String, script: String?) {
        var text_ = text
        
        #if MAIN
        text_ = ShortenFilePaths(in: text_)
        #endif
        
        Python.shared.output += text_
        
        #if WIDGET
        let visibles = [ConsoleViewController.visible ?? ConsoleViewController()]
        #else
        let visibles = ConsoleViewController.visibles
        #endif
        
        for console in visibles {
            
            #if !WIDGET && MAIN
            if script != nil {
                guard console.editorSplitViewController?.editor.document?.fileURL.path == script else {
                    continue
                }
            }
            #endif
            
            DispatchQueue.main.async {
                
                #if MAIN
                let font = EditorViewController.font.withSize(CGFloat(ThemeFontSize))
                let color = ConsoleViewController.choosenTheme.warningColor
                #else
                let font = UIFont(name: "Menlo", size: 12) ?? UIFont.systemFont(ofSize: 12)
                let color = #colorLiteral(red: 0.7254902124, green: 0.4784313738, blue: 0.09803921729, alpha: 1)
                #endif
                
                if let attrStr = console.textView.attributedText {
                    let mutable = NSMutableAttributedString(attributedString: attrStr)
                    mutable.append(NSAttributedString(string: text_, attributes: [.font : font, .foregroundColor : color]))
                    console.textView.attributedText = mutable
                    console.textView.scrollToBottom()
                }
            }
        }
    }
}

#if !WIDGET
extension PyOutputHelper: ParserDelegate {
    
    func parser(_ parser: Parser, didReceiveString string: NSAttributedString) {
        
        #if WIDGET
        let visibles = [ConsoleViewController.visible ?? ConsoleViewController()]
        #else
        let visibles = ConsoleViewController.visibles
        #endif
        
        for console in visibles {
            
            #if !WIDGET && MAIN
            if script != nil {
                guard console.editorSplitViewController?.editor.document?.fileURL.path == script else {
                    continue
                }
            }
            #endif
            
            DispatchQueue.main.async {
                if let attrStr = console.textView.attributedText {
                    let mutable = NSMutableAttributedString(attributedString: attrStr)
                    
                    /*#if MAIN
                    let font = EditorViewController.font.withSize(CGFloat(ThemeFontSize))
                    #else
                    let font = UIFont(name: "Menlo", size: 12) ?? UIFont.systemFont(ofSize: 12)
                    #endif
                    
                    var attributes: [NSAttributedString.Key : AnyHashable] = [.font : font]
                    #if MAIN
                    attributes[.foregroundColor] = ConsoleViewController.choosenTheme.sourceCodeTheme.color(for: .plain)
                    #else
                    if #available(iOS 13.0, *) {
                        attributes[.foregroundColor] = UIColor.label
                    }
                    #endif*/
                    mutable.append(string)
                    console.textView.attributedText = mutable
                    console.textView.scrollToBottom()
                    
                    PyOutputHelper.semaphore?.signal()
                    PyOutputHelper.semaphore = nil
                }
            }
        }
    }

    func parserDidEndTransmission(_ parser: Parser) {}
}
#endif
