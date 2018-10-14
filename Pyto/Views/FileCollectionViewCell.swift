//
//  FileCollectionViewCell.swift
//  Pyto
//
//  Created by Adrian Labbe on 10/12/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit
import SavannaKit
import SourceEditor

/// A cell for displaying a file.
class FileCollectionViewCell: UICollectionViewCell, UIDocumentPickerDelegate, SyntaxTextViewDelegate {
    
    /// The view containing file icon.
    @IBOutlet weak var iconView: UIImageView?
    
    /// The view contaning the filename.
    @IBOutlet weak var titleView: UILabel!
    
    /// The view containing the code's preview.
    @IBOutlet weak var previewContainerView: UIView?
    
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
                    iconView?.image = UIImage(named: "Folder")
                    titleView.text = file!.lastPathComponent
                } else if file!.pathExtension.lowercased() == "py", let container = previewContainerView {
                    let textView = SyntaxTextView(frame: container.frame)
                    textView.delegate = self
                    if let code = try? String(contentsOf: file!) {
                        textView.text = code
                    }
                    
                    struct ReadonlyTheme: SourceCodeTheme {
                        let defaultTheme = DefaultSourceCodeTheme()
                        
                        var lineNumbersStyle: LineNumbersStyle? {
                            return nil
                        }
                        let gutterStyle = GutterStyle(backgroundColor: .clear, minimumWidth: 0)
                        var font: Font {
                            return defaultTheme.font
                        }
                        var backgroundColor: Color {
                            return defaultTheme.backgroundColor
                        }
                        func color(for syntaxColorType: SourceCodeTokenType) -> Color {
                            return defaultTheme.color(for: syntaxColorType)
                        }
                    }
                    textView.theme = ReadonlyTheme()
                    textView.contentTextView.font = textView.contentTextView.font?.withSize(5)
                    textView.contentTextView.isEditable = false
                    textView.contentTextView.isSelectable = false
                    textView.isUserInteractionEnabled = false
                    container.addSubview(textView)
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
                    documentBrowser?.ignoreObserver = true
                    documentBrowser?.collectionView.deleteItems(at: [IndexPath(row: index, section: 0)])
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
            textField?.text = self.file?.deletingPathExtension().lastPathComponent
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
    
    // MARK: - Syntax text view delegate
    
    func didChangeText(_ syntaxTextView: SyntaxTextView) {}
    
    func didChangeSelectedRange(_ syntaxTextView: SyntaxTextView, selectedRange: NSRange) {}
    
    func lexerForSource(_ source: String) -> Lexer {
        return Python3Lexer()
    }
}
