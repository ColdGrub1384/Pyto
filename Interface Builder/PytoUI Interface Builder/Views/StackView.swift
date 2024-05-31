//
//  StackView.swift
//  PytoUI Interface Builder
//
//  Created by Emma on 01-07-22.
//

// Stack Views and Scroll Views

import SwiftUI
import UniformTypeIdentifiers
import Combine

struct LibraryItem: Codable {
    
    var index: Int
}

struct ViewTag: Codable {
    
    var tag: Int
}

public let WillReleaseViewNotificationName = Notification.Name(rawValue: "WillReleaseViewNotification")

extension View {
    /// Applies the given transform if the given condition evaluates to `true`.
    /// - Parameters:
    ///   - condition: The condition to evaluate.
    ///   - transform: The transform to apply to the source `View`.
    /// - Returns: Either the original `View` or the modified `View` if the condition is `true`.
    @ViewBuilder func `if`<Content: View>(_ condition: Bool, transform: (Self) -> Content) -> some View {
        if condition {
            transform(self)
        } else {
            self
        }
    }
}

@available(iOS 16.0, *) public class StackViewManager: NSObject, ObservableObject, NSCoding {
    
    public weak var stackViewContainer: StackViewContainer?
    
    public func encode(with coder: NSCoder) {
        coder.encode(views, forKey: "views")
        coder.encode(axis.rawValue, forKey: "axis")
        coder.encode(horizontalAlignment.rawValue, forKey: "horizontalAlignment")
        coder.encode(verticalAlignment.rawValue, forKey: "verticalAlignment")
    }
    
    required public init?(coder: NSCoder) {
        
        guard let views = coder.decodeObject(forKey: "views") as? [UIView] else {
            return nil
        }
        
        guard let axisString = coder.decodeObject(forKey: "axis") as? String, let axis = Axis(rawValue: axisString) else {
            return nil
        }
        
        guard let horizontalAlignmentString = coder.decodeObject(forKey: "horizontalAlignment") as? String, let horizontalAlignment = HorizontalAlignment(rawValue: horizontalAlignmentString) else {
            return nil
        }
        
        guard let verticalAlignmentString = coder.decodeObject(forKey: "verticalAlignment") as? String, let verticalAlignment = VerticalAlignment(rawValue: verticalAlignmentString) else {
            return nil
        }
        
        self.axis = axis
        self.views = views
        
        self.horizontalAlignment = horizontalAlignment
        self.verticalAlignment = verticalAlignment
        
        super.init()
    }
    
    public enum Axis: String {
        case vertical = "Vertical"
        case horizontal = "Horizontal"
        case verticalScroll = "Vertical Scroll"
        case horizontalScroll = "Horizontal Scroll"
    }
    
    public enum HorizontalAlignment: String, CaseIterable {
        case leading = "Leading"
        case trailing = "Trailing"
        case center = "Center"
    }
    
    public enum VerticalAlignment: String, CaseIterable {
        case top = "Top"
        case bottom = "Bottom"
        case center = "Center"
    }
    
    public var views = [UIView]() {
        didSet {
            objectWillChange.send()
        }
    }
    
    public var axis: Axis {
        didSet {
            objectWillChange.send()
        }
    }
    
    public var horizontalAlignment = HorizontalAlignment.center
    
    public var verticalAlignment = VerticalAlignment.center
    
    @objc private func willRelease(_ notification: Notification) {
        guard let view = notification.object as? UIView else {
            return
        }
        
        views.removeAll(where: { $0 == view })
    }
    
    public init(axis: Axis) {
        self.axis = axis
        super.init()
        
        NotificationCenter.default.addObserver(self, selector: #selector(willRelease(_:)), name: WillReleaseViewNotificationName, object: nil)
    }
    
    deinit {
        NotificationCenter.default.removeObserver(self)
    }
}

@available(iOS 16.0, *) struct StackViewContent: View, DropDelegate {
    
