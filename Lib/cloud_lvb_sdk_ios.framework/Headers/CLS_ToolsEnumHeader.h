//
//  CLS_ToolsEnumHeader.h
//  cloud_lvb_sdk_ios
//
//  Created by Fox Doggy on 2021/8/23.
//

#ifndef CLS_ToolsEnumHeader_h
#define CLS_ToolsEnumHeader_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, CLS_RTMServerConnectState) {
    CLS_RTMServerConnect_Empty,
    CLS_RTMServerConnect_Online,
    CLS_RTMServerConnect_Connecting,
    CLS_RTMServerConnect_Offline,
    CLS_RTMServerConnect_Reconnect,
    CLS_RTMServerConnect_TimeOut,
    CLS_RTMServerConnect_Failure,
    CLS_RTMServerConnect_Close
};

typedef NS_ENUM(NSUInteger, CLS_RTMMessageCategoryType) {
    RTMMessageCategory_UNKNOWN,
    RTMMessageCategory_ROOM_START,
    RTMMessageCategory_ROOM_STOP,
    RTMMessageCategory_USER_STATUS,
    RTMMessageCategory_ROOM_ATTR,
    RTMMessageCategory_USER_ATTR,
    RTMMessageCategory_CONTROL_MESSAGE,
    RTMMessageCategory_CHAT_MESSAGE,
    RTMMessageCategory_WHITEBOARD_MESSAGE,
    RTMMessageCategory_KICK_OUT
};

typedef NS_ENUM(NSUInteger, CLS_RoomStatusEnum) {
    CLS_RoomStatus_START,
    CLS_RoomStatus_STOP,
    CLS_RoomStatus_UNKNOWN
};

typedef NS_ENUM(NSUInteger, CLS_RTMMessageReceiveType) {
    CLS_RTMMessageReceiveType_FROM_PEER,
    CLS_RTMMessageReceiveType_FROM_ROOM,
};

struct CLS_VideoConfigStruct {
    CGSize video_size;
    NSUInteger frameRate;
    NSUInteger bitrate;
};
typedef struct CG_BOXABLE CLS_VideoConfigStruct CLS_VideoConfigStruct;

CG_INLINE struct CLS_VideoConfigStruct CLS_VideoConfigStructMake(CGSize size, NSUInteger frameRate, NSUInteger bitrate)
{
    CLS_VideoConfigStruct info;
    info.video_size = size;
    info.frameRate = frameRate;
    info.bitrate = bitrate;
    return info;
}

#define CLS_VideoConfig_Small   CLS_VideoConfigStructMake(CGSizeMake(320.f, 180.f), 5, 50);
#define CLS_VideoConfig_Middle  CLS_VideoConfigStructMake(CGSizeMake(640.f, 320.f), 15, 1200);
#define CLS_VideoConfig_High    CLS_VideoConfigStructMake(CGSizeMake(1280.f, 720.f), 15, 1130);

typedef void(^CLS_PlatformLoadingCompleted)(BOOL success, NSError *_Nullable error, NSDictionary*_Nullable membersAttrs, NSDictionary *_Nullable roomAttrs);

#endif /* CLS_ToolsEnumHeader_h */
