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
    /// - Returns: The title of the pressed action.
    @objc func show() -> String {
        response = nil
        DispatchQueue.main.async {
            let alert = UIAlertController(title: self.title, message: self.message, preferredStyle: .alert)
            for action in self.actions ?? [] {
                alert.addAction(action)
            }
            UIApplication.shared.keyWindow?.topViewController?.present(alert, animated: true, completion: nil)
        }
        while response == nil {
            sleep(UInt32(0.1))
        }
        return response!
    }
    
    // MARK: - Setters
    
    private func addAction(title: String, style: UIAlertAction.Style) {
        DispatchQueue.main.async {
            
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
    @objc func addCancelAction(_ title: String) {
        addAction(title: title, style: .cancel)
    }
}
