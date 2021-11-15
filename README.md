# Cloud_Lvb_SDK iOS API Reference

Dxz Meeting iOS SDK是为 iOS 平台用户音视频服务的开源 SDK。通过大学长开放平台自研RTC，RTM系统,为客户提供质量可靠的音视频服务。

使用方式：

+ Pod仓引用SDK

```
pod 'Cloud_Lvb_SDK'

```

# 类

|             类名             |                             描述                             |
| :--------------------------: | :----------------------------------------------------------: |
|     CLS_PlatformManager      | SDK的音视频主要管理对象，功能包含了房间的加入，房间内的方法调用与房间人员管理等内容。 |
| CLS_PlatformAudioVolumeModel | 平台中正在发言的用户的数据模型对象。包含了用户的ID（userId），用户音量（volume）与是否为人声（vad）的信息存储。 |
| CLS_PlatformManagerDelegate  |               SDK内部所有事件的回调代理方法。                |
|     CLS_ToolsEnumHeader      |         SDK内用到的所有枚举，结构体， 宏等内容的文件         |

## CLS_PlatformAudioVolumeModel 类

说明：平台中正在发言的用户的数据模型对象。

| 属性名（类型）      | 描述                            |
| ------------------- | ------------------------------- |
| userId （Number）   | 用户的平台ID                    |
| volume （UInteger） | 用户音量（0~255）               |
| vad （UInteger）    | 人声检测 （0：非人声，1：人声） |



## CLS_ToolsEnumHeader 类

### 枚举类型

#### CLS_RTMServerConnectState

RTM服务状态类型

> CLS_RTMServerConnect_Empty   

> + 当前RTM服务没有任何连接

> CLS_RTMServerConnect_Online

> + 当前RTM已登录在线

> CLS_RTMServerConnect_Connecting

> + 当前RTM正在连接中

> CLS_RTMServerConnect_Offline

> + 当前RTM已登出

> CLS_RTMServerConnect_Reconnect

> + 当前RTM服务正在重连

> CLS_RTMServerConnect_TimeOut

> + 当前RTM服务连接超时

> CLS_RTMServerConnect_Failure

> + 当前RTM服务连接错误

> CLS_RTMServerConnect_Close

> + 当前RTM服务已关闭

#### CLS_RTMMessageCategoryType

RTM消息类型

> RTMMessageCategory_UNKNOWN
>
> + 未知的消息类型

> RTMMessageCategory_ROOM_START
>
> + 房间开始

> RTMMessageCategory_ROOM_STOP
>
> + 房间结束

> RTMMessageCategory_USER_STATUS
>
> + 用户状态更改

> RTMMessageCategory_ROOM_ATTR
>
> + 房间属性更改

> RTMMessageCategory_USER_ATTR
>
> + 用户属性更改

> RTMMessageCategory_CONTROL_MESSAGE
>
> + Control 通道消息

> RTMMessageCategory_CHAT_MESSAGE
>
> + Chat 通道消息

> RTMMessageCategory_WHITEBOARD_MESSAGE
>
> + Whiteboard 通道消息

> RTMMessageCategory_KICK_OUT
>
> + 踢人消息

#### CLS_RoomStatusEnum

房间状态类型

> CLS_RoomStatus_START
>
> + 房间开始

> CLS_RoomStatus_STOP
>
> + 房间结束

> CLS_RoomStatus_UNKNOWN
>
> + 未知房间状态

#### CLS_RTMMessageReceiveType

消息接收类型

> CLS_RTMMessageReceiveType_FROM_PEER
>
> + 点对点消息

> CLS_RTMMessageReceiveType_FROM_ROOM
>
> + 房间内广播消息

### 结构体类型

#### CLS_VideoConfigStruct

用于视频显示的参数结构体

| 属性       | 类型     | 描述                        |
| ---------- | -------- | --------------------------- |
| video_size | CGSize   | 视频的推流分辨率参数(宽x高) |
| frameRate  | UInteger | 视频帧率                    |
| bitrate    | UInteger | 视频比特率                  |

 ### 宏

目前宏部分定义了一些针对屏幕显示参数的几个标准参数

> CLS_VideoConfig_Small
>
> 小分辨率参数->视频分辨率宽高:(320, 180), 帧率:5, 比特率:50 的视频显示参数结构

> CLS_VideoConfig_Middle
>
> 中等分辨率参数->视频分辨率宽高:(640, 320), 帧率:15, 比特率:1200 的视频显示参数结构

> CLS_VideoConfig_High
>
> 高等分辨率参数->视频分辨率宽高:(1280, 720), 帧率:15, 比特率:1130 的视频显示参数结构

### Callback回调

> CLS_PlatformLoadingCompleted
>
> 在SDK调用join方法时的callback回调,返回成功状态(success), 错误信息(error 可为空), 房间内的当前时间点的用户所有属性信息(membersAttrs), 房间内当前时间点的房间属性信息(roomAttrs)

# CLS_PlatformManager

CLS_PlatformManager 是iOS端SDK的核心管理类, 包含了对房间内所有数据的管理与事件管理. 是SDK内部最主要的功能类.

## Index

### Properties

