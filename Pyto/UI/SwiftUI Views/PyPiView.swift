//
//  PyPiView.swift
//  SwiftUI Views
//
//  Created by Adrian Labbé on 13-06-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import Foundation
import SwiftUI
import Combine

func search(for package: String) -> [String] {
    let index = Bundle.main.url(forResource: "pypi_index", withExtension: "html") ?? FileManager.default.urls(for: .libraryDirectory, in: .allDomainsMask)[0].appendingPathComponent("pypi_index.html")
    
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
        DispatchQueue.global().async {
            let packages = search(for: searchString)
            DispatchQueue.main.async {
                if self.searchString == searchString {
                    self.packages = packages
                }
                self.isLoading = false
            }
        }
    }
}

@available(iOS 13.0.0, *)
public struct PyPiView: View {
        
    @ObservedObject var index = PyPiIndex()
        
    public var didSelectPackage: ((String, Bool, Bool) -> Void)
    
    public var hostingController: UIViewController?
    
    public init(hostingController: UIViewController?, didSelectPackage: @escaping ((String, Bool, Bool) -> Void)) {
        self.didSelectPackage = didSelectPackage
        self.hostingController = hostingController
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
                    HStack {
                        HStack {
                            if item.lowercased() == self.index.searchString.lowercased() {
                                Text(item).fontWeight(.bold)
                            } else {
                                Text(item)
                            }
                            
                            ZStack {
                                Color.black.opacity(0.001).onTapGesture {
                                    self.didSelectPackage(item, false, false)
                                }
                                Spacer()
                            }
                            
                            Image(systemName: "chevron.right").foregroundColor(.secondary)
                        }
                        .onTapGesture {
                            self.didSelectPackage(item, false, false)
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
                                Text("pypi.moreInfo", comment: "")
                                Image(systemName: "ellipsis")
                            }
                        }
                    }
                })
            } else {
                Text("pypi.info", comment: "Text displayed on the PyPi installer")
                    .foregroundColor(.secondary)
                    .padding()
                Spacer()
                HStack(spacing: 0) {
                    Text("pypi.credits", comment: "Credits displayed on the bottom of the PyPi installer")
                        .foregroundColor(.secondary)
                        .font(.footnote)
                    
                    Button(action: {
                        UIApplication.shared.open(URL(string: "https://apps.apple.com/app/id1462586500")!, options: [:], completionHandler: nil)
                    }, label: {
                        Text("Juno")
                            .font(.footnote)
                            .foregroundColor(.blue)
                    })
                    
                    Spacer()
                }.padding()
            }
        }
        .navigationBarTitle("PyPi")
        .navigationBarItems(trailing:
            Button(action: {
                self.hostingController?.dismiss(animated: true, completion: nil)
            }) {
                Text("done", comment: "Done button").fontWeight(.bold)
            }
        )
    }
}

@available(iOS 13.0.0, *)
struct PyPiView_Previews: PreviewProvider {
    static var previews: some View {
        PyPiView(hostingController: nil, didSelectPackage: { _, _, _ in })
    }
}
