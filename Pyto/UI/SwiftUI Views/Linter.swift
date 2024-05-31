//
//  Linter.swift
//  Pyto
//
//  Created by Emma on 14-05-22.
//  Copyright © 2022 Emma Labbé. All rights reserved.
//

import SwiftUI

@available(iOS 15.0, *)
struct Linter: View, Identifiable, Hashable {
    
    static func == (lhs: Linter, rhs: Linter) -> Bool {
        lhs.id == rhs.id
    }
    
    struct Warning: Identifiable, Hashable {
        
        static func == (lhs: Warning, rhs: Warning) -> Bool {
            lhs.id == rhs.id
        }
        
        var id = UUID()
        
        func hash(into hasher: inout Hasher) {
            hasher.combine(type)
            hasher.combine(typeDescription)
            hasher.combine(message)
            hasher.combine(lineno)
        }
        
        var type: String
        
        var typeDescription: String
        
        var message: String
        
        var lineno: Int
        
        var url: URL
    }
    
    static func warnings(pylintOutput: String) -> [Warning] {
        var warnings = [Warning]()
        
        // {path}:{line}: {category} ({msg_id}, {symbol}, {obj}) {msg}
        
        for line in pylintOutput.components(separatedBy: "\n") {
            let comp = line.components(separatedBy: ":")
            guard comp.count >= 3 else {
                continue
            }
            
            var path = comp[0]
            if path.hasPrefix(" ") {
                path.removeFirst()
            }
            
            let url = URL(fileURLWithPath: path)
            
            guard let lineNumber = Int(comp[1]) else {
                continue
            }
            
            let error = comp[2]
            
            guard let type = error.components(separatedBy: "(").last?.components(separatedBy: ",").first else {
                continue
            }
            
            guard let typeName = error.components(separatedBy: "(").last?.components(separatedBy: ", ")[1] else {
                continue
            }
            
            guard let message = error.components(separatedBy: ") ").last else {
                continue
            }
            
            warnings.append(Warning(type: type, typeDescription: typeName, message: message, lineno: lineNumber, url: url))
        }
        
        return warnings
    }
    
    var id = UUID()
    
    func hash(into hasher: inout Hasher) {
        hasher.combine(warnings)
        hasher.combine(fileURL)
        hasher.combine(code)
    }
    
    #if !PREVIEW
    var fileBrowser: FileBrowserViewController?
    
    var editor: EditorViewController?
    #endif
    
    var fileURL: URL
    
    var code: String
    
    @State var warnings = [Warning]()
    
    var showCode = true
    
    var language = "python"
    
    var lines: [String] {
        code.components(separatedBy: "\n")
    }
    
    var numberOfWarnings: Int {
        warnings.filter({ !$0.typeDescription.hasSuffix("error") }).count
    }
    
    var numberOfErrors: Int {
        warnings.filter({ $0.typeDescription.hasSuffix("error") }).count
    }
    
    @Environment(\.colorScheme) var colorScheme
    
    func codeView(warning: Warning) -> some View {
        HStack {
            Text("\(warning.lineno)")
                .foregroundColor(.secondary)
            CodeView(code: lines[warning.lineno-1], language: language)
        }
            .padding()
            .background(Color(colorScheme == .light ? UIColor.secondarySystemBackground : UIColor.systemBackground).cornerRadius(6))
            .font(Font.custom("Menlo", size: UIFont.labelFontSize))
            .padding(.top, 5)
    }
    
