//
//  ArrayInput.swift
//  InterfaceBuilder
//
//  Created by Emma on 03-09-22.
//

import SwiftUI

@available(iOS 16.0, *)
extension InspectorView.PropertyView {
    
    /// An array input
    struct ArrayInput: View {
        
        /// The property being changed.
        var property: InspectorProperty
        
        /// The view being inspected.
        var view: UIView
        
        private var array: [Any?] {
            (property.getValue(view).value as? Array) ?? []
        }
        
        private func delete(at indexSet: IndexSet) {
            var array = self.array
            array.remove(atOffsets: indexSet)
            property.handler(view, .init(value: array))
            updateProperties()
        }
        
        private func addNew() {
            if case .array(_, let value) = property.valueType {
                var array = (property.getValue(view).value as? [Any?]) ?? []
                array.append(value().value)
                property.handler(view, InspectorProperty.Value(value: array))
            }
            updateProperties()
        }
        
        @State private var properties = [InspectorProperty]()
        
        private func updateProperties() {
            
            guard case .array(let type, _) = property.valueType else {
                return
            }
            
            var properties = [InspectorProperty]()
            
            var i = 0
            for _ in array {
                let index = i
                properties.append(InspectorProperty(name: "\(i)", valueType: type, getValue: { view in
                    guard array.indices.contains(index) else {
                        return .init(value: nil)
                    }
                    
                    return .init(value: array[index])
                }, handler: { view, value in
                    guard array.indices.contains(index) else {
                        return
                    }
                    
                    var newArray = array
                    newArray.remove(at: index)
                    newArray.insert(value.value, at: index)
                    property.handler(view, .init(value: newArray))
                }))
                
                i += 1
            }
            
            self.properties = properties
        }
        
        /// Initializes the text input with the property being changed and the view.
        init(property: InspectorProperty, view: UIView) {
            self.property = property
            self.view = view
        }
        
        var body: some View {
            List {
                ForEach(properties) { property in
                    InspectorView.PropertyView(property: property, view: view)
                }.onDelete { indexSet in
                    delete(at: indexSet)
                }
                
                SwiftUI.Button {
                    addNew()
                } label: {
                    SwiftUI.Label {
                        Text("Add").foregroundColor(.primary)
                    } icon: {
                        Image(systemName: "plus.circle.fill").symbolRenderingMode(.multicolor)
                    }
                }
            }.toolbar {
                ToolbarItemGroup(placement: .navigationBarTrailing) {
                    EditButton()
                }
            }.onAppear {
                updateProperties()
            }
        }
    }
}

