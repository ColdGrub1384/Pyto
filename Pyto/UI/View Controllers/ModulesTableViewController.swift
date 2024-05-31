//
//  ModulesTableViewController.swift
//  Pyto
//
//  Created by Emma Labbé on 4/20/19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit

/// A Table view controller for viewing and deleting imported modules. Should be presented from a Python script.
@objc class ModulesTableViewController: UITableViewController, UISearchResultsUpdating {
    
    private static var visible: ModulesTableViewController?
    
    /// Imported modules names.
    @objc static var modules = [String]() {
        didSet {
            if modules.count == paths.count {
                DispatchQueue.main.async {
                    self.visible?.tableView.reloadData()
                }
            }
        }
    }
    
    /// Paths of modules. If a module is built-in, add `'built-in'`.
    @objc static var paths = [String]() {
        didSet {
            if paths.count == modules.count {
                DispatchQueue.main.async {
                    self.visible?.tableView.reloadData()
                }
            }
        }
    }
    
    private var filtredModules: [String]?
    
    private var filtredPaths: [String]?
    
    private func shortened(path: String) -> String {
        return ShortenFilePaths(in: path)
    }
    
    @objc private func close() {
        dismiss(animated: true, completion: nil)
    }
    
    private let searchController = UISearchController(searchResultsController: nil)
    
    // MARK: - UITableViewController
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        title = NSLocalizedString("modulesTableViewController.title", comment: "The title of the view controller for displaying modules")
        
        searchController.searchResultsUpdater = self
        searchController.obscuresBackgroundDuringPresentation = false
        navigationItem.searchController = searchController
        
        if !isiOSAppOnMac && splitViewController == nil {
            navigationItem.leftBarButtonItem = UIBarButtonItem(barButtonSystemItem: .done, target: self, action: #selector(close))
        }
        
        tableView.backgroundColor = .systemBackground
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        ModulesTableViewController.visible = self
        navigationController?.navigationBar.prefersLargeTitles = true
        
        Python.shared.run(code: "import modules_inspector; modules_inspector.main()")
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        if #available(iOS 13.0, *) {
            view.window?.windowScene?.title = title
        }
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        
        if #available(iOS 13.0, *) {
            view.window?.windowScene?.title = ""
        }
    }
    
    override func numberOfSections(in tableView: UITableView) -> Int {
        return 2
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        if section == 1 {
            return (filtredModules ?? ModulesTableViewController.modules).count
        } else {
            return 0
        }
    }
    
    override func tableView(_ tableView: UITableView, titleForFooterInSection section: Int) -> String? {
        if section == 0 {
            return NSLocalizedString("modulesTableViewController.subtitle", comment: "The subtitle of the view controller for displaying modules")
        } else {
            return nil
        }
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let cell = UITableViewCell(style: .subtitle, reuseIdentifier: nil)
        
        
        let modules = (filtredModules ?? ModulesTableViewController.modules)
        let paths = (filtredPaths ?? ModulesTableViewController.paths)
        
        
        if modules.indices.contains(indexPath.row) {
            cell.textLabel?.text = modules[indexPath.row]
        }
        if paths.indices.contains(indexPath.row) {
            cell.detailTextLabel?.text = shortened(path: paths[indexPath.row])
        }
            
        if paths.indices.contains(indexPath.row) && FileManager.default.fileExists(atPath: paths[indexPath.row]) {
            cell.accessoryType = .disclosureIndicator
        } else {
            cell.accessoryType = .none
        }
        
        return cell
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let url = URL(fileURLWithPath: (filtredPaths ?? ModulesTableViewController.paths)[indexPath.row])
        if FileManager.default.fileExists(atPath: url.path) {
            
            if UIDevice.current.userInterfaceIdiom == .pad {
                let docBrowser = KeyboardHostingController(viewController: SidebarSplitViewController())
                SceneDelegate.viewControllerToShow = docBrowser
                if #available(iOS 13.0, *) {
                    UIApplication.shared.requestSceneSessionActivation(nil, userActivity: nil, options: nil, errorHandler: nil)
                }
                DispatchQueue.main.asyncAfter(deadline: .now()+1) {
                    let sidebar = (docBrowser.view.window?.windowScene?.delegate as? SceneDelegate)?.sidebarSplitViewController?.sidebar
                    docBrowser.view.window?.tintColor = ConsoleViewController.choosenTheme.tintColor
                    sidebar?.open(url: url)
                }
            } else if let splitVC = splitViewController as? SidebarSplitViewController {
                splitVC.sidebar?.open(url: url)
            }
        }
        tableView.deselectRow(at: indexPath, animated: true)
    }
    
    override func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCell.EditingStyle, forRowAt indexPath: IndexPath) {
        if editingStyle == .delete {
            
            Python.shared.run(code: "import sys; del sys.modules[\"\((self.filtredModules ?? ModulesTableViewController.modules)[indexPath.row])\"]; print(\"\((self.filtredModules ?? ModulesTableViewController.modules)[indexPath.row])\")")
            
            if filtredModules != nil {
                filtredModules?.remove(at: indexPath.row)
            } else {
                ModulesTableViewController.modules.remove(at: indexPath.row)
            }
            if filtredPaths != nil {
                filtredPaths?.remove(at: indexPath.row)
            } else {
                ModulesTableViewController.paths.remove(at: indexPath.row)
            }
            tableView.deleteRows(at: [indexPath], with: .fade)
        }
    }
    
    override func tableView(_ tableView: UITableView, canEditRowAt indexPath: IndexPath) -> Bool {
        return true
    }
    
    // MARK: - Search results updating
    
    func updateSearchResults(for searchController: UISearchController) {
        let text = searchController.searchBar.text
        if text == nil || text?.isEmpty == true {
            filtredModules = nil
            filtredPaths = nil
        } else if let text = text {
            filtredModules = []
            filtredPaths = []
            for (index, module) in ModulesTableViewController.modules.enumerated() {
                if module.lowercased().contains(text.lowercased()) {
                    filtredModules?.append(module)
                    filtredPaths?.append(ModulesTableViewController.paths[index])
                }
            }
            for (index, path) in ModulesTableViewController.paths.enumerated() {
                if path.lowercased().contains(text.lowercased()) {
                    filtredPaths?.append(path)
                    filtredModules?.append(ModulesTableViewController.modules[index])
                }
            }
        }
        tableView.reloadData()
    }
}
