//
//  WatchInputSuggestionsTableViewController.swift
//  Pyto
//
//  Created by Adrian Labbé on 05-02-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import UIKit

/// A View controller for adding or removing folders that Pyto is allowed to read.
class WatchInputSuggestionsTableViewController: UITableViewController {
    
    /// Suggestions displayed on the WatchOS text entry view.
    static var suggestions: [String] {
        set {
            UserDefaults.standard.set(newValue, forKey: "watchInputSuggestions")
        }
        
        get {
            return UserDefaults.standard.stringArray(forKey: "watchInputSuggestions") ?? ["yes", "no"]
        }
    }
    
    /// Adds an entry to `suggestions`.
    @IBAction func addSuggestion(_ sender: Any) {
        let alert = UIAlertController(title: "Add Suggestion", message: "Type a new suggestion", preferredStyle: .alert)
        alert.addTextField(configurationHandler: nil)
        alert.addAction(UIAlertAction(title: "Cancel", style: .cancel, handler: nil))
        
        alert.addAction(UIAlertAction(title: "Add", style: .default, handler: { (_) in
            guard let text = alert.textFields?.first?.text, !text.isEmpty else {
                return
            }
            
            WatchInputSuggestionsTableViewController.suggestions.append(text)
            
            self.tableView.reloadData()
        }))
        
        present(alert, animated: true, completion: nil)
    }
    
    // MARK: - Table view controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        navigationItem.rightBarButtonItems?.append(editButtonItem)
        navigationItem.largeTitleDisplayMode = .never
        
        clearsSelectionOnViewWillAppear = true
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return WatchInputSuggestionsTableViewController.suggestions.count
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = UITableViewCell(style: .default, reuseIdentifier: nil)
        
        cell.textLabel?.text = WatchInputSuggestionsTableViewController.suggestions[indexPath.row]
        
        return cell
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
    }
    
    override func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCell.EditingStyle, forRowAt indexPath: IndexPath) {
        if editingStyle == .delete {
            WatchInputSuggestionsTableViewController.suggestions.remove(at: indexPath.row)
            tableView.deleteRows(at: [indexPath], with: .automatic)
        }
    }
    
    override func tableView(_ tableView: UITableView, moveRowAt sourceIndexPath: IndexPath, to destinationIndexPath: IndexPath) {
        let item = WatchInputSuggestionsTableViewController.suggestions[sourceIndexPath.row]
        WatchInputSuggestionsTableViewController.suggestions.remove(at: sourceIndexPath.row)
        WatchInputSuggestionsTableViewController.suggestions.insert(item, at: destinationIndexPath.row)
    }
    
    override func tableView(_ tableView: UITableView, canEditRowAt indexPath: IndexPath) -> Bool {
        return true
    }
    
    override func tableView(_ tableView: UITableView, canMoveRowAt indexPath: IndexPath) -> Bool {
        return true
    }
}
