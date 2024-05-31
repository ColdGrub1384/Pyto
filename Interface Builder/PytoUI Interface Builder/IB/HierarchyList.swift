//
//  HierarchyList.swift
//  PytoUI Interface Builder
//
//  Created by Emma on 04-07-22.
//

import SwiftUI
import UniformTypeIdentifiers

fileprivate class EmptyStackViewContent: UIView {}

extension UIImage {

 var sfSymbolName: String? {
        guard let strSeq = "\(String(describing: self))".split(separator: ")").first else { return nil }
        let str = String(strSeq)
        guard let name = str.split(separator: ":").last else { return nil }
        return String(name).replacingOccurrences(of: " ", with: "")
    }
}

@available(iOS 16.0, *) struct HierarchyList: View {
    
    struct Item: Identifiable {
        
        static var isExpanded = [UIView:Bool]()
        
        var id = UUID()
        
        var view: UIView
        
        var children: [Item]?
        
        var isExpanded: Bool {
            Self.isExpanded[view] ?? false
        }
        
        func updateIsExpanded(_ isExpanded: Bool) {
            Self.isExpanded = Self.isExpanded.filter({ (key, _) in
                key.next != nil
            })
            
            Self.isExpanded[view] = isExpanded
        }
    }
    
    struct Label: View {
        
        var item: Item
        
        @ObservedObject var stackViewManager: StackViewManager
        
        @State private var clipboardIsEmpty = false
        
        func description(item: Item) -> String {
            
            let dflt = prettifyClassName(NSStringFromClass(type(of: item.view)))
            
            if let name = item.view.model?.names.name(for: item.view.tag), !name.isEmpty {
                return name.replacingOccurrences(of: "_", with: " ").localizedCapitalized
            }
            
            if let stackView = item.view as? StackViewContainer {
                if stackView.manager.axis == .vertical {
                    return "Vertical Stack"
                } else if stackView.manager.axis == .horizontal {
                    return "Horizontal Stack"
                } else if stackView.manager.axis == .verticalScroll {
                    return "Vertical Scroll"
                } else if stackView.manager.axis == .horizontalScroll {
                    return "Horizontal Scroll"
                } else {
                    return "Unknown Stack"
                }
            } else if let label = item.view as? UILabel {
                return label.text?.isEmpty == false ? label.text! : dflt
            } else if let button = item.view as? UIButton {
                return button.title(for: .normal)?.isEmpty == false ? button.title(for: .normal)! : dflt
            } else if let textField = item.view as? UITextField {
                if let placeholder = textField.placeholder, !placeholder.isEmpty {
                    return placeholder
                } else if let text = textField.text, !text.isEmpty {
                    return text
                } else {
                    return dflt
                }
            } else if item.view is StackViewSpacer {
                return "Spacer"
            } else if item.view is StackViewDivider {
                return "Divider"
            } else {
                return dflt
            }
        }
        
        func remove(item: Item) {
            let manager = (item.view.superview?.superview?.superview?.next as? StackViewContainer)?.manager
            if let stackViewManager = manager, let i = stackViewManager.views.firstIndex(of: item.view) {
                stackViewManager.views.remove(at: i)
                self.stackViewManager.objectWillChange.send()
            } else if item.view is StackViewSpacer || item.view is StackViewDivider, let container = stackViewManager.stackViewContainer {
                func findSpacer(view: StackViewContainer) {
                    for subview in view.manager.views {
                        if subview == item.view {
                            if let i = view.manager.views.firstIndex(of: subview) {
                                view.manager.views.remove(at: i)
                                self.stackViewManager.objectWillChange.send()
                            }
                        } else if let container = subview as? StackViewContainer {
                            findSpacer(view: container)
                        }
                    }
                }
                
                findSpacer(view: container)
            }
            
            item.view.interfaceBuilder?.autosave()
            NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: item.view)
        }
        
