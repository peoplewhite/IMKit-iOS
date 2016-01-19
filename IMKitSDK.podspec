Pod::Spec.new do |s|
  s.name          = "IMKitSDK"
  s.version       = '0.0.12'
  s.summary       = "IMKitSDK" 
  s.homepage      = 'http://imkit.co/'
  s.license       = 'MIT'
  s.author        = { "Lova Shih" => "lova@funtek.co" }
  s.platform      = :ios, "8.0"
  s.source        = { :git => "https://github.com/FUNTEKco/IMKit-iOS.git", :tag => '0.0.12' }
  s.source_files  = "IMKitSDK.framework/Headers/*.h"
  s.ios.vendored_frameworks = 'IMKitSDK.framework'
  s.framework     = 'UIKit'

  s.dependency 'AFNetworking', '~> 3.0.4'
  s.dependency 'Socket.IO-Client-Swift','~> 4.0.4'
  s.dependency 'JSONModel','~> 1.1.2'
  s.dependency 'GVUserDefaults','~> 1.0.1'

  s.requires_arc  = true
end

