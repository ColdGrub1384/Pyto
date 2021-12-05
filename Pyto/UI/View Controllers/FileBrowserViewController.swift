//
//  FileBrowserViewController.swift
//  SeeLess
//
//  Created by Emma Labbé on 16-09-19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit
import QuickLook
import MobileCoreServices
import Dynamic
import UniformTypeIdentifiers

/// The file browser used to manage files inside a project.
@objc public class FileBrowserViewController: UITableViewController, UIDocumentPickerDelegate, UIContextMenuInteractionDelegate, UITableViewDragDelegate, UITableViewDropDelegate, UISearchResultsUpdating {
    
    /// Returns the URL for iCloud Drive folder.
    @objc static let iCloudContainerURL = FileManager.default.url(forUbiquityContainerIdentifier: nil)?.appendingPathComponent("Documents")
    
    /// Returns the URL for local folder.
    @objc static let localContainerURL = FileManager.default.urls(for: .documentDirectory, in: .allDomainsMask)[0]
    
    private struct LocalFile {
        var url: URL
        var directory: URL
    }
    
    /// A type of file.
    enum FileType {
        
        /// Python source.
        case python
        
        /// Blank file.
        case blank
        
        /// Folder.
        case folder
    }
        
    private var folderObserver: DispatchSourceFileSystemObject?
    
    private var descriptor: Int32?
    
    private var filteredResults: [URL]? {
        didSet {
            DispatchQueue.main.async { [weak self] in
                self?.tableView.reloadData()
            }
        }
    }
    
    /// FIles in the directory.
    var files = [URL]()
        
    /// The directory to browse.
    var directory: URL! {
        didSet {
            title = directory != FileBrowserViewController.iCloudContainerURL ? FileManager.default.displayName(atPath: directory.path) : "iCloud Drive"
            load()
        }
    }
    
    /// Loads directory.
    func load() {
        tableView.backgroundView = nil
        do {
            var files = [URL]()
            for file in try FileManager.default.contentsOfDirectory(at: directory, includingPropertiesForKeys: nil, options: []) {
                if file.lastPathComponent != ".DS_Store" && file.lastPathComponent != ".Trash" {
                    files.append(file)
                }
            }
            self.files = files
        } catch {
            files = []
            
            
            let textView = UITextView()
            textView.isEditable = false
            textView.text = error.localizedDescription
            tableView.backgroundView = textView
        }
        
        tableView.reloadData()
    }
    
    /// Creates a file with given file type.
    ///
    /// - Parameters:
    ///     - type: The file type.
    func createFile(type: FileType) {
        
        if type == .python {
            let navVC = UIStoryboard(name: "Template Chooser", bundle: nil).instantiateInitialViewController()!
            ((navVC as? UINavigationController)?.topViewController as? TemplateChooserTableViewController)?.importHandler = { url, _ in
                if let url = url {
                    do {
                        try FileManager.default.copyItem(at: url, to: self.directory.appendingPathComponent(url.lastPathComponent))
                    } catch {
                        present(error: error)
                    }
                }
            }
            
            self.present(navVC, animated: true, completion: nil)
            
            return
        }
        
        func present(error: Error) {
            let alert = UIAlertController(title: Localizable.Errors.errorCreatingFile, message: error.localizedDescription, preferredStyle: .alert)
            alert.addAction(UIAlertAction(title: Localizable.cancel, style: .cancel, handler: nil))
            self.present(alert, animated: true, completion: nil)
        }
        
        let alert = UIAlertController(title: (type == .python ? Localizable.Creation.createScriptTitle : (type == .folder ? Localizable.Creation.createFolderTitle : Localizable.Creation.createFileTitle)), message: (type == .folder ? Localizable.Creation.typeFolderName : Localizable.Creation.typeFileName), preferredStyle: .alert)
        
        var textField: UITextField!
        
        alert.addAction(UIAlertAction(title: Localizable.create, style: .default, handler: { (_) in
            if true {
                do {
                    var name = textField.text ?? Localizable.untitled
                    if name.replacingOccurrences(of: " ", with: "").isEmpty {
                        name =  Localizable.untitled
                    }
                    
                    if type == .folder {
                        try FileManager.default.createDirectory(at: self.directory.appendingPathComponent(name), withIntermediateDirectories: true, attributes: nil)
                    } else {
                        if !FileManager.default.createFile(atPath: self.directory.appendingPathComponent(name).path, contents: "".data(using: .utf8), attributes: nil) {
                            throw NSError(domain: "SeeLess.errorCreatingFile", code: 1, userInfo: [NSLocalizedDescriptionKey : "Error creating file"])
                        }
                    }
                } catch {
                    present(error: error)
                }
            }
        }))
        
        alert.addAction(UIAlertAction(title: Localizable.cancel, style: .cancel, handler: nil))
        
        alert.addTextField { (_textField) in
            textField = _textField
            textField.placeholder = Localizable.untitled
        }
        
        self.present(alert, animated: true, completion: nil)
    }
    
