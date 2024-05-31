//
//  IntegerInput.swift
//  PytoUI Interface Builder
//
//  Created by Emma on 30-06-22.
//

import SwiftUI

@available(iOS 16.0, *)
extension InspectorView.PropertyView {
    
    /// An integer input.
    struct IntegerInput: View {
        
        /// The property being changed.
        var property: InspectorProperty
        
        /// The view being inspected.
        var view: UIView
        
        @State private var value = 0
        
        /// Initializes the integer input with the property being changed and the view.
        init(property: InspectorProperty, view: UIView) {
            self.property = property
            self.view = view
        }
        
        var body: some View {
            VStack {
                SwiftUI.TextField("", value: $value, format: .number)
                    .onChange(of: value) { newValue in
                        property.handler(view, .init(value: value))
                    }
                    .onAppear {
                        value = Int((property.getValue(view).value as? Int) ?? 0)
                    }
                    .padding()
                
                SwiftUI.Divider()
                
                SwiftUI.Spacer()
            }
        }
    }
}
