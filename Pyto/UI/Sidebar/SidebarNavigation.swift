//
//  SidebarNavigation.swift
//  SwiftUI Views
//
//  Created by Adrian Labbé on 23-06-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import SwiftUI

@available(iOS 14.0, *)
fileprivate func SidebarLabel(_ text: String, systemImage: String, selection: SelectedSection?, selected: SelectedSection?) -> Label<Text, AnyView> {
    
    if isiOSAppOnMac {
        return Label(
            title: { Text(NSLocalizedString(text, comment: "")).foregroundColor(.primary) },
            icon: { AnyView(Image(systemName: systemImage).foregroundColor(.accentColor)) }
        )
    } else {
        return Label(
            title: { Text(NSLocalizedString(text, comment: "")) },
            icon: { AnyView(Image(systemName: systemImage)) }
        )
    }
}

@available(iOS 14.0, *)
fileprivate func adjustBackground(_ colorScheme: ColorScheme) {
    if ProcessInfo.processInfo.isiOSAppOnMac && colorScheme != .dark {
        UITableView.appearance().backgroundColor = .systemBackground
    } else {
        UITableView.appearance().backgroundColor = .secondarySystemBackground
    }
}

/// A code editor view.
///
/// Use it as a `NavigationLink` for opening a code editor. The code editor is only created when this view appears so it works a lot faster and uses less memory than directly linking a `ViewController`.
@available(iOS 14.0, *)
public struct EditorView: View {
    
    /// A store containing the view controller.
    public class EditorStore {
        public static var perScene = [UIWindowScene:EditorStore]()
        
        public var editor: ViewController?
        
        var sizeClass: (UIUserInterfaceSizeClass, UIUserInterfaceSizeClass)?
        
        static var checkedForConflicts: URL?
    }
    
    private class IsOpeningStore {
        
        var isOpening = false
    }
    
    /// The code returning a view controller.
    let makeEditor: ((ViewControllerStore?) -> ViewController)
    
    /// The store containing the editor.
    let editorStore: EditorStore
    
    /// An object storing the code editor.
    let currentViewStore: CurrentViewStore
    
    /// The `ViewControllerStore` object associated with the sidebar navigation.
    let viewControllerStore: ViewControllerStore?
    
    /// A boolean that will be set to `false` on appear to enable the split view on the menu.
    let isStack: Binding<Bool>
    
    /// The selection.
    let selection: SelectedSection
    
    /// The binding where the selection will be written.
    let selected: Binding<SelectedSection?>
    
    /// The selection restored from state restoration.
    let restoredSelection: Binding<SelectedSection?>
    
    /// The URL of the document to edit.
    let url: URL
    
    private let scene: UIWindowScene?
    
    /// Initializes an editor.
    ///
    /// - Parameters:
    ///     - makeEditor: A block returning a view controller.
    ///     - url: The URL of the document to edit.
    ///     - currentViewStore: The object storing the current selection of the sidebar.
    ///     - viewControllerStore: The `ViewControllerStore` object associated with the sidebar navigation.
    ///     - isStack: A boolean that will be set to `false` on appear to enable the split view on the menu.
    ///     - selection: The selection.
    ///     - selected: The binding where the selection will be written.
    ///     - restoredSelection: The selection restored from state restoration.
    init(makeEditor: @escaping ((ViewControllerStore?) -> ViewController), url: URL, scene: UIWindowScene?, currentViewStore: CurrentViewStore, viewControllerStore: ViewControllerStore?, isStack: Binding<Bool>, selection: SelectedSection, selected: Binding<SelectedSection?>, restoredSelection: Binding<SelectedSection?>) {
        self.makeEditor = makeEditor
        self.url = url
        self.currentViewStore = currentViewStore
        self.viewControllerStore = viewControllerStore
        self.isStack = isStack
        self.selection = selection
        self.restoredSelection = restoredSelection
        self.selected = selected
        self.scene = scene
        
        if let scene = scene {
            self.editorStore = EditorStore.perScene[scene] ?? EditorStore()
            EditorStore.perScene[scene] = self.editorStore
        } else {
            self.editorStore = EditorStore()
        }
    }
    
