//
//  PyWatchUI.swift
//  Pyto Watch Extension
//
//  Created by Adrian Labbé on 07-10-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import WatchConnectivity
import SwiftUI

#if os(watchOS)
import WatchKit

class WatchHostingController: WKHostingController<ScrollView<AnyView>> {
    
    var lastViewData: Data?
    
    override var body: ScrollView<AnyView> {
        if let view = PyWatchUI.cachedView {
            
            do {
                lastViewData = try JSONEncoder().encode(view)
            } catch {
                print(error.localizedDescription)
            }
            
            return ScrollView {
                return AnyView(view.makeView)
            }
        } else {
            return ScrollView {
                return AnyView(Spacer())
            }
        }
    }
}
#endif

@available(iOS 14.0, *)
@objc class PyWatchUI: NSObject {
    
    static let cacheURL = FileManager.default.urls(for: .documentDirectory, in: .allDomainsMask)[0].appendingPathComponent("watchui.json")
    
    #if os(watchOS)
        
    static func showView() {
        var controller = WKExtension.shared().visibleInterfaceController ?? WKExtension.shared().rootInterfaceController
        
        if let hostingController = controller as? WatchHostingController {
            
            if let view = PyWatchUI.cachedView {
                let data = try? JSONEncoder().encode(view)
                if hostingController.lastViewData == data { // Do not update the view if it's the same
                    return
                }
            }
            
            controller?.dismiss()
            controller = WKExtension.shared().rootInterfaceController
        }
        
        controller?.presentController(withName: "UI", context: nil)
    }
    
    static var cachedView: WidgetView? {
        do {
            let data = try Data(contentsOf: cacheURL)
            let view = try JSONDecoder().decode(WidgetView.self, from: data)
            return view
        } catch {
            return nil
        }
    }
    #endif
    
    #if os(iOS)
    @objc static func sendUI(_ view: WidgetView) {
        do {
            let data = try JSONEncoder().encode(view)
            try data.write(to: cacheURL)
        } catch {
            print(error.localizedDescription)
        }
        
        WCSession.default.transferFile(cacheURL, metadata: nil)
    }
    #endif
}
