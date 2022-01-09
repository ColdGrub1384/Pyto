//
//  SidebarViewController.swift
//  Pyto
//
//  Created by Emma on 10-11-21.
//  Copyright © 2021 Emma Labbé. All rights reserved.
//

import UIKit
import SwiftUI
import MobileCoreServices
import Dynamic

fileprivate struct Item: Hashable {
    let title: String?
    let image: UIImage?
    let section: Section
    private let identifier = UUID()
}

fileprivate let tabsItems = [
    Item(title: NSLocalizedString("Create", comment: "Create script"), image: UIImage(systemName: "plus.square.fill"), section: .tabs),
    Item(title: NSLocalizedString("Open script", comment: "Open script"), image: UIImage(systemName: "square.and.arrow.down"), section: .tabs),
    Item(title: NSLocalizedString("Open directory", comment: "Open directory"), image: UIImage(systemName: "folder"), section: .tabs)
]

fileprivate let pythonItems = [
    Item(title: NSLocalizedString("repl", comment: "The REPL"), image: UIImage(systemName: "play"), section: .python),
    Item(title: "Shell", image: UIImage(systemName: "chevron.left.forwardslash.chevron.right"), section: .python),
    Item(title: NSLocalizedString("sidebar.pypi", comment: "PyPI"), image: UIImage(systemName: "cloud"), section: .python),
    Item(title: "site-packages", image: UIImage(systemName: "shippingbox"), section: .python),
    Item(title: NSLocalizedString("sidebar.loadedModules", comment: "Loaded modules"), image: UIImage(systemName: "info.circle"), section: .python)
]
    
fileprivate let resourcesItems = [
    Item(title: NSLocalizedString("sidebar.examples", comment: "Examples"), image: UIImage(systemName: "bookmark"), section: .resources),
    Item(title: NSLocalizedString("help.documentation", comment: "'Documentation' button"), image: UIImage(systemName: "book"), section: .resources),
]
    
fileprivate enum Section: String {
    
    var localizedString: String {
        switch self {
        case .recents:
            return NSLocalizedString("sidebar.recent", comment: "'Recents' section header")
        case .favorites:
            return NSLocalizedString("sidebar.favorites", comment: "'Favorites' section header")
        case .python:
            return NSLocalizedString("sidebar.python", comment: "'Python' section header")
        case .resources:
            return NSLocalizedString("sidebar.resources", comment: "'Resources' section header")
        case .tabs:
            return ""
        }
    }
    
    case tabs
    case recents = "sidebar.recent"
    case favorites = "sidebar.favorites"
    case python = "sidebar.python"
    case resources = "sidebar.resources"
}

@objc class SidebarViewController: UICollectionViewController, UIDocumentPickerDelegate, UICollectionViewDropDelegate, UICollectionViewDragDelegate {
    
    /// The Pyto version.
    @objc static var pytoVersion: String {
        
        var buildDate: Date {
            if let infoPath = Bundle.main.path(forResource: "Info", ofType: "plist"), let infoAttr = try? FileManager.default.attributesOfItem(atPath: infoPath), let infoDate = infoAttr[.creationDate] as? Date {
                return infoDate
            } else {
                return Date()
            }
        }
        
        guard let version = Bundle.main.infoDictionary?["CFBundleShortVersionString"] as? String, let build = Bundle.main.infoDictionary?[kCFBundleVersionKey as String] as? String else {
            return ""
        }
        
        guard let baseSDK = Bundle.main.infoDictionary?["DTSDKName"] as? String else {
            return ""
        }
        
        let formatter = DateFormatter()
        formatter.dateStyle = .medium
        formatter.timeStyle = .short
        
        return "Pyto version \(version) (\(build)) \(baseSDK) \(formatter.string(from: buildDate))"
    }
    
    class NavigationController: UINavigationController {
        
        var vc: UIViewController?
        
        override init(rootViewController: UIViewController) {
            super.init(rootViewController: rootViewController)
            
            vc = rootViewController
        }
        
        required init?(coder aDecoder: NSCoder) {
            fatalError("init(coder:) has not been implemented")
        }
    }
    
    private var dataSource: UICollectionViewDiffableDataSource<Section, Item>! = nil
    
