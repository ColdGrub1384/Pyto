import SwiftUI

@available(iOS 15.0, *)
struct BreakpointsScriptView: View {
    
    @State var isExpanded = true
    
    @State var isAddingBreakpoint = false
    
    @Binding var runningBreakpoint: Breakpoint?
    
    var script: URL
    
    var breakpoints: [Breakpoint]
    
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
        
        @State var areLocalsExpanded = true
        
        @State var areGlobalsExpanded = false
        
        @Binding var id: String?
        
        @State var repl: LocalsAndGlobalsREPLViewController?
        
        @State var isShowingREPL = false
        
        @Environment(\.dismiss) var dismiss
        
        struct LocalsAndGlobalsREPL: UIViewControllerRepresentable {
            
            var repl: LocalsAndGlobalsREPLViewController
            
            func makeUIViewController(context: Context) -> some UIViewController {
                repl
            }
            
            func updateUIViewController(_ uiViewController: UIViewControllerType, context: Context) {
            }
        }
        
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
                                Text("Resume")
                            }.frame(width: 70)
                        }.padding(.trailing, 2)
                        
                        Button {
                            if repl == nil && id != nil {
                                repl = LocalsAndGlobalsREPLViewController(id: id!, line: breakpoint.line ?? "", url: scriptURL)
                            }
                            
                            isShowingREPL = true
                        } label: {
                            VStack {
                                Image(systemName: "terminal.fill")
                                Text("REPL")
                            }.frame(width: 70)
                        }.padding(.leading, 2)

                        
                        Spacer()
                    }.tint(.green).buttonStyle(.bordered)
                    
                    Divider()
                    
                    List {
                        DisclosureGroup(isExpanded: $areLocalsExpanded) {
                            EmptyView()
                        } label: {
                            Text("Locals")
                        }
                        
                        DisclosureGroup(isExpanded: $areGlobalsExpanded) {
                            EmptyView()
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
            ForEach(breakpoints) { breakpoint in
                ZStack {
                    
                    if isRunning(breakpoint: breakpoint) {
                        NavigationLink(isActive: $isShowingRunningBreakpoint) {
                            StoppedView(breakpoint: breakpoint, scriptURL: script, id: $id).navigationBarTitleDisplayMode(.inline)
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
                                Text("Delete")
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
                    Text("Add").foregroundColor(.primary)
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
                                Text("Cancel")
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
                        Text("Delete")
                    } icon: { 
                        Image(systemName: "trash.fill")
                    }
                }
            }
        }
    }
}
