//
//  TextInput.swift
//  PytoUI Interface Builder
//
//  Created by Emma on 30-06-22.
//

import SwiftUI

@available(iOS 16.0, *)
extension InspectorView.PropertyView {
    
    /// A text input
    struct TextInput: View {
        
        /// The property being changed.
        var property: InspectorProperty
        
        /// The view being inspected.
        var view: UIView
        
        @State private var text = ""
        
        /// Initializes the text input with the property being changed and the view.
        init(property: InspectorProperty, view: UIView) {
            self.property = property
            self.view = view
        }
        
        var body: some View {
            TextEditor(text: $text)
                .autocorrectionDisabled()
                .textInputAutocapitalization(.never)
                .onAppear {
                    text = (property.getValue(view).value as? String) ?? ""
                }
                .onChange(of: text) { newValue in
                    property.handler(view, .init(value: newValue))
                }
        }
    }
}
