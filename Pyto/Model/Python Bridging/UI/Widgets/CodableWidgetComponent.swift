//
//  CodableWidgetComponent.swift
//  Pyto
//
//  Created by Emma Labbé on 30-07-20.
//  Copyright © 2020 Emma Labbé. All rights reserved.
//

import Foundation

struct CodableWidgetComponent: Codable {
    
    var className: String
    
    var data: Data
    
    func makeObject() -> WidgetComponent? {
        
        var className = self.className
        #if WIDGET
        className = "WidgetExtension.\(className)"
        #elseif os(iOS)
        className = "Pyto.\(className)"
        #elseif os(watchOS)
        className = "Pyto_Watch_Extension.\(className)"
        #endif
        
        guard let WidgetClass = NSClassFromString(className) as? WidgetComponent.Type else {
            return nil
        }
        
        do {
            let object = try JSONDecoder().decode(WidgetClass, from: data)
            return object
        } catch {
            print(error.localizedDescription)
            return nil
        }
    }
}
