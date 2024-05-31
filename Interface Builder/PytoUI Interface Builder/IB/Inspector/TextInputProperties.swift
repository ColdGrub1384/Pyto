//
//  TextInputProperties.swift
//  InterfaceBuilder
//
//  Created by Emma on 06-09-22.
//

import UIKit

/// Properties for text input.
let TextInputProperties = [
    InspectorProperty(name: "Auto Correction",
                      valueType: .enumeration([
                        "Default",
                        "Yes",
                        "No"
                      ]), getValue: { view in
                          
                          guard let input = view as? UITextInput else {
                              return .init(value: nil)
                          }
                          
                          let value: String
                          switch input.autocorrectionType {
                          case .default: value = "Default"
                          case .yes: value = "Yes"
                          case .no: value = "No"
                          default: value = "Default"
                          }
                          
                          return .init(value: value)
                      }, handler: { view, value in
                          
                          var textField = view as? UITextField
                          var textView = view as? UITextView
                          
                          func setValue(_ value: UITextAutocorrectionType) {
                              textField?.autocorrectionType = value
                              textView?.autocorrectionType = value
                          }
                          
                          switch value.value as? String {
                          case "Default": setValue(.default)
                          case "Yes": setValue(.yes)
                          case "No": setValue(.no)
                          default:
                              break
                          }
                      }),
    
    InspectorProperty(name: "Auto Capitalization",
                      valueType: .enumeration([
                        "None",
                        "All Characters",
                        "Sentences",
                        "Words"
                      ]), getValue: { view in
                          guard let input = view as? UITextInput else {
                              return .init(value: nil)
                          }
                          
                          let value: String
                          switch input.autocapitalizationType {
                          case .none?: value = "None"
                          case .allCharacters: value = "All Characters"
                          case .words: value = "Words"
                          case .sentences: value = "Sentences"
                          default: value = "None"
                          }
                          
                          return .init(value: value)
                      }, handler: { view, value in
                          
                          var textField = view as? UITextField
                          var textView = view as? UITextView
                          
                          func setValue(_ value: UITextAutocapitalizationType) {
                              textField?.autocapitalizationType = value
                              textView?.autocapitalizationType = value
                          }
                          
                          switch value.value as? String {
                          case "None": setValue(.none)
                          case "All Characters": setValue(.allCharacters)
                          case "Sentences": setValue(.sentences)
                          case "Words": setValue(.words)
                          default:
                              break
                          }
                      }),
    
    InspectorProperty(name: "Smart Dashes",
                      valueType: .enumeration([
                        "Default",
                        "Yes",
                        "No",
                      ]), getValue: { view in
                          guard let input = view as? UITextInput else {
                              return .init(value: nil)
                          }
                          
                          let value: String
                          switch input.smartDashesType {
                          case .default: value = "Default"
                          case .yes: value = "Yes"
                          case .no: value = "No"
                          default: value = "Default"
                          }
                          
                          return .init(value: value)
                      }, handler: { view, value in
                          
                          var textField = view as? UITextField
                          var textView = view as? UITextView
                          
                          func setValue(_ value: UITextSmartDashesType) {
                              textField?.smartDashesType = value
                              textView?.smartDashesType = value
                          }
                          
                          switch value.value as? String {
                          case "Default": setValue(.default)
                          case "Yes": setValue(.yes)
                          case "No": setValue(.no)
                          default:
                              break
                          }
                      }),
    
    InspectorProperty(name: "Smart Quotes",
                      valueType: .enumeration([
                        "Default",
                        "Yes",
                        "No",
                      ]), getValue: { view in
                          guard let input = view as? UITextInput else {
                              return .init(value: nil)
                          }
                          
                          let value: String
                          switch input.smartQuotesType {
                          case .default: value = "Default"
                          case .yes: value = "Yes"
                          case .no: value = "No"
                          default: value = "Default"
                          }
                          
                          return .init(value: value)
                      }, handler: { view, value in
                          
                          var textField = view as? UITextField
                          var textView = view as? UITextView
                          
                          func setValue(_ value: UITextSmartQuotesType) {
                              textField?.smartQuotesType = value
                              textView?.smartQuotesType = value
                          }
                          
                          switch value.value as? String {
                          case "Default": setValue(.default)
                          case "Yes": setValue(.yes)
                          case "No": setValue(.no)
                          default:
                              break
                          }
                      }),
]
