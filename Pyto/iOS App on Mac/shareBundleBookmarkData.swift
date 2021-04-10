//
//  shareBundleBookmarkData.swift
//  Pyto
//
//  Created by Emma Labbé on 14-01-21.
//  Copyright © 2021 Emma Labbé. All rights reserved.
//

import UIKit

// 'WidgetExtension' doesn't have the permission to read the main bundle on macOS, so we share a bookmark data.

// For Automator, we share a caches directory.

func shareBundleBookmarkData() {
    
    guard isiOSAppOnMac else {
        return
    }
    
    do {
        let data = try Bundle.main.bundleURL.bookmarkData()
        UserDefaults.shared?.setValue(data, forKey: "sharedBundleURL")
    } catch {
        print(error.localizedDescription)
    }
}
