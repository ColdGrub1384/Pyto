//
//  MenuViewController.swift
//  Pyto
//
//  Created by Adrian Labbé on 4/17/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit

/// A View controller for choosing from `REPL`, `PyPi` and `Settings` from an `UIDocumentBrowserViewController`.
class MenuTableViewController: UITableViewController {
    
    /// Closes this View controller.
    @IBAction func close(_ sender: Any) {
        dismiss(animated: true, completion: nil)
    }
    
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
            DocumentBrowserViewController.visible?.present(UINavigationController(rootViewController: ModulesTableViewController(style: .grouped)), animated: true, completion: nil)
        }
        
        if wasRunningScript {
            _ = Timer.scheduledTimer(withTimeInterval: 1, repeats: false, block: { (_) in
                checkModules()
            })
        } else {
            checkModules()
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
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        switch indexPath.row {
        case 0:
            selectREPL()
        case 2:
            selectPyPi()
        case 3:
            selectLoadedModules()
        case 4:
            selectSettings()
        default:
            break
        }
        
        tableView.deselectRow(at: indexPath, animated: true)
    }
}
