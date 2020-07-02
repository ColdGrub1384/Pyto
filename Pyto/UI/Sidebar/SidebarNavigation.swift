//
//  SidebarNavigation.swift
//  SwiftUI Views
//
//  Created by Adrian Labbé on 23-06-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import SwiftUI

// TODO: Localize

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
    
    /// The data source storing sections expansions state.
    @ObservedObject var expansionState = ExpansionState()
        
    /// The selected section in the sidebar.
    @ObservedObject var sceneStateStore: SceneStateStore
    
    /// The object storing the associated view controller.
    public let viewControllerStore = ViewControllerStore()
    
    /// The block that makes an editor for the passed file.
    var makeEditor: ((URL) -> UIViewController)
    
    /// The size class.
    @Environment(\.horizontalSizeClass) var sizeClass
    
    /// The presentation mode.
    @Environment(\.presentationMode) var presentationMode
    
    /// A boolean indicating whether the navigation view style should be stack.
    @State var stack = false
        
    /// Initializes from given views.
    ///
    /// - Parameters:
    ///     - url: The URL of the file to edit.
    ///     - scene: The Window Scene containing this sidebar navigation.
    ///     - pypiViewControlelr: The View Controller for PyPi without navigation.
    ///     - samplesView: The view for samples with navigation included.
    ///     - documentationViewController: The View Controller for the documentation without documentation.
    ///     - modulesViewController: The View Controller for loaded modules.
    ///     - makeEditor: The block that makes an editor for the passed file.
    public init(url: URL?, scene: UIWindowScene?, sceneStateStore: SceneStateStore, pypiViewController: UIViewController, samplesView: SamplesNavigationView, documentationViewController: UIViewController, modulesViewController: UIViewController, makeEditor: @escaping (URL) -> UIViewController) {
        
        let storyboard = UIStoryboard(name: "Main", bundle: .main)
        
        self.scene = scene
        self.sceneStateStore = sceneStateStore
        self.repl = ViewController(viewController: storyboard.instantiateViewController(withIdentifier: "replVC"))
        self.pypi = ViewController(viewController: pypiViewController)
        self.runModule = ViewController(viewController: storyboard.instantiateViewController(withIdentifier: "runModule"))
        self.samples = samplesView
        self.documentation = ViewController(viewController: documentationViewController)
        self.modules = ViewController(viewController: modulesViewController)
        self.settings = ViewController(viewController: UIStoryboard(name: "Settings", bundle: .main).instantiateInitialViewController() ?? UIViewController())
        self.makeEditor = makeEditor
        
        recentDataSource.makeEditor = makeEditor
        _stack = .init(initialValue: (url == nil && sceneStateStore.sceneState.selection == nil))
                
        currentViewStore.navigation = self
        
        self._url = .init(initialValue: url)
    }
    
    private func withDoneButton(_ view: AnyView) -> AnyView {
        if sizeClass == .compact {
            return AnyView(view.navigationBarItems(leading: Button(action: {
                self.viewControllerStore.vc?.dismiss(animated: true, completion: nil)
            }, label: {
                Text("done", comment: "Done button").fontWeight(.bold)
            })))
        } else {
            return view
        }
    }
    
    /// The sidebar.
    public var sidebar: some View {
        List {
            Button {
                presentationMode.wrappedValue.dismiss()
                viewControllerStore.vc?.dismiss(animated: true, completion: nil)
            } label: {
                Label("Scripts", systemImage: "folder")
            }
                        
            DisclosureGroup("Recent", isExpanded: $expansionState.isRecentExpanded) {
                ForEach(recentDataSource.recentItems, id: \.url) { item in
                    NavigationLink(
                        destination: item.viewController.navigationBarTitleDisplayMode(.inline).link(store: currentViewStore, isStack: $stack),
                        tag: SelectedSection.recent(item.url),
                        selection: $sceneStateStore.sceneState.selection,
                        label: {
                            Label(FileManager.default.displayName(atPath: item.url.path), systemImage: "clock")
                    })
                }
            }
            
            DisclosureGroup("Python", isExpanded: $expansionState.isPythonExpanded) {
                NavigationLink(
                    destination: repl.navigationBarTitleDisplayMode(.inline).link(store: currentViewStore, isStack: $stack),
                    tag: SelectedSection.repl,
                    selection: $sceneStateStore.sceneState.selection,
                    label: {
                        Label("REPL", systemImage: "play")
                    })
                                
                NavigationLink(
                    destination: runModule.navigationBarTitleDisplayMode(.inline).link(store: currentViewStore, isStack: $stack),
                    tag: SelectedSection.runModule,
                    selection: $sceneStateStore.sceneState.selection) {
                    Label("Run module (python -m)", systemImage: "doc")
                }
                
                NavigationLink(destination: pypi.onAppear {
                    scene?.title = "PyPI"
                }.onDisappear {
                    scene?.title = ""
                }.link(store: currentViewStore, isStack: $stack),
                tag: SelectedSection.pypi,
                selection: $sceneStateStore.sceneState.selection) {
                    Label("PyPI", systemImage: "cube.box")
                }
            }
            
            DisclosureGroup("Resources", isExpanded: $expansionState.isResourcesExpanded) {
                NavigationLink(destination: samples.withoutNavigation.onAppear {
                    scene?.title = "Examples"
                }.onDisappear {
                    scene?.title = ""
                }.link(store: currentViewStore, isStack: $stack),
                tag: SelectedSection.examples,
                selection: $sceneStateStore.sceneState.selection) {
                    Label("Examples", systemImage: "bookmark")
                }
                
                NavigationLink(destination: documentation.link(store: currentViewStore, isStack: $stack),
                               tag: SelectedSection.documentation,
                               selection: $sceneStateStore.sceneState.selection) {
                    Label("Documentation", systemImage: "book")
                }
            }
            
            DisclosureGroup("More", isExpanded: $expansionState.isMoreExpanded) {
                
                NavigationLink(destination: modules.link(store: currentViewStore, isStack: $stack),
                               tag: SelectedSection.loadedModules,
                               selection: $sceneStateStore.sceneState.selection) {
                    Label("Loaded modules", systemImage: "info.circle")
                }
                
                NavigationLink(destination: settings.link(store: currentViewStore, isStack: $stack),
                               tag: SelectedSection.settings,
                               selection: $sceneStateStore.sceneState.selection) {
                    Label("Settings", systemImage: "gear")
                }
            }
            
            if let footer = SidebarNavigation.footer {
                Text(footer).font(.footnote).foregroundColor(.secondary)
            }
        }
        .listStyle(SidebarListStyle())
        .navigationTitle("Pyto")
    }
    
    public var body: some View {
        
        var editor: some View {
            ViewController(viewController: makeEditor(url!)).navigationBarTitleDisplayMode(.inline)
        }
        
        let navView = NavigationView {
            if sizeClass != .compact || stack {
                sidebar
            }
                
            if currentViewStore.currentView != nil {
                // That's a lot of parenthesis
                withDoneButton(AnyView((currentViewStore.currentView!)))
            } else if !stack && url != nil {
                editor.link(store: currentViewStore, isStack: $stack).onAppear {
                    if let url = url {
                        sceneStateStore.sceneState.selection = SelectedSection.recent(url)
                    }
                }
            }
        }.onAppear {
            if stack {
                UITableView.appearance().backgroundColor = .systemBackground
            } else {
                UITableView.appearance().backgroundColor = .secondarySystemBackground
            }
        }
        
        if stack {
            return AnyView(navView.navigationViewStyle(StackNavigationViewStyle()))
        } else {
            return AnyView(navView.navigationViewStyle(DoubleColumnNavigationViewStyle()))
        }
    }
}

@available(iOS 14.0, *)
struct Sidebar_Previews: PreviewProvider {
    static var previews: some View {
        SidebarNavigation(url: nil,
                          scene: nil,
                          sceneStateStore: SceneStateStore(),
                          pypiViewController: UIViewController(), samplesView: SamplesNavigationView(url: URL(fileURLWithPath: "/"), selectScript: { _ in }), documentationViewController: UIViewController(), modulesViewController: UIViewController(),
                          makeEditor: { _ in return UIViewController() }
        )
    }
}
