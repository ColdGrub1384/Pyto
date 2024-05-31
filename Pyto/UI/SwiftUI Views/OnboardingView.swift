//
//  OnboardingView.swift
//  Pyto
//
//  Created by Emma Labbé on 04-06-20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import SwiftUI

fileprivate var fullVersionLibraries: [String] {
    #if PREVIEW
    ["numpy", "pandas", "matplotlib", "blah blah blah"]
    #else
    Python.shared.fullVersionExclusives
    #endif
}

@available(iOS 13.0.0, *)
public struct OnboardingView: View {
    
    @Environment(\.verticalSizeClass) var vertical
    
    @Environment(\.horizontalSizeClass) var horizontal
        
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
        
        if isTrialEnded {
            _isPricingSheetPresented = State(wrappedValue: true)
        }
    }
    
    var restoreButton: some View {
        Button(action: {
            self.restore()
        }) {
            Text("onboarding.restore", comment: "The button for restoring purchases")
        }
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
            .background(Color.green)
            .cornerRadius(12)
            
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
            .background(Color.orange)
            .cornerRadius(12)
        }
    }
    
    @State var isPricingSheetPresented = false
    
    var purchaseView: some View {
        VStack {
            NavigationLink(destination: {
                pricingView
            }, label: {
                Text("onboarding.purchase", comment: "The button for choosing a pricing")
                    .foregroundColor(.white)
                    .frame(width: 200)
                    .padding()
                    .background(Color.accentColor)
            })
            
            .cornerRadius(12)
        }
    }
    
    func featureView(name: String, lite: Bool) -> some View {
        HStack {
            Text(name)
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
            ScrollView {
                VStack {
                    HStack {
                        Spacer()
                        Text("onboarding.full", comment: "'Full'")
                        Text("onboarding.limited", comment: "'Limited'")
                    }.padding()
                    
                    featureView(name: NSLocalizedString("onboarding.features.1", comment: "Feature 1"), lite: true)
                    featureView(name: NSLocalizedString("onboarding.features.2", comment: "Feature 2"), lite: true)
                    featureView(name: NSLocalizedString("onboarding.features.3", comment: "Feature 3"), lite: true)
                    featureView(name: NSLocalizedString("onboarding.features.4", comment: "Feature 4"), lite: true)
                    featureView(name: NSLocalizedString("onboarding.features.5", comment: "Feature 5"), lite: true)
                    featureView(name: NSLocalizedString("onboarding.features.6", comment: "Feature 6"), lite: true)
                    featureView(name: NSLocalizedString("onboarding.features.7", comment: "Feature 7"), lite: false)
                    
                    ForEach(fullVersionLibraries.sorted(), id: \.self) { lib in
                        featureView(name: lib.capitalized, lite: false)
                    }
                }
            }
            
            Divider()
            
            if horizontal == .regular || vertical == .compact {
                HStack {
                    fullFeaturedView
                    liteView
                }.padding()
            } else {
                VStack {
                    fullFeaturedView
                    liteView
                }.padding()
            }
        }.navigationTitle(Text("onboarding.purchase", comment: "The button for choosing a pricing")).navigationBarTitleDisplayMode(.inline).toolbar {
            if horizontal == .compact {
                restoreButton
            }
        }
    }
    
    var welcome: Text {
        if #available(iOS 15.0, *) {
            var attr = AttributedString(localized: "onboarding.title.ios15", comment: "The title of the onboarding view")
            
            let inflection = InflectionRule(morphology: Morphology.user)
            attr.inflect = inflection
            
            attr = attr.inflected()
            
            if Morphology.user.grammaticalGender == nil || Morphology.user.grammaticalGender == .none {
                attr = AttributedString(localized: "onboarding.title.ios15.genderless", comment: "The title of the onboarding view")
            }
            
            return Text(attr).bold()
        } else {
            return Text("onboarding.title", comment: "The title of the onboarding view").bold()
        }
    }
    
    public var body: some View {
        NavigationView {
            VStack {
                
                welcome
                    .font(.largeTitle)
                    .padding()
                                
                Text("onboarding.subtitle", comment: "The text below the title")
                    .padding()
                
                Spacer()
                
                if vertical != .compact {
                    VStack {
                        ScrollView {
                            HStack {
                                if horizontal == .regular {
                                    Spacer()
                                }
                                VStack(alignment: .leading) {
                                    
                                    HStack {
                                        if #available(iOS 15.0, *) {
                                            Image(systemName: "play.fill").foregroundColor(.green).symbolRenderingMode(.multicolor).font(.largeTitle).frame(width: 50, height: 50)
                                        } else {
                                            Image(systemName: "play.fill")
                                        }
                                        Text("onboarding.runCode", comment: "The first presented feature")
                                        if horizontal == .compact {
                                            Spacer()
                                        }
                                    }
                                                                    
                                    HStack {
                                        if #available(iOS 15.0, *) {
                                            Image(systemName: "keyboard.fill").foregroundColor(.red).symbolRenderingMode(.multicolor).font(.largeTitle).frame(width: 50, height: 50)
                                        } else {
                                            Image(systemName: "keyboard.fill")
                                        }
                                        Text("onboarding.editor", comment: "The second presented feature")
                                        if horizontal == .compact {
                                            Spacer()
                                        }
                                    }
                                                                    
                                    HStack {
                                        if #available(iOS 15.0, *) {
                                            Image(systemName: "cube.box.fill").foregroundColor(.brown).symbolRenderingMode(.multicolor).font(.largeTitle).frame(width: 50, height: 50)
                                        } else {
                                            Image(systemName: "cube.box.fill")
                                        }
                                        Text("onboarding.pypi", comment: "The third presented feature")
                                        if horizontal == .compact {
                                            Spacer()
                                        }
                                    }
                                                                    
                                    HStack {
                                        if #available(iOS 15.0, *) {
                                            Image(systemName: "mic.fill").symbolRenderingMode(.multicolor).font(.largeTitle).frame(width: 50, height: 50)
                                        } else {
                                            Image(systemName: "mic.fill")
                                        }
                                        Text("onboarding.shortcuts", comment: "The fourth presented feature")
                                        if horizontal == .compact {
                                            Spacer()
                                        }
                                    }
                                    
                                                                    
                                    Group {
                                        HStack {
                                            if #available(iOS 15.0, *) {
                                                Image(systemName: "app.badge.fill").foregroundColor(.blue).symbolRenderingMode(.multicolor).font(.largeTitle).frame(width: 50, height: 50)
                                            } else {
                                                Image(systemName: "app.badge.fill")
                                            }
                                            Text("onboarding.widgetsuis", comment: "The fifth presented feature")
                                            if horizontal == .compact {
                                                Spacer()
                                            }
                                        }
                                        
                                        
                                    }
                                }.padding()
                                
                                if horizontal == .regular {
                                    Spacer()
                                }
                            }.font(horizontal == .regular ? .title3 : .body)
                            }
                        
                        Spacer()
                    }
                }
                
                
                if horizontal == .compact && vertical == .regular {
                    trialButton
                    purchaseView
                } else {
                    HStack {
                        purchaseView
                        trialButton
                        restoreButton.padding()
                    }
                }
            }.navigationBarHidden(true)
        }.navigationViewStyle(.stack)
    }
}

