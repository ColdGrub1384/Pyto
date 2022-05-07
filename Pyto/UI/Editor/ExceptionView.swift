//
//  ExceptionView.swift
//  Pyto
//
//  Created by Emma on 16-12-21.
//  Copyright © 2021 Emma Labbé. All rights reserved.
//

import SwiftUI
import Highlightr

struct Traceback: Codable {
    
    struct Frame: Codable, Identifiable {
        var id: Int {
            index
        }
        
        var file_path: String
        var lineno: Int
        var line: String?
        var name: String?
        var index: Int
        var _id: String?
        
        struct FrameView: View {
            
            var frame: Frame
            
            var handler: ((Frame) -> Void)
            
            @Environment(\.colorScheme) var colorScheme
            
            @State var isShowingREPL = false
            
            @State var isShowingContext = false
            
            #if !PREVIEW
            @State var repl: LocalsAndGlobalsREPLViewController?
            #endif
            
            var menu: some View {
                Group {
                    Button {
                        #if !PREVIEW
                        if repl == nil {
                            repl = LocalsAndGlobalsREPLViewController(id: frame._id!, index: frame.index, line: frame.line ?? "", url: URL(fileURLWithPath: frame.file_path))
                        }
                        isShowingREPL = true
                        #endif
                    } label: {
                        Label("REPL", systemImage: "play.fill")
                    }
                    
                    Button {
                        isShowingContext = true
                    } label: {
                        Label("Context", systemImage: "curlybraces")
                    }
                }

            }
            
            @State var areLocalsExpanded = true
            @State var areGlobalsExpanded = false
            
            var body: some View {
                ZStack {
                    NavigationLink(isActive: $isShowingContext) {
                        List {
                            DisclosureGroup(isExpanded: $areLocalsExpanded) {
                                #if !PREVIEW
                                ObjectView(object: .evaluate("console.namespaces['\(frame._id ?? "")'][\(frame.index)]().local"))
                                #else
                                EmptyView()
                                #endif
                            } label: {
                                Text("Locals")
                            }
                            
                            DisclosureGroup(isExpanded: $areGlobalsExpanded) {
                                #if !PREVIEW
                                ObjectView(object: .evaluate("console.namespaces['\(frame._id ?? "")'][\(frame.index)]()._global"))
                                #else
                                EmptyView()
                                #endif
                            } label: {
                                Text("Globals")
                            }
                        }.navigationTitle(Text("Context "))
                    } label: {
                        Text("")
                    }.opacity(0)

                    VStack {
                        HStack {
                            Label {
                                Text(ShortenFilePaths(in: frame.file_path)) + Text(": \(frame.lineno)")
                            } icon: {
                                Image(systemName: "doc")
                            }
                            Spacer()
                        }
                        
                        if frame.name != nil {
                            HStack {
                                Label {
                                    Text(frame.name!).bold()
                                } icon: {
                                    Image(systemName: "function")
                                }
                                Spacer()
                            }
                        }
                        
                        if frame.line != nil && !frame.line!.isEmpty {
                            HStack {
                                Button {
                                    handler(frame)
                                } label: {
                                    HStack {
                                        ZStack {
                                            if colorScheme == .light {
                                                Color(UIColor.systemBackground)
                                            } else {
                                                Color.black.opacity(0.6)
                                            }
                                            CodeView(code: frame.line!).padding()
                                        }
                                        Spacer()
                                    }.padding(.vertical)
                                }
                                
                                ZStack {
                                    NavigationLink(isActive: $isShowingREPL) {
                                        #if !PREVIEW
                                        if repl != nil {
                                            LocalsAndGlobalsREPL(repl: repl!)
                                        } else {
                                            EmptyView()
                                        }
                                        #endif
                                    } label: {
                                        Text("")
                                    }.opacity(0)
                                    
                                    if frame._id != nil {
                                        Menu {
                                            menu
                                        } label: {
                                            Image(systemName: "ellipsis")
                                        }
                                    }
                                }
                            }
                        }
                    }.contextMenu {
                        menu
                    }
                }
            }
        }
    }
    
    var exc_type: String
    var msg: String
    var stack: [Frame]
    var as_text: String
    var name: String?
    var suggestion: String?
    var offset: Int
    var end_offset: Int
}

struct ExceptionView: View {
    
    var traceback: Traceback
    
    #if MAIN
    var editor: EditorViewController
    #endif
    
    static var viewUIFont: UIFont {
        #if MAIN
        EditorViewController.font
        #else
        UIFont(name: "Menlo", size: 17)!
        #endif
    }
    
