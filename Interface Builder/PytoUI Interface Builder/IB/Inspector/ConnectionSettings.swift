//
//  ConnectionSettings.swift
//  InterfaceBuilder
//
//  Created by Emma on 13-07-22.
//

import SwiftUI

fileprivate func removingSpecialCharsFromString(text: String) -> String {
    let okayChars : Set<Character> =
        Set("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLKMNOPQRSTUVWXYZ1234567890_")
    return String(text.filter {okayChars.contains($0) })
}

@available(iOS 16.0, *)
struct ConnectionSettings: View {
    
    var view: UIView
        
    @State var name = ""
    
    @State var customClassName = ""
    
    @State var isExpanded = true
    
    var onlyClassName  = false
    
    var connections: [String] {
        let viewType = type(of: view)
        let sel = NSSelectorFromString("\(NSStringFromClass(viewType).components(separatedBy: ".").last ?? "")_connections")
        guard viewType.responds(to: sel) else {
            return []
        }
        
        guard let connections = viewType.perform(sel).takeUnretainedValue() as? [String] else {
            return []
        }
        
        return connections
    }
    
    struct CustomConnectionInput: View {
        
        var view: UIView
        
        var connection: String
        
        @State var name = ""
        
        var connectionDisplayName: String {
            if !(view is UIButton) && connection == "action" {
                return "Did Change Value"
            } else {
                return connection.replacingOccurrences(of: "_", with: " ").localizedCapitalized
            }
        }
        
        var signature: String {
            let sel = NSSelectorFromString("\(NSStringFromClass(type(of: view)).components(separatedBy: ".").last ?? "")_customConnectionsSignatures")
            
            let `default` = "sender: ui.\(PytoUIClassName(from: type(of: view)))"
            
            guard type(of: view).responds(to: sel) else {
                return `default`
            }
            
            guard let result = type(of: view).perform(sel)?.takeUnretainedValue() as? [String:String] else {
                return `default`
            }
            
            return result[connection] ?? `default`
        }
        
        var body: some View {
            
            NavigationLink {
                VStack {
                    
                    SwiftUI.TextField("", text: $name)
                        .autocorrectionDisabled()
                        .textInputAutocapitalization(.never)
                    
                    SwiftUI.Divider()
                    
                    if !name.isEmpty {
                        HStack {
                            AnyView(HighlightedCode!("@ui.ib_action\ndef \(name)(\(signature)): pass"))
                            SwiftUI.Spacer()
                            SwiftUI.Button {
                                UIPasteboard.general.string = "@ui.ib_action\ndef \(name)(\(signature)): pass"
                            } label: {
                                Image(systemName: "doc.on.clipboard")
                            }
                        }
                        
                        SwiftUI.Divider()
                        
                        HStack {
                            AnyView(HighlightedCode!("@ui.ib_action\ndef \(name)(self, \(signature)): pass"))
                            SwiftUI.Spacer()
                            SwiftUI.Button {
                                UIPasteboard.general.string = "@ui.ib_action\ndef \(name)(self, \(signature)): pass"
                            } label: {
                                Image(systemName: "doc.on.clipboard")
                            }
                        }
                    }
                    
                    SwiftUI.Spacer()
                }
                    .padding()
                    .navigationTitle(connectionDisplayName)
                    .onChange(of: name) { newValue in
                        
                        guard removingSpecialCharsFromString(text: newValue) == newValue else {
                            name = removingSpecialCharsFromString(text: newValue)
                            return
                        }
                        
                        guard let ib = view.interfaceBuilder else {
                            return
                        }
                        
                        if ib.model.connections[view.tag] == nil {
                            ib.model.connections[view.tag] = []
                        }
                        
                        if let i = ib.model.connections[view.tag]?.firstIndex(where: {
                            $0.attributeName == connection
                        }) {
                            ib.model.connections[view.tag]?.remove(at: i)
                        }
                        
                        ib.model.connections[view.tag]?.append(.init(attributeName: connection, functionName: name))
                    }
            } label: {
                HStack {
                    Text(connectionDisplayName)
                    SwiftUI.Spacer()
                    Text(name).foregroundColor(.secondary)
                }
            }.onAppear {
                if let connection = view.interfaceBuilder?.model.connections[view.tag]?.first(where: {
                    $0.attributeName == connection
                }) {
                    name = connection.functionName
                }
            }
        }
    }
    
