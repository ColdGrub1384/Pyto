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
import WebKit
import QuickLook

/// A protocol to set as `DocumentBrowserViewController.delegate`. Used if you want to pick a script.
protocol DocumentBrowserViewControllerDelegate {
    
    /// Called when a Python script is picked. Will not be called for other file types.
    ///
    /// - Parameters:
    ///     - path: The path of the script picked.
    func documentBrowserViewController(_ documentBrowserViewController: DocumentBrowserViewController, didPickScriptAtPath path: String)
}

/// The main file browser used to edit scripts.
@objc class DocumentBrowserViewController: UIViewController, UICollectionViewDataSource, UICollectionViewDelegate, UICollectionViewDropDelegate, UICollectionViewDragDelegate, QLPreviewControllerDataSource, UIDocumentPickerDelegate {
    
    /// Stops file observer.
    func stopObserver() {
        stopObserver_ = true
    }
    
    private var stopObserver_ = false
    
    /// Store here `EditorSplitViewController`s because it crashes on dealloc. RIP memory
    private static var splitVCs = [UIViewController?]()
    
    /// Set it if you want to implement a custom file picker.
    var delegate: DocumentBrowserViewControllerDelegate? {
        didSet {
            if delegate != nil {
                navigationItem.leftBarButtonItems = []
                navigationItem.rightBarButtonItems = []
                view.viewWithTag(2)?.alpha = 0.5
                view.viewWithTag(2)?.isUserInteractionEnabled = false
            }
        }
    }
    
    /// If set to `true`, the files observer will ignore next change.
    var ignoreObserver = false
    
    /// The Collection view displaying files.
    @IBOutlet weak var collectionView: UICollectionView!
    
    /// Returns the URL for iCloud Drive folder.
    @objc static let iCloudContainerURL = FileManager.default.url(forUbiquityContainerIdentifier: nil)?.appendingPathComponent("Documents")
    
    /// Returns the URL for local folder.
    @objc static let localContainerURL = FileManager.default.urls(for: .documentDirectory, in: .allDomainsMask)[0]
    
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
    
    /// All scripts, directories and Markdown files in current directory.
    var scripts = [URL]()
    
