//
//  isiOSAppOnMac.swift
//  Pyto
//
//  Created by administrator on 12/14/20.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import Foundation

@objc class MacSupport: NSObject {
    
    @objc static let isRunningOnMac = isiOSAppOnMac
}

var isiOSAppOnMac: Bool {
    return ProcessInfo.processInfo.isiOSAppOnMac
}
