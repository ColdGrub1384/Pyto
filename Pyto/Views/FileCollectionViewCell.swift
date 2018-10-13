//
//  FileCollectionViewCell.swift
//  Pyto
//
//  Created by Adrian Labbe on 10/12/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit

/// A cell for displaying a file.
class FileCollectionViewCell: UICollectionViewCell, UIDocumentPickerDelegate {
    
    /// The view containing file icon.
    @IBOutlet weak var iconView: UIImageView!
    
    /// The view contaning the filename.
    @IBOutlet weak var titleView: UILabel!
    
    /// The Document browser view controller containing this Collection view.
    var documentBrowser: DocumentBrowserViewController?
    
    private var isDirectory: ObjCBool = false
    
    /// The URL to represent.
    var file: URL? {
        didSet {
            
            guard file != nil else {
                return
            }
            
            if FileManager.default.fileExists(atPath: file!.path, isDirectory: &isDirectory) {
                if isDirectory.boolValue {
                    iconView.image = UIImage(named: "Folder")
                    titleView.text = file!.lastPathComponent
                } else {
                    iconView.image = UIDocumentInteractionController(url: file!).icons.last
                    titleView.text = file!.deletingPathExtension().lastPathComponent
                }
            }
        }
    }
    
    /// Removes file.
    @objc func remove(_ sender: Any) {
        if let file = file {
            do {
                let index = documentBrowser?.scripts.firstIndex(of: file)
                try FileManager.default.removeItem(at: file)
                if let index = index {
                    DocumentBrowserViewController.visible?.collectionView.deleteItems(at: [IndexPath(row: index, section: 0)])
                }
            } catch {
                let alert = UIAlertController(title: "Error removing file!", message: error.localizedDescription, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: "Ok", style: .cancel, handler: nil))
                UIApplication.shared.keyWindow?.topViewController?.present(alert, animated: true, completion: nil)
            }
        }
    }
    
    /// Renames file.
    @objc func rename(_ sender: Any) {
        
        guard let file = file else {
            return
        }
        
        var textField: UITextField?
        let alert = UIAlertController(title: "Rename file", message: "Please type the new file's name.", preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "Rename", style: .default, handler: { (_) in
            guard let filename = textField?.text else {
                return
            }
            var newFileURL = file.deletingLastPathComponent().appendingPathComponent(filename)
            if !self.isDirectory.boolValue {
                newFileURL.appendPathExtension(file.pathExtension)
            }
            do {
                try FileManager.default.moveItem(at: file, to: newFileURL)
                self.documentBrowser?.collectionView.reloadData()
            } catch {
                let alert = UIAlertController(title: "Error creating file!", message: error.localizedDescription, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: "Ok", style: .cancel, handler: nil))
                UIApplication.shared.keyWindow?.topViewController?.present(alert, animated: true, completion: nil)
            }
        }))
        alert.addAction(UIAlertAction(title: "Cancel", style: .cancel, handler: nil))
        alert.addTextField { (textField_) in
            textField = textField_
            textField?.placeholder = "New file name"
            textField?.text = self.file?.lastPathComponent
        }
        documentBrowser?.present(alert, animated: true, completion: nil)
    }
    
    /// Runs script.
    @objc func run(_ sender: Any) {
        if let file = file {
           DocumentBrowserViewController.visible?.openDocument(file, run: true)
        }
    }
    
    /// Opens file.
    @objc func open(_ sender: Any) {
        if let file = file {
            DocumentBrowserViewController.visible?.openDocument(file, run: false)
        }
    }
    
    /// Copies file.
    @objc func copyFile(_ sender: Any) {
        if let file = file {
            let picker = UIDocumentPickerViewController(url: file, in: .exportToService)
            picker.delegate = self
            documentBrowser?.present(picker, animated: true, completion: nil)
        }
    }
    
    /// Moves file.
    @objc func move(_ sender: Any) {
        if let file = file {
            let picker = UIDocumentPickerViewController(url: file, in: .moveToService)
            picker.delegate = self
            documentBrowser?.present(picker, animated: true, completion: nil)
        }
    }
    
    // MARK: - Collection view cell
    
    override var canBecomeFirstResponder: Bool {
        return true
    }
    
    override func canPerformAction(_ action: Selector, withSender sender: Any?) -> Bool {
        return (action == #selector(remove(_:)) || action == #selector(run(_:)) || action == #selector(open(_:)) || action == #selector(rename(_:)) || action == #selector(copyFile(_:)) || action == #selector(move(_:)))
    }
    
    // MARK: - Document picker view controller delegate
    
    func documentPicker(_ controller: UIDocumentPickerViewController, didPickDocumentsAt urls: [URL]) {
        documentBrowser?.collectionView.reloadData()
    }
}