        var body: some View {
            Group {
                if item.view is StackViewContainer {
                    SwiftUI.Label {
                       Text(description(item: item))
                    } icon: {
                        Image(systemName: "square.stack")
                    }
                } else {
                    SwiftUI.Label {
                        Text(description(item: item)).lineLimit(1)
                    } icon: {
                        if let image = Items.first(where: {
                            type(of: item.view) == $0.type
                        })?.image {
                            if let name = image.sfSymbolName {
                                Image(systemName: name).foregroundColor(.primary)
                            } else {
                                Image(uiImage: image)
                            }
                        } else {
                            EmptyView()
                        }
                    }
                }
            }.contextMenu(menuItems: {
                
                if !(item.view is StackViewSpacer) && !(item.view is StackViewDivider) {
                    SwiftUI.Button {
                        item.view.interfaceBuilder?.inspect(view: item.view, isRoot: item.view.interfaceBuilder?.containerView == item.view)
                    } label: {
                        SwiftUI.Label {
                            Text("Edit")
                        } icon: {
                            Image(systemName: "pencil")
                        }
                    }
                }
                
                SwiftUI.Divider()
                
                SwiftUI.Button {
                    Clipboard.shared.copy(view: item.view)
                } label: {
                    SwiftUI.Label {
                        Text("Copy")
                    } icon: {
                        Image(systemName: "doc.on.doc")
                    }
                }
                
                SwiftUI.Button {
                    Clipboard.shared.copy(view: item.view)
                    remove(item: item)
                } label: {
                    SwiftUI.Label {
                        Text("Cut")
                    } icon: {
                        Image(systemName: "scissors")
                    }
                }
                                
                SwiftUI.Button {
                    guard let view = Clipboard.shared.paste() else {
                        return
                    }
                    
                    guard let stackView = (item.view as? StackViewContainer) ?? item.view.superview?.superview?.superview?.next as? StackViewContainer else {
                        return
                    }
                    
                    stackView.manager.views.append(view)
                    NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: stackView.interfaceBuilder?.containerView ?? stackView)
                } label: {
                    SwiftUI.Label {
                        Text("Paste")
                    } icon: {
                        Image(systemName: "doc.on.clipboard")
                    }
                }.disabled(clipboardIsEmpty)
                
                SwiftUI.Divider()
                
                if let stackView = item.view as? StackViewContainer {
                    SwiftUI.Button {
                        stackView.interfaceBuilder?.showLibrary(containerView: stackView)
                    } label: {
                        SwiftUI.Label {
                            Text("Add")
                        } icon: {
                            Image(systemName: "plus")
                        }
                    }
                }
                
                SwiftUI.Button(role: .destructive) {
                    remove(item: item)
                } label: {
                    SwiftUI.Label {
                        Text("Remove")
                    } icon: {
                        Image(systemName: "trash.fill")
                    }
                }
            }).onReceive(NotificationCenter.Publisher(center: .default, name: DidChangeViewPaddingOrFrameNotificationName)) { notif in
                if (notif.object as? UIView) == item.view {
                    stackViewManager.objectWillChange.send()
                }
            }.onReceive(NotificationCenter.Publisher(center: .default, name: Clipboard.didChangeNotificationName), perform: { notif in
                
                guard let clipboard = notif.object as? Clipboard else {
                    return
                }
                
                clipboardIsEmpty = !clipboard.hasContent
            }).onDrag {
                let data = try? JSONEncoder().encode(ViewTag(tag: item.view.tag))
                let itemProvider = NSItemProvider(item: data as? NSSecureCoding, typeIdentifier: "interfacebuilder.view")
                return itemProvider
            }.onAppear {
                clipboardIsEmpty = !Clipboard.shared.hasContent
            }
        }
    }
    
    struct ItemView: View {
        
        var item: Item
        
        @ObservedObject var stackViewManager: StackViewManager
        
        @State var isExpanded = false
        
        func setTag(view: UIView) {
            var tag = Int.random(in: 1...9999)
            while item.view.interfaceBuilder?.view.viewWithTag(tag) != nil {
                tag = Int.random(in: 1...9999)
            }
            
            view.tag = tag
        }
        
        func drop(index: Int, providers: [NSItemProvider]) {
            DispatchQueue.global().async {
                                            
                var views = [UIView]()
                for provider in providers {
                    let topLevelSemaphore = DispatchSemaphore(value: 0)
                    _ = provider.loadDataRepresentation(for: .interfaceBuilderView, completionHandler: { data, _ in
                        guard let data = data else {
                            topLevelSemaphore.signal()
                            return
                        }
                        
                        DispatchQueue.global().async {
                            if let viewTag = try? JSONDecoder().decode(ViewTag.self, from: data) {
                                let semaphore = DispatchSemaphore(value: 0)
                                DispatchQueue.main.async {
                                    guard let view = item.view.interfaceBuilder?.containerView.viewWithTag(viewTag.tag) else {
                                        return
                                    }
                                    
                                    let manager = (view.superview?.superview?.superview?.next as? StackViewContainer)?.manager
                                    if let stackViewManager = manager, let i = stackViewManager.views.firstIndex(of: view) {
                                        stackViewManager.views.remove(at: i)
                                    } else if item.view is StackViewSpacer || item.view is StackViewDivider, let container = stackViewManager.stackViewContainer {
                                        @MainActor func findSpacer(view: StackViewContainer) {
                                            for subview in view.manager.views {
                                                if subview == view {
                                                    if let i = view.manager.views.firstIndex(of: subview) {
                                                        view.manager.views.remove(at: i)
                                                    }
                                                } else if let container = subview as? StackViewContainer {
                                                    findSpacer(view: container)
                                                }
                                            }
                                        }
                                        
                                        findSpacer(view: container)
                                    }
                                    
                                    views.append(view)
                                    semaphore.signal()
                                }
                                semaphore.wait()
                            } else if let index = try? JSONDecoder().decode(LibraryItem.self, from: data).index {
                                let semaphore = DispatchSemaphore(value: 0)
                                DispatchQueue.main.async {
                                    let item = Items[index]
                                    let view = item.makeView()
                                    view.clipsToBounds = true
                                    
                                    setTag(view: view)
                                    
                                    view.isUserInteractionEnabled = true
                                    
                                    view.interfaceBuilder = self.item.view.interfaceBuilder
                                    view.model = self.item.view.model
                                    
                                    guard var model = self.item.view.interfaceBuilder?.model else {
                                        return
                                    }
                                    item.configure(view: view, model: &model)
                                    self.item.view.interfaceBuilder?.model = model
                                    
                                    views.append(view)
                                    semaphore.signal()
                                }
                                semaphore.wait()
                            }
                            topLevelSemaphore.signal()
                        }
                    })
                    topLevelSemaphore.wait()
                }
                                            
                DispatchQueue.main.async {
                    for view in views {
                        guard let stackView = view.superview?.superview?.superview as? StackViewContainer else {
                            continue
                        }
                        
                        if let i = stackView.manager.views.firstIndex(of: view) {
                            stackView.manager.views.remove(at: i)
                        }
                    }
                    
                    (item.view as? StackViewContainer)?.manager.views.insert(contentsOf: views, at: index)
                    stackViewManager.objectWillChange.send()
                    NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: item.view)
                    item.view.interfaceBuilder?.autosave()
                }
            }
        }
        
        var body: some View {
            if item.children == nil {
                Label(item: item, stackViewManager: stackViewManager)
            } else {
                DisclosureGroup(isExpanded: $isExpanded) {
                    ForEach(item.children!.count == 0 ? [Item(view: EmptyStackViewContent())] : item.children!) { item in
                        if item.view is EmptyStackViewContent {
                            Text("Insert view here").foregroundColor(.secondary)
                        } else {
                            ItemView(item: item, stackViewManager: stackViewManager)
                        }
                    }.onInsert(of: [.interfaceBuilderView]) { index, providers in
                        
                        guard let container = item.view as? StackViewContainer else {
                            return
                        }
                        
                        var _index = index
                        if container.manager.views.count == 0 {
                            _index = 0
                        }
                        
                        drop(index: _index, providers: providers)
                    }
                } label: {
                    Label(item: item, stackViewManager: stackViewManager)
                }.onAppear {
                    if !isExpanded {
                        isExpanded = item.isExpanded
                    }
                }.onChange(of: isExpanded) { newValue in
                    item.updateIsExpanded(newValue)
                }
            }
        }
    }
    
    @ObservedObject var stackViewManager: StackViewManager
    
    var stackView: StackViewContainer
    
    init(stackView: StackViewContainer) {
        self.stackView = stackView
        self.stackViewManager = stackView.manager
    }
    
    func children(view: UIView) -> [Item]? {
        guard let stackView = view as? StackViewContainer else {
            return nil
        }
        
        return stackView.manager.views.map({
            Item(view: $0, children: children(view: $0))
        })
    }
    
    var hierarchy: Item {
        Item(view: stackView, children: children(view: stackView))
    }
    
    @State var editMode: EditMode = EditMode.active
        
    var body: some View {
        List {
            ItemView(item: hierarchy, stackViewManager: stackViewManager, isExpanded: true)
        }
            // TODO: Upgrade Xcode and iPadOS: .scrollContentBackground(Color(.secondarySystemBackground))
            .font(Font.custom("Menlo", size: UIFont.systemFontSize))
            .environment(\.editMode, $editMode)
    }
}
