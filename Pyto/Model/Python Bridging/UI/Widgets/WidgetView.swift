//
//  WidgetView.swift
//  Pyto
//
//  Created by Adrian Labbé on 25-07-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import UIKit
import SwiftUI

@available(iOS 14.0, *)
@objc class WidgetView: NSObject, Codable {
    
    override init() {}
    
    var rows = [WidgetRow]()
    
    #if os(iOS)
    var entry: ScriptEntry?
    #endif
    
    @objc var backgroundColor: UIColor?
        
    @objc var backgroundImage: WidgetImage?
    
<<<<<<< HEAD
    @objc var backgroundGradient: [UIColor]?
    
=======
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
    @objc var link: String?
    
    @objc func addRow(_ row: NSArray, backgroundColor: UIColor?, cornerRadius: Float, identifier: String?) {
        if let row = row as? [WidgetComponent] {
            var newRow = WidgetRow(content: row, identifier: nil)
            newRow.backgroundColor = backgroundColor
            newRow.cornerRadius = cornerRadius
            newRow.identifier = identifier
            rows.append(newRow)
        }
    }
    
    @objc func addSpacer() {
        rows.append(WidgetRow(content: [], isSpacer: true, identifier: nil))
    }
    
    @objc func addDivider(color: UIColor?) {
        var row = WidgetRow(content: [], isDivider: true, identifier: nil)
        row.backgroundColor = color
        rows.append(row)
    }
    
    var makeView: some View {
        VStack {
            ForEach(rows) { row -> AnyView in
                if row.isSpacer {
                    
                    return AnyView(Spacer())
                    
                } else if row.isDivider {
                    
                    #if os(iOS)
                    let gray = UIColor.systemGray
                    #elseif os(watchOS)
                    let gray = UIColor.lightGray
                    #endif
                    
                    return AnyView(Rectangle()
                                    .fill(Color(row.backgroundColor ?? gray))
                                    .frame(height: 1)
                                    .edgesIgnoringSafeArea(.horizontal))
                    
                } else {
                                            
                    let rowContent = HStack {
                        HStack {
                            ForEach(row.content) { view -> AnyView in
                                #if os(iOS)
                                if view.identifier != nil, let url = self.entry?.url(viewID: view.identifier) {
                                    
                                    return AnyView(Link(destination: url, label: {
                                        WidgetComponent.PaddingView(view: AnyView(view.makeView.padding(view.paddingEdges)), customPadding: view.customPadding)
                                    }).buttonStyle(PlainButtonStyle()))
                                    
                                } else {
                                    
                                    return AnyView(WidgetComponent.PaddingView(view: AnyView(view.makeView.padding(view.paddingEdges)), customPadding: view.customPadding))
                                    
                                }
                                #elseif os(watchOS)
                                return AnyView(WidgetComponent.PaddingView(view: AnyView(view.makeView.padding(view.paddingEdges)), customPadding: view.customPadding))
                                #endif
                            }
                        }.padding((row.backgroundColor != nil && row.backgroundColor != UIColor.clear) ? .vertical : [])
                         .padding((row.backgroundColor != nil && row.backgroundColor != UIColor.clear) ? .horizontal : [], 10)
                    }
                    .background(Color(row.backgroundColor ?? UIColor.clear))
                    .cornerRadius(CGFloat(row.cornerRadius))
                    
                    #if os(iOS)
                    if row.identifier != nil, let url = self.entry?.url(viewID: row.identifier) {
                        return AnyView(Link(destination: url, label: {
                            rowContent
                        }))
                    } else {
                        return AnyView(rowContent)
                    }
                    #elseif os(watchOS)
                    return AnyView(rowContent)
                    #endif
                }
            }
        }
    }
    
    enum Keys: CodingKey {
        
        case rows
        
        case backgroundColor
        
<<<<<<< HEAD
        case backgroundGradient
        
=======
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
        case backgroundImage
        
        case link
    }
    
    required init(from decoder: Decoder) throws {
        let container = try decoder.container(keyedBy: Keys.self)
        
        do {
            let colorData = try container.decode(Data.self, forKey: .backgroundColor)
            backgroundColor = UIColor.color(withData: colorData)
        } catch {
            backgroundColor = nil
        }
        
        do {
<<<<<<< HEAD
            let colorData = try container.decode([Data].self, forKey: .backgroundGradient)
            var gradient = [UIColor]()
            for data in colorData {
                gradient.append(UIColor.color(withData: data))
            }
            backgroundGradient = gradient
        } catch {
            backgroundGradient = nil
        }
        
        do {
=======
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
            backgroundImage = try container.decode(WidgetImage.self, forKey: .backgroundImage)
        } catch {
            backgroundImage = nil
        }
        
        rows = try container.decode([WidgetRow].self, forKey: .rows)
        
        do {
            link = try container.decode(String.self, forKey: .link)
        } catch {
            link = nil
        }
    }
    
    func encode(to encoder: Encoder) throws {
        var container = encoder.container(keyedBy: Keys.self)
        try container.encode(backgroundColor?.encode(), forKey: .backgroundColor)
        try container.encode(backgroundImage, forKey: .backgroundImage)
        try container.encode(rows, forKey: .rows)
        try container.encode(link, forKey: .link)
<<<<<<< HEAD
        
        if let gradient = backgroundGradient {
            var gradientData = [Data]()
            for gradientColor in gradient {
                gradientData.append(gradientColor.encode())
            }
            try container.encode(gradientData, forKey: .backgroundGradient)
        }
=======
>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
    }
}
