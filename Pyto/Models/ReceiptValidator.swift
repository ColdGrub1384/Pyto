//
//  ReceiptValidator.swift
//  Pyto
//
//  Created by Adrian Labbé on 04-06-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

import Foundation
import StoreKit

#if MAIN

fileprivate func readASN1Data(ptr: UnsafePointer<UInt8>, length: Int) -> Data {
    return Data(bytes: ptr, count: length)
}

fileprivate func readASN1Integer(ptr: inout UnsafePointer<UInt8>?, maxLength: Int) -> Int? {
    var type: Int32 = 0
    var xclass: Int32 = 0
    var length: Int = 0
  
    ASN1_get_object(&ptr, &length, &type, &xclass, maxLength)
    guard type == V_ASN1_INTEGER else {
        return nil
    }
    let integerObject = c2i_ASN1_INTEGER(nil, &ptr, length)
    let intValue = ASN1_INTEGER_get(integerObject)
    ASN1_INTEGER_free(integerObject)
  
    return intValue
}

fileprivate func readASN1String(ptr: inout UnsafePointer<UInt8>?, maxLength: Int) -> String? {
    var strClass: Int32 = 0
    var strLength = 0
    var strType: Int32 = 0
  
    var strPointer = ptr
    ASN1_get_object(&strPointer, &strLength, &strType, &strClass, maxLength)
    if strType == V_ASN1_UTF8STRING {
        let p = UnsafeMutableRawPointer(mutating: strPointer!)
        let utfString = String(bytesNoCopy: p, length: strLength, encoding: .utf8, freeWhenDone: false)
        return utfString
    }
    
    if strType == V_ASN1_IA5STRING {
        let p = UnsafeMutablePointer(mutating: strPointer!)
        let ia5String = String(bytesNoCopy: p, length: strLength, encoding: .ascii, freeWhenDone: false)
        return ia5String
    }
  
    return nil
}

fileprivate func readASN1Date(ptr: inout UnsafePointer<UInt8>?, maxLength: Int) -> Date? {
    var str_xclass: Int32 = 0
    var str_length = 0
    var str_type: Int32 = 0
  
    // A date formatter to handle RFC 3339 dates in the GMT time zone
    let formatter = DateFormatter()
    formatter.locale = Locale(identifier: "en_US_POSIX")
    formatter.dateFormat = "yyyy'-'MM'-'dd'T'HH':'mm':'ss'Z'"
    formatter.timeZone = TimeZone(abbreviation: "GMT")
  
    var strPointer = ptr
    ASN1_get_object(&strPointer, &str_length, &str_type, &str_xclass, maxLength)
    guard str_type == V_ASN1_IA5STRING else {
        return nil
    }

    let p = UnsafeMutableRawPointer(mutating: strPointer!)
    if let dateString = String(bytesNoCopy: p, length: str_length, encoding: .ascii, freeWhenDone: false) {
        return formatter.date(from: dateString)
    }

    return nil
}

/// An on device receipt validator.
struct ReceiptValidator {
    
    init?() {
        guard let receipt = ReceiptValidator.loadReceipt() else {
            return nil
        }

        guard ReceiptValidator.validateSigning(receipt) else {
            return nil
        }
        
        self.receipt = ReceiptValidator.readReceipt(receipt)
    }
    
    private static func loadReceipt() -> UnsafeMutablePointer<PKCS7>? {
                
        guard let receiptUrl = Bundle.main.appStoreReceiptURL, let receiptData = try? Data(contentsOf: receiptUrl) else {
            return nil
        }
        
        // 1
        let receiptBIO = BIO_new(BIO_s_mem())
        let receiptBytes: [UInt8] = .init(receiptData)
        BIO_write(receiptBIO, receiptBytes, Int32(receiptData.count))
        // 2
        let receiptPKCS7 = d2i_PKCS7_bio(receiptBIO, nil)
        BIO_free(receiptBIO)
        // 3
        guard receiptPKCS7 != nil else {
            return nil
        }
        
        // Check that the container has a signature
        guard OBJ_obj2nid(receiptPKCS7!.pointee.type) == NID_pkcs7_signed else {
            return nil
        }

        // Check that the container contains data
        let receiptContents = receiptPKCS7!.pointee.d.sign.pointee.contents
        guard OBJ_obj2nid(receiptContents?.pointee.type) == NID_pkcs7_data else {
            return nil
        }

        return receiptPKCS7
    }
    