    private let isOpeningStore = IsOpeningStore()
        
    public var body: some View {
        
        var view: AnyView!
        
        let editorVC = (editorStore.editor?.viewController as? EditorSplitViewController)?.editor
        
        if editorStore.editor == nil {
            let vc = makeEditor(viewControllerStore)
            let splitVC = vc.viewController as? EditorSplitViewController
            
            if splitVC?.editor?.document?.documentState.contains(.closed) == true {
                let doc = PyDocument(fileURL: url)
                doc.open { (_) in
                    splitVC?.editor?.document = doc
                    splitVC?.editor?.viewWillAppear(false)
                }
            } else {
                splitVC?.editor?.viewWillAppear(false)
            }
            
            self.editorStore.editor = vc
            if let traitCollection = scene?.windows.first?.traitCollection {
                self.editorStore.sizeClass = (traitCollection.horizontalSizeClass, traitCollection.verticalSizeClass)
            }
            view = AnyView(vc)
            
            (vc.viewController as? EditorSplitViewController)?.editor?.document?.checkForConflicts(onViewController: self.viewControllerStore?.vc ?? UIViewController(), completion: nil)
        } else {
            if editorVC?.document?.fileURL != url && !isOpeningStore.isOpening {
                isOpeningStore.isOpening = true
                editorVC?.textView.resignFirstResponder()
                
                editorVC?.document?.editor = nil
                
                func open() {
                    let document = PyDocument(fileURL: url)
                    document.open { (_) in
                        
                        func finallyOpen() {
                            editorVC?.isDocOpened = false
                            editorVC?.parent?.title = document.fileURL.deletingPathExtension().lastPathComponent
                            editorVC?.parent?.parent?.title = editorVC?.parent?.title
                            editorVC?.parent?.parent?.parent?.title = editorVC?.parent?.title // I'm not kidding
                            editorVC?.document = document
                            document.editor = editorVC
                            editorVC?.viewWillAppear(false)
                            self.isOpeningStore.isOpening = false
                        }
                        
                        if EditorStore.checkedForConflicts != url {
                            document.checkForConflicts(onViewController: self.viewControllerStore?.vc ?? UIViewController(), completion: {
                                
                                finallyOpen()
                            })
                        } else {
                            finallyOpen()
                        }
                        
                        EditorStore.checkedForConflicts = url
                    }
                }
                
                if editorVC?.document?.documentState.contains(.closed) != true {
                    editorVC?.document?.close(completionHandler: { (_) in
                        open()
                    })
                } else {
                    open()
                }
            }
            
            view = AnyView(editorStore.editor!)
        }
        
        return AnyView(view.navigationBarTitleDisplayMode(.inline).link(store: currentViewStore, isStack: isStack, selection: selection, selected: selected, restoredSelection: restoredSelection))
    }
}

/// A view that manages navigation with sidebar.
@available(iOS 14.0, *)
public struct SidebarNavigation: View {
    
    /// The text to display at the bottom of the sidebar.
    public static var footer: String?
    
    /// The file url to edit.
    @State var url: URL?
    
    /// The scene containing this sidebar navigation.
    var scene: UIWindowScene?
        
    /// The REPL view (without navigation).
    var repl: ViewController
    
    /// The PyPi view (without navigation).
    var pypi: ViewController
    
    /// The python -m view (without navigation).
    var runModule: ViewController
    
    /// The samples view (with navigation).
    var samples: SamplesNavigationView
    
    /// The documentation view (without navigation).
    var documentation: ViewController
    
    /// The loaded modules view (without navigation).
    var modules: ViewController
    
    /// The settings view (without navigation)
    var settings: ViewController
    
