//
//  CLS_PlatformManager.h
//  cloud_lvb_sdk_ios
//
//  Created by Fox Doggy on 2021/8/20.
//

#import <Foundation/Foundation.h>
#import "CLS_ToolsEnumHeader.h"
#import "CLS_PlatformManagerDelegate.h"

/**
 
 da xue zhange (dxz) Cloud LVB SDK abbreviated as CLS is dxz platform develop live SDK
 
 */

NS_ASSUME_NONNULL_BEGIN
__attribute__((objc_subclassing_restricted))
@interface CLS_PlatformManager : NSObject
/** @auth_token
 
 Unique identifier for user login authentication
 
 */
@property (copy, nonatomic, readonly) NSString *auth_token;
/** The CLS_PlatformManagerDelegate protocol enables callbacks to your app.
 
 The SDK uses delegate callbacks in the CLS_PlatformManagerDelegate protocol to report runtime events to the app.
 
 */
@property (weak, nonatomic) id<CLS_PlatformManagerDelegate> delegate;

@property (copy, nonatomic) NSString *user_name;
@property (copy, nonatomic) NSString *user_role;

#pragma mark - system method
/** Creats a CLS_PlatformManager instance.
 
 @param authToken user request from lvb platform(url: http://cloud.m.com/) for each user has an authToken.
 @param appKey request from lvb platform(url: http://cloud.m.com/) for each user has an app key.
 
 Unless otherwise specified, all the methods provided by the AgoraRtcEngineKit instance are executed asynchronously. Agora recommends calling these methods in the same thread.
 
 ** Notice **
 - You must create a CLS_PlatformManager instance before calling any other method.
 - You must user [+ (instancetype)defaultManagerWithToken:(NSString *)authToken AppKey:(NSString *)appKey] in Objective-c or [defaultManager(authToken:appkey:)] in Swift to instance
 
 */
+ (instancetype)defaultManagerWithToken:(NSString *)authToken AppKey:(NSString *)appKey NS_SWIFT_NAME(defaultManager(authToken:appkey:));

/** join a meeting with user id, meeting room id, is meeting creater and audio speaker status
 
 @param userId user's ID, the ID is request from DaXueZhange Cloud Platform
 @param roomId meeting number, the number is user create on the DaXueZhange Cloud Platform, return 9 count number.
 @param isAdmin if current joined user ID is creater "isAdmin" is true, else "isAdmin" is false
 @param isSpeaker choose sound play mode is use speaker or ear piece
 @param handler join result callback
 
 User join the meeting, in the same meeting room, user can talk to each other, users with different app IDs can join the same meeting room.
 
 You must call the [CLS_LeaveCurrentRoom] to leave current meeting room if you want to release the SDK system, you must call [CLS_LeaveTheSystem] to release source and destory the SDK process.
 
 The SDK uses the iOS's AVAudioSession shared object for audio sampling and playback. Using this object may affect the SDK’s audio functions.
 
 */
- (void)CLS_JoinRoomWithUserId:(NSNumber *)userId
                        RoomId:(NSNumber *)roomId
                       IsAdmin:(BOOL)isAdmin
             DefaultAudioRoute:(BOOL)isSpeaker
              CompletedHandler:(CLS_PlatformLoadingCompleted)handler;

/** read meeting room current time online users attributes and return dictionary struct
 
 room members is keeping update, when user leave or user join the sdk is updating users.
 
 */
- (NSDictionary<NSNumber *, NSDictionary *> *)CLS_ReadCurrentRoomAllUsersAttrs;
/** read meeting room current attributions and return dictionary struct
 
 room attribute is keeping update, host or co-host can update room attributes, use [CLS_SettingRoomAttrWithRoomId:AttrsMap:CompletedHandler:]
 
 */
- (NSDictionary<NSString *, id> *)CLS_ReadCurrentRoomAttrs;
/** current login user leave current room
 
 return leave result:
 0: success
 -1: failura
 
 */
- (int)CLS_LeaveCurrentRoom;
/** release SDK source, leave the room and leave the system
 
 if your call the method before not call the [CLS_LeaveCurrentRoom], SDK will call the leave room first, after leave the room, SDK continue release source and leave the rtc, rtm system.
 
 */
- (void)CLS_LeaveTheSystem;
/** read sdk version
 
 format like 1.0.0
 
 */
- (NSString *)CLS_SDKVersion;
/** check current sdk enable to work
 
 return value
 0: enable
 -1: disable
 when you call this method, SDK will check the rtm and rtc server is normal work.
 if current system don't join any room, call this method will return -1
 
 */
- (int)CLS_CheckSDKEnable;