@available(iOS 13.0.0, *)
struct OnboardingView_Previews: PreviewProvider {
    static var previews: some View {
        OnboardingView(isTrialEnded: false, fullFeaturedPrice: "9.99$", noExtensionsPrice: "2.99$", startFreeTrial: {}, purchaseFull: {}, purchaseLite: {}, restore: {}).previewDevice(.init(rawValue: "iPhone 13 mini"))
        
        if #available(iOS 15.0, *) {
            OnboardingView(isTrialEnded: true, fullFeaturedPrice: "9.99$", noExtensionsPrice: "2.99$", startFreeTrial: {}, purchaseFull: {}, purchaseLite: {}, restore: {}).previewDevice(.init(rawValue: "iPhone 13 mini")).previewInterfaceOrientation(.landscapeRight)
        }
        
        if #available(iOS 15.0, *) {
            OnboardingView(isTrialEnded: false, fullFeaturedPrice: "9.99$", noExtensionsPrice: "2.99$", startFreeTrial: {}, purchaseFull: {}, purchaseLite: {}, restore: {}).previewDevice(.init(rawValue: "iPad Pro (11-inch) (3rd generation)")).previewInterfaceOrientation(.landscapeRight)
        }
        OnboardingView(isTrialEnded: true, fullFeaturedPrice: "9.99$", noExtensionsPrice: "2.99$", startFreeTrial: {}, purchaseFull: {}, purchaseLite: {}, restore: {}).previewDevice(.init(rawValue: "iPad Pro (11-inch) (3rd generation)"))
    }
}