    /// Creates a new folder.
    @objc func createFolder(_ sender: UIBarButtonItem) {
        self.createFile(type: .folder)
    }
    
    /// Creates a new file.
    @objc func createNewFile(_ sender: UIBarButtonItem) {
        let alert = UIAlertController(title: Localizable.Creation.createFileTitle, message: nil, preferredStyle: .actionSheet)
        
        alert.addAction(UIAlertAction(title: Localizable.Creation.pythonScript, style: .default, handler: { (_) in
            self.createFile(type: .python)
        }))
        
        alert.addAction(UIAlertAction(title: Localizable.Creation.blankFile, style: .default, handler: { (_) in
            self.createFile(type: .blank)
        }))
        
        alert.addAction(UIAlertAction(title: Localizable.Creation.importFromFiles, style: .default, handler: { (_) in
            let vc = UIDocumentPickerViewController.init(forOpeningContentTypes: [.item], asCopy: true)
            vc.allowsMultipleSelection = true
            vc.delegate = self
            self.present(vc, animated: true, completion: nil)
        }))
        
        alert.addAction(UIAlertAction(title: Localizable.cancel, style: .cancel, handler: nil))
        
        alert.popoverPresentationController?.barButtonItem = sender
        present(alert, animated: true, completion: nil)
    }
    
    /// Closes the View Controller.
    @objc func close() {
        dismiss(animated: true, completion: nil)
    }
    
    /// Returns to the file browser.
    @objc func goToFiles() {
        let presenting = presentingViewController
        dismiss(animated: true) {
            presenting?.dismiss(animated: true, completion: nil)
        }
    }
    
    private var searchController = UISearchController(searchResultsController: nil)
    
    @objc func search() {
        searchController.isActive = true
        searchController.searchBar.becomeFirstResponder()
    }
    
    // MARK: - Table view controller
    
    private var alreadyShown = false
    
