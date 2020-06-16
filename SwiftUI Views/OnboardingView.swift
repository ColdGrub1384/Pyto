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
    
    return keys
}

@available(iOS 13.0.0, *)
public struct OnboardingView: View {
    
    @Environment(\.verticalSizeClass) var vertical
    
    @State var showingDetail = false
    
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
    }
    
    var restoreButton: some View {
        Button(action: {
            self.restore()
        }) {
            Text("onboarding.restore", bundle: SwiftUIBundle, comment: "The button for restoring purchases")
        }.padding()
    }
    
    var trialButton: some View {
        Button(action: {
            guard !self.isTrialEnded else {
                return
            }
            
            self.startFreeTrial()
        }) {
            Text(self.isTrialEnded ? "onboarding.trialEnded" : "onboarding.beginFreeTrial", bundle: SwiftUIBundle)
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
                Text("onboarding.fullFeatured \(self.fullFeaturedPrice)", bundle: SwiftUIBundle, comment: "The button for purchasing the full featured version")
                    .foregroundColor(.white)
                .frame(width: 200)
            }
            .padding()
            .background(Color.accentColor)
            .cornerRadius(12)
            
            Button(action: {
                self.showingDetail.toggle()
            }) {
                Text("onboarding.libraries", bundle: SwiftUIBundle, comment: "The button linking to a list of contained libraries in the pro version")
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
                            
                            Text("done", bundle: SwiftUIBundle, comment: "Done button")
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
        }
    }
    
    var liteView: some View {
        VStack {
            Button(action: {
                self.purchaseLite()
            }) {
                Text("onboarding.limitedVersion \(self.noExtensionsPrice)", bundle: SwiftUIBundle, comment: "The button for purchasing the limited version")
                    .foregroundColor(.white)
                .frame(width: 200)
            }
            .padding()
            .background(Color.accentColor)
            .cornerRadius(12)
            
            Text("onboarding.noExtensionsFootnote", bundle: SwiftUIBundle, comment: "The footnote below the button for purchasing the limited version")
            .font(.footnote)
            .frame(width: 200)
            .padding()
        }
    }
    
    public var body: some View {
        VStack {
            
            Text("onboarding.title", bundle: SwiftUIBundle, comment: "The title of the onboarding view")
                .font(.largeTitle)
                .padding()
                            
            Text("onboarding.subtitle", bundle: SwiftUIBundle, comment: "The text below the title")
                .padding()
            
            Spacer()
            
            if vertical != .compact {
                VStack {
                    ScrollView {
                        VStack {
                            
                            HStack {
                                Image(systemName: "play")
                                Text("onboarding.runCode", bundle: SwiftUIBundle, comment: "The first presented feature")
                                Spacer()
                            }
                            
                            Divider()
                            
                            HStack {
                                Image(systemName: "keyboard")
                                Text("onboarding.editor", bundle: SwiftUIBundle, comment: "The second presented feature")
                                Spacer()
                            }
                            
                            Divider()
                            
                            HStack {
                                Image(systemName: "cube.box")
                                Text("onboarding.pypi", bundle: SwiftUIBundle, comment: "The third presented feature")
                                Spacer()
                            }
                            
                            Divider()
                            
                            HStack {
                                Image(systemName: "mic")
                                Text("onboarding.shortcuts", bundle: SwiftUIBundle, comment: "The fourth presented feature")
                                Spacer()
                            }
                        }.padding()
                    }
                    
                    Spacer()
                }
            }
            
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
            
            if vertical == .compact {
                HStack {
                    trialButton
                    //Spacer()
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
        OnboardingView(isTrialEnded: false, fullFeaturedPrice: "9.99$", noExtensionsPrice: "2.99$", startFreeTrial: {}, purchaseFull: {}, purchaseLite: {}, restore: {}).previewLayout(.fixed(width: 568, height: 320))
    }
}
