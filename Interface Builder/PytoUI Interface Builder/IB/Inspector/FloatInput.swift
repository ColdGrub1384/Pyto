//
//  FloatInput.swift
//  PytoUI Interface Builder
//
//  Created by Emma on 30-06-22.
//

import SwiftUI

@available(iOS 16.0, *) 
extension InspectorView.PropertyView {
    
    /// A float input.
    struct FloatInput: View {
        
        /// The property being changed.
        var property: InspectorProperty
        
        /// The view being inspected.
        var view: UIView
        
        @State private var value: Double = 0
        
        /// Initializes the float input with the property being changed and the view.
        init(property: InspectorProperty, view: UIView) {
            self.property = property
            self.view = view
        }
        
        var body: some View {
            VStack {
                SwiftUI.TextField("", value: $value, format: .number)
                    .onChange(of: value) { newValue in
                        property.handler(view, .init(value: CGFloat(value)))
                    }
                    .onAppear {
                        value = Double((property.getValue(view).value as? CGFloat) ?? 0)
                    }
                    .padding()
                
                SwiftUI.Divider()
                
                SwiftUI.Spacer()
            }
        }
    }

}
