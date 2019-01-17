//
//  ViewController.swift
//  Pyto
//
//  Created by Adrian Labbe on 9/8/18.
//  Copyright © 2018 Adrian Labbé. All rights reserved.
//

import UIKit
import SafariServices
import CoreSpotlight
import SplitKit
import SavannaKit

/// The main file browser used to edit scripts.
class DocumentBrowserViewController: UIViewController, UICollectionViewDataSource, UICollectionViewDelegate, UICollectionViewDropDelegate, UICollectionViewDragDelegate {
    
    /// Stops file observer.
    func stopObserver() {
        stopObserver_ = true
    }
    
    private var stopObserver_ = false
    
    /// If set to `true`, the files observer will ignore next change.
    var ignoreObserver = false
    
    /// The Collection view displaying files.
    @IBOutlet weak var collectionView: UICollectionView!
    
    /// Returns the URL for iCloud Drive folder.
    static let iCloudContainerURL = FileManager.default.url(forUbiquityContainerIdentifier: nil)?.appendingPathComponent("Documents")
    
    /// Returns the URL for local folder.
    static let localContainerURL = FileManager.default.urls(for: .documentDirectory, in: .allDomainsMask)[0]
    
    /// Sets directory without affecting navigation bar.
    ///
    /// - Parameters:
    ///     - directory: The directory to show files.
    func setDirectory(_ directory: URL) {
        callDirectorySetter = false
        self.directory = directory
        collectionView?.reloadData()
    }
    
    private var callDirectorySetter = true
    
    /// The directory to show files.
    var directory = localContainerURL {
        didSet {
            if callDirectorySetter {
                title = directory.lastPathComponent
                navigationItem.largeTitleDisplayMode = .never
                collectionView?.reloadData()
            } else {
                callDirectorySetter = true
            }
        }
    }
    
    /// All scripts and directories in current directory.
    var scripts = [URL]()
    
    private var scripts_: [URL] {
        var files = self.files
        
        var i = 0
        for file in files {
            var isDir: ObjCBool = false
            if FileManager.default.fileExists(atPath: file.path, isDirectory: &isDir) {
                if ((file.pathExtension.lowercased() != "py" && !isDir.boolValue) || (file.lastPathComponent == "__pycache__")) || file.lastPathComponent.hasPrefix(".") {
                    files.remove(at: i)
                } else {
                    i += 1
                }
            } else {
                files.remove(at: i)
            }
            
            if let iCloud = DocumentBrowserViewController.iCloudContainerURL, file.path.hasPrefix(iCloud.path) {
                do {
                    try FileManager.default.startDownloadingUbiquitousItem(at: file)
                } catch {
                    print(error.localizedDescription)
                }
            }
        }
        
        return files
    }
    
