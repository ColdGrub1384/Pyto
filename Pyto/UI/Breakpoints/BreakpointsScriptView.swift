import SwiftUI

struct EditorKey: EnvironmentKey {
    static let defaultValue: EditorViewController? = nil
}

extension EnvironmentValues {
    var editor: EditorViewController? {
      get { self[EditorKey.self] }
      set { self[EditorKey.self] = newValue }
    }
}

@available(iOS 15.0, *)
struct BreakpointsScriptView: View {
    
    @State var isExpanded = true
    
    @State var isAddingBreakpoint = false
    
    @Binding var runningBreakpoint: Breakpoint?
    
    var script: URL
    
    var breakpoints: [Breakpoint]
    
    var tracebackJSON: String?
    
    @Binding var id: String?
    
    var update: (Breakpoint, ((inout Breakpoint) -> Void)) -> Void
    
    var removeFile: (URL) -> Void
    
    var removeBreakpoint: (Breakpoint) -> Void
    
    func isRunning(breakpoint: Breakpoint) -> Bool {
        runningBreakpoint != nil &&
        runningBreakpoint!.url?.resolvingSymlinksInPath().path == breakpoint.url?.resolvingSymlinksInPath().path &&
        runningBreakpoint!.lineno == breakpoint.lineno
    }
    
    
    struct BreakpointCell: View {
        
        var breakpoint: Breakpoint
        
        var isRunning: Bool
        
        var showDisclosureIndicator: Bool
        
        var body: some View {
            HStack {
                Image(systemName: "arrowtriangle.right\(breakpoint.isEnabled ? ".fill" : "")").foregroundColor(.accentColor).padding(.trailing)
                Text("\(breakpoint.lineno)").foregroundColor(.secondary)
                Text(breakpoint.line ?? "").foregroundColor(.primary)
                Spacer()
                if isRunning && showDisclosureIndicator {
                    Image(systemName: "chevron.right").foregroundColor(.secondary)
                }
            }.font(.custom("Menlo", size: 16))
        }
    }
    
    @State var isShowingRunningBreakpoint = false
    
    struct StoppedView: View {
        
        var breakpoint: Breakpoint
        
        var scriptURL: URL
        
        var tracebackJSON: String?
        
        @State var areLocalsExpanded = true
        
        @State var areGlobalsExpanded = false
        
        @Binding var id: String?
        
        @State var repl: LocalsAndGlobalsREPLViewController?
        
        @State var isShowingREPL = false
        
        @State var isShowingStackTrace = false
        
        @Environment(\.dismiss) var dismiss
        
        @Environment(\.editor) var editor
        
