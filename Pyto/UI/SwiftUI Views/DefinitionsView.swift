//
//  DefinitionsView.swift
//  SwiftUI Views
//
//  Created by Emma Labbé on 18-06-20.
//  Copyright © 2020 Emma Labbé. All rights reserved.
//

import SwiftUI

public struct Definiton {
    
    public var signature: String
    
    public var line: Int
    
    public init(signature: String, line: Int) {
        self.signature = signature
        self.line = line
    }
}

@available(iOS 13.0.0, *)
public class DefinitionsDataSource: ObservableObject {
    
    @Published public var definitions = [Definiton]()
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
        
    public var handler: ((Definiton) -> Void)
    
    public var dismiss: (() -> Void)?
    
    @ObservedObject public var dataSource = DefinitionsDataSource()
    
    @State var text = ""
    
    public init(defintions: [Definiton], handler: @escaping ((Definiton) -> Void), dismiss: (() -> Void)?) {
        self.handler = handler
        self.dismiss = dismiss
        self.dataSource.definitions = defintions
    }
    
    public var body: some View {
        VStack {
            
            SearchBar(text: $text).padding()
            
            List(dataSource.definitions.filter({ (def) -> Bool in
                if text != "" {
                    return def.signature.lowercased().contains(text)
                } else {
                    return true
                }
            }), id: \.signature) { item in
                Button(action: {
                    self.handler(item)
                }) {
                    HStack {
                        HighlightedText(item.signature, matching: self.text)
                            .font(Font.custom("Courier", size: 16))
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
        }
    }
}

@available(iOS 13.0.0, *)
struct DefinitionsView_Previews: PreviewProvider {
    static var previews: some View {
        DefinitionsView(defintions: [Definiton(signature: "def foo", line: 2)], handler: { _ in }, dismiss: {})
    }
}