    static var viewFont: Font {
        #if MAIN
        Font.custom(EditorViewController.font.familyName, size: EditorViewController.font.pointSize)
        #else
        Font.custom("Menlo", size: 17)
        #endif
    
    
    }
    
    @Environment(\.colorScheme) var colorScheme
    
    func fixIt(frame: Traceback.Frame) {
        guard let text = try? (String(contentsOf: URL(fileURLWithPath: frame.file_path))) as NSString else {
            return
        }
        
        let range = NSRange(location: 0, length: text.length)
        
        var lineRange: NSRange?
        
        var i = 1
        text.enumerateSubstrings(in: range, options: .byLines) { _, range, _, `continue` in
            
            if i == frame.lineno {
                lineRange = range
                `continue`.pointee = true
            }
            
            i += 1
        }
        
        guard let lineRange = lineRange else {
            return
        }

        var line = text.substring(with: lineRange) as NSString
        
        if traceback.exc_type == "SyntaxError" {
            let errorRange = NSRange(location: traceback.offset-1, length: traceback.end_offset-traceback.offset)
            
            guard errorRange.location + errorRange.length <= line.length else {
                return
            }
            
            var error = line.substring(with: errorRange)
            error = error.replacingFirstOccurrence(of: " ", with: ", ")
            line = line.replacingCharacters(in: errorRange, with: error) as NSString
        } else if traceback.exc_type == "AttributeError", let name = traceback.name, let suggestion = traceback.suggestion {
            
            var unAllowedChars = CharacterSet.alphanumerics
            #if !PREVIEW
            unAllowedChars.insert("_") // For some reason it doesn't compile when previewing
            #endif
            
            let string = line as String
            var newString = string
            for range in string.allRanges(of: ".\(name)") as [Range<String.Index>] {
                
                func fixIt() {
                    newString = newString.replacingCharacters(in: range, with: ".\(suggestion)")
                }
                
                guard let nextCharRange = string.index(range.upperBound, offsetBy: 0, limitedBy: string.endIndex) else {
                    fixIt()
                    break
                }
                
                guard string.indices.contains(range.upperBound) else {
                    fixIt()
                    continue
                }
                
                guard let nextChar = string[nextCharRange].unicodeScalars.first else {
                    continue
                }
                
                guard !unAllowedChars.contains(nextChar) else {
                    continue
                }
                
                fixIt()
                break
            }
            
            line = newString as NSString
        } else if traceback.exc_type == "NameError", let name = traceback.name, let suggestion = traceback.suggestion {
            
            var unAllowedChars = CharacterSet.alphanumerics
            #if !PREVIEW
            unAllowedChars.insert("_") // For some reason it doesn't compile when previewing
            #endif
            
            let string = line as String
            var newString = string
            for range in string.allRanges(of: name) as [Range<String.Index>] {
                
                func fixIt() {
                    newString = newString.replacingCharacters(in: range, with: suggestion)
                }
                
                var hasUnallowedCharacterAfter: Bool {
                    guard let nextCharRange = string.index(range.upperBound, offsetBy: 0, limitedBy: string.endIndex) else {
                        return false
                    }
                    
                    guard string.indices.contains(range.upperBound) else {
                        return false
                    }
                    
                    guard let nextChar = string[nextCharRange].unicodeScalars.first else {
                        return false
                    }
                    
                    return unAllowedChars.contains(nextChar)
                }
                
                var hasUnallowedCharacterBefore: Bool {
                    guard range.lowerBound > string.startIndex else {
                        return false
                    }
                    
                    guard let prevCharRange = string.index(range.lowerBound, offsetBy: -1, limitedBy: string.endIndex) else {
                        return false
                    }
                    
                    guard string.indices.contains(range.lowerBound) else {
                        return false
                    }
                    
                    guard let prevChar = string[prevCharRange].unicodeScalars.first else {
                        return false
                    }
                    var _unAllowedChars = unAllowedChars
                    #if !PREVIEW
                    _unAllowedChars.insert(".") // For some reason it doesn't compile when previewing
                    #endif
                    return _unAllowedChars.contains(prevChar)
                }
                
                guard !hasUnallowedCharacterAfter && !hasUnallowedCharacterBefore else {
                    continue
                }
                
                fixIt()
                break
            }
            
            line = newString as NSString
        }
        
        #if !PREVIEW
        show(url: URL(fileURLWithPath: frame.file_path)) { editor in
            let text = (editor.textView.text as NSString)
            let range = NSRange(location: 0, length: text.length)
            
            var i = 1
            text.enumerateSubstrings(in: range, options: .byLines) { _, range, _, `continue` in
                
                if i == frame.lineno {
                    let endRange = NSRange(location: range.location+range.length, length: 0)
                    
                    editor.textView.text = (editor.textView.text as NSString).replacingCharacters(in: range, with: line as String)
                    
                    editor.textView.selectedRange = endRange
                    editor.textView.becomeFirstResponder()
                    `continue`.pointee = true
                }
                
                i += 1
            }
        }
        #endif
    }
    
