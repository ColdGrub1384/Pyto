//
//  PyOutputHelper.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/9/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit
#if MAIN
import WatchConnectivity
#if !Xcode11
import WidgetKit
#endif
#endif

#if WIDGET && !Xcode11
#else
fileprivate extension ConsoleViewController {
    
    struct Holder {
        
        static var values = [ConsoleViewController:NSAttributedString]()
    }
    
    var attributedConsole: NSAttributedString? {
        get {
            return Holder.values[self]
        }
        
        set {
            Holder.values[self] = newValue
        }
    }
}
#endif

/// A class accessible by Rubicon to print without writting to the stdout.
@objc class PyOutputHelper: NSObject {
        
    /// All output from the last executed Shortcut.
    @objc static var output = ""
    
    #if !WIDGET
    /// Sends `output` to the current running Shortcut.
    ///
    /// - Parameters:
    ///     - errorMessage: If an exception was thrown, pass the traceback.
    @objc static func sendOutputToShortcuts(_ errorMessage: String?) {
        guard let group = FileManager.default.containerURL(forSecurityApplicationGroupIdentifier: "group.pyto") else {
            return
        }
                
        do {
            let encodedImages = try NSKeyedArchiver.archivedData(withRootObject: QuickLookHelper.images, requiringSecureCoding: true)
            try encodedImages.write(to: group.appendingPathComponent("ShortcutPlots"))
        } catch {
            Swift.print(error.localizedDescription)
        }
        
        if let error = errorMessage {
            output = error
        }
        
        if output.hasSuffix("\n") {
            output.removeLast()
        }
        
        do {
            try ("\(errorMessage != nil ? "Fail" : "Success")\n"+output).write(to: group.appendingPathComponent("ShortcutOutput.txt"), atomically: true, encoding: .utf8)
        } catch {
            Swift.print(error.localizedDescription)
        }
        
        QuickLookHelper.images = []
        output = ""
    }
    #endif
    
    #if !WIDGET
    private static var outputParser: Parser!
    #endif
    
    private var script: String?
        
    private static var semaphore: DispatchSemaphore?
    
    private static let queue = DispatchQueue.global(qos: .userInteractive)
    
    #if WIDGET && !Xcode11
    #else
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
        
        output += text_
        
        if script == Python.watchScriptURL.path {
            WCSession.default.sendMessageData(text_.data(using: .utf8) ?? Data(), replyHandler: nil, errorHandler: nil)
            return
        }
        #endif
        
        if text_.hasPrefix("\r") {
            DispatchQueue.main.async {
                #if WIDGET
                let visibles = [ConsoleViewController.visible ?? ConsoleViewController()]
                #else
                let visibles = ConsoleViewController.visibles
                #endif
                
                for console in visibles {
                    #if !WIDGET && MAIN
                    if script != nil {
                        guard console.editorSplitViewController?.editor?.document?.fileURL.path == script else {
                            continue
                        }
                    }
                    #endif
                    
                    if console.textView.text.hasSuffix("\n") {
                        text_ = text_.components(separatedBy: "\r").last ?? text_
                        continue
                    }
                    
                    text_ = "\r\(text_.components(separatedBy: "\r").last ?? text_)"
                    
                    let attrString = NSMutableAttributedString(attributedString: console.textView.attributedText)
                    
                    let range = (console.textView.text as NSString).lineRange(for: NSRange(location: (console.textView.text as NSString).length-1, length: 1))
                    
                    let offset: Int
                    if console.textView.text.contains("\n") || console.textView.text.contains("\r") {
                        offset = 1
                    } else {
                        offset = 0
                    }
                    
                    attrString.replaceCharacters(in: NSRange(location: range.location-offset, length: range.length+offset), with: NSAttributedString(string: ""))
                    
                    console.textView.attributedText = attrString
                    
                    console.textView.scrollToBottom()
                }
            }
        } else if text_.contains("\r") {
            text_ = text_.components(separatedBy: "\r").last ?? text_
        }
        
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
        let visibles = ConsoleViewController.visibles
        
