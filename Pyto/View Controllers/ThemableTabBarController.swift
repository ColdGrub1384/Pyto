//
//  ThemableTabBarViewController.swift
//  Pyto
//
//  Created by Adrian Labbé on 1/16/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit

class ThemableTabBarController: UITabBarController {
    
    /// Setups the View controller interface for given theme.
    ///
    /// - Parameters:
    ///     - theme: The theme to apply.
    func setup(theme: Theme) {
        viewControllers?.first?.view.backgroundColor = theme.sourceCodeTheme.backgroundColor
        tabBar.barStyle = theme.barStyle
        tabBar.barTintColor = theme.sourceCodeTheme.backgroundColor
    }
    
    /// Called when the user choosed a theme.
    @objc func themeDidChanged(_ notification: Notification) {
        setup(theme: ConsoleViewController.choosenTheme)
    }
    
    deinit {
        NotificationCenter.default.removeObserver(self)
    }
    
    // MARK: Tab bar controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        NotificationCenter.default.addObserver(self, selector: #selector(themeDidChanged(_:)), name: ThemeDidChangedNotification, object: nil)
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        setup(theme: ConsoleViewController.choosenTheme)
        tabBar.isTranslucent = false
        tabBar.shadowImage = UIImage()
    }
}