    var shouldInsertComma: Bool {
        traceback.msg.hasSuffix("Perhaps you forgot a comma?")
    }
    
    var message: String {
        return traceback.msg.components(separatedBy: ". Perhaps you forgot a comma?").first ?? traceback.msg
    }
    
    var printTracebackButton: some View {
        Group {
            if #available(iOS 15.0, *) {
                Button {
                    #if MAIN
                    (editor.parent as? EditorSplitViewController)?.console?.print("\n"+ShortenFilePaths(in: traceback.as_text))
                    #endif
                } label: {
                    Text("Print traceback")
                }.tint(Color.green).buttonStyle(BorderedButtonStyle())
            } else {
                Button {
                    #if MAIN
                    (editor.parent as? EditorSplitViewController)?.console?.print("\n"+ShortenFilePaths(in: traceback.as_text))
                    #endif
                } label: {
                    Text("Print traceback")
                }
            }
        }
    }
    
    @Environment(\.horizontalSizeClass) var horizontalSizeClass
    
    #if !PREVIEW
    func show(url: URL, completion: @escaping ((EditorViewController) -> Void)) {
        
        guard let splitVC = editor.parent as? EditorSplitViewController else {
            return
        }
        
        editor.dismiss(animated: true, completion: {
            
            if splitVC.isConsoleShown {
                splitVC.showEditor {
                    self.show(url: url, completion: completion)
                }
                return
            }
            
            if editor.parent is ScriptRunnerViewController {
                editor.dismiss(animated: true, completion: {
                    (editor.view.window?.windowScene?.delegate as? SceneDelegate)?.openDocument(at: url, run: false, folder: nil, isShortcut: false, completion: completion)
                })
            } else {
                (editor.view.window?.windowScene?.delegate as? SceneDelegate)?.openDocument(at: url, run: false, folder: nil, isShortcut: false, completion: completion)
            }
        })
    }
    #endif
    
    var body: some View {
        ZStack {
            if colorScheme == .light {
                Color(UIColor.secondarySystemBackground).ignoresSafeArea()
            }
            
            VStack {
                if !message.isEmpty {
                    HStack {
                        if #available(iOS 15.0, *) {
                            Text(ShortenFilePaths(in: message)).foregroundColor(.red).textSelection(.enabled)
                        } else {
                            Text(ShortenFilePaths(in: message)).foregroundColor(.red)
                        }
                        Spacer()
                    }.padding()
                }
                
                ScrollView {
                    VStack {
                        ForEach(traceback.stack) { frame in
                            
                            VStack {
                                Traceback.Frame.FrameView(frame: frame, handler: { frame in
                                    #if MAIN

                                    guard FileManager.default.fileExists(atPath: frame.file_path) else {
                                        return
                                    }

                                    show(url: URL(fileURLWithPath: frame.file_path)) { editor in
                                        let text = (editor.textView.text as NSString)
                                        let range = NSRange(location: 0, length: text.length)
                                        
                                        var i = 1
                                        text.enumerateSubstrings(in: range, options: .byLines) { _, range, _, `continue` in
                                            
                                            if i == frame.lineno {
                                                let endRange = NSRange(location: range.location+range.length, length: 0)
                                                
                                                editor.textView.selectedRange = endRange
                                                editor.textView.becomeFirstResponder()
                                                `continue`.pointee = true
                                            }
                                            
                                            i += 1
                                        }
                                    }
                                    #endif
                                }).foregroundColor(.primary)
                                
                                if frame.index == 0, traceback.suggestion != nil || shouldInsertComma {
                                    HStack {
                                        if shouldInsertComma {
                                            Text("Perhaps you forgot a comma?").foregroundColor(.red)
                                        } else if let suggestion = traceback.suggestion {
                                            (Text("Did you mean ") + Text(suggestion).bold() + Text("?")).foregroundColor(.red)
                                        }
                                        Spacer()
                                        if #available(iOS 15.0, *) {
                                            Button {
                                                fixIt(frame: frame)
                                            } label: {
                                                Text("Fix it")
                                            }.tint(Color.red).buttonStyle(BorderedButtonStyle())
                                        } else {
                                            Button {
                                                fixIt(frame: frame)
                                            } label: {
                                                Text("Fix it")
                                            }.accentColor(Color.red)
                                        }
                                    }
                                }
                                
                                Divider()
                            }

                        }.padding(.horizontal)
                    }
                }
                
                if traceback.exc_type != "Breakpoint" {
                    HStack {
                        if horizontalSizeClass == .compact {
                            Spacer()
                            printTracebackButton.padding([.horizontal, .bottom])
                        }
                    }
                }
            }
        }.toolbar {
            ToolbarItemGroup(placement: .principal) {
                HStack {
                    Image(systemName: traceback.exc_type == "Breakpoint" ? "arrowtriangle.forward.fill" : "exclamationmark.triangle.fill").font(.title2)
                    Text(traceback.exc_type).bold().font(Font.custom(Self.viewUIFont.familyName, size: UIFont.preferredFont(forTextStyle: .title2).pointSize))
                    Spacer()
                }.foregroundColor(traceback.exc_type == "Breakpoint" ? .green : .red)
            }
            
            ToolbarItemGroup(placement: .navigationBarTrailing) {
                if horizontalSizeClass == .regular && traceback.exc_type != "Breakpoint" {
                    printTracebackButton
                }
            }
        }.font(Self.viewFont).navigationBarTitleDisplayMode(.inline)
    }
}

