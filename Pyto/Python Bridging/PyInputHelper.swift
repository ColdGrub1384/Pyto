//
//  PyInputHelper.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/9/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit

/// A helperaccessible by Rubicon to request user's input.
@objc class PyInputHelper: NSObject {
    
    /// The user's input. Set its value while Python script is waiting for input to pass the input.
    @objc static var userInput: String?
    
    /// Shows an alert to request input.
    ///
    /// - Parameters:
    ///     - prompt: The title of the alert.
    @objc static func showAlert(prompt: String?) {
        DispatchQueue.main.async {
            
            let pyContentConsole = (PyContentViewController.shared?.viewController as? UINavigationController)?.visibleViewController as? ConsoleViewController
            
            let console = ((UIApplication.shared.keyWindow?.rootViewController as? UITabBarController)?.viewControllers?.last as? UINavigationController)?.visibleViewController as? REPLViewController
            
            if PyContentViewController.shared?.isViewVisible == true {
                pyContentConsole?.input(prompt: prompt ?? "")
            } else {
                console?.input(prompt: prompt ?? "")
            }
        }
    }
}
