import UIKit
import SwiftUI

/// The interface editor. Initialize it with ``InterfaceBuilderViewController.init(document:)``.
@available(iOS 16.0, *) public class InterfaceBuilderViewController: UIViewController, UIScrollViewDelegate, UINavigationItemRenameDelegate {
    
    /// The library.
    let libraryViewController = LibraryViewController()
    
    /// Inspects view.
    func inspect(view: UIView, isRoot: Bool = false) {
        
        let inspector = InspectorViewController(view: view, isRoot: isRoot)
        
        let controller = UINavigationController(rootViewController: inspector)
        controller.modalPresentationStyle = .popover
        controller.popoverPresentationController?.sourceRect = view.bounds
        controller.popoverPresentationController?.sourceView = view
        controller.popoverPresentationController?.delegate = inspector
        (presentedViewController ?? self).present(controller, animated: true, completion: nil)
    }
    
    /// Shows the library to add a view to the given stack view.
    func showLibrary(containerView: StackViewContainer) {
        libraryViewController.didSelect = { [unowned self] item in
            let manager = containerView.manager
            
            let view = item.makeView()
            view.interfaceBuilder = self
            view.model = self.model
            view.clipsToBounds = true
            
            var tag = Int.random(in: 1...9999)
            while self.view.viewWithTag(tag) != nil {
                tag = Int.random(in: 1...9999)
            }
            
            view.tag = tag
            
            view.isUserInteractionEnabled = true
            manager?.views.append(view)
            view.interfaceBuilder = self
            item.configure(view: view, model: &model)
            view.model = self.model
            
            self.libraryViewController.dismiss(animated: true)
            
            NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: self.containerView)
            
            self.autosave()
        }
        
