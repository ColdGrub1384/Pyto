//
//  isiOSAppOnMac.swift
//  Pyto
//
//  Created by administrator on 12/14/20.
//  Copyright © 2020 Emma Labbé. All rights reserved.
//

import Foundation

// So we just have to check one condition and not both if iOS 14 is available AND iOS App on Mac
var isiOSAppOnMac: Bool {
    if #available(iOS 14.0, *) {
        return ProcessInfo.processInfo.isiOSAppOnMac
    } else {
        return false
    }
}
