//
//  PyPiView.swift
//  SwiftUI Views
//
//  Created by Emma Labbé on 13-06-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import Foundation
import SwiftUI
import Combine

let DidRunPipNotificationName = Notification.Name("DidRunPipNotification")

let DidPressInstallWheelButtonNotificationName = Notification.Name(rawValue: "DidPressInstallWheelButtonNotification")

func search(for package: String) -> [String] {
    let index = Bundle.main.url(forResource: "pypi_index", withExtension: "html") ?? FileManager.default.urls(for: .libraryDirectory, in: .userDomainMask)[0].appendingPathComponent("pypi_index.html")
    
    guard FileManager.default.fileExists(atPath: index.path) else {
        #if MAIN
        AppDelegate.shared.updatePyPiCache()
        #endif
        return []
    }
    
    do {
        let content = try String(contentsOf: index)
        let lines = content.components(separatedBy: "\n")
        
        var packages = [String]()
        for line in lines {
            if line.contains("/simple/"), let name = line.slice(from: "/\">", to: "<"), name.lowercased().contains(package.lowercased()) {
                packages.append(name)
            }
        }
        
        var packagesWithSearchedTextAsPrefix = [String]()
        
        var firstResult: String?
        
        var i = 0
        for _package in packages {
            if _package.lowercased().hasPrefix(package.lowercased()) {
                if _package.lowercased() == package.lowercased() {
                    firstResult = _package
                } else {
                    packagesWithSearchedTextAsPrefix.append(_package)
                }
                
                packages.remove(at: i)
            } else {
                i += 1
            }
        }
        
        packagesWithSearchedTextAsPrefix.sort()
        packages.sort()
        
        if let first = firstResult {
            packagesWithSearchedTextAsPrefix.insert(first, at: 0)
        }
        
        return [String]((packagesWithSearchedTextAsPrefix+packages).prefix(200))
    } catch {
        return []
    }
}

func isPackageInstalled(_ package: String) -> Bool {
    let index = FileManager.default.urls(for: .documentDirectory, in: .allDomainsMask)[0].appendingPathComponent("site-packages/.pypi_packages")
    if let str = (try? String(contentsOf: index)) {
        for line in str.components(separatedBy: .newlines) {
            if line.hasPrefix("["), let packageName = line.slice(from: "[", to: "]"), package.lowercased() == packageName.lowercased() {
                return true
            }
        }
    }
    return false
}

@available(iOS 13.0, *)
struct ActivityIndicator: UIViewRepresentable {

    @Binding var isAnimating: Bool
    let style: UIActivityIndicatorView.Style

    func makeUIView(context: UIViewRepresentableContext<ActivityIndicator>) -> UIActivityIndicatorView {
        return UIActivityIndicatorView(style: style)
    }

    func updateUIView(_ uiView: UIActivityIndicatorView, context: UIViewRepresentableContext<ActivityIndicator>) {
        isAnimating ? uiView.startAnimating() : uiView.stopAnimating()
    }
}

@available(iOS 13.0, *)
class PyPiIndex: ObservableObject {
         
    @Published var packages: [String] = []
    
    @Published var searchString = "" {
        didSet {
            let search = searchString
            DispatchQueue.main.asyncAfter(deadline: .now()+0.5) {
                if search == self.searchString {
                    self.fetch(self.searchString)
                }
            }
        }
    }
    
    @Published var isLoading = false
    
    func fetch(_ searchString: String) {
        isLoading = true
        DispatchQueue.global().async { [weak self] in
            let packages = search(for: searchString)
            DispatchQueue.main.async {
                if self?.searchString == searchString {
                    self?.packages = packages
                }
                self?.isLoading = false
            }
        }
    }
}

struct PipShow: View {
    
    var package: String
    
    @State var info: String?
    
    var didSelectPackage: ((String, Bool, Bool) -> Void)
    
