//
//  TextViewSearch.swift
//  Pyto
//
//  Created by Emma on 19-11-21.
//  Copyright © 2021 Emma Labbé. All rights reserved.
//

import SwiftUI

@available(iOS 15.0, *)
struct TextViewSearch: View {
    
    struct Line: Identifiable {
        
        var id = UUID()
        
        var lineNumber: Int
        
        var lineRange: NSRange
        
        var searchResults: [SearchResult]
    }
    
    struct SearchResult: Identifiable {
        
        var id = UUID()
        
        var lineNumber: Int
        var lineRange: NSRange
        var foundTextRange: NSRange
        var absoluteTextRange: NSRange
        
        static func lines(from searchResults: [SearchResult]) -> [Line] {
            var lines = [Line]()
            
            for searchResult in searchResults {
                var line: Line
                let index: Int
                
                if let i = lines.firstIndex(where: { $0.lineNumber == searchResult.lineNumber }) {
                    index = i
                    line = lines[i]
                } else {
                    line = Line(lineNumber: searchResult.lineNumber, lineRange: searchResult.lineRange, searchResults: [searchResult])
                    lines.append(line)
                    continue
                }
                
                line.searchResults.append(searchResult)
                lines.remove(at: index)
                lines.insert(line, at: index)
            }
            
            return lines
        }
    }
    
    enum ReplaceMode {
        case replace
        case all
    }
    
    enum SearchMode {
        case find
        case replace
    }
    
    var textView: UITextView
        
    @State var search = ""
    
    @State var searchResults = [SearchResult]()
    
    @State var searchMode = SearchMode.find
    
    @State var replaceText = ""
    
    @State var replaceMode = ReplaceMode.replace
    
    @State var caseSensitive = false
    
    @State var willReplace = false
    
    @Environment(\.dismiss) var dismiss
    
    func searchResultAttributedString(lineRange: NSRange, highlightedRanges: [NSRange]) -> Text {
        
        let text = (textView.attributedText as NSAttributedString).attributedSubstring(from: lineRange)
        
        let attr = NSMutableAttributedString(attributedString: text)
        for highlightedRange in highlightedRanges {
            attr.addAttributes([.backgroundColor : UIColor.systemYellow.withAlphaComponent(0.5)], range: highlightedRange)
        }
        
        if let font = attr.attribute(.font, at: 0, effectiveRange: nil) as? UIFont {
            attr.removeAttribute(.font, range: NSRange(location: 0, length: (attr as NSAttributedString).length))
            attr.addAttributes([.font: font.withSize(UIFont.systemFontSize)], range: NSRange(location: 0, length: (attr as NSAttributedString).length))
        }
        
        guard let swiftUIAttr = try? AttributedString(attr, including: \.uiKit) else {
            return Text("")
        }
        
        return Text(swiftUIAttr)
    }
    
    func updateResults() {
        var results = [SearchResult]()
        
        if !search.isEmpty {
            var i = 1
            
            (textView.text as NSString).enumerateSubstrings(in: NSRange(location: 0, length: (textView.text as NSString).length), options: .byLines) { line, lineRange, _, _ in
                
                guard let line = line else {
                    return
                }
                
                var searchRange = NSRange(location: 0, length: (line as NSString).length)
                var foundRange = NSRange()
                while searchRange.location < (line as NSString).length {
                    searchRange.length = (line as NSString).length - searchRange.location
                    foundRange = (line as NSString).range(of: (caseSensitive ? search : search.lowercased()), options: caseSensitive ? [] : NSString.CompareOptions.caseInsensitive, range: searchRange)
                    if foundRange.location != NSNotFound {
                        searchRange.location = foundRange.location + foundRange.length
                        
                        results.append(SearchResult(lineNumber: i, lineRange: lineRange, foundTextRange: foundRange, absoluteTextRange: foundRange))
                    } else {
                        break
                    }
                }

                i += 1
            }
            
            var j = 0
            
            var searchRange = NSRange(location: 0, length: (textView.text as NSString).length)
            var foundRange = NSRange()
            while searchRange.location < (textView.text as NSString).length {
                searchRange.length = (textView.text as NSString).length - searchRange.location
                foundRange = (textView.text as NSString).range(of: (caseSensitive ? search : search.lowercased()), options: caseSensitive ? [] : NSString.CompareOptions.caseInsensitive, range: searchRange)
                if foundRange.location != NSNotFound {
                    searchRange.location = foundRange.location + foundRange.length
                    
                    var result = results[j]
                    result.absoluteTextRange = foundRange
                    results.remove(at: j)
                    results.insert(result, at: j)
                } else {
                    break
                }
                
                j += 1
            }
        }
        
        searchResults = results
    }
    
    func replace(all: Bool) {
        
        var result = searchResults.first
        while result != nil {
            
            guard let lineRange = result?.lineRange, let range = result?.foundTextRange else {
                continue
            }
            
            let newLine = (((textView.text as NSString).substring(with: lineRange)) as NSString).replacingCharacters(in: range, with: replaceText)
            
            textView.text = (textView.text as NSString).replacingCharacters(in: lineRange, with: newLine)
            updateResults()
            result = searchResults.first
            if !all {
                break
            }
        }
        
        replaceText = ""
    }
    
