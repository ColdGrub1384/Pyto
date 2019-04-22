//
//  MenuViewController.swift
//  Pyto
//
//  Created by Adrian Labbé on 4/17/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit

/// A View controller for choosing from `REPL`, `PyPi` and `Settings` from an `UIDocumentBrowserViewController`.
class MenuTableViewController: UITableViewController, UIPopoverPresentationControllerDelegate {
    
    private static var repl: UIViewController?
    
    /// Opens the REPL.
    func selectREPL() {
        dismiss(animated: true) {
            if let repl = MenuTableViewController.repl {
                DocumentBrowserViewController.visible?.present(repl, animated: true, completion: nil)
            } else if let repl = self.storyboard?.instantiateViewController(withIdentifier: "repl") {
                MenuTableViewController.repl = repl
                DocumentBrowserViewController.visible?.present(repl, animated: true, completion: nil)
            }
        }
    }
    
    /// Opens PyPi.
    func selectPyPi() {
        dismiss(animated: true) {
            if let pypi = self.storyboard?.instantiateViewController(withIdentifier: "pypi") {
                DocumentBrowserViewController.visible?.present(pypi, animated: true, completion: nil)
            }
        }
    }
    
    /// Shows loaded modules.
    func selectLoadedModules() {
        let wasRunningScript = Python.shared.isScriptRunning
        if wasRunningScript {
            Python.shared.stop()
        }
        
        func checkModules() {
            PyInputHelper.userInput = "import modules_inspector; modules_inspector.main()"
        }
        
        dismiss(animated: true) {
            let navVC = UINavigationController(rootViewController: ModulesTableViewController(style: .grouped))
            navVC.modalPresentationStyle = .formSheet
            UIApplication.shared.keyWindow?.topViewController?.present(navVC, animated: true, completion: {
                if wasRunningScript {
                    _ = Timer.scheduledTimer(withTimeInterval: 1, repeats: false, block: { (_) in
                        checkModules()
                    })
                } else {
                    checkModules()
                }
            })
        }
    }
    
    /// Opens settings.
    func selectSettings() {
        dismiss(animated: true) {
            if let settings = UIStoryboard(name: "Settings", bundle: nil).instantiateInitialViewController() {
                DocumentBrowserViewController.visible?.present(settings, animated: true, completion: nil)
            }
        }
    }
    
    // MARK: - Table view controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        view.accessibilityIgnoresInvertColors = true
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        switch indexPath.row {
        case 0:
            selectREPL()
        case 1:
            selectPyPi()
        case 2:
            selectLoadedModules()
        case 3:
            selectSettings()
        default:
            break
        }
    }
    
    // MARK: - Popover presentation controller delegate
    
    func adaptivePresentationStyle(for controller: UIPresentationController) -> UIModalPresentationStyle {
        return .none
    }
}
