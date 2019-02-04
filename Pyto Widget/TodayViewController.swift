//
//  TodayViewController.swift
//  Pyto Widget
//
//  Created by Adrian Labbé on 2/3/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit
import NotificationCenter

/// Shared directory.
let dir = FileManager.default.sharedDirectory

/// Extension context from main View controller.
var sharedExtensionContext: NSExtensionContext?

/// View controller shown on Today widget.
class TodayViewController: UIViewController, NCWidgetProviding {
    
    private func load(viewController: UIViewController) {
        
        for child in children {
            child.view?.removeFromSuperview()
            child.removeFromParent()
        }
        
        addChild(viewController)
        
        view.addSubview(viewController.view)
        viewController.view.frame = view.frame
        viewController.view.autoresizingMask = [.flexibleWidth, .flexibleHeight]
    }
    
    // MARK: - View controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        sharedExtensionContext = extensionContext
    }
    
    // MARK: - Widget providing
    
    func widgetPerformUpdate(completionHandler: (@escaping (NCUpdateResult) -> Void)) {
        // Perform any setup necessary in order to update the view.
        
        // If an error is encountered, use NCUpdateResult.Failed
        // If there's no update required, use NCUpdateResult.NoData
        // If there's an update, use NCUpdateResult.NewData
        
        if let script = dir?.appendingPathComponent("main.py"), !FileManager.default.fileExists(atPath: script.path), let noScriptVC = storyboard?.instantiateViewController(withIdentifier: "NoScript") {
            load(viewController: noScriptVC)
        } else if let consoleVC = storyboard?.instantiateViewController(withIdentifier: "Console") {
            load(viewController: consoleVC)
        }
        
        for child in children {
            if child is NCWidgetProviding {
                return (child as! NCWidgetProviding).widgetPerformUpdate?(completionHandler: completionHandler) ?? ()
            }
        }
        
        completionHandler(NCUpdateResult.newData)
    }
    
    func widgetActiveDisplayModeDidChange(_ activeDisplayMode: NCWidgetDisplayMode, withMaximumSize maxSize: CGSize) {
        if activeDisplayMode == .compact {
            preferredContentSize = CGSize(width: 0, height: 150)
        } else {
            preferredContentSize = CGSize(width: 0, height: 300)
        }
    }
}
