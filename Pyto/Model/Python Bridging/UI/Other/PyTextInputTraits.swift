//
//  PyTextInputTraits.swift
//  Pyto
//
//  Created by Emma Labbé on 19-07-19.
//  Copyright © 2018-2021 Emma Labbé. All rights reserved.
//

import UIKit

@available(iOS 13.0, *) @objc public class PyTextInputTraitsConstants: NSObject {
    
    @objc public static let KeyboardAppearanceDefault = UIKeyboardAppearance.default
    
    @objc public static let KeyboardAppearanceLight = UIKeyboardAppearance.light
    
    @objc public static let KeyboardAppearanceDark = UIKeyboardAppearance.dark
    
    
    @objc public static let KeyboardTypeDefault = UIKeyboardType.default
    
    @objc public static let KeyboardTypeAlphabet = UIKeyboardType.alphabet
    
    @objc public static let KeyboardTypeAsciiCapable = UIKeyboardType.asciiCapable
    
    @objc public static let KeyboardTypeAsciiCapableNumberPad = UIKeyboardType.asciiCapableNumberPad
    
    @objc public static let KeyboardTypeDecimalPad = UIKeyboardType.decimalPad
    
    @objc public static let KeyboardTypeEmailAddress = UIKeyboardType.emailAddress
    
    @objc public static let KeyboardTypeNamePhonePad = UIKeyboardType.namePhonePad
    
    @objc public static let KeyboardTypeNumberPad = UIKeyboardType.numberPad
    
    @objc public static let KeyboardTypeNumbersAndPunctuation = UIKeyboardType.numbersAndPunctuation
    
    @objc public static let KeyboardTypePhonePad = UIKeyboardType.phonePad
    
    @objc public static let KeyboardTypeTwitter = UIKeyboardType.twitter
    
    @objc public static let KeyboardTypeURL = UIKeyboardType.URL
    
    @objc public static let KeyboardTypeWebSearch = UIKeyboardType.webSearch
    
    
    @objc public static let ReturnKeyTypeDefault = UIReturnKeyType.default
    
    @objc public static let ReturnKeyTypeContinue = UIReturnKeyType.continue
    
    @objc public static let ReturnKeyTypeDone = UIReturnKeyType.done
    
    @objc public static let ReturnKeyTypeEmergencyCall = UIReturnKeyType.emergencyCall
    
    @objc public static let ReturnKeyTypeGo = UIReturnKeyType.go
    
    @objc public static let ReturnKeyTypeGoogle = UIReturnKeyType.google
    
    @objc public static let ReturnKeyTypeJoin = UIReturnKeyType.join
    
    @objc public static let ReturnKeyTypeNext = UIReturnKeyType.next
    
    @objc public static let ReturnKeyTypeRoute = UIReturnKeyType.route
    
    @objc public static let ReturnKeyTypeSearch = UIReturnKeyType.search
    
    @objc public static let ReturnKeyTypeSend = UIReturnKeyType.send
    
    @objc public static let ReturnKeyTypeYahoo = UIReturnKeyType.yahoo
    
    
    @objc public static let AutocapitalizationTypeNone = UITextAutocapitalizationType.none
    
    @objc public static let AutocapitalizationTypeAllCharacters = UITextAutocapitalizationType.allCharacters
    
    @objc public static let AutocapitalizationTypeSentences = UITextAutocapitalizationType.sentences
    
    @objc public static let AutocapitalizationTypeWords = UITextAutocapitalizationType.words

}

@objc public protocol TextInputTraits {
    
    @objc var _smartDashesType: UITextSmartDashesType { get set }
    
    @objc var _smartQuotesType: UITextSmartQuotesType { get set }
    
    @objc var _keyboardType: UIKeyboardType { get set }
    
    @objc var _returnKeyType: UIReturnKeyType { get set }
    
    @objc var _keyboardAppearance: UIKeyboardAppearance { get set }
    
    @objc var _isSecureTextEntry: Bool { get set }
    
    @objc var _autocapitalizationType: UITextAutocapitalizationType { get set }
    
     @objc var _autocorrectionType: UITextAutocorrectionType { get set }
}

extension UITextView: TextInputTraits {
    public var _smartDashesType: UITextSmartDashesType {
        get {
            return self.smartDashesType
        }
        set {
            self.smartDashesType = newValue
        }
    }
    
    public var _smartQuotesType: UITextSmartQuotesType {
        get {
            return self.smartQuotesType
        }
        set {
            self.smartQuotesType = newValue
        }
    }
    