    private static func validateSigning(_ receipt: UnsafeMutablePointer<PKCS7>?) -> Bool {
        guard let rootCertUrl = Bundle.main.url(forResource: "AppleIncRootCertificate", withExtension: "cer"), let rootCertData = try? Data(contentsOf: rootCertUrl) else {
            return false
        }
          
        let rootCertBio = BIO_new(BIO_s_mem())
        let rootCertBytes: [UInt8] = .init(rootCertData)
        BIO_write(rootCertBio, rootCertBytes, Int32(rootCertData.count))
        let rootCertX509 = d2i_X509_bio(rootCertBio, nil)
        BIO_free(rootCertBio)
        
        // 1
        let store = X509_STORE_new()
        X509_STORE_add_cert(store, rootCertX509)

        // 2
        SSL_library_init()
        OpenSSL_add_all_digests()

        // 3
        let verificationResult = PKCS7_verify(receipt, nil, store, nil, nil, 0)
        guard verificationResult == 1  else {
            return false
        }

        return true
    }
    
    /// Fields in the app receipt.
    enum ReceiptField {

        /// Bundle ID
        case bundleID

        /// Bundle version
        case bundleVersion

        /// Receipt data
        case opaqueData
        
        /// Hash data
        case hashData
        
        /// Creation date
        case creationDate
        
        /// Original app version
        case originalAppVersion
        
        /// Expiration date
        case expirationDate
        
        /// In App Purchase receipt
        case inApp
    }
    
    fileprivate static func readReceipt(_ receiptPKCS7: UnsafeMutablePointer<PKCS7>?) -> [ReceiptField:Any] {
        // Get a pointer to the start and end of the ASN.1 payload
        let receiptSign = receiptPKCS7?.pointee.d.sign
        let octets = receiptSign?.pointee.contents.pointee.d.data
        var ptr = UnsafePointer(octets?.pointee.data)
        let end = ptr!.advanced(by: Int(octets!.pointee.length))
        
        var type: Int32 = 0
        var xclass: Int32 = 0
        var length: Int = 0

        ASN1_get_object(&ptr, &length, &type, &xclass, ptr!.distance(to: end))
        guard type == V_ASN1_SET else {
            return [:]
        }
        
        var dict = [ReceiptField:Any]()
        var iaps = [RMAppReceiptIAP]()
        
        // 1
        while ptr! < end {
            // 2
            ASN1_get_object(&ptr, &length, &type, &xclass, ptr!.distance(to: end))
            guard type == V_ASN1_SEQUENCE else {
                return [:]
            }
              
            // 3
            guard let attributeType = readASN1Integer(ptr: &ptr, maxLength: length) else {
                return [:]
            }
              
            // 4
            guard let _ = readASN1Integer(ptr: &ptr, maxLength: ptr!.distance(to: end)) else {
                return [:]
            }
              
            // 5
            ASN1_get_object(&ptr, &length, &type, &xclass, ptr!.distance(to: end))
            guard type == V_ASN1_OCTET_STRING else {
                return [:]
            }
            
            switch attributeType {
            case 2: // The bundle identifier
                var stringStartPtr = ptr
                dict[.bundleID] = readASN1String(ptr: &stringStartPtr, maxLength: length)
            case 3: // Bundle version
                var stringStartPtr = ptr
                dict[.bundleVersion] = readASN1String(ptr: &stringStartPtr, maxLength: length)
              
            case 4: // Opaque value
                dict[.opaqueData] = readASN1Data(ptr: ptr!, length: length)
              
            case 5: // Computed GUID (SHA-1 Hash)
                let dataStartPtr = ptr!
                dict[.hashData] = readASN1Data(ptr: dataStartPtr, length: length)
              
            case 12: // Receipt Creation Date
                var dateStartPtr = ptr
                dict[.creationDate] = readASN1Date(ptr: &dateStartPtr, maxLength: length)

            case 17: // IAP Receipt
                let dataStartPtr = ptr!
                iaps.append(RMAppReceiptIAP(asn1Data: readASN1Data(ptr: dataStartPtr, length: length)))
            case 19: // Original App Version
                var stringStartPtr = ptr
                dict[.originalAppVersion] = readASN1String(ptr: &stringStartPtr, maxLength: length)
              
            case 21: // Expiration Date
                var dateStartPtr = ptr
                dict[.expirationDate] = readASN1Date(ptr: &dateStartPtr, maxLength: length)
              
            default: // Ignore other attributes in receipt
                print("Not processing attribute type: \(attributeType)")
            }

            // Advance pointer to the next item
            ptr = ptr!.advanced(by: length)
        }
        
        dict[.inApp] = iaps
        return dict
    }
    
    /// A dictionary containing the receipt's data.
    let receipt: [ReceiptField:Any]
    
    /// The free trial expiration date.
    var trialExpirationDate: Date? {
        for inApp in (receipt[.inApp] as? [RMAppReceiptIAP]) ?? [] {
            if inApp.productIdentifier.hasSuffix("freetrial") {
                return inApp.originalPurchaseDate
            }
        }
        
        return nil
    }
}
#endif
