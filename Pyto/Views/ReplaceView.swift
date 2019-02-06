//
//  ReplaceAllView.swift
//  Pyto
//
//  Created by Adrian Labbé on 2/5/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit

/// The View placed bellow the find bar on the editor for replacing text.
class ReplaceView: UIView, UITextFieldDelegate {
    
    /// Code called for replacing all occurences in code. Parameter passed is a String to replace.
    var replaceAllHandler: ((String) -> Void)?
    
    /// Code called for replacing occurences in code. Parameter passed is a String to replace.
    var replaceHandler: ((String) -> Void)?
    
    // MARK: - UI
    
    @IBOutlet weak private var textField: UITextField!
    
    @IBAction private func replace(_ sender: Any) {
        textField.resignFirstResponder()
        replaceHandler?(textField.text ?? "")
    }
    
    @IBAction private func replaceAll(_ sender: Any) {
        textField.resignFirstResponder()
        replaceAllHandler?(textField.text ?? "")
    }
    
    // MARK: - Text field delegate
    
    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        textField.resignFirstResponder()
        return true
    }
}
