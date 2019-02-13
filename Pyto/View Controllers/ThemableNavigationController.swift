//
//  ThemableNavigationController.swift
//  Pyto
//
//  Created by Adrian Labbé on 1/16/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit
import SplitKit

/// A themable Navigation controller.
class ThemableNavigationController: UINavigationController, UINavigationControllerDelegate {
    
    /// Setups the View controller interface for given theme.
    ///
    /// - Parameters:
    ///     - theme: The theme to apply.
    func setup(theme: Theme) {
        for viewController in viewControllers {
            viewController.view.backgroundColor = theme.sourceCodeTheme.backgroundColor
        }
        navigationBar.barStyle = theme.barStyle
        navigationBar.barTintColor = theme.sourceCodeTheme.backgroundColor
        toolbar.barStyle = theme.barStyle
        toolbar.barTintColor = theme.sourceCodeTheme.backgroundColor
    }
    
    /// Called when the user choosed a theme.
    @objc func themeDidChanged(_ notification: Notification) {
        setup(theme: ConsoleViewController.choosenTheme)
        
        if let currentBrowser = visibleViewController as? DocumentBrowserViewController, let storyboard = self.storyboard, let browser = storyboard.instantiateViewController(withIdentifier: "Browser") as? DocumentBrowserViewController {
            
            if currentBrowser.directory != DocumentBrowserViewController.localContainerURL {
                browser.directory = currentBrowser.directory
            } else {
                browser.setDirectory(currentBrowser.directory)
            }
            
            var vcs = viewControllers
            vcs.removeLast()
            vcs.append(browser)
            viewControllers = vcs
        }
    }
    
    deinit {
        NotificationCenter.default.removeObserver(self)
    }
    
    // MARK: - Navigation controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        NotificationCenter.default.addObserver(self, selector: #selector(themeDidChanged(_:)), name: ThemeDidChangeNotification, object: nil)
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        setup(theme: ConsoleViewController.choosenTheme)
        
        navigationBar.isTranslucent = false
        navigationBar.shadowImage = UIImage()
        toolbar.setShadowImage(UIImage(), forToolbarPosition: .any)
        toolbar.isTranslucent = false
        
        delegate = self
    }
    
    // MARK: - Navigation controller delegate
    
    func navigationController(_ navigationController: UINavigationController, willShow viewController: UIViewController, animated: Bool) {
        
        viewController.view.backgroundColor = ConsoleViewController.choosenTheme.sourceCodeTheme.backgroundColor
    }
}
