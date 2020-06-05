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
    
    public var body: some View {
        VStack {
            VStack {
                Text("Welcome to Pyto\n")
                    .font(.largeTitle)
                            
                Text("You can try Pyto for free during 3 days. Once your free trial expired, you'll need to purchase one of the two options bellow to continue using the app.")
                    .padding()
                
                Spacer()
            }
            
            Button(action: {
                self.purchaseFull()
            }) {
                Text("Full featured \(self.fullFeaturedPrice)")
                    .foregroundColor(.white)
                .frame(width: 200)
            }
            .padding()
            .background(Color.accentColor)
            .cornerRadius(12)
            
            Button(action: {
                self.showingDetail.toggle()
            }) {
                Text("Contains these libraries")
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
                }.accentColor(.blue)
            }
            .accentColor(.primary)
            
            Spacer()
            
            Button(action: {
                self.purchaseLite()
            }) {
                Text("No C extensions \(self.noExtensionsPrice)")
                    .foregroundColor(.white)
                .frame(width: 200)
            }
            .padding()
            .background(Color.accentColor)
            .cornerRadius(12)
            
            Text("Doesn't contain any C extension")
            .font(.footnote)
            .padding()
            
            Spacer()
            
            Button(action: {
                guard !self.isTrialEnded else {
                    return
                }
                
                self.startFreeTrial()
            }) {
                Text(self.isTrialEnded ? "Trial period ended" : "Begin free trial (3 days)")
                .foregroundColor(.white)
                .frame(width: 200)
            }
            .padding()
            .background(Color.accentColor)
            .cornerRadius(12)
            .disabled(self.isTrialEnded)
            
            Spacer()
            
            Button(action: {
                self.restore()
            }) {
                Text("Restore")
            }.padding()
        }.accentColor(.blue)
    }
}

@available(iOS 13.0.0, *)
struct OnboardingView_Previews: PreviewProvider {
    static var previews: some View {
        OnboardingView(isTrialEnded: false, fullFeaturedPrice: "9.99$", noExtensionsPrice: "3.99$", startFreeTrial: {}, purchaseFull: {}, purchaseLite: {}, restore: {})
    }
}