    var body: some View {
        NavigationView {
            VStack {
                
                HStack {
                    Image(systemName: "magnifyingglass")

                    TextField("Find", text: $search).foregroundColor(.primary)
                }
                .padding(EdgeInsets(top: 8, leading: 6, bottom: 8, trailing: 6))
                .foregroundColor(.secondary)
                .background(Color(.tertiarySystemFill))
                .cornerRadius(10.0)
                .padding(.horizontal)
                
                if searchMode == .replace {
                    HStack {
                        HStack {
                            Image(systemName: "pencil")

                            TextField("Replace by", text: $replaceText).foregroundColor(.primary)
                        }
                        .padding(EdgeInsets(top: 8, leading: 6, bottom: 8, trailing: 6))
                        .foregroundColor(.secondary)
                        .background(Color(.tertiarySystemFill))
                        .cornerRadius(10.0)
                        .padding(.horizontal)
                        
                        Button(action: {
                            willReplace = true
                        }, label: {
                            Text("Replace")
                        }).actionSheet(isPresented: $willReplace, content: {
                                                        
                            ActionSheet(title: Text("Replace"), message: nil, buttons: [
                            
                                ActionSheet.Button.default(Text("First"), action: {
                                    replace(all: false)
                                }),
                                
                                ActionSheet.Button.default(Text("All"), action: {
                                    replace(all: true)
                                }),
                                
                                ActionSheet.Button.cancel()
                            ])
                        }).padding(.trailing)
                    }
                }
                
                List {
                    ForEach(SearchResult.lines(from: searchResults)) { result in
                        Button {
                            let animation = CATransition()
                            animation.duration = 0.25
                            animation.timingFunction = .init(name: .easeInEaseOut)
                            textView.layer.add(animation, forKey: nil)
                            
                            for searchResult in result.searchResults {
                                textView.textStorage.addAttributes([.backgroundColor : UIColor.systemYellow.withAlphaComponent(0.5)], range: searchResult.absoluteTextRange)
                            }
                            
                            DispatchQueue.main.asyncAfter(deadline: .now()+1) {
                                let animation = CATransition()
                                animation.duration = 0.25
                                animation.timingFunction = .init(name: .easeInEaseOut)
                                textView.layer.add(animation, forKey: nil)
                                
                                for searchResult in result.searchResults {
                                    textView.textStorage.removeAttribute(.backgroundColor, range: searchResult.absoluteTextRange)
                                }
                            }
                            
                            dismiss()
                        } label: {
                            Text("\(result.lineNumber) ").font(Font.custom("Menlo", size: UIFont.systemFontSize)).foregroundColor(.secondary) + searchResultAttributedString(lineRange: result.lineRange, highlightedRanges: result.searchResults.map({ $0.foundTextRange }))
                        }
                    }
                }
            }
                .background(Color(UIColor.secondarySystemBackground))
                .textInputAutocapitalization(.never)
                .disableAutocorrection(true)
                .onChange(of: search) { _ in
                    updateResults()
                }.onChange(of: caseSensitive, perform: { _ in
                    updateResults()
                }).toolbar {
                    ToolbarItemGroup(placement: .navigation) {
                        Menu {
                            Picker(selection: $searchMode) {
                                Text("Find").tag(SearchMode.find)
                                Text("Replace").tag(SearchMode.replace)
                            } label: {
                                Image(systemName: "chevron.up.chevron.down")
                            }
                        } label: {
                            HStack {
                                Text(searchMode == .find ? "Find" : "Replace").font(.largeTitle).bold()
                                Image(systemName: "chevron.up.chevron.down")
                            }
                        }
                    }
                    
                    ToolbarItemGroup(placement: .navigationBarTrailing) {
                        if caseSensitive {
                            Button {
                                caseSensitive.toggle()
                            } label: {
                                Image(systemName: "textformat.alt")
                            }.buttonStyle(.borderedProminent)
                        } else {
                            Button {
                                caseSensitive.toggle()
                            } label: {
                                Image(systemName: "textformat.alt")
                            }
                        }
                    }
                }.navigationBarTitleDisplayMode(.inline)
        }.navigationViewStyle(.stack).onAppear {
            updateResults()
        }
    }
}

@available(iOS 15.0, *)
struct TextViewSearch_Previews: PreviewProvider {
    
    static var textView: UITextView {
        let textView = UITextView()
        textView.text = """
        //
        //  TextViewSearch.swift
        //  Example
        //
        //  Created by Emma on 19-11-21.
        //

        import SwiftUI

        struct TextViewSearch: View {
            
            var textView: UITextView
            
            var body: some View {
                Text("Hello, World!")
            }
        }

        struct TextViewSearch_Previews: PreviewProvider {
            
            var textView: UITextView {
                let textView = UITextView()
                textView.text = ""
                return textView
            }
            
            static var previews: some View {
                TextViewSearch(textView: textView)
            }
        }
        """
        textView.font = UIFont(name: "Menlo", size: 17)
        return textView
    }
    
    static var previews: some View {
        TextViewSearch(textView: textView, searchMode: .replace)
    }
}