    /// The object storing the current view.
    let currentViewStore = CurrentViewStore()
        
    /// The data source storing recent items.
    @ObservedObject public var recentDataSource = RecentDataSource.shared
        
    /// The selected section in the sidebar.
    @ObservedObject var sceneStateStore: SceneStateStore
    
    /// The object storing the associated view controller.
    public let viewControllerStore: ViewControllerStore
    
    /// The block that makes an editor for the passed file.
    var makeEditor: ((URL) -> UIViewController)
    
    /// The size class.
    @Environment(\.horizontalSizeClass) var sizeClass
    
    /// The presentation mode.
    @Environment(\.presentationMode) var presentationMode
    
    /// The  user interface style.
    @Environment(\.colorScheme) var userInterfaceStyle
    
    /// A boolean indicating whether the navigation view style should be stack.
    @State var stack = false
    
    /// The selection restored from state restoration.
    @State var restoredSelection: SelectedSection?
    
    /// A boolean indicating whether the sidebar is shown.
    var isSidebarShowing: Bool {
        return (viewControllerStore.vc?.children.first as? UISplitViewController)?.displayMode != .secondaryOnly
    }
        
    /// Initializes from given views.
    ///
    /// - Parameters:
    ///     - url: The URL of the file to edit.
    ///     - scene: The Window Scene containing this sidebar navigation.
    ///     - pypiViewController: The View Controller for PyPi without navigation.
    ///     - samplesView: The view for samples with navigation included.
    ///     - documentationViewController: The View Controller for the documentation without documentation.
    ///     - modulesViewController: The View Controller for loaded modules.
    ///     - makeEditor: The block that makes an editor for the passed file.
    public init(url: URL?, scene: UIWindowScene?, sceneStateStore: SceneStateStore, restoreSelection: Bool, pypiViewController: UIViewController, samplesView: SamplesNavigationView, documentationViewController: UIViewController, modulesViewController: UIViewController, makeEditor: @escaping (URL) -> UIViewController) {
        
        let storyboard = UIStoryboard(name: "Main", bundle: .main)
        let store = ViewControllerStore()
        
        self.scene = scene
        self.sceneStateStore = sceneStateStore
        self.repl = ViewController(viewController: storyboard.instantiateViewController(withIdentifier: "replVC"), viewControllerStore: store)
        self.pypi = ViewController(viewController: pypiViewController, viewControllerStore: store)
        self.runModule = ViewController(viewController: storyboard.instantiateViewController(withIdentifier: "runModule"), viewControllerStore: store)
        self.samples = samplesView
        self.documentation = ViewController(viewController: documentationViewController, viewControllerStore: store)
        self.modules = ViewController(viewController: modulesViewController, viewControllerStore: store)
        self.settings = ViewController(viewController: UIStoryboard(name: "Settings", bundle: .main).instantiateInitialViewController() ?? UIViewController(), viewControllerStore: store)
        self.makeEditor = makeEditor
        
        self.viewControllerStore = store
        self.viewControllerStore.scene = scene
        
        recentDataSource.makeEditor = makeEditor
        if restoreSelection {
            _restoredSelection = .init(initialValue: sceneStateStore.sceneState.selection)
        }
        
        currentViewStore.sceneStateStore = sceneStateStore
        currentViewStore.navigation = self
        
        _url = .init(initialValue: url)
        
        samplesView.withoutNavigation.$selectedItemStore.scene.wrappedValue = scene
    }
    
    private func withDoneButton(_ view: AnyView) -> AnyView {
        if ProcessInfo.processInfo.isiOSAppOnMac {
            return view
        } else if sizeClass == .compact {
            return AnyView(view.navigationBarItems(leading: Button(action: {
                self.viewControllerStore.vc?.dismiss(animated: true, completion: nil)
            }, label: {
                Text("done", comment: "Done button").fontWeight(.bold)
            }).hoverEffect()))
        } else {
            return view
        }
    }
    
