//
//  ViewController.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/8/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit
import SafariServices

/// The main file browser used to edit scripts.
class DocumentBrowserViewController: UIViewController, UICollectionViewDataSource, UICollectionViewDelegate, UIViewControllerRestoration {
    
    /// The Collection view displaying files.
    @IBOutlet weak var collectionView: UICollectionView!
    
    /// The directory to show files.
    var directory = FileManager.default.urls(for: .documentDirectory, in: .allDomainsMask)[0] {
        didSet {
            title = directory.lastPathComponent
            navigationItem.largeTitleDisplayMode = .never
            collectionView?.reloadData()
        }
    }
    
    /// Returns all scripts in current directory.
    var scripts: [URL] {
        return (try? FileManager.default.contentsOfDirectory(at: directory, includingPropertiesForKeys: nil, options: .skipsHiddenFiles)) ?? []
    }
    
    /// Creates script.
    @IBAction func create(_ sender: Any) {
        var textField: UITextField?
        let alert = UIAlertController(title: "Create script", message: "Please type the new script's name.", preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "Create", style: .default, handler: { (_) in
            guard let filename = textField?.text else {
                return
            }
            let script = self.directory.appendingPathComponent(filename).appendingPathExtension("py")
            do {
                guard let url = Bundle.main.url(forResource: "Untitled", withExtension: "py") else {
                    return
                }
                if FileManager.default.createFile(atPath: script.path, contents: try Data(contentsOf: url), attributes: nil) {
                    if let index = self.scripts.firstIndex(of: script) {
                        DocumentBrowserViewController.visible?.collectionView.insertItems(at: [IndexPath(row: index, section: 0)])
                    }
                    self.openDocument(script, run: false)
                } else {
                    let alert = UIAlertController(title: "Error creating file!", message: nil, preferredStyle: .alert)
                    alert.addAction(UIAlertAction(title: "Ok", style: .cancel, handler: nil))
                    UIApplication.shared.keyWindow?.topViewController?.present(alert, animated: true, completion: nil)
                }
            } catch {
                let alert = UIAlertController(title: "Error creating file!", message: error.localizedDescription, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: "Ok", style: .cancel, handler: nil))
                UIApplication.shared.keyWindow?.topViewController?.present(alert, animated: true, completion: nil)
            }
        }))
        alert.addAction(UIAlertAction(title: "Cancel", style: .cancel, handler: nil))
        alert.addTextField { (textField_) in
            textField = textField_
            textField?.placeholder = "File name"
        }
        present(alert, animated: true, completion: nil)
    }
    
    /// Creates folder.
    @IBAction func createFolder(_ sender: Any) {
        var textField: UITextField?
        let alert = UIAlertController(title: "Create folder", message: "Please type the new folder's name.", preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "Create", style: .default, handler: { (_) in
            guard let filename = textField?.text else {
                return
            }
            let folder = self.directory.appendingPathComponent(filename)
            do {
                try FileManager.default.createDirectory(at: folder, withIntermediateDirectories: true, attributes: nil)
                var i = 0
                for file in self.scripts { // For loop needed because the folder is not found with `Array.firstIndex(of:)`
                    if file.lastPathComponent == folder.lastPathComponent {
                        DocumentBrowserViewController.visible?.collectionView.insertItems(at: [IndexPath(row: i, section: 0)])
                        break
                    }
                    i += 1
                }
            } catch {
                let alert = UIAlertController(title: "Error creating folder!", message: error.localizedDescription, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: "Ok", style: .cancel, handler: nil))
                UIApplication.shared.keyWindow?.topViewController?.present(alert, animated: true, completion: nil)
            }
        }))
        alert.addAction(UIAlertAction(title: "Cancel", style: .cancel, handler: nil))
        alert.addTextField { (textField_) in
            textField = textField_
            textField?.placeholder = "File name"
        }
        present(alert, animated: true, completion: nil)
    }
    
    /// Open the documentation or samples.
    @IBAction func help(_ sender: UIBarButtonItem) {
        let sheet = UIAlertController(title: "Pyto", message: Python.shared.version, preferredStyle: .actionSheet)
        
        sheet.addAction(UIAlertAction(title: "Documentation", style: .default, handler: { _ in
            let safari = SFSafariViewController(url: URL(string: "https://coldgrub1384.github.io/Pyto")!)
            self.present(safari, animated: true, completion: nil)
        }))
        sheet.addAction(UIAlertAction(title: "Samples", style: .default, handler: { _ in
            let samplesSheet = UIAlertController(title: "Samples", message: "Select a sample to preview", preferredStyle: .actionSheet)
            if let samplesURL = Bundle.main.url(forResource: "Samples", withExtension: nil) {
                do {
                    let samples = try FileManager.default.contentsOfDirectory(at: samplesURL, includingPropertiesForKeys: nil, options: .init(rawValue: 0))
                    for sample in samples {
                        samplesSheet.addAction(UIAlertAction(title: sample.deletingPathExtension().lastPathComponent, style: .default, handler: { (_) in
                            self.openDocument(sample, run: false)
                        }))
                    }
                } catch {
                    print(error.localizedDescription)
                }
            }
            samplesSheet.addAction(UIAlertAction(title: "Cancel", style: .cancel, handler: nil))
            samplesSheet.popoverPresentationController?.barButtonItem = sender
            self.present(samplesSheet, animated: true, completion: nil)
        }))
        sheet.addAction(UIAlertAction(title: "Acknowledgments", style: .default, handler: { _ in
            let safari = SFSafariViewController(url: URL(string: "https://coldgrub1384.github.io/Pyto/Licenses")!)
            self.present(safari, animated: true, completion: nil)
        }))
        sheet.addAction(UIAlertAction(title: "Source code", style: .default, handler: { _ in
            let safari = SFSafariViewController(url: URL(string: "https://github.com/ColdGrub1384/Pyto")!)
            self.present(safari, animated: true, completion: nil)
        }))
        sheet.addAction(UIAlertAction(title: "Cancel", style: .cancel, handler: nil))
        sheet.popoverPresentationController?.barButtonItem = sender
        present(sheet, animated: true, completion: nil)
    }
    
    func run(code: String) {
        let url = URL(fileURLWithPath: NSTemporaryDirectory()+"/Temporary")
        if FileManager.default.fileExists(atPath: url.path) {
            try? FileManager.default.removeItem(at: url)
        }
        FileManager.default.createFile(atPath: url.path, contents: code.data(using: .utf8), attributes: nil)
        openDocument(url, run: true)
    }
    
    /// Opens the given script.
    ///
    /// - Parameters:
    ///     - document: The URL of the script.
    ///     - run: Set to `true` to run the script inmediately.
    ///     - completion: Code called after presenting the UI.
    func openDocument(_ document: URL, run: Bool, completion: (() -> Void)? = nil) {
                
        if presentedViewController != nil {
            (((presentedViewController as? UITabBarController)?.viewControllers?.first as? UINavigationController)?.viewControllers.first as? EditorViewController)?.save()
            dismiss(animated: true) {
                self.openDocument(document, run: run, completion: completion)
            }
        }
        
        Py_SetProgramName(document.lastPathComponent.cWchar_t)
        
        let doc = PyDocument(fileURL: document)
        let editor = EditorViewController(document: doc)
        let navVC = UINavigationController(rootViewController: editor)
        navVC.navigationBar.barStyle = .black
        navVC.tabBarItem = UITabBarItem(title: "Code", image: UIImage(named: "fileIcon"), tag: 0)
        let contentVC = PyContentViewController()
        contentVC.tabBarItem = UITabBarItem(tabBarSystemItem: .more, tag: 1)
        let tabBarVC = UITabBarController()
        tabBarVC.viewControllers = [navVC, contentVC]
        tabBarVC.tabBar.barStyle = .black
        tabBarVC.view.tintColor = UIColor(named: "TintColor")
        tabBarVC.view.backgroundColor = .clear
        
        tabBarVC.modalPresentationStyle = .overCurrentContext
        
        UIApplication.shared.keyWindow?.rootViewController?.present(tabBarVC, animated: true, completion: {
            if run {
                editor.run()
            }
            completion?()
        })
    }
    
    /// The visible instance
    static var visible: DocumentBrowserViewController? {
        return ((UIApplication.shared.keyWindow?.rootViewController as? UITabBarController)?.viewControllers?.first as? UINavigationController)?.visibleViewController as? DocumentBrowserViewController
    }
    
    // MARK: - View controller
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        collectionView.reloadData()
    }
    
    // MARK: - State restoration
    
    override func encodeRestorableState(with coder: NSCoder) {
        
        if let tabBarVC = presentedViewController as? UITabBarController, let editor = (tabBarVC.viewControllers?.first as? UINavigationController)?.viewControllers.first as? EditorViewController, let url = editor.document?.fileURL, let bookmark = try? url.bookmarkData() {
            
            editor.save()
            coder.encode(bookmark, forKey: "bookmark")
            if let console = (PyContentViewController.shared?.viewController as? UINavigationController)?.viewControllers.first as? ConsoleViewController {
                coder.encode(console.textView.text, forKey: "console")
            }
        }
        
        super.encodeRestorableState(with: coder)
    }
    
    override func decodeRestorableState(with coder: NSCoder) {
        super.decodeRestorableState(with: coder)
        
        var bookmarkDataIsStale = false
        if let bookmark = coder.decodeObject(forKey: "bookmark") as? Data, let url = try? URL(resolvingBookmarkData: bookmark, bookmarkDataIsStale: &bookmarkDataIsStale) {
            _ = Timer.scheduledTimer(withTimeInterval: 0.5, repeats: false, block: { (_) in // TODO: Anyway to do it without a timer?
                self.openDocument(url, run: false, completion: {
                    ((PyContentViewController.shared?.viewController as? UINavigationController)?.viewControllers.first as? ConsoleViewController)?.textView.text = (coder.decodeObject(forKey: "console") as? String) ?? ""
                })
            })
        }
        
        super.decodeRestorableState(with: coder)
    }
    
    // MARK: - View controller restoration
    
    static func viewController(withRestorationIdentifierPath identifierComponents: [String], coder: NSCoder) -> UIViewController? {
        return DocumentBrowserViewController()
    }
    
    // MARK: - Collection view data source
    
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return scripts.count
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "File", for: indexPath) as! FileCollectionViewCell
        cell.file = scripts[indexPath.row]
        cell.documentBrowser = self
        
        var isDir: ObjCBool = false
        _ = FileManager.default.fileExists(atPath: scripts[indexPath.row].path, isDirectory: &isDir)
        
        if scripts[indexPath.row].pathExtension.lowercased() == "py" || isDir.boolValue {
            cell.isUserInteractionEnabled = true
            cell.alpha = 1
        } else {
            cell.isUserInteractionEnabled = false
            cell.alpha = 0.5
        }
        return cell
    }
    
    func collectionView(_ collectionView: UICollectionView, shouldShowMenuForItemAt indexPath: IndexPath) -> Bool {
        return true
    }
    
    func collectionView(_ collectionView: UICollectionView, canPerformAction action: Selector, forItemAt indexPath: IndexPath, withSender sender: Any?) -> Bool {
        return collectionView.cellForItem(at: indexPath)?.canPerformAction(action, withSender: sender) ?? false
    }
    
    func collectionView(_ collectionView: UICollectionView, performAction action: Selector, forItemAt indexPath: IndexPath, withSender sender: Any?) {}
    
    // MARK: - Collection view delegate
    
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        var isDir: ObjCBool = false
        if FileManager.default.fileExists(atPath: scripts[indexPath.row].path, isDirectory: &isDir) {
            if isDir.boolValue {
                guard let vc = storyboard?.instantiateViewController(withIdentifier: "Browser") as? DocumentBrowserViewController else {
                    return
                }
                vc.directory = scripts[indexPath.row]
                navigationController?.pushViewController(vc, animated: true)
            } else {
                openDocument(scripts[indexPath.row], run: false)
            }
        }
    }
}
