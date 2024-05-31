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
import QuickLook
import InterfaceBuilder

@objc class SidebarViewController: UICollectionViewController, UIDocumentPickerDelegate, UICollectionViewDropDelegate, UICollectionViewDragDelegate, QLPreviewControllerDelegate, QLPreviewControllerDataSource {
    
    private let tabsItems = [
        Item(title: NSLocalizedString("Create", comment: "Create script"), image: UIImage(systemName: "plus.square.fill"), section: .tabs),
        Item(title: NSLocalizedString("Open script", comment: "Open script"), image: UIImage(systemName: "square.and.arrow.down"), section: .tabs),
        Item(title: NSLocalizedString("Open directory", comment: "Open directory"), image: UIImage(systemName: "folder"), section: .tabs),
    ]

    private let pythonItems = [
        Item(title: "Terminal", image: UIImage(systemName: "terminal"), section: .python),
        Item(title: NSLocalizedString("sidebar.pypi", comment: "PyPI"), image: UIImage(systemName: "cloud"), section: .python),
        Item(title: "Home", image: UIImage(systemName: "house"), section: .python),
        Item(title: NSLocalizedString("sidebar.loadedModules", comment: "Loaded modules"), image: UIImage(systemName: "info.circle"), section: .python)
    ]
        
    private let resourcesItems = [
        Item(title: NSLocalizedString("sidebar.examples", comment: "Examples"), image: UIImage(systemName: "bookmark"), section: .resources),
        Item(title: NSLocalizedString("help.documentation", comment: "'Documentation' button"), image: UIImage(systemName: "book"), section: .resources),
    ]
    
    struct Item: Hashable {
        var title: String?
        var image: UIImage?
        var section: Section
        var imageColor: UIColor? = nil
        private let identifier = UUID()
    }
    