    /// The sidebar.
    public var sidebar: some View {
        List {
            Button {
                presentationMode.wrappedValue.dismiss()
                (viewControllerStore.vc?.presentingViewController as? DocumentBrowserViewController)?.sceneState = sceneStateStore.sceneState
                viewControllerStore.vc?.dismiss(animated: true, completion: nil)
            } label: {
                SidebarLabel("sidebar.scripts", systemImage: "folder", selection: nil, selected: sceneStateStore.sceneState.selection)
            }
                                    
            Section(header: Text("sidebar.recent")) {
                ForEach(recentDataSource.recentItems.reversed(), id: \.url) { item in
                    NavigationLink(
                        destination: EditorView(makeEditor: item.makeViewController, url: item.url, scene: scene, currentViewStore: currentViewStore, viewControllerStore: viewControllerStore, isStack: $stack, selection: .recent(item.url), selected: $sceneStateStore.sceneState.selection, restoredSelection: $restoredSelection),
                        label: {
                            SidebarLabel(FileManager.default.displayName(atPath: item.url.path), systemImage: "clock", selection: .recent(item.url), selected: sceneStateStore.sceneState.selection)
                        })
                }
            }
                        
            Section(header: Text("sidebar.python")) {
                NavigationLink(
                    destination: repl.navigationBarTitleDisplayMode(.inline).link(store: currentViewStore, isStack: $stack, selection: .repl, selected: $sceneStateStore.sceneState.selection, restoredSelection: $restoredSelection),
                    tag: SelectedSection.repl,
                    selection: $restoredSelection,
                    label: {
                        SidebarLabel("repl", systemImage: "play", selection: .repl, selected: sceneStateStore.sceneState.selection)
                })
                
                NavigationLink(
                    destination: runModule.navigationBarTitleDisplayMode(.inline).link(store: currentViewStore, isStack: $stack, selection: .runModule, selected: $sceneStateStore.sceneState.selection, restoredSelection: $restoredSelection),
                    tag: SelectedSection.runModule,
                    selection: $restoredSelection) {
                    SidebarLabel("sidebar.runModule", systemImage: "doc", selection: .runModule, selected: sceneStateStore.sceneState.selection)
                }
                
                NavigationLink(destination: pypi.onAppear {
                    scene?.title = "PyPI"
                }.onDisappear {
                    scene?.title = ""
                }.link(store: currentViewStore, isStack: $stack, selection: .pypi, selected: $sceneStateStore.sceneState.selection, restoredSelection: $restoredSelection),
                tag: SelectedSection.pypi,
                selection: $restoredSelection) {
                    SidebarLabel("sidebar.pypi", systemImage: "cube.box", selection: .pypi, selected: sceneStateStore.sceneState.selection)
                }
                
                NavigationLink(destination: modules.link(store: currentViewStore, isStack: $stack, selection: .loadedModules, selected: $sceneStateStore.sceneState.selection, restoredSelection: $restoredSelection),
                    tag: SelectedSection.loadedModules,
                    selection: $restoredSelection) {
                    SidebarLabel("sidebar.loadedModules", systemImage: "info.circle", selection: .loadedModules, selected: sceneStateStore.sceneState.selection)
                }
            }
            
            Section(header: Text("sidebar.resources")) {
                NavigationLink(destination: samples.withoutNavigation.onAppear {
                    scene?.title = "sidebar.examples"
                }.onDisappear {
                    scene?.title = ""
                }.link(store: currentViewStore, isStack: $stack, selection: .examples, selected: $sceneStateStore.sceneState.selection, restoredSelection: $restoredSelection),
                tag: SelectedSection.examples,
                selection: $restoredSelection) {
                    SidebarLabel("sidebar.examples", systemImage: "bookmark", selection: .examples, selected: sceneStateStore.sceneState.selection)
                }
                
                NavigationLink(destination: documentation.link(store: currentViewStore, isStack: $stack, selection: .documentation, selected: $sceneStateStore.sceneState.selection, restoredSelection: $restoredSelection),
                    tag: SelectedSection.documentation,
                    selection: $restoredSelection) {
                    SidebarLabel("help.documentation", systemImage: "book", selection: .documentation, selected: sceneStateStore.sceneState.selection)
                }
            }
            
            if let footer = SidebarNavigation.footer {
                Text(footer).font(.footnote).foregroundColor(.secondary)
            }
        }
        .listStyle(SidebarListStyle())
        .navigationTitle("Pyto")
        .navigationBarItems(trailing: Button(action: {
            let navVC = UINavigationController(rootViewController: settings.viewController ?? UIViewController())
            navVC.modalPresentationStyle = .formSheet
            self.viewControllerStore.vc?.present(navVC, animated: true, completion: nil)
        }, label: {
            Image(systemName: "gear")
        }).padding(5).hover())
        .onAppear {
            adjustBackground(userInterfaceStyle)
        }.onChange(of: userInterfaceStyle) { (value) in
            adjustBackground(value)
        }
    }
    
