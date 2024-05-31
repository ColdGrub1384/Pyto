//
//  InspectorView.swift
//  PytoUI Interface Builder
//
//  Created by Emma on 30-06-22.
//

import SwiftUI

/// A view for modifying a view xd.
@available(iOS 16.0, *) struct InspectorView: View {
    
    /// The inspector presenting this view.
    var inspectorViewController: InspectorViewController

    /// Returns a list of properties for the given view type.
    static func getProperties(viewType: UIView.Type) -> [InspectorProperty]? {
        
        let className = NSStringFromClass(viewType).components(separatedBy: ".").last ?? ""
        let sel = NSSelectorFromString("\(className)_properties")
        guard viewType.responds(to: sel) else {
            return []
        }
        
        return viewType.perform(sel)?.takeUnretainedValue() as? [InspectorProperty]
    }
    
    /// The properties of the view, per class.
    var properties: [(type: UIView.Type, properties: [InspectorProperty], id: UUID)]
    
    /// Initializes the inspector view with the given Inspector view controller.
    init(inspectorViewController: InspectorViewController, showTopBar: Bool = true) {
        self.inspectorViewController = inspectorViewController
        
        var props = [(type: UIView.Type, properties: [InspectorProperty], id: UUID)]()
        
        var cls: UIView.Type? = type(of: inspectorViewController.inspectedView)
        guard let properties = Self.getProperties(viewType: cls!) else {
            self.properties = []
            return
        }
        props.append((type: cls!, properties: properties, id: UUID()))
        
        cls = cls?.superclass() as? UIView.Type
        while cls != nil, let properties = Self.getProperties(viewType: cls!) {
            props.append((type: cls!, properties: properties, id: UUID()))
            cls = cls?.superclass() as? UIView.Type
        }
        
        self.properties = props
        self.showTopBar = showTopBar
    }
        
    /// A Disclosure group listing a list of properties
    struct PropertiesView<AdditionalType: View, LabelType: View>: View {
        
        /// The properties to be listed.
        var properties: [InspectorProperty]
        
        /// The view that is currently being inspected.
        var view: UIView
        
        /// Additional views to add below the properties.
        @ViewBuilder var additional: (() -> AdditionalType)
        
        /// The label of the Disclosure group.
        @ViewBuilder var label: (() -> LabelType)
        
        @State private var isExpanded = true
        
        @State private var update = false
        
        @State var lastFilteredProperties = [InspectorProperty]()
        
        private func getFilteredProperties() -> [InspectorProperty] {
            let properties = properties.filter {
                $0.isChangeable?(view) ?? true
            }
            
            DispatchQueue.main.async {
                lastFilteredProperties = properties
            }
            
            return properties
        }
        
        var body: some View {
            DisclosureGroup(isExpanded: $isExpanded) {
                if update {
                    Text("").onAppear {
                        update = false
                    }
                } else {
                    ForEach(getFilteredProperties()) { property in
                        PropertyView(property: property, view: view)
                    }
                }
                
                additional()
            } label: {
                label()
            }.onReceive(NotificationCenter.Publisher(center: .default, name: DidChangeViewPaddingOrFrameNotificationName)) { _ in
                if lastFilteredProperties.map({ $0.name }) != getFilteredProperties().map({ $0.name }) {
                    update = true
                }
            }.onAppear {
                _ = getFilteredProperties()
            }
        }
    }

    /// A cell displaying the name of a property and it's value. Let's the user edit the value by pressing it.
    struct PropertyView: View {
        
        /// The property.
        var property: InspectorProperty
        
        @State private var value: Any? = 0
                
        /// The view being inspected.
        var view: UIView
        
        private var selectedColor: Binding<Color>!
                
        /// Initializes the property view with the property and the view.
        init(property: InspectorProperty, view: UIView) {
            self.property = property
            self.view = view
            selectedColor = .init(get: { () -> Color in
                if let color = property.getValue(view).value as? UIColor {
                    return Color(uiColor: color)
                } else {
                    return Color.clear
                }
            }, set: { newValue in
                property.handler(view, .init(value: UIColor(newValue)))
            })
        }
        
        private struct OptionalPropertyView: View {
            
