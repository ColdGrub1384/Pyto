//
//  ResolveConflictsTableViewController.swift
//  Pyto
//
//  Created by Emma Labbé on 5/11/19.
//  Copyright © 2019 Emma Labbé. All rights reserved.
//

import UIKit
import QuickLook

extension NSFileVersion: QLPreviewItem {
    
    public var previewItemURL: URL? {
        let doc = PyDocument(fileURL: url)
        try? doc.read(from: url)
        let text = doc.text
        
        let fileURL = URL(fileURLWithPath: NSTemporaryDirectory()).appendingPathComponent(url.lastPathComponent)
        FileManager.default.createFile(atPath: fileURL.path, contents: text.data(using: .utf8), attributes: nil)
        
        return fileURL
    }
    
    public var previewItemTitle: String? {
        let dateFormatter = DateFormatter()
        dateFormatter.dateStyle = .medium
        dateFormatter.timeStyle = .medium
        dateFormatter.locale = Locale.current
        
        if let date = modificationDate {
            return dateFormatter.string(from: date)
        } else {
            return nil
        }
    }
}

/// A View controller that displays all conflicted versions of a file and the version to keep.
class ResolveConflictsTableViewController: UITableViewController, QLPreviewControllerDelegate, QLPreviewControllerDataSource {
    
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
        dismiss(animated: true, completion: completion)
    }
    
    @IBAction private func keep(_ sender: Any) {
        guard let version = selectedVersion, let doc = document else {
            return
        }
        
        do {
            if NSFileVersion.currentVersionOfItem(at: doc.fileURL) != version {
                try version.replaceItem(at: doc.fileURL, options: [])
                
                try doc.load(fromContents: try Data(contentsOf: doc.fileURL), ofType: "public.python-script")
            }
            
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
            cell.accessoryType = .detailButton
        }
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        
        tableView.deselectRow(at: indexPath, animated: true)
        
        let cells = tableView.visibleCells
        let currentCell = cells[indexPath.row]
            
        if currentCell.accessoryType == .detailButton {
            selectedVersion = versions[indexPath.row]
            currentCell.accessoryType = .checkmark
        } else {
            selectedVersion = nil
            currentCell.accessoryType = .detailButton
        }
        
        for cell in cells {
            if cell !== currentCell {
                cell.accessoryType = .detailButton
            }
        }
    }
    
    override func tableView(_ tableView: UITableView, accessoryButtonTappedForRowWith indexPath: IndexPath) {
        let vc = QLPreviewController()
        vc.dataSource = self
        vc.delegate = self
        vc.currentPreviewItemIndex = indexPath.row
        present(vc, animated: true, completion: nil)
    }
    
    // MARK: - Preview controller data source
    
    func numberOfPreviewItems(in controller: QLPreviewController) -> Int {
        return versions.count
    }
    
    func previewController(_ controller: QLPreviewController, previewItemAt index: Int) -> QLPreviewItem {
        return versions[index] as QLPreviewItem
    }
}
