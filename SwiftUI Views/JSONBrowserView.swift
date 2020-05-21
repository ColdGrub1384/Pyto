//
//  JSONBrowserView.swift
//  SwiftUI Views
//
//  Created by Adrian Labbé on 18-05-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import SwiftUI

func asDictionary(_ value: Any?) -> [String:Any] {
    
    if let dict = value as? [String:Any] {
        return dict
    } else if let arr = value as? [Any] {
        var dict = [String:Any]()
        for (index, value) in arr.enumerated() {
            dict["\(index)"] = value
        }
        
        return dict
    }
    
    return [:]
}

func sorted(_ arr: [Any], sorted: Bool) -> [String] {
    if !sorted {
        return (arr as? [String]) ?? []
    } else {
        return (arr.sorted { (val1, val2) -> Bool in
            guard let str1 = val1 as? String, let str2 = val2 as? String else {
                return false
            }
            
            guard let num1 = Int(str1), let num2 = Int(str2) else {
                return false
            }
            
            return num1 < num2
        } as? [String]) ?? []
    }
}

@available(iOS 13.0, *)
public struct JSONBrowserView: View {
    
    let items: [String:Any]
    
    @Binding var navBarMode: NavigationBarItem.TitleDisplayMode
    
    @State var displayMode: NavigationBarItem.TitleDisplayMode = .inline
    
    let title: String
    
    let isArray: Bool
    
    let dismiss: (() -> Void)?
    
    init(title: String = "Inspector", dismiss: (() -> Void)? = nil, navBarMode: Binding<NavigationBarItem.TitleDisplayMode>, items: [String:Any], isArray: Bool = false) {
        self.title = title
        self.dismiss = dismiss
        self._navBarMode = navBarMode
        self.items = items
        self.isArray = true
    }
    
    public var body: some View {
        List(sorted(Array(items.keys), sorted: isArray), id:\.self) { item in
            if self.items[item] is Dictionary<String, Any> || self.items[item] is Array<Any> {
                NavigationLink(destination: JSONBrowserView(title: item, dismiss: self.dismiss, navBarMode: self.$displayMode, items: asDictionary(self.items[item]), isArray: (self.items[item] is Array<Any>))) {
                    Cell(title: item, detail: String("\(self.items[item] ?? "")".prefix(300)))
                }
            } else {
                NavigationLink(destination: ValueView(title: item, text: "\(self.items[item] ?? "")")) {
                    Cell(title: item, detail: String("\(self.items[item] ?? "")".prefix(300)))
                }
            }
        }
        .id(UUID())
        .navigationBarTitle(Text(title), displayMode: navBarMode)
        .navigationBarItems(trailing:
            Button(action: {
                self.dismiss?()
            }) {
                if self.dismiss != nil {
                    Text("Done").fontWeight(.bold)
                }
            }
        )
    }
}

@available(iOS 13.0, *)
public struct JSONBrowserNavigationView: View {
    
    @State var displayMode: NavigationBarItem.TitleDisplayMode = .automatic
    
    let items: [String:Any]
    
    let dismiss: (() -> Void)?
    
    public init(items: [String:Any], dismiss: (() -> Void)? = nil) {
        self.items = items
        self.dismiss = dismiss
    }
    
    public var body: some View {
        NavigationView {
            JSONBrowserView(dismiss: dismiss, navBarMode: self.$displayMode, items: items)
        }
        .navigationViewStyle(StackNavigationViewStyle())
    }
}

@available(iOS 13.0, *)
struct JSONBrowserView_Previews: PreviewProvider {
    static var previews: some View {
        JSONBrowserNavigationView(items: ["'Foo'":"Bar", "Hello": ["World": "Foo", "Array": [1, 2, "Foo", "Bar", 4]]])
        .previewDevice(PreviewDevice(rawValue: "iPad (7th generation)"))
        .previewDisplayName("iPad")
    }
}
