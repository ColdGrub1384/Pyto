//
//  ResolveConflictsTableViewController.swift
//  Pyto
//
//  Created by Adrian Labbé on 5/11/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit

/// A View controller that displays all conflicted versions of a file and the version to keep.
class ResolveConflictsTableViewController: UITableViewController {
    
    /// Conflicted versions of the file.
    var versions = [NSFileVersion]() {
        didSet {
            loadViewIfNeeded()
            tableView.reloadData()
        }
    }
    
    /// The document where `versions` come from.
    var document: PyDocument?
    
    /// Code called after resolving conflict.
    var completion: (() -> Void)?
    
    private var selectedVersion: NSFileVersion? {
        didSet {
            keepButton.isEnabled = (selectedVersion != nil)
        }
    }
    
    // MARK: - UI
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        if #available(iOS 13.0, *) {
            view.window?.windowScene?.title = title
        }
    }
    
    @IBOutlet weak private var keepButton: UIBarButtonItem!
    
    
    @IBAction private func cancel(_ sender: Any) {
        dismiss(animated: true, completion: nil)
    }
    
    @IBAction private func keep(_ sender: Any) {
        guard let version = selectedVersion, let doc = document else {
            return
        }
        
        do {
            try version.replaceItem(at: doc.fileURL, options: [])
            
            try doc.load(fromContents: try Data(contentsOf: doc.fileURL), ofType: "public.python-script")
            
            try NSFileVersion.removeOtherVersionsOfItem(at: doc.fileURL)
            
            dismiss(animated: true, completion: completion)
        } catch {
            let alert = UIAlertController(title: Localizable.Errors.errorWrittingToScript, message: error.localizedDescription, preferredStyle: .alert)
            alert.addAction(UIAlertAction(title: Localizable.cancel, style: .cancel, handler: nil))
            present(alert, animated: true, completion: nil)
        }
    }
    
    // MARK: - Table view controller
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let cell = tableView.dequeueReusableCell(withIdentifier: "version") ?? UITableViewCell(style: .subtitle, reuseIdentifier: nil)
        
        cell.textLabel?.text = versions[indexPath.row].localizedNameOfSavingComputer ?? versions[indexPath.row].localizedName
        
        let dateFormatter = DateFormatter()
        dateFormatter.dateStyle = .medium
        dateFormatter.timeStyle = .medium
        dateFormatter.locale = Locale.current
        
        if let date = versions[indexPath.row].modificationDate {
            cell.detailTextLabel?.text = dateFormatter.string(from: date)
        }
        
        return cell
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return versions.count
    }
    
    override func tableView(_ tableView: UITableView, willDisplay cell: UITableViewCell, forRowAt indexPath: IndexPath) {
        
        if versions[indexPath.row] == selectedVersion {
            cell.accessoryType = .checkmark
        } else {
            cell.accessoryType = .none
        }
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        
        tableView.deselectRow(at: indexPath, animated: true)
        
        let cells = tableView.visibleCells
        let currentCell = cells[indexPath.row]
            
        if currentCell.accessoryType == .none {
            selectedVersion = versions[indexPath.row]
            currentCell.accessoryType = .checkmark
        } else {
            selectedVersion = nil
            currentCell.accessoryType = .none
        }
        
        for cell in cells {
            if cell !== currentCell {
                cell.accessoryType = .none
            }
        }
    }
}
