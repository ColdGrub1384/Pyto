//
//  ThemableNavigationController.swift
//  Pyto
//
//  Created by Emma Labbé on 1/16/19.
//  Copyright © 2019 Emma Labbé. All rights reserved.
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
    @objc func themeDidChange(_ notification: Notification?) {
        setup(theme: ConsoleViewController.choosenTheme)
        setNeedsStatusBarAppearanceUpdate()
    }
    
    deinit {
        NotificationCenter.default.removeObserver(self)
    }
    
    // MARK: - Navigation controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        view.accessibilityIgnoresInvertColors = true
        
        NotificationCenter.default.addObserver(self, selector: #selector(themeDidChange(_:)), name: ThemeDidChangeNotification, object: nil)
    }
    
    override func traitCollectionDidChange(_ previousTraitCollection: UITraitCollection?) {
        super.traitCollectionDidChange(previousTraitCollection)
        
        themeDidChange(nil)
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        setup(theme: ConsoleViewController.choosenTheme)
        
        delegate = self
    }
    
    override var preferredStatusBarStyle: UIStatusBarStyle {
        if isDarkModeEnabled {
            if navigationBar.barStyle == .black {
                return .default
            } else {
                return .lightContent
            }
        } else {
            return super.preferredStatusBarStyle
        }
    }
    
    // MARK: - Navigation controller delegate
    
    func navigationController(_ navigationController: UINavigationController, willShow viewController: UIViewController, animated: Bool) {
        
        if #available(iOS 13.0, *) {
            viewController.view.backgroundColor = .systemBackground
        } else {
            viewController.view.backgroundColor = ConsoleViewController.choosenTheme.sourceCodeTheme.backgroundColor
        }
    }
}
