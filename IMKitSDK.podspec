Pod::Spec.new do |s|
  s.name          = "IMKitSDK"
  s.version       = '0.0.63'
  s.summary       = "IMKitSDK"
  s.homepage      = 'http://imkit.co/'
  s.license       = 'MIT'
  s.author        = { "Lova Shih" => "lova@funtek.co" }
  s.platform      = :ios, "8.0"
  s.source        = { :git => "https://github.com/FUNTEKco/IMKit-iOS.git", :tag => s.version.to_s }
  s.source_files  = "IMKitSDK.framework/Headers/*.h"
  s.resources     = "IMMain.storyboard",
                    "demo/demo/assets.xcassets/**/*.{jpg,png}"
  s.ios.vendored_frameworks = 'IMKitSDK.framework'
  s.framework     = 'UIKit'

  #s.dependency 'Socket.IO-Client-Swift','~> 6.1.1'
  s.dependency 'Socket.IO-Client-Swift','~> 5.4.1'
  s.dependency 'JSONModel','~> 1.2.0'
  s.dependency 'GVUserDefaults','~> 1.0.2'
  s.dependency 'UITableView+FDTemplateLayoutCell', '~> 1.4'
  s.dependency 'YYWebImage','~> 1.0.3'
  s.dependency 'LOAlertController','~> 0.1.4'
  s.dependency 'LOUIKit','0.1.19'
  s.dependency 'YapDatabase','2.9'
  # s.dependency 'UICollectionView-ARDynamicHeightLayoutCell' ,'1.0.2'

  s.requires_arc  = true
end