    public override var keyCommands: [UIKeyCommand]? {
        return [UIKeyCommand.command(input: "f", modifierFlags: .command, action: #selector(search), discoverabilityTitle: Localizable.find)]
    }
    
    public override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        tableView.reloadData()
        
        if navigationController?.viewControllers.first == self && !isiOSAppOnMac {
            var items = [UIBarButtonItem]()
            if let parent = navigationController?.presentingViewController, parent is EditorViewController || parent is EditorSplitViewController || parent is EditorSplitViewController.NavigationController {
                items.append(UIBarButtonItem(image: EditorSplitViewController.gridImage, style: .plain, target: self, action: #selector(goToFiles)))
            }
            navigationItem.leftBarButtonItems = items
        }
        
        if !alreadyShown {
            alreadyShown = true
            
            DispatchQueue.main.async { [weak self] in
                self?.navigationController?.navigationBar.sizeToFit()
            }
        }
    }
    
    public override func viewDidLoad() {
        super.viewDidLoad()
        
        view.backgroundColor = .systemBackground
        
        tableView.contentInsetAdjustmentBehavior = .never
        edgesForExtendedLayout = []
        
        clearsSelectionOnViewWillAppear = true
        tableView.tableFooterView = UIView()
        
        tableView.dragDelegate = self
        tableView.dropDelegate = self
        
        searchController.searchResultsUpdater = self
        searchController.obscuresBackgroundDuringPresentation = false
        searchController.searchBar.placeholder = NSLocalizedString("Search", bundle: Bundle(for: UIApplication.self), comment: "")
        navigationItem.searchController = searchController
        definesPresentationContext = true
        
        navigationItem.rightBarButtonItems = [
            UIBarButtonItem(barButtonSystemItem: .add, target: self, action: #selector(createNewFile(_:))),
            UIBarButtonItem(image: UIImage(systemName: "folder.badge.plus"), style: .plain, target: self, action: #selector(createFolder(_:)))
        ]
    }
    
    public override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        becomeFirstResponder()
        
        descriptor = open(directory.path, O_EVTONLY)
        folderObserver = DispatchSource.makeFileSystemObjectSource(fileDescriptor: descriptor!, eventMask: .write, queue: DispatchQueue.main)
        folderObserver?.setEventHandler {
            self.load()
        }
        folderObserver?.resume()
    }
    
    public override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        
        folderObserver?.cancel()
        if let descriptor = descriptor {
            Darwin.close(descriptor)
        }
    }
    
    public override func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return !isiOSAppOnMac ? 80 : super.tableView(tableView, heightForRowAt: indexPath)
    }
        
    public override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return (filteredResults ?? files).count
    }
    
    public override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let files = filteredResults ?? self.files
        
        let cell = UITableViewCell(style: !isiOSAppOnMac ? .subtitle : .default, reuseIdentifier: nil)
        
        let icloud = (files[indexPath.row].pathExtension == "icloud" && files[indexPath.row].lastPathComponent.hasPrefix("."))
        
        if icloud {
            var name = files[indexPath.row].deletingPathExtension().lastPathComponent
            name.removeFirst()
            cell.textLabel?.text = name
        } else {
            cell.textLabel?.text = files[indexPath.row].lastPathComponent
        }
        
        do {
            if let modificationDate = try FileManager.default.attributesOfItem(atPath: files[indexPath.row].path)[FileAttributeKey.modificationDate] as? Date {
                let formatter = DateFormatter()
                formatter.dateStyle = .full
                formatter.timeStyle = .short
                cell.detailTextLabel?.text = formatter.string(from: modificationDate)
            }
        } catch {
            print(error.localizedDescription)
        }
        
        var isDir: ObjCBool = false
        if FileManager.default.fileExists(atPath: files[indexPath.row].path, isDirectory: &isDir) && isDir.boolValue {
            cell.imageView?.image = UIImage(systemName: "folder.fill")
            cell.accessoryType = .disclosureIndicator
        } else {
            if !icloud {
                cell.imageView?.image = UIImage(systemName: "doc.fill")
            } else {
                cell.imageView?.image = UIImage(systemName: "icloud.and.arrow.down.fill")
            }
            cell.accessoryType = .none
        }
        
        cell.contentView.alpha = files[indexPath.row].lastPathComponent.hasPrefix(".") ? 0.5 : 1
        
        let interaction = UIContextMenuInteraction(delegate: self)
        cell.addInteraction(interaction)
        
        return cell
    }
    
    private var lastDoc: UIDocument?
    
    public override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        
        let files = filteredResults ?? self.files
        
