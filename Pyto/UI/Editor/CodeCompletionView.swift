//
//  CodeCompletionView.swift
//  Pyto
//
//  Created by Emma on 19-04-22.
//  Copyright © 2022 Emma Labbé. All rights reserved.
//

import SwiftUI

fileprivate extension UIFont {
    func boldFont() -> UIFont? {
        guard let boldDescriptor = fontDescriptor.withSymbolicTraits(.traitBold) else {
            return nil
        }

        return UIFont(descriptor: boldDescriptor, size: pointSize)
    }
}

struct CompletionCell: View {
    
    var suggestion: String
    
    var isSelected: Bool
    
    @ObservedObject var manager: CodeCompletionManager
    
    var index: Int
    
    var type: String {
        if let type = manager.types[suggestion]?.first {
            return String(type).uppercased()
        } else {
            return "?"
        }
    }
    
    var suggestionText: Text {
        
        guard #available(iOS 15.0, *), let currentWord = manager.currentWord else {
            return Text(suggestion)
        }
        
        let attr = NSMutableAttributedString(string: suggestion)
        
        let font = EditorViewController.font.withSize(UIFont.systemFontSize)
        attr.addAttributes([.font: font, .foregroundColor: UIColor.secondaryLabel], range: NSRange(location: 0, length: (attr as NSAttributedString).length))
        
        (attr.string as NSString).enumerateSubstrings(in: NSRange(location: 0, length: attr.length), options: .byComposedCharacterSequences) { char, range, _, _ in
            
            guard let char = char else {
                return
            }
            
            if currentWord.lowercased().contains(char.lowercased()) {
                attr.addAttributes([.font: (font.boldFont() ?? font), .foregroundColor: UIColor.label], range: range)
            }
        }
        
        guard let swiftUIAttr = try? AttributedString(attr, including: \.uiKit) else {
            return Text("")
        }
        
        return Text(swiftUIAttr)
    }
    
    var body: some View {
        VStack(alignment: .leading) {
            HStack {
                Button {
                    manager.selectedIndex = index
                } label: {
                    HStack {
                        (Text(type+" ").foregroundColor(.secondary) + suggestionText).lineLimit(1).padding(.horizontal, 10)
                        Spacer()
                    }
                }.padding(isSelected ? [] : [.vertical], 5)
                if isSelected {
                    VStack {
                        Spacer()
                        Button {
                            manager.didSelectSuggestion?(index)
                        } label: {
                            Image(systemName: "arrow.turn.down.left").foregroundColor(.white)
                        }.padding(5).background(RoundedRectangle(cornerRadius: 4).fill(Color.accentColor)).padding(.trailing)
                    }
                }
            }
            Divider().opacity(0) // Fixes alignment
        }.background(manager.selectedIndex == index ? Color.accentColor.opacity(0.4) : Color.clear)
    }
}

class CodeCompletionManager: ObservableObject {
    
    struct Name: Codable, Equatable, Hashable {
        var module_name: String
        var module_path: String
        var line: Int
        
        func hash(into hasher: inout Hasher) {
            hasher.combine(module_name)
            hasher.combine(module_path)
            hasher.combine(line)
        }
    }
    
    weak var editor: EditorViewController?
    
    @Published var selectedIndex = 0 {
        didSet {
            objectWillChange.send()
        }
    }
    
    @Published var completions = [String]() {
        didSet {
            objectWillChange.send()
        }
    }
    
    @Published var suggestions = [String]() {
        didSet {
            objectWillChange.send()
        }
    }
    
    @Published var isDocStringExpanded = false {
        didSet {
            objectWillChange.send()
        }
    }
    
    @Published var currentWord: String? {
        didSet {
            objectWillChange.send()
        }
    }
    
    @Published var docStrings = [String: String]() {
        didSet {
            objectWillChange.send()
        }
    }
    
    @Published var definition: Name?
    
    var types = [String: String]()
    
    @Published var signatures = [String: String]() {
        didSet {
            objectWillChange.send()
        }
    }
    
    var didSelectSuggestion: ((Int) -> ())?
    