    func code(_ code: String) -> some View {
        HStack {
            AnyView(HighlightedCode!(code))
            SwiftUI.Spacer()
            SwiftUI.Button {
                UIPasteboard.general.string = code
            } label: {
                Image(systemName: "doc.on.clipboard")
            }
        }
    }
    
    var body: some View {
        DisclosureGroup(isExpanded: $isExpanded, content: {
            
            if !onlyClassName {
                NavigationLink {
                    VStack {
                        
                        SwiftUI.TextField("", text: $name)
                            .autocorrectionDisabled()
                            .textInputAutocapitalization(.never)
                        
                        SwiftUI.Divider()
                        
                        if !name.isEmpty {
                            VStack(alignment: .leading) {
                                
                                Text("Object property")
                                    .font(.headline)
                                    .bold()
                                    .padding(.vertical)
                                                                
                                AnyView(HighlightedCode!("class MyView(ui.View):\n\n"))
                                HStack(spacing: 0) {
                                    Text("    ")
                                    code("\(name): \(customClassName.isEmpty ? "ui.\(PytoUIClassName(from: type(of: view)))" : customClassName)")
                                }
                                
                                SwiftUI.Divider()
                                
                                Text("Global namespace")
                                    .font(.headline)
                                    .bold()
                                    .padding(.vertical)
                                
                                code("\(name): \(customClassName.isEmpty ? "ui.\(PytoUIClassName(from: type(of: view)))" : customClassName) = ui.ib_ref()")
                                
                                SwiftUI.Divider()
                                
                                Text("Subscript")
                                    .font(.headline)
                                    .bold()
                                    .padding(.vertical)
                                
                                AnyView(HighlightedCode!("my_view[\"\(name)\"]"))
                                
                            }.font(.custom("Menlo", size: UIFont.systemFontSize))
                        }
                        
                        SwiftUI.Spacer()
                    }.padding().navigationTitle("Name")
                } label: {
                    HStack {
                        Text("Name")
                        SwiftUI.Spacer()
                        Text(name).foregroundColor(.secondary)
                    }
                }
            }
            
            NavigationLink {
                VStack {
                    
                    VStack {
                        SwiftUI.TextField("pyto_ui.\(PytoUIClassName(from: type(of: view)))", text: $customClassName)
                            .autocorrectionDisabled()
                            .textInputAutocapitalization(.never)
                        
                        SwiftUI.Divider()
                    }.padding()
                    
                    Text("The class must exist in the global namespace (MyClass) or you can specify the name of a module (my_module.MyClass).")
                        .foregroundColor(.secondary)
                        .padding(.horizontal, 10)
                    
                    SwiftUI.Spacer()
                }.navigationTitle("Class name")
            } label: {
                HStack {
                    Text("Class name")
                    SwiftUI.Spacer()
                    Text(customClassName).foregroundColor(.secondary)
                }
            }
            
            ForEach(connections, id: \.self) { connection in
                CustomConnectionInput(view: view, connection: connection)
            }
        }, label: {
            SwiftUI.Label {
                Text("Connections")
            } icon: {
                Image(systemName: "ellipsis.curlybraces")
            }
        }).onAppear {
            name = view.interfaceBuilder?.model.names.name(for: view.tag) ?? ""
            customClassName = view.interfaceBuilder?.model.names.customClassName(for: view.tag) ?? ""
        }.onChange(of: name) { newValue in
            
            guard removingSpecialCharsFromString(text: newValue) == newValue else {
                name = removingSpecialCharsFromString(text: newValue)
                return
            }
            
            view.interfaceBuilder?.model.names.set(name: newValue, for: view.tag)
        }.onChange(of: customClassName) { newValue in
            view.interfaceBuilder?.model.names.set(customClassName: customClassName, for: view.tag)
        }
    }
}