    var repl: NavigationController?
    
    var moduleRunner: NavigationController?
    
    var pypi: NavigationController?
    
    var loadedModules: NavigationController?
    
    var examples: NavigationController?
    
    var documentation: NavigationController?
    
    var editor: NavigationController?
    
    static var splitViews = [SidebarSplitViewController]()
    
    var compact = false
    
    static func makePyPiView() -> UIViewController {
        
        class ViewController: UIViewController {
            
            override func viewDidAppear(_ animated: Bool) {
                super.viewDidAppear(animated)
                
                view.window?.windowScene?.title = "PyPI"
            }
            
            @objc func close() {
                dismiss(animated: true, completion: nil)
            }
        }
        
        let vc = ViewController()
        
        func run(command: String) {
            let installer = PipInstallerViewController(command: command)
            let _navVC = ThemableNavigationController(rootViewController: installer)
            _navVC.modalPresentationStyle = .formSheet
            vc.present(_navVC, animated: true, completion: nil)
        }
        
        let view = PyPiView(hostingController: vc) { package, install, remove in
            
            if install {
                run(command: "--verbose install \(package)")
            } else if remove {
                run(command: "--verbose uninstall \(package)")
            } else {
                if let pypi = UIStoryboard(name: "Main", bundle: .main).instantiateViewController(withIdentifier: "pypi") as? PipViewController {
                    
                    let loadingVC = UIViewController()
                    loadingVC.view = UIActivityIndicatorView(style: .medium)
                    (loadingVC.view as! UIActivityIndicatorView).startAnimating()
                    loadingVC.view.backgroundColor = .systemBackground
                    
                    vc.show(loadingVC, sender: nil)
                    
                    DispatchQueue.global().async {
                        let pyPackage = PyPackage(name: package)
                        
                        DispatchQueue.main.async {
                            
                            pypi.currentPackage = pyPackage
                            if let name = pyPackage?.name {
                                pypi.title = name
                            }
                            
                            let navVC = loadingVC.navigationController
                            
                            if let i = navVC?.viewControllers.firstIndex(of: loadingVC) {
                                navVC?.viewControllers.remove(at: i)
                            }
                            
                            navVC?.pushViewController(pypi, animated: false)
                        }
                    }
                }
            }
        }
        
        let hostVC = UIHostingController(rootView: view)
        vc.addChild(hostVC)
        vc.view.addSubview(hostVC.view)
        hostVC.view.frame = vc.view.frame
        hostVC.view.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        
        vc.title = "PyPI"
        
        return vc
    }
    