        var isDir: ObjCBool = false
        if FileManager.default.fileExists(atPath: files[indexPath.row].path, isDirectory: &isDir) && isDir.boolValue {
            let browser = FileBrowserViewController()
            browser.navigationItem.largeTitleDisplayMode = .never
            browser.directory = files[indexPath.row]
            navigationController?.pushViewController(browser, animated: true)
        } else {
            
            let icloud = (files[indexPath.row].pathExtension == "icloud" && files[indexPath.row].lastPathComponent.hasPrefix("."))
            
            var last = files[indexPath.row].deletingPathExtension().lastPathComponent
            last.removeFirst()
            
            let url: URL
            if icloud {
                url = files[indexPath.row].deletingLastPathComponent().appendingPathComponent(last)
            } else {
                url = files[indexPath.row]
            }
            
            if url.pathExtension.lowercased() == "py" || url.pathExtension.lowercased() == "pyhtml" || (try? url.resourceValues(forKeys: [.contentTypeKey]))?.contentType?.conforms(to: .text) == true {
                
                if let editor = ((splitViewController as? SidebarSplitViewController)?.sidebar?.editor?.vc as? EditorSplitViewController)?.editor {
                    
                    (editor.parent as? EditorSplitViewController)?.killREPL()
                    
                    editor.document?.editor = nil
                    
                    editor.save { (_) in
                        editor.document?.close(completionHandler: { (_) in
                            let document = PyDocument(fileURL: url)
                            document.open { (_) in
                                
                                #if !Xcode11
                                if #available(iOS 14.0, *) {
                                    RecentDataSource.shared.recent.append(url)
                                }
                                #endif
                                
                                editor.isDocOpened = false
                                editor.parent?.title = document.fileURL.deletingPathExtension().lastPathComponent
                                editor.document = document
                                editor.viewWillAppear(false)
                                editor.appKitWindow.representedURL = document.fileURL
                                
                                self.showDetailViewController(UINavigationController(rootViewController: editor.parent!), sender: self)
                            }
                        })
                    }
                } else {
                    let splitVC = splitViewController as? SidebarSplitViewController
                    if let editor = splitVC?.sidebar?.openDocument(url, run: false, folder: self.directory) {
                        (splitViewController as? SidebarSplitViewController)?.sidebar?.editor = SidebarViewController.NavigationController(rootViewController: editor)
                        let navVC = UINavigationController(rootViewController: editor)
                        navVC.navigationBar.prefersLargeTitles = false
                        editor.navigationItem.largeTitleDisplayMode = .never
                        showDetailViewController(navVC, sender: self)
                    }
                }
            } else {
                
                class DataSource: NSObject, QLPreviewControllerDataSource {
                    
                    var url: URL
                    
                    init(url: URL) {
                        self.url = url
                    }
                    
                    func numberOfPreviewItems(in controller: QLPreviewController) -> Int {
                        return 1
                    }
                    
                    func previewController(_ controller: QLPreviewController, previewItemAt index: Int) -> QLPreviewItem {
                        return url as QLPreviewItem
                    }
                }
                
                if !isiOSAppOnMac {
                    let doc = PyDocument(fileURL: url)
                    doc.open { [weak self] (_) in
                        let dataSource = DataSource(url: doc.fileURL)
                        
                        let vc = QLPreviewController()
                        vc.dataSource = dataSource
                        self?.present(vc, animated: true, completion: nil)
                    }
                } else {
                    Dynamic.NSWorkspace.sharedWorkspace.openURL(url)
                }
            }
        }
    }
    
    // MARK: - Table view drag delegate
    
    public func tableView(_ tableView: UITableView, itemsForBeginning session: UIDragSession, at indexPath: IndexPath) -> [UIDragItem] {
        
        let file = files[indexPath.row]
        
        let item = UIDragItem(itemProvider: NSItemProvider())
        item.itemProvider.registerFileRepresentation(forTypeIdentifier: (try? file.resourceValues(forKeys: [.typeIdentifierKey]))?.typeIdentifier ?? kUTTypeItem as String, fileOptions: .openInPlace, visibility: .all) { (handler) -> Progress? in
            
            handler(file, true, nil)
            
            let progress = Progress(totalUnitCount: 1)
            progress.completedUnitCount = 1
            return progress
        }
        
        item.itemProvider.suggestedName = file.lastPathComponent
        item.localObject = LocalFile(url: file, directory: directory)
        
        return [item]
    }
    
    // MARK: - Table view drop delegate
    
    public func tableView(_ tableView: UITableView, canHandle session: UIDropSession) -> Bool {
        return session.hasItemsConforming(toTypeIdentifiers: [kUTTypeItem as String])
    }
    
    public func tableView(_ tableView: UITableView, performDropWith coordinator: UITableViewDropCoordinator) {
        
        let files = filteredResults ?? self.files
        
        guard let destination = ((coordinator.destinationIndexPath != nil && coordinator.proposal.intent == .insertIntoDestinationIndexPath) ? files[coordinator.destinationIndexPath!.row] : self.directory) else {
            return
        }
        
        for item in coordinator.items {
            if let file = item.dragItem.localObject as? LocalFile {
                
                let fileName = file.url.lastPathComponent
                
                if coordinator.proposal.operation == .move {
                    try? FileManager.default.moveItem(at: file.url, to: destination.appendingPathComponent(fileName))
                } else if coordinator.proposal.operation == .copy {
                    try? FileManager.default.copyItem(at: file.url, to: destination.appendingPathComponent(fileName))
                }
                
            } else if item.dragItem.itemProvider.hasItemConformingToTypeIdentifier(kUTTypeItem as String) {
                
                item.dragItem.itemProvider.loadInPlaceFileRepresentation(forTypeIdentifier: kUTTypeItem as String, completionHandler: { (file, inPlace, error) in
                    
                    if let error = error {
                        print(error.localizedDescription)
                    }
                    
                    if let file = file {
                        
                        let fileName = file.lastPathComponent
                        
                        _ = file.startAccessingSecurityScopedResource()
                        if coordinator.proposal.operation == .move {
                            try? FileManager.default.moveItem(at: file, to: destination.appendingPathComponent(fileName))
                        } else if coordinator.proposal.operation == .copy {
                            try? FileManager.default.copyItem(at: file, to: destination.appendingPathComponent(fileName))
                        }
                        
                        file.stopAccessingSecurityScopedResource()
                        
                        DispatchQueue.main.async { [weak self] in
                            self?.load()
                        }
                    }
                })
            }
        }
    }
    
    public func tableView(_ tableView: UITableView, dropSessionDidUpdate session: UIDropSession, withDestinationIndexPath destinationIndexPath: IndexPath?) -> UITableViewDropProposal {
        
        if let local = session.items.first?.localObject as? LocalFile, local.url.deletingLastPathComponent() != directory {
            return UITableViewDropProposal(operation: .move)
        }
        
        var isDir: ObjCBool = false
        if destinationIndexPath == nil || !(destinationIndexPath != nil && files.indices.contains(destinationIndexPath!.row) && FileManager.default.fileExists(atPath: files[destinationIndexPath!.row].path, isDirectory: &isDir) && isDir.boolValue) {
            
            if destinationIndexPath == nil && (session.items.first?.localObject as? LocalFile)?.url.deletingLastPathComponent() == directory {
                return UITableViewDropProposal(operation: .forbidden)
            } else if session.items.first?.localObject == nil || (session.items.first?.localObject as? LocalFile)?.directory != directory {
                return UITableViewDropProposal(operation: .copy, intent: .insertAtDestinationIndexPath)
            } else {
                return UITableViewDropProposal(operation: .move, intent: .insertAtDestinationIndexPath)
            }
        } else if destinationIndexPath != nil && files.indices.contains(destinationIndexPath!.row) && FileManager.default.fileExists(atPath: files[destinationIndexPath!.row].path, isDirectory: &isDir) && isDir.boolValue && (session.items.first?.localObject as? URL)?.deletingLastPathComponent() == files[destinationIndexPath!.row] {
            return UITableViewDropProposal(operation: .forbidden)
        } else if destinationIndexPath == nil && (session.items.first?.localObject as? LocalFile)?.url.deletingLastPathComponent() == directory {
            return UITableViewDropProposal(operation: .forbidden)
        } else if session.items.first?.localObject == nil {
            return UITableViewDropProposal(operation: .copy, intent: .insertIntoDestinationIndexPath)
        } else {
            return UITableViewDropProposal(operation: .move, intent: .insertIntoDestinationIndexPath)
        }
    }
        
    // MARK: - Document picker view controller delegate
    
    public func documentPicker(_ controller: UIDocumentPickerViewController, didPickDocumentsAt urls: [URL]) {
        
        func move(at index: Int) {
            do {
                try FileManager.default.moveItem(at: urls[index], to: directory.appendingPathComponent(urls[index].lastPathComponent))
                
                if urls.indices.contains(index+1) {
                    move(at: index+1)
                } else {
                    tableView.reloadData()
                }
                
            } catch {
                let alert = UIAlertController(title: Localizable.Errors.errorCreatingFile, message: error.localizedDescription, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: Localizable.cancel, style: .cancel, handler: { _ in
                    if urls.indices.contains(index+1) {
                        move(at: index+1)
                    } else {
                        self.tableView.reloadData()
                    }
                }))
                present(alert, animated: true, completion: nil)
            }
        }
        
        move(at: 0)
    }
    
    // MARK: - Context menu interaction delegate
    
    @available(iOS 13.0, *)
    public func contextMenuInteraction(_ interaction: UIContextMenuInteraction, configurationForMenuAtLocation location: CGPoint) -> UIContextMenuConfiguration? {
        
        let files = filteredResults ?? self.files
        
        guard let cell = interaction.view as? UITableViewCell else {
            return nil
        }
        
        let share = UIAction(title: Localizable.MenuItems.share, image: UIImage(systemName: "square.and.arrow.up")) { action in
            
            guard let index = self.tableView.indexPath(for: cell), files.indices.contains(index.row) else {
                return
            }
            
            let activityVC = UIActivityViewController(activityItems: [files[index.row]], applicationActivities: nil)
            activityVC.popoverPresentationController?.sourceView = cell
            activityVC.popoverPresentationController?.sourceRect = cell.bounds
            self.present(activityVC, animated: true, completion: nil)
        }
        
        let saveTo: UIAction
        if !isiOSAppOnMac {
            saveTo = UIAction(title: Localizable.MenuItems.saveToFiles, image: UIImage(systemName: "folder")) { action in
                
                guard let index = self.tableView.indexPath(for: cell), files.indices.contains(index.row) else {
                    return
                }
                
                self.present(UIDocumentPickerViewController(forExporting: [files[index.row]], asCopy: true), animated: true, completion: nil)
            }
        } else {
            saveTo = UIAction(title: NSLocalizedString("Show in Finder", comment: "The 'Show in Finder' menu item"), image: UIImage(systemName: "folder")) { action in
                
                guard let index = self.tableView.indexPath(for: cell), files.indices.contains(index.row) else {
                    return
                }
                
                Dynamic.NSWorkspace.sharedWorkspace.activateFileViewerSelectingURLs([files[index.row]])
            }
        }
                
        let rename = UIAction(title: Localizable.MenuItems.rename, image: UIImage(systemName: "pencil")) { action in
            
            guard let index = self.tableView.indexPath(for: cell), files.indices.contains(index.row) else {
                return
            }
            
            let file = files[index.row]
            
            var textField: UITextField!
            let alert = UIAlertController(title: "\(Localizable.MenuItems.rename) '\(file.lastPathComponent)'", message: Localizable.Creation.typeFileName, preferredStyle: .alert)
            
            alert.addAction(UIAlertAction(title: Localizable.MenuItems.rename, style: .default, handler: { (_) in
                do {
                    
                    let name = textField.text ?? ""
                    
                    if !name.isEmpty {
                        try FileManager.default.moveItem(at: file, to: file.deletingLastPathComponent().appendingPathComponent(name))
                    }
                } catch {
                    let alert = UIAlertController(title: Localizable.Errors.errorRenamingFile, message: error.localizedDescription, preferredStyle: .alert)
                    alert.addAction(UIAlertAction(title: Localizable.cancel, style: .cancel, handler: nil))
                    self.present(alert, animated: true, completion: nil)
                }
            }))
            
            alert.addAction(UIAlertAction(title: Localizable.cancel, style: .cancel, handler: nil))
            alert.addTextField { (_textField) in
                textField = _textField
                textField.placeholder = Localizable.untitled
                textField.text = file.lastPathComponent
            }
            
            self.present(alert, animated: true, completion: nil)
        }
        
        let delete = UIAction(title: Localizable.MenuItems.remove, image: UIImage(systemName: "trash.fill"), attributes: .destructive) { action in
            
            guard let index = self.tableView.indexPath(for: cell), files.indices.contains(index.row) else {
                return
            }
            
            do {
                try FileManager.default.removeItem(at: files[index.row])
                
                if self.filteredResults != nil {
                    self.filteredResults?.remove(at: index.row)
                } else {
                    self.files.remove(at: index.row)
                }
                
                self.tableView.deleteRows(at: [IndexPath(row: index.row, section: 0)], with: .automatic)
            } catch {
                let alert = UIAlertController(title: Localizable.Errors.errorRemovingFile, message: error.localizedDescription, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: Localizable.cancel, style: .cancel, handler: nil))
                self.present(alert, animated: true, completion: nil)
            }
        }
        
        let run = UIAction(title: Localizable.MenuItems.run, image: UIImage(systemName: "play")) { action in
            
            guard let index = self.tableView.indexPath(for: cell), files.indices.contains(index.row) else {
                return
            }
            
            let runner = ScriptRunnerViewController(scriptURL: files[index.row])
            let navVC = UINavigationController(rootViewController: runner)
            navVC.modalPresentationStyle = .formSheet
            
            if #available(iOS 15.0, *) {
                if let presentationController = navVC.presentationController as? UISheetPresentationController {
                    presentationController.prefersGrabberVisible = true
                    presentationController.detents = [.medium(), .large()]
                }
            }
            
            self.present(navVC, animated: true, completion: nil)
        }

        return UIContextMenuConfiguration(identifier: nil, previewProvider: nil) { (_) -> UIMenu? in
            
            guard let index = self.tableView.indexPath(for: cell), files.indices.contains(index.row) else {
                return nil
            }
            
            return UIMenu(title: cell.textLabel?.text ?? "", children: ((files[index.row].pathExtension.lowercased() == "py" || files[index.row].pathExtension.lowercased() == "pyhtml") ? [run] : [])+[share, saveTo, rename, delete])
        }
    }
    
    // MARK: - Search results updating
    
    private var lastSearch: String?
    
    public func updateSearchResults(for searchController: UISearchController) {
                
        let text = searchController.searchBar.text
        
        guard text != lastSearch else {
            return
        }
        
        lastSearch = text
        
        if text == nil || text == "" {
            filteredResults = nil
        } else {
            var results = [URL]()
            for file in files {
                if file.lastPathComponent.lowercased().contains(text!.lowercased()) {
                    results.append(file)
                }
            }
            filteredResults = results
        }
    }
}
