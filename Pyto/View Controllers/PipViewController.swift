//
//  PipViewController.swift
//  Pyto
//
//  Created by Adrian Labbé on 3/17/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit
import SafariServices

/// A View controller for installing PyPi packages.
@objc class PipViewController: UITableViewController, UISearchBarDelegate, UISearchControllerDelegate {
    
    private class VersionSelectorTableViewController: UITableViewController {
        
        var versions = [String]() {
            didSet {
                tableView.reloadData()
            }
        }
        
        var origin: PipViewController?
        
        override func viewDidLoad() {
            super.viewDidLoad()
            
            title = "Select a version"
            versions = origin?.currentPackage?.versions ?? []
            navigationItem.largeTitleDisplayMode = .never
        }
        
        override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
            return versions.count
        }
        
        override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
            let cell = UITableViewCell(style: .default, reuseIdentifier: nil)
            cell.textLabel?.text = versions[indexPath.row]
            
            if versions[indexPath.row].rangeOfCharacter(from: CharacterSet.letters) == nil {
                if #available(iOS 13.0, *) {
                    cell.textLabel?.textColor = .label
                } else {
                    cell.textLabel?.textColor = .white
                }
            } else {
                cell.textLabel?.textColor = .systemOrange
            }
            
            if versions[indexPath.row] == origin?.version {
                cell.accessoryType = .checkmark
            } else {
                cell.accessoryType = .none
            }
            
            return cell
        }
        
        override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
            origin?.version = versions[indexPath.row]
            navigationController?.popViewController(animated: true)
        }
    }
    
    private func run(command: String) {
        let installer = PipInstallerViewController(command: command)
        installer.viewer = self
        let navVC = ThemableNavigationController(rootViewController: installer)
        navVC.modalPresentationStyle = .formSheet
        present(navVC, animated: true, completion: nil)
    }
    
    /// Installs package.
    @objc func install() {
        run(command: "install \(currentPackage?.name ?? "")\(version == nil ? "" : "==\(version!)")")
    }
    
    /// Removes package.
    @objc func remove() {
        run(command: "uninstall \(currentPackage?.name ?? "")")
    }
    
    /// Bundled modules.
    static var bundled = [String]()
    
    /// Add a module to `bundled`. I add it one by one because for some reason setting directly an array fails **sometimes**.
    ///
    /// - Parameters:
    ///     - module: The module to add.
    @objc static func addBundledModule(_ module: String) {
        bundled.append(module)
    }
    
    /// The selected package version.
    var version: String? {
        didSet {
            DispatchQueue.main.async {
                self.tableView.reloadData()
            }
        }
    }
    
    /// Returns the currently viewing package.
    var currentPackage: PyPackage? {
        didSet {
            version = currentPackage?.stableVersion
            DispatchQueue.main.async {
                (self.tableView.tableHeaderView as? UILabel)?.text = self.currentPackage?.description
                (self.tableView.tableHeaderView as? UILabel)?.sizeToFit()
                (self.tableView.tableHeaderView as? UILabel)?.text = self.currentPackage?.description
                self.tableView.tableHeaderView?.frame.size.height += 80
                self.tableView.reloadData()
                
                self.tableView.tableFooterView?.isHidden = self.currentPackage != nil
                (self.tableView.tableFooterView as? UILabel)?.text = "Package not found."
            }
        }
    }
    
    /// Returns `true` if the currently viewed package is installed.
    var isPackageInstalled: Bool {
        let index = FileManager.default.urls(for: .documentDirectory, in: .allDomainsMask)[0].appendingPathComponent("site-packages/.pypi_packages")
        if let str = (try? String(contentsOf: index)) {
            for line in str.components(separatedBy: .newlines) {
                if line.hasPrefix("["), let packageName = line.slice(from: "[", to: "]"), currentPackage?.name?.lowercased() == packageName.lowercased() {
                    return true
                }
            }
        }
        return false
    }
    
    /// Closes this View controller.
    @IBAction func close(_ sender: Any) {
        dismiss(animated: true, completion: nil)
    }
    
    private var _originalTitle: String?
    
    // MARK: - Table view controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        _originalTitle = title
        
        let searchController = UISearchController(searchResultsController: nil)
        searchController.delegate = self
        searchController.searchBar.delegate = self
        searchController.searchBar.placeholder = "Python package"
        searchController.searchBar.autocorrectionType = .no
        searchController.searchBar.autocapitalizationType = .none
        searchController.hidesNavigationBarDuringPresentation = false
        navigationItem.searchController = searchController
        navigationItem.hidesSearchBarWhenScrolling = false
        
        definesPresentationContext = true
        
        navigationItem.largeTitleDisplayMode = .always
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        if currentPackage == nil {
            navigationItem.searchController?.isActive = true
        }
    }
    
    override func numberOfSections(in tableView: UITableView) -> Int {
        if currentPackage != nil {
            return 5
        } else {
            return 0
        }
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        switch section {
        case 0: // Version
            return 1
        case 1: // Requirements
            return currentPackage?.requirements.count ?? 0
        case 2: // Install
            return 1
        case 3: // Project
            
            var count = 0
            
            if currentPackage?.author?.isEmpty == false {
                count += 1
            }
            
            if currentPackage?.maintainer?.isEmpty == false {
                count += 1
            }
            
            return count
        case 4: // Links
            return currentPackage?.links.count ?? 0
        default:
            return 0
        }
    }
    
    override func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        
        guard let package = currentPackage else {
            return nil
        }
        
        switch section {
        case 0: // Version
            return nil
        case 1: // Requirements
            if package.requirements.count > 0 {
                return "Requirements"
            } else {
                return nil
            }
        case 2: // Install
            return nil
        case 3: // Project
            if package.author?.isEmpty == false || package.maintainer?.isEmpty == false {
                return "Project"
            } else {
                return nil
            }
        case 4: // Links
            if package.links.count > 0 {
                return "Links"
            } else {
                return nil
            }
        default:
            return nil
        }
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        var infoCell: UITableViewCell {
            let cell = tableView.dequeueReusableCell(withIdentifier: "info") ?? UITableViewCell()
            if #available(iOS 13.0, *) {
                cell.detailTextLabel?.textColor = .secondaryLabel
            } else {
                cell.detailTextLabel?.textColor = .gray
            }
            cell.accessoryType = .none
            cell.detailTextLabel?.text = ""
            cell.textLabel?.text = ""
            cell.imageView?.image = nil
            cell.contentView.tintColor = nil
            return cell
        }
        
        switch indexPath.section {
        case 0: // Version
            let cell = infoCell
            cell.textLabel?.text = "Version"
            cell.detailTextLabel?.text = version ?? "UKNOWN"
            cell.accessoryType = .disclosureIndicator
            return cell
        case 1: // Requirements
            let cell = infoCell
            cell.textLabel?.text = currentPackage?.requirements[indexPath.row]
            cell.accessoryType = .disclosureIndicator
            return cell
        case 2: // Install
            let cell = tableView.dequeueReusableCell(withIdentifier: "install") ?? UITableViewCell()
            
            if isPackageInstalled {
                cell.contentView.tintColor = .systemRed
                (cell.viewWithTag(1) as? UIButton)?.setTitle("Remove \(currentPackage?.name ?? "package")", for: .normal)
                if #available(iOS 13.0, *) {
                    cell.imageView?.image = UIImage(systemName: "trash")
                }
            } else if let name = currentPackage?.name, PipViewController.bundled.contains(name) {
                (cell.viewWithTag(1) as? UIButton)?.setTitle("Provided by Pyto", for: .normal)
                if #available(iOS 13.0, *) {
                    cell.contentView.tintColor = .secondaryLabel
                } else {
                    cell.contentView.tintColor = .gray
                }
            } else {
                cell.contentView.tintColor = nil
                (cell.viewWithTag(1) as? UIButton)?.setTitle("Install \(currentPackage?.name ?? "package") \(version ?? "")", for: .normal)
                if #available(iOS 13.0, *) {
                    cell.imageView?.image = UIImage(systemName: "icloud.and.arrow.down")
                }
            }
            
            return cell
        case 3: // Project
            if indexPath.row == 0 { // Author
                if let author = currentPackage?.author {
                    let cell = infoCell
                    cell.textLabel?.text = "Author"
                    cell.detailTextLabel?.text = author
                    return cell
                } else if let maintainer = currentPackage?.maintainer {
                    let cell = infoCell
                    cell.textLabel?.text = "Maintainer"
                    cell.detailTextLabel?.text = maintainer
                    return cell
                } else {
                    return UITableViewCell()
                }
            } else if indexPath.row == 1 { // Maintainer
                let cell = infoCell
                cell.textLabel?.text = "Maintainer"
                cell.detailTextLabel?.text = currentPackage?.maintainer ?? "UKNOWN"
                return cell
            } else {
                return UITableViewCell()
            }
        case 4: // Links
            let cell = tableView.dequeueReusableCell(withIdentifier: "link") ?? UITableViewCell()
            (cell.contentView.viewWithTag(1) as? UIButton)?.setTitle(currentPackage?.links[indexPath.row].title, for: .normal)
            cell.accessoryType = .disclosureIndicator
            if #available(iOS 13.0, *) {
                cell.imageView?.image = UIImage(systemName: "safari")
            }
            return cell
        default:
            return UITableViewCell()
        }
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
        
        switch indexPath.section {
        case 0: // Version
            let picker = VersionSelectorTableViewController()
            picker.origin = self
            navigationController?.pushViewController(picker, animated: true)
        case 1: // Requirement
            
            guard let requirements = currentPackage?.requirements else {
                return
            }
            
            guard let vc = storyboard?.instantiateViewController(withIdentifier: "pypi") as? PipViewController else {
                return
            }
            
            let name = requirements[indexPath.row].components(separatedBy: " ")[0]
            
            vc.title = name
            
            DispatchQueue.global().async {
                vc.currentPackage = PyPackage(name: name)
                
                DispatchQueue.main.async {
                    self.navigationController?.pushViewController(vc, animated: true)
                }
            }
        case 2: // Install / Remove
            if isPackageInstalled {
                remove()
            } else {
                install()
            }
        case 3: // Info
            break
        case 4: // Link
            
            guard let url = currentPackage?.links[indexPath.row].url else {
                return
            }
            
            present(SFSafariViewController(url: url), animated: true, completion: nil)
        default:
            break
        }
    }
    
    // MARK: - Search bar delegate
    
    func searchBarSearchButtonClicked(_ searchBar: UISearchBar) {
        searchBar.text = searchBar.text?.lowercased()
        title = searchBar.text
        if title?.isEmpty != false {
            title = _originalTitle
        }
        
        if let title = title {
            DispatchQueue.global().async {
                self.currentPackage = PyPackage(name: title)
            }
        }
        
        navigationItem.searchController?.isActive = false
    }
        
    // MARK: - Search controller delegate
    
    func presentSearchController(_ searchController: UISearchController) {
        searchController.searchBar.becomeFirstResponder()
    }
}
