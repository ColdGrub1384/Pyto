//
//  PyInputHelper.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/9/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit

/// A helper accessible by Rubicon to request user's input.
@objc public class PyInputHelper: NSObject {
    
    /// The user's input. Set its value while Python script is waiting for input to pass the input.
    @objc public static var userInput: String?
    
    /// Shows an alert to request input.
    ///
    /// - Parameters:
    ///     - prompt: The title of the alert.
    @objc public static func showAlert(prompt: String?) {
        DispatchQueue.main.async {
            let alert = UIAlertController(title: prompt, message: "The script requested for your input", preferredStyle: .alert)
            var textField: UITextField?
            alert.addAction(UIAlertAction(title: "Submit", style: .default, handler: { (_) in
                self.userInput = textField?.text ?? ""
            }))
            alert.addTextField(configurationHandler: { (textField_) in
                textField = textField_
            })
            UIApplication.shared.keyWindow?.topViewController?.present(alert, animated: true, completion: nil)
        }
    }
}
