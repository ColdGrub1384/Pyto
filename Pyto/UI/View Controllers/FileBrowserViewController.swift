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
import SwiftUI

fileprivate extension URL {
    
    func relativePath(from base: URL) -> String? {
        // Ensure that both URLs represent files:
        guard self.isFileURL && base.isFileURL else {
            return nil
        }

        //this is the new part, clearly, need to use workBase in lower part
        var workBase = base
        if workBase.pathExtension != "" {
            workBase = workBase.deletingLastPathComponent()
        }

        // Remove/replace "." and "..", make paths absolute:
        let destComponents = self.standardized.resolvingSymlinksInPath().pathComponents
        let baseComponents = workBase.standardized.resolvingSymlinksInPath().pathComponents

        // Find number of common path components:
        var i = 0
        while i < destComponents.count &&
              i < baseComponents.count &&
              destComponents[i] == baseComponents[i] {
                i += 1
        }

        // Build relative path:
        var relComponents = Array(repeating: "..", count: baseComponents.count - i)
        relComponents.append(contentsOf: destComponents[i...])
        return relComponents.joined(separator: "/")
    }
}

/// The file browser used to manage files inside a project.
@objc public class FileBrowserViewController: UICollectionViewController, UIDocumentPickerDelegate, UIContextMenuInteractionDelegate, UISearchResultsUpdating, UICollectionViewDragDelegate, UICollectionViewDropDelegate {
    