    func getDocstring(suggestion: String) {
        DispatchQueue.global().async {
            guard let result = Python.pythonShared?.perform(#selector(PythonRuntime.getString(_:)), with: """
            from _codecompletion import completion_objects
            
            docstring = None
            for completion in completion_objects:
                if completion.name == '\(suggestion.replacingOccurrences(of: "'", with: "\\'"))':
                    docstring = completion.docstring(raw=True, fast=False)
                    break
            
            if docstring is None or docstring == '':
                docstring = 'No docstring'
            
            s = docstring
            """)?.takeUnretainedValue() as? String else {
                return
            }
            
            DispatchQueue.main.async {
                self.docStrings[suggestion] = result
            }
        }
    }
    
    func getSignature(suggestion: String) {
        DispatchQueue.global().async {
            guard let result = Python.pythonShared?.perform(#selector(PythonRuntime.getString(_:)), with: """
            from _codecompletion import completion_objects
            
            signature = None
            for completion in completion_objects:
                if completion.name == '\(suggestion.replacingOccurrences(of: "'", with: "\\'"))':
                    for _signature in completion.get_signatures():
                        if _signature.to_string() == "NoneType()":
                            continue

                        signature = _signature.to_string()
                        break
            
            if signature is None or signature == '':
                signature = '\(suggestion.replacingOccurrences(of: "'", with: "\\'"))'
            
            s = signature
            """)?.takeUnretainedValue() as? String else {
                return
            }
            DispatchQueue.main.async {
                self.signatures[suggestion] = result
            }
        }
    }
    
    func getDefinition(suggestion: String) {
        DispatchQueue.global().async {
            guard let result = (Python.pythonShared?.perform(#selector(PythonRuntime.getString(_:)), with: """
            from _codecompletion import completion_objects
            import json
            
            file = {}
            for completion in completion_objects:
                if completion.name == '\(suggestion.replacingOccurrences(of: "'", with: "\\'"))':
                    goto = completion.goto()
                    for name in goto:
                        file = {
                            "module_name": name.module_name,
                            "module_path": str(name.module_path),
                            "line": name.line
                        }
                        break
            
            s = json.dumps(file)
            """)?.takeUnretainedValue() as? String)?.data(using: .utf8) else {
                return
            }
            
            guard let definition = try? JSONDecoder().decode(Name.self, from: result) else {
                return
            }
                        
            DispatchQueue.main.async {
                self.definition = definition
            }
        }
    }
}

struct CompletionsView: View {
    @ObservedObject var manager: CodeCompletionManager
    
    @State var docstring: String?
    
    @State var signature: String?
    
    func updateHelp() {
        guard manager.suggestions.indices.contains(manager.selectedIndex) else {
            return
        }
        
        if manager.docStrings[manager.suggestions[manager.selectedIndex]] == nil || manager.docStrings[manager.suggestions[manager.selectedIndex]] == "" {
            manager.getDocstring(suggestion: manager.suggestions[manager.selectedIndex])
        } else {
            docstring = manager.docStrings[manager.suggestions[manager.selectedIndex]]
        }
        
        if manager.signatures[manager.suggestions[manager.selectedIndex]] == nil || manager.signatures[manager.suggestions[manager.selectedIndex]] == "" {
            manager.getSignature(suggestion: manager.suggestions[manager.selectedIndex])
        } else {
            signature = manager.signatures[manager.suggestions[manager.selectedIndex]]
        }
        
        manager.getDefinition(suggestion: manager.suggestions[manager.selectedIndex])
    }
    
    var body: some View {
        VStack(spacing: 0) {
            ScrollViewReader { proxy in
                ScrollView {
                    if manager.completions != [""] && !manager.isDocStringExpanded {
                        if manager.completions.indices.contains(manager.selectedIndex) && manager.suggestions.indices.contains(manager.selectedIndex) {
                            ForEach(0..<manager.suggestions.count, id: \.self) { i in
                                CompletionCell(suggestion: manager.suggestions[i], isSelected: (i == manager.selectedIndex) && !(manager.completions[manager.selectedIndex].isEmpty), manager: manager, index: i)
                            }
                        }
                    }
                }
                    .frame(height: (manager.completions != [""] && !manager.isDocStringExpanded && manager.completions.indices.contains(manager.selectedIndex) && manager.suggestions.indices.contains(manager.selectedIndex)) ? nil : 1)
                    .onChange(of: manager.selectedIndex, perform: { _ in
                        while manager.selectedIndex >= manager.suggestions.count {
                            manager.selectedIndex -= 1
                        }
                        
                        if manager.selectedIndex < 0 {
                            manager.selectedIndex = 0
                        }
                        
                        updateHelp()
                        
                        proxy.scrollTo(manager.selectedIndex)
                    })
                    .onChange(of: manager.suggestions, perform: { _ in
                        updateHelp()
                    })
                    .onChange(of: manager.docStrings, perform: { newValue in
                        guard manager.suggestions.indices.contains(manager.selectedIndex) else {
                            return
                        }
                        
                        let newDocString = newValue[manager.suggestions[manager.selectedIndex]]
                        
                        guard newDocString?.isEmpty == false else {
                            return
                        }
                        
                        docstring = newDocString
                    })
                    .onChange(of: manager.signatures, perform: { newValue in
                        guard manager.suggestions.indices.contains(manager.selectedIndex) else {
                            return
                        }
                        
                        let newSignature = newValue[manager.suggestions[manager.selectedIndex]]
                        
                        guard newSignature?.isEmpty == false else {
                            return
                        }
                        
                        signature = newValue[manager.suggestions[manager.selectedIndex]]
                    })
                    .frame(height: (manager.completions == [""] || manager.isDocStringExpanded) ? 0 : nil)
            }
            if manager.suggestions.indices.contains(manager.selectedIndex) {
                ZStack {
                    Color(.secondarySystemBackground)
                    VStack {
                        HStack {
                            CodeView(code: signature ?? manager.suggestions[manager.selectedIndex], fontSize: 13)
                                .lineLimit(3)
                                .fixedSize(horizontal: false, vertical: true)
                            Spacer()
                            if manager.completions != [""] {
                                Button {
                                    withAnimation {
                                        manager.isDocStringExpanded.toggle()
                                    }
                                } label: {
                                    Image(systemName: "chevron.\(manager.isDocStringExpanded ? "down" : "up")")
                                }
                            }
                        }.padding(.bottom, 5)
                        HStack {
                            Group {
                                if manager.completions == [""] || manager.isDocStringExpanded {
                                    VStack {
                                        if let def = manager.definition {
                                            HStack {
                                                Button {
                                                    let sidebar = (manager.editor?.splitViewController as? SidebarSplitViewController)?.sidebar
                                                    
                                                    let url = URL(fileURLWithPath: def.module_path)
                                                    if url != manager.editor?.document?.fileURL {
                                                        sidebar?.open(url: url)
                                                    }
                                                    
                                                    DispatchQueue.main.asyncAfter(deadline: .now()+0.25) {
                                                        let editor = (sidebar?.editor?.vc as? EditorSplitViewController)?.editor
                                                        
                                                        let text = (editor?.textView.text ?? "") as NSString
                                                        var line = 1
                                                        var lineRange: NSRange?
                                                        text.enumerateSubstrings(in: NSRange(location: 0, length: text.length), options: .byLines) { _, range, _, stop in
                                                            
                                                            if line == def.line {
                                                                stop.pointee = true
                                                                lineRange = range
                                                            }
                                                            
                                                            line += 1
                                                        }
                                                        
                                                        if let lineRange = lineRange, let textView = editor?.textView {
                                                            let rect = textView.layoutManager.boundingRect(forGlyphRange: lineRange, in: textView.textContainer)
                                                            let topTextInset = textView.textContainerInset.top
                                                            let contentOffset = CGPoint(x: 0, y: topTextInset + rect.origin.y)

                                                            textView.setContentOffset(contentOffset, animated: true)
                                                            
                                                            textView.selectedRange = lineRange
                                                        }
                                                    }
                                                } label: {
                                                    Text(String(def.module_name+":\(def.line)")).underline().foregroundColor(.primary)
                                                }
                                                Spacer()
                                            }
                                        }
                                        ScrollView {
                                            HStack {
                                                if let docstring = docstring {
                                                    Text(docstring)
                                                } else {
                                                    Text("No docstring")
                                                }
                                                Spacer()
                                            }
                                        }
                                    }
                                } else {
                                    if let docstring = docstring?.components(separatedBy: "\n").first, !docstring.isEmpty {
                                        Text(docstring).lineLimit(1)
                                    } else {
                                        Text("No docstring")
                                    }
                                }
                                Spacer()
                            }.foregroundColor(.secondary).font(.system(.body))
                        }
                    }.padding()
                }
                .frame(height: (manager.completions == [""] || manager.isDocStringExpanded) ? nil : 80)
                    .transition(.move(edge: .bottom))
            }
        }
            .frame(width: 500, height: 230, alignment: .top)
            .fixedSize()
            .cornerRadius(6)
            .overlay(
                RoundedRectangle(cornerRadius: 6)
                    .stroke(Color.secondary, lineWidth: 0.5)
            )
            .font(.custom("Menlo", size: 14))
            .background(Color(.systemBackground))
    }
}