    struct ViewRepresentable: UIViewRepresentable {
        
        var view: UIView
        
        func makeUIView(context: Context) -> some UIView {
            view
        }
        
        func updateUIView(_ uiView: UIViewType, context: Context) {
        }
    }
    
    @ObservedObject var manager: StackViewManager
    
    weak var contentView: UIView?
    
    @State var pointedView: UIView?
    
    @State var clipboardIsEmpty = false
    
    let tableViewDataSource = PreviewTableViewDataSource()
    
    func needsFlexibleSize(stack: StackViewContainer) -> (width: Bool, height: Bool) {
        
        var width = false
        var height = false
        
        for view in stack.manager.views {
            
            if view.flexibleWidth {
                width = true
            }
            
            if view.flexibleHeight {
                height = true
            }
            
            if let container = view as? StackViewContainer {
                
                let flex = needsFlexibleSize(stack: container)
                
                if flex.width {
                    width = true
                }
                
                if flex.height {
                    height = true
                }
            }
        }
        
        return (width: width, height: height)
    }
    
    private func viewRepresentable(_ view: UIView) -> some View {
        
        if !(view is StackViewContainer), view.interfaceBuilder != nil {
            view.isUserInteractionEnabled = false
        } else {
            view.isUserInteractionEnabled = true
        }
        
        var flex: (width: Bool, height: Bool)?
        if let container = view as? StackViewContainer {
            flex = needsFlexibleSize(stack: container)
        }
        
        if let tableView = view as? UITableView, view.interfaceBuilder != nil {
            tableView.dataSource = tableViewDataSource
            tableView.delegate = tableViewDataSource
        }
        
        return ViewRepresentable(view: view)
            .cornerRadius(view.cornerRadius)
            .if(!(view is UIScrollView), transform: { v in
                v.padding(EdgeInsets(top: view.layoutMargins.top, leading: view.layoutMargins.left, bottom: view.layoutMargins.bottom, trailing: view.layoutMargins.right))
            })
            .frame(width: view.isHidden ? 0 : view.customWidth, height: view.isHidden ? 0 : view.customHeight)
            .if(view.flexibleWidth || flex?.width == true, transform: {
                $0.frame(maxWidth: .infinity)
            })
            .if(view.flexibleHeight || flex?.height == true, transform: {
                $0.frame(maxHeight: .infinity)
            })
            
            .fixedSize(horizontal: view.customWidth == nil && !(view is StackViewContainer) && !view.flexibleWidth, vertical: view.customHeight == nil && !(view is StackViewContainer) && !view.flexibleHeight)
            .onAppear {
                view.tintAdjustmentMode = .normal
            }
            .clipped()
    }
    
    func didSelect(item: InterfaceBuilderView, contentView: UIView?, library: LibraryViewController) {
        let manager = (contentView as? StackViewContainer)?.manager
        
        guard var model = contentView?.interfaceBuilder?.model else {
            return
        }
        
        let view = item.makeView()
        view.interfaceBuilder = contentView?.interfaceBuilder
        view.model = model
        view.clipsToBounds = true
        
        var tag = Int.random(in: 1...9999)
        while contentView?.interfaceBuilder?.containerView?.viewWithTag(tag) != nil {
            tag = Int.random(in: 1...9999)
        }
        
        view.tag = tag
        
        view.isUserInteractionEnabled = true
        manager?.views.append(view)
        view.interfaceBuilder = contentView?.interfaceBuilder
        
        item.configure(view: view, model: &model)
        
        view.model = model
        view.interfaceBuilder?.model = model
        
        library.navigationController?.dismiss(animated: true)
        
        update = true
        NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: contentView)
        
        contentView?.interfaceBuilder?.autosave()
    }
    
    var dropView: any View {
        if contentView != nil {
            return Rectangle()
                .fill(Color.primary.opacity(0.0000001))
                .onDrop(of: [.interfaceBuilderView], delegate: self)
        } else {
            return EmptyView()
        }
    }
    