    var body: some View {
        Group {
            if info == nil {
                Text("")
            } else {
                VStack {
                    HStack {
                        if #available(iOS 15.0, *) {
                            Text(info!).font(.custom("Menlo", size: UIFont.systemFontSize)).textSelection(.enabled)
                        } else {
                            Text(info!).font(.custom("Menlo", size: UIFont.systemFontSize))
                        }
                        Spacer()
                    }.padding(.bottom)
                    
                    if Python.shared.fullVersionExclusives.contains(package) && isLiteVersion.boolValue {
                        Button {
                            UIApplication.shared.open(URL(string: "pyto://upgrade")!)
                        } label: {
                            Text("pypi.unlock \(ProcessInfo.processInfo.environment["UPGRADE_PRICE"] ?? "3.99$")", comment: "Unlock a full version exclusive package. Replace %@ by the price")
                        }
                    } else {
                        HStack {
                            if #available(iOS 15.0, *) {
                                Button(role: .destructive) {
                                    didSelectPackage("\(package)", false, true)
                                } label: {
                                    Label {
                                        Text("pypi.uninstall", comment: "Uninstall a package")
                                    } icon: {
                                        Image(systemName: "trash").foregroundColor(PipViewController.bundled.contains(package) ? .secondary : .red)
                                    }
                                }.buttonStyle(.bordered).disabled(PipViewController.bundled.contains(package))
                            } else {
                                Button {
                                    didSelectPackage("\(package)", false, true)
                                } label: {
                                    Label {
                                        Text("pypi.uninstall", comment: "Uninstall a package")
                                    } icon: {
                                        Image(systemName: "trash").foregroundColor(PipViewController.bundled.contains(package) ? .secondary : .red)
                                    }
                                }.accentColor(.red).disabled(PipViewController.bundled.contains(package))
                            }
                            Spacer()
                        }
                    }
                }
            }
        }.onAppear {
            #if !PREVIEW
            info = ShortenFilePaths(in: runPip(arguments: ["show", package]))
            #endif
        }
    }
}

@available(iOS 13.0.0, *)
public struct PyPiView: View {
        
    @ObservedObject var index = PyPiIndex()
    
    @ObservedObject var updatesManager = PyPiUpdatesManager()
    
    @State var isPickingWheel = false
    
    @State var updating = [String]()
    
    public var didSelectPackage: ((String, Bool, Bool) -> Void)
    
    public var hostingController: UIViewController?
    
    public init(hostingController: UIViewController?, didSelectPackage: @escaping ((String, Bool, Bool) -> Void)) {
        self.didSelectPackage = didSelectPackage
        self.hostingController = hostingController
    }
    
    @State var installedPackages = [(name: String, version: String)]()
    
    func getInstalledPackages() -> [(name: String, version: String)]  {
        #if !PREVIEW
        let installed = runPip(arguments: ["list", "--format", "json"])
        
        if let packages = try? JSONSerialization.jsonObject(with: installed.data(using: .utf8) ?? Data()) as? [[String:String]] {
            var list = [(name: String, version: String)]()
            for package in packages {
                if let name = package["name"], let version = package["version"] {
                    list.append((name: name, version: version))
                }
            }
            return list
        } else {
            return []
        }
        #else
        []
        #endif
    }
    
