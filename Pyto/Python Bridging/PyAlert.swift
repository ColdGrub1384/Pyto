//
//  PyAlert.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/15/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit

/// A class representing an alert to be used from the Python API.
@objc public class PyAlert: NSObject {
    
    /// The alert's title.
    @objc public var title: String?
    
    /// The alert's message.
    @objc public var message: String?
    
    /// The alert's actions.
    var actions: [UIAlertAction]?
    
    /// Initialize a new alert.
    ///
    /// - Parameters:
    ///     - title: The alert's title.
    ///     - message: The alert's message.
    @objc public static func initWithTitle(_ title: String?, message: String?) -> PyAlert {
        let self_ = PyAlert()
        
        self_.title = title
        self_.message = message
        
        return self_
    }
    
    /// Show an alert with set parameters.
    @objc public func show() {
        DispatchQueue.main.async {
            let alert = UIAlertController(title: self.title, message: self.message, preferredStyle: .alert)
            for action in self.actions ?? [] {
                alert.addAction(action)
            }
            PyContentViewController.shared?.present(alert, animated: true, completion: nil)
        }
    }
    
    // MARK: - Setters
    
    private func addAction(title: String, handler: (() -> Void)?, style: UIAlertAction.Style) {
        DispatchQueue.main.async {
            
            if self.actions == nil {
                self.actions = []
            }
            
            self.actions?.append(UIAlertAction(title: title, style: style, handler: { (_) in
                handler?()
            }))
        }
    }
    
    /// Add an action with given tilte and handler.
    ///
    /// - Parameters:
    ///     - title: The title of the action.
    ///     - handler: The action's handler.
    @objc public func addAction(title: String, handler: (() -> Void)?) {
        addAction(title: title, handler: handler, style: .default)
    }
    
    /// Add a destructive action with given tilte and handler.
    ///
    /// - Parameters:
    ///     - title: The title of the action.
    ///     - handler: The action's handler.
    @objc public func addDestructiveAction(title: String, handler: (() -> Void)?) {
        addAction(title: title, handler: handler, style: .destructive)
    }
    
    /// Add a cancel action with given tilte and handler.
    ///
    /// - Parameters:
    ///     - title: The title of the action.
    ///     - handler: The action's handler.
    @objc public func addCancelAction(title: String, handler: (() -> Void)?) {
        addAction(title: title, handler: handler, style: .cancel)
    }
}