    var content: some View {
        ForEach(manager.views, id: \.self) { view in
            Group {
                if view is StackViewSpacer || view is StackViewDivider {
                    ZStack {
                        if view is StackViewSpacer {
                            SwiftUI.Spacer()
                            AnyView(dropView)
                        } else if view is StackViewDivider {
                            SwiftUI.Divider().padding(5)
                        }
                    }
                } else {
                    if let stackView = view as? StackViewContainer {
                        
                        if stackView.manager.axis != .verticalScroll && stackView.manager.axis != .horizontalScroll {
                            
                            viewRepresentable(stackView).fixedSize(horizontal: !stackView.manager.views.contains(where: {
                                $0.flexibleWidth || ((stackView.manager.axis == .horizontal || stackView.manager.axis == .horizontalScroll) && $0 is StackViewSpacer)
                            }), vertical: !stackView.manager.views.contains(where: {
                                $0.flexibleHeight || ((stackView.manager.axis == .vertical || stackView.manager.axis == .verticalScroll) && $0 is StackViewSpacer)
                            }))
                        } else {
                            viewRepresentable(stackView).flexible(width: true, height: true)
                        }
                    } else {
                        viewRepresentable(view).onDrop(of: [.interfaceBuilderView], delegate: self)
                    }
                }
            }
            .background {
                if pointedView == view {
                    Color.blue.opacity(0.2)
                } else {
                    EmptyView()
                }
            }.onHover(perform: { enter in
                guard view.interfaceBuilder != nil else {
                    return
                }
                
                if enter {
                    pointedView = view
                } else if pointedView == view {
                    pointedView = nil
                }
            }).if(view.interfaceBuilder != nil, transform: { swiftUIView in
                swiftUIView.onDrag({
                    let tag = try? JSONEncoder().encode(ViewTag(tag: view.tag))
                    let itemProvider = NSItemProvider(item: tag as? NSSecureCoding, typeIdentifier: "interfacebuilder.view")
                    return itemProvider
                }).contextMenu {
                    
                    if !(view is StackViewSpacer) && !(view is StackViewDivider) {
                        SwiftUI.Button {
                            view.interfaceBuilder?.inspect(view: view)
                        } label: {
                            SwiftUI.Label {
                                Text("Edit")
                            } icon: {
                                Image(systemName: "pencil")
                            }
                        }
                        
                        SwiftUI.Divider()
                    }
                    
                    SwiftUI.Button {
                        Clipboard.shared.copy(view: view)
                    } label: {
                        SwiftUI.Label {
                            Text("Copy")
                        } icon: {
                            Image(systemName: "doc.on.doc")
                        }
                    }
                    
                    SwiftUI.Button {
                        Clipboard.shared.copy(view: view)
                        if let i = manager.views.firstIndex(of: view) {
                            manager.views.remove(at: i)
                        }
                        
                        contentView?.interfaceBuilder?.autosave()
                        update = true
                        NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: contentView)
                    } label: {
                        SwiftUI.Label {
                            Text("Cut")
                        } icon: {
                            Image(systemName: "scissors")
                        }
                    }
                                    
                    SwiftUI.Button {
                        guard let newView = Clipboard.shared.paste() else {
                            return
                        }
                        
                        manager.views.append(newView)
                        NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: contentView?.interfaceBuilder?.containerView ?? contentView)
                    } label: {
                        SwiftUI.Label {
                            Text("Paste")
                        } icon: {
                            Image(systemName: "doc.on.clipboard")
                        }
                    }.disabled(clipboardIsEmpty)
                    
                    SwiftUI.Divider()
                    
                    if view is StackViewContainer {
                        SwiftUI.Button {
                            let library = LibraryViewController(style: .plain)
                            library.didSelect = { item in
                                self.didSelect(item: item, contentView: view, library: library)
                            }
                            
                            let navVC = UINavigationController(rootViewController: library)
                            navVC.view.backgroundColor = .systemBackground
                            navVC.modalPresentationStyle = .pageSheet
                            navVC.sheetPresentationController?.detents = [.medium(), .large()]
                            navVC.sheetPresentationController?.prefersGrabberVisible = true
                            view.interfaceBuilder?.present(navVC, animated: true)
                        } label: {
                            SwiftUI.Label {
                                Text("Add")
                            } icon: {
                                Image(systemName: "plus")
                            }
                        }
                    }
                    
                    if manager.views.count > 1 {
                        
                        SwiftUI.Divider()
                        
                        if view != manager.views.first {
                            SwiftUI.Button {
                                if let i = manager.views.firstIndex(of: view) {
                                    manager.views.remove(at: i)
                                    manager.views.insert(view, at: i-1)
                                }
                                
                                contentView?.interfaceBuilder?.autosave()
                                NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: contentView)
                            } label: {
                                if manager.axis == .vertical || manager.axis == .verticalScroll {
                                    SwiftUI.Label {
                                        Text("Move up")
                                    } icon: {
                                        Image(systemName: "arrowtriangle.up.fill")
                                    }
                                } else {
                                    SwiftUI.Label {
                                        Text("Move left")
                                    } icon: {
                                        Image(systemName: "arrowtriangle.left.fill")
                                    }
                                }
                            }
                        }
                        
                        if view != manager.views.last {
                            SwiftUI.Button {
                                if let i = manager.views.firstIndex(of: view) {
                                    manager.views.remove(at: i)
                                    manager.views.insert(view, at: i+1)
                                }
                                
                                contentView?.interfaceBuilder?.autosave()
                                NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: contentView)
                            } label: {
                                if manager.axis == .vertical || manager.axis == .verticalScroll {
                                    SwiftUI.Label {
                                        Text("Move down")
                                    } icon: {
                                        Image(systemName: "arrowtriangle.down.fill")
                                    }
                                } else {
                                    SwiftUI.Label {
                                        Text("Move right")
                                    } icon: {
                                        Image(systemName: "arrowtriangle.right.fill")
                                    }
                                }
                            }
                        }
                    }
                    
                    SwiftUI.Divider()
                    
                    SwiftUI.Button(role: .destructive) {
                        if let i = manager.views.firstIndex(of: view) {
                            manager.views.remove(at: i)
                        }
                        
                        contentView?.interfaceBuilder?.autosave()
                        update = true
                        NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: contentView)
                    } label: {
                        SwiftUI.Label {
                            Text("Remove")
                        } icon: {
                            Image(systemName: "trash")
                        }
                    }
                } preview: {
                    Text(prettifyClassName(NSStringFromClass(type(of: view)))).font(.custom("Menlo", size: UIFont.systemFontSize)).padding()
                }
            })
        }.onAppear {
            clipboardIsEmpty = !Clipboard.shared.hasContent
        }.onReceive(NotificationCenter.Publisher(center: .default, name: Clipboard.didChangeNotificationName)) { notif in
            
            guard let clipboard = notif.object as? Clipboard else {
                return
            }
            
            clipboardIsEmpty = !clipboard.hasContent
        }
    }
    
    @State private var update = false
    
    @State private var isDropping = false
    
    @State private var updated = false
    
    var parentUpdate: Binding<Bool>?
        
    func setTag(view: UIView) {
        var tag = Int.random(in: 1...9999)
        while contentView?.interfaceBuilder?.view.viewWithTag(tag) != nil {
            tag = Int.random(in: 1...9999)
        }
        
        view.tag = tag
    }
    
    func drop(providers: [NSItemProvider]) -> Bool {
        
        for itemProvider in providers {
            
            _ = itemProvider.loadDataRepresentation(for: .interfaceBuilderView) { data, _ in
                
                guard let data = data else {
                    return
                }
                
                DispatchQueue.main.async {
                    if let index = try? JSONDecoder().decode(LibraryItem.self, from: data).index {
                        let item = Items[index]
                        let view = item.makeView()
                        view.clipsToBounds = true
                        
                        setTag(view: view)
                        
                        view.isUserInteractionEnabled = true
                        manager.views.append(view)
                        
                        view.interfaceBuilder = self.contentView?.interfaceBuilder
                        view.model = self.contentView?.model
                        
                        guard var model = self.contentView?.interfaceBuilder?.model else {
                            return
                        }
                        item.configure(view: view, model: &model)
                        self.contentView?.interfaceBuilder?.model = model
                    } else if let tag = try? JSONDecoder().decode(ViewTag.self, from: data).tag {
                        
                        guard let view = contentView?.interfaceBuilder?.view.viewWithTag(tag) else {
                            return
                        }
                        
                        guard let stackView = view.superview?.superview?.superview?.superview as? StackViewContainer else {
                            return
                        }
                        
                        if let i = stackView.manager.views.firstIndex(of: view) {
                            stackView.manager.views.remove(at: i)
                            manager.views.append(view)
                        }
                    }
                    
                    update = true
                    NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: contentView)
                    
                    contentView?.interfaceBuilder?.autosave()
                }
            }
            
        }
            
        
        return true
    }
    
    func dropEntered(info: DropInfo) {
        isDropping = true
    }
    
    func dropExited(info: DropInfo) {
        isDropping = false
    }
    
    func validateDrop(info: DropInfo) -> Bool {
        contentView?.interfaceBuilder != nil && info.hasItemsConforming(to: [.interfaceBuilderView])
    }
    
    func dropUpdated(info: DropInfo) -> DropProposal? {
        return DropProposal(operation: .move)
    }
    
    func performDrop(info: DropInfo) -> Bool {
        isDropping = false
        return drop(providers: info.itemProviders(for: [.interfaceBuilderView]))
    }
        
    var body: some View {
        Group {
            if !update {
                ZStack {
                    
                    (isDropping ? Color.blue.opacity(0.2) : Color.primary.opacity(0.000001)).onDrop(of: [.interfaceBuilderView], delegate: self)
                    
                    switch manager.axis {
                    case .horizontal:
                        HStack(alignment: [manager.verticalAlignment].map({
                            switch $0 {
                            case .top:
                                return VerticalAlignment.top
                            case .bottom:
                                return VerticalAlignment.bottom
                            case .center:
                                return VerticalAlignment.center
                            }
                        })[0]) {
                            content
                        }
                    case .vertical:
                        VStack(alignment: [manager.horizontalAlignment].map({
                            switch $0 {
                            case .leading:
                                return HorizontalAlignment.leading
                            case .trailing:
                                return HorizontalAlignment.trailing
                            case .center:
                                return HorizontalAlignment.center
                            }
                        })[0]) {
                            content
                        }
                    case .horizontalScroll:
                        SwiftUI.ScrollView(.horizontal, showsIndicators: true) {
                            HStack {
                                content
                            }
                        }
                    case .verticalScroll:
                        SwiftUI.ScrollView(.vertical, showsIndicators: true) {
                            VStack {
                                content
                            }
                        }.flexible(width: true, height: true)
                    }
                }
            } else {
                Text("").onAppear {
                    DispatchQueue.main.async {
                        update = false
                        contentView?.interfaceBuilder?.autosave()
                    }
                }
            }
        }
            .onReceive(NotificationCenter.Publisher(center: .default, name: DidChangeViewPaddingOrFrameNotificationName)) { notif in
                
                guard let view = notif.object as? UIView else {
                    return
                }
                
                if view.next?.next?.next?.next is UINavigationBar {
                    view.sizeToFit()
                }
                
                if manager.views.contains(view) || view == contentView {
                    update = true
                    if let parentStack = contentView?.superview?.superview?.superview as? StackViewContainer {
                        NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: parentStack)
                    }
                }
            }
    }
}