    var body: some View {
        Group {
            if !showCode, let first = warnings.first {
                codeView(warning: first)
            }
            
            ForEach(warnings, id: \.self) { warning in
                Button {
                    if editor?.view.window != nil {
                        editor?.dismiss(animated: true)
                        
                        var lineRanges = [NSRange]()
                        (editor?.textView.text as? NSString)?.enumerateSubstrings(in: NSRange(location: 0, length: (editor?.textView.text as? NSString)?.length ?? 0), options: [], using: { line, range, _, _ in
                            
                            lineRanges.append(range)
                        })
                        
                        if lineRanges.indices.contains(warning.lineno-1) {
                            editor?.textView.becomeFirstResponder()
                            editor?.textView.selectedRange = lineRanges[warning.lineno-1]
                        }
                    }
                } label: {
                    VStack {
                        HStack {
                            Group {
                                if warning.typeDescription.hasSuffix("error") {
                                    Image(systemName: "xmark.octagon.fill").foregroundColor(.red)
                                } else {
                                    Image(systemName: "exclamationmark.triangle.fill").foregroundColor(.yellow)
                                }
                            }.font(.title3)
                            Text(warning.message).foregroundColor(.primary).fixedSize(horizontal: false, vertical: true)
                            Spacer()
                            VStack {
                                Text(warning.type).foregroundColor(.secondary)
                                Spacer()
                            }
                        }
                        
                        
                        if lines.indices.contains(warning.lineno-1) && showCode {
                            codeView(warning: warning)
                        }
                    }
                }.frame(height: 100)
            }
        }
    }
}

@available(iOS 15.0, *)
struct ProjectLinter: View {
    
    var linters: [Linter]
    
    @Environment(\.dismiss) var dismiss
    
    func errors(linter: Linter) -> AnyView {
        return AnyView(Group {
            if linter.numberOfWarnings > 0 {
                HStack {
                    Image(systemName: "exclamationmark.triangle.fill").foregroundColor(.yellow)
                    Text("\(linter.numberOfWarnings)")
                }
            }
            
            if linter.numberOfErrors > 0 {
                HStack {
                    Image(systemName: "xmark.octagon.fill").foregroundColor(.red)
                    Text("\(linter.numberOfErrors)")
                }
            }
        })
    }
    
    var body: some View {
        NavigationView {
            List {
                
                ForEach(linters) { linter in
                    
                    DisclosureGroup {
                        linter
                    } label: {
                        HStack {
                            Image(uiImage: UIImage(named: "python.SFSymbol")!.withRenderingMode(.alwaysOriginal).withConfiguration(UIImage.SymbolConfiguration(font: UIFont(descriptor: .preferredFontDescriptor(withTextStyle: .title1), size: 20)))).resizable().frame(width: 20, height: 20)
                            Text(linter.fileURL.lastPathComponent)
                            
                            Spacer()
                            
                            errors(linter: linter)
                        }
                    }

                }
                
            }
                .navigationTitle("Linter")
                .toolbar {
                    ToolbarItemGroup(placement: .navigationBarTrailing) {
                        Button {
                            dismiss()
                        } label: {
                            Text("Done").bold()
                        }
                    }
                }
        }.navigationViewStyle(.stack)
    }
}

#if PREVIEW
struct LinterView_Previews: PreviewProvider {
    static var previews: some View {
        if #available(iOS 15.0, *) {
            ProjectLinter(linters:
                [
                    Linter(fileURL: URL(fileURLWithPath: NSTemporaryDirectory()).appendingPathComponent("hello.py"), code:
                        """
                        #!/usr/bin/env python
                        
                        import sys
                        
                        print(sys.stdin)
                        
                        name = input("What's your name? ")
                        print(f"Hello {name}!")
                        
                        """,
                               
                        warnings: [
                            .init(type: "C0305", typeDescription: "trailing-newlines", message: "Trailing newlines", lineno: 9),
                                
                                .init(type: "C0114", typeDescription: "missing-module-docstring", message: "Missing module docstring", lineno: 1)
                        ])
                ]
            )

            ProjectLinter(linters: [
                Linter(fileURL: URL(fileURLWithPath: NSTemporaryDirectory()).appendingPathComponent("hello.py"), code:
                    """
                    #!/usr/bin/env python

                    import sys

                    if Tru:

                    print(sys.stdin)

                    name = input("What's your name? ")
                    print(f"Hello {name}!")
                    
                    """,
                           
                           warnings: [
                            .init(type: "E0001", typeDescription: "syntax-error", message: "expected an indented block after 'if' statement on line 5", lineno: 7),
                           ])
            ])
        } else {
            EmptyView()
        }
    }
}
#endif
