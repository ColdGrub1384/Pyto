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
    
    /// Opens the REPL.
    func selectREPL() {
        let presentingVC = presentingViewController
        dismiss(animated: true) {
            if let repl = self.storyboard?.instantiateViewController(withIdentifier: "repl") {
                presentingVC?.present(repl, animated: true, completion: nil)
            }
        }
    }
    
    /// Opens PyPi.
    func selectPyPi() {
        let presentingVC = presentingViewController
        dismiss(animated: true) {
            if let pypi = self.storyboard?.instantiateViewController(withIdentifier: "pypi") {
                presentingVC?.present(pypi, animated: true, completion: nil)
            }
        }
    }
    
    /// Shows loaded modules.
    func selectLoadedModules() {
        
        let presentingVC = presentingViewController
        
        func checkModules() {
            Python.shared.run(code: "import modules_inspector; modules_inspector.main()")
        }
        
        dismiss(animated: true) {
            presentingVC?.present(UINavigationController(rootViewController: ModulesTableViewController(style: .grouped)), animated: true, completion: nil)
        }
        
        checkModules()
    }
    
    /// Opens settings.
    func selectSettings() {
        
        let presentingVC = presentingViewController
        
        dismiss(animated: true) {
            if let settings = UIStoryboard(name: "Settings", bundle: nil).instantiateInitialViewController() {
                presentingVC?.present(settings, animated: true, completion: nil)
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
