//
//  DefinitionsView.swift
//  SwiftUI Views
//
//  Created by Emma Labbé on 18-06-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import SwiftUI

fileprivate extension Array where Element: Hashable {
    func uniqued() -> [Element] {
        var seen = Set<Element>()
        return filter{ seen.insert($0).inserted }
    }
}

public struct Definition: View, Hashable {
    
    public static func == (lhs: Definition, rhs: Definition) -> Bool {
        lhs.signature == rhs.signature
    }
    
    public func hash(into hasher: inout Hasher) {
        hasher.combine(signature)
    }
    
    private var _signatures: [String]
    
    private var _signature: String
    
    public var signature: String {
        if type == "statement" || type == "module" {
            return _signature
        } else {
            return _signatures.first ?? _signature
        }
    }
    
    public var line: Int
    
    public var docString: String
    
    public var name: String
        
    public var definedNames: [Definition]
    
    public var moduleName: String
    
    public var type: String
    
    @State var isDocStringExpanded = false
    
    @State var text = ""
    
    public init(signature: String, line: Int, docString: String, name: String, signatures: [String], definedNames: [Definition], moduleName: String, type: String) {
        self._signature = signature
        self.line = line
        self.docString = docString
        self.name = name
        self._signatures = signatures
        self.definedNames = definedNames
        self.moduleName = moduleName
        self.type = type
    }
    
    public var body: some View {
        VStack {
            SearchBar(text: $text).padding()
            
            ScrollView {
                VStack {
                    HStack {
                        if #available(iOS 15.0, *) {
                            Text(signature).bold().font(.custom("Courier", size: UIFont.labelFontSize)).textSelection(.enabled)
                        } else {
                            Text(signature).bold().font(.custom("Courier", size: UIFont.labelFontSize))
                        }
                        Spacer()
                    }.padding()
                    
                    if !docString.isEmpty {
                        DisclosureGroup(isExpanded: $isDocStringExpanded) {
                            Text(docString).font(.custom("Courier", size: UIFont.labelFontSize)).disabled(true)
                        } label: {
                            Text("Docstring").bold()
                        }.padding(.horizontal)
                    }
                    
                    ForEach(definedNames.uniqued().filter({ $0.type != "module" }).sorted(by: { $0.signature.lowercased() < $1.signature.lowercased() }).filter({ def in
                        
                        if text != "" {
                            return def.signature.contains(text)
                        } else {
                            return true
                        }
                        
                    }), id: \.signature) { name in
                        NavigationLink(destination: {
                            name.navigationTitle(name.name)
                        }, label: {
                            VStack {
                                HStack {
                                    HighlightedText(name.signature, matching: text).font(.custom("Courier", size: UIFont.labelFontSize))
                                    Spacer()
                                }
                                Divider()
                            }.foregroundColor(.primary)
                        }).padding(.horizontal)
                    }
                }
            }
        }
    }
}

@available(iOS 13.0.0, *)
public class DefinitionsDataSource: ObservableObject {
    
    @Published public var definitions = [Definition]()
}

@available(iOS 13.0.0, *)
struct HighlightedText: View {
    let text: String
    let matching: String

    init(_ text: String, matching: String) {
        self.text = text
        self.matching = matching
    }

    var body: some View {
        let tagged = text.replacingOccurrences(of: self.matching, with: "<SPLIT>>\(self.matching)<SPLIT>")
        let split = tagged.components(separatedBy: "<SPLIT>")
        return split.reduce(Text("")) { (a, b) -> Text in
            guard !b.hasPrefix(">") else {
                return a + Text(b.dropFirst()).foregroundColor(.yellow)
            }
            return a + Text(b)
        }
    }
}

@available(iOS 13.0.0, *)
public struct DefinitionsView: View {
        
    public var handler: ((Definition) -> Void)
    
    public var dismiss: (() -> Void)?
    
    @ObservedObject public var dataSource = DefinitionsDataSource()
    
    @State var text = ""
    
    public init(defintions: [Definition], handler: @escaping ((Definition) -> Void), dismiss: (() -> Void)?) {
        self.handler = handler
        self.dismiss = dismiss
        self.dataSource.definitions = defintions
    }
    
    public var body: some View {
        VStack {
            
            SearchBar(text: $text).padding()
            
            List(dataSource.definitions.filter({ (def) -> Bool in
                if text != "" {
                    return def.signature.contains(text)
                } else {
                    return true
                }
            }), id: \.signature) { item in
                
                NavigationLink {
                    item.navigationBarItems(trailing: Button(action: {
                        self.handler(item)
                    }) {
                        Text("Go")
                    }).navigationTitle(item.name)
                } label: {
                    HStack {
                        HighlightedText(item.signature, matching: self.text)
                            .font(Font.custom("Courier", size: 16)).foregroundColor(.primary)
                        Spacer()
                        Text("\(item.line)")
                            .font(Font.custom("Courier", size: 16))
                            .foregroundColor(.secondary)
                    }
                }
            }.navigationBarItems(trailing:
                Button(action: {
                    self.dismiss?()
                }) {
                    if self.dismiss != nil {
                        Text("done", comment: "Done button").fontWeight(.bold).padding(5)
                    }
                }.hover()
            )
        }.navigationBarTitle(Text("Definitions"))
    }
}

@available(iOS 13.0.0, *)
struct DefinitionsView_Previews: PreviewProvider {
    static var previews: some View {
        DefinitionsView(defintions: [Definition(signature: "def foo", line: 2, docString: "docstring", name: "foo", signatures: [], definedNames: [], moduleName: "", type: "function")], handler: { _ in }, dismiss: {})
    }
}