    init(splitViewID: UUID, compact: Bool) {
        super.init(collectionViewLayout: UICollectionViewCompositionalLayout { section, layoutEnvironment in
            var config = UICollectionLayoutListConfiguration(appearance: .sidebar)
            config.headerMode = section == 0 ? .none : .firstItemInSection
            config.footerMode = section == 4 ? .supplementary : .none
            
            return NSCollectionLayoutSection.list(using: config, layoutEnvironment: layoutEnvironment)
        })
        self.compact = compact
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    var recent = [URL]()
    
    func loadRecents() {
        let section = Section.recents
        var items = [Item]()
        
        recent = []
        var recentItems = RecentDataSource.shared.recent
        
        if compact {
            recentItems.append((splitViewController as! SidebarSplitViewController).compactFileBrowser.directory)
        }
        
        for item in recentItems.reversed() {
            recent.append(item)
            
            let image: UIImage!
            
            var isDir: ObjCBool = false
            if FileManager.default.fileExists(atPath: item.path, isDirectory: &isDir) && isDir.boolValue {
                image = UIImage(systemName: "folder")
            } else {
                if item.pathExtension.lowercased() == "py" {
                    image = UIImage(named: "python.SFSymbol")
                } else {
                    image = UIImage(systemName: "doc.fill")
                }
            }
            
            let title: String
            if item == FileBrowserViewController.iCloudContainerURL {
                title = "iCloud Drive"
            } else {
                title = item.lastPathComponent
            }
            items.append(Item(title: title, image: image, section: .recents))
        }
        
        loadViewIfNeeded()
        
        let headerItem = Item(title: section.localizedString, image: nil, section: .recents)
        var sectionSnapshot = NSDiffableDataSourceSectionSnapshot<Item>()
        sectionSnapshot.append([headerItem])
        sectionSnapshot.append(items, to: headerItem)
        if let item = dataSource.snapshot(for: .recents).items.first {
            if dataSource.snapshot(for: .recents).isExpanded(item) {
                sectionSnapshot.expand([headerItem])
            } else {
                sectionSnapshot.collapse([headerItem])
            }
        } else {
            sectionSnapshot.collapse([headerItem])
        }
        dataSource.apply(sectionSnapshot, to: section)
    }
    
    static var favorites: [URL] {
        get {
            ((UserDefaults.standard.array(forKey: "sidebarFavorites") as? [Data]) ?? []).compactMap {
                var isStale = false
                return (try? URL(resolvingBookmarkData: $0, bookmarkDataIsStale: &isStale))
            }
        }
        
        set {
            UserDefaults.standard.set(newValue.compactMap({
                try? $0.bookmarkData()
            }), forKey: "sidebarFavorites")
        }
    }
    
    var favorites = [URL]()
    
    func loadFavorites() {
        let section = Section.favorites
        var items = [Item]()
        
        favorites = []
        
        for item in Self.favorites {
            favorites.append(item)
            
            let image: UIImage!
            
            var isDir: ObjCBool = false
            if FileManager.default.fileExists(atPath: item.path, isDirectory: &isDir) && isDir.boolValue {
                image = UIImage(systemName: "folder")
            } else {
                if item.pathExtension.lowercased() == "py" {
                    image = UIImage(named: "python.SFSymbol")
                } else {
                    image = UIImage(systemName: "doc.fill")
                }
            }
            
            let title: String
            if item == FileBrowserViewController.iCloudContainerURL {
                title = "iCloud Drive"
            } else {
                title = item.lastPathComponent
            }
            items.append(Item(title: title, image: image, section: .favorites))
        }
        
        loadViewIfNeeded()
        
        let headerItem = Item(title: section.localizedString, image: nil, section: .favorites)
        var sectionSnapshot = NSDiffableDataSourceSectionSnapshot<Item>()
        sectionSnapshot.append([headerItem])
        sectionSnapshot.append(items, to: headerItem)
        sectionSnapshot.expand([headerItem])
        dataSource.apply(sectionSnapshot, to: section)
    }
    
    @objc func showSettings() {
        let vc = UIStoryboard(name: "SettingsView", bundle: .main).instantiateInitialViewController()
        vc?.modalPresentationStyle = .formSheet
        let navVC = UINavigationController(rootViewController: vc!)
        navVC.modalPresentationStyle = .formSheet
        navVC.navigationBar.prefersLargeTitles = true
        present(navVC, animated: true)
    }
    
    @objc func showExamples() {
        if examples == nil {
            examples = NavigationController(rootViewController: UIHostingController(rootView: SamplesNavigationView(url: Bundle.main.url(forResource: "Samples", withExtension: nil)!, selectScript: { [weak self] script in
                self?.open(url: script)
            }).withoutNavigation))
            examples?.navigationBar.prefersLargeTitles = true
        }
        
        show(vc: examples!)
    }
    
    @objc func showDocumentationOnSplitView() {
        if documentation == nil {
            documentation = NavigationController(rootViewController: DocumentationViewController())
            documentation?.navigationBar.prefersLargeTitles = false
        }
            
        show(vc: documentation!)
    }
    
    @objc func showPyPI() {
        if pypi == nil {
            pypi = NavigationController(rootViewController: Self.makePyPiView())
            pypi!.navigationBar.prefersLargeTitles = true
        }
        
        show(vc: pypi!)
    }
    
    @objc func showREPL() {
        if repl == nil {
            repl = NavigationController(rootViewController: REPLViewController())
        }
        
        show(vc: repl!)
    }
    
    func makeModuleRunnerIfNecessary() {
        if moduleRunner == nil {
            moduleRunner = NavigationController(rootViewController: UIStoryboard(name: "Main", bundle: .main).instantiateViewController(withIdentifier: "runModule"))
        }
    }
    
    func showModuleRunner() {
        makeModuleRunnerIfNecessary()
        
        show(vc: moduleRunner!)
    }
    
    func showLoadedModules() {
        if loadedModules == nil {
            loadedModules = NavigationController(rootViewController: ModulesTableViewController(style: .grouped))
        }
        
        show(vc: loadedModules!)
    }
    
    func install(wheel: URL) {
        
        let isShellRunning = self.moduleRunner?.vc != nil
        
        let alert = UIAlertController(title: wheel.lastPathComponent.components(separatedBy: "-").first ?? wheel.lastPathComponent, message: "Do you want to install this wheel?", preferredStyle: .alert)
        
        alert.addAction(UIAlertAction(title: "Install", style: .default, handler: { _ in
            self.showModuleRunner()
            DispatchQueue.main.asyncAfter(deadline: .now()+(isShellRunning ? 0.2 : 2.5)) {
                let console = (self.moduleRunner?.vc as? RunModuleViewController)?.console
                console?.addToHistory = false
                console?.movableTextField?.handler?("pip install --force-reinstall '\(wheel.path.replacingOccurrences(of: "'", with: "\\'"))'")
            }
        }))
        
        alert.addAction(UIAlertAction(title: "Cancel", style: .cancel, handler: nil))
        present(alert, animated: true, completion: nil)
    }
    
    @objc func newScript() {
        let templateChooser = TemplateChooser(parent: self, chooseName: false) { [weak self] url, _ in
            self?.dismiss(animated: true, completion: {
                if let url = url {
                    let docPicker = UIDocumentPickerViewController(forExporting: [url], asCopy: false)
                    docPicker.delegate = self
                    self?.present(docPicker, animated: true, completion: nil)
                }
            })
        }
        
        self.present(UIHostingController(rootView: templateChooser), animated: true, completion: nil)
    }
    
    @objc func newProject() {
        if #available(iOS 15.0, *) {
            let creator = ProjectCreator { [weak self] url in
                self?.dismiss(animated: true, completion: {
                    self?.documentPicker(UIDocumentPickerViewController(forExporting: [url]), didPickDocumentsAt: [url])
                })
            }
            self.present(UIHostingController(rootView: creator), animated: true, completion: nil)
        }
    }
    
