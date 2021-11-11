//
//  CLS_PlatformManagerDelegate.h
//  cloud_lvb_sdk_ios
//
//  Created by Fox Doggy on 2021/8/24.
//

#ifndef CLS_PlatformManagerDelegate_h
#define CLS_PlatformManagerDelegate_h

#import "CLS_PlatformAudioVolumeModel.h"

NS_ASSUME_NONNULL_BEGIN
@class CLS_PlatformManager;
@protocol CLS_PlatformManagerDelegate <NSObject>

@optional
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
 CurrentUserDidJoinedSystem:(NSNumber *)roomId;
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
    UserDidJoinedRoomWithId:(NSNumber *)userId
                      Attrs:(NSDictionary<NSString *, id> *)userAttrs;
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
    UserDidLeavedRoomWithId:(NSNumber *)userId;

- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
            UserUpdateAttrs:(NSDictionary<NSString *, id> *)attrs
                 WithUserId:(NSNumber *)userId;

- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
        RoomDidUpdatedAttrs:(NSDictionary<NSString *, id> *)roomAttrs
               SenderUserId:(NSNumber *)userId;

- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
        RoomStatusDidUpdate:(CLS_RoomStatusEnum)status;

- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
CurrentUserRemoteLoginWithMessage:(NSString *)message;

- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
CurrentUserDidLeavedRoomWithId:(NSNumber *)roomId;

- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
CurrentUserDidBeenKickoutFromRoomSenderUserWithId:(NSNumber *)userId;

- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
DidReceivedControlMessageWithContent:(NSString *)content_json
                ReceiveType:(NSInteger)ReceiveType
                  ReceiveId:(NSNumber *)ReceiveId
                   SenderId:(NSNumber *)senderId;

- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
DidReceivedChatMessageWithContent:(NSString *)content_json
                ReceiveType:(NSInteger)ReceiveType
                  ReceiveId:(NSNumber *)ReceiveId
                   SenderId:(NSNumber *)senderId;

- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
DidReceivedWhiteboardMessageWithContent:(NSString *)content_json
                ReceiveType:(NSInteger)ReceiveType
                  ReceiveId:(NSNumber *)ReceiveId
                   SenderId:(NSNumber *)senderId;
/// rtc
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
UserDidStartedPublishStreamWithId:(NSNumber *)userId;

- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
UserDidStoppedPublishStreamWithId:(NSNumber *)userId;

- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
       RoomUsersAudioVolume:(NSArray<CLS_PlatformAudioVolumeModel *> *)infos;

- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
 RoomSharerDidPublishStream:(NSNumber *)shareId;

/// system control message callback
// control channel
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
  RequestVideoStatusChanged:(BOOL)value
                   SenderId:(NSNumber *)senderId;

- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
  RequestAudioStatusChanged:(BOOL)value
                   SenderId:(NSNumber *)senderId;

- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
         RequestNameChanged:(NSString *)value
                   SenderId:(NSNumber *)senderId;

- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
         RequestRoleChanged:(NSString *)value
                   SenderId:(NSNumber *)senderId;

- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
ReceivedBreakoutStatusChanged:(BOOL)status;

- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
ReceivedSystemCustomMessage:(NSDictionary *)opts
                       Type:(NSString *)typeName
                   SenderId:(NSNumber *)senderId;

- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
ReceivedSystemMoveUserToSubRoomRequest:(NSNumber *)toRoomId
                   SenderId:(NSNumber *)senderId;

- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
ReceivedSystemBroadcastMessage:(NSString *)message
                    GroupId:(NSNumber *)groupId
                   SenderId:(NSNumber *)senderId;

- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
ReceivedSystemCallHostGroupId:(NSNumber *)groupId
                   SenderId:(NSNumber *)senderId;
// chat channel
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
ReceivedSystemChatChannelMessageWithContent:(NSString *)content
               ReceivedType:(NSString *)type
                   SenderId:(NSNumber *)senderId;

@end
NS_ASSUME_NONNULL_END

#endif /* CLS_PlatformManagerDelegate_h */
