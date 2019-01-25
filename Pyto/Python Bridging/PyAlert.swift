//
//  PyAlert.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/15/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit

/// A class representing an alert to be used from the Python API.
@objc class PyAlert: NSObject {
    
    /// The alert's title.
    @objc var title: String?
    
    /// The alert's message.
    @objc var message: String?
    
    /// Response sent by the user.
    @objc var response: String?
    
    /// The alert's actions.
    @objc var actions: [UIAlertAction]?
    
    /// A semaphore used for actions.
    @objc var semaphore = DispatchSemaphore(value: 0)
    
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
    
    // MARK: - Setters
    
    private func addAction(title: String, style: UIAlertAction.Style) {
        DispatchQueue.main.async {
            
            if self.actions == nil {
                self.actions = []
            }
            
            self.actions?.append(UIAlertAction(title: title, style: style, handler: { (_) in
                self.response = title
                self.semaphore.signal()
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
    @objc func addCancelAction(_ title: String) {
        addAction(title: title, style: .cancel)
    }
}