#pragma mark - api method
/** instance current user attributes
 
 @param attrMap user attribute <key: String, value: id>
 @param handler method result callback
 
 use this method to setting user attribute, after you setting attrbute, other member in the room will received your status is init message
 
 */
- (void)CLS_InitUserAttrsMap:(NSDictionary<NSString *, id> *)attrMap
            CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
/** kick out user from meeting room
 
 @param userId kick out user's ID
 @param roomId meeting room number
 
 when developer use the method want to kick out someone, target user will receive a event message what is kick out, so receiver need leave by it self. this method can't straightforward let user leave.
 
 */
- (void)CLS_KickoutRoomMemberWithUserId:(NSNumber *)userId
                                 RoomId:(NSNumber *)roomId
                       CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
/** setting or updating someone's user attribute
 
 @param userId changed user's ID
 @param roomId user in room's number
 @param attrMap setting or updating user's attribute dictionay <key: String, value: id>
 @param handler method result callback
 
 when developer use this method to change or update user attribute, server will send the event to all users in the room and the RTM server will save this change. if a new user join the room and synchronize user info, server will send to him the updated attribute data.
 
 */
- (void)CLS_SettingUserAttrWithUserId:(NSNumber *)userId
                               RoomId:(NSNumber *)roomId
                             AttrsMap:(NSDictionary<NSString *, id> *)attrMap
                     CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
/** use this method can setting or updating room attribute
 
 @param roomId meeting room number
 @param attrMap setting or updating room attribute dictionay <key: String, value: id>
 @param handler method result callback
 
 developer can use this method to change or update room attribute, call this method, the server will save this changed and send a room attribute update event to the room. when new user join the meeting room and synchronize, server will send updated room attribute data.
 
 */
- (void)CLS_SettingRoomAttrWithRoomId:(NSNumber *)roomId
                             AttrsMap:(NSDictionary<NSString *, id> *)attrMap
                     CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
/** set share user info on SDK
 
 @param sharerId share user's ID
 @param sharer_token share user auth_token
 
 if meeting room will user share screen function, SDK need to know share user info. so if developer setting this info, when share user push stream on RTC
 
 */
- (void)CLS_SettingShareUserInfoWithId:(NSNumber *)sharerId
                                 Token:(NSString *)sharer_token;
/** close the meeting room
 
 @param roomId closed room number
 @param handler method result callback
 
 When a user wants to end a meeting room, use this method to close the room with the specified room ID.
 
 */
- (void)CLS_RoomStopWithRoomId:(NSNumber *)roomId
              CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
/** send message to peer user
 
 @param userId peer user's ID
 @param category message channel type
 @param message send message content
 @param handler method result callback
 
 The SDK supports sending peer-to-peer messages to specified users. Developers can select a channel type to send messages to different channels.
 
 */
- (void)CLS_SendMessageToUserWithUserId:(NSNumber *)userId
                               Category:(CLS_RTMMessageCategoryType)category
                         MessageContent:(NSString *)message
                       CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
/** send message to room
 
 @param roomId target room's number
 @param category message channel type
 @param message send message content
 @param handler method result callback
 
 The SDK supports the broadcast of sending messages in the specified room. For the specified message type, you can choose to send the message on different channel types.
 
 */
- (void)CLS_SendMessageToRoomWithRoomId:(NSNumber *)roomId
                               Category:(CLS_RTMMessageCategoryType)category
                         MessageContent:(NSString *)message
                       CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
/** synchronize whiteboard server history draw message
 
 @param completed method result callback
 
 DaXueZhang Cloud Platform has whiteboard server to record whiteboard draw data. After the platform has applied for the whiteboard service, the whiteboard service of the platform can be used in the meeting as in Demo.The drawing data of the whiteboard has a specific format. If the user has a custom whiteboard style, the current service is not supported.
 
 */
- (void)CLS_SynchronizeWhiteboardDrawContent:(void (^)(BOOL success, NSError *_Nullable error))completed;
/** generate rtc share user info
 
 @param roomId share user target room number
 @param name share user name in server
 @param handler method result callback
 
 The SDK provides a way to register users for the shared video feature.This method registers new users with shared services for RTC.
 
 */
- (void)CLS_GenerateRTCUserWithRoomId:(NSNumber *)roomId
                 GeneratePropertyName:(NSString *)name
                     CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;

#pragma mark - rtm method
/** RTM message event, send SDK encapsulation changing target user video status request
 
 @param userId target user's ID
 @param value target changed video value
 @param handler method result callback
 
 This is an RTM message encapsulated in the SDK and is mainly used to implement the message structure similar to the application scenario of the senior meeting.One party sends a request and the other party receives a message to change its status.
 
 */
