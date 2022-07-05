//
//  SnippetsView.swift
//  Pyto
//
//  Created by Emma on 18-06-22.
//  Copyright © 2022 Emma Labbé. All rights reserved.
//

import SwiftUI
import Highlightr

@available(iOS 15.0, *)
struct SnippetsView: View {
    
    struct Snippet: Codable, View {
        
        var name: String
        
        var code: String
        
        var language: String
        
        var id = UUID()
        
        enum CodingKeys: CodingKey {
            case name
            case code
            case language
            case id
        }
        
        init(from decoder: Decoder) throws {
            let container: KeyedDecodingContainer<SnippetsView.Snippet.CodingKeys> = try decoder.container(keyedBy: SnippetsView.Snippet.CodingKeys.self)
            self.name = try container.decode(String.self, forKey: SnippetsView.Snippet.CodingKeys.name)
            self.code = try container.decode(String.self, forKey: SnippetsView.Snippet.CodingKeys.code)
            self.language = try container.decode(String.self, forKey: SnippetsView.Snippet.CodingKeys.language)
            self.id = try container.decode(UUID.self, forKey: SnippetsView.Snippet.CodingKeys.id)
        }
        
        func encode(to encoder: Encoder) throws {
            var container = encoder.container(keyedBy: SnippetsView.Snippet.CodingKeys.self)
            try container.encode(self.name, forKey: SnippetsView.Snippet.CodingKeys.name)
            try container.encode(self.code, forKey: SnippetsView.Snippet.CodingKeys.code)
            try container.encode(self.language, forKey: SnippetsView.Snippet.CodingKeys.language)
            try container.encode(self.id, forKey: SnippetsView.Snippet.CodingKeys.id)
        }
        
        init(name: String, code: String, language: String) {
            self.name = name
            self.code = code
            self.language = language
        }
        
        @Environment(\.colorScheme) var colorScheme
        
        var body: some View {
            VStack(alignment: .leading) {
                Text(name).bold().foregroundColor(.primary)
                HStack {
                    CodeView(code: code, language: language)
                    Spacer()
                }
                .padding()
                .background(Color(colorScheme == .light ? UIColor.secondarySystemBackground : UIColor.systemBackground))
                .cornerRadius(6)
            }
        }
    }
    
    class SnippetsHolder: ObservableObject {
        
        static let shared = SnippetsHolder()
        
        var systemSnippets: [Snippet] {
            [Snippet(name: "Call Entrypoint", code: "if __name__ == \"__main__\":\n\tmain()", language: "python")]
        }
        
        var snippets: [Snippet] {
            get {
                guard let data = UserDefaults.standard.data(forKey: "codeSnippets") else {
                    return []
                }
                
                return (try? JSONDecoder().decode([Snippet].self, from: data)) ?? []
            }
            
            set {
                UserDefaults.standard.set(try? JSONEncoder().encode(newValue), forKey: "codeSnippets")
                objectWillChange.send()
            }
        }
    }
    
    @ObservedObject var snippetsHolder = SnippetsHolder()
    
    var language: String
        
    var selectionHandler: ((String) -> Void)
    
    struct SnippetCreator: View {
        
        @ObservedObject var snippetsHolder: SnippetsHolder
        
        @State var name = ""
                
        @State var textView: UITextView?
        
        var language: String
        
        @Environment(\.dismiss) var dismiss
        
        @Environment(\.colorScheme) var colorScheme
        
        struct Editor: UIViewRepresentable {
            
            var language: String
            
            var theme: Theme
            
            var textView: Binding<UITextView?>
            
            class TextViewDelegate: NSObject, UITextViewDelegate {
                
                func textView(_ textView: UITextView, shouldChangeTextIn range: NSRange, replacementText text: String) -> Bool {
                    return true
                }
            }
            
            func makeUIView(context: Context) -> some UIView {
                let textStorage = CodeAttributedString()
                textStorage.language = language
                
                let textView = EditorTextView(frame: .zero, andTextStorage: textStorage) ?? EditorTextView(frame: .zero)
                textView.smartQuotesType = .no
                textView.smartDashesType = .no
                textView.autocorrectionType = .no
                textView.autocapitalizationType = .none
                textView.spellCheckingType = .no
                
                DispatchQueue.main.async {
                    textView.becomeFirstResponder()
                }
                
                self.textView.wrappedValue = textView
                
                return textView
            }
            