* [auth_token](#auth_token)
* [delegate](#delegate)

### Methods

* [defaultManagerWithToken:AppKey:](#defaultManagerWithToken:AppKey:)
* [CLS_SDKVersion](#CLS_SDKVersion)
* [CLS_CheckSDKEnable](#CLS_CheckSDKEnable)
* [CLS_JoinRoomWithUserId:RoomId:IsAdmin:DefaultAudioRoute:CompletedHandler:](#CLS_JoinRoomWithUserId:RoomId:IsAdmin:DefaultAudioRoute:CompletedHandler:)
* [CLS_ReadCurrentRoomAllUsersAttrs](#CLS_ReadCurrentRoomAllUsersAttrs)
* [CLS_ReadCurrentRoomAttrs](#CLS_ReadCurrentRoomAttrs)
* [CLS_LeaveCurrentRoom](#CLS_LeaveCurrentRoom)
* [CLS_LeaveTheSystem](#CLS_LeaveTheSystem)
* [CLS_InitUserAttrsMap:CompletedHandler:](#CLS_InitUserAttrsMap:CompletedHandler:)
* [CLS_KickoutRoomMemberWithUserId:RoomId:CompletedHandler:](#CLS_KickoutRoomMemberWithUserId:RoomId:CompletedHandler:)
* [CLS_SettingUserAttrWithUserId:RoomId:AttrsMap:CompletedHandler:](#CLS_SettingUserAttrWithUserId:RoomId:AttrsMap:CompletedHandler:)
* [CLS_SettingRoomAttrWithRoomId:AttrsMap:CompletedHandler:](#CLS_SettingRoomAttrWithRoomId:AttrsMap:CompletedHandler:)
* [CLS_SettingShareUserInfoWithId:Token:](#CLS_SettingShareUserInfoWithId:Token:)
* [CLS_RoomStopWithRoomId:CompletedHandler:](#CLS_RoomStopWithRoomId:CompletedHandler:)
* [CLS_SendMessageToUserWithUserId:Category:MessageContent:CompletedHandler:](#CLS_SendMessageToUserWithUserId:Category:MessageContent:CompletedHandler:)
* [CLS_SendMessageToRoomWithRoomId:Category:MessageContent:CompletedHandler:](#CLS_SendMessageToRoomWithRoomId:Category:MessageContent:CompletedHandler:)
* [CLS_SynchronizeWhiteboardDrawContent:](#CLS_SynchronizeWhiteboardDrawContent:)
* [CLS_GenerateRTCUserWithRoomId:GeneratePropertyName:CompletedHandler:](#CLS_GenerateRTCUserWithRoomId:GeneratePropertyName:CompletedHandler:)
* [CLS_ChangeOtherVideoStatusWithUserId:StatusValue:CompletedHandler:](#CLS_ChangeOtherVideoStatusWithUserId:StatusValue:CompletedHandler:)
* [CLS_ChangeOtherAudioStatusWithUserId:StatusValue:CompletedHandler:](#CLS_ChangeOtherAudioStatusWithUserId:StatusValue:CompletedHandler:)
* [CLS_ChangeOtherRoleWithUserId:RoleValue:CompletedHandler:](#CLS_ChangeOtherRoleWithUserId:RoleValue:CompletedHandler:)
* [CLS_ChangeOtherNamaWithUserId:NameValue:CompletedHandler:](#CLS_ChangeOtherNamaWithUserId:NameValue:CompletedHandler:)
* [CLS_SendSystemCustomMessageWithType:Opts:CompletedHandler:](#CLS_SendSystemCustomMessageWithType:Opts:CompletedHandler:)
* [CLS_HostChangeBreakoutStatus:CompletedHandler:](#CLS_HostChangeBreakoutStatus:CompletedHandler:)
* [CLS_RequestUsersMoveToBreakoutGroupWithGroupId:MoveUsersId:CompletedHandler:](#CLS_RequestUsersMoveToBreakoutGroupWithGroupId:MoveUsersId:CompletedHandler:)
* [CLS_SendSystemBroadcaseMessageToGroupWithGroupId:Message:CompletedHandler:](#CLS_SendSystemBroadcaseMessageToGroupWithGroupId:Message:CompletedHandler:)
* [CLS_CallHostFromGroup:CompletedHandler:](#CLS_CallHostFromGroup:CompletedHandler:)
* [CLS_RTMSystemSendCommonChatMessage:CompletedHandler:](#CLS_RTMSystemSendCommonChatMessage:CompletedHandler:)
* [CLS_RTMSystemSendSystemChatMessage:CompletedHandler:](#CLS_RTMSystemSendSystemChatMessage:CompletedHandler:)
* [CLS_SwitchCamera](#CLS_SwitchCamera)
* [CLS_ChangedSoundMode:](#CLS_ChangedSoundMode:)
* [CLS_SettingLocalAudioStreamState:](#CLS_SettingLocalAudioStreamState:)
* [CLS_SettingLocalVideoStreamState:](#CLS_SettingLocalVideoStreamState:)
* [CLS_PreviewLocalVideoWithUI:isFullDisplay:](#CLS_PreviewLocalVideoWithUI:isFullDisplay:)
* [CLS_ShowRemoteUserWithId:DisplayUI:isFullDisplay:](#CLS_ShowRemoteUserWithId:DisplayUI:isFullDisplay:)
* [CLS_StartOnPlatform](#CLS_StartOnPlatform)
* [CLS_LeavePlatform](#CLS_LeavePlatform)
* [CLS_MuteAllRemoteUserStream:](#CLS_MuteAllRemoteUserStream:)
* [CLS_RemoteUserStreamWithId:MuteStatus:](#CLS_RemoteUserStreamWithId:MuteStatus:)
* [CLS_ChangedVideoMirrorDisplayMode:](#CLS_ChangedVideoMirrorDisplayMode:)

##  Properties

### auth_token

``` objective-c
NSString *auth_token
```

auth_token: 用户身份的唯一标识,在用户登录系统之后,会返回一个身份标识为"auth_token".当用户加入使用SDK时,该属性作为初始化的必须参数,被传入并赋值,在外部为只读属性.

### delegate

``` objective-c
id<CLS_PlatformManagerDelegate> delegate
```

delegate: SDK内所有事件以代理回调的方式,让App获取所有事件内容.声明代理<CLS_PlatformManagerDelegate>, 并响应其内部的代理事件就可以接收所订阅的事件内容.

## Methods

### defaultManagerWithToken:AppKey:

``` objective-c
+ (instancetype)defaultManagerWithToken:(NSString *)authToken AppKey:(NSString *)appKey NS_SWIFT_NAME(defaultManager(authToken:appkey:));
```

SDK的初始化方法, 使用者需要传入从平台登录后返回的authToken与appKey作为参数,进行初始化.

#### Notice:

> 1. 该方法是SDK的唯一初始化方式, 其他的初始化方式,可能创建CLS_PlatformManager这个对象但是无法使用其所有功能, 也就是说, 非该方式的初始化所得到的对象都是无用对象, 无法正常使用其正常功能. 

> 2. 对于初始化的参数( authToken, appKey)是不为空对象, SDK会对其做校验, 如果为空则会进入断言被进行判空处理. 

> 3. 初始化只是对CLS_PlatformManager的基本功能进行了构建, 并没有加入任何房间或进行后台通信. 所以初始化后的对象可以进行[joinRoom](#CLS_JoinRoomWithUserId:RoomId:IsAdmin:DefaultAudioRoute:CompletedHandler:)的操作

### CLS_SDKVersion

``` objective-c
- (NSString *)CLS_SDKVersion;
```

返回SDK当前的版本号. 例: 1.0.0

### CLS_CheckSDKEnable

``` objective-c
- (int)CLS_CheckSDKEnable;
```

检查当前SDK是否可用(可用状态包括RTC, RTM对象已创建,并且连接状态良好). 0: 可用, -1: 不可用

### CLS_JoinRoomWithUserId:RoomId:IsAdmin:DefaultAudioRoute:CompletedHandler:

```objective-c
- (void)CLS_JoinRoomWithUserId:(NSNumber *)userId
                        RoomId:(NSNumber *)roomId
                       IsAdmin:(BOOL)isAdmin
             DefaultAudioRoute:(BOOL)isSpeaker
              CompletedHandler:(CLS_PlatformLoadingCompleted)handler;
```

用户加入指定房间号的房间,并做一些基础配置. CompletedHandler的Callback,将在RTM与RTC加入房间之后回调,如果中途有某个对象出现错误或者网络错误等, Callback也将即时返回并报错.

#### 参数解释:

> userId 类型: NSNumber
>
> + 用户ID, 用户在大学长云平台申请到的用户ID.

> roomId 类型: NSNumber
>
> + 房间ID, 在大学长平台创建的9位ID的房间号码.

> isAdmin 类型: Bool
>
> + 是否为创建者, 如果当前用户ID为该房间ID的创建者, 那么isAdmin=YES, 否则isAdmin=NO.

> isSpeaker 类型: BOOL
>
> + 是否打开扬声器, 用户加入房间时的基础配置参数,是否选择已打开扬声器的方式进入会议, 如果isSpeaker=NO, 则以听筒播放的方式进入房间.

> handler 类型: CLS_PlatformLoadingCompleted
>
> + 加入房间的Callback函数, 如果用户加入成功, 该Callback将返回成功标识success = YES,并且返回当前时间点房间内的属性值与房间用户属性.

### CLS_ReadCurrentRoomAllUsersAttrs

```objective-c
- (NSDictionary<NSNumber *, NSDictionary *> *)CLS_ReadCurrentRoomAllUsersAttrs;
```

读取当前房间内所有用户的属性, 返回NSDictionary类型<key: 用户的云平台用户ID(NSNumber), value: 用户当前的属性状态值(NSDictionary)>

### CLS_ReadCurrentRoomAttrs

```objective-c
- (NSDictionary *)CLS_ReadCurrentRoomAttrs
```

读取当前房间设置的属性值, 返回NSDictionary类型<key: 属性名(NSString), value: 属性内容(id)>

### CLS_LeaveCurrentRoom

```objective-c
- (int)CLS_LeaveCurrentRoom;
```

离开当前房间并返回结果, 0: 成功离开, -1: 离开失败. 成功离开房间后, 会断开与房间连接的RTM与RTC, 用户可以重新调用[joinRoom](#CLS_JoinRoomWithUserId:RoomId:IsAdmin:DefaultAudioRoute:CompletedHandler:)方法, 重新加入到其他房间.

### CLS_LeaveTheSystem

```objective-c
- (void)CLS_LeaveTheSystem;
```

离开系统, SDK存储的数据资源会被释放, SDK内部创建的对象也将被释放, 如果当前还正在房间内, 调用该方法会离开当前房间并断开RTM与RTC服务. CLS_PlatformManage也被释放掉.

### CLS_InitUserAttrsMap:CompletedHandler:

```objective-c
- (void)CLS_InitUserAttrsMap:(NSDictionary<NSString *, id> *)attrMap
            CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
```

RTM事件, 初始化当前用户的用户属性值, 传入用户属性字典, CompletedHandler作为Callback函数将会返回设置结果.

#### 参数解释:

>attrMap 类型: NSDictionary<NSString *, id>
>
>+ 用户属性的键值对<key: 属性名(NSString), value: 属性值(id)>

>handler 类型: Block函数(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))
>
>+ Callback回调函数, 返回当前设置结果 (isSuccess: 成功与否; response: 成功返回, 返回函数调用结果, 如未成功, 返回nil; error: 如果失败返回错误信息, 如果成功则为nil)

#### 流程详解:

当开发者调用[joinRoom](#CLS_JoinRoomWithUserId:RoomId:IsAdmin:DefaultAudioRoute:CompletedHandler:)方法后, 在回调事件中将收到自己加入房间的消息, 在其返回的Callback函数中会接收房间内用户设置的属性值与房间属性值. 如果此时开发者想让房间内其他用户也获取自己的用户状态,需要调用该方法设置. 值得注意的是, 该方法只能在[joinRoom](#CLS_JoinRoomWithUserId:RoomId:IsAdmin:DefaultAudioRoute:CompletedHandler:)方法成功之后调用, 建议在回调事件"[CurrentUserDidJoinedSystem](#CurrentUserDidJoinedSystem)"中调用, 初始化自己的用户属性值.

### 1.3.10 CLS_KickoutRoomMemberWithUserId:RoomId:CompletedHandler:

```objective-c
- (void)CLS_KickoutRoomMemberWithUserId:(NSNumber *)userId
                                 RoomId:(NSNumber *)roomId
                       CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
```

RTM事件, 踢出某房间(roomId)中的某用户(userId). 值得注意的是, 这并不是一个强制踢出的操作, 而是创建了一条踢人的指令在特定房间内广播, 所有用户都可以收取到该消息, 并在回调事件中处理. 但只有指定的用户(userId)需要处理该事件, 自己做下一步的处理.

#### 参数解释:

> userId 类型: NSNumber
>
> + 踢出的目标用户ID

> roomId 类型: NSNumber
>
> + 指定房间的房间ID

> handler 类型: Block函数(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))
>
> + Callback回调函数, 返回当前设置结果 (isSuccess: 成功与否; response: 成功返回, 返回函数调用结果, 如未成功, 返回nil; error: 如果失败返回错误信息, 如果成功则为nil)

### CLS_SettingUserAttrWithUserId:RoomId:AttrsMap:CompletedHandler:

```objective-c
- (void)CLS_SettingUserAttrWithUserId:(NSNumber *)userId
                               RoomId:(NSNumber *)roomId
                             AttrsMap:(NSDictionary<NSString *, id> *)attrMap
                     CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
```

RTM事件, 设置用户的属性, 该方法可以设置指定房间(roomId)下的指定用户(userId), 并修改其用户属性. 当开发者调用该方法后, 会在RTM系统中被广播, 所有房间内用户都可以接收到该事件,并在事件回调中收取. AttrsMap是需要修改的属性名与值,  CompletedHandler将会返回设置的结果. 当设置成功后会在回调事件"[CLS_PlatformManager:UserUpdateAttrs:WithUserId:](#UserUpdateAttrs)"中接收到该消息.

#### 参数解释:

> userId 类型: NSNumber
>
> + 设置属性的目标用户ID

> roomId 类型: NSNumber
>
> + 指定房间的房间ID

> handler 类型: Block函数(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))
>
> + Callback回调函数, 返回当前设置结果 (isSuccess: 成功与否; response: 成功返回, 返回函数调用结果, 如未成功, 返回nil; error: 如果失败返回错误信息, 如果成功则为nil)

### CLS_SettingRoomAttrWithRoomId:AttrsMap:CompletedHandler:

```objective-c
- (void)CLS_SettingRoomAttrWithRoomId:(NSNumber *)roomId
                             AttrsMap:(NSDictionary<NSString *, id> *)attrMap
                     CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
```

RTM事件, 设置指定房间(roomId)的房间属性. AttrsMap为设置的属性内容. CompletedHandler为函数调用后的Callback回调函数,返回设置结果. 当开发者调用该方法成功后, 会在事件回调"[CLS_PlatformManager:RoomStatusDidUpdate:](#RoomStatusDidUpdate)"中接收到该事件

#### 参数解释:

> roomId 类型: NSNumber
>
> + 指定房间的房间ID

> attrMap 类型: NSDictionary<NSString *, id>
>
> + 设置的房间属性键值对<key: 属性名(NSString), value: 属性值(id)>

> handler 类型: Block函数(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))
>
> + Callback回调函数, 返回当前设置结果 (isSuccess: 成功与否; response: 成功返回, 返回函数调用结果, 如未成功, 返回nil; error: 如果失败返回错误信息, 如果成功则为nil)

### CLS_SettingShareUserInfoWithId:Token:

```objective-c
- (void)CLS_SettingShareUserInfoWithId:(NSNumber *)sharerId
                                 Token:(NSString *)sharer_token;
```

RTM事件, SDK提供了屏幕共享功能, 如果房间内设置了该功能, 需要将共享时使用的用户信息提供给SDK, 让SDK可以得知有共享者的存在. Id为共享者的平台ID, Token为共享者的平台auth_token. 值得注意的是, 如果SDK被设置了共享者参数, 当接收到来自共享者发送的视频/音频数据时, 会在回调事件"[CLS_PlatformManager:RoomSharerDidPublishStream:](#CLS_PlatformManager:RoomSharerDidPublishStream:)"中通知开发者.

#### 参数解释:

> sharerId 类型: NSNumber
>
> + 共享人的平台用户ID

> sharer_token 类型: NSString
>
> + 共享人的平台authToken

### CLS_RoomStopWithRoomId:CompletedHandler:

```objective-c
- (void)CLS_RoomStopWithRoomId:(NSNumber *)roomId
              CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
```

RTM事件, 关闭指定的房间. RoomId为指定的房间ID, CompletedHandler为函数调用后的Callback回调函数,返回设置结果. 当开发者调用该函数来结束房间时, 会在事件回调"[CLS_PlatformManager:RoomStatusDidUpdate:](#RoomStatusDidUpdate)"中接收到房间关闭的消息

#### 参数解释:

>roomId 类型: NSNumber
>
>+ 要关闭的房间的房间ID

> handler 类型: Block函数(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))
>
> + Callback回调函数, 返回当前设置结果 (isSuccess: 成功与否; response: 成功返回, 返回函数调用结果, 如未成功, 返回nil; error: 如果失败返回错误信息, 如果成功则为nil)

### CLS_SendMessageToUserWithUserId:Category:MessageContent:CompletedHandler:

```objective-c
- (void)CLS_SendMessageToUserWithUserId:(NSNumber *)userId
                               Category:(CLS_RTMMessageCategoryType)category
                         MessageContent:(NSString *)message
                       CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
```

RTM事件, 发送给指定用户的某类型的点对点消息. UserId为用户的平台ID, Category为消息种类的枚举类型(详情见[CLS_RTMMessageCategoryType](#CLS_RTMMessageCategoryType)), MessageContent为需要发送的消息内容的json字符串格式, CompletedHandler为函数调用后的Callback回调函数,返回设置结果. 值得注意的是, 该方法并不指定某个房间, 所以如果该用户在线, 就会接收到消息,  不管他是否与你同在一个房间. 

#### 参数解释:

> userId 类型: NSNumber
>
> + 要发送消息的指定的用户平台ID

> category 类型: CLS_RTMMessageCategoryType
>
> + 要发送的消息的消息类/通道类

> message 类型: NSString
>
> + 发送的消息的消息体, 必须为Json字符串

> handler 类型: Block函数(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))
>
> + Callback回调函数, 返回当前设置结果 (isSuccess: 成功与否; response: 成功返回, 返回函数调用结果, 如未成功, 返回nil; error: 如果失败返回错误信息, 如果成功则为nil)

### CLS_SendMessageToRoomWithRoomId:Category:MessageContent:CompletedHandler:

```objective-c
- (void)CLS_SendMessageToRoomWithRoomId:(NSNumber *)roomId
                               Category:(CLS_RTMMessageCategoryType)category
                         MessageContent:(NSString *)message
                       CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
```

RTM事件, 在指定房间发送广播消息,  该消息会广播给在指定房间中的每一个在线用户. RoomId为指定的房间平台ID, Category为消息种类的枚举类型(详情见[CLS_RTMMessageCategoryType](#CLS_RTMMessageCategoryType)), MessageContent为需要发送的消息内容的json字符串格式, CompletedHandler为函数调用后的Callback回调函数,返回设置结果.

#### 参数解释:

> roomId 类型: NSNumber
>
> + 需要广播到的指定平台房间ID. 

> category 类型: CLSRTMMessageCategoryType
>
> + 要发送的消息的消息类/通道类

> message 类型: NSString
>
> + 发送的消息的消息体, 必须为Json字符串

> handler 类型: Block函数(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))
>
> + Callback回调函数, 返回当前设置结果 (isSuccess: 成功与否; response: 成功返回, 返回函数调用结果, 如未成功, 返回nil; error: 如果失败返回错误信息, 如果成功则为nil)

### CLS_SynchronizeWhiteboardDrawContent:

```object
- (void)CLS_SynchronizeWhiteboardDrawContent:(void (^)(BOOL success, NSError *_Nullable error))completed;
```

RTM事件, SDK同时也提供了自己的白板服务, 详细的事件方式可以参考Demo中的白板功能部分. 该方法是请求该房间之前绘制的白板数据信息的函数, 当开发者使用大学长系统提供的白板服务时, 调用该方法会在回调事件"[CLS_PlatformManager:DidReceivedWhiteboardMessageWithContent:ReceiveType:ReceiveId:SenderId:](#DidReceivedWhiteboardMessageWithContent)"中得到历史的描绘数据.

#### 参数解释:

> handler 类型: Block函数(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))
>
> + Callback回调函数, 返回当前设置结果 (isSuccess: 成功与否; response: 成功返回, 返回函数调用结果, 如未成功, 返回nil; error: 如果失败返回错误信息, 如果成功则为nil)

### CLS_GenerateRTCUserWithRoomId:GeneratePropertyName:CompletedHandler:

```objective-c
- (void)CLS_GenerateRTCUserWithRoomId:(NSNumber *)roomId
                 GeneratePropertyName:(NSString *)name
                     CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
```

RTM事件, SDK提供让用户自己生成共享用户信息的方法, RoomId为指定生成的房间平台ID, Name为共享用户的别名, CompletedHandler为返回的结果, 如果成功response为生成的共享用户信息, 字典结构.

#### 参数解释:

> roomId 类型: NSNumber
>
> + 需要生成共享用户的指定房间平台ID

> name 类型: NSString
>
> + 要生成的共享用户的别名

> handler 类型: Block函数(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))
>
> + Callback回调函数, 返回当前设置结果 (isSuccess: 成功与否; response: 成功返回, 返回函数调用结果, 如未成功, 返回nil; error: 如果失败返回错误信息, 如果成功则为nil)

### CLS_ChangeOtherVideoStatusWithUserId:StatusValue:CompletedHandler:

```objective-c
- (void)CLS_ChangeOtherVideoStatusWithUserId:(NSNumber *)userId
                                 StatusValue:(BOOL)value
                            CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
```

RTM事件, 发送一个修改指定用户Video状态为StatusValue的请求. 该方法并不会直接修改指定用户的Video状态, 只会发送一条请求消息, 给指定用户. 指定的用户在接收到消息后, 可以自己决定是否需要修改, 并调用自己的RTC方法修改自己的Video状态. UserId为指定的用户, value为目标状态值, CompletedHandler为函数调用后的Callback回调函数.

#### 参数解释:

> userId 类型: NSNumber
>
> + 发送给指定用户的用户平台ID

> value 类型: BOOL
>
> + 期望值 YES=open, No=close

> handler 类型: Block函数(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))
>
> + Callback回调函数, 返回当前设置结果 (isSuccess: 成功与否; response: 成功返回, 返回函数调用结果, 如未成功, 返回nil; error: 如果失败返回错误信息, 如果成功则为nil)

### CLS_ChangeOtherAudioStatusWithUserId:StatusValue:CompletedHandler:

```objective-c
- (void)CLS_ChangeOtherAudioStatusWithUserId:(NSNumber *)userId
                                 StatusValue:(BOOL)value
                            CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
```

RTM事件, 发送一个修改指定用户Audio状态为StatusValue的请求. 该方法并不会直接修改指定用户的Audio状态, 只会发送一条请求消息, 给指定用户. 指定的用户在接收到消息后, 可以自己决定是否需要修改, 并调用自己的RTC方法修改自己的Audio状态. UserId为指定的用户, value为目标状态值, CompletedHandler为函数调用后的Callback回调函数.

#### 参数解释:

> userId 类型: NSNumber
>
> + 发送给指定用户的用户平台ID

> value 类型: BOOL
>
> + 期望值 YES=open, No=close

> handler 类型: Block函数(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))
>
> + Callback回调函数, 返回当前设置结果 (isSuccess: 成功与否; response: 成功返回, 返回函数调用结果, 如未成功, 返回nil; error: 如果失败返回错误信息, 如果成功则为nil)

### CLS_ChangeOtherRoleWithUserId:RoleValue:CompletedHandler:

```objective-c
- (void)CLS_ChangeOtherRoleWithUserId:(NSNumber *)userId
                            RoleValue:(NSString *)value
                     CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
```

RTM事件, 我们的平台提供了可定义用户种类的功能, 在会议的场景里可以定义用户的属性Role为host, co-host, attendee三种, 该方法的意义是发送一个修改指定用户Role属性状态为RoleValue的请求. 该方法并不会直接修改指定用户的Role值, 只会发送一条请求消息, 给指定用户. 指定的用户在接收到消息后, 可以自己决定是否需要修改, 并调用自己的属性修改方法修改自己的Role值. UserId为指定的用户, value为目标值, CompletedHandler为函数调用后的Callback回调函数.

#### 参数解释:

> userId 类型: NSNumber
>
> + 发送给指定用户的用户平台ID

> value 类型: NSString
>
> + 期望值  co-host, attendee

> handler 类型: Block函数(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))
>
> + Callback回调函数, 返回当前设置结果 (isSuccess: 成功与否; response: 成功返回, 返回函数调用结果, 如未成功, 返回nil; error: 如果失败返回错误信息, 如果成功则为nil)

### CLS_ChangeOtherNamaWithUserId:NameValue:CompletedHandler:

```objective-c
- (void)CLS_ChangeOtherNamaWithUserId:(NSNumber *)userId
                            NameValue:(NSString *)value
                     CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
```

RTM事件, 我们的平台提供了可定义用户名称的功能, 在会议的场景里可以定义用户的昵称属性, 该方法的意义是发送一个修改指定用户昵称为NameValue的请求. 该方法并不会直接修改指定用户的昵称, 只会发送一条请求消息, 给指定用户. 指定的用户在接收到消息后, 可以自己决定是否需要修改, 并调用自己的属性修改方法修改自己的昵称. UserId为指定的用户, value为目标昵称CompletedHandler为函数调用后的Callback回调函数.

#### 参数解释:

> userId 类型: NSNumber
>
> + 发送给指定用户的用户平台ID

> value 类型: NSString
>
> + 目标昵称 

> handler 类型: Block函数(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))
>
> + Callback回调函数, 返回当前设置结果 (isSuccess: 成功与否; response: 成功返回, 返回函数调用结果, 如未成功, 返回nil; error: 如果失败返回错误信息, 如果成功则为nil)

### CLS_SendSystemCustomMessageWithType:Opts:CompletedHandler:

```objective-c
- (void)CLS_SendSystemCustomMessageWithType:(NSString *)type
                                       Opts:(NSDictionary *)opts
                           CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
```

RTM事件, SDK提供了用户可以发送自定义广播事件, 用户可以定义一个自定义标识type与消息内容opts, 然后调用该方法发送自定义事件, CompletedHandler为函数调用后的Callback回调函数.

#### 参数解释:

> type 类型: NSString
>
> + 自定义事件的标识

> opts 类型: NSDictionary
>
> + 自定义事件的内容, 参数内容必须为可被Json序列化的数据

> handler 类型: Block函数(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))
>
> + Callback回调函数, 返回当前设置结果 (isSuccess: 成功与否; response: 成功返回, 返回函数调用结果, 如未成功, 返回nil; error: 如果失败返回错误信息, 如果成功则为nil)

### CLS_HostChangeBreakoutStatus:CompletedHandler:

```objective-c
- (void)CLS_HostChangeBreakoutStatus:(BOOL)status
                    CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
```

RTM事件, SDK提供了一个快速分组的场景, 详情请见Demo. 在该场景下调用该函数可以发送一条分组状态改变的消息. 通知房间内的所有用户, 分组状态已变化为目标status值. CompletedHandler为函数调用后的Callback回调函数.

#### 参数解释:

> status 类型: BOOL
>
> + 分组的改变状态值

> handler 类型: Block函数(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))
>
> + Callback回调函数, 返回当前设置结果 (isSuccess: 成功与否; response: 成功返回, 返回函数调用结果, 如未成功, 返回nil; error: 如果失败返回错误信息, 如果成功则为nil)

### CLS_RequestUsersMoveToBreakoutGroupWithGroupId:MoveUsersId:CompletedHandler:

```objective-c
- (void)CLS_RequestUsersMoveToBreakoutGroupWithGroupId:(NSNumber *)toGroupId
                                           MoveUsersId:(NSArray<NSNumber *> *)users
                                      CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
```

RTM事件, SDK提供了一个快速分组的场景, 详情请见Demo. 在该场景下可以实现将用户转移组的操作, 调用该函数可以将目标users, 转移到指定的groupId的组中. CompletedHandler为函数调用后的Callback回调函数.

#### 参数解释:

> toGroupId 类型: NSNumber
>
> + 要转移的目标组ID

> users 类型: NSArray<NSNumber *>
>
> + 要转移的目标用户的平台ID的数组

> handler 类型: Block函数(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))
>
> + Callback回调函数, 返回当前设置结果 (isSuccess: 成功与否; response: 成功返回, 返回函数调用结果, 如未成功, 返回nil; error: 如果失败返回错误信息, 如果成功则为nil)

### CLS_SendSystemBroadcastMessageToGroupWithGroupId:Message:CompletedHandler:

```objective-c
- (void)CLS_SendSystemBroadcastMessageToGroupWithGroupId:(NSNumber *_Nullable)groupId
                                                 Message:(NSString *)message
                                        CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
```

RTM事件, SDK提供了一个快速分组的场景, 详情请见Demo. 在该场景下Role角色为host或者co-host的用户可以发送Broadcast Message到指定的GroupId分组中,  CompletedHandler为函数调用后的Callback回调函数.

#### 参数解释:

> groupId 类型: NSNumber
>
> + 指定的分组ID

> message 类型: NSString
>
> + Broadcast Message的文字内容

> handler 类型: Block函数(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))
>
> + Callback回调函数, 返回当前设置结果 (isSuccess: 成功与否; response: 成功返回, 返回函数调用结果, 如未成功, 返回nil; error: 如果失败返回错误信息, 如果成功则为nil)

### CLS_CallHostFromGroup:CompletedHandler:

```objective-c
- (void)CLS_CallHostFromGroup:(NSNumber *)groupId
             CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
```

RTM事件, SDK提供了一个快速分组的场景, 详情请见Demo. 在该场景下用户可以发送呼叫host和co-host角色的消息, host或co-host角色在接收到该消息后, 自主决定是否加入到该群组中, CompletedHandler为函数调用后的Callback回调函数.

#### 参数解释:

> groupId 类型: NSNumber
>
> + 当前分组的分组ID

> handler 类型: Block函数(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))
>
> + Callback回调函数, 返回当前设置结果 (isSuccess: 成功与否; response: 成功返回, 返回函数调用结果, 如未成功, 返回nil; error: 如果失败返回错误信息, 如果成功则为nil)

### CLS_RTMSystemSendCommonChatMessage:CompletedHandler:

```objective-c
- (void)CLS_RTMSystemSendCommonChatMessage:(NSString *)message
                          CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
```

RTM事件, SDK提供了一个聊天系统,  详情请见Demo, 如果使用SDK内部的聊天功能的话, 可以使用该方法发送普通聊天消息. 如果开发者想自定义一套自己的聊天内容的话可以使用"[CLS_SendMessageToUserWithUserId:Category:MessageContent:CompletedHandler:](#CLS_SendMessageToUserWithUserId:Category:MessageContent:CompletedHandler:)"或者"[CLS_SendMessageToRoomWithRoomId:Category:MessageContent:CompletedHandler:](#CLS_SendMessageToRoomWithRoomId:Category:MessageContent:CompletedHandler:)"将category设置为chat, message为自定义聊天结构即可. CompletedHandler为函数调用后的Callback回调函数.

#### 参数解释:

> message 类型: NSString
>
> + 要发送的聊天内容

> handler 类型: Block函数(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))
>
> + Callback回调函数, 返回当前设置结果 (isSuccess: 成功与否; response: 成功返回, 返回函数调用结果, 如未成功, 返回nil; error: 如果失败返回错误信息, 如果成功则为nil)

### CLS_RTMSystemSendSystemChatMessage:CompletedHandler:

```objective-c
- (void)CLS_RTMSystemSendSystemChatMessage:(NSString *)message
                          CompletedHandler:(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))handler;
```

RTM事件, SDK提供了一个聊天系统,  详情请见Demo, 如果使用SDK内部的聊天功能的话, 可以使用该方法发送系统聊天消息. 如果开发者想自定义一套自己的聊天内容的话可以使用"[CLS_SendMessageToUserWithUserId:Category:MessageContent:CompletedHandler:](#CLS_SendMessageToUserWithUserId:Category:MessageContent:CompletedHandler:)"或者"[CLS_SendMessageToRoomWithRoomId:Category:MessageContent:CompletedHandler:](#CLS_SendMessageToRoomWithRoomId:Category:MessageContent:CompletedHandler:)"将category设置为chat, message为自定义聊天结构即可. CompletedHandler为函数调用后的Callback回调函数.

#### 参数解释:

> message 类型: NSString
>
> + 要发送的系统聊天内容

> handler 类型: Block函数(void (^)(BOOL isSuccess, id _Nullable response, NSError *_Nullable error))
>
> + Callback回调函数, 返回当前设置结果 (isSuccess: 成功与否; response: 成功返回, 返回函数调用结果, 如未成功, 返回nil; error: 如果失败返回错误信息, 如果成功则为nil)

### CLS_SwitchCamera

```objective-c
- (void)CLS_SwitchCamera;
```

RTC事件, 切换前后摄像头. 默认状态是打开前置摄像头,  调用该方法可以调整为打开后置摄像头.

### 1.3.31 CLS_ChangedSoundMode:

```objective-c
- (void)CLS_ChangedSoundMode:(BOOL)isSpeaker;
```

RTC事件, 切换声音播放模式, YES为扬声器模式, No为听筒模式. 如果在[joinRoom](#CLS_JoinRoomWithUserId:RoomId:IsAdmin:DefaultAudioRoute:CompletedHandler:)方法中, 设置的speaker为YES, 再设置该方法为YES时, 状态无更改. 类似的如果在[joinRoom](#CLS_JoinRoomWithUserId:RoomId:IsAdmin:DefaultAudioRoute:CompletedHandler:)方法中, 设置的speaker为No, 再设置该方法为No时, 也无状态更改.

#### 参数解释:

> isSpeaker 类型: BOOL
>
> + 是否打开扬声器, YES为扬声器模式, No为听筒模式

### CLS_SettingLocalAudioStreamState:

```objective-c
- (void)CLS_SettingLocalAudioStreamState:(BOOL)enable;
```

RTC事件, 设置本机设备的音频流是否继续推送. enable为YES则继续推送, 为No则不推送.

#### 参数解释:

> enable
>
> + 是否继续推送音频流, YES: 继续推送, No: 不推送

### CLS_SettingLocalVideoStreamState:

```objective-c
- (void)CLS_SettingLocalVideoStreamState:(BOOL)enable;
```

RTC事件, 设置本机设备的视频流是否继续推送. enable为YES则继续推送, 为No则不推送.

#### 参数解释:

> enable
>
> + 是否继续推送视频流, YES: 继续推送, No: 不推送

### CLS_PreviewLocalVideoWithUI:isFullDisplay:

```objective-c
- (void)CLS_PreviewLocalVideoWithUI:(__kindof UIView *_Nullable)displayUI
                      isFullDisplay:(BOOL)isFull;
```

RTC事件, 设置本机视频预览的视频流数据显示在提供的displayUI上, 并设置其显示样式, isFull为YES时, 标识当接收的视频流铺满提供的displayUI, 为No时, 会按照接收视频流的视频比例显示在displayUI上.

#### 参数解释:

> displayUI 类型: 以UIView为基类的类型
>
> + 视频数据流显示的UI层

> isFull 类型: BOOL
>
> + 设置视频流显示的样式, YES: 铺满显示, No: 按比例显示

### CLS_ShowRemoteUserWithId:DisplayUI:isFullDisplay:

```objective-c
- (void)CLS_ShowRemoteUserWithId:(NSNumber *)user_id
                       DisplayUI:(__kindof UIView *_Nullable)displayUI
                   isFullDisplay:(BOOL)isFull;
```

RTC事件, 设置某用户Id的视频流数据显示在提供的displayUI上, 并设置其显示样式, isFull为YES时, 标识当接收的视频流铺满提供的displayUI, 为No时, 会按照接收视频流的视频比例显示在displayUI上.

#### 参数解释:

> user_id 类型: NSNumber
>
> + 要订阅的视频流用户的平台ID

> displayUI 类型: 以UIView为基类的类型
>
> + 视频数据流显示的UI层

> isFull 类型: BOOL
>
> + 设置视频流显示的样式, YES: 铺满显示, No: 按比例显示

### CLS_StartOnPlatform

```objective-c
- (void)CLS_StartOnPlatform;
```

RTC事件, 当前用户上台并推流. 在用户初始状态时, RTC服务并未自动让用户上台并推流, 需要开发者手动调用该方法让用户推流.

### CLS_LeavePlatform

```objective-c
- (void)CLS_LeavePlatform;
```

RTC事件, 如果需要用户下台不推流, 可以调用该方法让当前用户下台并结束推流.

### CLS_MuteAllRemoteUserStream:

```objective-c
- (void)CLS_MuteAllRemoteUserStream:(BOOL)mute;
```

RTC事件, 订阅或屏蔽所有远端推送过来的流数据, 包括视频与音频. 当开发者调用该方法并将mute=YES, 不仅会屏蔽当前房间内的所有用户的流数据, 对后登录的用户, 也将屏蔽. 如果想再次显示所有流时, 需要再调用该方法并将mute=No.

#### 参数解释:

> mute 类型: BOOL
>
> + 屏蔽或订阅所有流数据, YES: 屏蔽, No: 订阅

### CLS_RemoteUserStreamWithId:MuteStatus:

```objective-c
- (void)CLS_RemoteUserStreamWithId:(NSNumber *)userId
                        MuteStatus:(BOOL)mute;
```

RTC事件, 订阅或屏蔽指定的用户ID的流数据.

#### 参数解释:

> userId 类型: NSNumber
>
> + 指定的目标用户的平台ID

> mute 类型: BOOL
>
> + 订阅或屏蔽的状态, YES: 屏蔽, No: 订阅

### CLS_ChangedVideoMirrorDisplayMode:

```objective-c
- (void)CLS_ChangedVideoMirrorDisplayMode:(BOOL)mirrorMode;
```

RTC事件, 修改视频流显示的镜像状态, mirrorMode为YES时, 以镜像方式显示视频, 为No时, 为非镜像方式显示. 值得注意的是, 当开发者设置该方法时, 会刷新所有视频的显示样式, 并对后加入的用户的视频显示赋予设置的镜像模式显示.

#### 参数解释:

> mirrorMode 类型: BOOL
>
> + 镜像模式选择 YES: 镜像模式, No: 非镜像模式

# CLS_PlatformManagerDelegate

CLS_PlatformManagerDelegate 是iOS端SDK的所有事件的回调代理协议, 里面包含了SDK中所能提供的所有事件的回调.

## Index

### Events

* [CLS_PlatformManager:CurrentUserDidJoinedSystem:](#CurrentUserDidJoinedSystem)
* [CLS_PlatformManager:UserDidJoinedRoomWithId:Attrs:](#UserDidJoinedRoomWithId)
* [CLS_PlatformManager:UserDidLeavedRoomWithId:](#UserDidLeavedRoomWithId)
* [CLS_PlatformManager:UserUpdateAttrs:](#UserUpdateAttrs)
* [CLS_PlatformManager:RoomDidUpdatedAttrs:SenderUserId:](#RoomDidUpdatedAttrs)
* [CLS_PlatformManager:RoomStatusDidUpdate:](#RoomStatusDidUpdate)
* [CLS_PlatformManager:CurrentUserRemoteLoginWithMessage:](#CurrentUserRemoteLoginWithMessage)
* [CLS_PlatformManager:CurrentUserDidLeavedRoomWithId:](#CurrentUserDidLeavedRoomWithId)
* [CLS_PlatformManager:CurrentUserDidBeenKickoutFromRoomSenderUserWithId:](#CurrentUserDidBeenKickoutFromRoomSenderUserWithId)
* [CLS_PlatformManager:DidReceivedControlMessageWithContent:ReceiveType:ReceiveId:SenderId:](#DidReceivedControlMessageWithContent)
* [CLS_PlatformManager:DidReceivedChatMessageWithContent:ReceiveType:ReceiveId:SenderId:](#DidReceivedChatMessageWithContent)
* [CLS_PlatformManager:DidReceivedWhiteboardMessageWithContent:ReceiveType:ReceiveId:SenderId:](#DidReceivedWhiteboardMessageWithContent)
* [CLS_PlatformManager:UserDidStartedPublishStreamWithId:](#UserDidStartedPublishStreamWithId)
* [CLS_PlatformManager:UserDidStoppedPublishStreamWithId:](#UserDidStoppedPublishStreamWithId)
* [CLS_PlatformManager:RoomUsersAudioVolume:](#RoomUsersAudioVolume)
* [CLS_PlatformManager:RoomSharerDidPublishStream:](#RoomSharerDidPublishStream)
* [CLS_PlatformManager:RequestVideoStatusChanged:SenderId:](#RequestVideoStatusChanged)
* [CLS_PlatformManager:RequestAudioStatusChanged:SenderId:](#RequestAudioStatusChanged)
* [CLS_PlatformManager:RequestNameChanged:SenderId:](#RequestNameChanged)
* [CLS_PlatformManager:RequestRoleChanged:SenderId:](#RequestRoleChanged)
* [CLS_PlatformManager:ReceivedBreakoutStatusChanged:](#ReceivedBreakoutStatusChanged)
* [CLS_PlatformManager:ReceivedSystemCustomMessage:Type:SenderId:](#ReceivedSystemCustomMessage)
* [CLS_PlatformManager:ReceivedSystemMoveUserToSubRoomRequest:SenderId:](#ReceivedSystemMoveUserToSubRoomRequest)
* [CLS_PlatformManager:ReceivedSystemBroadcaseMessage:GroupId:SenderId:](#ReceivedSystemBroadcaseMessage)
* [CLS_PlatformManager:ReceivedSystemCallHostGroupId:SenderId:](#ReceivedSystemCallHostGroupId)
* [CLS_PlatformManager:ReceivedSystemChatChannelMessageWithContent:ReceivedType:SenderId:](#ReceivedSystemChatChannelMessageWithContent)

## 1.2 Listeners

### 1.2.1 CurrentUserDidJoinedSystem

```objective-c
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager CurrentUserDidJoinedSystem:(NSNumber *)roomId;
```

|      事件名      |               描述               |
| :--------------: | :------------------------------: |
| 当前用户加入房间 | 当前用户已经加入了该roomId的房间 |

#### 参数解释:

> roomId 类型: NSNumber
>
> + 已加入的房间平台ID

### 1.2.2 UserDidJoinedRoomWithId

```objective-c
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager UserDidJoinedRoomWithId:(NSNumber *)userId Attrs:(NSDictionary<NSString *, id> *)userAttrs;
```

|          事件名           |                     描述                     |
| :-----------------------: | :------------------------------------------: |
| RTM事件, 用户加入房间事件 | 平台用户加入了该房间, 并返回该用户的用户属性 |

#### 参数解释:

> userId 类型: NSNumber
>
> + 已加入房间的用户平台ID

> userAttrs 类型: NSDictionary<NSString *, id>
>
> + 该用户设置的自己的用户属性<key: 属性名, value: 属性值>

### 1.2.3 UserDidLeavedRoomWithId

```objective-c
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager UserDidLeavedRoomWithId:(NSNumber *)userId;
```

|          事件名           |               描述               |
| :-----------------------: | :------------------------------: |
| RTM事件, 用户离开房间事件 | 某ID为userId的用户离开了当前房间 |

#### 参数解释:

> userId 类型: NSNumber
>
> + 离开用户的平台用户ID

### 1.2.4 UserUpdateAttrs

```objective-c
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager UserUpdateAttrs:(NSDictionary<NSString *, id> *)attrs WithUserId:(NSNumber *)userId;
```

|          事件名           |                          描述                           |
| :-----------------------: | :-----------------------------------------------------: |
| RTM事件, 用户属性更新事件 | 某ID为userId的用户更新了自己的用户属性, 更新内容为attrs |

#### 参数解释:

> attrs 类型: NSDictionary<NSString *, id>
>
> + 更新的属性内容, <key: 更新的属性名, value: 更新后的属性值>

### 1.2.5 RoomDidUpdatedAttrs

```objective-c
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager RoomDidUpdatedAttrs:(NSDictionary<NSString *, id> *)roomAttrs SenderUserId:(NSNumber *)userId;
```

|        事件名         |                          描述                           |
| :-------------------: | :-----------------------------------------------------: |
| RTM事件, 房间属性更新 | 用户ID为userId的用户更新了房间属性, 更新内容为roomAttrs |

#### 参数解释:

> roomAttrs 类型: NSDictionary<NSString *, id>
>
> + 更新的房间属性内容, <key: 更新的属性名, value: 更新后的属性值>

> userId 类型: NSNumber
>
> + 更新者的用户平台ID

### 1.2.6 RoomStatusDidUpdate

```objective-c
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager RoomStatusDidUpdate:(CLS_RoomStatusEnum)status;
```

|      事件名      |               描述               |
| :--------------: | :------------------------------: |
| 房间状态更新事件 | 当前房间的房间状态已更新为status |

#### 参数解释:

> status 类型: CLS_RoomStatusEnum
>
> + 更新后的房间状态, CLS_RoomStatus_START: 房间已开启, CLS_RoomStatus_STOP: 房间已关闭

### 1.2.7 CurrentUserRemoteLoginWithMessage

```objective-c
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager CurrentUserRemoteLoginWithMessage:(NSString *)message;
```

|            事件名             |                             描述                             |
| :---------------------------: | :----------------------------------------------------------: |
| RTM事件, 当前账号已在远端登录 | 当前用户ID的账号, 已经在远端再登录, 当前设备被强制下线, message为提醒消息 |

#### 参数解释:

> message 类型: NSString
>
> + 提醒消息, 返回设备类型

### 1.2.8 CurrentUserDidLeavedRoomWithId

```objective-c
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager CurrentUserDidLeavedRoomWithId:(NSNumber *)roomId;
```

|             事件名              |                      描述                      |
| :-----------------------------: | :--------------------------------------------: |
| RTM事件, 当前账号退出该房间事件 | 当前用户已经离开了该房间, 并返回房间平台roomId |

#### 参数解释:

> roomId 类型: NSNumber
>
> + 当前房间的平台ID

### 1.2.9 CurrentUserDidBeenKickoutFromRoomSenderUserWithId

```objective-c
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager CurrentUserDidBeenKickoutFromRoomSenderUserWithId:(NSNumber *)userId;
```

|             事件名              |                     描述                      |
| :-----------------------------: | :-------------------------------------------: |
| RTM事件, 当前用户被踢出房间事件 | 用户接收到被踢出的事件消息, userId为发送者ID. |

#### 参数解释:

> userId 类型: NSNumber
>
> + 发送者的平台ID

### 1.2.10 DidReceivedControlMessageWithContent

```objective-c
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
DidReceivedControlMessageWithContent:(NSString *)content_json
                ReceiveType:(NSInteger)ReceiveType
                  ReceiveId:(NSNumber *)ReceiveId
                   SenderId:(NSNumber *)senderId;
```

|                  事件名                  |                             描述                             |
| :--------------------------------------: | :----------------------------------------------------------: |
| RTM事件, 接收到来自Control通道的消息事件 | 接收到来自Control通道的JSON消息, 消息类型为ReceiveType, 接受者为ReceiveId, 发送者为senderId |

#### 参数解释:

> content_json 类型: NSString
>
> + 在Control通道发送的消息的JSON字符串

>ReceiveType 类型: NSInteger
>
>+ 消息发送类型, 1: 点对点发送给用户, 2: 房间广播

>ReceiveId 类型: NSNumber
>
>+ 消息接收者的平台ID

> senderId 类型: NSNumber
>
> + 消息发送者的平台ID

### 1.2.11 DidReceivedChatMessageWithContent

```objective-c
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
DidReceivedChatMessageWithContent:(NSString *)content_json
                ReceiveType:(NSInteger)ReceiveType
                  ReceiveId:(NSNumber *)ReceiveId
                   SenderId:(NSNumber *)senderId;
```

|                事件名                 |                             描述                             |
| :-----------------------------------: | :----------------------------------------------------------: |
| RTM事件, 接收到来自Chat通道的消息事件 | 接收到来自Chat通道的JSON消息, 消息类型为ReceiveType, 接受者为ReceiveId, 发送者为senderId |

#### 参数解释:

> content_json 类型: NSString
>
> + 在Chat通道发送的消息的JSON字符串

>ReceiveType 类型: NSInteger
>
>+ 消息发送类型, 1: 点对点发送给用户, 2: 房间广播

>ReceiveId 类型: NSNumber
>
>+ 消息接收者的平台ID

> senderId 类型: NSNumber
>
> + 消息发送者的平台ID

### 1.2.12 DidReceivedWhiteboardMessageWithContent

```objective-c
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
DidReceivedWhiteboardMessageWithContent:(NSString *)content_json
                ReceiveType:(NSInteger)ReceiveType
                  ReceiveId:(NSNumber *)ReceiveId
                   SenderId:(NSNumber *)senderId;
```

|                   事件名                    |                             描述                             |
| :-----------------------------------------: | :----------------------------------------------------------: |
| RTM事件, 接收到来自Whiteboard通道的消息事件 | 接收到来自Whiteboard通道的JSON消息, 消息类型为ReceiveType, 接受者为ReceiveId, 发送者为senderId |

#### 参数解释:

> content_json 类型: NSString
>
> + 在Whiteboard通道发送的消息的JSON字符串

>ReceiveType 类型: NSInteger
>
>+ 消息发送类型, 1: 点对点发送给用户, 2: 房间广播

>ReceiveId 类型: NSNumber
>
>+ 消息接收者的平台ID

> senderId 类型: NSNumber
>
> + 消息发送者的平台ID

### 1.2.13 UserDidStartedPublishStreamWithId

```objective-c
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
UserDidStartedPublishStreamWithId:(NSNumber *)userId;
```

|            事件名             |                             描述                             |
| :---------------------------: | :----------------------------------------------------------: |
| RTC事件, 接收到用户的推流事件 | 在RTC房间中接收到有用户已上台并正在推流, userId为推流者的平台ID |

#### 参数解释:

> userId 类型: NSNumber
>
> + 推流用户的平台ID

### 1.2.14 UserDidStoppedPublishStreamWithId

```objective-c
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
UserDidStoppedPublishStreamWithId:(NSNumber *)userId;
```

|              事件名               |                             描述                             |
| :-------------------------------: | :----------------------------------------------------------: |
| RTC事件, 接收到用户的结束推流事件 | 在RTC房间中接收到有用户下台并结束推流, userId为结束推流者的平台ID |

#### 参数解释:

> userId 类型: NSNumber
>
> + 结束推流用户的平台ID

### 1.2.15 RoomUsersAudioVolume

```objective-c
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
       RoomUsersAudioVolume:(NSArray<CLS_PlatformAudioVolumeModel *> *)infos;
```

|              事件名               |                             描述                             |
| :-------------------------------: | :----------------------------------------------------------: |
| RTC事件, 接收到房间用户的声音事件 | 在RTC房间中接收到当前音频有声音的用户与音频信息的回调, infos为声音信息列表 |

#### 参数解释:

> infos 类型: NSArray
>
> + 存储当前有声音的用户的列表, CLS_PlatformAudioVolumeModel为用户的声音信息

### 1.2.16 RoomSharerDidPublishStream

```objective-c
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
 RoomSharerDidPublishStream:(NSNumber *)shareId;
```

|              事件名               |                           描述                           |
| :-------------------------------: | :------------------------------------------------------: |
| RTC事件, 接收到房间共享者推流事件 | 在RTC房间中接收到共享者正在推流, shareId为共享者的平台ID |

#### 参数解释:

> shareId 类型: NSNumber
>
> + 共享用户的平台ID

### 1.2.17 RequestVideoStatusChanged

```objective-c
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
  RequestVideoStatusChanged:(BOOL)value
                   SenderId:(NSNumber *)senderId;
```

|            事件名             |                             描述                             |
| :---------------------------: | :----------------------------------------------------------: |
| RTM事件, 请求视频状态更新事件 | 房间中接收到其他管理者角色的用户对当前用户的视频状态更新请求, value为请求目标值, senderId为发送者平台ID |

#### 参数解释:

> value 类型: BOOL
>
> + 请求更新的目标值, YES: 打开视频, No: 关闭视频

> senderId 类型: NSNumber
>
> + 发送请求的用户平台ID

### 1.2.18 RequestAudioStatusChanged

```objective-c
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
  RequestAudioStatusChanged:(BOOL)value
                   SenderId:(NSNumber *)senderId;
```

|            事件名             |                             描述                             |
| :---------------------------: | :----------------------------------------------------------: |
| RTM事件, 请求音频状态更新事件 | 房间中接收到其他管理者角色的用户对当前用户的音频状态更新请求, value为请求目标值, senderId为发送者平台ID |

#### 参数解释:

> value 类型: BOOL
>
> + 请求更新的目标值, YES: 打开音频, No: 关闭音频

> senderId 类型: NSNumber
>
> + 发送请求的用户平台ID

### 1.2.19 RequestNameChanged

```objective-c
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
         RequestNameChanged:(NSString *)value
                   SenderId:(NSNumber *)senderId;
```

|          事件名           |                             描述                             |
| :-----------------------: | :----------------------------------------------------------: |
| RTM事件, 请求修改昵称事件 | 房间中接收到其他管理者角色的用户对当前用户的昵称更新修改, value为请求目标昵称值, senderId为发送者平台ID |

#### 参数解释:

> value 类型: NSString
>
> + 请求更新的目标昵称内容

> senderId 类型: NSNumber
>
> + 发送请求的用户平台ID

### 1.2.20 RequestRoleChanged

```objective-c
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
         RequestRoleChanged:(NSString *)value
                   SenderId:(NSNumber *)senderId;
```

|            事件名             |                             描述                             |
| :---------------------------: | :----------------------------------------------------------: |
| RTM事件, 请求修改用户角色事件 | 房间中接收到其他管理者角色的用户对当前用户的角色更改, value为请求目标角色, senderId为发送者平台ID |

#### 参数解释:

> value 类型: NSString
>
> + 请求更新的目标角色, 包括co-host, attendee

> senderId 类型: NSNumber
>
> + 发送请求的用户平台ID

### 1.2.21 ReceivedBreakoutStatusChanged

```objective-c
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
ReceivedBreakoutStatusChanged:(BOOL)status;
```

|                 事件名                  |                             描述                             |
| :-------------------------------------: | :----------------------------------------------------------: |
| RTM事件,  SDK分组功能, 分组状态更新事件 | 房间中接收到SDK的分组功能的分组状态更新, status为当前分组状态值. |

#### 参数解释:

> status 类型: BOOL
>
> + 当前分组状态, YES: 已开始分组, No: 分组状态已结束

### 1.2.22 ReceivedSystemCustomMessage

```objective-c
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
ReceivedSystemCustomMessage:(NSDictionary *)opts
                       Type:(NSString *)typeName
                   SenderId:(NSNumber *)senderId;
```

|                     事件名                      |                             描述                             |
| :---------------------------------------------: | :----------------------------------------------------------: |
| RTM事件,  接收到在Control通道内的自定义消息事件 | 房间中接收到Control通道的自定义消息, opts为自定义消息内容, typeName为自定义消息的类型名, senderId为发送者平台ID |

#### 参数解释:

> opts 类型: NSDictionary
>
> + 自定义消息体中的消息内容

> typeName 类型: NSString
>
> + 自定义消息体的消息类型名

> senderId 类型: NSNumber
>
> + 消息发送者的平台ID

### 1.2.23 ReceivedSystemMoveUserToSubRoomRequest

```objective-c
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
ReceivedSystemMoveUserToSubRoomRequest:(NSNumber *)toRoomId
                   SenderId:(NSNumber *)senderId;
```

|                 事件名                  |                             描述                             |
| :-------------------------------------: | :----------------------------------------------------------: |
| RTM事件,  SDK分组功能, 用户分组转移事件 | 房间中接收到SDK的分组功能的用户分组转移事件, toRoomId为要转移的目标分组ID, senderId为发送者的平台ID |

#### 参数解释:

> toRoomId 类型: NSNumber
>
> + 要转移的目标分组ID

> senderId 类型: NSNumber
>
> + 消息发送者的平台ID

### 1.2.24 ReceivedSystemBroadcaseMessage

```objective-c
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
ReceivedSystemBroadcaseMessage:(NSString *)message
                    GroupId:(NSNumber *)groupId
                   SenderId:(NSNumber *)senderId;
```

|                    事件名                     |                             描述                             |
| :-------------------------------------------: | :----------------------------------------------------------: |
| RTM事件,  SDK分组功能, 接收到分组广播消息事件 | 房间中接收到SDK的分组功能, 用户接收到发给某或所有分组的广播消息事件, message为广播消息, groupId为指定的分组, senderId为发送者的平台ID |

#### 参数解释:

> message 类型: NSString
>
> + 广播消息的消息内容

> groupId 类型: NSNumber
>
> + 指定发送到的分组ID, 可空, 如果为空则为发给所有分组

> senderId 类型: NSNumber
>
> + 消息发送者的平台ID

### 1.2.25 ReceivedSystemCallHostGroupId

```objective-c
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
ReceivedSystemCallHostGroupId:(NSNumber *)groupId
                   SenderId:(NSNumber *)senderId;
```

|                           事件名                            |                             描述                             |
| :---------------------------------------------------------: | :----------------------------------------------------------: |
| RTM事件,  SDK分组功能, 接收子分组发送的呼叫管理员的通知事件 | 房间中接收到SDK的分组功能, 管理者角色接收子分组发送的呼叫管理员的通知事件, groupId为呼叫用户所在的分组, senderId为发送者的平台ID |

#### 参数解释:

> groupId 类型: NSNumber
>
> + 呼叫用户所在的分组的分组ID

> senderId 类型: NSNumber
>
> + 消息发送者的平台ID

### 1.2.26 ReceivedSystemChatChannelMessageWithContent

```objective-c
- (void)CLS_PlatformManager:(CLS_PlatformManager *)manager
ReceivedSystemChatChannelMessageWithContent:(NSString *)content
               ReceivedType:(NSString *)type
                   SenderId:(NSNumber *)senderId;
```

|                   事件名                    |                             描述                             |
| :-----------------------------------------: | :----------------------------------------------------------: |
| RTM事件,  SDK的聊天功能, 接收到聊天内容事件 | 房间中接收到SDK的聊天功能, 用户发送的聊天消息, content为聊天内容, type为聊天消息类型, senderId为发送者的平台ID |

#### 参数解释:

> content 类型: NSString
>
> + 聊天的文字内容

> type 类型: NSString
>
> + 聊天消息类型 common: 普通聊天, system: 系统消息

> senderId 类型: NSNumber
>
> + 消息发送者的平台ID