@available(iOS 16.0, *) public class StackViewContainer: UIView {
    
    public override var tag: Int {
        didSet {
            print(tag)
        }
    }
    
    public var manager: StackViewManager! {
        didSet {
            manager.stackViewContainer = self
        }
    }
    
    public var stackView: UIView!
        
    public var emptyLabel: UILabel!
    
    private var cancellableBag = Set<AnyCancellable>()
    
    private func setup() {
        let stackView = StackViewContent(manager: manager, contentView: self)
        let vc = UIHostingController(rootView: stackView)
        vc.view.frame = frame
        vc.view.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        vc.view.backgroundColor = .clear
        self.stackView = vc.view
        addSubview(vc.view)
        
        emptyLabel = UILabel()
        emptyLabel.text = "Insert view here"
        emptyLabel.textColor = .secondaryLabel
        emptyLabel.sizeToFit()
        emptyLabel.isHidden = manager.views.count > 0
        emptyLabel.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        addSubview(emptyLabel)
        
        manager.objectWillChange.sink { [weak self] _ in
            
            guard self?.interfaceBuilder?.containerView != self else {
                return
            }
            
            self?.emptyLabel.isHidden = self!.manager.views.count > 0
        }.store(in: &cancellableBag)
    }
    
    public init(axis: StackViewManager.Axis) {
        super.init(frame: CGRect(x: 0, y: 0, width: 375, height: 667))
        
        manager = StackViewManager(axis: axis)
        setup()
    }
    