    func makeBarButtonItem() -> UIBarButtonItem {
        UIBarButtonItem(title: nil, image: UIImage(systemName: "ellipsis.circle"), primaryAction: nil, menu: UIMenu(title: "", image: nil, identifier: nil, options: [], children: [
        
            UIAction(title: NSLocalizedString("settings", comment: "Settings"), image: UIImage(systemName: "gear"), identifier: nil, discoverabilityTitle: NSLocalizedString("settings", comment: "Settings"), attributes: [], state: .off, handler: { [weak self] _ in
                self?.showSettings()
            }),
            
            UIAction(title: NSLocalizedString("sidebar.editSidebar", comment: "Edit sidebar"), image: nil, identifier: nil, discoverabilityTitle: NSLocalizedString("sidebar.editSidebar", comment: "Edit sidebar"), attributes: [], state: .off, handler: { [weak self] _ in
                self?.setEditing(true, animated: true)
            })
        ]))
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        title = "Pyto"
        navigationItem.largeTitleDisplayMode = .always
        navigationItem.backButtonDisplayMode = .minimal
        
        let headerRegistration = UICollectionView.CellRegistration<UICollectionViewListCell, Item> { (cell, indexPath, item) in
            var content = cell.defaultContentConfiguration()
            content.text = item.title
            cell.contentConfiguration = content
            cell.accessories = [.outlineDisclosure()]
        }
                
        let cellRegistration = UICollectionView.CellRegistration<UICollectionViewListCell, Item> { (cell, indexPath, item) in
            var content = cell.defaultContentConfiguration()
            content.text = item.title
            content.image = item.image
            if (indexPath.section == 1 || indexPath.section == 2) && item.title?.lowercased().hasSuffix(".py") == true {
                content.imageProperties.preferredSymbolConfiguration = UIImage.SymbolConfiguration(font: .preferredFont(forTextStyle: .largeTitle, compatibleWith: nil))
            }

            cell.contentConfiguration = content
            
            if item.section == .tabs && indexPath.row == 0 {
                let button = UIButton()
                button.frame = cell.contentView.frame
                button.autoresizingMask = [.flexibleWidth, .flexibleHeight]
                
                var iOS15: Bool
                if #available(iOS 15.0, *) {
                    iOS15 = true
                } else {
                    iOS15 = false
                }
                
                button.menu = UIMenu(title: "Create", image: nil, identifier: nil, options: [], children: [
                    UIAction(title: "Script", image: UIImage(systemName: "curlybraces"), identifier: nil, discoverabilityTitle: "Script", attributes: [], state: .off, handler: { [weak self] _ in
                        self?.newScript()
                    }),
                    
                    UIAction(title: "Project", image: UIImage(systemName: "shippingbox"), identifier: nil, discoverabilityTitle: "Project", attributes: !iOS15 ? [.disabled] : [], state: .off, handler: { [weak self] _ in
                        if #available(iOS 15.0, *) {
                            self?.newProject()
                        }
                    }),
                ])
                button.showsMenuAsPrimaryAction = true
                cell.contentView.addSubview(button)
            } else if item.section == .favorites {
                cell.accessories = [.delete(actionHandler: { [weak self] in
                    if self?.favorites.indices.contains(indexPath.row-1) == true {
                        self?.favorites.remove(at: indexPath.row-1)
                        Self.favorites = self!.favorites
                        self?.loadFavorites()
                    }
                }), .reorder()]
            } else if item.section == .recents {
                cell.accessories = [.delete(actionHandler: { [weak self] in
                    var recent = Array(RecentDataSource.shared.recent.reversed())
                    if recent.indices.contains(indexPath.row-1) {
                        recent.remove(at: indexPath.row-1)
                    }
                    RecentDataSource.shared.recent = recent.reversed()
                    RecentDataSource.shared.didSetRecent = {
                        self?.loadRecents()
                        RecentDataSource.shared.didSetRecent = nil
                    }
                })]
            } else {
                cell.accessories = []
            }
        }
        
        let footerRegistration = UICollectionView.SupplementaryRegistration<UICollectionViewListCell>(elementKind: UICollectionView.elementKindSectionFooter) { (cell, indexPath, item) in
            var content = cell.defaultContentConfiguration()
            content.text = """
            \(Self.pytoVersion)
            
            Python \(Python.shared.version)
            """
            content.textProperties.color = .secondaryLabel
            content.textProperties.numberOfLines = 0
            content.textProperties.lineBreakMode = .byWordWrapping
            content.textProperties.font = UIFont.preferredFont(forTextStyle: .footnote, compatibleWith: nil)
            cell.contentConfiguration = content
        }

        // Creating the datasource
        dataSource = UICollectionViewDiffableDataSource<Section, Item>(collectionView: collectionView) { (collectionView: UICollectionView, indexPath: IndexPath, item: Item) -> UICollectionViewCell? in
            
            if indexPath.item == 0 && indexPath.section != 0 {
                return collectionView.dequeueConfiguredReusableCell(using: headerRegistration, for: indexPath, item: item)
            } else {
                return collectionView.dequeueConfiguredReusableCell(using: cellRegistration, for: indexPath, item: item)
            }
        }
        
        dataSource.supplementaryViewProvider = { (collectionView, elementKind, indexPath) -> UICollectionReusableView? in
            
            if indexPath.section == 4 && elementKind == UICollectionView.elementKindSectionFooter {
                return collectionView.dequeueConfiguredReusableSupplementary(
                    using: footerRegistration, for: indexPath)
            } else {
                return nil
            }
        }
        
        // Creating and applying snapshots
        let sections: [Section] = [.tabs, .recents, .favorites, .python, .resources]
        var snapshot = NSDiffableDataSourceSnapshot<Section, Item>()
        snapshot.appendSections(sections)

        for section in sections {
            switch section {
            case .tabs:
                var sectionSnapshot = NSDiffableDataSourceSectionSnapshot<Item>()
                sectionSnapshot.append(tabsItems)
                dataSource.apply(sectionSnapshot, to: section)
            case .recents:
                loadRecents()
            case .favorites:
                loadFavorites()
            case .python:
                let headerItem = Item(title: section.localizedString, image: nil, section: .python)
                var sectionSnapshot = NSDiffableDataSourceSectionSnapshot<Item>()
                sectionSnapshot.append([headerItem])
                sectionSnapshot.append(pythonItems, to: headerItem)
                sectionSnapshot.expand([headerItem])
                dataSource.apply(sectionSnapshot, to: section)
            case .resources:
                let headerItem = Item(title: section.localizedString, image: nil, section: .resources)
                var sectionSnapshot = NSDiffableDataSourceSectionSnapshot<Item>()
                sectionSnapshot.append([headerItem])
                sectionSnapshot.append(resourcesItems, to: headerItem)
                sectionSnapshot.expand([headerItem])
                dataSource.apply(sectionSnapshot, to: section)
            }
        }
                
        collectionView.dropDelegate = self
        collectionView.dragDelegate = self
        
        navigationItem.rightBarButtonItem = makeBarButtonItem()
    }
    
    public override func setEditing(_ editing: Bool, animated: Bool) {
        super.setEditing(editing, animated: animated)
        
        if editing {
            navigationItem.rightBarButtonItem = editButtonItem
        } else {
            navigationItem.rightBarButtonItem = makeBarButtonItem()
        }
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        navigationController?.setToolbarHidden(true, animated: true)
    }
        
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        navigationController?.navigationBar.prefersLargeTitles = true
        loadRecents()
    }
    
    func show(vc: NavigationController) {
        
        if vc.viewControllers.first == nil {
            vc.viewControllers = [vc.vc!]
        }
        
        if splitViewController?.isCollapsed == true {
            navigationController?.pushViewController(vc.vc!, animated: true)
        } else {
            splitViewController?.setViewController(vc, for: .secondary)
        }
    }
    
    func run(code: String) {
        let url = URL(fileURLWithPath: NSTemporaryDirectory()+"/Script.py")
        if FileManager.default.fileExists(atPath: url.path) {
            try? FileManager.default.removeItem(at: url)
        }
        FileManager.default.createFile(atPath: url.path, contents: code.data(using: .utf8), attributes: nil)
        open(url: url, run: true)
    }
    
    @discardableResult func openDocument(_ documentURL: URL, run: Bool, viewController: UIViewController? = nil, isShortcut: Bool = false, folder: URL? = nil, animated: Bool = true, completion: (() -> Void)? = nil) -> EditorSplitViewController? {
        
        let tintColor = ConsoleViewController.choosenTheme.tintColor ?? .systemGreen
        
        let document = PyDocument(fileURL: documentURL)
        
        let isPip = (documentURL.path == Bundle.main.path(forResource: "installer", ofType: "py"))
                
        let editor = EditorViewController(document: document)
        editor.shouldRun = run
        editor.isShortcut = isShortcut
        
        let contentVC = ConsoleViewController()
        contentVC.view.backgroundColor = .white
        
        let splitVC = EditorSplitViewController()
        splitVC.folder = folder
        
        if isPip {
            splitVC.ratio = 0
        }
        
        if splitViewController?.traitCollection.horizontalSizeClass == .compact && !EditorSplitViewController.shouldShowConsoleAtBottom {
            splitVC.ratio = 1
        }
        
        let navVC = EditorSplitViewController.NavigationController(rootViewController: splitVC)
        navVC.modalPresentationStyle = .fullScreen
        navVC.navigationBar.isTranslucent = true
                
        splitVC.separatorColor = .clear
        splitVC.separatorSelectedColor = tintColor
        splitVC.editor = editor
        splitVC.console = contentVC
        if EditorSplitViewController.shouldShowConsoleAtBottom { // Please, don't remove this condition :)
            splitVC.firstChild = editor
            splitVC.secondChild = contentVC
        }
        splitVC.view.backgroundColor = .systemBackground
        
        splitVC.arrangement = .horizontal
                        
        return splitVC
    }
    
    func open(url: URL, reloadRecents: Bool = false, run: Bool = false, completion: ((EditorViewController) -> Void)? = nil) {
        if self.editor == nil {
            if let editor = openDocument(url, run: false, folder: nil) {
                let navVC = NavigationController(rootViewController: editor)
                navVC.navigationBar.prefersLargeTitles = false
                editor.navigationItem.largeTitleDisplayMode = .never
                self.editor = navVC
            } else {
                return
            }
        }
        
        if let editor = (self.editor?.vc as? EditorSplitViewController)?.editor {
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
                        
                        completion?(editor)
                    }
                })
            }
        }
        
        RecentDataSource.shared.didSetRecent = {
            
            if reloadRecents {
                self.loadRecents()
                var i = 0
                var indexPath: IndexPath?
                for item in self.recent {
                    if item == url {
                        indexPath = IndexPath(item: i, section: 1)
                        break
                    }
                    i += 1
                }
                
                if let indexPath = indexPath {
                    self.collectionView.selectItem(at: indexPath, animated: true, scrollPosition: .centeredVertically)
                }
            }
            
            RecentDataSource.shared.didSetRecent = nil
        }
        RecentDataSource.shared.recent.append(url)
        RecentDataSource.shared.didSetRecent = { [weak self] in
            self?.loadRecents()
            RecentDataSource.shared.didSetRecent = nil
        }
        
        show(vc: editor!)
        
        if run {
            (editor?.vc as? EditorSplitViewController)?.editor?.run()
        }
    }
    
    func openScript() {
        let docPicker = UIDocumentPickerViewController(forOpeningContentTypes: [.pythonScript, .init(filenameExtension: "html")!])
        docPicker.delegate = self
        present(docPicker, animated: true, completion: nil)
    }
    
    override func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        
        switch indexPath.section {
        case 0:
            // Pyto
            switch indexPath.row {
            case 1:
                // Open script
                openScript()
            case 2:
                // Open directory
                let docPicker = UIDocumentPickerViewController(forOpeningContentTypes: [.folder])
                docPicker.delegate = self
                present(docPicker, animated: true, completion: nil)
            default:
                break
            }
        case 1:
            // Recent
            var isDir: ObjCBool = false
            if FileManager.default.fileExists(atPath: recent[indexPath.row-1].path, isDirectory: &isDir) && isDir.boolValue {
                (splitViewController as! SidebarSplitViewController).compactFileBrowser.directory = recent[indexPath.row-1]
                (splitViewController as! SidebarSplitViewController).fileBrowser.directory = recent[indexPath.row-1]
                show(vc: (splitViewController as! SidebarSplitViewController).compactFileBrowserNavVC)
            } else {
                open(url: recent[indexPath.row-1])
            }
        case 2:
            // Favorites
            var isDir: ObjCBool = false
            if FileManager.default.fileExists(atPath: favorites[indexPath.row-1].path, isDirectory: &isDir) && isDir.boolValue {
                (splitViewController as! SidebarSplitViewController).compactFileBrowser.directory = favorites[indexPath.row-1]
                (splitViewController as! SidebarSplitViewController).fileBrowser.directory = favorites[indexPath.row-1]
                
                let picker = UIDocumentPickerViewController(forOpeningContentTypes: [.folder])
                (repl?.vc as? REPLViewController)?.documentPicker(picker, didPickDocumentsAt: [favorites[indexPath.row-1]])
                (moduleRunner?.vc as? RunModuleViewController)?.documentPicker(picker, didPickDocumentsAt: [favorites[indexPath.row-1]])
                
                if splitViewController?.isCollapsed == true {
                    show(vc: (splitViewController as! SidebarSplitViewController).compactFileBrowserNavVC)
                }
            } else {
                open(url: favorites[indexPath.row-1])
            }
        case 3:
            // Python
            switch indexPath.row-1 {
            case 0:
                // REPL
                showREPL()
            case 1:
                // Run module
                showModuleRunner()
            case 2:
                // PyPI
                showPyPI()
            case 3:
                // site-packages
                
                let browser = FileBrowserViewController()
                
                let site_packages = Python.pythonShared?.perform(#selector(PythonRuntime.getString(_:)), with: """
                    import site
                    s = site.getusersitepackages()
                    """)
                
                guard let path = site_packages?.takeUnretainedValue() as? String else {
                    return
                }
                
                let url = URL(fileURLWithPath: path)
                
                if !FileManager.default.fileExists(atPath: url.path) {
                    try? FileManager.default.createDirectory(at: url, withIntermediateDirectories: false, attributes: nil)
                }
                browser.directory = url
                
                if splitViewController?.isCollapsed == false {
                    (splitViewController as! SidebarSplitViewController).fileBrowserNavVC.pushViewController(browser, animated: true)
                } else {
                    show(vc: NavigationController(rootViewController: browser))
                }
            case 4:
                // Loaded modules
                showLoadedModules()
            default:
                break
            }
        case 4:
            // Resources
            switch indexPath.row-1 {
            case 0:
                // Examples
                
                showExamples()
            case 1:
                // Documentation
                showDocumentationOnSplitView()
            default:
                break
            }
        default:
            break
        }
    }
    
    func documentPicker(_ controller: UIDocumentPickerViewController, didPickDocumentsAt urls: [URL]) {
        _ = urls.first?.startAccessingSecurityScopedResource()
        
        var isDir: ObjCBool = false
        if FileManager.default.fileExists(atPath: urls.first!.path, isDirectory:  &isDir) && isDir.boolValue {
            
            (splitViewController as? SidebarSplitViewController)?.compactFileBrowser.directory = urls.first!
            (splitViewController as? SidebarSplitViewController)?.fileBrowser.directory = urls.first!
            
            loadRecents()
            
            if (splitViewController?.isCollapsed == true), let browser = (splitViewController as? SidebarSplitViewController)?.compactFileBrowserNavVC {
                show(vc: browser)
            }
            
            (repl?.vc as? REPLViewController)?.documentPicker(controller, didPickDocumentsAt: urls)
            (moduleRunner?.vc as? RunModuleViewController)?.documentPicker(controller, didPickDocumentsAt: urls)
        } else {
            open(url: urls.first!, reloadRecents: true)
        }
    }
    
    public func collectionView(_ collectionView: UICollectionView, canHandle session: UIDropSession) -> Bool {
        return session.hasItemsConforming(toTypeIdentifiers: [kUTTypeItem as String]) || session.items.filter({ $0.localObject is Item }).count > 0
    }
    
    func collectionView(_ collectionView: UICollectionView, dropSessionDidUpdate session: UIDropSession, withDestinationIndexPath destinationIndexPath: IndexPath?) -> UICollectionViewDropProposal {
        
        if destinationIndexPath?.section == 2 {
            return session.items.filter({ $0.localObject is IndexPath }).count > 0 ? .init(operation: UIDropOperation.move, intent: .insertAtDestinationIndexPath) : .init(operation: UIDropOperation.copy, intent: .insertAtDestinationIndexPath)
        } else {
            return .init(operation: .forbidden)
        }
    }
    
    func collectionView(_ collectionView: UICollectionView, performDropWith coordinator: UICollectionViewDropCoordinator) {
        
        var urls = [URL]()
        
        for item in coordinator.items {
            if let indexPath = item.dragItem.localObject as? IndexPath {
                if favorites.indices.contains(indexPath.row-1), let i = coordinator.destinationIndexPath?.row {
                    let item = favorites.remove(at: indexPath.row-1)
                    favorites.insert(item, at: i == 0 ? 0 : i-1)
                    Self.favorites = favorites
                }
            } else if let file = item.dragItem.localObject as? FileBrowserViewController.LocalFile {
                urls.append(file.url)
            } else {
                let semaphore = DispatchSemaphore(value: 0)
                item.dragItem.itemProvider.loadInPlaceFileRepresentation(forTypeIdentifier: kUTTypeItem as String) { url, inPlace, error in
                    
                    if let error = error {
                        print(error.localizedDescription)
                    }
                    
                    if let url = url, inPlace {
                        urls.append(url)
                    }
                    
                    semaphore.signal()
                }
                semaphore.wait()
            }
        }
        
        let row = coordinator.destinationIndexPath?.row
        Self.favorites.insert(contentsOf: urls, at: ((row == 0 ? 1 : row) ?? 1)-1)
        loadFavorites()
    }
    
    func collectionView(_ collectionView: UICollectionView, itemsForBeginning session: UIDragSession, at indexPath: IndexPath) -> [UIDragItem] {
        
        if indexPath.section == 2 {
            let item = UIDragItem(itemProvider: NSItemProvider(object: "\(indexPath)" as NSItemProviderWriting))
            item.localObject = indexPath
            return [item]
        } else {
            return []
        }
    }
}
