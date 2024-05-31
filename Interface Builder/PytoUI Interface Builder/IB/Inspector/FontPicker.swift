//
//  FontPicker.swift
//  PytoUI Interface Builder
//
//  Created by Emma on 30-06-22.
//

import SwiftUI

fileprivate func name(for textStyle: UIFont.TextStyle) -> String {
    
    var name = textStyle.rawValue.replacingOccurrences(of: "UICTFontTextStyle", with: "")
    if name == "Title0" {
        name = "Large Title"
    }
    
    if name.hasSuffix("RegularUsage") {
        name = "System"
    }
    
    if name.hasSuffix("EmphasizedUsage") {
        name = "System Bold"
    }
    
    if name.hasSuffix("ObliqueUsage") {
        name = "System Italic"
    }
    
    return name
}

fileprivate struct CustomFontPicker: UIViewControllerRepresentable {

    class Coordinator: NSObject, UIFontPickerViewControllerDelegate {
        
        var parent: CustomFontPicker
        
        private let onFontPick: (UIFontDescriptor) -> Void
        
        init(_ parent: CustomFontPicker, onFontPick: @escaping (UIFontDescriptor) -> Void) {
            self.onFontPick = onFontPick
            self.parent = parent
        }
        
        func fontPickerViewControllerDidPickFont(_ viewController: UIFontPickerViewController) {
            guard let descriptor = viewController.selectedFontDescriptor else { return }
            onFontPick(descriptor)
            parent.presentationMode.wrappedValue.dismiss()
        }
    }
    
    @Environment(\.presentationMode) var presentationMode
    private let onFontPick: (UIFontDescriptor) -> Void
    
    init(onFontPick: @escaping (UIFontDescriptor) -> Void) {
        self.onFontPick = onFontPick
    }
    
    func makeUIViewController(context: Context) -> UIFontPickerViewController {
        let configuration = UIFontPickerViewController.Configuration()
        configuration.includeFaces = true
        configuration.displayUsingSystemFont = false
        let vc = UIFontPickerViewController(configuration: configuration)
        vc.delegate = context.coordinator
        return vc
    }
    
    func updateUIViewController(_ uiViewController: UIFontPickerViewController, context: UIViewControllerRepresentableContext<CustomFontPicker>) {
    }
    
    func makeCoordinator() -> Coordinator {
        Coordinator(self, onFontPick: self.onFontPick)
    }
}

@available(iOS 16.0, *)
extension InspectorView.PropertyView {
    
    /// A font picker-
    struct FontPicker: View {
        
        @State private var font = UIFont.systemFont(ofSize: UIFont.systemFontSize)
        
        /// The property being changed.
        var property: InspectorProperty
        
        /// The view being inspected.
        var view: UIView
        
        /// Initializes the font picker with the property being changed and the view.
        init(property: InspectorProperty, view: UIView) {
            self.property = property
            self.view = view
        }
        
        let styles = ["CTFontUltraLightUsage", "CTFontThinUsage", "CTFontLightUsage", "CTFontRegularUsage", "CTFontMediumUsage", "CTFontDemiUsage", "CTFontEmphasizedUsage", "CTFontHeavyUsage", "CTFontBlackUsage"]
        
        private struct TextStylePicker: View {
            
            var property: InspectorProperty
            
            var view: UIView
            
            var textStyles: [UIFont.TextStyle] {
                [
                    .body,
                    .callout,
                    .caption1,
                    .caption2,
                    .footnote,
                    .headline,
                    .largeTitle,
                    .subheadline,
                    .title1,
                    .title2,
                    .title3,
                ]
            }
            
            @State var textStyle: UIFont.TextStyle?
            
            @State var isFontPickerPresented = false
            
            func styleButton(textStyle: String, font: UIFont, name: String) -> some View {
                SwiftUI.Button {
                    self.textStyle = UIFont.TextStyle(rawValue: textStyle)
                    property.handler(view, .init(value: font))
                } label: {
                    HStack {
                        Text(name).foregroundColor(.primary)
                        SwiftUI.Spacer()
                        if self.textStyle?.rawValue.hasSuffix(textStyle.replacingOccurrences(of: "CTFont", with: "")) == true {
                            Image(systemName: "checkmark").foregroundColor(.accentColor)
                        }
                    }
                }
            }
            
