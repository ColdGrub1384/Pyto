//
//  TodayViewController.swift
//  Pyto Widget
//
//  Created by Adrian Labbé on 2/3/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit
import NotificationCenter

fileprivate var isPythonSetup = false

/// View controller with console content on the Today widget.
@objc class ConsoleViewController: UIViewController, NCWidgetProviding {
    
    /// The visible instance.
    @objc static var visible: ConsoleViewController!
    
    /// Set to `true` to start the script.
    @objc static var startScript = true
    
    /// The shared directory path to be passed to Python.
    @objc static var sharedDirectoryPath: String?
    
    /// Text view containing the console.
    @IBOutlet weak var textView: UITextView!
    
    /// Adds given text to the text view.
    ///
    /// - Parameters:
    ///     - text: Text to be added.
    @objc func print(_ text: String) {
        DispatchQueue.main.async {
            self.textView.text += text
        }
    }
    
    /// Clears screen.
    @objc func clear() {
        DispatchQueue.main.sync {
            textView.text = ""
        }
    }
    
    // MARK: - View controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view from its nib.
        
        ConsoleViewController.sharedDirectoryPath = dir?.path
        
        if !isPythonSetup {
            setup_python()
            isPythonSetup = true
        }
        
        sharedExtensionContext?.widgetLargestAvailableDisplayMode = .expanded
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        if ConsoleViewController.visible != self {
            ConsoleViewController.visible = self
        }
    }
    
    // MARK: - Widget providing
    
    func widgetPerformUpdate(completionHandler: (@escaping (NCUpdateResult) -> Void)) {
        // Perform any setup necessary in order to update the view.
        
        // If an error is encountered, use NCUpdateResult.Failed
        // If there's no update required, use NCUpdateResult.NoData
        // If there's an update, use NCUpdateResult.NewData
        
        textView.text = ""
        ConsoleViewController.startScript = true
        
        if !Python.shared.isScriptRunning {
            Python.shared.runScript(at: Bundle.main.url(forResource: "main", withExtension: "py")!)
        }
        
        completionHandler(NCUpdateResult.newData)
    }
}
