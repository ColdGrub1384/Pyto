//
//  PipInstallerViewController.swift
//  Pyto
//
//  Created by Emma Labbé on 5/5/19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit

fileprivate extension UIBarButtonItem {
    convenience init(image :UIImage, title :String, target: Any?, action: Selector?) {
        
        let button: UIButton
        if #available(iOS 15.0, *) {
            button = UIButton(configuration: .bordered())
        } else {
            button = UIButton(type: .custom)
        }
        button.setImage(image, for: .normal)
        button.setTitle(title, for: .normal)
        button.frame = CGRect(x: 0, y: 0, width: image.size.width, height: image.size.height)
        
        if let target = target, let action = action {
            button.addTarget(target, action: action, for: .touchUpInside)
        }
        
        self.init(customView: button)
    }
}

/// A View controller for running `python -m` commands.
@objc class RunModuleViewController: EditorSplitViewController, UIDocumentPickerDelegate {
    
    private class TabsManager {
        
        var tabs = [RunModuleViewController]() {
            didSet {
                for tab in tabs {
                    guard tab.console != nil else {
                        return
                    }
                    
                    if !ConsoleViewController.visibles.contains(tab.console!) {
                        ConsoleViewController.visibles.append(tab.console!)
                    }
                }
            }
        }
    }
    
    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
    }
    
    /// Arguments sent to the script containing script to run name.
    var argv: [String]? {
        didSet {
            loadViewIfNeeded()
            editor?.args = argv?.joined(separator: " ") ?? ""
        }
    }
    
    @objc private func goToFileBrowser() {
        dismiss(animated: true, completion: nil)
    }
        
    private var viewAppeared = false
    
    @objc private func setCurrentDirectory() {
        console?.movableTextField?.textField.resignFirstResponder()
        let picker = UIDocumentPickerViewController(forOpeningContentTypes: [.folder])
        picker.delegate = self
        picker.allowsMultipleSelection = true
        present(picker, animated: true, completion: nil)
    }
        
    var previousTitle = ""
    
    func setTitle(_ title: String) {
        let size = console?.terminalSize
        self.title = "\(ShortenFilePaths(in: title)) — \(size?.columns ?? 0)x\(size?.rows ?? 0)"
        if tabsManager.tabs.count > 1 {
            self.title = "[ \((tabsManager.tabs.firstIndex(of: self) ?? 0)+1) ] — " + self.title!
        }
    }
    
    private var chdir = false
        
    private var tabsManager = TabsManager()
    
    var moveBack: UIBarButtonItem!
    
    var moveForward: UIBarButtonItem!
    
    var findItem: UIBarButtonItem!
    
    var closeItem: UIBarButtonItem!
    
    var newTabItem: UIBarButtonItem!
    
    func makeTabIfNecessary() {
        if !tabsManager.tabs.contains(self) {
            tabsManager.tabs.append(self)
        }
    }
    
    @objc func back() {
        if let i = tabsManager.tabs.firstIndex(of: self), tabsManager.tabs.indices.contains(i-1) {
            
            let terminal = tabsManager.tabs[i-1]
            let navVC = navigationController
            (navVC as? SidebarViewController.NavigationController)?.vc = terminal
            var vcs = navVC?.viewControllers ?? []
            vcs.removeLast()
            vcs.append(terminal)
            navVC?.viewControllers = vcs
        }
    }
    
    @objc func forward() {
        if let i = tabsManager.tabs.firstIndex(of: self), tabsManager.tabs.indices.contains(i+1) {
            
            let terminal = tabsManager.tabs[i+1]
            let navVC = navigationController
            (navVC as? SidebarViewController.NavigationController)?.vc = terminal
            var vcs = navVC?.viewControllers ?? []
            vcs.removeLast()
            vcs.append(terminal)
            navVC?.viewControllers = vcs
        }
    }
    
    @objc func createTab() {
        
        makeTabIfNecessary()
        
        guard let i = tabsManager.tabs.firstIndex(of: self) else {
            return
        }
        
        let terminal = UIStoryboard(name: "Main", bundle: .main).instantiateViewController(withIdentifier: "runModule") as! RunModuleViewController
        terminal.tabsManager = tabsManager
        tabsManager.tabs.insert(terminal, at: i+1)
        
        let navVC = navigationController
        (splitViewController as? SidebarSplitViewController)?.sidebar?.moduleRunner?.vc = terminal
        
        var vcs = navVC?.viewControllers ?? []
        vcs.removeLast()
        vcs.append(terminal)
        navVC?.viewControllers = vcs
    }
    
    @objc func closeTab() {
        tabsManager.tabs.removeAll(where: { $0 == self })
        
        let terminal: RunModuleViewController
        if let i = tabsManager.tabs.firstIndex(of: self), tabsManager.tabs.indices.contains(i+1) {
            terminal = tabsManager.tabs[i+1]
        } else if let i = tabsManager.tabs.firstIndex(of: self), tabsManager.tabs.indices.contains(i-1) {
            terminal = tabsManager.tabs[i-1]
        } else if let last = tabsManager.tabs.last {
            terminal = last
        } else {
            terminal = UIStoryboard(name: "Main", bundle: .main).instantiateViewController(withIdentifier: "runModule") as! RunModuleViewController
        }
        
        let navVC = self.navigationController
        (splitViewController as? SidebarSplitViewController)?.sidebar?.moduleRunner?.vc = terminal
        
        var vcs = navVC?.viewControllers ?? []
        vcs.removeLast()
        vcs.append(terminal)
        navVC?.viewControllers = vcs
    }
    
    let indexItem = UIBarButtonItem(title: "[ 0 ]", style: .plain, target: nil, action: nil)
    
    @available(iOS 16.0, *)
    @objc func findOnWebView() {
        console?.webView.findInteraction?.presentFindNavigator(showingReplace: false)
    }
    
    @available(iOS 16.0, *)
    func configureTrailingGroups(traitCollection: UITraitCollection? = nil) {
        let collection = traitCollection ?? self.traitCollection
        if collection.horizontalSizeClass == .compact {
            navigationItem.trailingItemGroups = [
                .fixedGroup(items: [UIBarButtonItem(image: UIImage(systemName: "ellipsis.circle"), menu: UIMenu(title: "", options: .displayInline, children: [
                    
                    UIAction(title: findItem.title ?? "", image: findItem.image, handler: { [weak self] _ in
                        self?.search()
                    }),
                    
                    UIAction(title: newTabItem.title ?? "", image: newTabItem.image, handler: { [weak self] _ in
                        self?.createTab()
                    }),
                    
                    UIAction(title: closeItem.title ?? "", image: closeItem.image, attributes: .destructive, handler: { [weak self] _ in
                        self?.closeTab()
                    }),
                ]))]),
            ]
        } else {
            navigationItem.trailingItemGroups = [
                .fixedGroup(items: [findItem, newTabItem, closeItem]),
            ]
        }
    }
    
    // MARK: - Editor split view controller
    
    override var title: String? {
        didSet {
            if view.window != nil {
                view.window?.windowScene?.title = title
            }
        }
    }
    
    override var keyCommands: [UIKeyCommand]? {
        return [UIKeyCommand.command(input: "C", modifierFlags: .control, action: #selector(interrupt), discoverabilityTitle: NSLocalizedString("interrupt", comment: "Description for CTRL+C key command."))]
    }
    
    override func loadView() {
        super.loadView()
        
        ratio = 0
        
        if let repl = Bundle.main.url(forResource: "command_runner", withExtension: "py") {
            
            /// Taken from https://stackoverflow.com/a/26845710/7515957
            func randomString(length: Int) -> String {
                let letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
                return String((0..<length).map{ _ in letters.randomElement()! })
            }
            
            let newURL = URL(fileURLWithPath: NSTemporaryDirectory()).appendingPathComponent(randomString(length: 5)).appendingPathExtension("repl.py")
            try? FileManager.default.copyItem(at: repl, to: newURL)
            
            let editor = EditorViewController(document: PyDocument(fileURL: newURL))
            self.editor = editor
        }
        
        console = ConsoleViewController()
    }
    
    override func viewDidLoad() {
                
        let titleLabel = UILabel()
        titleLabel.font = UIFont.boldSystemFont(ofSize: UIFont.systemFontSize)
        
        super.viewDidLoad()
        
        title = ""
        
        firstChild = editor
        secondChild = console
        
        arrangement = .horizontal
        
        navigationItem.largeTitleDisplayMode = .never
        
        moveBack = UIBarButtonItem(image: UIImage(systemName: "chevron.backward"), style: .plain, target: self, action: #selector(back))
        moveBack.title = NSLocalizedString("goBack", comment: "Go Back")
        moveForward = UIBarButtonItem(image: UIImage(systemName: "chevron.forward"), style: .plain, target: self, action: #selector(forward))
        moveForward.title = NSLocalizedString("goForward", comment: "Go Forward")
        closeItem = UIBarButtonItem(image: UIImage(systemName: "xmark"), style: .plain, target: self, action: #selector(closeTab))
        closeItem.tintColor = .systemRed
        closeItem.title = NSLocalizedString("menuItems.closeTab", comment: "Close terminal tab")
        newTabItem = UIBarButtonItem(image: UIImage(systemName: "plus.square.on.square"), style: .plain, target: self, action: #selector(createTab))
        newTabItem.title = NSLocalizedString("menuItems.newTab", comment: "New terminal tab")
        
        if #available(iOS 16.0, *) {
            findItem = UIBarButtonItem(image: UIImage(systemName: "magnifyingglass"), style: .plain, target: self, action: #selector(findOnWebView))
            findItem.title = NSLocalizedString("find", comment: "'Find'")
            
            navigationItem.style = .browser
            navigationItem.customizationIdentifier = "terminal"
            navigationItem.leadingItemGroups = [
                .fixedGroup(items: [moveBack, moveForward]),
                .fixedGroup(items: [UIBarButtonItem(title: NSLocalizedString("sidebar.cwd", comment: "The working directory on compact view"), image: UIImage(systemName: "folder.badge.gearshape"), target: self, action: #selector(setCurrentDirectory))])
            ]
            configureTrailingGroups()
        }
    }
        
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        setTitle(console?.terminalTitle ?? "")
        
        if #available(iOS 16.0, *) {
            console?.webView.isFindInteractionEnabled = true
        }
        
        if let i = tabsManager.tabs.firstIndex(of: self) {
            moveBack.isEnabled = tabsManager.tabs.indices.contains(i-1)
            moveForward.isEnabled = tabsManager.tabs.indices.contains(i+1)
        } else {
            moveBack.isEnabled = false
            moveForward.isEnabled = false
        }
        
        if !isiOSAppOnMac && splitViewController == nil {
            navigationItem.leftBarButtonItem = UIBarButtonItem(barButtonSystemItem: .done, target: self, action: #selector(goToFileBrowser))
        }
        navigationController?.isToolbarHidden = true
        parent?.title = title
        parent?.navigationItem.title = title
        
        if #available(iOS 13.0, *) {
            view.window?.windowScene?.title = title
        }
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        
        view.window?.windowScene?.title = nil
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
                
        if chdir {
            console?.input = ""
            console?.webView.enter()
            chdir = false
        }
        
        guard !viewAppeared else {
            return
        }
        
        viewAppeared = true
        
        #if !SCREENSHOTS
        _ = Timer.scheduledTimer(withTimeInterval: 0.3, repeats: true, block: { [weak self] (timer) in
            if Python.shared.isSetup && isUnlocked {
                if let dir = (self?.view.window?.windowScene?.delegate as? SceneDelegate)?.sidebarSplitViewController?.fileBrowser.directory {
                    self?.editor?.currentDirectory = dir
                }
                self?.editor?.run()
                timer.invalidate()
            }
        })
        #endif
        
        view.window?.windowScene?.title = title
    }
    
    override func willTransition(to newCollection: UITraitCollection, with coordinator: UIViewControllerTransitionCoordinator) {
        super.willTransition(to: newCollection, with: coordinator)
        
        if #available(iOS 16.0, *) {
            configureTrailingGroups(traitCollection: newCollection)
        }
        
    }
    
    // MARK: Document picker view controller
    
    func documentPicker(_ controller: UIDocumentPickerViewController, didPickDocumentsAt urls: [URL]) {
        _ = urls[0].startAccessingSecurityScopedResource()
        REPLViewController.pickedDirectory[editor!.document!.fileURL.path] = urls[0].path
        if view.window == nil {
            chdir = true // chdir on viewDidAppear
        } else {
            console?.input = ""
            console?.webView.enter()
        }
    }
}

