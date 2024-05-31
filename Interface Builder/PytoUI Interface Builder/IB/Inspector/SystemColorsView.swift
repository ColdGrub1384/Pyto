//
//  SystemColorsView.swift
//  PytoUI Interface Builder
//
//  Created by Emma on 30-06-22.
//

import SwiftUI

@available(iOS 16.0, *)
extension InspectorView.PropertyView {
    
    /// A color picker.
    struct SystemColorsView: View {
        
        /// The property being changed.
        var property: InspectorProperty
        
        /// The view being inspected
        var view: UIView
                    
        @State private var selectedColor = Color.clear
        
        private var uiElements: [UIColor] = [
            .label,
            .secondaryLabel,
            .tertiaryLabel,
            .quaternaryLabel,
            .systemFill,
            .secondarySystemFill,
            .tertiarySystemFill,
            .quaternarySystemFill,
            .placeholderText,
            .systemBackground,
            .secondarySystemBackground,
            .tertiarySystemBackground,
            .systemGroupedBackground,
            .secondarySystemGroupedBackground,
            .tertiarySystemGroupedBackground,
            .separator,
            .opaqueSeparator,
            .link,
            .darkText,
            .lightText,
        ]
        
        private var standard: [UIColor] = [
            .systemBlue,
            .systemBrown,
            .systemCyan,
            .systemGreen,
            .systemIndigo,
            .systemMint,
            .systemOrange,
            .systemPink,
            .systemPurple,
            .systemRed,
            .systemTeal,
            .systemYellow,
            .systemGray,
            .systemGray2,
            .systemGray3,
            .systemGray4,
            .systemGray5,
            .systemGray6,
        ]
        
        private func name(color: UIColor) -> String {
            
            if color == .darkText {
                return "Dark Text"
            } else if color == .lightText {
                return "Light Text"
            }
            
            var name = color.description.components(separatedBy: " ").last ?? ""
            if name.hasSuffix(">") {
                name.removeLast()
            }
            let first = String(name.first ?? Character(""))
            name.removeFirst()
            name = first.uppercased()+name
            
            var newName = prettifyClassName(name).replacingOccurrences(of: " Color", with: "")
            if newName == "0" {
                newName = "Clear"
            }
            return newName
        }
        
        private func colors(_ colors: [UIColor]) -> some View {
            ForEach(colors, id: \.self) { color in
                SwiftUI.Button {
                    update = true
                    property.handler(view, .init(value: color))
                } label: {
                    HStack {
                        Text(name(color: color)).foregroundColor(.primary)
                        SwiftUI.Spacer()
                        if color == property.getValue(view).value as? UIColor {
                            Image(systemName: "checkmark").foregroundColor(.accentColor)
                        }
                        Circle()
                            .fill(Color(uiColor: color))
                            .frame(width: 30, height: 30)
                            .overlay(Circle().strokeBorder(Color.primary, lineWidth: 1)).padding(.leading, 5)
                    }
                }
            }
        }
        
        /// Initializes the color picker with the property being changed and the view.
        init(property: InspectorProperty, view: UIView) {
            self.property = property
            self.view = view
        }
        
        @State private var update = false
        
        @State private var updateSelectedColor = true
        
        var body: some View {
            List {
                
                Section {
                    ColorPicker(selection: $selectedColor) {
                        Text("Custom")
                    }
                    colors([UIColor.clear])
                }
                
                if !update {
                    Section {
                        colors(uiElements)
                    } header: {
                        Text("UI Elements")
                    }
                    
                    Section {
                        colors(standard)
                    } header: {
                        Text("Standard")
                    }
                } else {
                    Text("").onAppear {
                        update = false
                    }
                }
            }
                .navigationTitle(property.name)
                .onAppear {
                    if let color = property.getValue(view).value as? UIColor {
                        updateSelectedColor = false
                        selectedColor = Color(color)
                    }
                }.onChange(of: selectedColor) { newValue in
                    if updateSelectedColor {
                        property.handler(view, .init(value: UIColor(newValue)))
                    } else {
                        updateSelectedColor = true
                    }
                }
        }
    }
}
