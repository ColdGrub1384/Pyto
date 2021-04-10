//
//  PyAlert.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/15/18.
//  Copyright © 2018 Emma Labbé. All rights reserved.
//

import UIKit

/// A class representing an alert to be used from the Python API.
@objc class PyAlert: NSObject {
    
    /// The alert's title.
    @objc var title: String?
    
    /// The alert's message.
    @objc var message: String?
    
    private var response: String?
    
    /// The alert's actions.
    var actions: [UIAlertAction]?
    
    /// Initialize a new alert.
    ///
    /// - Parameters:
    ///     - title: The alert's title.
    ///     - message: The alert's message.
    @objc static func alertWithTitle(_ title: String?, message: String?) -> PyAlert {
        let self_ = PyAlert()
        
        self_.title = title
        self_.message = message
        
        return self_
    }
    
    /// Show an alert with set parameters.
    ///
    /// - Parameters:
    ///     - scriptPath: The path of the script that is showing the alert.
    ///
    /// - Returns: The title of the pressed action.
    @objc func _show(_ scriptPath: String?) -> String {
        response = nil
        DispatchQueue.main.async { [weak self] in
            
            guard let self = self else {
                return
            }
            
            let alert = UIAlertController(title: self.title, message: self.message, preferredStyle: .alert)
            for action in self.actions ?? [] {
                alert.addAction(action)
            }
            #if WIDGET
            ConsoleViewController.visible.present(alert, animated: true, completion: nil)
            #elseif !MAIN
            ConsoleViewController.visibles.first?.present(alert, animated: true, completion: nil)
            #else
            if #available(iOS 13.0, *), scriptPath == nil {
                for scene in UIApplication.shared.connectedScenes {
                    let window = (scene as? UIWindowScene)?.windows.first
                    if window?.isKeyWindow == true {
                        window?.topViewController?.present(alert, animated: true, completion: nil)
                    }
                }
            } else {
                for console in ConsoleViewController.visibles {
                    
                    if scriptPath == nil {
                        console.topViewController.present(alert, animated: true, completion: nil)
                        break
                    }
                    
                    if console.editorSplitViewController?.editor?.document?.fileURL.path == scriptPath {
                        console.topViewController.present(alert, animated: true, completion: nil)
                        break
                    }
                }
                if ConsoleViewController.visibles.count == 0 {
                    self.response = ""
                }
            }
            #endif
        }
        while response == nil {
            sleep(UInt32(0.2))
        }
        return response!
    }
    
    // MARK: - Setters
    
    private func addAction(title: String, style: UIAlertAction.Style) {
        DispatchQueue.main.async { [weak self] in
            
            guard let self = self else {
                return
            }
            
            if self.actions == nil {
                self.actions = []
            }
            
            self.actions?.append(UIAlertAction(title: title, style: style, handler: { (_) in
                self.response = title
            }))
        }
    }
    
    /// Add an action with given tilte and handler.
    ///
    /// - Parameters:
    ///     - title: The title of the action.
    @objc func addAction(_ title: String) {
        addAction(title: title, style: .default)
    }
    
    /// Add a destructive action with given tilte and handler.
    ///
    /// - Parameters:
    ///     - title: The title of the action.
    @objc func addDestructiveAction(_ title: String) {
        addAction(title: title, style: .destructive)
    }
    
    /// Add a cancel action with given tilte and handler.
    ///
    /// - Parameters:
    ///     - title: The title of the action.
    ///
    /// - Returns: `false` if there is already a cancel action.
    @objc func addCancelAction(_ title: String) -> Bool {
        var hasCancelAction = false
        DispatchQueue.main.sync {
            for action in self.actions ?? [] {
                if action.style == .cancel {
                    hasCancelAction = true
                    return
                }
            }
            self.addAction(title: title, style: .cancel)
        }
        return !hasCancelAction
    }
}