struct ExceptionView_Previews: PreviewProvider {
    
    static let traceback = try! JSONDecoder().decode(Traceback.self, from: Data(base64Encoded: "ewogImV4Y190eXBlIjogIlplcm9EaXZpc2lvbkVycm9yIiwKICJtc2ciOiAiZGl2aXNpb24gYnkgemVybyIsCiAiYXNfdGV4dCI6ICJUcmFjZWJhY2sgKG1vc3QgcmVjZW50IGNhbGwgbGFzdCk6XG4gIEZpbGUgXCIvcHJpdmF0ZS92YXIvbW9iaWxlL0xpYnJhcnkvTW9iaWxlIERvY3VtZW50cy9pQ2xvdWR+Y2h+bWFyY2VsYX5hZGF+UHl0by9Eb2N1bWVudHMvdGVzdC9leGMucHlcIiwgbGluZSAxMiwgaW4gPG1vZHVsZT5cbiAgICBtYWluKClcbiAgRmlsZSBcIi9wcml2YXRlL3Zhci9tb2JpbGUvTGlicmFyeS9Nb2JpbGUgRG9jdW1lbnRzL2lDbG91ZH5jaH5tYXJjZWxhfmFkYX5QeXRvL0RvY3VtZW50cy90ZXN0L2V4Yy5weVwiLCBsaW5lIDksIGluIG1haW5cbiAgICByZXR1cm4gMC8wXG5aZXJvRGl2aXNpb25FcnJvcjogZGl2aXNpb24gYnkgemVyb1xuIiwKICJzdGFjayI6IFsKICB7CiAgICJmaWxlX3BhdGgiOiAiL3ByaXZhdGUvdmFyL21vYmlsZS9MaWJyYXJ5L01vYmlsZSBEb2N1bWVudHMvaUNsb3VkfmNofm1hcmNlbGF+YWRhflB5dG8vRG9jdW1lbnRzL3Rlc3QvZXhjLnB5IiwKICAgImxpbmVubyI6IDksCiAgICJsaW5lIjogInJldHVybiAwLzAiLAogICAibmFtZSI6ICJtYWluIiwKICAgImluZGV4IjogMAogIH0sCiAgewogICAiZmlsZV9wYXRoIjogIi9wcml2YXRlL3Zhci9tb2JpbGUvTGlicmFyeS9Nb2JpbGUgRG9jdW1lbnRzL2lDbG91ZH5jaH5tYXJjZWxhfmFkYX5QeXRvL0RvY3VtZW50cy90ZXN0L2V4Yy5weSIsCiAgICJsaW5lbm8iOiAxMiwKICAgImxpbmUiOiAibWFpbigpIiwKICAgIm5hbWUiOiAiPG1vZHVsZT4iLAogICAiaW5kZXgiOiAxCiAgfQogXQp9")!)
    
    static var previews: some View {
        #if MAIN
        NavigationView {
            ExceptionView(traceback: traceback, editor: EditorViewController(document: PyDocument(fileURL: URL(fileURLWithPath: "/script.py"))))
        }.navigationViewStyle(.stack)
        #else
        NavigationView {
            ExceptionView(traceback: traceback)
                .preferredColorScheme(.light)
        }.navigationViewStyle(.stack)
        #endif
    }
}
