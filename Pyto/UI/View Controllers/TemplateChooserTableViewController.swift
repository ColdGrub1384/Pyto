//
//  TemplateChooserTableViewController.swift
//  Pyto
//
//  Created by Emma Labbé on 12-10-19.
//  Copyright © 2019 Emma Labbé. All rights reserved.
//

import UIKit

/// A View controller displayed for creating a script.
class TemplateChooserTableViewController: UITableViewController, UIDocumentPickerDelegate {
    
    /// The function called to create the file. Passed from `UIDocumentBrowserViewController.documentBrowser(_:didRequestDocumentCreationWithHandler:)`.
    var importHandler: ((URL?, UIDocumentBrowserViewController.ImportMode) -> Void)?
    
    /// Templates created by user.
    var templates: [URL] {
        return (try? FileManager.default.contentsOfDirectory(at: FileManager.default.urls(for: .libraryDirectory, in: .allDomainsMask)[0].appendingPathComponent("templates"), includingPropertiesForKeys: nil, options: .skipsHiddenFiles)) ?? []
    }
    
    /// A boolean indicating whether the user should type a script name.
    var chooseName = true
        
    /// Closes the View controller.
    @IBAction func close(_ sender: Any) {
        dismiss(animated: true, completion: nil)
    }
    
    /// Creates an empty script.
    func createEmptyScript() {
        createScript(templateURL: Bundle.main.url(forResource: "Untitled", withExtension: "py.template")!)
    }
    
    /// Creates a Hello World script.
    func createHelloWorld() {
        createScript(templateURL: Bundle.main.url(forResource: "Hello World", withExtension: "py.template")!)
    }
    
    /// Creates a widget.
    func createWidget() {
        createScript(templateURL: Bundle.main.url(forResource: "Widget", withExtension: "py.template")!)
    }
    
    /// Creates an UI.
    func createUI() {
        createScript(templateURL: Bundle.main.url(forResource: "User Interface", withExtension: "py.template")!)
    }
    
    /// Creates a script from given template. Asks for name
    ///
    /// - Parameters:
    ///     - templateURL: The URL of the template to use.
    func createScript(templateURL: URL) {
        
        func create(name: String) {
            let importHandler = self.importHandler
            self.importHandler = nil
            
            func callHandler() {
                let newURL = FileManager.default.urls(for: .cachesDirectory, in: .allDomainsMask)[0].appendingPathComponent(name)
                
                if FileManager.default.fileExists(atPath: newURL.path) {
                    try? FileManager.default.removeItem(at: newURL)
                }
                
                try? FileManager.default.copyItem(at: templateURL, to: newURL)
                
                importHandler?(newURL, .move)
            }
            
            if chooseName {
                self.dismiss(animated: true) {
                    callHandler()
                }
            } else {
                callHandler()
            }
        }
        
        if chooseName {
            let alert = UIAlertController(title: Localizable.Creation.createScriptTitle, message: Localizable.Creation.typeFileName, preferredStyle: .alert)
            alert.addAction(UIAlertAction(title: Localizable.cancel, style: .cancel, handler: nil))
            alert.addAction(UIAlertAction(title: Localizable.create, style: .default, handler: { (_) in
                
                var name = ""
                if let text = alert.textFields?.first?.text {
                    if !text.replacingOccurrences(of: " ", with: "").isEmpty {
                        name = text
                    } else {
                        name = alert.textFields?.first?.placeholder ?? ""
                    }
                } else {
                    name = Localizable.untitled
                }
                
                if (name as NSString).pathExtension.lowercased() != "py" {
                    name = (name as NSString).appendingPathExtension("py") ?? ""
                }
                
                create(name: name)
            }))
            alert.addTextField { (textField) in
                textField.placeholder = Localizable.untitled
            }
            present(alert, animated: true, completion: nil)
        } else {
            create(name: Localizable.untitled+".py")
        }
    }
    
    // MARK: - Table view controller
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        tableView.backgroundColor = .systemGroupedBackground
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        
        importHandler?(nil, .none)
    }
    
    override func numberOfSections(in tableView: UITableView) -> Int {
        return 2
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        switch section {
        case 0:
            return 4
        case 1:
            return templates.count+1
        default:
            return 0
        }
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        switch indexPath {
        case IndexPath(row: 0, section: 0):
            createEmptyScript()
        case IndexPath(row: 1, section: 0):
            createHelloWorld()
        case IndexPath(row: 2, section: 0):
            createWidget()
        case IndexPath(row: 3, section: 0):
            createUI()
        case IndexPath(row: 0, section: 1):
            let picker = UIDocumentPickerViewController(documentTypes: ["public.python-script"], in: .open)
            picker.allowsMultipleSelection = true
            picker.delegate = self
            present(picker, animated: true, completion: nil)
        default:
            if indexPath.section == 1, templates.indices.contains(indexPath.row-1) {
                createScript(templateURL: templates[indexPath.row-1])
            }
        }
        
        tableView.deselectRow(at: indexPath, animated: true)
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        switch indexPath {
        case IndexPath(row: 0, section: 0):
            return tableView.dequeueReusableCell(withIdentifier: "empty") ?? UITableViewCell()
        case IndexPath(row: 1, section: 0):
            return tableView.dequeueReusableCell(withIdentifier: "hello") ?? UITableViewCell()
        case IndexPath(row: 2, section: 0):
            return tableView.dequeueReusableCell(withIdentifier: "widget") ?? UITableViewCell()
        case IndexPath(row: 3, section: 0):
            return tableView.dequeueReusableCell(withIdentifier: "ui") ?? UITableViewCell()
        case IndexPath(row: 0, section: 1):
            return tableView.dequeueReusableCell(withIdentifier: "import") ?? UITableViewCell()
        default:
            if indexPath.section == 1 {
                let cell = UITableViewCell(style: .default, reuseIdentifier: nil)
                if #available(iOS 13.0, *) {
                cell.imageView?.image = UIImage(systemName: "doc.fill")
                }
                cell.textLabel?.text = templates[indexPath.row-1].deletingPathExtension().lastPathComponent
                return cell
            } else {
                return UITableViewCell()
            }
        }
    }
    
    override func tableView(_ tableView: UITableView, canEditRowAt indexPath: IndexPath) -> Bool {
        return (indexPath.section == 1 && indexPath.row > 0)
    }
    
    override func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCell.EditingStyle, forRowAt indexPath: IndexPath) {
        if editingStyle == .delete, templates.indices.contains(indexPath.row-1) {
            try? FileManager.default.removeItem(at: templates[indexPath.row-1])
            tableView.reloadData()
        }
    }
    
    // MARK: - Document picker delegate
    
    func documentPicker(_ controller: UIDocumentPickerViewController, didPickDocumentsAt urls: [URL]) {
        
        let templatesURL = FileManager.default.urls(for: .libraryDirectory, in: .allDomainsMask)[0].appendingPathComponent("templates")
        if !FileManager.default.fileExists(atPath: templatesURL.path) {
            try? FileManager.default.createDirectory(at: templatesURL, withIntermediateDirectories: true, attributes: nil)
        }
        
        for url in urls {
            
            let newURL = templatesURL.appendingPathComponent(url.lastPathComponent)
            
            if FileManager.default.fileExists(atPath: newURL.path) {
                try? FileManager.default.removeItem(at: newURL)
            }
            
            try? FileManager.default.copyItem(at: url, to: newURL)
        }
        
        tableView.reloadData()
    }
}