    public var body: some View {
        VStack {
            SearchBar(text: $index.searchString)
            if index.isLoading {
                Spacer()
                ActivityIndicator(isAnimating: .constant(true), style: .medium)
                Spacer()
            } else if !index.searchString.isEmpty {
                List(index.packages, id: \.self, rowContent: { item in
                    Button(action: {
                        self.didSelectPackage(item, false, false)
                    }, label: {
                        HStack {
                            if item.lowercased() == self.index.searchString.lowercased() {
                                Text(item).fontWeight(.bold).foregroundColor(.primary)
                            } else {
                                Text(item).foregroundColor(.primary)
                            }
                            
                            Spacer()
                            
                            Image(systemName: "chevron.right").foregroundColor(.secondary)
                        }
                        .contextMenu {
                            Button(action: {
                                UIApplication.shared.open(URL(string: "https://pypi.org/project/\(item)")!, options: [:], completionHandler: nil)
                            }) {
                                Text("pypi.viewOnPyPi", comment: "A button on the context menu to show the package on PyPi")
                                Image(systemName: "globe")
                            }
                            
                            if isPackageInstalled(item) {
                                Button(action: {
                                    self.didSelectPackage(item, false, true)
                                }) {
                                    Text("menuItems.remove", comment: "The 'Remove' menu item")
                                    Image(systemName: "trash.fill")
                                }.accentColor(.red)
                            } else {
                                Button(action: {
                                    self.didSelectPackage(item, true, false)
                                }) {
                                    Text("install", comment: "Install")
                                    Image(systemName: "square.and.arrow.down.fill")
                                }
                            }
                            
                            Button(action: {
                                self.didSelectPackage(item, false, false)
                            }) {
                                Text("pypi.moreInfo", comment: "A button on the context menu to show more info")
                                Image(systemName: "ellipsis")
                            }
                        }
                    })
                })
            } else {
                if installedPackages.isEmpty {
                    VStack {
                        Spacer()
                        HStack {
                            Spacer()
                            ProgressView().progressViewStyle(.circular)
                            Spacer()
                        }
                        Spacer()
                    }
                } else {
                    List {
                        
                        if !updatesManager.updatablePackages.isEmpty {
                            Section {
                                DisclosureGroup {
                                    Button {
                                        let pkgs = updatesManager.updatablePackages.map({ $0.name })
                                        updating = pkgs
                                        didSelectPackage("\(pkgs.joined(separator: " ")) --upgrade", true, false)
                                    } label: {
                                        Text("pypi.updateAll", comment: "Update all")
                                    }
                                    
                                    ForEach(updatesManager.updatablePackages, id: \.name) { pkg in
                                        HStack {
                                            VStack(alignment: .leading) {
                                                Text(pkg.name)
                                                Text(pkg.version).font(.footnote).foregroundColor(.secondary)
                                            }
                                            Spacer()
                                            Button {
                                                updating = [pkg.name]
                                                didSelectPackage("\(pkg.name) --upgrade", true, false)
                                            } label: {
                                                Text("pypi.update", comment: "Update")
                                            }
                                        }
                                    }
                                } label: {
                                    HStack {
                                        Text("pypi.updates", comment: "Updatable packages")
                                        ZStack {
                                            Circle().fill(.red).frame(width: 25, height: 25)
                                            Text("\(updatesManager.updatablePackages.count)").foregroundColor(.white).font(.system(size: 15))
                                        }
                                    }
                                }
                            }
                        }
                        
                        Section {
                            ForEach(installedPackages.filter({ !PipViewController.bundled.contains($0.name) }), id: \.name) { pkg in
                                DisclosureGroup {
                                    PipShow(package: pkg.name, didSelectPackage: didSelectPackage)
                                } label: {
                                    VStack {
                                        HStack {
                                            Text(pkg.name).foregroundColor(.primary)
                                            Spacer()
                                            Text(pkg.version).foregroundColor(.secondary)
                                        }
                                    }
                                }
                            }
                        } header: {
                            Text("pypi.installed", comment: "Installed packages")
                        }
                        
                        Section {
                            ForEach(installedPackages.filter({ PipViewController.bundled.contains($0.name) }), id: \.name) { pkg in
                                DisclosureGroup {
                                    PipShow(package: pkg.name, didSelectPackage: didSelectPackage)
                                } label: {
                                    VStack {
                                        HStack {
                                            if Python.shared.fullVersionExclusives.contains(pkg.name) {
                                                Image(systemName: "lock\(isLiteVersion.boolValue ? "" : ".open").fill").foregroundColor(isLiteVersion.boolValue ? .red : .green)
                                            }
                                            Text(pkg.name).foregroundColor(.primary)
                                            Spacer()
                                            Text(pkg.version).foregroundColor(.secondary)
                                        }
                                        if Python.shared.fullVersionExclusives.contains(pkg.name) {
                                            HStack {
                                                Text("pypi.fullversion", comment: "The subtitle of a package that is full version exclusive").foregroundColor(.secondary)
                                                Spacer()
                                            }
                                        }
                                    }
                                }
                            }
                        } header: {
                            Text("pypi.bundled", comment: "Bundled packages")
                        }
                    }
                }
            }
        }
        .navigationBarTitle("PyPI").fileImporter(isPresented: $isPickingWheel, allowedContentTypes: [.init(exportedAs: "ch.ada.pyto.wheel")]) { result in
            if case .success(let url) = result {
                _ = url.startAccessingSecurityScopedResource()
                didSelectPackage(url.path, true, false)
            }
        }.onAppear {
            DispatchQueue.global().async {
                let packages = getInstalledPackages()
                DispatchQueue.main.async {
                    self.installedPackages = packages
                }
            }
            updatesManager.fetchUpdates()
        }.onReceive(NotificationCenter.Publisher(center: .default, name: DidRunPipNotificationName)) { _ in
            DispatchQueue.global().async {
                let packages = getInstalledPackages()
                DispatchQueue.main.async {
                    self.installedPackages = packages
                }
            }
            
            updatesManager.updatablePackages = updatesManager.updatablePackages.filter({ !updating.contains($0.name) })
            updating = []
            updatesManager.fetchUpdates()
        }.onReceive(NotificationCenter.Publisher(center: .default, name: DidPressInstallWheelButtonNotificationName)) { _ in
            isPickingWheel = true
        }
    }
}

@available(iOS 13.0.0, *)
struct PyPiView_Previews: PreviewProvider {
    static var previews: some View {
        PyPiView(hostingController: nil, didSelectPackage: { _, _, _ in })
    }
}
