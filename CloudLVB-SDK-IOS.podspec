Pod::Spec.new do |s|
  s.name             = 'CloudLVB-SDK-IOS'
  s.version          = '1.0.1'
  s.summary          = 'DaXueZhang Open Platform Audio Video Founction SDK For iOS - CloudLVB-SDK-IOS.'

  s.description      = <<-DESC
DaXueZhang Open Platform Audio Video Founction SDK For iOS - CloudLVB-SDK-IOS.
                       DESC

  s.homepage         = 'https://open.jjldxz.com/'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'dxz-tech@jjldxz.com' => 'dxz-tech@jjldxz.com' }
  s.source           = { :git => 'https://github.com/jjldxz/CloudLVB-SDK-IOS.git', :tag => s.version.to_s }

  s.ios.deployment_target = '12.0'
  s.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64' }
  s.vendored_frameworks = 'Lib/cloud_lvb_sdk_ios.framework'
  s.frameworks = 'UIKit', 'Foundation', 'CoreTelephony'
  s.dependency 'AFNetworking'
  s.dependency 'SocketRocket'
  s.dependency 'Protobuf'
  s.dependency 'AgoraRtcEngine_iOS', '3.4.7'
end
