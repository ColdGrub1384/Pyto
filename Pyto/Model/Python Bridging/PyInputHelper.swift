//
//  PyInputHelper.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/9/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import Foundation
#if MAIN
import WatchConnectivity
#endif

/// A helper accessible by Rubicon to request user's input.
@objc class PyInputHelper: NSObject {
    
    /// The user's input. Set its value while Python script is waiting for input to pass the input.
    static var userInput = [String:String]() {
        didSet {
            for key in userInput.keys {
                semaphores[key]?.signal()
                semaphores[key] = nil
            }
        }
    }
    
    /// Semaphores waiting for user input.
    static var semaphores = [String:DispatchSemaphore]()
    
    /// Waits for user input with the given script path.
    ///
    /// - Returns: The input result.
    @objc static func waitForInput(_ path: String) -> String? {
        userInput[path] = nil
        let semaphore = DispatchSemaphore(value: 0)
        semaphores[path] = semaphore
        semaphore.wait()
        let input = getUserInput(path)
        userInput[path] = nil
        return input
    }
    
    /// Returns user input for script at given path.
    ///
    /// - Parameters:
    ///     - path: The path of the script that is asking for input or an empty string.
    ///
    /// - Returns: The input entered by the user.
    @objc static func getUserInput(_ path: String) -> String? {
        return userInput[path] ?? userInput[URL(fileURLWithPath: path).resolvingSymlinksInPath().path]
    }
    
    /// Requests for input.
    ///
    /// - Parameters:
    ///     - prompt: The prompt sent by Python function.
    ///     - script: The script that asked for input. Set to `nil` to request input on every console.
    ///     - highlight: A boolean idicating whether the line should be syntax colored.
    @objc static func showAlert(prompt: String?, script: String?, highlight: Bool) {
        let prompt_ = prompt
        DispatchQueue.main.sync {
            
            #if MAIN
            if script == Python.watchScriptURL.path {
                WCSession.default.sendMessage(["prompt": prompt_ ?? "", "suggestions": WatchInputSuggestionsTableViewController.suggestions], replyHandler: { (res) in
                    self.userInput[script!] = res["input"] as? String
                }, errorHandler: { (_) in
                    self.userInput[script!] = ""
                })
            }
            #endif
            
            #if !WIDGET && !MAIN
            ConsoleViewController.visibles.first?.input(prompt: prompt_ ?? "", highlight: false)
            #elseif !WIDGET
            
            for console in ConsoleViewController.visibles {
                if script != nil {
                    let splitVC = console.editorSplitViewController
                    guard let url = splitVC?.editor?.document?.fileURL, url.resolvingSymlinksInPath() == URL(fileURLWithPath: script!).resolvingSymlinksInPath() else {
                        continue
                    }
                }
                
                console.input(prompt: prompt_ ?? "", highlight:highlight)
            }
            #endif
        }
    }
    
    /// Requests for a password.
    ///
    /// - Parameters:
    ///     - prompt: The prompt sent by Python function.
    ///     - script: The script that asked for input. Set to `nil` to request input on every console.
    @objc static func getPass(prompt: String?, script: String?) {
        let prompt_ = prompt
        DispatchQueue.main.sync {
            #if !WIDGET && !MAIN
            ConsoleViewController.visibles.first?.getpass(prompt: prompt_ ?? "")
            #elseif !WIDGET
            for console in ConsoleViewController.visibles {
                
                if script != nil {
                    guard console.editorSplitViewController?.editor?.document?.fileURL.path == script else {
                        continue
                    }
                }
                
                console.getpass(prompt: prompt_ ?? "")
            }
            #endif
        }
    }
}
