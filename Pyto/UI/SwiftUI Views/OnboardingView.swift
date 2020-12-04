//
//  OnboardingView.swift
//  Pyto
//
//  Created by Adrian Labbé on 04-06-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import SwiftUI

fileprivate var fullVersionLibrairies: [String] {
    
    // Pure Python libraires that can be install with PyPi but are included because they are dependencies of a library
    let purePython = [
        "dask",
        "jmespath",
        "joblib",
        "smart_open",
        "boto",
        "boto3",
        "botocore"
    ]
    
    guard let url = Bundle.main.url(forResource: "OnDemandLibraries", withExtension: "plist") else {
        return []
    }
    
    guard let dict = NSDictionary(contentsOf: url) else {
        return []
    }
    
    var keys = [String]()
    
    for key in (dict.allKeys as? [String]) ?? [] {
        if !purePython.contains(key) {
            keys.append(key)
        }
    }
    
    keys.sort()
    
<<<<<<< HEAD
    if let i = keys.firstIndex(of: "matplotlib") {
        keys.remove(at: i)
        keys.insert("matplotlib", at: 0)
    }
    
    if let i = keys.firstIndex(of: "pandas") {
        keys.remove(at: i)
        keys.insert("pandas", at: 0)
    }
    
    if let i = keys.firstIndex(of: "numpy") {
        keys.remove(at: i)
        keys.insert("numpy", at: 0)
    }
    
=======
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
    return keys
}

@available(iOS 13.0.0, *)
public struct OnboardingView: View {
    
    @Environment(\.verticalSizeClass) var vertical
<<<<<<< HEAD
        
=======
    
    @State var showingDetail = false
    
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
    public var isTrialEnded: Bool
    
    public var fullFeaturedPrice: String
    
    public var noExtensionsPrice: String
    
    public var startFreeTrial: (() -> Void)
    
    public var purchaseFull: (() -> Void)
    
    public var purchaseLite: (() -> Void)
    
    public var restore: (() -> Void)
    
    public init(isTrialEnded: Bool, fullFeaturedPrice: String, noExtensionsPrice: String, startFreeTrial: @escaping (() -> Void), purchaseFull: @escaping (() -> Void), purchaseLite: @escaping (() -> Void), restore: @escaping (() -> Void)) {
        self.isTrialEnded = isTrialEnded
        self.fullFeaturedPrice = fullFeaturedPrice
        self.noExtensionsPrice = noExtensionsPrice
        self.startFreeTrial = startFreeTrial
        self.purchaseFull = purchaseFull
        self.purchaseLite = purchaseLite
        self.restore = restore
<<<<<<< HEAD
        
        if isTrialEnded {
            _isPricingSheetPresented = State(wrappedValue: true)
        }
=======
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
    }
    
    var restoreButton: some View {
        Button(action: {
            self.restore()
        }) {
            Text("onboarding.restore", comment: "The button for restoring purchases")
        }.padding()
    }
    
    var trialButton: some View {
        Button(action: {
            guard !self.isTrialEnded else {
                return
            }
            
            self.startFreeTrial()
        }) {
            Text(self.isTrialEnded ? "onboarding.trialEnded" : "onboarding.beginFreeTrial")
            .foregroundColor(.white)
            .frame(width: 200)
        }
        .padding()
        .background(Color.accentColor)
        .cornerRadius(12)
        .disabled(self.isTrialEnded)
    }
    
    var fullFeaturedView: some View {
        VStack {
            Button(action: {
                self.purchaseFull()
            }) {
                Text("onboarding.fullFeatured \(self.fullFeaturedPrice)", comment: "The button for purchasing the full featured version")
                    .foregroundColor(.white)
                .frame(width: 200)
            }
            .padding()
<<<<<<< HEAD
            .background(Color.green)
            .cornerRadius(12)
            
=======
            .background(Color.accentColor)
            .cornerRadius(12)
            
            Button(action: {
                self.showingDetail.toggle()
            }) {
                Text("onboarding.libraries", comment: "The button linking to a list of contained libraries in the pro version")
                .font(.footnote)
                .underline()
                .padding()
            }
            .sheet(isPresented: $showingDetail) {
                VStack {
                    Button(action: {
                        self.showingDetail = false
                    }) {
                        HStack {
                            Spacer()
                            
                            Text("done", comment: "Done button")
                            .fontWeight(.bold)
                            .padding()
                        }
                    }
                    
                    List(fullVersionLibrairies, id: \.self) { item in
                        Text(item)
                    }
                }
            }
            .accentColor(.primary)
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
        }
    }
    
    var liteView: some View {
        VStack {
            Button(action: {
                self.purchaseLite()
            }) {
                Text("onboarding.limitedVersion \(self.noExtensionsPrice)", comment: "The button for purchasing the limited version")
                    .foregroundColor(.white)
                .frame(width: 200)
            }
            .padding()
<<<<<<< HEAD
            .background(Color.orange)
            .cornerRadius(12)
        }
    }
    
    @State var isPricingSheetPresented = false
    
