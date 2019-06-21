//
//  UIResponder.swift
//  Pyto
//
//  Created by Adrian Labbé on 16-06-19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit

#if targetEnvironment(UIKitForMac)
extension UIApplication {
    
    /// Opens a new window.
    @IBAction func newFile(_ sender: Any) {
        requestSceneSessionActivation(nil, userActivity: nil, options: nil, errorHandler: nil)
    }
    
    /// Shows settings.
    @IBAction func showSettings(_ sender: Any) {
        
        if let settings = UIStoryboard(name: "Settings", bundle: nil).instantiateInitialViewController() {
            SceneDelegate.viewControllerToShow = settings
            requestSceneSessionActivation(nil, userActivity: nil, options: nil, errorHandler: nil)
        }
    }
    
    /// Shows REPL.
    @IBAction func showREPL(_ sender: Any) {
        
        SceneDelegate.viewControllerToShow = UIStoryboard(name: "Main", bundle: nil).instantiateViewController(identifier: "repl")
        SceneDelegate.viewControllerToShow?.loadView()
        requestSceneSessionActivation(nil, userActivity: nil, options: nil, errorHandler: nil)
    }
    
    /// Shows PyPi.
    @IBAction func showPyPi(_ sender: Any) {
        
        SceneDelegate.viewControllerToShow = UIStoryboard(name: "Main", bundle: nil).instantiateViewController(identifier: "pypi")
        requestSceneSessionActivation(nil, userActivity: nil, options: nil, errorHandler: nil)
    }
    
    /// Shows the View controller for running commands.
    @IBAction func runModules(_ sender: Any) {
        
        SceneDelegate.viewControllerToShow = UIStoryboard(name: "Main", bundle: nil).instantiateViewController(identifier: "runModulesNavigationController")
        requestSceneSessionActivation(nil, userActivity: nil, options: nil, errorHandler: nil)
    }
    
    /// Shows loaded modules.
    @IBAction func showLoadedModules(_ sender: Any) {
        
        Python.shared.run(code: "import modules_inspector; modules_inspector.main()")
        
        SceneDelegate.viewControllerToShow = UINavigationController(rootViewController: ModulesTableViewController(style: .grouped))
        requestSceneSessionActivation(nil, userActivity: nil, options: nil, errorHandler: nil)
    }
}
#endif
