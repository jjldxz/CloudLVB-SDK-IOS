//
//  CLS_PlatformAudioVolumeModel.h
//  cloud_lvb_sdk_ios
//
//  Created by Fox Doggy on 2021/8/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CLS_PlatformAudioVolumeModel : NSObject

@property (copy, nonatomic) NSNumber *userId;
@property (assign, nonatomic) NSUInteger volume;
@property (assign, nonatomic) NSUInteger vad;

@end

NS_ASSUME_NONNULL_END