    public var _keyboardType: UIKeyboardType {
        get {
            return self.keyboardType
        }
        set {
            self.keyboardType = newValue
        }
    }
    
    public var _returnKeyType: UIReturnKeyType {
        get {
            return self.returnKeyType
        }
        set {
            self.returnKeyType = newValue
        }
    }
    
    public var _keyboardAppearance: UIKeyboardAppearance {
        get {
            return self.keyboardAppearance
        }
        set {
            self.keyboardAppearance = newValue
        }
    }
    
    public var _isSecureTextEntry: Bool {
        get {
            return self.isSecureTextEntry
        }
        set {
            self.isSecureTextEntry = newValue
        }
    }
    
    public var _autocapitalizationType: UITextAutocapitalizationType {
        get {
            return self.autocapitalizationType
        }
        set {
            self.autocapitalizationType = newValue
        }
    }
    
    public var _autocorrectionType: UITextAutocorrectionType {
        get {
            return self.autocorrectionType
        }
        set {
            self.autocorrectionType = newValue
        }
    }
}
extension UITextField: TextInputTraits {
    public var _smartDashesType: UITextSmartDashesType {
        get {
            return self.smartDashesType
        }
        set {
            self.smartDashesType = newValue
        }
    }
    
    public var _smartQuotesType: UITextSmartQuotesType {
        get {
            return self.smartQuotesType
        }
        set {
            self.smartQuotesType = newValue
        }
    }
    
    public var _keyboardType: UIKeyboardType {
        get {
            return self.keyboardType
        }
        set {
            self.keyboardType = newValue
        }
    }
    
    public var _returnKeyType: UIReturnKeyType {
        get {
            return self.returnKeyType
        }
        set {
            self.returnKeyType = newValue
        }
    }
    
    public var _keyboardAppearance: UIKeyboardAppearance {
        get {
            return self.keyboardAppearance
        }
        set {
            self.keyboardAppearance = newValue
        }
    }
    
    public var _isSecureTextEntry: Bool {
        get {
            return self.isSecureTextEntry
        }
        set {
            self.isSecureTextEntry = newValue
        }
    }
    
    public var _autocapitalizationType: UITextAutocapitalizationType {
        get {
            self.autocapitalizationType
        }
        set {
            self.autocapitalizationType = newValue
        }
    }
    
    public var _autocorrectionType: UITextAutocorrectionType {
        get {
            return self.autocorrectionType
        }
        set {
            self.autocorrectionType = newValue
        }
    }
}

@available(iOS 13.0, *) @objc public protocol PyTextInputTraits: NSObjectProtocol {
    
    @objc var textInputTraits: TextInputTraits { get }
    
    @objc var smartDashes: Bool { get set }
    
    @objc var smartQuotes: Bool { get set }
    
    @objc var keyboardType: UIKeyboardType { get set }
    
    @objc var returnKeyType: UIReturnKeyType { get set }
    
    @objc var keyboardAppearance: UIKeyboardAppearance { get set }
    
    @objc var isSecureTextEntry: Bool { get set }
    
    @objc var autocapitalizationType: UITextAutocapitalizationType { get set }
    
    @objc var autocorrection: Bool { get set }
}

@available(iOS 13.0, *)
extension PyTextView {
    
    @objc public var textInputTraits: TextInputTraits {
        return get {
            return self.textView
        }
    }
    
    @objc public var smartDashes: Bool {
        get {
            return PyWrapper.get {
                return (self.textInputTraits._smartDashesType == .yes || self.textInputTraits._smartDashesType == .default)
            }
        }
        
        set {
            PyWrapper.set {
                if newValue {
                    self.textInputTraits._smartDashesType = .yes
                } else {
                    self.textInputTraits._smartDashesType = .no
                }
            }
        }
    }
    
    @objc public var smartQuotes: Bool {
        get {
            return PyWrapper.get {
                return (self.textInputTraits._smartQuotesType == .yes || self.textInputTraits._smartQuotesType == .default)
            }
        }
        
        set {
            PyWrapper.set {
                if newValue {
                    self.textInputTraits._smartQuotesType = .yes
                } else {
                    self.textInputTraits._smartQuotesType = .no
                }
            }
        }
    }
    
    @objc public var keyboardType: UIKeyboardType {
        get {
            return PyWrapper.get {
                return self.textInputTraits._keyboardType
            }
        }
        
        set {
            PyWrapper.set {
                self.textInputTraits._keyboardType = newValue
            }
        }
    }
    
