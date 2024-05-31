//
//  DeviceLayout.swift
//  PytoUI Interface Builder
//
//  Created by Emma on 01-07-22.
//
// https://www.screensizes.app/

import UIKit

/// An enumeration of iOS devices and their properties to use for preview.
public enum DeviceLayout: CaseIterable, Codable {
    
    public var symbol: UIImage? {
        if userInterfaceIdiom == .phone && homeIndicatorHeight == 0 {
            return UIImage(systemName: "iphone.homebutton") // iPhone with home button
        } else if userInterfaceIdiom == .phone && homeIndicatorHeight > 0 {
            return UIImage(systemName: "iphone") // iPhone without home button
        } else if userInterfaceIdiom == .pad && homeIndicatorHeight == 0 {
            return UIImage(systemName: "ipad.homebutton") // iPad with home button
        } else {
            return UIImage(systemName: "ipad") // iPad without home button
        }
    }
    
    public var userInterfaceIdiom: UIUserInterfaceIdiom {
        switch self {
        case .iPhoneSE1, .iPhoneSE3, .iPhone8Plus, .iPhone13Mini, .iPhone13Pro, .iPhone11, .iPhone11ProMax, .iPhone13ProMax:
            return .phone
        case .iPad97, .iPad, .iPadPro10_5, .iPadPro12_9, .iPadMini, .iPadAir, .iPadPro11, .iPadPro12_9_5:
            return .pad
        }
    }
    
    public var hasNotch: Bool {
        userInterfaceIdiom == .phone && statusBarHeight > 20
    }
    
    public var homeIndicatorHeight: CGFloat {
        switch self {
        case .iPhoneSE1, .iPhoneSE3, .iPhone8Plus, .iPad97, .iPad, .iPadPro10_5, .iPadPro12_9:
            return 0
        case .iPhone13Mini, .iPhone13Pro, .iPhone11, .iPhone11ProMax, .iPhone13ProMax:
            return 34
        case .iPadMini, .iPadAir, .iPadPro11, .iPadPro12_9_5:
            return 20
        }
    }
    
    public var statusBarHeight: CGFloat {
        switch self {
        case .iPhoneSE1:
            return 20
        case .iPhoneSE3:
            return 20
        case .iPhone8Plus:
            return 20
        case .iPhone13Mini:
            return 50
        case .iPhone13Pro:
            return 47
        case .iPhone11:
            return 48
        case .iPhone11ProMax:
            return 44
        case .iPhone13ProMax:
            return 47
            
        case .iPad97:
            return 20
        case .iPad:
            return 20
        case .iPadPro10_5:
            return 20
        case .iPadPro12_9:
            return 20
        case .iPadMini:
            return 24
        case .iPadAir:
            return 24
        case .iPadPro11:
            return 24
        case .iPadPro12_9_5:
            return 24
        }
    }
    
    public var size: CGSize {
        switch self {
        case .iPhoneSE1:
            return CGSize(width: 320, height: 568)
        case .iPhoneSE3:
            return CGSize(width: 375, height: 667)
        case .iPhone8Plus:
            return CGSize(width: 414, height: 736)
        case .iPhone13Mini:
            return CGSize(width: 375, height: 812)
        case .iPhone13Pro:
            return CGSize(width: 390, height: 844)
        case .iPhone11:
            return CGSize(width: 414, height: 896)
        case .iPhone11ProMax:
            return CGSize(width: 414, height: 896)
        case .iPhone13ProMax:
            return CGSize(width: 428, height: 926)
            
        case .iPad97:
            return CGSize(width: 768, height: 1024)
        case .iPad:
            return CGSize(width: 810, height: 1080)
        case .iPadPro10_5:
            return CGSize(width: 834, height: 1112)
        case .iPadPro12_9:
            return CGSize(width: 1024, height: 1366)
        case .iPadMini:
            return CGSize(width: 744, height: 1133)
        case .iPadAir:
            return CGSize(width: 820, height: 1180)
        case .iPadPro11:
            return CGSize(width: 834, height: 1194)
        case .iPadPro12_9_5:
            return CGSize(width: 1024, height: 1366)
        }
    }
    
    public var name: String {
        switch self {
        case .iPhoneSE1:
            return "iPhone SE (1st generation)"
        case .iPhoneSE3:
            return "iPhone SE (3rd generation)"
        case .iPhone8Plus:
            return "iPhone 8 Plus"
        case .iPhone13Mini:
            return "iPhone 13 Mini"
        case .iPhone13Pro:
            return "iPhone 13 Pro"
        case .iPhone11:
            return "iPhone 11"
        case .iPhone11ProMax:
            return "iPhone 11 Pro Max"
        case .iPhone13ProMax:
            return "iPhone 13 Pro Max"
            
        case .iPad97:
            return "iPad 9.7\""
        case .iPad:
            return "iPad"
        case .iPadPro10_5:
            return "iPad Pro 10.5\""
        case .iPadPro12_9:
            return "iPad Pro 12.9\""
        case .iPadMini:
            return "iPad Mini"
        case .iPadAir:
            return "iPad Air"
        case .iPadPro11:
            return "iPad Pro 11\""
        case .iPadPro12_9_5:
            return "iPad Pro 12.9\" (5th generation)"
        }
    }
    
    case iPhoneSE1
    case iPhoneSE3
    case iPhone8Plus
    case iPhone13Mini
    case iPhone13Pro
    case iPhone11
    case iPhone11ProMax
    case iPhone13ProMax
    
    case iPad97
    case iPad
    case iPadPro10_5
    case iPadPro12_9
    case iPadMini
    case iPadAir
    case iPadPro11
    case iPadPro12_9_5
}