            func updateUIView(_ uiView: UIViewType, context: Context) {
                guard let textView = uiView as? EditorTextView else {
                    return
                }
                
                textView.lineNumberTextColor = theme.sourceCodeTheme.color(for: .plain).withAlphaComponent(0.5)
                textView.lineNumberBackgroundColor = theme.sourceCodeTheme.backgroundColor
                textView.lineNumberFont = EditorViewController.font.withSize(CGFloat(ThemeFontSize))
                textView.lineNumberBorderColor = .clear
                
                let highlightrTheme = HighlightrTheme(themeString: theme.css)
                highlightrTheme.setCodeFont(EditorViewController.font.withSize(CGFloat(ThemeFontSize)))
                highlightrTheme.themeBackgroundColor = theme.sourceCodeTheme.backgroundColor
                highlightrTheme.themeTextColor = theme.sourceCodeTheme.color(for: .plain)
                
                let textStorage = textView.layoutManager.textStorage as? CodeAttributedString
                
                guard textStorage?.highlightr.theme != highlightrTheme else {
                    return
                }
                
                textStorage?.highlightr.theme = highlightrTheme
                textView.textColor = theme.sourceCodeTheme.color(for: .plain)
                textView.backgroundColor = theme.sourceCodeTheme.backgroundColor
            }
        }
        
        var body: some View {
            NavigationView {
                VStack {
                    HStack {
                        Text("Name")
                        TextField("", text: $name)
                            .textFieldStyle(.plain)
                            .multilineTextAlignment(.trailing)
                    }
                    Divider()
                    Editor(language: language, theme: colorScheme == .dark ? XcodeDarkTheme() : XcodeLightTheme(), textView: $textView)
                    Button {
                        let snippet = Snippet(name: name, code: textView?.text ?? "", language: language)
                        snippetsHolder.snippets.insert(snippet, at: 0)
                        dismiss()
                    } label: {
                        Label {
                            Text("Save")
                        } icon: {
                            Image(systemName: "square.and.arrow.down")
                        }.padding(.horizontal, 50).padding(.vertical, 5)
                    }.buttonStyle(.borderedProminent)
                }
                .padding()
                .navigationTitle("New snippet")
                .toolbar {
                    ToolbarItemGroup(placement: .navigationBarTrailing) {
                        Button {
                            dismiss()
                        } label: {
                            Text("Cancel")
                        }
                    }
                }
            }.navigationViewStyle(.stack)
        }
    }
    
    @State var isCreatorPresented = false
    
    @Environment(\.dismiss) var dismiss
    
    var body: some View {
        NavigationView {
            List {
                if snippetsHolder.snippets.filter({ $0.language == language }).count > 0 {
                    Section {
                        ForEach(snippetsHolder.snippets.filter({ $0.language == language }), id: \.name) { snippet in
                            Button {
                                selectionHandler(snippet.code.replacingOccurrences(of: "\t", with: EditorViewController.indentation))
                            } label: {
                                snippet
                            }.contextMenu(menuItems: {
                                Button(role: .destructive) {
                                    if let i = snippetsHolder.snippets.firstIndex(where: { $0.id == snippet.id }) {
                                        snippetsHolder.snippets.remove(at: i)
                                    }
                                } label: {
                                    Label {
                                        Text("Delete")
                                    } icon: {
                                        Image(systemName: "trash")
                                    }
                                }
                            })
                        }.onDelete(perform: {
                            snippetsHolder.snippets.remove(at: $0.first!)
                        })
                    } header: {
                        Text("User")
                    }
                }
                
                if snippetsHolder.systemSnippets.filter({ $0.language == language }).count > 0 {
                    Section {
                        ForEach(snippetsHolder.systemSnippets.filter({ $0.language == language }), id: \.name) { snippet in
                            Button {
                                selectionHandler(snippet.code.replacingOccurrences(of: "\t", with: EditorViewController.indentation))
                            } label: {
                                snippet
                            }
                        }
                    } header: {
                        Text("Default")
                    }
                }
            }.overlay(VStack {
                Spacer()
                HStack {
                    Spacer()
                    ZStack {
                        Circle().fill(Color.accentColor).frame(width: 50, height: 50)
                        Button {
                            isCreatorPresented = true
                        } label: {
                            Image(systemName: "plus").imageScale(.large)
                        }.tint(Color.white)
                    }
                }.padding()
            }).toolbar {
                ToolbarItemGroup(placement: .navigationBarTrailing) {
                    Button {
                        dismiss()
                    } label: {
                        Text("Done").bold()
                    }
                }
            }.sheet(isPresented: $isCreatorPresented) {
                SnippetCreator(snippetsHolder: snippetsHolder, language: language)
            }.navigationTitle("Snippets")
        }.navigationViewStyle(.stack)
    }
}