    var purchaseView: some View {
        VStack {
            Button(action: {
                self.isPricingSheetPresented = true
            }, label: {
                Text("onboarding.purchase", comment: "The button for choosing a pricing")
                    .foregroundColor(.white)
                    .frame(width: 200)
                    .padding()
                    .background(Color.accentColor)
            })
            
            .cornerRadius(12)
            .sheet(isPresented: $isPricingSheetPresented, content: {
                pricingView
            })
            
            Text("onboarding.twoPricesAvailable", comment: "The text bellow the purchase button")
=======
            .background(Color.accentColor)
            .cornerRadius(12)
            
            Text("onboarding.noExtensionsFootnote", comment: "The footnote below the button for purchasing the limited version")
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
            .font(.footnote)
            .frame(width: 200)
            .padding()
        }
    }
    
<<<<<<< HEAD
    func featureView(name: String, lite: Bool) -> some View {
        HStack {
            Text(NSLocalizedString(name, comment: ""))
            Spacer()
            
            Image(systemName: "checkmark").foregroundColor(.green).padding(.horizontal, 30)
            
            if lite {
                Image(systemName: "checkmark").foregroundColor(.green)
            } else {
                Image(systemName: "xmark").foregroundColor(.red)
            }
        }.padding(10)
    }
    
    var pricingView: some View {
        VStack {
                        
            HStack {
                Spacer()
                Button(action: {
                    isPricingSheetPresented = false
                }, label: {
                    Text("done").fontWeight(.bold)
                }).hover().padding(5)
            }
            
            ScrollView {
                
                if vertical != .compact {
                    HStack {
                        Text("onboarding.purchase", comment: "The button for choosing a pricing").font(.largeTitle).fontWeight(.bold)
                        Spacer()
                    }.padding()
                }
                
                VStack {
                    HStack {
                        Spacer()
                        Text("onboarding.full", comment: "'Full'")
                        Text("onboarding.limited", comment: "'Limited'")
                    }.padding()
                    
                    featureView(name: "onboarding.features.1", lite: true)
                    featureView(name: "onboarding.features.2", lite: true)
                    featureView(name: "onboarding.features.3", lite: true)
                    featureView(name: "onboarding.features.4", lite: true)
                    featureView(name: "onboarding.features.5", lite: true)
                    
                    ForEach(fullVersionLibrairies, id: \.self) { lib in
                        featureView(name: lib.capitalized, lite: false)
                    }
                    
                    Text("onboarding.purchaseWarning", comment: "A warning so people don't email me about how to install Tensorflow")
                        .foregroundColor(.orange)
                        .padding()
                }
            }
            
            Divider()
            
            if vertical == .compact {
                HStack {
                    fullFeaturedView
                    liteView
                }.padding()
            } else {
                VStack {
                    fullFeaturedView
                    liteView
                    restoreButton
                }.padding()
            }
        }
    }
    
=======
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
    public var body: some View {
        VStack {
            
            Text("onboarding.title", comment: "The title of the onboarding view")
                .font(.largeTitle)
                .padding()
                            
            Text("onboarding.subtitle", comment: "The text below the title")
                .padding()
            
            Spacer()
            
            if vertical != .compact {
                VStack {
                    ScrollView {
                        VStack {
                            
                            HStack {
                                Image(systemName: "play")
                                Text("onboarding.runCode", comment: "The first presented feature")
                                Spacer()
                            }
                            
                            Divider()
                            
                            HStack {
                                Image(systemName: "keyboard")
                                Text("onboarding.editor", comment: "The second presented feature")
                                Spacer()
                            }
                            
                            Divider()
                            
                            HStack {
                                Image(systemName: "cube.box")
                                Text("onboarding.pypi", comment: "The third presented feature")
                                Spacer()
                            }
                            
                            Divider()
                            
                            HStack {
                                Image(systemName: "mic")
                                Text("onboarding.shortcuts", comment: "The fourth presented feature")
                                Spacer()
                            }
<<<<<<< HEAD
                            
                            Divider()
                            
                            HStack {
                                Image(systemName: "apps.iphone")
                                Text("onboarding.widgets", comment: "The fifth presented feature")
                                Spacer()
                            }
=======
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
                        }.padding()
                    }
                    
                    Spacer()
                }
            }
<<<<<<< HEAD
                        
            purchaseView
=======
            
            //Spacer()
            
            if vertical == .compact {
                HStack {
                    VStack {
                        fullFeaturedView
                        Spacer()
                    }
                    
                    VStack {
                        liteView
                        Spacer()
                    }
                }
            } else {
                fullFeaturedView
                
                Spacer()
                
                liteView
            }
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
            
            if vertical == .compact {
                HStack {
                    trialButton
<<<<<<< HEAD
=======
                    //Spacer()
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
                    restoreButton
                }
                Spacer()
            } else {
                trialButton
                
                Spacer()
                
                restoreButton
            }
        }
    }
}

@available(iOS 13.0.0, *)
struct OnboardingView_Previews: PreviewProvider {
    static var previews: some View {
<<<<<<< HEAD
        OnboardingView(isTrialEnded: true, fullFeaturedPrice: "9.99$", noExtensionsPrice: "2.99$", startFreeTrial: {}, purchaseFull: {}, purchaseLite: {}, restore: {})
=======
        OnboardingView(isTrialEnded: false, fullFeaturedPrice: "9.99$", noExtensionsPrice: "2.99$", startFreeTrial: {}, purchaseFull: {}, purchaseLite: {}, restore: {}).previewLayout(.fixed(width: 568, height: 320))
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
    }
}
