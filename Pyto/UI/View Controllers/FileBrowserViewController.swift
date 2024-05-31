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
import InterfaceBuilder

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
@objc public class FileBrowserViewController: UICollectionViewController, UIDocumentPickerDelegate, UISearchResultsUpdating, UICollectionViewDragDelegate, UICollectionViewDropDelegate, UINavigationItemRenameDelegate {
    
    init() {
        super.init(collectionViewLayout: UICollectionViewCompositionalLayout { section, layoutEnvironment in
            var config = UICollectionLayoutListConfiguration(appearance: .insetGrouped)
            config.showsSeparators = true
            return NSCollectionLayoutSection.list(using: config, layoutEnvironment: layoutEnvironment)
        })
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    /// The button for showing the menu.
    let menuButton = UIButton()
    
    /// The navigation item menu.
    var menu: UIMenu?
    
    /// Configures `menuButton`.
    func configureMenu() {
        
        menu = UIMenu(title: directory.lastPathComponent, image: nil, identifier: nil, options: [], children: [])
        
        var hierarchy = [UIMenuElement]()
        
        var history = directory!
        for _ in directory.pathComponents.reversed() {
            
            history = history.deletingLastPathComponent()
            let url = history
            
            guard FileManager.default.isReadableFile(atPath: url.path) else {
                break
            }
            
            var image = UIImage(systemName: "folder")
            var name = url.lastPathComponent
            
            if url == Self.iCloudContainerURL?.deletingLastPathComponent() {
                break
            } else if url == Self.iCloudContainerURL {
                name = "iCloud Drive"
                image = UIImage(systemName: "cloud")
            }
            
            hierarchy.append(UIAction(title: name, image: image, handler: { [weak self] _ in
                let browser = FileBrowserViewController()
                browser.directory = url
                self?.navigationController?.pushViewController(browser, animated: true)
            }))
            
        }
        
        let hierarchyMenu = [UIMenu(title: "", options: .displayInline, children: hierarchy)]
        
        let addToFavorites = UIAction(title: NSLocalizedString("addToFavorites", comment: "Add to favorites"), image: UIImage(systemName: "star")) { action in
            
            SidebarViewController.favorites.append(self.directory)
            (self.splitViewController as? SidebarSplitViewController)?.sidebar?.loadFavorites()
        }
        
        if #available(iOS 16.0, *) {
            navigationItem.titleMenuProvider = { items in
                return UIMenu(children: hierarchyMenu + items + self.menu!.children + (SidebarViewController.favorites.contains(self.directory) ? [] : [UIMenu(title: "", options: .displayInline, children: [addToFavorites])]))
            }
        }
    }
    
    /// The directory opened at launch.
    static var defaultDirectory: URL {
        get {
            guard let data = UserDefaults.standard.data(forKey: "defaultDirectory") else {
                return iCloudContainerURL ?? localContainerURL
            }
            
            var isStale = false
            
            guard let url = try? URL(resolvingBookmarkData: data, bookmarkDataIsStale: &isStale) else {
                return iCloudContainerURL ?? localContainerURL
            }
            
            _ = url.startAccessingSecurityScopedResource()
            
            return url
        }
        
        set {
            guard let data = try? newValue.bookmarkData() else {
                return
            }
            
            UserDefaults.standard.set(data, forKey: "defaultDirectory")
        }
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
        
        /// A PytoUI view.
        case view
        
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
            DispatchQueue.main.async {
                self.load()
            }
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
            
            if #available(iOS 16.0, *) {
                let props = UIDocumentProperties(url: directory)
                props.activityViewControllerProvider = {
                    UIActivityViewController(activityItems: [self.directory!], applicationActivities: nil)
                }
                navigationItem.documentProperties = props
            }
            
            expanded = []
            
            if dataSource != nil {
                load()
            }
            
            if view.window != nil {
                observe(directory: directory)
            }
            
