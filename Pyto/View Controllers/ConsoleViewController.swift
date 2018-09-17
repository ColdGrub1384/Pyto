//
//  ConsoleViewController.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/8/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit
import SavannaKit
import SourceEditor

/// A View controller containing Python script output and stderr.
class ConsoleViewController: UIViewController {
    
    /// The Text view containing the console.
    var textView: UITextView!
    
    /// Add the content of the given notification as `String` to `textView`. Called when the stderr changed or when a script printed from the Pyto module's `print` function`.
    ///
    /// - Parameters:
    ///     - notification: Its associated object should be the `String` added to `textView`.
    @objc func print_(_ notification: Notification) {
        if let output = notification.object as? String {
            DispatchQueue.main.async {
                if output == "PytoRemoveConsoleContent" {
                    self.textView?.text = ""
                } else {
                    self.textView?.text.append(output)
                }
            }
        }
    }
    
    /// Closes the View controller.
    @objc func close() {
        extensionContext?.completeRequest(returningItems: nil, completionHandler: nil)
        dismiss(animated: true, completion: nil)
    }
    
    deinit {        
        NotificationCenter.default.removeObserver(self)
    }
    
    // MARK: - View controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        title = "Console"
        textView = UITextView(frame: view.frame)
        textView.autoresizingMask = [.flexibleHeight, .flexibleWidth]
        textView.backgroundColor = .clear
        view.backgroundColor = DefaultSourceCodeTheme().backgroundColor
        textView.textColor = DefaultSourceCodeTheme().color(for: .plain)
        textView.isEditable = false
        textView.font = UIFont(name: "Courier", size: UIFont.systemFontSize)
        view.addSubview(textView)
        
        navigationItem.rightBarButtonItems = [UIBarButtonItem(barButtonSystemItem: .done, target: self, action: #selector(close))]
        
        NotificationCenter.default.addObserver(self, selector: #selector(print_(_:)), name: .init(rawValue: "DidReceiveOutput"), object: nil)
    }
}