    private var files: [URL] {
        var files = (try? FileManager.default.contentsOfDirectory(at: directory, includingPropertiesForKeys: nil, options: .skipsHiddenFiles)) ?? []
        
        if let iCloudURL = DocumentBrowserViewController.iCloudContainerURL, directory.pathComponents == DocumentBrowserViewController.localContainerURL.pathComponents {
            
            if !FileManager.default.fileExists(atPath: iCloudURL.path) {
                try? FileManager.default.createDirectory(at: iCloudURL, withIntermediateDirectories: true, attributes: nil)
            }
            
            files = ((try? FileManager.default.contentsOfDirectory(at: iCloudURL, includingPropertiesForKeys: nil, options: .init(rawValue: 0))) ?? [])+files
        }
        
        return files
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
            let script: URL
            if self.directory == DocumentBrowserViewController.localContainerURL {
                script = (DocumentBrowserViewController.iCloudContainerURL ?? self.directory).appendingPathComponent(filename).appendingPathExtension("py")
            } else {
                script = self.directory.appendingPathComponent(filename).appendingPathExtension("py")
            }
            do {
                guard let url = Bundle.main.url(forResource: "Untitled", withExtension: "py") else {
                    return
                }
                if FileManager.default.createFile(atPath: script.path, contents: try Data(contentsOf: url), attributes: nil) {
                    var i = 0
                    for file in self.scripts { // For loop needed because the folder is not found with `Array.firstIndex(of:)`
                        if file.lastPathComponent == script.lastPathComponent {
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
            let folder: URL
            if self.directory == DocumentBrowserViewController.localContainerURL {
                folder = (DocumentBrowserViewController.iCloudContainerURL ?? self.directory).appendingPathComponent(filename)
            } else {
                folder = self.directory.appendingPathComponent(filename)
            }
            do {
                try FileManager.default.createDirectory(at: folder, withIntermediateDirectories: true, attributes: nil)
                var i = 0
                for file in self.scripts { // For loop needed because the folder is not found with `Array.firstIndex(of:)`
                    if file.lastPathComponent == folder.lastPathComponent {
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
        
        sheet.view.tintColor = UIView().tintColor
        
        sheet.addAction(UIAlertAction(title: Localizable.Help.theme, style: .default, handler: { (_) in
            if let vc = UIStoryboard(name: "Theme Chooser", bundle: Bundle.main).instantiateInitialViewController() {
                self.present(vc, animated: true, completion: nil)
            }
        }))
                
        sheet.addAction(UIAlertAction(title: Localizable.Help.help, style: .default, handler: { _ in
            if let helpURL = Bundle.main.url(forResource: "Help", withExtension: "py") {
                self.openDocument(helpURL, run: false)
            }
        }))
        
        sheet.addAction(UIAlertAction(title: Localizable.Help.documentation, style: .default, handler: { _ in
            self.present(UINavigationController(rootViewController: DocumentationViewController()), animated: true, completion: nil)
        }))
        sheet.addAction(UIAlertAction(title: Localizable.Help.acknowledgments, style: .default, handler: { _ in
            self.present(UINavigationController(rootViewController: AcknowledgmentsViewController()), animated: true, completion: nil)
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
                
        let doc = PyDocument(fileURL: document)
        let editor = EditorViewController(document: doc)
        let contentVC = ConsoleViewController.visible
        contentVC.view.backgroundColor = .white
        
        let tintColor = ConsoleViewController.choosenTheme.tintColor ?? UIColor(named: "TintColor") ?? .orange
        
        let splitVC = EditorSplitViewController()
        let navVC = ThemableNavigationController(rootViewController: splitVC)
        
        splitVC.separatorColor = tintColor
        splitVC.separatorSelectedColor = tintColor
        splitVC.editor = editor
        splitVC.console = contentVC
        splitVC.view.backgroundColor = .white
        
        navVC.toolbar.setShadowImage(UIImage(), forToolbarPosition: .any)
        navVC.navigationBar.shadowImage = UIImage()
        navVC.navigationBar.isTranslucent = false
        navVC.modalTransitionStyle = .crossDissolve
        
        UIApplication.shared.keyWindow?.rootViewController?.present(navVC, animated: true, completion: {
            
            NotificationCenter.default.removeObserver(splitVC)
            
            splitVC.firstChild = editor
            splitVC.secondChild = contentVC
            
            if run {
                DispatchQueue.main.asyncAfter(deadline: .now()+0.2, execute: {
                    editor.run()
                })
            }
            completion?()
        })
    }
    
    /// Opens pip installer.
    @IBAction func pip(_ sender: Any) {
        if let url = Bundle.main.url(forResource: "installer", withExtension: "py") {
            openDocument(url, run: true)
        }
    }
    
    /// Reloads browser.
    func reloadData() {
        scripts = scripts_
        collectionView.reloadData()
    }
    
    /// The visible instance
    static var visible: DocumentBrowserViewController? {
        return ((UIApplication.shared.keyWindow?.rootViewController as? UITabBarController)?.viewControllers?.first as? UINavigationController)?.visibleViewController as? DocumentBrowserViewController
    }
    
    // MARK: - View controller
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        navigationController?.view.backgroundColor = .white
        navigationController?.navigationBar.shadowImage = UIImage()
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        scripts = scripts_
        
        navigationController?.view.backgroundColor = .black
        
        collectionView.dragDelegate = self
        collectionView.dropDelegate = self
        collectionView.dragInteractionEnabled = true
        collectionView.reloadData()
        
        // Directory observer
        DispatchQueue.global(qos: .background).async {
            var files = self.scripts_
            while true {
                if self.stopObserver_ {
                    self.stopObserver_ = false
                    break
                }
                
                if files != self.scripts_ {
                    
                    for file in files {
                        if !FileManager.default.fileExists(atPath: file.path) {
                            CSSearchableIndex.default().deleteSearchableItems(withDomainIdentifiers: [RelativePathForScript(file)], completionHandler: { error in
                                print(error?.localizedDescription ?? "")
                            })
                        }
                    }
                    
                    files = self.scripts_
                    self.scripts = files
                    
                    if self.ignoreObserver {
                        self.ignoreObserver = false
                    } else {
                        DispatchQueue.main.async {
                            self.collectionView.reloadData()
                        }
                    }
                }
                
                Thread.sleep(forTimeInterval: 0.1)
            }
        }
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        
        stopObserver()
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        
        stopObserver()
    }
    
    override var keyCommands: [UIKeyCommand]? {
        return [
            UIKeyCommand(input: "n", modifierFlags: .command, action: #selector(create(_:)), discoverabilityTitle: Localizable.Creation.createScript),
            UIKeyCommand(input: "n", modifierFlags: [.command, .shift], action: #selector(createFolder(_:)), discoverabilityTitle: Localizable.Creation.createFolder)
        ]
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
        
        if cell.file != scripts[indexPath.row], let str = try? String(contentsOf: scripts[indexPath.row]), let textView = cell.previewContainerView?.subviews.first as? SyntaxTextView {
            
            var smallerCode = ""
            
            for (i, line) in str.components(separatedBy: "\n").enumerated() {
                
                guard i < 20 else {
                    break
                }
                
                smallerCode += line+"\n"
            }
            
            if textView.text != smallerCode {
                cell.file = scripts[indexPath.row]
            }
        } else {
            cell.file = scripts[indexPath.row]
        }
        cell.titleView.text = scripts[indexPath.row].deletingPathExtension().lastPathComponent
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
