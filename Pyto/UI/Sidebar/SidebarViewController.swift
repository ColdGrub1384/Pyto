//
//  SidebarViewController.swift
//  Pyto
//
//  Created by Emma on 10-11-21.
//  Copyright © 2021 Emma Labbé. All rights reserved.
//

import UIKit
import SwiftUI

fileprivate struct Item: Hashable {
    let title: String?
    let image: UIImage?
    private let identifier = UUID()
}

fileprivate let tabsItems = [
    Item(title: NSLocalizedString("Create", comment: ""), image: UIImage(systemName: "plus.square.fill")),
    Item(title: NSLocalizedString("Open script", comment: ""), image: UIImage(systemName: "square.and.arrow.down")),
    Item(title: NSLocalizedString("Open directory", comment: ""), image: UIImage(systemName: "folder"))]

fileprivate let pythonItems = [Item(title: NSLocalizedString("repl", comment: ""), image: UIImage(systemName: "play")),
                     Item(title: NSLocalizedString("sidebar.runModule", comment: ""), image: UIImage(systemName: "chevron.left.forwardslash.chevron.right")),
                     Item(title: NSLocalizedString("sidebar.pypi", comment: ""), image: UIImage(systemName: "cloud")),
                     Item(title: NSLocalizedString("sidebar.loadedModules", comment: ""), image: UIImage(systemName: "info.circle"))]
    
fileprivate let resourcesItems = [
    Item(title: NSLocalizedString("sidebar.examples", comment: ""), image: UIImage(systemName: "bookmark")),
    Item(title: NSLocalizedString("help.documentation", comment: ""), image: UIImage(systemName: "book")),
]
    
fileprivate enum Section: String {
    case tabs
    case recents = "sidebar.recent"
    case python = "sidebar.python"
    case resources = "sidebar.resources"
}

@objc class SidebarViewController: UICollectionViewController, UIDocumentPickerDelegate {
    
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
                    DispatchQueue.global().async {
                        let pyPackage = PyPackage(name: package)
                        
                        DispatchQueue.main.async {
                            
                            pypi.currentPackage = pyPackage
                            if let name = pyPackage?.name {
                                pypi.title = name
                            }
                            
                            vc.show(pypi, sender: nil)
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
            var config = UICollectionLayoutListConfiguration(appearance: (Self.splitViews.first(where: { $0.id == splitViewID }))?.traitCollection.horizontalSizeClass == .compact ? .sidebarPlain : .sidebar)
            config.headerMode = section == 0 ? .none : .firstItemInSection
            config.footerMode = section == 3 ? .supplementary : .none
            
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
            
            let image: String
            
            var isDir: ObjCBool = false
            if FileManager.default.fileExists(atPath: item.path, isDirectory: &isDir) && isDir.boolValue {
                image = "folder"
            } else {
                image = "doc"
            }
            
            let title: String
            if item == FileBrowserViewController.iCloudContainerURL {
                title = "iCloud Drive"
            } else {
                title = item.lastPathComponent
            }
            items.append(Item(title: title, image: UIImage(systemName: image)))
        }
        
        loadViewIfNeeded()
        
        let headerItem = Item(title: NSLocalizedString(section.rawValue, comment: ""), image: nil)
        var sectionSnapshot = NSDiffableDataSourceSectionSnapshot<Item>()
        sectionSnapshot.append([headerItem])
        sectionSnapshot.append(items, to: headerItem)
        sectionSnapshot.expand([headerItem])
        dataSource.apply(sectionSnapshot, to: section)
    }
    
