import SwiftUI
import Highlightr

@available(iOS 15.0, *)
struct ScriptView: View {
    
    class _TextView: LineNumberTextView {
        
        var lineno: Binding<Int>?
        
        override func touchesEnded(_ touches: Set<UITouch>, with event: UIEvent?) {
            super.touchesEnded(touches, with: event)
            
            guard let touch = touches.first else {
                return
            }
            
            let location = touch.location(in: self)
            guard let textRange = characterRange(at: location) else {
                return
            }
            
            let _location = offset(from: beginningOfDocument, to: textRange.start)
            let length = offset(from: textRange.start, to: textRange.end)
            let range = NSRange(location: _location, length: length)
            
            var lineno = 1
            (text as NSString).enumerateSubstrings(in: NSRange(location: 0, length: (text as NSString).length), options: .byLines) { _, lineRange, _, stop in
                
                if NSIntersectionRange(lineRange, range).length > 0 {
                    stop.pointee = true
                    return
                }
                
                lineno += 1
            }
            
            self.lineno?.wrappedValue = lineno
        }
    }
    
    struct TextView: UIViewRepresentable {
        
        var text: String
        
        @Binding var textView: UITextView?
        
        @Binding var lineno: Int
        
        typealias UIViewType = UITextView
        
        func makeUIView(context: Context) -> UIViewType {
            let textView = _TextView()
            textView.lineno = $lineno
            textView.isEditable = false
            textView.text = text
            textView.font = UIFont(name: "Menlo", size: 17)
            DispatchQueue.main.async {
                self.textView = textView
            }
            return textView
        }
        
        func updateUIView(_ uiView: UIViewType, context: Context) {            
            let highlightr = Highlightr()
            
            let theme = ConsoleViewController.choosenTheme
            let highlightrTheme = HighlightrTheme(themeString: theme.css)
            highlightrTheme.setCodeFont(EditorViewController.font.withSize(CGFloat(ThemeFontSize)))
            highlightrTheme.themeBackgroundColor = theme.sourceCodeTheme.backgroundColor
            highlightrTheme.themeTextColor = theme.sourceCodeTheme.color(for: .plain)
            
            highlightr.theme = highlightrTheme
            uiView.textColor = theme.sourceCodeTheme.color(for: .plain)
            uiView.backgroundColor = theme.sourceCodeTheme.backgroundColor
            
            let lineNumberText = uiView as? LineNumberTextView
            lineNumberText?.lineNumberTextColor = theme.sourceCodeTheme.color(for: .plain).withAlphaComponent(0.5)
            lineNumberText?.lineNumberBackgroundColor = theme.sourceCodeTheme.backgroundColor
            lineNumberText?.lineNumberFont = EditorViewController.font.withSize(CGFloat(ThemeFontSize))
            lineNumberText?.lineNumberBorderColor = .clear
            
            uiView.attributedText = highlightr.highlight(text, as: "python")
        }
    }
    
    var fileURL: URL
    
    var text: String
    
    init(fileURL: URL, dismiss: @escaping () -> Void) {
        self.fileURL = fileURL
        self.text = (try? String(contentsOf: fileURL)) ?? ""
        self.dismiss = dismiss
    }
    
    @State var lineno: Int = 1
    
    @State var textView: UITextView?
    
    var dismiss: () -> Void
    
    var linenoTextField: some View {
        let formatter = NumberFormatter()
        formatter.numberStyle = .none
        formatter.allowsFloats = false
        formatter.minimum = 1
        formatter.maximum = NSNumber(value: text.components(separatedBy: "\n").count)
        return TextField("number", value: $lineno, formatter: formatter).textFieldStyle(.roundedBorder)
    }
    
    func highlight() {
        guard let textView = textView else {
            print("textView is nil")
            return
        }
        
        let attr = NSMutableAttributedString(attributedString: textView.attributedText)
        let range = NSRange(location: 0, length: attr.length)
        
        attr.removeAttribute(.attachment, range: range)
        
        var i = 1
        (attr.string as NSString).enumerateSubstrings(in: range, options: .byLines) { _, _range, _, _stop in
            
            if i == lineno {
                _stop.pointee = true
                
                let range = NSRange(location: _range.location+_range.length, length: 1)
                let attachment = NSTextAttachment(image: UIImage(systemName: "arrowtriangle.left.fill")!)
                attachment.bounds.size = CGSize(width: 25, height: 17)
                let arrow = NSMutableAttributedString(attachment: attachment)
                arrow.insert(NSAttributedString(string: " "), at: 0)
                attr.insert(arrow, at: range.location)
            }
            
            i += 1
        }
        
        textView.attributedText = attr
    }
    
    @Environment(\.colorScheme) var colorScheme
    
    var body: some View {
        VStack {
            HStack {
                Text("lineNumber").bold()
                Stepper("lineNumber") { 
                    if lineno+1 <= text.components(separatedBy: "\n").count {
                        lineno += 1
                    }
                } onDecrement: { 
                    if lineno-1 > 0 {
                        lineno -= 1
                    }
                } onEditingChanged: { _ in
                    
                }.labelsHidden().padding(.trailing)
                linenoTextField
            }.padding()
            TextView(text: text, textView: $textView, lineno: $lineno).navigationTitle(fileURL.lastPathComponent)
        }.onChange(of: lineno) { _ in
            highlight()
        }.onAppear {
            highlight()
        }.onChange(of: textView, perform: { _ in
            highlight()
        }).toolbar(content: {
            ToolbarItemGroup(placement: .navigationBarTrailing) { 
                Button("add") {
                    do {
                        var breakpoints = BreakpointsStore.breakpoints(for: fileURL)
                        breakpoints.append(try Breakpoint(url: fileURL, lineno: lineno))
                        BreakpointsStore.set(breakpoints: breakpoints, for: fileURL)
                        
                        NotificationCenter.default.post(name: breakpointStoreDidChangeNotification, object: BreakpointsStore.shared)
                        
                        dismiss()
                    } catch {
                        print(error.localizedDescription)
                    }
                }
            }
        })
    }
}