    @objc public var keyboardAppearance: UIKeyboardAppearance {
        get {
            return PyWrapper.get {
                return self.textInputTraits._keyboardAppearance
            }
        }
        
        set {
            PyWrapper.set {
                self.textInputTraits._keyboardAppearance = newValue
            }
        }
    }
    
    @objc public var returnKeyType: UIReturnKeyType {
        get {
            return PyWrapper.get {
                return self.textInputTraits._returnKeyType
            }
        }
        
        set {
            PyWrapper.set {
                self.textInputTraits._returnKeyType = newValue
            }
        }
    }
    
    @objc public var isSecureTextEntry: Bool {
        get {
            return PyWrapper.get {
                return self.textInputTraits._isSecureTextEntry
            }
        }
        
        set {
            PyWrapper.set {
                self.textInputTraits._isSecureTextEntry = newValue
            }
        }
    }
    
    @objc public var autocapitalizationType: UITextAutocapitalizationType {
        get {
            return PyWrapper.get {
                return self.textInputTraits._autocapitalizationType
            }
        }
        
        set {
            PyWrapper.set {
                self.textInputTraits._autocapitalizationType = newValue
            }
        }
    }
    
    @objc public var autocorrection: Bool {
        get {
            return PyWrapper.get {
                return (self.textInputTraits._autocorrectionType == .default || self.textInputTraits._autocorrectionType == .yes)
            }
        }
        set {
            PyWrapper.set {
                if newValue {
                    self.textInputTraits._autocorrectionType = .yes
                } else {
                    self.textInputTraits._autocorrectionType = .no
                }
            }
        }
    }
}

@available(iOS 13.0, *)
extension PyTextField {
    
    @objc public var textInputTraits: TextInputTraits {
        return get {
            return self.textField
        }
    }
    
    @objc public var smartDashes: Bool {
        get {
            return PyWrapper.get {
                return (self.textInputTraits._smartDashesType == .yes || self.textInputTraits._smartDashesType == .default)
            }
        }
        
        set {
            PyWrapper.set {
                if newValue {
                    self.textInputTraits._smartDashesType = .yes
                } else {
                    self.textInputTraits._smartDashesType = .no
                }
            }
        }
    }
    
    @objc public var smartQuotes: Bool {
        get {
            return PyWrapper.get {
                return (self.textInputTraits._smartQuotesType == .yes || self.textInputTraits._smartQuotesType == .default)
            }
        }
        
        set {
            PyWrapper.set {
                if newValue {
                    self.textInputTraits._smartQuotesType = .yes
                } else {
                    self.textInputTraits._smartQuotesType = .no
                }
            }
        }
    }
    
    @objc public var keyboardType: UIKeyboardType {
        get {
            return PyWrapper.get {
                return self.textInputTraits._keyboardType
            }
        }
        
        set {
            PyWrapper.set {
                self.textInputTraits._keyboardType = newValue
            }
        }
    }
    
    @objc public var keyboardAppearance: UIKeyboardAppearance {
        get {
            return PyWrapper.get {
                return self.textInputTraits._keyboardAppearance
            }
        }
        
        set {
            PyWrapper.set {
                self.textInputTraits._keyboardAppearance = newValue
            }
        }
    }
    
    @objc public var returnKeyType: UIReturnKeyType {
        get {
            return PyWrapper.get {
                return self.textInputTraits._returnKeyType
            }
        }
        
        set {
            PyWrapper.set {
                self.textInputTraits._returnKeyType = newValue
            }
        }
    }
    
    @objc public var isSecureTextEntry: Bool {
        get {
            return PyWrapper.get {
                return self.textInputTraits._isSecureTextEntry
            }
        }
        
        set {
            PyWrapper.set {
                self.textInputTraits._isSecureTextEntry = newValue
            }
        }
    }
    
    @objc public var autocapitalizationType: UITextAutocapitalizationType {
        get {
            return PyWrapper.get {
                return self.textInputTraits._autocapitalizationType
            }
        }
        
        set {
            PyWrapper.set {
                self.textInputTraits._autocapitalizationType = newValue
            }
        }
    }
    
    @objc public var autocorrection: Bool {
        get {
            return PyWrapper.get {
                return (self.textInputTraits._autocorrectionType == .default || self.textInputTraits._autocorrectionType == .yes)
            }
        }
        set {
            PyWrapper.set {
                if newValue {
                    self.textInputTraits._autocorrectionType = .yes
                } else {
                    self.textInputTraits._autocorrectionType = .no
                }
            }
        }
    }
}