            var body: some View {
                List {
                    
                    Section {
                        SwiftUI.Button {
                            isFontPickerPresented = true
                        } label: {
                            HStack {
                                Text("Custom").foregroundColor(.primary)
                                SwiftUI.Spacer()
                                Image(systemName: "chevron.forward").foregroundColor(.secondary)
                            }
                        }
                    }.sheet(isPresented: $isFontPickerPresented) {
                        CustomFontPicker { descriptor in
                            textStyle = nil
                            property.handler(view, .init(value: UIFont(descriptor: descriptor, size: 17)))
                        }
                    }
                    
                    Section {
                        
                        styleButton(textStyle: "CTFontUltraLightUsage", font: UIFont.systemFont(ofSize: 17, weight: .ultraLight), name: "System Ultra Light")
                        
                        styleButton(textStyle: "CTFontThinUsage", font: UIFont.systemFont(ofSize: 17, weight: .thin), name: "System Thin")
                        
                        styleButton(textStyle: "CTFontLightUsage", font: UIFont.systemFont(ofSize: 17, weight: .light), name: "System Light")
                        
                        styleButton(textStyle: "CTFontRegularUsage", font: UIFont.systemFont(ofSize: 17), name: "System")
                        
                        styleButton(textStyle: "CTFontMediumUsage", font: UIFont.systemFont(ofSize: 17, weight: .medium), name: "System Medium")
                        
                        styleButton(textStyle: "CTFontDemiUsage", font: UIFont.systemFont(ofSize: 17, weight: .semibold), name: "System Semibold")
                        
                        styleButton(textStyle: "CTFontEmphasizedUsage", font: UIFont.boldSystemFont(ofSize: 17), name: "System Bold")
                        
                        styleButton(textStyle: "CTFontHeavyUsage", font: UIFont.systemFont(ofSize: 17, weight: .heavy), name: "System Heavy")
                        
                        styleButton(textStyle: "CTFontBlackUsage", font: UIFont.systemFont(ofSize: 17, weight: .black), name: "System Black")
                    }
                    
                    Section {
                        ForEach(textStyles, id: \.rawValue) { textStyle in
                            SwiftUI.Button {
                                self.textStyle = textStyle
                                property.handler(view, .init(value: UIFont(descriptor: .preferredFontDescriptor(withTextStyle: textStyle), size: UIFontDescriptor.preferredFontDescriptor(withTextStyle: textStyle).pointSize)))
                            } label: {
                                HStack {
                                    Text(name(for: textStyle)).foregroundColor(.primary)
                                    SwiftUI.Spacer()
                                    if self.textStyle == textStyle {
                                        Image(systemName: "checkmark").foregroundColor(.accentColor)
                                    }
                                }
                            }
                        }
                    } header: {
                        Text("Text styles")
                    }
                }.onAppear {
                    textStyle = (property.getValue(view).value as? UIFont)?.fontDescriptor.object(forKey: UIFontDescriptor.AttributeName.textStyle) as? UIFont.TextStyle
                }.navigationTitle("Font")
            }
        }
        
        private var textStyle: UIFont.TextStyle? {
            font.fontDescriptor.object(forKey: UIFontDescriptor.AttributeName.textStyle) as? UIFont.TextStyle
        }
        
        var body: some View {
            List {
                
                NavigationLink {
                    TextStylePicker(property: property, view: view)
                } label: {
                    HStack {
                        Text("Font")
                        SwiftUI.Spacer()
                        if let style = textStyle {
                            Text(name(for: style)).foregroundColor(.secondary)
                        } else {
                            Text(font.fontName).foregroundColor(.secondary)
                        }
                    }
                }
                
                if textStyle == nil || styles.contains(textStyle!.rawValue) {
                    HStack {
                        Text("Size")
                        SwiftUI.Spacer()
                        Text("\(Int(font.pointSize))px").foregroundColor(.secondary)
                        SwiftUI.Stepper("") {
                            font = font.withSize(font.pointSize+1)
                        } onDecrement: {
                            font = font.withSize(font.pointSize-1)
                        }.frame(width: 80)
                    }
                }
            }.onAppear {
                if let font = property.getValue(view).value as? UIFont {
                    self.font = font
                }
            }.onChange(of: font) { newValue in
                property.handler(view, .init(value: newValue))
            }.navigationTitle(property.name)
        }
    }
}
