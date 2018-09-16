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
    
    let alert = UIAlertController(title: nil, message: nil, preferredStyle: .alert)
    
    /// The alert's title.
    @objc public var title: String? {
        didSet {
            DispatchQueue.main.async {
                self.alert.title = self.title
            }
        }
    }
    
    /// The alert's message.
    @objc public var message: String? {
        didSet {
            DispatchQueue.main.async {
                self.alert.message = self.message
            }
        }
    }
    
    /// The alert's text fields.
    @objc public var textFields: [UITextField] {
        return alert.textFields ?? []
    }
    
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
    
    @objc public func show() {
        DispatchQueue.main.async {
            UIApplication.shared.keyWindow?.topViewController?.present(self.alert, animated: true, completion: nil)
        }
    }
    
    // MARK: - Setters
    
    /// Add an action with given tilte and handler.
    ///
    /// - Parameters:
    ///     - title: The title of the action.
    ///     - handler: The action's handler.
    @objc public func addAction(title: String, handler: @escaping (() -> Void)) {
        DispatchQueue.main.async {
            self.alert.addAction(UIAlertAction(title: title, style: .default, handler: { (_) in
                handler()
            }))
        }
    }
    
    /// Add a destructive action with given tilte and handler.
    ///
    /// - Parameters:
    ///     - title: The title of the action.
    ///     - handler: The action's handler.
    @objc public func addDestructiveAction(title: String, handler: @escaping (() -> Void)) {
        DispatchQueue.main.async {
            self.alert.addAction(UIAlertAction(title: title, style: .destructive, handler: { (_) in
                handler()
            }))
        }
    }
    
    /// Add a cancel action with given tilte and handler.
    ///
    /// - Parameters:
    ///     - title: The title of the action.
    ///     - handler: The action's handler.
    @objc public func addCancelAction(title: String, handler: @escaping (() -> Void)) {
        DispatchQueue.main.async {
            self.alert.addAction(UIAlertAction(title: title, style: .cancel, handler: { (_) in
                handler()
            }))
        }
    }
    
    /// Add a text field.
    ///
    /// - Parameters:
    ///     - configurationHandler: The code called to configure the text field. The parameter passed is an `UITextField`.
    @objc public func addTextField(configurationHandler: @escaping ((UITextField) -> Void)) {
        DispatchQueue.main.async {
            self.alert.addTextField(configurationHandler: configurationHandler)
        }
    }
}
