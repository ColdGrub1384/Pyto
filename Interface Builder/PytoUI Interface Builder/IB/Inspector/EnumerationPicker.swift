//
//  EnumerationPicker.swift
//  PytoUI Interface Builder
//
//  Created by Emma on 30-06-22.
//

import SwiftUI

@available(iOS 16.0, *) 
extension InspectorView.PropertyView {
    
    /// A view for picking a value in an enumeration.
    struct EnumerationPicker: View {
        
        /// The property being changed.
        var property: InspectorProperty
        
        /// The view being inspected.
        var view: UIView
        
        @State private var value: String?
        
        /// Initializes the view with the property being changed and the view.
        init(property: InspectorProperty, view: UIView) {
            self.property = property
            self.view = view
        }
        
        
        private func content(values: [String]) -> some View {
            List {
                ForEach(values, id: \.self) { value in
                    SwiftUI.Button {
                        self.value = value
                    } label: {
                        HStack {
                            Text(value).foregroundColor(.primary)
                            SwiftUI.Spacer()
                            if self.value == value {
                                Image(systemName: "checkmark").foregroundColor(.accentColor)
                            }
                        }
                    }
                }
            }.onAppear {
                value = property.getValue(view).value as? String
            }.onChange(of: value) { newValue in
                property.handler(view, .init(value: newValue ?? "Unknown"))
            }.navigationTitle(property.name)
        }
        
        var body: some View {
            if case let .enumeration(values) = property.valueType {
                content(values: values)
            } else if case let .dynamicEnumeration(values) = property.valueType {
                content(values: values.handler(view))
            } else {
                EmptyView()
            }
        }
    }

}
