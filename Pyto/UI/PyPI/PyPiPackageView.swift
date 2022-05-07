//
//  PyPiPackageView.swift
//  Pyto
//
//  Created by Emma on 05-04-22.
//  Copyright © 2022 Emma Labbé. All rights reserved.
//

import SwiftUI

struct PyPiPackageView: View {
    
    @Environment(\.horizontalSizeClass) var horizontal
    
    var pipViewController: PipViewController
    
    @State var selectedVersion: String?
    
    @State private var isUpdatingMenuPicker = false // WHY CAN'T YOU YOU JUST UPDATE ON @State CHANGE LIKE EVERYONE ELSE
    
    var package: PyPackage
    
    var isFullVersion: Bool {
        !isLiteVersion.boolValue
    }
    
    var isBundled: Bool {
        PipViewController.bundled.contains(package.name ?? "<nil>")
    }
    
    var isInstalled: Bool {
        
        guard let name = package.name else {
            return false
        }
        
        let installed = Python.pythonShared?.perform(#selector(PythonRuntime.getString(_:)), with: """
        import _pip
        import json
        s = json.dumps(_pip._get_modules())
        """)
        
        if let list = (installed?.takeUnretainedValue() as? String)?.data(using: .utf8), let installedList = (try? JSONSerialization.jsonObject(with: list, options: .fragmentsAllowed)) as? [String] {
            
            return installedList.map({ $0.lowercased() }).contains(name)
        } else {
            return false
        }
    }
    
    var links: [(title: String, url: URL)] {
        [(
            title: "PyPI",
            url: URL(string: "https://pypi.org/project/\(package.name ?? "")")!
        )]+package.links
    }
    
    func buttonsLayout<Content: View>(@ViewBuilder buttons: @escaping () -> Content) -> some View {
        
        let yeahIFinallyAddedSomethingThatTellsTheUserTheyCannotInstallThisPackageBecauseItHasCExtensions😅ItDoesNotWorkForPackagesThatDontDistributeBinariesThoICouldLookForTheSetupDotPyButThatWouldRequireDownloadingTheSourceCode = Text("pypi.hasCext", comment: "The text displayed when a package has C extensions").foregroundColor(.secondary)
        
        if horizontal == .compact {
            return AnyView(VStack(alignment: .leading) {
                buttons()
                if package.foundExtensions {
                    yeahIFinallyAddedSomethingThatTellsTheUserTheyCannotInstallThisPackageBecauseItHasCExtensions😅ItDoesNotWorkForPackagesThatDontDistributeBinariesThoICouldLookForTheSetupDotPyButThatWouldRequireDownloadingTheSourceCode
                }
            })
        } else {
            return AnyView(VStack(alignment: .leading) {
                HStack(spacing: 10) {
                    buttons()
                }
                
                if package.foundExtensions {
                    HStack {
                        yeahIFinallyAddedSomethingThatTellsTheUserTheyCannotInstallThisPackageBecauseItHasCExtensions😅ItDoesNotWorkForPackagesThatDontDistributeBinariesThoICouldLookForTheSetupDotPyButThatWouldRequireDownloadingTheSourceCode
                        Spacer()
                    }
                }
            })
        }
    }
    
    func conditionallyCustomize<Content: View, Result: View>(@ViewBuilder content: @escaping () -> Content, @ViewBuilder customize: @escaping (Content) -> Result) -> some View {
        customize(content())
    }
    
    var body: some View {
        ScrollView {
            
            if let desc = package.description {
                HStack {
                    Text(desc)
                    Spacer()
                }.padding()
            }
            
            HStack {
                buttonsLayout {
                    if isBundled {
                        
                        conditionallyCustomize {
                            
                            if isFullVersion {
                                Button {
                                    
                                } label: {
                                    Label {
                                        Text("pypi.providedByPyto", comment: "Library is provided by Pyto")
                                    } icon: {
                                        Image(systemName: "shippingbox.fill")
                                    }.frame(width: 250, height: 30)
                                }.disabled(true)
                            } else {
                                Button {
                                    UIApplication.shared.open(URL(string: "pyto://upgrade")!)
                                } label: {
                                    Text("Upgrade \(ProcessInfo.processInfo.environment["UPGRADE_PRICE"] ?? "3.99")$").frame(width: 250, height: 30)
                                }.accentColor(.blue)
                            }
                            
                            
                        } customize: { button in
                            if #available(iOS 15.0, *) {
                                button.buttonStyle(.borderedProminent)
                            } else {
                                button
                            }
                        }
                    } else {
                        conditionallyCustomize {
                            Button {
                                pipViewController.install(version: selectedVersion ?? package.stableVersion)
                            } label: {
                                Label {
                                    Text("pypi.install", comment: "Install")
                                } icon: {
                                    Image(systemName: "square.and.arrow.down.fill")
                                }.frame(width: 250, height: 30)
                            }.disabled(package.foundExtensions)
                        } customize: { button in
                            if #available(iOS 15.0, *) {
                                button.buttonStyle(.borderedProminent)
                            } else {
                                button
                            }
                        }

                        
                        if isInstalled {
                            conditionallyCustomize {
                                Button {
                                    pipViewController.remove()
                                } label: {
                                    Label {
                                        Text("pypi.uninstall", comment: "Uninstall a package")
                                    } icon: {
                                        Image(systemName: "trash.fill")
                                    }.frame(width: 250, height: 30)
                                }.accentColor(.red)
                            } customize: { button in
                                if #available(iOS 15.0, *) {
                                    button.buttonStyle(.bordered)
                                } else {
                                    button
                                }
                            }
                        }
                    }
                }
                Spacer()
            }.padding()
            
            VStack {
                Divider()
                HStack {
                    Label {
                        Text("pypi.author", comment: "Author").bold()
                    } icon: {
                        Image(systemName: "person")
                    }
                    Spacer()
                    Text(package.author ?? "")
                }
                
                if let maintainer = package.maintainer, maintainer != package.author && !maintainer.isEmpty {
                    Divider()
                    
                    HStack {
                        Label {
                            Text("pypi.maintainer", comment: "Maintainer").bold()
                        } icon: {
                            Image(systemName: "hammer")
                        }
                        Spacer()
                        Text(maintainer)
                    }
                }
                
                Divider()
                
                DisclosureGroup {
                    VStack {
                        ForEach(links, id: \.url) { link in
                            Link(destination: link.url) {
                                HStack {
                                    Text(link.title).foregroundColor(.accentColor)
                                    Spacer()
                                    Image(systemName: "arrow.up.forward").foregroundColor(.accentColor)
                                }
                            }
                            Divider()
                        }
                    }.padding([.leading, .top])
                } label: {
                    Label {
                        Text("pypi.links", comment: "The title of the 'Links' section").bold()
                    } icon: {
                        Image(systemName: "safari")
                    }.foregroundColor(.primary)
                }
            }.padding()
        }.navigationTitle(package.name ?? "").toolbar {
            ToolbarItemGroup(placement: .navigationBarTrailing) {
                if !isUpdatingMenuPicker {
                    Menu {
                        ForEach(package.versions, id: \.self) { version in
                            Button {
                                selectedVersion = version
                            } label: {
                                if version == selectedVersion {
                                    Label {
                                        Text(version)
                                    } icon: {
                                        Image(systemName: "checkmark")
                                    }
                                } else {
                                    Text(version)
                                }
                            }
                        }
                    } label: {
                        HStack {
                            Text(selectedVersion ?? package.stableVersion ?? "").font(.title3)
                            Image(systemName: "chevron.up.chevron.down")
                        }
                    }
                } else {
                    Text("").onAppear {
                        isUpdatingMenuPicker = false
                    }
                }
            }
        }.onChange(of: selectedVersion) { _ in
            isUpdatingMenuPicker = true
        }
    }
}