        for console in visibles {
            
            #if MAIN
            if script != nil {
                guard console.editorSplitViewController?.editor?.document?.fileURL.path == script else {
                    continue
                }
            }
            #endif
            
            DispatchQueue.main.async {
                
                console.attributedConsole = console.textView.attributedText
                
                #if MAIN
                let font = EditorViewController.font.withSize(CGFloat(ThemeFontSize))
                let color = ConsoleViewController.choosenTheme.sourceCodeTheme.color(for: .plain)
                #else
                let font = UIFont(name: "Menlo", size: 12) ?? UIFont.systemFont(ofSize: 12)
                let color: UIColor
                if #available(iOS 13.0, *) {
                    color = UIColor.label
                } else {
                    color = .black
                }
                #endif
                
                if let attrStr = console.textView.attributedText {
                    let mutable = NSMutableAttributedString(attributedString: attrStr)
                    mutable.append(NSAttributedString(string: text_, attributes: [.font : font, .foregroundColor : color]))
                    console.textView.attributedText = mutable
                    console.textView.scrollToBottom()
                }
            }
        }
        
        queue.sync {
            outputParser = Parser()
            let delegate = PyOutputHelper()
            delegate.script = script
            outputParser.delegate = delegate
            PyOutputHelper.semaphore = DispatchSemaphore(value: 0)
            outputParser.parse(text_.data(using: .utf8) ?? Data())
            if script != nil {
                PyOutputHelper.semaphore?.wait()
            }
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
        
        Swift.print(text_)
        
        output += text_
        
        if script == Python.watchScriptURL.path {
            WCSession.default.sendMessageData(text_.data(using: .utf8) ?? Data(), replyHandler: nil, errorHandler: nil)
            return
        }
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
                guard console.editorSplitViewController?.editor?.document?.fileURL.path == script else {
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
        
        output += text_
        
        if script == Python.watchScriptURL.path {
            WCSession.default.sendMessageData(text_.data(using: .utf8) ?? Data(), replyHandler: nil, errorHandler: nil)
            return
        }
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
                guard console.editorSplitViewController?.editor?.document?.fileURL.path == script else {
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
    
    /// Shows value from the REPL in the console.
    ///
    /// - Parameters:
    ///     - text: Text to print.
    ///     - value: JSON describing the value.
    ///     - script: Script that printed the output. Set to `nil` to be printed in every console.
    @objc static func printValue(_ text: String, value: String, script: String?) {
        
        var text_ = text
        
        guard !text_.isEmpty else {
            return
        }
        
        #if MAIN
        text_ = ShortenFilePaths(in: text_)
        
        output += text_
        
        if script == Python.watchScriptURL.path {
            WCSession.default.sendMessageData(text_.data(using: .utf8) ?? Data(), replyHandler: nil, errorHandler: nil)
            return
        }
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
                guard console.editorSplitViewController?.editor?.document?.fileURL.path == script else {
                    continue
                }
            }
            #endif
            
            let url = "pyto://inspector/\(text.addingPercentEncoding(withAllowedCharacters: .urlPathAllowed) ?? "")/?\(value.addingPercentEncoding(withAllowedCharacters: .urlQueryAllowed) ?? "")"
            
            NSLog("%@", url)
            NSLog("%@", value)
            
            DispatchQueue.main.async {
                
                #if MAIN
                let font = EditorViewController.font.withSize(CGFloat(ThemeFontSize))
                let color = ConsoleViewController.choosenTheme.sourceCodeTheme.color(for: .identifier)
                #else
                let font = UIFont(name: "Menlo", size: 12) ?? UIFont.systemFont(ofSize: 12)
                let color = #colorLiteral(red: 0.1960784346, green: 0.3411764801, blue: 0.1019607857, alpha: 1)
                #endif
                
                if let attrStr = console.textView.attributedText {
                    let mutable = NSMutableAttributedString(attributedString: attrStr)
                    mutable.append(NSAttributedString(string: text_, attributes: [.font : font, .foregroundColor : color, .link : url, .underlineStyle: NSUnderlineStyle.single.rawValue]))
                    console.textView.attributedText = mutable
                    console.textView.scrollToBottom()
                }
            }
        }
    }
    
    /// Shows link
    ///
    /// - Parameters:
    ///     - text: Text to print.
    ///     - url: URL to open.
    ///     - script: Script that printed the output. Set to `nil` to be printed in every console.
    @objc static func printLink(_ text: String, url: String, script: String?) {
        
        var text_ = text
        
        guard !text_.isEmpty else {
            return
        }
        
        #if MAIN
        text_ = ShortenFilePaths(in: text_)
        
        output += text_
        
        if script == Python.watchScriptURL.path {
            WCSession.default.sendMessageData(text_.data(using: .utf8) ?? Data(), replyHandler: nil, errorHandler: nil)
            return
        }
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
                guard console.editorSplitViewController?.editor?.document?.fileURL.path == script else {
                    continue
                }
            }
            #endif
            
            DispatchQueue.main.async {
                
                #if MAIN
                let font = EditorViewController.font.withSize(CGFloat(ThemeFontSize))
                let color = ConsoleViewController.choosenTheme.sourceCodeTheme.color(for: .identifier)
                #else
                let font = UIFont(name: "Menlo", size: 12) ?? UIFont.systemFont(ofSize: 12)
                let color = #colorLiteral(red: 0.1960784346, green: 0.3411764801, blue: 0.1019607857, alpha: 1)
                #endif
                
                if let attrStr = console.textView.attributedText {
                    let mutable = NSMutableAttributedString(attributedString: attrStr)
                    mutable.append(NSAttributedString(string: text_, attributes: [.font : font, .foregroundColor : color, .link : url, .underlineStyle: NSUnderlineStyle.single.rawValue]))
                    console.textView.attributedText = mutable
                    console.textView.scrollToBottom()
                }
            }
        }
    }
    #endif
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
                guard console.editorSplitViewController?.editor?.document?.fileURL.path == script else {
                    continue
                }
            }
            #endif
            
            DispatchQueue.main.async {
                if let attrStr = console.attributedConsole {
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
                    
                    DispatchQueue.main.asyncAfter(deadline: .now()+0.5) {
                        console.textView.scrollToBottom()
                    }
                    
                    PyOutputHelper.semaphore?.signal()
                    PyOutputHelper.semaphore = nil
                }
            }
        }
    }

    func parserDidEndTransmission(_ parser: Parser) {}
}
#endif
