Objective-C
===========

Pyto has the `Rubicon-ObjC <https://rubicon-objc.readthedocs.io>`_ library as its bridge between Python and Objective-C. See the `documentation <https://rubicon-objc.readthedocs.io/en/latest/tutorial/index.html>`_ for more information.

To make the usage of Objective-C classes easier, Pyto has the iOS system frameworks as modules containing a list of classes.

Usage
-----

.. highlight:: python
.. code-block:: python
    
    from Foundation import NSBundle
    bundle_path = str(NSBundle.mainBundle.bundleURL.path)

Frameworks
----------

These are the frameworks that can be imported directly in Pyto.

- Accounts
- AGXMetalA10
- AudioToolbox
- AuthenticationServices
- AVFAudio
- AVFoundation
- AVKit
- AXSpeechImplementation
- BackgroundTasks
- CallKit
- CFNetwork
- ClassKit
- CloudDocsFileProvider
- CloudKit
- Combine
- Contacts
- ContactsUI
- CoreAudio
- CoreBluetooth
- CoreData
- CoreFoundation
- CoreHaptics
- CoreImage
- CoreLocation
- CoreMedia
- CoreMIDI
- CoreML
- CoreMotion
- CoreServices
- CoreSpotlight
- CoreTelephony
- CoreText
- CryptoTokenKit
- EventKit
- ExposureNotification
- ExternalAccessory
- FileProvider
- FileProviderOverride
- Foundation
- HealthKit
- ImageCaptureCore
- Intents
- IntentsUI
- IOKit
- IOSurface
- JavaScriptCore
- lib
- LinkPresentation
- LocalAuthentication
- MapKit
- MediaPlayer
- MediaToolbox
- MessageUI
- Metal
- MetalKit
- MLCompute
- MPSCore
- MPSImage
- MPSMatrix
- MPSNDArray
- MPSNeuralNetwork
- MPSRayIntersector
- MultipeerConnectivity
- NaturalLanguage
- Network
- NetworkExtension
- NotificationCenter
- OpenGLES
- PDFKit
- PencilKit
- Photos
- PushKit
- QuartzCore
- QuickLook
- QuickLookThumbnailing
- SafariServices
- Security
- SharedUtils
- SoundAnalysis
- Speech
- StoreKit
- swift
- SwiftUI
- system
- UIKit
- UniformTypeIdentifiers
- UserNotifications
- vecLib
- VideoSubscriberAccount
- VideoToolbox
- Vision
- WatchConnectivity
- WebKit
- WidgetKit
