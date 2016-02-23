Pod::Spec.new do |s|
  s.name          = "IMKitSDK"
  s.version       = '0.0.27'
  s.summary       = "IMKitSDK" 
  s.homepage      = 'http://imkit.co/'
  s.license       = 'MIT'
  s.author        = { "Lova Shih" => "lova@funtek.co" }
  s.platform      = :ios, "8.0"
  s.source        = { :git => "https://github.com/FUNTEKco/IMKit-iOS.git", :tag => '0.0.27' }
  s.source_files  = "IMKitSDK.framework/Headers/*.h"
  s.ios.vendored_frameworks = 'IMKitSDK.framework'
  s.framework     = 'UIKit'

  s.dependency 'Socket.IO-Client-Swift','~> 5.4.1'
  s.dependency 'JSONModel','~> 1.2.0'
  s.dependency 'GVUserDefaults','~> 1.0.2'

  s.requires_arc  = true
end

