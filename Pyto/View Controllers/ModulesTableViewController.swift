//
//  ModulesTableViewController.swift
//  Pyto
//
//  Created by Adrian Labbé on 4/20/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
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
        var _path = path
        _path = _path.replacingOccurrences(of: DocumentBrowserViewController.localContainerURL.path, with: "Documents")
        _path = _path.replacingOccurrences(of: Bundle.main.bundlePath, with: "Pyto.app")
        if let iCloud = DocumentBrowserViewController.iCloudContainerURL {
            _path = _path.replacingOccurrences(of: iCloud.path, with: "iCloud")
        }
        _path = _path.replacingOccurrences(of: "/privatePyto.app", with: "Pyto.app")
        _path = _path.replacingOccurrences(of: "/privateDocuments", with: "Documents")
        
        return _path
    }
    
    @objc private func close() {
        dismiss(animated: true, completion: nil)
    }
    
    private let searchController = UISearchController(searchResultsController: nil)
    
    // MARK: - UITableViewController
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        title = Localizable.ModulesTableViewController.title
        
        searchController.searchResultsUpdater = self
        searchController.obscuresBackgroundDuringPresentation = false
        navigationItem.searchController = searchController
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        ModulesTableViewController.visible = self
        navigationController?.navigationBar.prefersLargeTitles = true
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
            return Localizable.ModulesTableViewController.subtitle
        } else {
            return nil
        }
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let cell = UITableViewCell(style: .subtitle, reuseIdentifier: nil)
        cell.textLabel?.text = (filtredModules ?? ModulesTableViewController.modules)[indexPath.row]
        cell.detailTextLabel?.text = shortened(path: (filtredPaths ?? ModulesTableViewController.paths)[indexPath.row])
        
        if FileManager.default.fileExists(atPath: (filtredPaths ?? ModulesTableViewController.paths)[indexPath.row]) {
            cell.accessoryType = .disclosureIndicator
        } else {
            cell.accessoryType = .none
        }
        
        return cell
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let url = URL(fileURLWithPath: ModulesTableViewController.paths[indexPath.row])
        if FileManager.default.fileExists(atPath: url.path) {
            _ = (UIApplication.shared.delegate as? AppDelegate)?.application(UIApplication.shared, open: url)
        }
        tableView.deselectRow(at: indexPath, animated: true)
    }
    
    override func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCell.EditingStyle, forRowAt indexPath: IndexPath) {
        if editingStyle == .delete {
            
            if Python.shared.isScriptRunning {
                Python.shared.stop()
            }
            PyInputHelper.userInput = "import sys; del sys.modules[\"\((self.filtredModules ?? ModulesTableViewController.modules)[indexPath.row])\"]; print(\"\((self.filtredModules ?? ModulesTableViewController.modules)[indexPath.row])\")"
            
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