            var property: InspectorProperty
            
            var view: UIView
            
            var getDefaultValue: (UIView) -> InspectorProperty.Value
            
            @State var isEnabled: Bool
            
            @State private var update = false
            
            init(property: InspectorProperty, view: UIView) {
                var newProperty = property
                
                if case .optional(let type, let getDefaultValue) = newProperty.valueType {
                    newProperty.valueType = type
                    self.getDefaultValue = getDefaultValue
                } else {
                    getDefaultValue = { _ in
                        .init(value: nil)
                    }
                }
                
                self.property = newProperty
                self.view = view
                self._isEnabled = State(initialValue: property.getValue(view).value != nil)
            }
            
            var body: some View {
                VStack {
                    Toggle(isOn: $isEnabled) {
                        Text(property.name)
                    }
                    
                    if !update {
                        if isEnabled {
                            PropertyView(property: property, view: view)
                        } else {
                            Text("")
                        }
                    } else {
                        Text("").onAppear {
                            update = false
                        }
                    }
                }.onChange(of: isEnabled) { newValue in
                    if !isEnabled {
                        property.handler(view, .init(value: nil))
                    } else {
                        property.handler(view, getDefaultValue(view))
                        update = true
                    }
                    NotificationCenter.default.post(name: DidChangeViewPaddingOrFrameNotificationName, object: view)
                }
            }
        }
        
        private func image(_ image: InspectorImage) -> Image {
            switch image {
            case .symbol(let name):
                return Image(systemName: name)
            default:
                if let uiImage = (view as? UIImageView)?.image {
                    return Image(uiImage: uiImage)
                } else {
                    return Image(systemName: "photo")
                }
            }
        }
        
        var body: some View {
            switch property.valueType {
            case .optional(_, _):
                OptionalPropertyView(property: property, view: view)
            default:
                HStack {
                    
                    Text(property.name)
                    SwiftUI.Spacer()
                    
                    Group {
                        switch property.valueType {
                        case .string:
                            NavigationLink {
                                TextInput(property: property, view: view)
                                    .navigationTitle(property.name)
                            } label: {
                                HStack {
                                    SwiftUI.Spacer()
                                    Text((value as? String) ?? "").lineLimit(1)
                                }
                            }
                        case .number:
                            NavigationLink {
                                FloatInput(property: property, view: view)
                                    .navigationTitle(property.name)
                            } label: {
                                HStack {
                                    SwiftUI.Spacer()
                                    Text(String("\(value ?? "nil")"))
                                }
                            }
                        case .integer:
                            NavigationLink {
                                IntegerInput(property: property, view: view)
                                    .navigationTitle(property.name)
                            } label: {
                                HStack {
                                    SwiftUI.Spacer()
                                    Text(String("\(value ?? "nil")"))
                                }
                            }
                        case .boolean:
                            Toggle(isOn: .init(get: {
                                (value as? Bool) ?? false
                            }, set: { newValue in
                                value = newValue
                                property.handler(view, .init(value: newValue))
                            })) {
                                EmptyView()
                            }
                        case .color:
                            NavigationLink {
                                SystemColorsView(property: property, view: view)
                            } label: {
                                HStack {
                                    SwiftUI.Spacer()
                                    
                                    ColorPicker(selection: selectedColor, supportsOpacity: true) {
                                        EmptyView()
                                    }.frame(width: 30).disabled(true)
                                }
                            }
                        case .font:
                            if let font = property.getValue(view).value as? UIFont {
                                NavigationLink {
                                    FontPicker(property: property, view: view)
                                } label: {
                                    HStack {
                                        SwiftUI.Spacer()
                                        Text(font.familyName+" \(font.pointSize)px").font(Font(font.withSize(UIFont.systemFontSize)))
                                    }
                                }
                            }
                        case .image:
                            if let image = property.getValue(view).value as? InspectorImage {
                                NavigationLink {
                                    ImagePicker(property: property, view: view)
                                } label: {
                                    HStack {
                                        SwiftUI.Spacer()
                                        self.image(image)
                                            .resizable()
                                            .aspectRatio(contentMode: SwiftUI.ContentMode.fit)
                                            .frame(width: 20, height: 20)
                                            .foregroundColor(.primary)
                                    }
                                }
                            }
                        case .barItem:
                            if let buttonItem = property.getValue(view).value as? UIBarButtonItem {
                                NavigationLink {
                                    BarItemInput(property: property, view: view)
                                } label: {
                                    HStack {
                                        SwiftUI.Spacer()
                                        Text((buttonItem.customView as? UIButton)?.configuration?.title ?? "")
                                        if let image = (buttonItem.customView as? UIButton)?.configuration?.image, !image.isSymbolImage {
                                            Image(uiImage: image)
                                                .foregroundColor(.secondary)
                                                .padding(.leading)
                                        } else if let symbol = (buttonItem.customView as? UIButton)?.configuration?.image?.sfSymbolName {
                                            Image(systemName: symbol)
                                                .foregroundColor(.secondary)
                                                .padding(.leading)
                                        }
                                    }
                                }
                            }
                        case .array(_, _):
                            NavigationLink {
                                ArrayInput(property: property, view: view)
                                    .navigationTitle(property.name)
                            } label: {
                                HStack {
                                    SwiftUI.Spacer()
                                    Text("\((value as? [Any?])?.count ?? 0) items")
                                }
                            }
                        case .enumeration(_), .dynamicEnumeration(_):
                            NavigationLink {
                                EnumerationPicker(property: property, view: view)
                            } label: {
                                HStack {
                                    SwiftUI.Spacer()
                                    Text((value as? String) ?? "Unknown")
                                }
                            }
                        case .optional(_, _):
                            EmptyView()
                        }
                    }.foregroundColor(.secondary)
                }
                    .onAppear {
                        value = property.getValue(view).value
                    }
            }
        }
    }
    
