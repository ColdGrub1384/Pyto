import SwiftUI

let exampleScript = Bundle.main.url(forResource: "Script", withExtension: "py")!

let exampleBreakpoints = [
    try! Breakpoint(url: exampleScript, lineno: 7),
    try! Breakpoint(url: exampleScript, lineno: 4)
]

let breakpointStoreDidChangeNotification = Notification.Name("breakpointStoreDidChangeNotification")

@available(iOS 15.0, *)
struct BreakpointsView: View {
    
    @State var breakpoints = [Breakpoint]()
    
    @State var runningBreakpoint: Breakpoint?
    
    var fileURL: URL
    
    @State var id: String?
    
    var files: [URL] {
        var all = [URL]()
        for breakpoint in breakpoints {
            guard let url = breakpoint.url else {
                continue
            }
            
            guard !all.map({ $0.resolvingSymlinksInPath().path }).contains(url.resolvingSymlinksInPath().path) else {
                continue
            }
            
            all.append(url)
        }
        
        if all.count == 0 {
            return [fileURL]
        }
        
        return all
    }
    
    func breakpoints(script: URL) -> [Breakpoint] {
        breakpoints.filter({ $0.url != nil && $0.url!.resolvingSymlinksInPath().path == script.resolvingSymlinksInPath().path }).sorted(by: { $0.lineno < $1.lineno })
    }
    
    func update(breakpoint: Breakpoint, handler: ((inout Breakpoint) -> Void)) {
        var _breakpoint = breakpoint
        handler(&_breakpoint)
        if let i = breakpoints.firstIndex(where: { $0.id == breakpoint.id }) {
            var newBreakpoints = breakpoints
            newBreakpoints.remove(at: i)
            newBreakpoints.insert(_breakpoint, at: i)
            breakpoints = newBreakpoints
        }
    }
    
    func remove(breakpoint: Breakpoint) {
        if let i = breakpoints.firstIndex(where: { $0.id == breakpoint.id }) {
            breakpoints.remove(at: i)
        }
    }
    
    func remove(file: URL) {
        for breakpoint in breakpoints {
            if breakpoint.url == file {
                remove(breakpoint: breakpoint)
            }
        }
    }
    
    @State var isPresentingAddSheet = false
    
    @Environment(\.dismiss) var dismiss
    
    @State var isRunning = false
    
    @State var tracebackJSON: String?
    
    var run: () -> ()
    
    init(fileURL: URL, id: String?, run: @escaping () -> (), runningBreakpoint: Breakpoint?, tracebackJSON: String?) {
        self.fileURL = fileURL
        self._id = .init(initialValue: id)
        self.run = run
        self._tracebackJSON = .init(initialValue: tracebackJSON)
        self._runningBreakpoint = .init(initialValue: runningBreakpoint)
    }
    
    var body: some View {
        NavigationView {
            List {
                ForEach(files, id: \.path) { script in
                    BreakpointsScriptView(runningBreakpoint: $runningBreakpoint, script: script, breakpoints: breakpoints(script: script), tracebackJSON: tracebackJSON, id: $id, update: update, removeFile: {
                        remove(file: $0)
                    }, removeBreakpoint: {
                        remove(breakpoint: $0)
                    })
                }
            }.navigationTitle("Breakpoints").toolbar {
                ToolbarItemGroup(placement: .navigationBarLeading) {
                    Button {
                        dismiss()
                    } label: {
                        Text("Cancel")
                    }
                }
                
                ToolbarItemGroup(placement: .navigationBarTrailing) {
                    Button {
                        isPresentingAddSheet = true
                    } label: {
                        Image(systemName: "plus")
                    }
                    
                    if runningBreakpoint == nil {
                        Button {
                            run()
                        } label: {
                            Image(systemName: "play.fill")
                        }.disabled(isRunning)
                    } else {
                        Button {
                            PyInputHelper.userInput[runningBreakpoint!.url!.path] = "c"
                        } label: {
                            Image(systemName: "forward.end.fill")
                        }
                    }
                }
            }.onReceive(NotificationCenter.Publisher(center: .default, name: EditorViewController.didTriggerBreakpointNotificationName, object: nil)) { notif in
                runningBreakpoint = notif.object as? Breakpoint
                
                if let id = notif.userInfo?["id"] as? String, !id.isEmpty {
                    self.id = id
                }
                
                if let json = notif.userInfo?["traceback"] as? String, !json.isEmpty {
                    self.tracebackJSON = json
                }
            }
        }.navigationViewStyle(.stack).onAppear { 
            breakpoints = BreakpointsStore.breakpoints(for: fileURL)
        }.onChange(of: breakpoints) { _ in
            BreakpointsStore.set(breakpoints: breakpoints, for: fileURL)
        }.sheet(isPresented: $isPresentingAddSheet) { 
            BreakpointCreator(fileURL: fileURL, files: files)
        }.onReceive(NotificationCenter.Publisher(center: .default, name: breakpointStoreDidChangeNotification, object: nil)) { notif in
            breakpoints = BreakpointsStore.breakpoints(for: fileURL)
        }.onAppear {
            isRunning = Python.shared.isScriptRunning(fileURL.path)
        }.onReceive(NotificationCenter.Publisher(center: .default, name: EditorViewController.didUpdateBarItemsNotificationName, object: nil)) { notif in
            isRunning = Python.shared.isScriptRunning(fileURL.path)
        }
    }
}
