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
import WebKit

class CollectionView: UICollectionView {
    
    override func layoutAttributesForItem(at indexPath: IndexPath) -> UICollectionViewLayoutAttributes? {
        return nil
    }
}

/// A cell for displaying a file.
class FileCollectionViewCell: UICollectionViewCell, UIDocumentPickerDelegate, SyntaxTextViewDelegate {
    
    /// The view contaning the filename.
    @IBOutlet weak var titleView: UILabel!
    
    /// The view containing the code's preview.
    @IBOutlet weak var previewContainerView: UIView?
    
    /// Label showing info about a folder.
    @IBOutlet weak var folderLabel: UILabel?
    
    /// The Document browser view controller containing this Collection view.
    var documentBrowser: DocumentBrowserViewController?
    
    private var isDirectory: ObjCBool = false
    
    private var directoryContents: (Int, [URL]) {
        guard isDirectory.boolValue, let file = file else {
            return (0, [])
        }
        
        var files = (try? FileManager.default.contentsOfDirectory(at: file, includingPropertiesForKeys: nil, options: .skipsHiddenFiles)) ?? []
        
        var dirs = 0
        
        var i = 0
        for file in files {
            var isDir: ObjCBool = false
            if FileManager.default.fileExists(atPath: file.path, isDirectory: &isDir) {
                if file.pathExtension.lowercased() != "py" || isDir.boolValue {
                    
                    if isDir.boolValue {
                        dirs += 1
                    }
                    
                    files.remove(at: i)
                } else {
                    i += 1
                }
            } else {
                files.remove(at: i)
            }
        }
        
        return (dirs, files)
    }
    
    /// The URL to represent.
    var file: URL? {
        didSet {
            
            guard file != nil else {
                return
            }
            
            titleView.text = file!.deletingPathExtension().lastPathComponent
            
            if FileManager.default.fileExists(atPath: file!.path, isDirectory: &isDirectory) {
                
                for view in previewContainerView?.subviews ?? [] {
                    if view is UIImageView {
                        view.removeFromSuperview()
                    }
                }
                
                previewContainerView?.layer.borderColor = UIColor.gray.cgColor
                previewContainerView?.layer.borderWidth = 0.25
                
                folderLabel?.layer.borderColor = UIColor.gray.cgColor
                folderLabel?.layer.borderWidth = 0.25
                
                if isDirectory.boolValue {
                    self.folderLabel?.text = ""
                    DispatchQueue.global().async {
                        let numOfFiles = self.directoryContents.1.count+self.directoryContents.0
                        DispatchQueue.main.async {
                            self.folderLabel?.isHidden = false
                            self.folderLabel?.text = Localizable.Folders.numberOfFiles(numOfFiles)
                            self.titleView.text = self.file!.lastPathComponent
                        }
                    }
                } else if file!.pathExtension.lowercased() == "py" || file!.pathExtension.lowercased() == "md" || file!.pathExtension.lowercased() == "markdown", let container = previewContainerView {
                    
                    var textView: SyntaxTextView!

                    for view in (previewContainerView?.subviews ?? []) {
                        if let syntaxTextView = view as? SyntaxTextView {
                            textView = syntaxTextView
                        }
                    }
                    
                    if textView == nil {
                        textView = SyntaxTextView(frame: container.frame)
                    }
                    
                    textView.delegate = self
                    if let code = try? String(contentsOf: file!) {
                        var smallerCode = ""
                        
                        for (i, line) in code.components(separatedBy: "\n").enumerated() {
                            
                            guard i < 20 else {
                                break
                            }
                            
                            smallerCode += line+"\n"
                        }
                        
                        textView.text = smallerCode
                    }
                    
                    textView.theme = ReadonlyTheme(ConsoleViewController.choosenTheme.sourceCodeTheme)
                    textView.contentTextView.font = textView.contentTextView.font?.withSize(12)
                    textView.contentTextView.isEditable = false
                    textView.contentTextView.isSelectable = false
                    textView.isUserInteractionEnabled = false
                    
                    textView.backgroundColor = .clear
                    textView.contentTextView.backgroundColor = .clear
                    textView.subviews.first?.backgroundColor = .clear
                    
                    if textView.window == nil {
                        container.addSubview(textView)
                    }
                    titleView.text = file!.deletingPathExtension().lastPathComponent
                } else if let container = previewContainerView {
                    
                    let image: UIImage?
                    if let data = try? Data(contentsOf: file!), let preview = UIImage(data: data) {
                        image = preview
                    } else {
                        image = UIDocumentInteractionController(url: file!).icons.last
                    }
                    
                    var imageView: UIImageView!
                    
                    for view in container.subviews {
                        if !(view is UIImageView) {
                            view.removeFromSuperview()
                        } else {
                            imageView = view as? UIImageView
                            imageView.image = image
                        }
                    }
                    
                    if imageView == nil {
                        imageView = UIImageView(image: image)
                    }
                    
                    imageView.frame = CGRect(origin: .zero, size: CGSize(width: container.frame.width/2, height: container.frame.height/2))
                    imageView.center = container.center
                    imageView.autoresizingMask = [.flexibleWidth, .flexibleHeight]
                    
                    imageView.contentMode = .scaleAspectFit
                    
                    if imageView.window == nil {
                        container.addSubview(imageView)
                    }
                    
                    titleView.text = file!.deletingPathExtension().lastPathComponent
                }
            }
        }
    }
    