    @State private var update = false
    
    /// A boolean indicating wether to show the top bar or not.
    public var showTopBar = true
    
    var content: some View {
        List {
            if !update {
                
                if inspectorViewController.isRoot {
                    PropertyView(property: InspectorProperty(name: "Title", valueType: .string, getValue: { view in
                        .init(value: (view.next as? UIViewController)?.title ?? "")
                    }, handler: { view, value in
                        (view.next as? UIViewController)?.title = value.value as? String
                    }), view: inspectorViewController.inspectedView)
                    
                    PropertyView(property: InspectorProperty(name: "Large title", valueType: .boolean, getValue: { view in
                        .init(value: (view.next as? UIViewController)?.navigationItem.largeTitleDisplayMode == .always)
                    }, handler: { view, value in
                        guard let largeTitle = value.value as? Bool else {
                            return
                        }
                        
                        let navigationItem = (view.next as? UIViewController)?.navigationItem
                        
                        if largeTitle {
                            navigationItem?.largeTitleDisplayMode = .always
                        } else {
                            navigationItem?.largeTitleDisplayMode = .never
                        }
                    }), view: inspectorViewController.inspectedView)
                    
                    PropertyView(property: InspectorProperty(name: "Title Color", valueType: .color, getValue: { view in
                        let navVC = (view.next as? UIViewController)?.navigationController
                        return .init(value: (navVC?.navigationBar.titleTextAttributes?[.foregroundColor] as? UIColor) ?? UIColor.label)
                    }, handler: { view, value in
                        let navVC = (view.next as? UIViewController)?.navigationController
                        if navVC?.navigationBar.titleTextAttributes != nil {
                            navVC?.navigationBar.titleTextAttributes?[.foregroundColor] = value.value as? UIColor
                            navVC?.navigationBar.largeTitleTextAttributes?[.foregroundColor] = value.value as? UIColor
                        } else {
                            navVC?.navigationBar.titleTextAttributes = [.foregroundColor: (value.value as? UIColor) ?? UIColor.label]
                            navVC?.navigationBar.largeTitleTextAttributes = [.foregroundColor: (value.value as? UIColor) ?? UIColor.label]
                        }
                    }), view: inspectorViewController.inspectedView)
                    
                    PropertyView(property: InspectorProperty(name: "Show Top Bar", valueType: .boolean, getValue: { view in
                        .init(value: (view.next as? UIViewController)?.navigationController?.isNavigationBarHidden == false)
                    }, handler: { view, value in
                        guard let showNavBar = value.value as? Bool else {
                            return
                        }
                        (view.next as? UIViewController)?.navigationController?.isNavigationBarHidden = !showNavBar
                    }), view: inspectorViewController.inspectedView)
                    
                    PropertyView(property: InspectorProperty(name: "Left Bar Items", valueType: .array(.barItem, {
                        let button = InterfaceBuilderButton(type: .system)
                        button.tag = Int.random(in: 1...9999)
                        button.interfaceBuilder = inspectorViewController.inspectedView.interfaceBuilder
                        button.model = inspectorViewController.inspectedView.model
                        return .init(value: UIBarButtonItem(customView: button))
                    }), getValue: { view in
                            .init(value: (view.next as? UIViewController)?.navigationItem.leftBarButtonItems)
                    }, handler: { view, value in
                        (view.next as? UIViewController)?.navigationItem.leftBarButtonItems = value.value as? [UIBarButtonItem]
                    }), view: inspectorViewController.inspectedView)
                    
                    PropertyView(property: InspectorProperty(name: "Right Bar Items", valueType: .array(.barItem, {
                        let button = InterfaceBuilderButton(type: .system)
                        button.tag = Int.random(in: 1...9999)
                        button.interfaceBuilder = inspectorViewController.inspectedView.interfaceBuilder
                        button.model = inspectorViewController.inspectedView.model
                        return .init(value: UIBarButtonItem(customView: button))
                    }), getValue: { view in
                            .init(value: (view.next as? UIViewController)?.navigationItem.rightBarButtonItems)
                    }, handler: { view, value in
                        (view.next as? UIViewController)?.navigationItem.rightBarButtonItems = value.value as? [UIBarButtonItem]
                    }), view: inspectorViewController.inspectedView)
                }
                
                if !inspectorViewController.isRoot {
                    ForEach(properties.first!.properties.filter({
                        $0.isChangeable?(inspectorViewController.inspectedView) ?? true
                    })) { property in
                        PropertyView(property: property, view: inspectorViewController.inspectedView)
                    }
                }
                
                ConnectionSettings(view: inspectorViewController.inspectedView, onlyClassName: inspectorViewController.isRoot)
                
                ForEach(properties, id: \.id) { cls in
                    
                    if (cls.id == properties.first?.id && !inspectorViewController.isRoot) || cls.properties.count == 0 {
                        EmptyView()
                    } else {
                        PropertiesView(properties: cls.properties.filter({
                            $0.isChangeable?(inspectorViewController.inspectedView) ?? true
                        }), view: inspectorViewController.inspectedView) {
                            EmptyView()
                        } label: {
                            SwiftUI.Label {
                                Text(prettifyClassName(NSStringFromClass(cls.type))).bold()
                            } icon: {
                                Image(systemName: "squareshape.split.2x2.dotted")
                            }
                        }
                    }
                }
                
                if !inspectorViewController.isRoot {
                    
                    PropertiesView(properties: UIView.frameProperties, view: inspectorViewController.inspectedView) {
                        EmptyView()
                    } label: {
                        SwiftUI.Label {
                            Text("Frame").bold()
                        } icon: {
                            Image(systemName: "arrow.up.left.and.down.right.and.arrow.up.right.and.down.left")
                        }
                    }
                    
                    PropertiesView(properties: UIView.paddingProperties, view: inspectorViewController.inspectedView) {
                        EmptyView()
                    } label: {
                        SwiftUI.Label {
                            Text("Padding").bold()
                        } icon: {
                            Image(systemName: "arrow.up.left.and.down.right.and.arrow.up.right.and.down.left")
                        }
                    }
                }
            } else {
                Text("").onAppear {
                    update = false
                }
            }
        }
            .navigationTitle(prettifyClassName(NSStringFromClass(type(of: inspectorViewController.inspectedView))))
            .font(Font.custom("Menlo", size: 15))
            .onAppear {
                update = true
            }
    }
    
    var body: some View {
        if showTopBar {
            NavigationView {
                content
            }.navigationViewStyle(.stack)
        } else {
            content
        }
    }
}