- (void)CLS_ChangeOtherVideoStatusWithUserId:(NSNumber *)userId
                                 StatusValue:(BOOL)value
                            CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
/** RTM message event, send SDK encapsulation changing target user audio status request
 
 @param userId target user's ID
 @param value target changed audio value
 @param handler method result callback
 
 This is an RTM message encapsulated in the SDK and is mainly used to implement the message structure similar to the application scenario of the senior meeting. One party sends a request and the other party receives a message to change its status.
 
 */
- (void)CLS_ChangeOtherAudioStatusWithUserId:(NSNumber *)userId
                                 StatusValue:(BOOL)value
                            CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
/** RTM message event, send SDK encapsulation changing target user role request
 
 @param userId target user's ID
 @param value target changed role value
 @param handler method result callback
 
 This is an RTM message encapsulated in the SDK and is mainly used to implement the message structure similar to the application scenario of the senior meeting. One party sends a request and the other party receives a message to change its status.
 
 */
- (void)CLS_ChangeOtherRoleWithUserId:(NSNumber *)userId
                            RoleValue:(NSString *)value
                     CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
/** RTM message event, send SDK encapsulation changing target user name request
 
 @param userId target user's ID
 @param value target changed name content
 @param handler method result callback
 
 This is an RTM message encapsulated in the SDK and is mainly used to implement the message structure similar to the application scenario of the senior meeting. One party sends a request and the other party receives a message to change its status.
 
 */
- (void)CLS_ChangeOtherNamaWithUserId:(NSNumber *)userId
                            NameValue:(NSString *)value
                     CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
/** RTM message event, send SDK encapsulation custom comtrol message on control channel
 
 @param type custom message type name
 @param opts custom message content <key, value> structure, The structure must be serializable by JSON
 @param handler method result callback
 
 This is an RTM message encapsulated in the SDK and is mainly used to implement the message structure similar to the application scenario of the senior meeting. On this basis, developers can extend the body of messages that send some custom interfaces.Send by this method
 
 */
- (void)CLS_SendSystemCustomMessageWithType:(NSString *)type
                                       Opts:(NSDictionary *)opts
                           CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
/** RTM message event, send SDK encapsulation meeting breakout event message
 
 @param status meeting breakout status, YES: breakout start, NO: breakout stop
 
 This is an RTM message encapsulated in the SDK and is mainly used to implement the message structure similar to the application scenario of the senior meeting. This message informs the user in the meeting room that the grouping status has started or ended.
 
 */
- (void)CLS_HostChangeBreakoutStatus:(BOOL)status
                    CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
/** RTM message event, send SDK encapsulation move users from one group to another group request
 
 @param toGroupId target move group's ID
 @param users request user's ID list
 @param handler method result callback
 
 This is an RTM message encapsulated in the SDK and is mainly used to implement the message structure similar to the application scenario of the senior meeting. This method is used to send a personnel transfer request when the manager needs to modify the current grouping personnel configuration.When the target user receives the message, it sends a method to modify its own Attribute to notify everyone that it has transferred the packet.
 
 */
- (void)CLS_RequestUsersMoveToBreakoutGroupWithGroupId:(NSNumber *)toGroupId
                                           MoveUsersId:(NSArray<NSNumber *> *)users
                                      CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
/** RTM message event, send SDK encapsulation notice message to all or some group
 
 @param groupId target group's ID, if its nil means send to current meeting all group
 @param message notice message content
 @param handler method result callback
 
 This is an RTM message encapsulated in the SDK and is mainly used to implement the message structure similar to the application scenario of the senior meeting. This message is a broadcast message that is used to notify or be reflected in a chat. The sender can specify a packet or not, and the target packet or all packets will receive and display the broadcast content.
 
 */
- (void)CLS_SendSystemBroadcastMessageToGroupWithGroupId:(NSNumber *_Nullable)groupId
                                                 Message:(NSString *)message
                                        CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
/** RTM message event, send SDK encapsulation notice message to call host or co-host join in user's group
 
 @param groupId current user's in the group's ID
 @param handler method result callback
 
 This is an RTM message encapsulated in the SDK and is mainly used to implement the message structure similar to the application scenario of the senior meeting. Send this message if the user in the Administrator role is not in the same group as the current user, but needs to go to that group.The message is broadcast throughout the room and the manager responds to the request by judging his current identity and deciding whether he needs to go to the group.If it is decided to go, a message is sent to the room to modify its own groupId.
 
 */
- (void)CLS_CallHostFromGroup:(NSNumber *)groupId
             CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
