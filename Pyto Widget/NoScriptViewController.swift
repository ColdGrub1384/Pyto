//
//  NoScriptViewController.swift
//  Pyto Widget
//
//  Created by Adrian Labbé on 2/3/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit
import NotificationCenter

class NoScriptViewController: UIViewController, NCWidgetProviding {
    
    /// Opens Pyto settings.
    @IBAction func openPyto(_ sender: Any) {
        extensionContext?.open(URL(string: "pyto://select-script")!, completionHandler: nil)
    }
    
    // MARK: - View controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    // MARK: - Widget providing
    
    func widgetPerformUpdate(completionHandler: (@escaping (NCUpdateResult) -> Void)) {
        // Perform any setup necessary in order to update the view.
        
        // If an error is encountered, use NCUpdateResult.Failed
        // If there's no update required, use NCUpdateResult.NoData
        // If there's an update, use NCUpdateResult.NewData
        
        completionHandler(NCUpdateResult.newData)
    }
}