        var body: some View {
            ZStack {
                
                NavigationLink(isActive: $isShowingREPL) {
                    if repl != nil {
                        LocalsAndGlobalsREPL(repl: repl!)
                    } else {
                        EmptyView()
                    }
                } label: {
                    Text("")
                }.opacity(0)
                
                NavigationLink(isActive: $isShowingStackTrace) {
                    if let data = tracebackJSON?.data(using: .utf8), let traceback = try? JSONDecoder().decode(Traceback.self, from: data), let editor = editor {
                        ExceptionView(traceback: traceback, editor: editor)
                    } else {
                        EmptyView()
                    }
                } label: {
                    Text("")
                }.opacity(0)
                
                Color(UIColor.systemGroupedBackground)
                
                VStack {
                    BreakpointCell(breakpoint: breakpoint, isRunning: true, showDisclosureIndicator: false).padding().background(Color.green.opacity(0.25))

                    
                    HStack {
                        Spacer()
                        
                        Button {
                            dismiss()
                            PyInputHelper.userInput[breakpoint.url!.path] = "c"
                        } label: {
                            VStack {
                                Image(systemName: "forward.end.fill")
                                Text("resume")
                            }.frame(width: 90)
                        }.padding(.trailing, 2)
                        
                        if tracebackJSON != nil {
                            Button {
                                isShowingStackTrace = true
                            } label: {
                                VStack {
                                    Image(systemName: "rectangle.stack.fill")
                                    Text("Stack")
                                }.frame(width: 90)
                            }.padding(.leading, 2)
                        }
                        
                        Button {
                            if repl == nil && id != nil {
                                repl = LocalsAndGlobalsREPLViewController(id: id!, line: breakpoint.line ?? "", url: scriptURL)
                            }
                            
                            isShowingREPL = true
                        } label: {
                            VStack {
                                Image(systemName: "terminal.fill")
                                Text("REPL")
                            }.frame(width: 90)
                        }.padding(.leading, 2)

                        
                        Spacer()
                    }.tint(.green).buttonStyle(.bordered)
                    
                    Divider()
                    
                    List {
                        DisclosureGroup(isExpanded: $areLocalsExpanded) {
                            ObjectView(object: .namespace(id ?? "", .locals))
                        } label: {
                            Text("Locals")
                        }
                        
                        DisclosureGroup(isExpanded: $areGlobalsExpanded) {
                            ObjectView(object: .namespace(id ?? "", .globals))
                        } label: {
                            Text("Globals")
                        }
                    }
                }
            }.navigationTitle("\(breakpoint.url?.lastPathComponent ?? "script"): \(breakpoint.lineno)")
        }
    }
    
    var body: some View {
        DisclosureGroup(isExpanded: $isExpanded) {
            ForEach(breakpoints.sorted(by: { $0.lineno < $1.lineno })) { breakpoint in
                ZStack {
                    
                    if isRunning(breakpoint: breakpoint) {
                        NavigationLink(isActive: $isShowingRunningBreakpoint) {
                            StoppedView(breakpoint: breakpoint, scriptURL: script, tracebackJSON: tracebackJSON, id: $id).navigationBarTitleDisplayMode(.inline)
                        } label: {
                            Text("").opacity(0)
                        }
                    }
                    
                    Button {
                        if !isRunning(breakpoint: breakpoint) {
                            update(breakpoint) {
                                $0.isEnabled.toggle()
                            }
                        }
                    } label: {
                        BreakpointCell(breakpoint: breakpoint, isRunning: isRunning(breakpoint: breakpoint), showDisclosureIndicator: true)
                    }.contextMenu {
                        Button(role: .destructive) {
                            removeBreakpoint(breakpoint)
                        } label: {
                            Label {
                                Text("menuItems.remove")
                            } icon: {
                                Image(systemName: "trash.fill")
                            }
                        }
                    }
                }.listRowBackground(isRunning(breakpoint: breakpoint) ? Color.green.opacity(0.25) : nil)
            }.onDelete { indexSet in
                if let index = indexSet.first {
                    removeBreakpoint(breakpoints[index])
                }
            }
            
            Button { 
                isAddingBreakpoint = true
            } label: { 
                Label { 
                    Text("add").foregroundColor(.primary)
                } icon: { 
                    Image(systemName: "plus")
                }
            }.sheet(isPresented: $isAddingBreakpoint) { 
                NavigationView {
                    ScriptView(fileURL: script) { 
                        isAddingBreakpoint = false
                    }.toolbar {
                        ToolbarItemGroup(placement: .navigationBarLeading) { 
                            Button { 
                                isAddingBreakpoint = false
                            } label: { 
                                Text("cancel")
                            }
                        }
                    }.navigationBarTitleDisplayMode(.inline)
                }.navigationViewStyle(.stack)
            }
        } label: { 
            Label { 
                Text(script.lastPathComponent)
            } icon: { 
                Image(systemName: "doc")
            }.contextMenu { 
                Button(role: .destructive) { 
                    removeFile(script)
                } label: { 
                    Label { 
                        Text("menuItems.remove")
                    } icon: { 
                        Image(systemName: "trash.fill")
                    }
                }
            }
        }
    }
}