/** RTM message event, send SDK encapsulation chat message
 
 @param message chat message content
 @param handler method result callback
 
 This is an RTM message encapsulated in the SDK and is mainly used to implement the message structure similar to the application scenario of the senior meeting. In the meeting scene, there is a need to chat, this structure is used for its chat scene.Calling this method sends a normal chat message.
 
 */
- (void)CLS_RTMSystemSendCommonChatMessage:(NSString *)message
                          CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
/** RTM message event, send SDK encapsulation chat message
 
 @param message chat message content
 @param handler method result callback
 
 This is an RTM message encapsulated in the SDK and is mainly used to implement the message structure similar to the application scenario of the senior meeting. In the meeting scene, there is a need to chat, this structure is used for its chat scene.Calling this method sends a system chat message.
 
 */
- (void)CLS_RTMSystemSendSystemChatMessage:(NSString *)message
                          CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;

#pragma mark - rtc method
/** switch front or Rear camera
 switch camera use
 */
- (void)CLS_SwitchCamera;
/** switch phone sound play move
 
 @param isSpeaker YES: use phone speaker to play sound, NO: use earpiece to play sound
 
 when developer use method [joinRoom] to join room, is setting defaut sound play mode, if developer want to change current sound mode, can use this method.
 
 */
- (void)CLS_ChangedSoundMode:(BOOL)isSpeaker;
/** change local RTC audio stream status
 
 @param enable YES: still send local audio stream to RTC server, NO: mute local audio stream.
 
 use this method can change current device local audio stream status. if set parameter disable, other user in the same room will can't listen you audio sound.
 
 */
- (void)CLS_SettingLocalAudioStreamState:(BOOL)enable;
/** change local RTC video stream status
 
 @param enable YES: still send local video stream to RTC server, NO: mute local video stream.
 
 use this method can change current device local video stream status. if set parameter disable, other user in the same room will can't see you video picture.
 
 */
- (void)CLS_SettingLocalVideoStreamState:(BOOL)enable;
/** preview camera image on display view
 
 @param displayUI the view can display the camera preview image
 @param isFull it's a display mode setting, YES: full view to play picture, NO: display size according to the actual ratio of the image
 
 after user join room success, can preview current device camera image on your view. if join room failure, call this method will display nothing.
 
 */
- (void)CLS_PreviewLocalVideoWithUI:(__kindof UIView *_Nullable)displayUI
                      isFullDisplay:(BOOL)isFull;
/** display remote user's video stream image on display view
 
 @param user_id remote user's ID
 @param displayUI the view can display video stream image
 @param isFull it's a display mode setting, YES: full view to play picture, NO: display size according to the actual ratio of the image
 
 after user join room success, when someone join the room and started push video stream on RTC server, you can use this method to subscribe its video stream and display on the "displayUI".
 
 */
- (void)CLS_ShowRemoteUserWithId:(NSNumber *)user_id
                       DisplayUI:(__kindof UIView *_Nullable)displayUI
                   isFullDisplay:(BOOL)isFull;
/** become the Broadcaster and start to push your audio video stream to the RTC server
 
 when you join room success, at this time, you don't push any stream at all. if you want to push stream immediately, you must call this method.
 
 */
- (void)CLS_StartOnPlatform;
/** stop push sream and change role from Broadcaster to Audience
 
 use this method, you will stop push any stream to the RTC server but you can still preview local camera image. and the role change from Broadcaster to Audience, also you can still received other user's stream and subscribe them.
 
 */
- (void)CLS_LeavePlatform;
/** mute every user in the meeting except yourself
 
 @param mute YES: mute every user's stream except yourself, NO: subscribe all user's stream.

 you can mute or subscribe all user's streams, if you setting mute all user's streams, when someone new join the meeting room, you can't received he push stream notice, and can't see his stream. if you wanna see, you must unmute all stream first and subscribe his stream.
 
 */
- (void)CLS_MuteAllRemoteUserStream:(BOOL)mute;
/** mute or subscription someone
 
 @param userId target user ID
 @param mute YES: mute target user stream, NO: subscribe target user stream
 
 developer can handle mute or subscribe someone stream data. specify someone's ID information and setting its mute status.
 
 */
- (void)CLS_RemoteUserStreamWithId:(NSNumber *)userId
                        MuteStatus:(BOOL)mute;
/** setting video display mirror mode
 
 @param mirrorMode YES: mirror mode to display all video stream, No: normal mode to display video stream.
 
 this method is setting video mirror display mode. developer can setting video display mirror style.
 
 */
- (void)CLS_ChangedVideoMirrorDisplayMode:(BOOL)mirrorMode;

@end

NS_ASSUME_NONNULL_END
