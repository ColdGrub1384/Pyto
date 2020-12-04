project 'Pyto.xcodeproj'

# Uncomment the next line to define a global platform for your project
# platform :ios, '9.0'

target 'Pyto' do

  # Comment the next line if you're not using Swift and don't want to use dynamic frameworks
  use_frameworks!

  # Pods for Pyto

  inhibit_all_warnings!

  pod 'SplitKit', :git => 'https://github.com/ColdGrub1384/SplitKit.git'
  pod 'SourceEditor', :git => 'https://github.com/ColdGrub1384/source-editor.git'
  pod 'Zip'
  pod 'Down', :git => 'https://github.com/ColdGrub1384/Down.git'
  pod 'FileBrowser', :git => 'https://github.com/ColdGrub1384/FileBrowser.git'
  pod "Color-Picker-for-iOS", :git => 'https://github.com/ColdGrub1384/Color-Picker-for-iOS.git'
  pod 'MultiPeer'
  pod 'SwiftyStoreKit'
  pod 'ObjectUserDefaults'
  pod 'TrueTime'
  pod 'Highlightr', :git => 'https://github.com/brunophilipe/Highlightr.git'
end

<<<<<<< HEAD
=======
target 'Pyto Xcode 11' do
  # Comment the next line if you're not using Swift and don't want to use dynamic frameworks
  use_frameworks!

  # Pods for Pyto

  inhibit_all_warnings!

  pod 'SplitKit', :git => 'https://github.com/ColdGrub1384/SplitKit.git'
  pod 'SourceEditor', :git => 'https://github.com/ColdGrub1384/source-editor.git'
  pod 'Zip'
  pod 'Down', :git => 'https://github.com/ColdGrub1384/Down.git'
  pod 'FileBrowser', :git => 'https://github.com/ColdGrub1384/FileBrowser.git'
  pod "Color-Picker-for-iOS", :git => 'https://github.com/ColdGrub1384/Color-Picker-for-iOS.git'
  pod 'MultiPeer'
  pod 'SwiftyStoreKit'
  pod 'ObjectUserDefaults'
  pod 'TrueTime'
  pod 'Highlightr', :git => 'https://github.com/brunophilipe/Highlightr.git'
end

>>>>>>> 9ec484051b222280c44a9356f1eb31cfa9a71619
target 'Pyto Screenshots' do
  # Comment the next line if you're not using Swift and don't want to use dynamic frameworks
  use_frameworks!

  # Pods for Pyto

  inhibit_all_warnings!

  pod 'SplitKit', :git => 'https://github.com/ColdGrub1384/SplitKit.git'
  pod 'SourceEditor', :git => 'https://github.com/ColdGrub1384/source-editor.git'
  pod 'Zip'
  pod 'Down', :git => 'https://github.com/ColdGrub1384/Down.git'
  pod 'FileBrowser', :git => 'https://github.com/ColdGrub1384/FileBrowser.git'
  pod "Color-Picker-for-iOS", :git => 'https://github.com/ColdGrub1384/Color-Picker-for-iOS.git'
  pod 'MultiPeer'
  pod 'SwiftyStoreKit'
  pod 'ObjectUserDefaults'
  pod 'TrueTime'
  pod 'Highlightr', :git => 'https://github.com/brunophilipe/Highlightr.git'
end

# post install
post_install do |installer|
    # Build settings
    installer.pods_project.targets.each do |target|
        target.build_configurations.each do |config|
            config.build_settings = config.build_settings.dup
            if config.build_settings['PRODUCT_MODULE_NAME'] == 'SavannaKit' || config.build_settings['PRODUCT_MODULE_NAME'] == 'SourceEditor' || config.build_settings['PRODUCT_MODULE_NAME'] == 'SplitKit'
                puts "Set Swift version"
                config.build_settings['SWIFT_VERSION'] = '4.0'
            end
        end
    end
end