    private var scripts_: [URL] {
        var files = self.files
        
        var i = 0
        for file in files {
            var isDir: ObjCBool = false
            if FileManager.default.fileExists(atPath: file.path, isDirectory: &isDir) {
                if file.lastPathComponent == "__pycache__" || file.lastPathComponent == "mpl-data" || file.lastPathComponent.hasPrefix(".") {
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
            
            if let welcome = Bundle.main.url(forResource: "Welcome to Pyto", withExtension: "md") {
                files.append(welcome)
            }
            
            if !FileManager.default.fileExists(atPath: iCloudURL.path) {
                try? FileManager.default.createDirectory(at: iCloudURL, withIntermediateDirectories: true, attributes: nil)
            }
            
            files = ((try? FileManager.default.contentsOfDirectory(at: iCloudURL, includingPropertiesForKeys: nil, options: .init(rawValue: 0))) ?? [])+files
        }
        
        return files
    }
    
    /// Creates script.
    @IBAction func create(_ sender: Any) {
        var textField: UITextField?
        let alert = UIAlertController(title: Localizable.Creation.createFileTitle, message: Localizable.Creation.typeScriptName, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: Localizable.Creation.createScript, style: .default, handler: { (_) in
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
        alert.addAction(UIAlertAction(title: Localizable.Creation.createMarkdown, style: .default, handler: { (_) in
            guard let filename = textField?.text else {
                return
            }
            guard !filename.hasSuffix(".") && !filename.isEmpty else {
                let alert = UIAlertController(title: Localizable.Errors.errorCreatingFile, message: Localizable.Errors.emptyName, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: Localizable.ok, style: .cancel, handler: nil))
                self.present(alert, animated: true, completion: nil)
                return
            }
            let file: URL
            if self.directory == DocumentBrowserViewController.localContainerURL {
                file = (DocumentBrowserViewController.iCloudContainerURL ?? self.directory).appendingPathComponent(filename).appendingPathExtension("md")
            } else {
                file = self.directory.appendingPathComponent(filename).appendingPathExtension("md")
            }
            do {
                guard let url = Bundle.main.url(forResource: "Untitled", withExtension: "md") else {
                    return
                }
                if FileManager.default.createFile(atPath: file.path, contents: try Data(contentsOf: url), attributes: nil) {
                    self.openDocument(file, run: false)
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
    
    /// Opens settings sheet.
    @IBAction func showSettings(_ sender: Any) {
        if let vc = UIStoryboard(name: "Settings", bundle: Bundle.main).instantiateInitialViewController() {
            present(vc, animated: true, completion: nil)
        }
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
    
    /// Opens the given file.
    ///
    /// - Parameters:
    ///     - document: The URL of the file or directory.
    ///     - tabBarController: If set, the document will be added to the value.
    ///     - run: Set to `true` to run the script inmediately.
    ///     - completion: Code called after presenting the UI.
    func openDocument(_ document: URL, onTabBarController tabBarController: UITabBarController? = nil, run: Bool, completion: (() -> Void)? = nil) {
        
        let tintColor = ConsoleViewController.choosenTheme.tintColor ?? UIColor(named: "TintColor") ?? .orange
        
        var isDir: ObjCBool = false
        
        guard document.pathExtension.lowercased() == "py" else {
            
            if document.pathExtension.lowercased() == "md" || document.pathExtension.lowercased() == "markdown" {
                _ = document.startAccessingSecurityScopedResource()
                
                let splitVC = MarkdownSplitViewController()
                splitVC.modalTransitionStyle = .crossDissolve
                splitVC.separatorColor = tintColor
                splitVC.separatorSelectedColor = tintColor
                splitVC.editor = PlainTextEditorViewController()
                splitVC.previewer = MarkdownPreviewController()
                splitVC.arrangement = .horizontal
                UIApplication.shared.keyWindow?.topViewController?.present(ThemableNavigationController(rootViewController: splitVC), animated: true, completion: {
                    
                    NotificationCenter.default.removeObserver(splitVC)
                    splitVC.editor.url = document
                    completion?()
                })
            } else if FileManager.default.fileExists(atPath: document.path, isDirectory: &isDir) && isDir.boolValue {
                guard let vc = storyboard?.instantiateViewController(withIdentifier: "Browser") as? DocumentBrowserViewController else {
                    return
                }
                vc.directory = document
                vc.delegate = delegate
                navigationController?.pushViewController(vc, animated: true)
                completion?()
            } else {
                previewingFile = document
                let controller = QLPreviewController()
                controller.dataSource = self
                UIApplication.shared.keyWindow?.topViewController?.present(controller, animated: true, completion: completion)
            }
            
            return
        }
        
        guard delegate == nil else {
            delegate?.documentBrowserViewController(self, didPickScriptAtPath: document.path)
            completion?()
            return
        }
        
        let isPip = (document.path == Bundle.main.path(forResource: "installer", ofType: "py"))
        
        if presentedViewController != nil {
            (((presentedViewController as? UITabBarController)?.viewControllers?.first as? UINavigationController)?.viewControllers.first as? EditorViewController)?.save()
            dismiss(animated: true) {
                self.openDocument(document, run: run, completion: completion)
            }
        }
                
        let editor = EditorViewController(document: document)
        editor.shouldRun = run
        let contentVC = ConsoleViewController.visible
        contentVC.view.backgroundColor = .white
        
        let splitVC = EditorSplitViewController()
        
        if isPip {
            splitVC.ratio = 0
        }
        
        DocumentBrowserViewController.splitVCs.append(EditorSplitViewController.visible)
        EditorSplitViewController.visible = splitVC
        let navVC = ThemableNavigationController(rootViewController: splitVC)
        
        splitVC.separatorColor = .clear
        splitVC.separatorSelectedColor = tintColor
        splitVC.editor = editor
        splitVC.console = contentVC
        splitVC.view.backgroundColor = .white
        
        navVC.toolbar.setShadowImage(UIImage(), forToolbarPosition: .any)
        navVC.navigationBar.shadowImage = UIImage()
        navVC.navigationBar.isTranslucent = false
        navVC.modalTransitionStyle = .crossDissolve
        
        stopObserver()
        
        func _completion() {
            NotificationCenter.default.removeObserver(splitVC)
            
            splitVC.firstChild = editor
            splitVC.secondChild = contentVC
            
            completion?()
        }
        
        if let tabBarController = tabBarController {
            tabBarController.viewControllers?.append(navVC)
            _completion()
        } else {
            UIApplication.shared.keyWindow?.topViewController?.present(navVC, animated: true, completion: _completion)
        }
    }
    
    /// Reloads browser.
    func reloadData() {
        scripts = scripts_
        collectionView.reloadData()
    }
    
    /// Imports script from another location.
    @IBAction func importScript(_ sender: Any) {
        let picker = UIDocumentPickerViewController(documentTypes: ["public.python-script"], in: .open)
        picker.delegate = self
        picker.allowsMultipleSelection = false
        present(picker, animated: true, completion: nil)
    }
    
    /// The visible instance
    static var visible: DocumentBrowserViewController? {
        return ((UIApplication.shared.keyWindow?.rootViewController as? UITabBarController)?.viewControllers?.first as? UINavigationController)?.visibleViewController as? DocumentBrowserViewController
    }
    
    // MARK: - View controller
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        if navigationController?.viewControllers.first != self, navigationItem.leftBarButtonItem?.action == #selector(importScript(_:)) {
            navigationItem.leftBarButtonItems?.remove(at: 0)
        }
        
        navigationController?.view.backgroundColor = .white
        navigationController?.navigationBar.shadowImage = UIImage()
        
        (collectionView.collectionViewLayout as? UICollectionViewFlowLayout)?.minimumInteritemSpacing = 100
        
        (UIApplication.shared.delegate as? AppDelegate)?.copyModules()
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
        stopObserver_ = false
        DispatchQueue.global().async {
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
        
        if (UIApplication.shared.delegate as? AppDelegate)?.shouldShowWelcomeMessage == true {
            (UIApplication.shared.delegate as? AppDelegate)?.shouldShowWelcomeMessage = false
            
            let welcomeAlert = UIAlertController(title: "Welcome to Pyto", message: "Pyto is a Python IDE. If you have any bug to report or something to suggest, you can contact me from settings page. If you like the app, please leave a review.", preferredStyle: .alert)
            welcomeAlert.addAction(UIAlertAction(title: Localizable.ok, style: .cancel, handler: nil))
            present(welcomeAlert, animated: true, completion: nil)
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
        
        DispatchQueue.global().async {
            let file = cell.file
            let script = self.scripts[indexPath.row]
            
            var textView: SyntaxTextView? {
                var value: SyntaxTextView?
                let semaphore = DispatchSemaphore(value: 0)
                DispatchQueue.main.async {
                    value = cell.previewContainerView?.subviews.first as? SyntaxTextView
                    semaphore.signal()
                }
                semaphore.wait()
                return value
            }
            
            if file != script, let str = try? String(contentsOf: script), let textView = textView {
                
                var smallerCode = ""
                
                for (i, line) in str.components(separatedBy: "\n").enumerated() {
                    
                    guard i < 9 else {
                        break
                    }
                    
                    smallerCode += line+"\n"
                }
                
                DispatchQueue.main.async {
                    if textView.text != smallerCode {
                        cell.file = script
                    }
                }
            } else if file != script {
                DispatchQueue.main.async {
                    cell.file = script
                }
            }
        }
        cell.titleView.text = scripts[indexPath.row].deletingPathExtension().lastPathComponent
        cell.documentBrowser = self
        
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
        openDocument(scripts[indexPath.row], run: false)
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
    
    // MARK: - Quick look
    
    /// The file to preview with quick look.
    var previewingFile: URL?
    
    func previewController(_ controller: QLPreviewController, previewItemAt index: Int) -> QLPreviewItem {
        return (previewingFile ?? URL(fileURLWithPath: "/")) as QLPreviewItem
    }
    
    func numberOfPreviewItems(in controller: QLPreviewController) -> Int {
        return 1
    }
    
    // MARK: - Document picker view controller delegate
    
    func documentPicker(_ controller: UIDocumentPickerViewController, didPickDocumentsAt urls: [URL]) {
        guard let url = urls.first else {
            return
        }
        _ = url.startAccessingSecurityScopedResource()
        openDocument(url, run: false)
    }
}
