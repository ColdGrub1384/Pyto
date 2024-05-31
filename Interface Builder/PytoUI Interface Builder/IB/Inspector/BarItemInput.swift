//
//  BarItemInput.swift
//  InterfaceBuilder
//
//  Created by Emma on 27-11-22.
//

import SwiftUI

@available(iOS 16.0, *)
fileprivate struct Inspector: UIViewControllerRepresentable {
    
    var inspectedView: UIView
    
    func makeUIViewController(context: Context) -> some UIViewController {
        InspectorViewController(view: inspectedView, showTopBar: false)
    }
    
    func updateUIViewController(_ uiViewController: UIViewControllerType, context: Context) {
    }
}

@available(iOS 16.0, *)
extension InspectorView.PropertyView {
    
    /// A bar item creator
    struct BarItemInput: View {
        
        /// The property being changed.
        var property: InspectorProperty
        
        /// The view being inspected.
        var view: UIView
        
        private var item: UIBarButtonItem!
        
        /// Initializes the float input with the property being changed and the view.
        init(property: InspectorProperty, view: UIView) {
            self.property = property
            self.view = view
            self.item = property.getValue(view).value! as? UIBarButtonItem
        }
        
        var body: some View {
            if let view = item.customView {
                Inspector(inspectedView: view)
            }
        }
    }

}
