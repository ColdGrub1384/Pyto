//
//  PyOutputHelper.swift
//  Pyto
//
//  Created by Emma Labbé on 9/9/18.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit
#if MAIN
import WatchConnectivity
import Dynamic
#if !Xcode11
import WidgetKit
#endif
#endif

#if WIDGET && !Xcode11
#else
fileprivate extension ConsoleViewController {
    
    struct Holder {
        
        static var values = [ConsoleViewController:NSAttributedString]()
        
        static var scrollingConsoles = [ConsoleViewController]()
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
    @objc static var output = "" {
        didSet {
            
            guard !output.isEmpty else {
                return
            }
            
            //try? output.write(toFile: FileManager.default.sharedDirectory?.appendingPathComponent("UIIntentsOutput").path ?? "", atomically: false, encoding: .utf8)
        }
    }
    
    #if !WIDGET
    /// Sends `output` to the current running Shortcut or Automator action.
    ///
    /// - Parameters:
    ///     - errorMessage: If an exception was thrown, pass the traceback.
    @objc static func sendOutputToShortcuts(_ errorMessage: String?) {
        
        // Remove ASCII color codes or whatever it's called
        let regex = try! NSRegularExpression(pattern: "\u{001B}\\[[;\\d]*m", options: NSRegularExpression.Options.caseInsensitive)
        let range = NSMakeRange(0, output.count)
        output = regex.stringByReplacingMatches(in: output, options: [], range: range, withTemplate: "")
        
        #if MAIN
        if isiOSAppOnMac {
            let notificationCenter = CFNotificationCenterGetDarwinNotifyCenter()
            let notificationName = CFNotificationName("pyto.receivedOutput" as CFString)
            
            let pb = Dynamic.NSPasteboard.pasteboardWithName("Pyto.Automator")
            pb.clearContents()
            pb.setString(output, forType: "public.utf8-plain-text")
            
            CFNotificationCenterPostNotification(notificationCenter, notificationName, nil, nil, true)
        }
        #endif
        
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
    
    private static let queue = DispatchQueue.main
    
    #if WIDGET && !Xcode11
    #else
    /// Shows output on visible console.
    /// - Parameters:
    ///     - text: Text to print.
    ///     - script: Script that printed the output. Set to `nil` to be printed in every console.
    @objc static func print(_ text: String, script: String?) {
        
        if Thread.current.isMainThread {
            return DispatchQueue.global().async {
                print(text, script: script)
            }
        }
        
        var text_ = text
        
        guard !text_.isEmpty else {
            return
        }
        
        Swift.print(text_, terminator: "")
        
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
            
            console.print(text_)
            
        }
        #endif
    }
    
    /// Shows error on visible console.
    ///
    /// - Parameters:
    ///     - text: Text to print.
    ///     - script: Script that printed the output. Set to `nil` to be printed in every console.
    @objc static func printError(_ text: String, script: String?) {
        print("\u{001B}[0;31m\(text)\u{001B}[0;0m", script: script)
    }
    
    /// Shows warning on visible console.
    ///
    /// - Parameters:
    ///     - text: Text to print.
    ///     - script: Script that printed the output. Set to `nil` to be printed in every console.
    @objc static func printWarning(_ text: String, script: String?) {
        print("\u{001B}[0;33m\(text)\u{001B}[0;0m", script: script)
    }
    
    /// Shows value from the REPL in the console.
    ///
    /// - Parameters:
    ///     - text: Text to print.
    ///     - value: JSON describing the value.
    ///     - script: Script that printed the output. Set to `nil` to be printed in every console.
    @objc static func printValue(_ text: String, value: String, script: String?) {
        
        let url = "pyto://inspector/\(text.addingPercentEncoding(withAllowedCharacters: .urlPathAllowed) ?? "")/?\(value.addingPercentEncoding(withAllowedCharacters: .urlQueryAllowed) ?? "")"
        printLink(text, url: url, script: script)
    }
    
    /// Shows link
    ///
    /// - Parameters:
    ///     - text: Text to print.
    ///     - url: URL to open.
    ///     - script: Script that printed the output. Set to `nil` to be printed in every console.
    @objc static func printLink(_ text: String, url: String, script: String?) {
                
        #if !WIDGET
        let visibles = ConsoleViewController.visibles
        
        for console in visibles {
            
            #if MAIN
            if script != nil {
                guard console.editorSplitViewController?.editor?.document?.fileURL.path == script else {
                    continue
                }
            }
            #endif
            
            console.printLink(text: ShortenFilePaths(in: text), link: url)
            
        }
        #endif
    }
    #endif
}
