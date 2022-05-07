//
//  PipViewController.swift
//  Pyto
//
//  Created by Emma Labbé on 3/17/19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit
import SafariServices
import SwiftUI

/// A View controller for installing PyPI packages.
class PipViewController: UIHostingController<AnyView> {
    
    private func run(command: String) {
        let installer = PipInstallerViewController(command: command)
        installer.viewer = self
        let navVC = ThemableNavigationController(rootViewController: installer)
        navVC.modalPresentationStyle = .formSheet
        if !isiOSAppOnMac {
            navVC.preferredContentSize = CGSize(width: 700, height: 500) // For some reason setting preferredContentSize on Mac makes the sheet smaller
        }
        present(navVC, animated: true, completion: nil)
    }
    
    init() {
        super.init(rootView: AnyView(EmptyView()))
    }
    
    @MainActor required dynamic init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    /// The PyPI package.
    var package: PyPackage! {
        didSet {
            if package == nil {
                rootView = AnyView(EmptyView())
            } else {
                rootView = AnyView(PyPiPackageView(pipViewController: self, package: package))
            }
        }
    }
    
    /// Installs package.
    func install(version: String?) {
        run(command: "install \(package.name ?? "")\(version == nil ? "" : "==\(version!)")")
    }
    
    /// Removes package.
    func remove() {
        run(command: "uninstall -y \(package.name ?? "") ")
    }
    
    /// Bundled modules.
    static var bundled = [String]()
    
    /// Add a module to `bundled`. I add it one by one because for some reason setting directly an array fails **sometimes**.
    ///
    /// - Parameters:
    ///     - module_: The module to add.
    @objc static func addBundledModule(_ module: String) {
        bundled.append(module)
    }
}