    override public var intrinsicContentSize: CGSize {
        manager.views.count > 0 ? stackView.intrinsicContentSize : emptyLabel.intrinsicContentSize
    }
    
    override public func encode(with coder: NSCoder) {
        
        stackView.removeFromSuperview()
        emptyLabel.removeFromSuperview()
        super.encode(with: coder)
        addSubview(stackView)
        addSubview(emptyLabel)
        
        coder.encode(manager, forKey: "manager")
        coder.encode(tag, forKey: "tag")
    }
    
    public override func didMoveToSuperview() {
        super.didMoveToSuperview()
        
        if interfaceBuilder?.containerView == self {
            emptyLabel.isHidden = true
        }
    }
    
    public override func didMoveToWindow() {
        super.didMoveToWindow()
        didMoveToSuperview()
    }
        
    required public init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
        
        guard let manager = aDecoder.decodeObject(forKey: "manager") as? StackViewManager else {
            return nil
        }
        
        if aDecoder.containsValue(forKey: "tag") {
            self.tag = aDecoder.decodeInteger(forKey: "tag")
        }
        
        self.manager = manager
        setup()
    }
    
    public override func viewWithTag(_ tag: Int) -> UIView? {
        for view in manager.views {
            
            if view.tag == tag {
                return view
            } else if let subview = view.viewWithTag(tag) {
                return subview
            }
        }
        
        return nil
    }
    
    public override func willMove(toWindow newWindow: UIWindow?) {
        super.willMove(toWindow: newWindow)
        
        NotificationCenter.default.addObserver(forName: .init("GlobalTraitCollectionDidChange"), object: nil, queue: .main) { [weak self] notif in
            if (notif.object as? UIWindowScene) == self?.window?.windowScene {
                guard let style = self?.window?.windowScene?.traitCollection.userInterfaceStyle else {
                    return
                }
                let pyView = (NSClassFromString("Pyto.PyView") as? NSObject.Type)?.perform(NSSelectorFromString("view:"), with: self)?.takeUnretainedValue()
                let customAppearance = pyView?.value(forKey: "customAppearance") as? Int
                if customAppearance == 0 {
                    self?.overrideUserInterfaceStyle = style
                }
            }
        }
    }
    
    @objc public class var StackViewContainer_properties: [Any] {
        return [
            InspectorProperty(name: "Axis", valueType: .dynamicEnumeration(.init(handler: { view in
                
                guard let stackView = view as? StackViewContainer else {
                    return []
                }
                
                if stackView.manager.axis == .horizontal || stackView.manager.axis == .vertical {
                    return ["Vertical", "Horizontal"]
                } else {
                    return ["Vertical Scroll", "Horizontal Scroll"]
                }
                
            })), getValue: { view in
                guard let stackView = view as? StackViewContainer else {
                    return .init(value: 0)
                }
                
                return .init(value: stackView.manager.axis.rawValue)
            }, handler: { view, value in
                guard let stackView = view as? StackViewContainer else {
                    return
                }
                
                if let value = value.value as? String, let axis = StackViewManager.Axis(rawValue: value) {
                    stackView.manager.axis = axis
                }
                
                NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: view)
            }),
            
            InspectorProperty(name: "Vertical Alignment", valueType: .enumeration(StackViewManager.VerticalAlignment.allCases.map { $0.rawValue }), getValue: { view in
                guard let stackView = view as? StackViewContainer else {
                    return .init(value: 0)
                }
                
                return .init(value: stackView.manager.verticalAlignment.rawValue)
            }, handler: { view, value in
                guard let stackView = view as? StackViewContainer else {
                    return
                }
                
                stackView.manager.verticalAlignment = StackViewManager.VerticalAlignment.allCases.first(where: { $0.rawValue == (value.value as? String) }) ?? .center
                
                NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: view)
            }, isChangeable: {
                ($0 as? StackViewContainer)?.manager.axis == .horizontal
            }),
            
            InspectorProperty(name: "Horizontal Alignment", valueType: .enumeration(StackViewManager.HorizontalAlignment.allCases.map { $0.rawValue }), getValue: { view in
                guard let stackView = view as? StackViewContainer else {
                    return .init(value: 0)
                }
                
                return .init(value: stackView.manager.horizontalAlignment.rawValue)
            }, handler: { view, value in
                guard let stackView = view as? StackViewContainer else {
                    return
                }
                
                stackView.manager.horizontalAlignment = StackViewManager.HorizontalAlignment.allCases.first(where: { $0.rawValue == (value.value as? String) }) ?? .center
                
                NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: view)
            }, isChangeable: {
                ($0 as? StackViewContainer)?.manager.axis == .vertical
            })
        ]
    }
}