    /// Removes file.
    @objc func remove(_ sender: Any) {
        if let file = file {
            do {
                try FileManager.default.removeItem(at: file)
                documentBrowser?.collectionView.reloadData()
            } catch {
                let alert = UIAlertController(title: Localizable.Errors.errorRemovingFile, message: error.localizedDescription, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: Localizable.ok, style: .cancel, handler: nil))
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
        let alert = UIAlertController(title: Localizable.Renaming.title, message: Localizable.Renaming.message, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: Localizable.Renaming.rename, style: .default, handler: { (_) in
            guard let filename = textField?.text else {
                return
            }
            guard !filename.hasSuffix(".") && !filename.isEmpty else {
                let alert = UIAlertController(title: Localizable.Errors.errorRenamingFile, message: Localizable.Errors.emptyName, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: Localizable.ok, style: .cancel, handler: nil))
                DocumentBrowserViewController.visible?.present(alert, animated: true, completion: nil)
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
                let alert = UIAlertController(title: Localizable.Errors.errorRenamingFile, message: error.localizedDescription, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: Localizable.ok, style: .cancel, handler: nil))
                UIApplication.shared.keyWindow?.topViewController?.present(alert, animated: true, completion: nil)
            }
        }))
        alert.addAction(UIAlertAction(title: Localizable.cancel, style: .cancel, handler: nil))
        alert.addTextField { (textField_) in
            textField = textField_
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
            guard let vc = documentBrowser?.storyboard?.instantiateViewController(withIdentifier: "Browser") as? DocumentBrowserViewController else {
                return
            }
            vc.directory = DocumentBrowserViewController.localContainerURL
            vc.fileToMove = file
            documentBrowser?.navigationController?.pushViewController(vc, animated: true)
        }
    }
    
    // MARK: - Collection view cell
    
    override func willMove(toWindow newWindow: UIWindow?) {
        super.willMove(toWindow: newWindow)
        
        layer.cornerRadius = 3
        folderLabel?.layer.cornerRadius = 3
        folderLabel?.layer.cornerRadius = 3
        
        let theme = ConsoleViewController.choosenTheme
        backgroundColor = theme.sourceCodeTheme.backgroundColor
        titleView.textColor = theme.sourceCodeTheme.color(for: .plain)
        folderLabel?.backgroundColor = backgroundColor
        previewContainerView?.backgroundColor = backgroundColor
    }
    
    override var canBecomeFirstResponder: Bool {
        return true
    }
    
    override func canPerformAction(_ action: Selector, withSender sender: Any?) -> Bool {
        
        guard documentBrowser?.fileToMove == nil else {
            return false
        }
        
        if file?.path.hasPrefix(Bundle.main.bundlePath) == true {
            return (action == #selector(open(_:)))
        } else if isDirectory.boolValue || file?.pathExtension.lowercased() != "py" {
            if let file = file, FileManager.default.isDeletableFile(atPath: file.path) {
                return (
                    action == #selector(open(_:))     ||
                    action == #selector(remove(_:))   ||
                    action == #selector(rename(_:))   ||
                    action == #selector(copyFile(_:)) ||
                    action == #selector(move(_:))
                )
            } else {
                return (
                    action == #selector(open(_:))     ||
                    action == #selector(copyFile(_:))
                )
            }
        } else {
            if let file = file, FileManager.default.isDeletableFile(atPath: file.path) {
                return (
                    action == #selector(remove(_:))   ||
                    action == #selector(run(_:))      ||
                    action == #selector(open(_:))     ||
                    action == #selector(rename(_:))   ||
                    action == #selector(copyFile(_:)) ||
                    action == #selector(move(_:))
                )
            } else {
                return (
                    action == #selector(run(_:))      ||
                    action == #selector(open(_:))     ||
                    action == #selector(copyFile(_:))
                )
            }
        }
    }
    
    // MARK: - Document picker view controller delegate
    
    func documentPicker(_ controller: UIDocumentPickerViewController, didPickDocumentsAt urls: [URL]) {
        //documentBrowser?.collectionView.reloadData()
    }
    
    // MARK: - Syntax text view delegate
    
    func didChangeText(_ syntaxTextView: SyntaxTextView) {}
    
    func didChangeSelectedRange(_ syntaxTextView: SyntaxTextView, selectedRange: NSRange) {}
    
    func lexerForSource(_ source: String) -> Lexer {
        if file?.pathExtension.lowercased() == "py" {
            return Python3Lexer()
        } else {
            struct PlainTextLexer: SourceCodeRegexLexer {
                func generators(source: String) -> [TokenGenerator] {
                    return []
                }
            }
            
            return PlainTextLexer()
        }
    }
}