        let libraryNavigationController = UINavigationController(rootViewController: libraryViewController)
        libraryNavigationController.view.backgroundColor = .systemBackground
        libraryNavigationController.modalPresentationStyle = .pageSheet
        libraryNavigationController.sheetPresentationController?.detents = [.medium(), .large()]
        libraryNavigationController.sheetPresentationController?.prefersGrabberVisible = true
        (presentedViewController ?? self).present(libraryNavigationController, animated: true)
    }
    
    /// Shows or hides the library.
    @objc func showLibrary(_ sender: Any) {
        if let stackView = containerView as? StackViewContainer {
            showLibrary(containerView: stackView)
        }
    }
    
    @objc func showInspector() {
        inspect(view: containerView, isRoot: true)
    }
    
    private var scrollView: UIScrollView!
    
    private var deviceLayoutView: UIView!
    
    private var containerViewController: UIViewController!
    
    var containerView: UIView!
    
    private var containerNavigationController: UINavigationController!
    
    private var scrollViewContainer: UIView!
    
    var deviceLayoutManager = DeviceContainerView.DeviceLayoutManager(deviceLayout: .iPhone13Pro, orientation: .portrait)
    
    var layoutButton: UIBarButtonItem!
    
    var orientationButton: UIBarButtonItem!
    
    var darkModeButton: UIBarButtonItem!
    
    func getOrientationButtonImage() -> UIImage? {
        UIImage(systemName: "rotate.\(deviceLayoutManager.orientation == .portrait ? "left" : "right")")
    }
    
    func getDarkModeButtonImage() -> UIImage? {
        UIImage(systemName: "moon.circle\(model.darkMode ? ".fill" : "")")
    }
    
    @objc func rotate() {
        scrollView.setZoomScale(1, animated: false)
        
        if deviceLayoutManager.orientation == .portrait {
            deviceLayoutManager.orientation = .landscape
            deviceLayoutView.frame.size = CGSize(width: model.selectedDevice.size.height, height: model.selectedDevice.size.width)
        } else {
            deviceLayoutManager.orientation = .portrait
            deviceLayoutView.frame.size = model.selectedDevice.size
        }
        
        model.orientation = deviceLayoutManager.orientation
                
        orientationButton.image = getOrientationButtonImage()
        
        zoom()
        
        autosave()
    }
    
    @objc func toggleDarkMode() {
        if model.darkMode {
            containerNavigationController?.overrideUserInterfaceStyle = .light
            deviceLayoutView?.overrideUserInterfaceStyle = .light
            view.overrideUserInterfaceStyle = .light
        } else {
            containerNavigationController?.overrideUserInterfaceStyle = .dark
            deviceLayoutView?.overrideUserInterfaceStyle = .dark
            view.overrideUserInterfaceStyle = .dark
        }
        
        model.darkMode = (containerNavigationController.traitCollection.userInterfaceStyle == .dark)
        
        darkModeButton.image = getDarkModeButtonImage()
        
        deviceLayoutView.setNeedsDisplay()
        
        autosave()
    }
    
    @objc func showHierarchy() {
        guard let stackView = containerView as? StackViewContainer else {
            return
        }
        let vc = UIHostingController(rootView: NavigationStack { [weak self] in
            HierarchyList(stackView: stackView)
                .navigationTitle(self?.containerNavigationController?.visibleViewController?.title ?? "")
                .toolbar {
                    ToolbarItemGroup(placement: .navigationBarTrailing) {
                        SwiftUI.Button {
                            self?.dismiss(animated: true)
                        } label: {
                            Text("Done").bold()
                        }
                    }
                }
        })
        present(vc, animated: true)
    }
        
    var model = InterfaceModel()
    
    func autosave() {
        document?.interfaceModel = model
        document?.save(to: document!.fileURL, for: .forOverwriting)
    }
    
    var layoutMenu: UIMenu {
        UIMenu(title: "Layout", image: nil, identifier: nil, options: [], children: DeviceLayout.allCases.map({ [weak self] device in
            
            UIAction(title: "\(device.name)", subtitle: "\(Int(device.size.width))x\(Int(device.size.height))", image: device.symbol, state: self?.model.selectedDevice == device ? .on : .off, handler: { _ in
                
                self?.scrollView.setZoomScale(1, animated: false)
                
                self?.model.selectedDevice = device
                self?.deviceLayoutManager.deviceLayout = device
               
                if self?.deviceLayoutManager.orientation == .portrait {
                    self?.deviceLayoutView.frame.size = device.size
                } else {
                    self?.deviceLayoutView.frame.size = CGSize(width: device.size.height, height: device.size.width)
                }
                
                self?.layoutButton.menu = self?.layoutMenu
                self?.layoutButton.image = device.symbol
                
                self?.deviceLayoutView.center = self?.scrollViewContainer.center ?? .zero
                
                self?.zoom()
                
                self?.autosave()
            })
        }))
    }
    
    func zoom() {
        var visibleRect = deviceLayoutView.frame

        let theScale = 1 / scrollView.zoomScale
        visibleRect.origin.x *= theScale
        visibleRect.origin.y *= theScale
        visibleRect.size.width *= theScale
        visibleRect.size.height *= theScale
        visibleRect.size.width += 50
        visibleRect.size.height += 50
        
        scrollView.zoom(to: visibleRect, animated: false)
    }
    
    struct Content: View {
        
        var scrollView: UIScrollView
        
        var stackView: StackViewContainer
        
        struct ScrollViewRepresentable: UIViewRepresentable {
            
            var scrollView: UIScrollView
            
            func makeUIView(context: Context) -> some UIView {
                scrollView
            }
            
            func updateUIView(_ uiView: UIViewType, context: Context) {
            }
        }
                
        @Environment(\.colorScheme) var colorScheme

        var body: some View {
            ScrollViewRepresentable(scrollView: scrollView)
        }
    }
    
    /// The document being edited.
    var document: InterfaceDocument? {
        didSet {
            if let url = document?.fileURL {
                navigationItem.documentProperties = UIDocumentProperties(url: url)
            } else {
                navigationItem.documentProperties = nil
            }
        }
    }
    
    private func setInterfaceBuilder(stackView: StackViewContainer) {
        for view in stackView.manager.views {
            if let stackView = view as? StackViewContainer {
                setInterfaceBuilder(stackView: stackView)
            }
            
            // Redundant I think, but I'm too lazy to think
            view.interfaceBuilder = self
            view.model = model
        }
        
        stackView.interfaceBuilder = self
        stackView.model = model
    }
    
    // MARK: - View controller
    
    /// Initializes the interface builder with the given document.
    ///
    /// - Parameters:
    ///     - document: The document to be edited.
    public init(document: InterfaceDocument) {
        super.init(nibName: nil, bundle: nil)
        
        self.document = document
        
        loadViewIfNeeded()
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    public override func viewDidLoad() {
        super.viewDidLoad()
        
        navigationItem.style = .editor
        
        view.tintAdjustmentMode = .normal
        
        edgesForExtendedLayout = []
        
        title = document?.fileURL.lastPathComponent
        
        if let savedModel = document?.interfaceModel, let navVC = savedModel.navigationController {
            model = savedModel
            
            if let stackView = navVC.viewControllers.last?.view as? StackViewContainer {
                setInterfaceBuilder(stackView: stackView)
            } else {
                navVC.viewControllers.last?.view.interfaceBuilder = self
                navVC.viewControllers.last?.view.model = model
            }
            
            for item in (navVC.viewControllers.last?.navigationItem.leftBarButtonItems ?? [])+(navVC.viewControllers.last?.navigationItem.rightBarButtonItems ?? []) {
                item.customView?.interfaceBuilder = self
                item.customView?.model = model
            }
            
            deviceLayoutManager.deviceLayout = model.selectedDevice
            deviceLayoutManager.orientation = model.orientation
            containerNavigationController = navVC
            containerViewController = navVC.viewControllers.first
            addChild(containerNavigationController)
        } else {
            containerViewController = UIViewController()
            containerViewController.view = StackViewContainer(axis: .vertical)
            containerViewController.view.tintColor = .systemBlue
            containerViewController.view.interfaceBuilder = self
            containerViewController.view.model = model
            containerViewController.view.backgroundColor = .systemBackground
            containerViewController.title = "My View"
            containerViewController.navigationItem.largeTitleDisplayMode = .always
            
            containerNavigationController = UINavigationController(rootViewController: containerViewController)
            containerNavigationController.navigationBar.prefersLargeTitles = true
            addChild(containerNavigationController)
        }
        
        containerView = containerViewController.view
        containerView.tintAdjustmentMode = .normal
        
        model.navigationController = containerNavigationController
        
        scrollView = UIScrollView(frame: view.frame)
        scrollView.isScrollEnabled = true
        scrollView.maximumZoomScale = 10
        scrollView.minimumZoomScale = 0.1
        scrollView.showsHorizontalScrollIndicator = true
        scrollView.showsVerticalScrollIndicator = true
        scrollView.contentSize = CGSize(width: 3000, height: 3000)
        scrollView.delegate = self
        scrollView.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        scrollView.tintAdjustmentMode = .normal
        
        let vc = UIHostingController(rootView: Content(scrollView: scrollView, stackView: (containerView as? StackViewContainer) ?? StackViewContainer(axis: .vertical)))
        vc.view.frame = view.frame
        vc.view.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        vc.view.backgroundColor = .clear
        addChild(vc)
        view.addSubview(vc.view)
        
        let deviceLayoutVC = UIHostingController(rootView: DeviceContainerView(containerNavigationController: .init(navigationController: containerNavigationController), deviceLayoutManager: deviceLayoutManager))
        deviceLayoutView = deviceLayoutVC.view
        deviceLayoutView.clipsToBounds = true
        
        if model.orientation == .portrait {
            deviceLayoutView.frame.size = model.selectedDevice.size
        } else {
            deviceLayoutView.frame.size = CGSize(width: model.selectedDevice.size.height, height: model.selectedDevice.size.width)
        }
        
        deviceLayoutView.backgroundColor = .clear
        deviceLayoutView.layer.borderColor = UIColor.gray.cgColor
        deviceLayoutView.layer.borderWidth = 0.7
        deviceLayoutView.layer.cornerRadius = 12
        deviceLayoutView.tintAdjustmentMode = .normal
        
        if model.darkMode {
            view.overrideUserInterfaceStyle = .dark
        } else {
            view.overrideUserInterfaceStyle = .light
        }
        
        scrollViewContainer = UIView(frame: CGRect(origin: .zero, size: CGSize(width: 3000, height: 3000)))
        
        scrollViewContainer.addSubview(deviceLayoutView)
        deviceLayoutView.center = scrollViewContainer.center
        scrollView.addSubview(scrollViewContainer)
        
        let libraryButton = UIBarButtonItem(image: UIImage(systemName: "plus.app"), style: .plain, target: self, action: #selector(showLibrary(_:)))
        layoutButton = UIBarButtonItem(image: model.selectedDevice.symbol, style: .plain, target: nil, action: nil)
        orientationButton = UIBarButtonItem(image: getOrientationButtonImage(), style: .plain, target: self, action: #selector(rotate))
        darkModeButton = UIBarButtonItem(image: getDarkModeButtonImage(), style: .plain, target: self, action: #selector(toggleDarkMode))
        let editButton = UIBarButtonItem(image: UIImage(systemName: "pencil"), style: .plain, target: self, action: #selector(showInspector))
        let hierarchyButton = UIBarButtonItem(image: UIImage(systemName: "square.stack"), style: .plain, target: self, action: #selector(showHierarchy))
        
        layoutButton.menu = layoutMenu
        
        libraryButton.title = "Add"
        layoutButton.title = "Layout"
        orientationButton.title = "Orientation"
        darkModeButton.title = "Toggle Dark Mode"
        editButton.title = "Edit"
        hierarchyButton.title = "Hierarchy"
        
        navigationItem.customizationIdentifier = "interfaceBuilderToolbar"
        
        navigationItem.centerItemGroups = [
            editButton.creatingMovableGroup(customizationIdentifier: "edit"),
            layoutButton.creatingOptionalGroup(customizationIdentifier: "layout"),
            orientationButton.creatingOptionalGroup(customizationIdentifier: "orientation"),
            darkModeButton.creatingOptionalGroup(customizationIdentifier: "Toggle Dark Mode"),
            hierarchyButton.creatingOptionalGroup(customizationIdentifier: "hierarchy"),
            libraryButton.creatingMovableGroup(customizationIdentifier: "library")
        ]
        
        if let url = document?.fileURL {
            let props = UIDocumentProperties(url: url)
            props.activityViewControllerProvider = {
                UIActivityViewController(activityItems: [url], applicationActivities: nil)
            }
            props.dragItemsProvider = { session in
                if let provider = NSItemProvider(contentsOf: url) {
                    return [UIDragItem(itemProvider: provider)]
                } else {
                    return []
                }
            }
            navigationItem.renameDelegate = self
            navigationItem.documentProperties = props
            navigationItem.style = .editor
        }
        
        view.backgroundColor = .secondarySystemBackground
    }
    
    public override func viewWillTransition(to size: CGSize, with coordinator: UIViewControllerTransitionCoordinator) {
        super.viewWillTransition(to: size, with: coordinator)
                
        coordinator.animate(alongsideTransition: nil) { _ in
            if self.deviceLayoutManager.orientation == .portrait {
                self.deviceLayoutView.frame.size = self.model.selectedDevice.size
            } else {
                self.deviceLayoutView.frame.size = CGSize(width: self.model.selectedDevice.size.height, height: self.model.selectedDevice.size.width)
            }
        }
    }
    
    public override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        containerNavigationController?.overrideUserInterfaceStyle = model.darkMode ? .dark : .light
        deviceLayoutView.overrideUserInterfaceStyle = model.darkMode ? .dark : .light
        navigationController?.view.backgroundColor = .systemBackground
    }
    
    public override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        zoom()
        NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: containerView)
        
        becomeFirstResponder()
    }
    
    public override var canBecomeFirstResponder: Bool {
        true
    }
    
    public override func traitCollectionDidChange(_ previousTraitCollection: UITraitCollection?) {
        super.traitCollectionDidChange(previousTraitCollection)
        
        if presentedViewController == nil {
            becomeFirstResponder()
        }
    }
    
    // MARK: - Scroll view delegate
    
    public func viewForZooming(in scrollView: UIScrollView) -> UIView? {
        return scrollViewContainer
    }
    
    // MARK: - Navigation item rename delegate
    
    public func navigationItem(_: UINavigationItem, didEndRenamingWith title: String) {
        
        guard let url = document?.fileURL else {
            return
        }
        
        var newURL = url.deletingLastPathComponent().appendingPathComponent(title)
        if !title.lowercased().hasSuffix(url.pathExtension.lowercased()) {
            newURL.appendPathExtension(url.pathExtension)
        }
        
        guard newURL != url else {
            return
        }
        
        autosave()
        document?.close(completionHandler: { _ in
            do {
                try FileManager.default.moveItem(at: url, to: newURL)
                let document = InterfaceDocument(fileURL: newURL)
                document.open { _ in
                    self.title = document.fileURL.lastPathComponent
                    self.document = document
                }
            } catch {
                DispatchQueue.main.async {
                    let alert = UIAlertController(title: NSLocalizedString("error", bundle: .main, comment: "Error"), message: error.localizedDescription, preferredStyle: .alert)
                    alert.addAction(UIAlertAction(title: NSLocalizedString("cancel", bundle: .main, comment: "Cancel"), style: .cancel))
                    self.present(alert, animated: true)
                }
            }
        })
        
    }
    
    public func navigationItemShouldBeginRenaming(_: UINavigationItem) -> Bool {
        document != nil && FileManager.default.isWritableFile(atPath: document!.fileURL.deletingLastPathComponent().path)
    }
}