@available(iOS 16.0, *) struct VerticalStackView: InterfaceBuilderView {
    
    var type: UIView.Type = StackViewContainer.self
    
    var previewColor: UIColor? {
        .gray
    }
    
    func preview(view: UIView) { }
    
    func configure(view: UIView, model: inout InterfaceModel) {
        
    }
    
    var image: UIImage? {
        UIImage(systemName: "square.stack.3d.down.forward")
    }
    
    var customDisplayName: String? {
        "Vertical Stack"
    }
    
    func makeView() -> UIView {
        StackViewContainer(axis: .vertical)
    }
}

@available(iOS 16.0, *) struct HorizontalStackView: InterfaceBuilderView {
    
    var type: UIView.Type = StackViewContainer.self
    
    var previewColor: UIColor? {
        .gray
    }
    
    func preview(view: UIView) {
    }
    
    func configure(view: UIView, model: inout InterfaceModel) {
        
    }
    
    var image: UIImage? {
        UIImage(systemName: "square.stack.3d.down.forward")
    }
    
    var customDisplayName: String? {
        "Horizontal Stack"
    }
    
    func makeView() -> UIView {
        StackViewContainer(axis: .horizontal)
    }
}

@available(iOS 16.0, *) struct ScrollView: InterfaceBuilderView {
    
    var type: UIView.Type = StackViewContainer.self
    
    var previewColor: UIColor? {
        .secondaryLabel
    }
    
    func preview(view: UIView) { }
    
    func configure(view: UIView, model: inout InterfaceModel) {
        
    }
    
    var image: UIImage? {
        UIImage(systemName: "scroll")
    }
    
    var customDisplayName: String? {
        "Scroll View"
    }
    
    func makeView() -> UIView {
        StackViewContainer(axis: .verticalScroll)
    }
}