    enum Section: String {
        
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
            case .workingDirectory:
                return NSLocalizedString("sidebar.cwd", comment: "The working directory on compact view")
            case .tabs:
                return ""
            }
        }
        
        case tabs
        case workingDirectory = "sidebar.cwd"
        case recents = "sidebar.recent"
        case favorites = "sidebar.favorites"
        case python = "sidebar.python"
        case resources = "sidebar.resources"
    }
    
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
    
    var dataSource: UICollectionViewDiffableDataSource<Section, Item>! = nil
    
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
                        
            override func viewDidLoad() {
                super.viewDidLoad()
                
                navigationItem.rightBarButtonItem = UIBarButtonItem(title: NSLocalizedString("pypi.installWheel", comment: "Button for installing a wheel"), image: nil, primaryAction: UIAction(handler: { _ in
                    NotificationCenter.default.post(name: DidPressInstallWheelButtonNotificationName, object: nil)
                }), menu: nil)
            }
            
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
                run(command: "install \(package)")
            } else if remove {
                run(command: "uninstall -y \(package)")
            } else {
                let pypi = PipViewController()
                let loadingVC = UIViewController()
                loadingVC.view = UIActivityIndicatorView(style: .medium)
                (loadingVC.view as! UIActivityIndicatorView).startAnimating()
                loadingVC.view.backgroundColor = .systemBackground
                
                vc.show(loadingVC, sender: nil)
                
                DispatchQueue.global().async {
                    let pyPackage = PyPackage(name: package)
                    
                    DispatchQueue.main.async {
                        
                        pypi.package = pyPackage
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
            config.footerMode = section == (compact ? 5 : 4) ? .supplementary : .none
            
            return NSCollectionLayoutSection.list(using: config, layoutEnvironment: layoutEnvironment)
        })
        self.compact = compact
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    var recent = [URL]()
    
    static func image(for url: URL, forceMonochrome: Bool = false) -> (image: UIImage?, color: UIColor?) {
        var isDir: ObjCBool = false
        if FileManager.default.fileExists(atPath: url.path, isDirectory: &isDir) && isDir.boolValue {
            if FileManager.default.fileExists(atPath: url.appendingPathComponent("__init__.py").path) || FileManager.default.fileExists(atPath: url.appendingPathComponent("__main__.py").path) {
                return (image: UIImage(systemName: "shippingbox.fill"), color: .systemBrown)
            } else {
                return (image: UIImage(systemName: "folder.fill"), color: .systemBlue)
            }
        } else {
            if !(url.pathExtension == "icloud" && url.lastPathComponent.hasPrefix(".")) {
                if ["py", "pyc", "pyx"].contains(url.pathExtension.lowercased()) {
                    
                    let image: UIImage?
                    if forceMonochrome {
                        image = UIImage(named: "python.SFSymbol")?.applyingSymbolConfiguration(UIImage.SymbolConfiguration(font: .systemFont(ofSize: 35)))?.withRenderingMode(.alwaysTemplate)
                    } else if #available(iOS 16.0, *) {
                        let renderer = ImageRenderer(content: Image("python.SFSymbol")
                            .resizable()
                            .symbolRenderingMode(.multicolor)
                            .foregroundStyle(.blue, .yellow)
                            .font(.system(size: 35)))
                        renderer.scale = 2
                        image = renderer.uiImage
                    } else {
                        image = UIImage(named: "python.SFSymbol")?.withRenderingMode(.alwaysOriginal)
                    }
                    
                    return (image: image, color: nil)
                } else if url.pathExtension.lowercased() == "pytoui" {
                    return (image: UIImage(systemName: "ipad"), color: .systemRed)
                } else if ["bc", "ll", "so"].contains(url.pathExtension.lowercased()) {
                    return (image: UIImage(systemName: "terminal.fill"), color: .label)
                } else if ["c", "cc", "cpp", "cxx", "m", "mm"].contains(url.pathExtension.lowercased()) {
                    return (image: UIImage(systemName: "c.square.fill"), color: .systemPurple)
                } else if ["h", "hpp"].contains(url.pathExtension.lowercased()) {
                    return (image: UIImage(systemName: "h.square.fill"), color: .systemPink)
                } else {
                    return (image: UIImage(systemName: "doc.text.fill"), color: .label)
                }
            } else {
                return (image: UIImage(systemName: "icloud.and.arrow.down.fill"), color: .systemBlue)
            }
        }
    }
    
    func loadWorkingDirectory() {
        guard compact else {
            return
        }
        
        var sectionSnapshot = NSDiffableDataSourceSectionSnapshot<Item>()
        sectionSnapshot.append([Item(title: Section.workingDirectory.localizedString, image: nil, section: .workingDirectory)])
        
        if compact, let dir = (splitViewController as? SidebarSplitViewController)?.compactFileBrowser.directory {
            sectionSnapshot.append([Item(title: dir == FileBrowserViewController.iCloudContainerURL ? "iCloud Drive" : FileManager.default.displayName(atPath: dir.path), image: UIImage(systemName: "folder.fill"), section: .workingDirectory, imageColor: .systemBlue)])
        }
        
        dataSource.apply(sectionSnapshot, to: .workingDirectory)
    }
    
    func loadRecents() {
        let section = Section.recents
        var items = [Item]()
        
        recent = []
        let recentItems = RecentDataSource.shared.recent
        
        for item in recentItems.reversed() {
            recent.append(item)
            
            let image: UIImage!
            let color: UIColor?
            
            (image, color) = Self.image(for: item)
            
            let title: String
            if item == FileBrowserViewController.iCloudContainerURL {
                title = "iCloud Drive"
            } else {
                title = item.lastPathComponent
            }
            items.append(Item(title: title, image: image, section: .recents, imageColor: color))
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
            sectionSnapshot.expand([headerItem])
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
            let color: UIColor?
            (image, color) = Self.image(for: item)
            
            let title: String
            if item == FileBrowserViewController.iCloudContainerURL {
                title = "iCloud Drive"
            } else {
                title = item.lastPathComponent
            }
            items.append(Item(title: title, image: image, section: .favorites, imageColor: color))
        }
        
        items.append(Item(title: NSLocalizedString("add", comment: "Add"), image: UIImage(systemName: "plus"), section: .favorites))
        
        loadViewIfNeeded()
        
        let headerItem = Item(title: section.localizedString, image: nil, section: .favorites)
        var sectionSnapshot = NSDiffableDataSourceSectionSnapshot<Item>()
        sectionSnapshot.append([headerItem])
        sectionSnapshot.append(items, to: headerItem)
        sectionSnapshot.expand([headerItem])
        dataSource.apply(sectionSnapshot, to: section)
        
        DispatchQueue.main.async {
            self.reloadFavorites()
        }
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
        
        let url = Bundle.main.url(forResource: "Samples/Examples", withExtension: nil)!
        
        if examples == nil {
            let browser = FileBrowserViewController()
            browser.directory = url
            examples = NavigationController(rootViewController: browser)
            examples?.navigationBar.prefersLargeTitles = true
        }
        
        show(vc: examples!)
    }
    
    func makeDocumentationViewControllerIfNeeded() {
        if documentation == nil {
            documentation = NavigationController(rootViewController: DocumentationViewController())
            documentation?.navigationBar.prefersLargeTitles = false
        }
    }
    
    @objc func showDocumentationOnSplitView() {
        makeDocumentationViewControllerIfNeeded()
        show(vc: documentation!)
    }
    
    var isPickingWheel = false
    
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
        
        let alert = UIAlertController(title: wheel.lastPathComponent.components(separatedBy: "-").first ?? wheel.lastPathComponent, message: NSLocalizedString("pypi.installWheelDialog", comment: "The message of the alert shown before installing a wheel"), preferredStyle: .alert)
        
        alert.addAction(UIAlertAction(title: NSLocalizedString("pypi.install", comment: "Install"), style: .default, handler: { _ in
            self.showModuleRunner()
            DispatchQueue.main.asyncAfter(deadline: .now()+(isShellRunning ? 0.2 : 2.5)) {
                let console = (self.moduleRunner?.vc as? RunModuleViewController)?.console
                console?.addToHistory = false
                console?.movableTextField?.handler?("pip install --force-reinstall '\(wheel.path.replacingOccurrences(of: "'", with: "\\'"))'")
            }
        }))
        
        alert.addAction(UIAlertAction(title: NSLocalizedString("cancel", comment: "'Cancel' button"), style: .cancel, handler: nil))
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
                    self?.documentPicker(UIDocumentPickerViewController(forOpeningContentTypes: [.folder]), didPickDocumentsAt: [url])
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
            
            UIAction(title: NSLocalizedString("sidebar.editSidebar", comment: "Edit sidebar"), image: UIImage(systemName: "pencil"), identifier: nil, discoverabilityTitle: NSLocalizedString("sidebar.editSidebar", comment: "Edit sidebar"), attributes: [], state: .off, handler: { [weak self] _ in
                self?.setEditing(true, animated: true)
            })
        ]))
    }
    
    var favoritesPicker: UIDocumentPickerViewController?
    
    func addToFavorites(folder: Bool) {
        favoritesPicker = UIDocumentPickerViewController(forOpeningContentTypes: folder ? [.folder] : [.item], asCopy: false)
        favoritesPicker!.delegate = self
        present(favoritesPicker!, animated: true, completion: nil)
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
            if (indexPath.section == 1 || indexPath.section == 2 || indexPath.section == 3) && item.title?.lowercased().hasSuffix(".py") == true {
                content.imageProperties.preferredSymbolConfiguration = UIImage.SymbolConfiguration(font: .preferredFont(forTextStyle: .largeTitle, compatibleWith: nil))
            }

            content.imageProperties.tintColor = item.imageColor
            
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
                
                button.menu = UIMenu(title: NSLocalizedString("Create", comment: "'Create' button"), image: nil, identifier: nil, options: [], children: [
                    UIAction(title: "Script", image: UIImage(systemName: "curlybraces"), identifier: nil, discoverabilityTitle: "Script", attributes: [], state: .off, handler: { [weak self] _ in
                        self?.newScript()
                    }),
                    
                    UIAction(title: NSLocalizedString("project", comment: "Project"), image: UIImage(systemName: "shippingbox"), identifier: nil, discoverabilityTitle: NSLocalizedString("project", comment: "Project"), attributes: !iOS15 ? [.disabled] : [], state: .off, handler: { [weak self] _ in
                        if #available(iOS 15.0, *) {
                            self?.newProject()
                        }
                    }),
                ])
                button.showsMenuAsPrimaryAction = true
                cell.contentView.addSubview(button)
            } else if item.section == .favorites {
                if indexPath.row == self.favorites.count+1 { // Add
                    let button = UIButton()
                    button.tag = 5434
                    button.frame = cell.contentView.frame
                    button.autoresizingMask = [.flexibleWidth, .flexibleHeight]
                    
                    
                    button.menu = UIMenu(title: NSLocalizedString("add", comment: "Add"), image: nil, identifier: nil, options: [], children: [
                        UIAction(title: NSLocalizedString("creation.file", comment: "A file"), image: UIImage(systemName: "doc"), identifier: nil, discoverabilityTitle: NSLocalizedString("creation.file", comment: "A file"), attributes: [], state: .off, handler: { [weak self] _ in
                            self?.addToFavorites(folder: false)
                        }),
                        
                        UIAction(title: NSLocalizedString("creation.folder", comment: "A folder"), image: UIImage(systemName: "folder"), identifier: nil, discoverabilityTitle: NSLocalizedString("creation.folder", comment: "A folder"), attributes: [], state: .off, handler: { [weak self] _ in
                            self?.addToFavorites(folder: true)
                        }),
                    ])
                    button.showsMenuAsPrimaryAction = true
                    cell.contentView.addSubview(button)
                } else { // Open
                    cell.accessories = [.delete(actionHandler: { [weak self] in
                        if self?.favorites.indices.contains(indexPath.row-1) == true {
                            self?.favorites.remove(at: indexPath.row-1)
                            Self.favorites = self!.favorites
                            self?.loadFavorites()
                        }
                    }), .reorder()]
                    
                    for view in cell.contentView.subviews {
                        if view is UIButton {
                            view.removeFromSuperview()
                            break
                        }
                    }
                }
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
            
            if item.section != .favorites {
                for view in cell.contentView.subviews {
                    if view.tag == 5434 {
                        view.removeFromSuperview()
                        break
                    }
                }
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
        dataSource = UICollectionViewDiffableDataSource<Section, Item>(collectionView: collectionView) { [weak self] (collectionView: UICollectionView, indexPath: IndexPath, item: Item) -> UICollectionViewCell? in
            
            if self?.compact == true && indexPath.section == 1 {
                return collectionView.dequeueConfiguredReusableCell(using: cellRegistration, for: indexPath, item: item)
            } else if indexPath.item == 0 && indexPath.section != 0 {
                return collectionView.dequeueConfiguredReusableCell(using: headerRegistration, for: indexPath, item: item)
            } else {
                return collectionView.dequeueConfiguredReusableCell(using: cellRegistration, for: indexPath, item: item)
            }
        }
        
        dataSource.supplementaryViewProvider = { [weak self] (collectionView, elementKind, indexPath) -> UICollectionReusableView? in
            
            if indexPath.section == (self?.compact == true ? 5 : 4) && elementKind == UICollectionView.elementKindSectionFooter {
                return collectionView.dequeueConfiguredReusableSupplementary(
                    using: footerRegistration, for: indexPath)
            } else {
                return nil
            }
        }
        
        // Creating and applying snapshots
        let sections: [Section] = [.tabs]+(compact ? [.workingDirectory] : [])+[.recents, .favorites, .python, .resources]
        var snapshot = NSDiffableDataSourceSnapshot<Section, Item>()
        snapshot.appendSections(sections)

        for section in sections {
            switch section {
            case .tabs:
                var sectionSnapshot = NSDiffableDataSourceSectionSnapshot<Item>()
                sectionSnapshot.append(tabsItems)
                dataSource.apply(sectionSnapshot, to: section)
            case .workingDirectory:
                loadWorkingDirectory()
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
        (editor?.vc as? EditorSplitViewController)?.editor?.setBarItems()
    }
        
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        navigationController?.navigationBar.prefersLargeTitles = true
        loadRecents()
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        
        (editor?.vc as? EditorSplitViewController)?.editor?.setBarItems()
    }
    
    func show(vc: NavigationController) {
        
        if vc.viewControllers.first == nil {
            vc.viewControllers = [vc.vc!]
        }
        
        if splitViewController?.isCollapsed == true {
            navigationController?.pushViewController(vc.vc!, animated: true)
        } else if vc.vc?.navigationController != nil && vc.vc?.navigationController != vc {
            vc.vc?.removeFromParent()
            vc.vc?.view.removeFromSuperview()
            splitViewController?.setViewController(NavigationController(rootViewController: vc.vc!), for: .secondary)
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
        
        let tintColor = ConsoleViewController.choosenTheme.tintColor ?? UIColor(named: "TintColor") ?? .systemGreen
        
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
        
        /*let navVC = EditorSplitViewController.NavigationController(rootViewController: splitVC)
        navVC.modalPresentationStyle = .fullScreen
        navVC.navigationBar.isTranslucent = true*/
                
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
    
    func showFilebrowserSidebar() {
        
        guard let sidebar = splitViewController as? SidebarSplitViewController else {
            return
        }
        
        let fileBrowserNavVC = sidebar.fileBrowserNavVC ?? SidebarViewController.NavigationController(rootViewController: sidebar.fileBrowser)
        fileBrowserNavVC.navigationBar.prefersLargeTitles = true
        fileBrowserNavVC.view.backgroundColor = .systemBackground
        
        sidebar.fileBrowserNavVC = fileBrowserNavVC
        splitViewController?.setViewController(fileBrowserNavVC, for: .supplementary)
    }
    
    func showDocumentationSidebar() {
        makeDocumentationViewControllerIfNeeded()
        let docs = documentation?.viewControllers.first as? DocumentationViewController
        splitViewController?.setViewController(DocumentationViewController.SidebarViewController(documentationViewController: docs), for: .supplementary)
    }
    
    var previewingFile: URL?
    
    func open(url: URL, reloadRecents: Bool = false, run: Bool = false, completion: ((EditorViewController) -> Void)? = nil) {
        
        guard url.pathExtension.lowercased() == "py" || url.pathExtension.lowercased() == "pytoui" || url.pathExtension.lowercased() == "html" || (try? url.resourceValues(forKeys: [.contentTypeKey]))?.contentType?.conforms(to: .text) == true || (try? String(contentsOf: url)) != nil else { // Quick look
            
            let vc = QLPreviewController()
            previewingFile = url
            vc.delegate = self
            vc.dataSource = self
            present(vc, animated: true, completion: nil)
            
            return
        }
        
        if self.editor == nil && url.pathExtension.lowercased() != "pytoui" {
            if let editor = openDocument(url, run: false, folder: nil) {
                let navVC = NavigationController(rootViewController: editor)
                navVC.navigationBar.prefersLargeTitles = false
                editor.navigationItem.largeTitleDisplayMode = .never
                self.editor = navVC
            } else {
                return
            }
        }
        
        showFilebrowserSidebar()
        
        if url.pathExtension.lowercased() != "pytoui", let editor = (self.editor?.vc as? EditorSplitViewController)?.editor {
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
                        editor.setBarItems()
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
        
        if url.pathExtension.lowercased() == "pytoui" {
            guard #available(iOS 16.0, *) else {
                return
            }
            
            let doc = InterfaceDocument(fileURL: url)
            doc.open { _ in
                DispatchQueue.main.async {
                    let ib = InterfaceBuilderViewController(document: doc)
                    let navVC = NavigationController(rootViewController: ib)
                    self.show(vc: navVC)
                }
            }
        } else if let editor = editor {
            
            if editor.vc?.view.window == nil {
                show(vc: editor)
            }
            
            if run {
                (editor.vc as? EditorSplitViewController)?.editor?.run()
            }
        }
    }
    
    func openScript() {
        let docPicker = UIDocumentPickerViewController(forOpeningContentTypes: [.pythonScript, .init(filenameExtension: "html")!, .cSource, .cPlusPlusSource, .cHeader, .cPlusPlusHeader, .objectiveCSource, .objectiveCPlusPlusSource, .plainText, .sourceCode])
        docPicker.delegate = self
        present(docPicker, animated: true, completion: nil)
    }
    
    func reloadFavorites() {
        var snapshot = dataSource.snapshot()
        snapshot.reloadSections([.favorites])
        dataSource.apply(snapshot)
    }
    
    override func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        
        guard let item = dataSource.itemIdentifier(for: indexPath) else {
            return
        }
        
        switch item.section {
        case .tabs:
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
        case .workingDirectory:
            // Working directory
            if let dir = (splitViewController as? SidebarSplitViewController)?.compactFileBrowser.directory {
                let picker = UIDocumentPickerViewController(forOpeningContentTypes: [.folder])
                documentPicker(picker, didPickDocumentsAt: [dir])
            }
            return
        case .recents:
            // Recent
            var isDir: ObjCBool = false
            if FileManager.default.fileExists(atPath: recent[indexPath.row-1].path, isDirectory: &isDir) && isDir.boolValue {
                (splitViewController as! SidebarSplitViewController).compactFileBrowser.directory = recent[indexPath.row-1]
                (splitViewController as! SidebarSplitViewController).fileBrowser.directory = recent[indexPath.row-1]
                show(vc: (splitViewController as! SidebarSplitViewController).compactFileBrowserNavVC)
            } else {
                open(url: recent[indexPath.row-1])
            }
        case .favorites:
            // Favorites
            
            guard favorites.indices.contains(indexPath.row-1) else {
                return
            }
            
            var isDir: ObjCBool = false
            if FileManager.default.fileExists(atPath: favorites[indexPath.row-1].path, isDirectory: &isDir) && isDir.boolValue {
                (splitViewController as! SidebarSplitViewController).compactFileBrowser.directory = favorites[indexPath.row-1]
                (splitViewController as! SidebarSplitViewController).fileBrowser.directory = favorites[indexPath.row-1]
                
                let picker = UIDocumentPickerViewController(forOpeningContentTypes: [.folder])
                (repl?.vc as? REPLViewController)?.documentPicker(picker, didPickDocumentsAt: [favorites[indexPath.row-1]])
                (moduleRunner?.vc as? RunModuleViewController)?.documentPicker(picker, didPickDocumentsAt: [favorites[indexPath.row-1]])
                
                if splitViewController?.isCollapsed == true {
                    show(vc: (splitViewController as! SidebarSplitViewController).compactFileBrowserNavVC)
                } else {
                    showFilebrowserSidebar()
                }
            } else {
                open(url: favorites[indexPath.row-1])
            }
        case .python:
            // Python
            switch indexPath.row-1 {
            case 0:
                // Run module
                showFilebrowserSidebar()
                showModuleRunner()
            case 1:
                // PyPI
                showFilebrowserSidebar()
                showPyPI()
            case 2:
                // Home
                
                showFilebrowserSidebar()
                
                let browser = FileBrowserViewController()
                browser.directory = FileBrowserViewController.localContainerURL
                
                if splitViewController?.isCollapsed == false {
                    (splitViewController as! SidebarSplitViewController).fileBrowserNavVC.pushViewController(browser, animated: true)
                } else {
                    show(vc: NavigationController(rootViewController: browser))
                }
            case 3:
                // Loaded modules
                showFilebrowserSidebar()
                showLoadedModules()
            default:
                break
            }
        case .resources:
            // Resources
            switch indexPath.row-1 {
            case 0:
                // Examples
                
                showFilebrowserSidebar()
                showExamples()
            case 1:
                // Documentation
                showDocumentationSidebar()
                showDocumentationOnSplitView()
            default:
                break
            }
        }
    }
    
    func documentPicker(_ controller: UIDocumentPickerViewController, didPickDocumentsAt urls: [URL]) {
        if controller == favoritesPicker { // Add to favorites
            
            favoritesPicker = nil
            favorites.append(urls[0])
            Self.favorites = favorites
            loadFavorites()
            
        } else { // Open
            _ = urls.first?.startAccessingSecurityScopedResource()
            
            var isDir: ObjCBool = false
            if FileManager.default.fileExists(atPath: urls.first!.path, isDirectory:  &isDir) && isDir.boolValue {
                
                (splitViewController as? SidebarSplitViewController)?.compactFileBrowser.directory = urls.first!
                (splitViewController as? SidebarSplitViewController)?.fileBrowser.directory = urls.first!
                
                loadWorkingDirectory()
                
                if (splitViewController?.isCollapsed == true), let browser = (splitViewController as? SidebarSplitViewController)?.compactFileBrowserNavVC {
                    show(vc: browser)
                }
                
                (repl?.vc as? REPLViewController)?.documentPicker(controller, didPickDocumentsAt: urls)
                (moduleRunner?.vc as? RunModuleViewController)?.documentPicker(controller, didPickDocumentsAt: urls)
            } else {
                open(url: urls.first!, reloadRecents: true)
            }
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
    
    func numberOfPreviewItems(in controller: QLPreviewController) -> Int {
        previewingFile != nil ? 1 : 0
    }
    
    func previewController(_ controller: QLPreviewController, previewItemAt index: Int) -> QLPreviewItem {
        previewingFile! as QLPreviewItem
    }
    
    func previewControllerDidDismiss(_ controller: QLPreviewController) {
        previewingFile = nil
    }
}
