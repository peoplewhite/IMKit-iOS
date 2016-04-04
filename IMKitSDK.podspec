Pod::Spec.new do |s|
  s.name          = "IMKitSDK"
  s.version       = '0.0.35'
  s.summary       = "IMKitSDK" 
  s.homepage      = 'http://imkit.co/'
  s.license       = 'MIT'
  s.author        = { "Lova Shih" => "lova@funtek.co" }
  s.platform      = :ios, "8.0"
  s.source        = { :git => "https://github.com/FUNTEKco/IMKit-iOS.git", :tag => s.version.to_s }
  s.source_files  = "IMKitSDK.framework/Headers/*.h"
  s.resources     = "IMMain.storyboard"
  s.ios.vendored_frameworks = 'IMKitSDK.framework'
  s.framework     = 'UIKit'

  s.dependency 'Socket.IO-Client-Swift','~> 6.0.0'
  s.dependency 'JSONModel','~> 1.2.0'
  s.dependency 'GVUserDefaults','~> 1.0.2'
  s.dependency 'UITableView+FDTemplateLayoutCell', '~> 1.4'
  s.dependency 'YYWebImage','~> 1.0'
  s.dependency 'LOAlertController','~> 0.1.2'
  s.dependency 'LOUIKit','0.1.3'
  s.dependency 'YapDatabase','2.8.3'
  
  s.requires_arc  = true
end

