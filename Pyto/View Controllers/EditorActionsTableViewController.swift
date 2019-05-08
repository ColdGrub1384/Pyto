//
//  EditorActionsTableViewController.swift
//  Pyto
//
//  Created by Adrian Labbé on 5/7/19.
//  Copyright © 2019 Adrian Labbé. All rights reserved.
//

import UIKit
import InputAssistant

/// An manager of `EditorScript`s saved to disk.
class EditorActionsTableViewController: UITableViewController, UIPopoverPresentationControllerDelegate, InputAssistantViewDataSource, InputAssistantViewDelegate {
    
    /// Initializes a view controller.
    ///
    /// - Parameters:
    ///     - scriptURL: The URL of the script passed to modules.
    init(scriptURL: URL) {
        super.init(style: .grouped)
        
        self.scriptURL = scriptURL
    }
    
    private var textField: UITextField?
    
    /// The URL of the script passed to modules.
    var scriptURL: URL!
    
    /// Editor scripts saved to disk.
    var savedEditorScripts: [EditorScript] {
        get {
            guard let data = UserDefaults.standard.data(forKey: "editorScripts") else {
                return []
            }
            
            do {
                return try JSONDecoder().decode([EditorScript].self, from: data)
            } catch {
                print(error.localizedDescription)
                return []
            }
        }
        
        set {
            do {
                UserDefaults.standard.set(try JSONEncoder().encode(newValue), forKey: "editorScripts")
            } catch {
                print(error.localizedDescription)
            }
            tableView.reloadData()
        }
    }
    
    /// Saved editor scripts with builtins.
    var editorScripts: [EditorScript] {
        return [k2to3Script, kBlackScript]+savedEditorScripts
    }
    
    /// The editor editing the script passed to programs.
    var editor: EditorViewController?
    
    @objc private func close() {
        dismiss(animated: true, completion: nil)
    }
    
    @objc private func addScript(_ sender: Any) {
        
        let alert = UIAlertController(title: Localizable.EditorActionsTableViewController.createEditorActionAlertTitle, message: Localizable.EditorActionsTableViewController.createEditorActionAlertMessage, preferredStyle: .alert)
        
        var argumentsTextField: UITextField?
        
        alert.addTextField { (textField) in
            argumentsTextField = textField
            textField.placeholder = Localizable.ArgumentsAlert.title
            self.textField = textField
            
            let inputAssistant = InputAssistantView()
            inputAssistant.delegate = self
            inputAssistant.dataSource = self
            inputAssistant.attach(to: textField)
        }
        
        alert.addAction(UIAlertAction(title: Localizable.ok, style: .default, handler: { (_) in
            guard let arguments = argumentsTextField?.text, !arguments.isEmpty else {
                return
            }
            
            self.savedEditorScripts.append(EditorScript(argv: arguments.components(separatedBy: " ")))
        }))
        
        alert.addAction(UIAlertAction(title: Localizable.cancel, style: .cancel, handler: nil))
        
        present(alert, animated: true, completion: nil)
    }
    
    // MARK: - Table view controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        title = Localizable.EditorActionsTableViewController.title
        
        navigationItem.rightBarButtonItems = [editButtonItem, UIBarButtonItem(barButtonSystemItem: .add, target: self, action: #selector(addScript(_:)))]
        navigationItem.leftBarButtonItem = UIBarButtonItem(barButtonSystemItem: .done, target: self, action: #selector(close))
    }
    
    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return editorScripts.count
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        return editorScripts[indexPath.row].tableViewCell(for: scriptURL)
    }
    
    override func tableView(_ tableView: UITableView, canEditRowAt indexPath: IndexPath) -> Bool {
        return editorScripts[indexPath.row] != k2to3Script && editorScripts[indexPath.row] != kBlackScript
    }
    
    override func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCell.EditingStyle, forRowAt indexPath: IndexPath) {
        if editingStyle == .delete {
            savedEditorScripts.remove(at: indexPath.row-2)
        }
    }
    
    override func tableView(_ tableView: UITableView, canMoveRowAt indexPath: IndexPath) -> Bool {
        return editorScripts[indexPath.row] != k2to3Script && editorScripts[indexPath.row] != kBlackScript
    }
    
    override func tableView(_ tableView: UITableView, moveRowAt sourceIndexPath: IndexPath, to destinationIndexPath: IndexPath) {
        
        guard editorScripts.indices.contains(sourceIndexPath.row), savedEditorScripts.indices.contains(sourceIndexPath.row-2), destinationIndexPath.row > 1 else {
            return tableView.reloadData()
        }
        
        let moved = editorScripts[sourceIndexPath.row]
        savedEditorScripts.remove(at: sourceIndexPath.row-2)
        savedEditorScripts.insert(moved, at: destinationIndexPath.row-2)
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        if let vc = UIStoryboard(name: "Main", bundle: Bundle.main).instantiateViewController(withIdentifier: "runModule") as? RunModuleViewController {
            vc.argv = editorScripts[indexPath.row].argv(for: scriptURL)
            navigationController?.pushViewController(vc, animated: true)
        }
        
    }
    
    // MARK: - Popover presentation controller delegate
    
    func adaptivePresentationStyle(for controller: UIPresentationController, traitCollection: UITraitCollection) -> UIModalPresentationStyle {
        return .none
    }
    
    // MARK: - Input assistant data source
    
    func textForEmptySuggestionsInInputAssistantView() -> String? {
        return nil
    }
    
    func numberOfSuggestionsInInputAssistantView() -> Int {
        return 1
    }
    
    func inputAssistantView(_ inputAssistantView: InputAssistantView, nameForSuggestionAtIndex index: Int) -> String {
        return "Script Path"
    }
    
    func inputAssistantView(_ inputAssistantView: InputAssistantView, didSelectSuggestionAtIndex index: Int) {
        textField?.insertText("$SCRIPT")
    }
}
