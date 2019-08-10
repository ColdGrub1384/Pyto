//
//  MenuViewController.swift
//  Pyto
//
//  Created by Adrian Labbé on 4/17/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit
import FileBrowser

/// A View controller for choosing from `REPL`, `PyPi` and `Settings` from an `UIDocumentBrowserViewController`.
class MenuTableViewController: UITableViewController {
    
    /// Closes this View controller.
    @IBAction func close(_ sender: Any) {
        dismiss(animated: true, completion: nil)
    }
    
    /// Opens the REPL.
    func selectREPL() {
        if let repl = self.storyboard?.instantiateViewController(withIdentifier: "repl") {
            present(repl, animated: true, completion: nil)
        }
    }
    
    /// Opens PyPi.
    func selectPyPi() {
        if let pypi = self.storyboard?.instantiateViewController(withIdentifier: "pypi") {
            present(pypi, animated: true, completion: nil)
        }
    }
    
    /// Show samples..
    func selectSamples() {
        guard let samples = Bundle.main.url(forResource: "Samples", withExtension: nil) else {
            return
        }
        
        let presentingVC = presentingViewController
        
        let fileBrowser = FileBrowser(initialPath: samples, allowEditing: false, showCancelButton: true)
        fileBrowser.didSelectFile = { file in
            guard file.filePath.pathExtension.lowercased() == "py" else {
                return
            }
            
            fileBrowser.dismiss(animated: true) {
                (presentingVC as? DocumentBrowserViewController)?.openDocument(file.filePath, run: false)
            }
        }
        
        present(fileBrowser, animated: true, completion: nil)
    }
    
    /// Shows loaded modules.
    func selectLoadedModules() {
                
        func checkModules() {
            Python.shared.run(code: "import modules_inspector; modules_inspector.main()")
        }
        
        present(UINavigationController(rootViewController: ModulesTableViewController(style: .grouped)), animated: true, completion: nil)
        
        checkModules()
    }
    
    /// Opens settings.
    func selectSettings() {
                
        if let settings = UIStoryboard(name: "Settings", bundle: nil).instantiateInitialViewController() {
            present(settings, animated: true, completion: nil)
        }
    }
    
    // MARK: - Table view controller
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = super.tableView(tableView, cellForRowAt: indexPath)
        
        guard #available(iOS 13.0, *) else {
            return cell
        }
        
        var image: UIImage?
        switch indexPath.row {
        case 0:
            image = UIImage(systemName: "play.fill")
        case 1:
            image = UIImage(systemName: "doc.fill")
        case 2:
            image = UIImage(named: "pypi")
        case 3:
            image = UIImage(systemName: "book.fill")
        case 4:
            image = UIImage(systemName: "info.circle.fill")
        case 5:
            image = UIImage(systemName: "gear")
        default:
            break
        }
        cell.imageView?.image = image
        
        return cell
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        switch indexPath.row {
        case 0:
            selectREPL()
        case 2:
            selectPyPi()
        case 3:
            selectSamples()
        case 4:
            selectLoadedModules()
        case 5:
            selectSettings()
        default:
            break
        }
        
        tableView.deselectRow(at: indexPath, animated: true)
    }
}