    init() {
        super.init(collectionViewLayout: UICollectionViewCompositionalLayout { section, layoutEnvironment in
            var config = UICollectionLayoutListConfiguration(appearance: .plain)
            config.showsSeparators = false
            return NSCollectionLayoutSection.list(using: config, layoutEnvironment: layoutEnvironment)
        })
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    /// Returns the URL for iCloud Drive folder.
    @objc static let iCloudContainerURL = FileManager.default.url(forUbiquityContainerIdentifier: nil)?.appendingPathComponent("Documents")
    
    /// Returns the URL for local folder.
    @objc static let localContainerURL = FileManager.default.urls(for: .documentDirectory, in: .allDomainsMask)[0]
    
    struct LocalFile {
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
    
    private var filteredResults: [URL]? {
        didSet {
            DispatchQueue.main.async { [weak self] in
                self?.load()
            }
        }
    }
    
    /// FIles in the directory.
    var files = [URL]()

    private var folderObservers = [URL: (observer: DispatchSourceFileSystemObject, descriptor: Int32)]()
    
    private func observe(directory: URL) {
        
        stopObserving(directory: directory)
        
        var isDir: ObjCBool = false
        guard FileManager.default.fileExists(atPath: directory.path, isDirectory: &isDir) && isDir.boolValue else {
            return
        }
        
        let descriptor = open(directory.path, O_EVTONLY)
        let folderObserver = DispatchSource.makeFileSystemObjectSource(fileDescriptor: descriptor, eventMask: .all, queue: DispatchQueue.main)
        folderObserver.setEventHandler {
            self.load()
        }
        folderObserver.resume()
        folderObservers[directory] = (observer: folderObserver, descriptor: descriptor)
    }
    
    private func stopObserving(directory: URL) {
        if let observer = folderObservers[directory] {
            observer.observer.cancel()
            UIKit.close(observer.descriptor)
        }
        
        folderObservers[directory] = nil
    }
    
    /// The directory to browse.
    var directory: URL! {
        willSet {
            if let dir = directory {
                stopObserving(directory: dir)
            }
        }
        
        didSet {
            title = directory != FileBrowserViewController.iCloudContainerURL ? FileManager.default.displayName(atPath: directory.path) : "iCloud Drive"
            
            expanded = []
            
            if dataSource != nil {
                load()
            }
            
            if view.window != nil {
                observe(directory: directory)
            }
        }
    }
    
    private var expanded = [URL]()
    
    func contents(of directory: URL) -> [URL] {
        ((try? FileManager.default.contentsOfDirectory(at: directory, includingPropertiesForKeys: nil, options: []))?.filter({ $0.lastPathComponent != ".DS_Store" && $0.lastPathComponent != ".Trash" }) ?? []).sorted(by: {
            $0.lastPathComponent < $1.lastPathComponent
        }).sorted(by: { a, _ in
            
            var isDir: ObjCBool = false
            if FileManager.default.fileExists(atPath: a.path, isDirectory: &isDir) && isDir.boolValue {
                return true
            } else {
                return false
            }
        })
    }
    
    private func run(cmd: String, onlyWrite: Bool = false) {
        let isShellRunning = (splitViewController as? SidebarSplitViewController)?.sidebar?.moduleRunner?.vc != nil
        (splitViewController as? SidebarSplitViewController)?.sidebar?.showModuleRunner()
        DispatchQueue.main.asyncAfter(deadline: .now()+(isShellRunning ? 0.5 : 2)) {
            let moduleRunner = (self.splitViewController as? SidebarSplitViewController)?.sidebar?.moduleRunner?.vc as? RunModuleViewController
            moduleRunner?.documentPicker(UIDocumentPickerViewController(forOpeningContentTypes: [.folder]), didPickDocumentsAt: [self.directory])
            DispatchQueue.main.asyncAfter(deadline: .now()+0.2) {
                if onlyWrite {
                    moduleRunner?.console?.movableTextField?.textField.text = cmd
                    moduleRunner?.console?.movableTextField?.focus()
                } else {
                    moduleRunner?.console?.movableTextField?.handler?(cmd)
                }
            }
        }
        
        if splitViewController?.isCollapsed == false && splitViewController?.displayMode == .twoOverSecondary {
            splitViewController?.preferredDisplayMode = .oneBesideSecondary
        }
    }
    
    /// Loads directory.
    func load() {
        files = contents(of: directory)
        
        var snaphsot = dataSource.snapshot(for: .main)
        snaphsot.deleteAll()
        
        var snapshot = NSDiffableDataSourceSectionSnapshot<URL>()
        if let filteredResults = filteredResults {
            for result in filteredResults {
                if result.resolvingSymlinksInPath().deletingLastPathComponent() == directory.resolvingSymlinksInPath() {
                    snapshot.append([result])
                } else {
                    if !snapshot.contains(result.deletingLastPathComponent()) {
                        snapshot.append([result.deletingLastPathComponent()])
                    }
                    snapshot.append([result], to: result.deletingLastPathComponent())
                    snapshot.expand([result.deletingLastPathComponent()])
                }
            }
        } else {
            snapshot.append(files)
            for expanded in self.expanded {
                
                var isDir: ObjCBool = false
                guard FileManager.default.fileExists(atPath: expanded.path, isDirectory: &isDir) && isDir.boolValue else {
                    if let i = self.expanded.firstIndex(of: expanded) {
                        self.expanded.remove(at: i)
                    }
                    return
                }
                
                if !snapshot.contains(expanded) {
                    if expanded.deletingLastPathComponent() == directory {
                        snapshot.append([expanded])
                    } else {
                        var added = snapshot.items
                        func add(url: URL) {
                            if url.deletingLastPathComponent() != directory && !snapshot.contains(url.deletingLastPathComponent()) && url.deletingLastPathComponent().path.hasPrefix(directory.path) && !added.contains(url) {
                                added.append(url)
                                add(url: url)
                            }
                            
                            if !snapshot.contains(url) {
                                snapshot.append([url])
                            }
                        }
                        
                        add(url: expanded)
                    }
                }
                snapshot.append(contents(of: expanded), to: expanded)
                snapshot.expand([expanded])
            }
        }
        dataSource.apply(snapshot, to: .main)
        
        if FileManager.default.fileExists(atPath: directory.appendingPathComponent("setup.py").path) {
            if navigationItem.rightBarButtonItems?.count == 2 {
                navigationItem.rightBarButtonItems?.insert(UIBarButtonItem(title: nil, image: UIImage(systemName: "hammer.fill"), primaryAction: nil, menu: UIMenu(title: "setup.py", image: nil, identifier: nil, options: [], children: [
                    
                    UIAction(title: "Install", image: UIImage(systemName: "square.and.arrow.down"), identifier: nil, discoverabilityTitle: "Install", attributes: [], state: .off, handler: { [weak self] _ in
                        
                        self?.run(cmd: "pip install .")
                    }),
                    
                    UIAction(title: "Build", image: UIImage(systemName: "gearshape.2"), identifier: nil, discoverabilityTitle: "Build", attributes: [], state: .off, handler: { [weak self] _ in
                        
                        self?.run(cmd: "python setup.py bdist_wheel")
                    }),
                    
                    UIAction(title: "Clean", image: UIImage(systemName: "trash"), identifier: nil, discoverabilityTitle: "Clean", attributes: [], state: .off, handler: { [weak self] _ in
                        
                        self?.run(cmd: "python setup.py clean")
                    }),
                ])), at: 0)
            }
        } else {
            if navigationItem.rightBarButtonItems?.count == 3 {
                navigationItem.rightBarButtonItems?.remove(at: 0)
            }
        }
    }
    
    private class DocumentPickerViewController: UIDocumentPickerViewController {
        
        var directory: URL?
    }
    
    /// Creates the menu for creating files.
    ///
    /// - Parameters:
    ///     - includeFolder. If `true`, includes a menu item to create a folder.
    ///     - directory: The directory where the file will be created. If `nil`, the file will be created in the receiver's directory.
    func makeCreateMenu(includeFolder: Bool = false, directory: URL? = nil) -> UIMenu {
        UIMenu(title: NSLocalizedString("create", comment: "'Create' button"), image: nil, identifier: nil, options: [], children: (includeFolder ? [
        
                UIAction(title: NSLocalizedString("creation.folder", comment: "A folder"), image: UIImage(systemName: "folder"), identifier: nil, discoverabilityTitle: NSLocalizedString("creation.folder", comment: "A folder"), attributes: [], state: .off, handler: { _ in
                    self.createFile(type: .folder, in: directory)
                })
            ] : [])+[
        
            UIAction(title: NSLocalizedString("creation.pythonScript", comment: "A Python script"), image: UIImage(systemName: "curlybraces"), identifier: nil, discoverabilityTitle: NSLocalizedString("creation.pythonScript", comment: "A Python script"), attributes: [], state: .off, handler: { _ in
                self.createFile(type: .python, in: directory)
            }),
            
            UIAction(title: NSLocalizedString("creation.blankFile", comment: "A blank file"), image: UIImage(systemName: "doc"), identifier: nil, discoverabilityTitle: NSLocalizedString("creation.blankFile", comment: "A blank file"), attributes: [], state: .off, handler: { _ in
                self.createFile(type: .blank, in: directory)
            }),
            
            UIAction(title: NSLocalizedString("creation.importFromFiles", comment: "Import from Files"), image: UIImage(systemName: "square.and.arrow.down"), identifier: nil, discoverabilityTitle: NSLocalizedString("creation.importFromFiles", comment: "Import from Files"), attributes: [], state: .off, handler: { _ in
                let vc = DocumentPickerViewController(forOpeningContentTypes: [.item], asCopy: true)
                vc.directory = directory
                vc.allowsMultipleSelection = true
                vc.delegate = self
                self.present(vc, animated: true, completion: nil)
            })
        
        ])
    }
    
    /// Creates a file with given file type.
    ///
    /// - Parameters:
    ///     - type: The file type.
    ///     - directory: The directory where the file will be created. If `nil`, the file will be created in the receiver's directory.
    func createFile(type: FileType, in directory: URL? = nil) {
        
        let dir = directory ?? self.directory!
        
        if type == .python {
            let templateChooser = TemplateChooser(parent: self, chooseName: true, importHandler: { url, _ in
                if let url = url {
                    do {
                        try FileManager.default.copyItem(at: url, to: dir.appendingPathComponent(url.lastPathComponent))
                    } catch {
                        present(error: error)
                    }
                }
            })
            
            self.present(UIHostingController(rootView: templateChooser), animated: true, completion: nil)
            
            return
        }
        
        func present(error: Error) {
            let alert = UIAlertController(title: NSLocalizedString("errors.errorCreatingFile", comment: "The title of alerts shown when an error occurred while creating a file"), message: error.localizedDescription, preferredStyle: .alert)
            alert.addAction(UIAlertAction(title: NSLocalizedString("cancel", comment: "'Cancel' button"), style: .cancel, handler: nil))
            self.present(alert, animated: true, completion: nil)
        }
        
        let alert = UIAlertController(title: (type == .python ? NSLocalizedString("creation.createScriptTitle", comment: "The title of the button shown for creating a script") : (type == .folder ? NSLocalizedString("creation.createFolderTitle", comment: "The title of the button shown for creating a folder") : NSLocalizedString("creation.createFileTitle", comment: "The title of the button shown for creating a file"))), message: (type == .folder ? NSLocalizedString("creation.typeFolderName", comment: "The message of the alert shown for creating a folder") : NSLocalizedString("creation.typeFileName", comment: "The message of the alert shown for creating a file")), preferredStyle: .alert)
        
        var textField: UITextField!
        
        alert.addAction(UIAlertAction(title: NSLocalizedString("create", comment: "'Create' button"), style: .default, handler: { (_) in
            if true {
                do {
                    var name = textField.text ?? NSLocalizedString("untitled", comment: "Untitled")
                    if name.replacingOccurrences(of: " ", with: "").isEmpty {
                        name =  NSLocalizedString("untitled", comment: "Untitled")
                    }
                    
                    if type == .folder {
                        try FileManager.default.createDirectory(at: dir.appendingPathComponent(name), withIntermediateDirectories: true, attributes: nil)
                    } else {
                        if !FileManager.default.createFile(atPath: dir.appendingPathComponent(name).path, contents: "".data(using: .utf8), attributes: nil) {
                            throw NSError(domain: "SeeLess.errorCreatingFile", code: 1, userInfo: [NSLocalizedDescriptionKey : "Error creating file"])
                        }
                    }
                } catch {
                    present(error: error)
                }
            }
        }))
        
        alert.addAction(UIAlertAction(title: NSLocalizedString("cancel", comment: "'Cancel' button"), style: .cancel, handler: nil))
        
        alert.addTextField { (_textField) in
            textField = _textField
            textField.placeholder = NSLocalizedString("untitled", comment: "Untitled")
        }
        
        self.present(alert, animated: true, completion: nil)
    }
    
    /// Creates a new folder.
    @objc func createFolder(_ sender: UIBarButtonItem) {
        self.createFile(type: .folder)
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
    
    enum Section {
        case main
    }
    
    var dataSource: UICollectionViewDiffableDataSource<Section, URL>!
    
    // MARK: - Table view controller
    
    private var alreadyShown = false
    
    public override var keyCommands: [UIKeyCommand]? {
        return [UIKeyCommand.command(input: "f", modifierFlags: .command, action: #selector(search), discoverabilityTitle: NSLocalizedString("find", comment: "'Find'"))]
    }
    
    public override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        load()
        
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
        edgesForExtendedLayout = []
        
        clearsSelectionOnViewWillAppear = true
        
        collectionView.dragDelegate = self
        collectionView.dropDelegate = self
        
        let cellRegistration = UICollectionView.CellRegistration<UICollectionViewListCell, URL> { (cell, indexPath, url) in
                var content = cell.defaultContentConfiguration()
                
                let icloud = (url.pathExtension == "icloud" && url.lastPathComponent.hasPrefix("."))
                
                if icloud {
                    var name = url.deletingPathExtension().lastPathComponent
                    name.removeFirst()
                    content.text = name
                } else {
                    content.text = url.lastPathComponent
                }
                
                var isDir: ObjCBool = false
                if FileManager.default.fileExists(atPath: url.path, isDirectory: &isDir) && isDir.boolValue {
                    if FileManager.default.fileExists(atPath: url.appendingPathComponent("__init__.py").path) || FileManager.default.fileExists(atPath: url.appendingPathComponent("__main__.py").path) {
                        content.image = UIImage(systemName: "shippingbox")
                    } else {
                        content.image = UIImage(systemName: "folder")
                    }
                    cell.accessories = [.outlineDisclosure(options: .init(style: .header))]
                } else {
                    if !icloud {
                        if url.pathExtension.lowercased() == "py" {
                            content.image = UIImage(named: "python.SFSymbol")
                            content.imageProperties.preferredSymbolConfiguration = UIImage.SymbolConfiguration(font: .preferredFont(forTextStyle: .largeTitle, compatibleWith: nil))
                        } else {
                            content.image = UIImage(systemName: "doc.fill")
                        }
                    } else {
                        content.image = UIImage(systemName: "icloud.and.arrow.down.fill")
                    }
                    cell.accessories = []
                }
                
                let interaction = UIContextMenuInteraction(delegate: self)
                cell.addInteraction(interaction)
                            
                cell.contentConfiguration = content
        }
        
        dataSource = UICollectionViewDiffableDataSource<Section, URL>(collectionView: collectionView, cellProvider: { collectionView, indexPath, itemIdentifier in
            return collectionView.dequeueConfiguredReusableCell(using: cellRegistration, for: indexPath, item: itemIdentifier)
        })
        
        dataSource.sectionSnapshotHandlers.shouldExpandItem = {
            var isDir: ObjCBool = false
            if FileManager.default.fileExists(atPath: $0.path, isDirectory: &isDir) {
                return isDir.boolValue
            } else {
                return false
            }
        }
        
        dataSource.sectionSnapshotHandlers.shouldCollapseItem = {
            var isDir: ObjCBool = false
            if FileManager.default.fileExists(atPath: $0.path, isDirectory: &isDir) {
                return isDir.boolValue
            } else {
                return false
            }
        }
        
        dataSource.sectionSnapshotHandlers.willExpandItem = { [weak self] url in
            guard let self = self else {
                return
            }
            
            if !self.expanded.contains(url) {
                self.expanded.append(url)
                self.observe(directory: url)
            }
            
            guard self.filteredResults == nil else {
                return
            }
            
            var snapshot = self.dataSource.snapshot(for: .main)
            for _url in self.contents(of: url) {
                if !snapshot.contains(_url) {
                    snapshot.append([_url], to: url)
                }
            }
            self.dataSource.apply(snapshot, to: .main, animatingDifferences: true, completion: nil)
        }
        
        dataSource.sectionSnapshotHandlers.willCollapseItem = { [weak self] url in
            guard let self = self else {
                return
            }
            
            if let i = self.expanded.firstIndex(of: url) {
                self.expanded.remove(at: i)
                self.stopObserving(directory: url)
            }
            
            guard self.filteredResults == nil else {
                return
            }
            
            var snapshot = self.dataSource.snapshot(for: .main)
            var items = [URL]()
            for item in snapshot.items {
                if item.resolvingSymlinksInPath().path.hasPrefix(url.resolvingSymlinksInPath().path) && item.resolvingSymlinksInPath() != url.resolvingSymlinksInPath() {
                    items.append(item)
                }
            }
            snapshot.delete(items)
            self.dataSource.apply(snapshot, to: .main, animatingDifferences: true, completion: nil)
        }
                
        searchController.searchResultsUpdater = self
        searchController.obscuresBackgroundDuringPresentation = false
        searchController.searchBar.placeholder = NSLocalizedString("Search", bundle: Bundle(for: UIApplication.self), comment: "")
        navigationItem.searchController = searchController
        definesPresentationContext = true
                
        let createButton = UIBarButtonItem(systemItem: .add, primaryAction: nil, menu: makeCreateMenu())
        
        navigationItem.rightBarButtonItems = [
            createButton,
            UIBarButtonItem(image: UIImage(systemName: "folder.badge.plus"), style: .plain, target: self, action: #selector(createFolder(_:)))
        ]
    }
    
    public override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        observe(directory: directory)
        for dir in expanded {
            observe(directory: dir)
        }
        
        load()
        
        becomeFirstResponder()
    }
    
    public override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        
        for dir in folderObservers.keys {
            stopObserving(directory: dir)
        }
        
        for dir in expanded {
            stopObserving(directory: dir)
        }
    }
    
    public override func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        
        guard var url = dataSource.itemIdentifier(for: indexPath) else {
            return
        }
        
        var isDir: ObjCBool = false
        if FileManager.default.fileExists(atPath: url.path, isDirectory: &isDir) && isDir.boolValue {
            let browser = FileBrowserViewController()
            browser.navigationItem.largeTitleDisplayMode = .never
            browser.directory = url
            navigationController?.pushViewController(browser, animated: true)
        } else {
            
            let icloud = (url.pathExtension == "icloud" && url.lastPathComponent.hasPrefix("."))
            
            var last = url.deletingPathExtension().lastPathComponent
            last.removeFirst()
            
            if icloud {
                url = url.deletingLastPathComponent().appendingPathComponent(last)
            }
            
            if url.pathExtension.lowercased() == "py" || url.pathExtension.lowercased() == "html" || (try? url.resourceValues(forKeys: [.contentTypeKey]))?.contentType?.conforms(to: .text) == true || (try? String(contentsOf: url)) != nil {
                
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
                                    RecentDataSource.shared.didSetRecent = {
                                        (self.splitViewController as? SidebarSplitViewController)?.sidebar?.loadRecents()
                                        RecentDataSource.shared.didSetRecent = nil
                                    }
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
                    RecentDataSource.shared.recent.append(url)
                    RecentDataSource.shared.didSetRecent = {
                        (self.splitViewController as? SidebarSplitViewController)?.sidebar?.loadRecents()
                        RecentDataSource.shared.didSetRecent = nil
                    }
                }
            } else if !icloud && url.pathExtension.lowercased() == "whl" {
                (splitViewController as? SidebarSplitViewController)?.sidebar?.install(wheel: url)
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
    
    // MARK: - Collection view drag delegate
    
    public func collectionView(_ collectionView: UICollectionView, itemsForBeginning session: UIDragSession, at indexPath: IndexPath) -> [UIDragItem] {
        
        guard let file = dataSource.itemIdentifier(for: indexPath) else {
            return []
        }
        
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
    
    public func collectionView(_ collectionView: UICollectionView, canHandle session: UIDropSession) -> Bool {
        return session.hasItemsConforming(toTypeIdentifiers: [kUTTypeItem as String])
    }
    
    public func collectionView(_ collectionView: UICollectionView, performDropWith coordinator: UICollectionViewDropCoordinator) {
        
        // Good luck debugging this :)
        guard let destination = (coordinator.destinationIndexPath != nil ? ((coordinator.destinationIndexPath != nil && coordinator.proposal.intent == .insertIntoDestinationIndexPath) ? self.dataSource.itemIdentifier(for: coordinator.destinationIndexPath!) : ((coordinator.proposal.intent == .insertAtDestinationIndexPath && self.dataSource.itemIdentifier(for: coordinator.destinationIndexPath!) != nil) ? self.dataSource.itemIdentifier(for: coordinator.destinationIndexPath!)!.deletingLastPathComponent() : self.directory)) : self.directory) else {
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
                
                load()
                
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
    
    public func collectionView(_ collectionView: UICollectionView, dropSessionDidUpdate session: UIDropSession, withDestinationIndexPath destinationIndexPath: IndexPath?) -> UICollectionViewDropProposal {
        
        if let local = session.items.first?.localObject as? LocalFile, local.url.deletingLastPathComponent() != directory {
            return UICollectionViewDropProposal(operation: .move)
        }
        
        var isDir: ObjCBool = false
        if destinationIndexPath == nil || !(destinationIndexPath != nil && dataSource.itemIdentifier(for: destinationIndexPath!) != nil && FileManager.default.fileExists(atPath: dataSource.itemIdentifier(for: destinationIndexPath!)!.path, isDirectory: &isDir) && isDir.boolValue) {
            
            if destinationIndexPath == nil && (session.items.first?.localObject as? LocalFile)?.url.deletingLastPathComponent() == directory {
                return UICollectionViewDropProposal(operation: .forbidden)
            } else if session.items.first?.localObject == nil || (session.items.first?.localObject as? LocalFile)?.directory != directory {
                return UICollectionViewDropProposal(operation: .copy, intent: .insertAtDestinationIndexPath)
            } else {
                return UICollectionViewDropProposal(operation: .move, intent: .insertAtDestinationIndexPath)
            }
        } else if destinationIndexPath != nil && dataSource.itemIdentifier(for: destinationIndexPath!) != nil && FileManager.default.fileExists(atPath: dataSource.itemIdentifier(for: destinationIndexPath!)!.path, isDirectory: &isDir) && isDir.boolValue && (session.items.first?.localObject as? URL)?.deletingLastPathComponent() == dataSource.itemIdentifier(for: destinationIndexPath!) {
            return UICollectionViewDropProposal(operation: .forbidden)
        } else if destinationIndexPath == nil && (session.items.first?.localObject as? LocalFile)?.url.deletingLastPathComponent() == directory {
            return UICollectionViewDropProposal(operation: .forbidden)
        } else if session.items.first?.localObject == nil {
            return UICollectionViewDropProposal(operation: .copy, intent: .insertIntoDestinationIndexPath)
        } else {
            return UICollectionViewDropProposal(operation: .move, intent: .insertIntoDestinationIndexPath)
        }
    }
        
    // MARK: - Document picker view controller delegate
    
    public func documentPicker(_ controller: UIDocumentPickerViewController, didPickDocumentsAt urls: [URL]) {
        
        let directory = (controller as? DocumentPickerViewController)?.directory ?? self.directory!
        
        func move(at index: Int) {
            do {
                try FileManager.default.moveItem(at: urls[index], to: directory.appendingPathComponent(urls[index].lastPathComponent))
                
                if urls.indices.contains(index+1) {
                    move(at: index+1)
                } else {
                    load()
                }
                
            } catch {
                let alert = UIAlertController(title: NSLocalizedString("errors.errorCreatingFile", comment: "The title of alerts shown when an error occurred while creating a file"), message: error.localizedDescription, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: NSLocalizedString("cancel", comment: "'Cancel' button"), style: .cancel, handler: { _ in
                    if urls.indices.contains(index+1) {
                        move(at: index+1)
                    } else {
                        self.load()
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
                
        guard let cell = interaction.view as? UICollectionViewCell else {
            return nil
        }
        
        guard let index = collectionView.indexPath(for: cell) else {
            return nil
        }
        
        guard let url = dataSource.itemIdentifier(for: index) else {
            return nil
        }
        
        let directory: URL
        var isDir: ObjCBool = false
        if FileManager.default.fileExists(atPath: url.path, isDirectory: &isDir) && isDir.boolValue {
            directory = url
        } else {
            directory = url.deletingLastPathComponent()
        }
        
        let create = makeCreateMenu(includeFolder: true, directory: directory)
        
        let addToFavorites = UIAction(title: NSLocalizedString("addToFavorites", comment: "Add to favorites"), image: UIImage(systemName: "star")) { action in
            
            SidebarViewController.favorites.append(url)
            (self.splitViewController as? SidebarSplitViewController)?.sidebar?.loadFavorites()
        }
        
        let share = UIAction(title: NSLocalizedString("menuItems.share", comment: "The menu item to share a file"), image: UIImage(systemName: "square.and.arrow.up")) { action in
            
            let activityVC = UIActivityViewController(activityItems: [url], applicationActivities: nil)
            activityVC.popoverPresentationController?.sourceView = cell
            activityVC.popoverPresentationController?.sourceRect = cell.bounds
            self.present(activityVC, animated: true, completion: nil)
        }
        
        let saveTo: UIAction
        if !isiOSAppOnMac {
            saveTo = UIAction(title: NSLocalizedString("menuItems.saveToFiles", comment: "The menu item to save a file to Files"), image: UIImage(systemName: "folder")) { action in
                
                self.present(UIDocumentPickerViewController(forExporting: [url], asCopy: true), animated: true, completion: nil)
            }
        } else {
            saveTo = UIAction(title: NSLocalizedString("Show in Finder", comment: "The 'Show in Finder' menu item"), image: UIImage(systemName: "folder")) { action in
                
                Dynamic.NSWorkspace.sharedWorkspace.activateFileViewerSelectingURLs([url])
            }
        }
                
        let rename = UIAction(title: NSLocalizedString("menuItems.rename", comment: "The 'Rename' menu item"), image: UIImage(systemName: "pencil")) { action in
            
            let file = url
            
            var textField: UITextField!
            let alert = UIAlertController(title: "\(NSLocalizedString("menuItems.rename", comment: "The 'Rename' menu item")) '\(file.lastPathComponent)'", message: NSLocalizedString("creation.typeFileName", comment: "The message of the alert shown for creating a file"), preferredStyle: .alert)
            
            alert.addAction(UIAlertAction(title: NSLocalizedString("menuItems.rename", comment: "The 'Rename' menu item"), style: .default, handler: { [weak self] (_) in
                do {
                    
                    let name = textField.text ?? ""
                    
                    if !name.isEmpty {
                        try FileManager.default.moveItem(at: file, to: file.deletingLastPathComponent().appendingPathComponent(name))
                    }
                } catch {
                    let alert = UIAlertController(title: NSLocalizedString("errors.errorRenamingFile", comment: "Title of the alert shown when an error occurred while renaming a file"), message: error.localizedDescription, preferredStyle: .alert)
                    alert.addAction(UIAlertAction(title: NSLocalizedString("cancel", comment: "'Cancel' button"), style: .cancel, handler: nil))
                    self?.present(alert, animated: true, completion: nil)
                }
            }))
            
            alert.addAction(UIAlertAction(title: NSLocalizedString("cancel", comment: "'Cancel' button"), style: .cancel, handler: nil))
            alert.addTextField { (_textField) in
                textField = _textField
                textField.placeholder = NSLocalizedString("untitled", comment: "Untitled")
                textField.text = file.lastPathComponent
            }
            
            self.present(alert, animated: true, completion: nil)
        }
        
        let delete = UIAction(title: NSLocalizedString("menuItems.remove", comment: "The 'Remove' menu item"), image: UIImage(systemName: "trash.fill"), attributes: .destructive) { action in
            
            do {
                try FileManager.default.removeItem(at: url)
                self.load()
            } catch {
                let alert = UIAlertController(title: NSLocalizedString("errors.errorRemovingFile", comment: "Title of the alert shown when an error occurred while removing a file"), message: error.localizedDescription, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: NSLocalizedString("cancel", comment: "'Cancel' button"), style: .cancel, handler: nil))
                self.present(alert, animated: true, completion: nil)
            }
        }
        
        let run = UIAction(title: NSLocalizedString("menuItems.run", comment: "The 'Run' menu item"), image: UIImage(systemName: "play")) { action in
            
            self.run(cmd: "python '\((url.relativePath(from: self.directory) ?? url.path).replacingOccurrences(of: "'", with: "\\'"))' ", onlyWrite: true)
        }

        return UIContextMenuConfiguration(identifier: nil, previewProvider: nil) { (_) -> UIMenu? in
            
            return UIMenu(title: url.lastPathComponent, children: [create, addToFavorites]+((url.pathExtension.lowercased() == "py" || url.pathExtension.lowercased() == "html") ? [run] : [])+[share, saveTo, rename, delete])
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
            guard let enumerator = FileManager.default.enumerator(at: directory, includingPropertiesForKeys: [URLResourceKey.isDirectoryKey, URLResourceKey.isRegularFileKey], options: []) else {
                return
            }
            for case let file as URL in enumerator {
                if file.lastPathComponent.lowercased().contains(text!.lowercased()) {
                    results.append(file)
                }
            }
            filteredResults = results
        }
    }
}