    @objc func showSettings() {
        let vc = UIStoryboard(name: "Settings", bundle: .main).instantiateInitialViewController()
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
            documentation?.navigationBar.prefersLargeTitles = true
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
    
    func showModuleRunner() {
        if moduleRunner == nil {
            moduleRunner = NavigationController(rootViewController: UIStoryboard(name: "Main", bundle: .main).instantiateViewController(withIdentifier: "runModule"))
        }
        
        show(vc: moduleRunner!)
    }
    
    func showLoadedModules() {
        if loadedModules == nil {
            loadedModules = NavigationController(rootViewController: ModulesTableViewController(style: .grouped))
        }
        
        show(vc: loadedModules!)
    }
    
    @objc func newScript() {
        let navVC = UIStoryboard(name: "Template Chooser", bundle: nil).instantiateInitialViewController()!
        ((navVC as? UINavigationController)?.topViewController as? TemplateChooserTableViewController)?.chooseName = false
        ((navVC as? UINavigationController)?.topViewController as? TemplateChooserTableViewController)?.importHandler = { [weak self] url, _ in
            self?.dismiss(animated: true, completion: {
                if let url = url {
                    let docPicker = UIDocumentPickerViewController(forExporting: [url], asCopy: false)
                    docPicker.delegate = self
                    self?.present(docPicker, animated: true, completion: nil)
                }
            })
        }
        
        self.present(navVC, animated: true, completion: nil)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        title = "Pyto"
        navigationItem.largeTitleDisplayMode = .always
        
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
                cell.contentConfiguration = content
                cell.accessories = []
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
            
            if indexPath.section == 3 && elementKind == UICollectionView.elementKindSectionFooter {
                return collectionView.dequeueConfiguredReusableSupplementary(
                    using: footerRegistration, for: indexPath)
            } else {
                return nil
            }
        }

        // Creating and applying snapshots
        let sections: [Section] = [.tabs, .recents, .python, .resources]
        var snapshot = NSDiffableDataSourceSnapshot<Section, Item>()
        snapshot.appendSections(sections)
        dataSource.apply(snapshot, animatingDifferences: false)

        for section in sections {
            switch section {
            case .tabs:
                var sectionSnapshot = NSDiffableDataSourceSectionSnapshot<Item>()
                sectionSnapshot.append(tabsItems)
                dataSource.apply(sectionSnapshot, to: section)
            case .recents:
                loadRecents()
            case .python:
                let headerItem = Item(title: NSLocalizedString(section.rawValue, comment: ""), image: nil)
                var sectionSnapshot = NSDiffableDataSourceSectionSnapshot<Item>()
                sectionSnapshot.append([headerItem])
                sectionSnapshot.append(pythonItems, to: headerItem)
                sectionSnapshot.expand([headerItem])
                dataSource.apply(sectionSnapshot, to: section)
            case .resources:
                let headerItem = Item(title: NSLocalizedString(section.rawValue, comment: ""), image: nil)
                var sectionSnapshot = NSDiffableDataSourceSectionSnapshot<Item>()
                sectionSnapshot.append([headerItem])
                sectionSnapshot.append(resourcesItems, to: headerItem)
                sectionSnapshot.expand([headerItem])
                dataSource.apply(sectionSnapshot, to: section)
            }
        }
        
        navigationItem.rightBarButtonItem = UIBarButtonItem(image: UIImage(systemName: "gear"), style: .plain, target: self, action: #selector(showSettings))
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
        
        let tintColor = ConsoleViewController.choosenTheme.tintColor ?? UIColor(named: "TintColor") ?? .orange
        
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
        
        if EditorSplitViewController.shouldShowSeparator {
            splitVC.separatorColor = tintColor
        } else {
            splitVC.separatorColor = .clear
        }
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
    
    func open(url: URL, reloadRecents: Bool = false, run: Bool = false) {
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
        
        show(vc: editor!)
        
        if run {
            (editor?.vc as? EditorSplitViewController)?.editor?.run()
        }
    }
    
    func openScript() {
        let docPicker = UIDocumentPickerViewController(forOpeningContentTypes: [.pythonScript, .init(filenameExtension: "pyhtml")!])
        docPicker.delegate = self
        present(docPicker, animated: true, completion: nil)
    }
    
    override func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        
        switch indexPath.section {
        case 0:
            // Pyto
            switch indexPath.row {
            case 0:
                newScript()
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
                // Loaded modules
                showLoadedModules()
            default:
                break
            }
        case 3:
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
        } else {
            open(url: urls.first!, reloadRecents: true)
        }
    }
}
