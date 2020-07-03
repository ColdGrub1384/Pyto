//
//  BlockBasedSelector.swift
//  Parking
//
//  Created by Charlton Provatas on 11/9/17.
//  Copyright © 2017 Charlton Provatas. All rights reserved.
//

import Foundation
// swiftlint:disable identifier_name
func Selector(_ block: @escaping () -> Void) -> Selector {
    let selector = NSSelectorFromString("\(CFAbsoluteTimeGetCurrent())")
    class_addMethodWithBlock(_Selector.self, selector) { _ in block() }
    return selector
}

/// used w/ callback if you need to get sender argument
func Selector(_ block: @escaping (Any?) -> Void) -> Selector {
    let selector = NSSelectorFromString("\(CFAbsoluteTimeGetCurrent())")
    class_addMethodWithBlockAndSender(_Selector.self, selector) { (_, sender) in block(sender) }
    return selector
}

// swiftlint:disable identifier_name
let Selector = _Selector.shared
@objc class _Selector: NSObject {
    @objc static let shared = _Selector()
}
