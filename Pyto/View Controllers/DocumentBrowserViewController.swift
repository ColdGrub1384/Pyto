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
class DocumentBrowserViewController: UIViewController, UICollectionViewDataSource, UICollectionViewDelegate, UICollectionViewDropDelegate, UICollectionViewDragDelegate, UIViewControllerRestoration {
    
    /// Stops file observer.
    func stopObserver() {
        stopObserver_ = true
    }
    
    private var stopObserver_ = false
    
    /// If set to `true`, the files observer will ignore next change.
    var ignoreObserver = false
    
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
    
    /// Returns all scripts and directories in current directory.
    var scripts: [URL] {
        var files = self.files
        
        var i = 0
        for file in files {
            var isDir: ObjCBool = false
            if FileManager.default.fileExists(atPath: file.path, isDirectory: &isDir) {
                if file.pathExtension.lowercased() != "py" && !isDir.boolValue {
                    files.remove(at: i)
                } else {
                    i += 1
                }
            } else {
                files.remove(at: i)
            }
        }
        
        return files
    }
    
    private var files: [URL] {
        return (try? FileManager.default.contentsOfDirectory(at: directory, includingPropertiesForKeys: nil, options: .skipsHiddenFiles)) ?? []
    }
    
    /// Creates script.
    @IBAction func create(_ sender: Any) {
        // "Create script"
        // "Please type the new script's name."
        // "Create"
        // "Error creating file!"
        // "Empty names aren't allowed."
        var textField: UITextField?
        let alert = UIAlertController(title: Localizable.Creation.createScript, message: Localizable.Creation.typeScriptName, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: Localizable.create, style: .default, handler: { (_) in
            guard let filename = textField?.text else {
                return
            }
            guard !filename.hasSuffix(".") && !filename.isEmpty else {
                let alert = UIAlertController(title: Localizable.Errors.errorCreatingFile, message: Localizable.Errors.emptyName, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: Localizable.ok, style: .cancel, handler: nil))
                self.present(alert, animated: true, completion: nil)
                return
            }
            let script = self.directory.appendingPathComponent(filename).appendingPathExtension("py")
            do {
                guard let url = Bundle.main.url(forResource: "Untitled", withExtension: "py") else {
                    return
                }
                if FileManager.default.createFile(atPath: script.path, contents: try Data(contentsOf: url), attributes: nil) {
                    var i = 0
                    for file in self.scripts { // For loop needed because the folder is not found with `Array.firstIndex(of:)`
                        if file.lastPathComponent == script.lastPathComponent {
                            self.ignoreObserver = true
                            self.collectionView.insertItems(at: [IndexPath(row: i, section: 0)])
                            break
                        }
                        i += 1
                    }
                    self.openDocument(script, run: false)
                } else {
                    let alert = UIAlertController(title: Localizable.Errors.errorCreatingFile, message: nil, preferredStyle: .alert)
                    alert.addAction(UIAlertAction(title: Localizable.ok, style: .cancel, handler: nil))
                    UIApplication.shared.keyWindow?.topViewController?.present(alert, animated: true, completion: nil)
                }
            } catch {
                let alert = UIAlertController(title: Localizable.Errors.errorCreatingFile, message: error.localizedDescription, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: Localizable.ok, style: .cancel, handler: nil))
                UIApplication.shared.keyWindow?.topViewController?.present(alert, animated: true, completion: nil)
            }
        }))
        alert.addAction(UIAlertAction(title: Localizable.cancel, style: .cancel, handler: nil))
        alert.addTextField { (textField_) in
            textField = textField_
        }
        present(alert, animated: true, completion: nil)
    }
    
    /// Creates folder.
    @IBAction func createFolder(_ sender: Any) {
        var textField: UITextField?
        let alert = UIAlertController(title: Localizable.Creation.createFolder, message: Localizable.Creation.typeFolderName, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: Localizable.create, style: .default, handler: { (_) in
            guard let filename = textField?.text else {
                return
            }
            guard !filename.hasSuffix(".") && !filename.isEmpty else {
                let alert = UIAlertController(title: Localizable.Errors.errorCreatingFolder, message: Localizable.Errors.emptyName, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: Localizable.ok, style: .cancel, handler: nil))
                self.present(alert, animated: true, completion: nil)
                return
            }
            let folder = self.directory.appendingPathComponent(filename)
            do {
                try FileManager.default.createDirectory(at: folder, withIntermediateDirectories: true, attributes: nil)
                var i = 0
                for file in self.scripts { // For loop needed because the folder is not found with `Array.firstIndex(of:)`
                    if file.lastPathComponent == folder.lastPathComponent {
                        self.ignoreObserver = true
                        self.collectionView.insertItems(at: [IndexPath(row: i, section: 0)])
                        break
                    }
                    i += 1
                }
            } catch {
                let alert = UIAlertController(title: Localizable.Creation.createFolder, message: error.localizedDescription, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: Localizable.create, style: .cancel, handler: nil))
                UIApplication.shared.keyWindow?.topViewController?.present(alert, animated: true, completion: nil)
            }
        }))
        alert.addAction(UIAlertAction(title: Localizable.cancel, style: .cancel, handler: nil))
        alert.addTextField { (textField_) in
            textField = textField_
        }
        present(alert, animated: true, completion: nil)
    }
    
    /// Open the documentation or samples.
    @IBAction func help(_ sender: UIBarButtonItem) {
        let sheet = UIAlertController(title: "Pyto", message: Python.shared.version, preferredStyle: .actionSheet)
        
        sheet.addAction(UIAlertAction(title: Localizable.Help.documentation, style: .default, handler: { _ in
            let safari = SFSafariViewController(url: URL(string: "https://coldgrub1384.github.io/Pyto")!)
            self.present(safari, animated: true, completion: nil)
        }))
        sheet.addAction(UIAlertAction(title: Localizable.Help.samples, style: .default, handler: { _ in
            let samplesSheet = UIAlertController(title: Localizable.Help.samples, message: Localizable.Help.selectSample, preferredStyle: .actionSheet)
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
            samplesSheet.addAction(UIAlertAction(title: Localizable.cancel, style: .cancel, handler: nil))
            samplesSheet.popoverPresentationController?.barButtonItem = sender
            self.present(samplesSheet, animated: true, completion: nil)
        }))
        sheet.addAction(UIAlertAction(title: Localizable.Help.acknowledgments, style: .default, handler: { _ in
            let safari = SFSafariViewController(url: URL(string: "https://coldgrub1384.github.io/Pyto/Licenses")!)
            self.present(safari, animated: true, completion: nil)
        }))
        sheet.addAction(UIAlertAction(title: Localizable.Help.sourceCode, style: .default, handler: { _ in
            let safari = SFSafariViewController(url: URL(string: "https://github.com/ColdGrub1384/Pyto")!)
            self.present(safari, animated: true, completion: nil)
        }))
        sheet.addAction(UIAlertAction(title: Localizable.cancel, style: .cancel, handler: nil))
        sheet.popoverPresentationController?.barButtonItem = sender
        present(sheet, animated: true, completion: nil)
    }
    
    /// Runs the given code.
    ///
    /// - Parameters:
    ///     - code: Code to run.
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
        
        tabBarVC.modalTransitionStyle = .crossDissolve
        
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
        
        collectionView.dragDelegate = self
        collectionView.dropDelegate = self
        collectionView.dragInteractionEnabled = true
        collectionView.reloadData()
        
        // Directory observer
        DispatchQueue.global(qos: .background).async {
            var files = self.scripts
            while true {
                if self.stopObserver_ {
                    self.stopObserver_ = false
                    break
                }
                
                if files != self.scripts {
                    files = self.scripts
                    
                    if self.ignoreObserver {
                        self.ignoreObserver = false
                    } else {
                        DispatchQueue.main.async {
                            self.collectionView.reloadData()
                        }
                    }
                }
            }
        }
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        
        stopObserver()
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
        
        var isDir: ObjCBool = false
        _ = FileManager.default.fileExists(atPath: scripts[indexPath.row].path, isDirectory: &isDir)
        
        var cell: FileCollectionViewCell
        if isDir.boolValue {
            cell = collectionView.dequeueReusableCell(withReuseIdentifier: "Folder", for: indexPath) as! FileCollectionViewCell
        } else {
            cell = collectionView.dequeueReusableCell(withReuseIdentifier: "File", for: indexPath) as! FileCollectionViewCell
        }
        cell.file = scripts[indexPath.row]
        cell.documentBrowser = self
        
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
    
    // MARK: - Collection view drag delegate
    
    func collectionView(_ collectionView: UICollectionView, itemsForBeginning session: UIDragSession, at indexPath: IndexPath) -> [UIDragItem] {
        
        guard let cell = collectionView.cellForItem(at: indexPath) as? FileCollectionViewCell else {
            return []
        }
        
        let files = scripts
        
        guard files.indices.contains(indexPath.row) else {
            return []
        }
        
        let file = files[indexPath.row]
        
        let item = UIDragItem(itemProvider: NSItemProvider(item: nil, typeIdentifier: "file"))
        item.localObject = file
        item.previewProvider = {
            
            guard let view = cell.folderContentCollectionView ?? cell.previewContainerView else {
                return nil
            }
            
            let dragPreview = UIDragPreview(view: view)
            dragPreview.parameters.backgroundColor = .clear
            
            return dragPreview
        }
        
        return [item]
    }
    
    // MARK: - Collection view drop delegate
    
    func collectionView(_ collectionView: UICollectionView, canHandle session: UIDropSession) -> Bool {
        for item in session.items {
            if !(item.localObject is URL) {
                return false
            }
        }
        return true
    }
    
    func collectionView(_ collectionView: UICollectionView, dropSessionDidUpdate session: UIDropSession, withDestinationIndexPath destinationIndexPath: IndexPath?) -> UICollectionViewDropProposal {
        
        var isDir: ObjCBool = false
        if let destinationIndexPath = destinationIndexPath, FileManager.default.fileExists(atPath: scripts[destinationIndexPath.row].path, isDirectory: &isDir) {
            
            if isDir.boolValue {
                return UICollectionViewDropProposal(operation: .move, intent: .insertIntoDestinationIndexPath)
            } else {
                return UICollectionViewDropProposal(operation: .forbidden, intent: .insertIntoDestinationIndexPath)
            }
        }
        
        return UICollectionViewDropProposal(operation: .cancel, intent: .insertIntoDestinationIndexPath)
    }
    
    func collectionView(_ collectionView: UICollectionView, performDropWith coordinator: UICollectionViewDropCoordinator) {
        guard let indexPath = coordinator.destinationIndexPath else {
            return
        }
        let destination = scripts[indexPath.row]
        
        for item in coordinator.items {
            if let url = item.dragItem.localObject as? URL {
                do {
                    try FileManager.default.moveItem(at: url, to: destination.appendingPathComponent(url.lastPathComponent))
                    var i = 0
                    for file in self.scripts { // For loop needed because folders are not found with `Array.firstIndex(of:)`
                        if file.lastPathComponent == url.lastPathComponent {
                            ignoreObserver = true
                            DocumentBrowserViewController.visible?.collectionView.deleteItems(at: [IndexPath(row: i, section: 0)])
                            break
                        }
                        i += 1
                    }
                } catch {
                    let alert = UIAlertController(title: Localizable.Errors.errorMovingFile, message: error.localizedDescription, preferredStyle: .alert)
                    alert.addAction(UIAlertAction(title: Localizable.ok, style: .cancel, handler: nil))
                    UIApplication.shared.keyWindow?.topViewController?.present(alert, animated: true, completion: nil)
                    break
                }
            }
        }
    }
}