    /// Returns an editor.
    var editor: some View {
        EditorView(makeEditor: { (store) -> ViewController in
            return ViewController(viewController: self.makeEditor(url!) , viewControllerStore: store)
        }, url: url!, scene: scene, currentViewStore: self.currentViewStore, viewControllerStore: self.viewControllerStore, isStack: $stack, selection: .recent(url!), selected: $sceneStateStore.sceneState.selection, restoredSelection: $restoredSelection).navigationBarTitleDisplayMode(.inline).onAppear {
            currentViewStore.isEditor = true
        }.onDisappear {
            currentViewStore.isEditor = false
        }
    }
    
    /// The content view.
    var contentView: AnyView? {
        if currentViewStore.currentView != nil {
            return withDoneButton(currentViewStore.currentView!)
        } else if !stack && url != nil {
            return AnyView(editor.link(store: currentViewStore, isStack: $stack, selection: .recent(url!), selected: $sceneStateStore.sceneState.selection, restoredSelection: $restoredSelection).onAppear {
                if let url = url {
                    sceneStateStore.sceneState.selection = SelectedSection.recent(url)
                }
            })
        } else {
            return nil
        }
    }
        
    public var body: some View {
                
        // We don't put the if statement in the NavigationView body builder because for some reason, it behaves very, very strangely in iOS 14 beta 6. Instead, we initialize a different NavigationView.
        let navigationView: AnyView
        if let contentView = contentView, sizeClass != .compact || self.stack {
            navigationView = AnyView(NavigationView {
                sidebar
                contentView
            })
        } else if let contentView = contentView {
            navigationView = AnyView(NavigationView {
                contentView
            })
        } else if sizeClass == .compact { // Nothing to show, just show the sidebar
            navigationView = AnyView(NavigationView {
                sidebar
            })
        } else {
            navigationView = AnyView(NavigationView {
                sidebar
                Rectangle().fill(Color(.systemBackground))
            })
        }
        
        if stack {
            return AnyView(navigationView.navigationViewStyle(StackNavigationViewStyle()))
        } else {
            return AnyView(navigationView.navigationViewStyle(DoubleColumnNavigationViewStyle()))
        }
    }
}

@available(iOS 14.0, *)
struct Sidebar_Previews: PreviewProvider {
    static var previews: some View {
        SidebarNavigation(url: nil,
                          scene: nil,
                          sceneStateStore: SceneStateStore(),
                          restoreSelection: false,
                          pypiViewController: UIViewController(), samplesView: SamplesNavigationView(url: URL(fileURLWithPath: "/"), selectScript: { _ in }), documentationViewController: UIViewController(), modulesViewController: UIViewController(),
                          makeEditor: { _ in return UIViewController() }
        )
    }
}