            configureMenu()
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
            _ = Timer.scheduledTimer(withTimeInterval: 0.2, repeats: true, block: { timer in
                if moduleRunner?.console?.prompt != nil {
                    moduleRunner?.console?.input = cmd
                    moduleRunner?.console?.inputIndex = cmd.count
                    moduleRunner?.console?.print(cmd)
                    moduleRunner?.console?.webView.printInput(operation: .insert)
                    DispatchQueue.main.asyncAfter(deadline: .now()+0.2) {
                        if !onlyWrite {
                            moduleRunner?.console?.webView.enter()
                        }
                    }
                    timer.invalidate()
                }
            })
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
        var newSnapshot = dataSource.snapshot()
        newSnapshot.reloadItems(newSnapshot.itemIdentifiers)
        dataSource.apply(newSnapshot)
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
                
        UIMenu(title: includeFolder ? NSLocalizedString("create", comment: "'Create' button") : NSLocalizedString("creation.createFileTitle", comment: "The title of the button shown for creating a file"), image: UIImage(systemName: "plus"), identifier: nil, options: [], children: (includeFolder ? [
        
                UIAction(title: NSLocalizedString("creation.folder", comment: "A folder"), image: UIImage(systemName: "folder"), identifier: nil, discoverabilityTitle: NSLocalizedString("creation.folder", comment: "A folder"), attributes: [], state: .off, handler: { _ in
                    self.createFile(type: .folder, in: directory)
                })
            ] : [])+[
        
            UIAction(title: NSLocalizedString("creation.templates", comment: "Templates menu"), image: UIImage(systemName: "curlybraces"), identifier: nil, discoverabilityTitle: NSLocalizedString("creation.templates", comment: "Templates menu"), attributes: [], state: .off, handler: { _ in
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
                        
                        let okayChars : Set<Character> =
                                Set("abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLKMNOPQRSTUVWXYZ1234567890_")
                        let name = String(url.deletingPathExtension().lastPathComponent.filter { okayChars.contains($0) })
                        
                        var text = try String(contentsOf: url)
                        text = text.replacingOccurrences(of: "<name>", with: name)
                        try text.write(to: dir.appendingPathComponent(url.lastPathComponent), atomically: true, encoding: .utf8)
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
                    
                    if type == .view && !name.lowercased().hasSuffix(".pytoui") {
                        name.append(".pytoui")
                    }
                    
                    if type == .folder {
                        try FileManager.default.createDirectory(at: dir.appendingPathComponent(name), withIntermediateDirectories: true, attributes: nil)
                    } else {
                        let url = dir.appendingPathComponent(name)
                        if type == .blank {
                            if !FileManager.default.createFile(atPath: url.path, contents: "".data(using: .utf8), attributes: nil) {
                                throw NSError(domain: "SeeLess.errorCreatingFile", code: 1, userInfo: [NSLocalizedDescriptionKey : "Error creating file"])
                            }
                        } else {
                            try InterfaceDocument.createEmptyDocument(at: url)
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
    
    @objc static var visibles = NSMutableArray()
    
    // MARK: - Collection view controller
    
    private var alreadyShown = false
    
    public override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        
        if Self.visibles.contains(self) {
            Self.visibles.remove(self)
        }
    }
    
    public override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
                
        Self.visibles.add(self)
        
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
        
        edgesForExtendedLayout = []
        
        clearsSelectionOnViewWillAppear = true
        
        collectionView.backgroundColor = .systemBackground
        collectionView.backgroundView = UIView()
        collectionView.dragDelegate = self
        collectionView.dropDelegate = self
        
        let cellRegistration = UICollectionView.CellRegistration<UICollectionViewListCell, URL> { (cell, indexPath, url) in
            var content = cell.defaultContentConfiguration()
            
            let icloud = (url.pathExtension == "icloud" && url.lastPathComponent.hasPrefix("."))
            
            if icloud {
                var name = url.deletingPathExtension().lastPathComponent
                name.removeFirst()
                content.text = name
                content.secondaryText = "iCloud Drive"
            } else {
                content.text = url.lastPathComponent
            }
            
            var isPythonScript = false
            
            var isDir: ObjCBool = false
            if FileManager.default.fileExists(atPath: url.path, isDirectory: &isDir) && isDir.boolValue {
                if FileManager.default.fileExists(atPath: url.appendingPathComponent("__init__.py").path) || FileManager.default.fileExists(atPath: url.appendingPathComponent("__main__.py").path) {
                    content.image = UIImage(systemName: "shippingbox.fill")
                    content.imageProperties.tintColor = .systemBrown
                } else {
                    content.image = UIImage(systemName: "folder.fill")
                    content.imageProperties.tintColor = .systemBlue
                }
                
                if let count = (try? FileManager.default.contentsOfDirectory(atPath: url.path))?.count, let attributes = (try? url.resourceValues(forKeys: [.contentModificationDateKey])), let date = attributes.contentModificationDate {
                    
                    let dateFormatter = DateFormatter()
                    dateFormatter.dateStyle = .short
                    dateFormatter.timeStyle = .none
                    
                    content.secondaryText = "\(dateFormatter.string(from: date)) - \(count) item\(count > 1 ? "s" : "")"
                }
                cell.accessories = [.outlineDisclosure(options: .init(style: .header))]
            } else {
                if ["py", "pyc", "pyx"].contains(url.pathExtension.lowercased()) {
                    if #available(iOS 16.0, *) {
                        let renderer = ImageRenderer(content: Image("python.SFSymbol")
                            .resizable()
                            .frame(width: 40, height: 40)
                            .symbolRenderingMode(.multicolor)
                            .foregroundStyle(.blue, .yellow)
                            .font(.system(size: 30)))
                        renderer.scale = 2
                        content.image = renderer.uiImage
                    } else {
                        content.image = UIImage(named: "python.SFSymbol")?.withRenderingMode(.alwaysOriginal)
                        content.imageProperties.preferredSymbolConfiguration = UIImage.SymbolConfiguration(font: UIFont.systemFont(ofSize: 30))
                        
                        content.imageProperties.tintColor = UIColor(named: "TintColor")
                    }
                    
                    isPythonScript = true
                } else if url.pathExtension.lowercased() == "pytoui" {
                    content.image = UIImage(systemName: "ipad")
                    content.imageProperties.tintColor = .systemRed
                } else if ["bc", "ll", "so"].contains(url.pathExtension.lowercased()) {
                    content.image = UIImage(systemName: "terminal.fill")
                    content.imageProperties.tintColor = .label
                } else if ["c", "cc", "cpp", "cxx", "m", "mm"].contains(url.pathExtension.lowercased()) {
                    content.image = UIImage(systemName: "c.square.fill")
                    content.imageProperties.tintColor = .systemPurple
                } else if ["h", "hpp"].contains(url.pathExtension.lowercased()) {
                    content.image = UIImage(systemName: "h.square.fill")
                    content.imageProperties.tintColor = .systemPink
                } else {
                    content.image = UIImage(systemName: "doc.text.fill")
                    content.imageProperties.tintColor = .label
                }
                if !icloud, let attributes = (try? url.resourceValues(forKeys: [.fileSizeKey, .contentModificationDateKey])), let fileSize = attributes.fileSize, let date = attributes.contentModificationDate {
                    let bytesFormatter = ByteCountFormatter()
                    let dateFormatter = DateFormatter()
                    dateFormatter.dateStyle = .short
                    dateFormatter.timeStyle = .none
                    content.secondaryText = "\(dateFormatter.string(from: date)) - \(bytesFormatter.string(fromByteCount: Int64(fileSize)))"
                }
                cell.accessories = []
            }
             
            if !isPythonScript {
                content.imageProperties.preferredSymbolConfiguration = .init(font: UIFont.systemFont(ofSize: 30))
            }
            content.imageProperties.reservedLayoutSize = CGSize(width: 30, height: 30)
            content.secondaryTextProperties.color = .secondaryLabel
            content.secondaryTextProperties.font = UIFont.preferredFont(forTextStyle: .caption1)
            cell.contentConfiguration = content
            cell.contentView.alpha = (icloud || url.lastPathComponent.hasPrefix(".")) ? 0.5 : 1
        }
        
        
        dataSource = UICollectionViewDiffableDataSource<Section, URL>(collectionView: collectionView, cellProvider: { collectionView, indexPath, itemIdentifier in
            let cell = collectionView.dequeueConfiguredReusableCell(using: cellRegistration, for: indexPath, item: itemIdentifier)
            return cell
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

        if #available(iOS 16.0, *) {
            navigationItem.largeTitleDisplayMode = .never
            navigationItem.style = .navigator
            navigationItem.renameDelegate = self
        } else {
            menuButton.setImage(UIImage(systemName: "ellipsis.circle"), for: .normal)
            menuButton.showsMenuAsPrimaryAction = true
            navigationItem.rightBarButtonItems = [
                UIBarButtonItem(customView: menuButton)
            ]
        }
        
        let createFolder = UIBarButtonItem(image: UIImage(systemName: "folder.badge.plus"), style: .plain, target: self, action: #selector(self.createFolder(_:)))
        
        let createFile = UIBarButtonItem(image: UIImage(systemName: "plus"), style: .done, target: nil, action: nil)
        createFile.menu = makeCreateMenu(includeFolder: false)
        
        navigationItem.rightBarButtonItems = [createFolder, createFile]
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
            
            if url.pathExtension.lowercased() == "py" || url.pathExtension.lowercased() == "html" || (try? url.resourceValues(forKeys: [.contentTypeKey]))?.contentType?.conforms(to: .text) == true || (try? String(contentsOf: url)) != nil, url.pathExtension.lowercased() != "pytoui" {
                
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
            } else if url.pathExtension.lowercased() == "pytoui", #available(iOS 16.0, *) {
                let doc = InterfaceDocument(fileURL: url)
                doc.open { _ in
                    DispatchQueue.main.async {
                        let ib = InterfaceBuilderViewController(document: doc)
                        let navVC = UINavigationController(rootViewController: ib)
                        navVC.navigationBar.prefersLargeTitles = false
                        ib.navigationItem.largeTitleDisplayMode = .never
                        self.showDetailViewController(navVC, sender: self)
                    }
                }
                
                RecentDataSource.shared.recent.append(url)
                RecentDataSource.shared.didSetRecent = {
                    (self.splitViewController as? SidebarSplitViewController)?.sidebar?.loadRecents()
                    RecentDataSource.shared.didSetRecent = nil
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
        item.itemProvider.registerObject(file as NSItemProviderWriting, visibility: .ownProcess)
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
    
    // MARK: - Collection view drop delegate
    
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
    
    public override func collectionView(_ collectionView: UICollectionView, contextMenuConfigurationForItemsAt indexPaths: [IndexPath], point: CGPoint) -> UIContextMenuConfiguration? {
        
        let cell = (indexPaths.first != nil) ? collectionView.cellForItem(at: indexPaths[0]) : nil
        
        var urls = [URL]()
        for i in indexPaths {
            guard let url = dataSource.itemIdentifier(for: i) else {
                continue
            }
            
            urls.append(url)
        }
        
        let isEmpty = urls.isEmpty
        if isEmpty {
            urls = [directory]
        }
        
        let create: UIMenu?
        if urls.count < 2, let url = urls.first {
            let directory: URL
            var isDir: ObjCBool = false
            if FileManager.default.fileExists(atPath: url.path, isDirectory: &isDir) && isDir.boolValue {
                directory = url
            } else {
                directory = url.deletingLastPathComponent()
            }
            
            create = makeCreateMenu(includeFolder: true, directory: directory)
        } else {
            create = nil
        }
        
        let addToFavorites = UIAction(title: NSLocalizedString("addToFavorites", comment: "Add to favorites"), image: UIImage(systemName: "star")) { action in
            
            SidebarViewController.favorites.append(contentsOf: urls)
            (self.splitViewController as? SidebarSplitViewController)?.sidebar?.loadFavorites()
        }
        
        let share = UIAction(title: NSLocalizedString("menuItems.share", comment: "The menu item to share a file"), image: UIImage(systemName: "square.and.arrow.up")) { action in
            
            let activityVC = UIActivityViewController(activityItems: urls, applicationActivities: nil)
            activityVC.popoverPresentationController?.sourceView = cell ?? collectionView
            activityVC.popoverPresentationController?.sourceRect = (cell ?? collectionView).bounds
            self.present(activityVC, animated: true, completion: nil)
        }
        
        let openInNewWindow = UIAction(title: NSLocalizedString("menuItems.openInNewWindow", comment: "The 'Open in new Window' menu item."), image: UIImage(systemName: "square.grid.2x2")) { action in
            
            guard let url = urls.first else {
                return
            }
            
            let options = UIScene.ActivationRequestOptions()
            options.requestingScene = self.view.window?.windowScene
            
            guard let data = try? self.directory.bookmarkData() else {
                return
            }
            
            var isDir: ObjCBool = false
            _ = FileManager.default.fileExists(atPath: url.path, isDirectory: &isDir)
            
            let bookmarkData = try? url.bookmarkData()
            guard isDir.boolValue || bookmarkData != nil else {
                return
            }
            
            let sceneState = SceneDelegate.SceneState(directoryBookmarkData: isDir.boolValue ? bookmarkData! : data, section: isDir.boolValue ? .fileBrowser : .editor(bookmarkData!))
            
            guard let sceneStateData = try? JSONEncoder().encode(sceneState) else {
                return
            }
            
            let userActivity = NSUserActivity(activityType: "pyto")
            userActivity.addUserInfoEntries(from: ["sceneState": sceneStateData])
            UIApplication.shared.requestSceneSessionActivation(nil, userActivity: userActivity, options: options)
        }
        
        let saveTo: UIAction
        if !isiOSAppOnMac {
            saveTo = UIAction(title: NSLocalizedString("menuItems.saveToFiles", comment: "The menu item to save a file to Files"), image: UIImage(systemName: "folder")) { action in
                
                self.present(UIDocumentPickerViewController(forExporting: urls, asCopy: true), animated: true, completion: nil)
            }
        } else {
            saveTo = UIAction(title: NSLocalizedString("Show in Finder", comment: "The 'Show in Finder' menu item"), image: UIImage(systemName: "folder")) { action in
                
                Dynamic.NSWorkspace.sharedWorkspace.activateFileViewerSelectingURLs(urls)
            }
        }
                
        let rename = UIAction(title: NSLocalizedString("menuItems.rename", comment: "The 'Rename' menu item"), image: UIImage(systemName: "pencil")) { action in
            
            guard let url = urls.first else {
                return
            }
            
            let file = url
            
            var textField: UITextField!
            let alert = UIAlertController(title: "\(NSLocalizedString("menuItems.rename", comment: "The 'Rename' menu item")) '\(file.lastPathComponent)'", message: NSLocalizedString("creation.typeFileName", comment: "The message of the alert shown for creating a file"), preferredStyle: .alert)
            
            alert.addAction(UIAlertAction(title: NSLocalizedString("menuItems.rename", comment: "The 'Rename' menu item"), style: .default, handler: { [weak self] (_) in
                do {
                    
                    let name = textField.text ?? ""
                    let newURL = file.deletingLastPathComponent().appendingPathComponent(name)
                    
                    if !name.isEmpty {
                        try FileManager.default.moveItem(at: file, to: newURL)
                    }
                    
                    if url == self?.directory {
                        self?.directory = url
                    }
                    (self?.splitViewController as? SidebarSplitViewController)?.sidebar?.loadFavorites()
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
                for url in urls {
                    try FileManager.default.removeItem(at: url)
                }
                self.load()
            } catch {
                let alert = UIAlertController(title: NSLocalizedString("errors.errorRemovingFile", comment: "Title of the alert shown when an error occurred while removing a file"), message: error.localizedDescription, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: NSLocalizedString("cancel", comment: "'Cancel' button"), style: .cancel, handler: nil))
                self.present(alert, animated: true, completion: nil)
            }
        }
        
        let run = UIAction(title: NSLocalizedString("menuItems.run", comment: "The 'Run' menu item"), image: UIImage(systemName: "play")) { action in
            
            guard let url = urls.first else {
                return
            }
            
            var path = (url.relativePath(from: self.directory) ?? url.path).replacingOccurrences(of: "'", with: "\\'")
            if !path.contains("/") {
                path = "./"+path
            }
            self.run(cmd: "python '\(path)' ", onlyWrite: false)
        }
        
        var isDir: ObjCBool = false
        _ = FileManager.default.fileExists(atPath: urls[0].path, isDirectory: &isDir)
        
        let isPackage = isDir.boolValue && ((((try? FileManager.default.contentsOfDirectory(atPath: urls[0].path))?.contains("__init__.py")) == true) || (((try? FileManager.default.contentsOfDirectory(atPath: urls[0].path))?.contains("__main__.py")) == true))
        
        let open = UIMenu(title: "", options: .displayInline, children: urls.count == 1 ? [
            UIAction(title: NSLocalizedString("menuItems.open", comment: "The 'Open' menu item"), image: UIImage(systemName: "chevron.right"), handler: { [weak self] _ in
                let browser = FileBrowserViewController()
                browser.directory = urls[0]
                self?.navigationController?.pushViewController(browser, animated: true)
            })
        ] : [])
        
        let showAddToFavorites: Bool
        if #available(iOS 16.0, *) {
            showAddToFavorites = !SidebarViewController.favorites.contains(urls)
        } else {
            showAddToFavorites = true
        }
        
        let top = UIMenu(title: "", options: .displayInline, children: (create != nil ? [create!] : []) + (isEmpty ? [] : [open]) + (showAddToFavorites ? [addToFavorites] : []))
        let middle = UIMenu(title: "", options: .displayInline, children: ((UIApplication.shared.supportsMultipleScenes && urls.count == 1) ? [openInNewWindow] : [])+(((urls.first?.pathExtension.lowercased() == "py" || urls.first?.pathExtension.lowercased() == "html" || isPackage) && urls.count == 1) ? [run] : []))
        let bottom = UIMenu(title: "", options: .displayInline, children: [share, saveTo] + (isEmpty ? [] : [rename, delete]))
        
        return UIContextMenuConfiguration(identifier: nil, previewProvider: nil) { (_) -> UIMenu? in
            
            return UIMenu(title: urls.map({ $0.lastPathComponent }).joined(separator: ", "), children: [top, middle, bottom])
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
    
    // MARK: - Navigation item rename delegate
    
    public func navigationItem(_: UINavigationItem, didEndRenamingWith title: String) {
        
        let newURL = directory.deletingLastPathComponent().appendingPathComponent(title)
        
        do {
            try FileManager.default.moveItem(at: directory, to: newURL)
            directory = newURL
        } catch {
            let alert = UIAlertController(title: NSLocalizedString("error", comment: "Error"), message: error.localizedDescription, preferredStyle: .alert)
            alert.addAction(UIAlertAction(title: NSLocalizedString("cancel", comment: "Cancel"), style: .cancel))
            present(alert, animated: true)
        }
    }
    
    public func navigationItemShouldBeginRenaming(_: UINavigationItem) -> Bool {
        FileManager.default.isWritableFile(atPath: directory.deletingLastPathComponent().path) && directory != Self.iCloudContainerURL
    }
}
