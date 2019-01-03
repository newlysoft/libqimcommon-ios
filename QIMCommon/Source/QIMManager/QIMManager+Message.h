//
//  QIMManager+Message.h
//  qunarChatIphone
//
//  Created by 李露 on 2018/4/1.
//

#import "QIMManager.h"

#pragma mark - 消息

@interface QIMManager (Message)

- (NSArray *)getMsgsForMsgType:(QIMMessageType)msgType;
- (NSDictionary *)getMsgDictByMsgId:(NSString *)msgId;

- (Message *)getMsgByMsgId:(NSString *)msgId;

- (void)checkMsgTimeWithJid:(NSString *)jid WithRealJid:(NSString *)realJid WithMsgDate:(long long)msgDate WithGroup:(BOOL)flag;

- (void)checkMsgTimeWithJid:(NSString *)jid WithMsgDate:(long long)msgDate WithGroup:(BOOL)flag;

#pragma mark - 公共消息

/**
 根据用户Id设置Message附加属性 {'cctext', 'bu'}
 
 @param appendInfoDict 附加字典
 @param userId 用户Id
 */
- (void)setAppendInfo:(NSDictionary *)appendInfoDict ForUserId:(NSString *)userId;

/**
 根据用户Id获取Message附加属性  {'cctext', 'bu'}
 
 @param userId 用户Id
 */
- (NSDictionary *)getAppendInfoForUserId:(NSString *)userId;

/**
 根据用户Id设置ChannelId
 
 @param channelId channelId
 @param userId 用户Id
 */
- (void)setChannelInfo:(NSString *)channelId ForUserId:(NSString *)userId;

/**
 根据用户Id获取ChannelId
 
 @param userId 用户Id
 */
- (NSString *)getChancelInfoForUserId:(NSString *)userId;


/**
 根据用户Id设置 点击聊天内容中的URL务必拼接的参数 （众包需求）
 
 @param param param
 @param jid 用户Id
 */
- (void)setConversationParam:(NSDictionary *)param WithJid:(NSString *)jid;

/**
 根据用户Id获取 点击聊天内容中的URL务必拼接的参数 （众包需求）
 
 @param param param
 @param jid 用户Id
 */
- (NSDictionary *)conversationParamWithJid:(NSString *)jid;

- (void)sendTypingToUserId:(NSString *)userId;

- (void)saveMsg:(Message *)msg ByJid:(NSString *)sid;

//更新消息
- (void)updateMsg:(Message *)msg ByJid:(NSString *)sid;

- (void)deleteMsg:(Message *)msg ByJid:(NSString *)sid;

- (BOOL)sendControlStateWithMessagesIdArray:(NSArray *)messages WithXmppId:(NSString *)xmppId;
- (BOOL)sendReadStateWithMessagesIdArray:(NSArray *)messages WithXmppId:(NSString *)xmppId;
- (BOOL)sendReadStateWithMessagesIdArray:(NSArray *)messages WithXmppId:(NSString *)xmppId WithRealJid:(NSString *)realJid;
- (BOOL)sendReadstateWithGroupLastMessageTime:(long long) lastTime withGroupId:(NSString *) groupId;


#pragma mark - 单人消息

/**
 发送窗口抖动
 
 @param userId 对方用户Id
 */
- (Message *)sendShockToUserId:(NSString *)userId;


/**
 撤销单人消息
 
 @param messageId messageId
 @param message message
 @param jid jid
 */
- (void)revokeMessageWithMessageId:(NSString *)messageId message:(NSString *)message ToJid:(NSString *)jid;

/**
 发送文件消息
 
 @param fileJson 文件URL
 @param userId 对方UserId
 @param msgId 消息Id
 */
- (void)sendFileJson:(NSString *)fileJson ToUserId:(NSString *)userId WithMsgId:(NSString *)msgId;

/**
 发送语音消息
 
 @param voiceUrl 语音文件地址
 @param voiceName 语音文件名
 @param seconds 语音时长
 @param userId 接收方Id
 */
- (Message *)sendVoiceUrl:(NSString *)voiceUrl withVoiceName:(NSString *)voiceName withSeconds:(int)seconds ToUserId:(NSString *)userId;


/**
 发送消息
 
 @param msg 消息Message对象
 @param userId 接收方Id
 */
- (Message *)sendMessage:(Message *)msg ToUserId:(NSString *)userId;

/**
 发送单人消息
 
 @param msg 消息Body
 @param info 消息ExtendInfo
 @param userId 接收Id
 @param msgType 消息Type
 */
- (Message *)sendMessage:(NSString *)msg WithInfo:(NSString *)info ToUserId:(NSString *)userId WihtMsgType:(int)msgType;


// Note消息自动回复消息(您好，我是在线客服xxx，很高兴为您服务)
- (Message *)createNoteReplyMessage:(NSString *)msg ToUserId:(NSString *)user;

#pragma mark - 群消息


/**
 发送群消息
 
 @param msg 消息Body
 @param groupId 群Id
 */
- (Message *)sendMessage:(NSString *)msg ToGroupId:(NSString *)groupId ;


/**
 发送群消息
 
 @param msg 消息Body
 @param info 消息ExtendInfo
 @param groupId 群Id
 @param msgType 消息Type
 */
- (Message *)sendMessage:(NSString *)msg WithInfo:(NSString *)info ToGroupId:(NSString *)groupId WihtMsgType:(int)msgType;


/**
 发送群消息
 
 @param msg 消息Body
 @param info 消息ExtendInfo
 @param groupId 群Id
 @param msgType 消息Type
 @param msgId 消息Id
 */
- (Message *)sendMessage:(NSString *)msg WithInfo:(NSString *)info ToGroupId:(NSString *)groupId WihtMsgType:(int)msgType WithMsgId:(NSString *)msgId;

/**
 发送群窗口抖动
 
 @param groupId 群Id
 */
- (Message *)sendGroupShockToGroupId:(NSString *)groupId;

/**
 回复群消息
 
 @param replyMsgId replyMsgId
 @param replyUser replyUser
 @param msgId msgId
 @param message message
 @param groupId groupId
 */
- (BOOL)sendReplyMessageId:(NSString *)replyMsgId WithReplyUser:(NSString *)replyUser WithMessageId:(NSString *)msgId WithMessage:(NSString *)message ToGroupId:(NSString *)groupId;

/**
 撤销群消息
 
 @param messageId messageId
 @param message message
 @param jid
 */
- (void)revokeGroupMessageWithMessageId:(NSString *)messageId message:(NSString *)message ToJid:(NSString *)jid;

/**
 发送群文件
 
 @param fileJson 文件地址
 @param groupId 群Id
 @param msgId 消息Id
 */
- (void)sendFileJson:(NSString *)fileJson ToGroupId:(NSString *)groupId WihtMsgId:(NSString *)msgId;


/**
 发送群语音消息
 
 @param voiceUrl 语音文件地址
 @param voiceName 语音文件名称
 @param seconds 语音时长
 @param groupId 群Id
 */
- (Message *)sendGroupVoiceUrl:(NSString *)voiceUrl withVoiceName:(NSString *)voiceName withSeconds:(int)seconds ToGroupId:(NSString *)groupId;

// Note消息自动回复消息(您好，我是在线客服xxx，很高兴为您服务)
- (Message *)createNoteReplyMessage:(NSString *)msg ToGroupId:(NSString *)groupId;

//发送wlan消息
-(void)sendWlanMessage:(NSString *)content to:(NSString *)targetID extendInfo:(NSString *)extendInfo msgType:(int) msgType completionHandler:(void (^)(NSData * data, NSURLResponse * response, NSError * error))completionHandler;


// 发送音视频消息
- (void)sendAudioVideoWithType:(int)msgType WithBody:(NSString *)body WithExtentInfo:(NSString *)extentInfo WithMsgId:(NSString *)msgId ToJid:(NSString *)jid;

- (Message *)createMessageWithMsg:(NSString *)msg extenddInfo:(NSString *)extendInfo userId:(NSString *)userId userType:(ChatType)userType msgType:(QIMMessageType)msgType forMsgId:(NSString *)mId willSave:(BOOL)willSave;
- (Message *)createMessageWithMsg:(NSString *)msg extenddInfo:(NSString *)extendInfo userId:(NSString *)userId realJid:(NSString *)realJid userType:(ChatType)userType msgType:(QIMMessageType)msgType forMsgId:(NSString *)mId msgState:(MessageState)msgState willSave:(BOOL)willSave ;
- (Message *)createMessageWithMsg:(NSString *)msg extenddInfo:(NSString *)extendInfo userId:(NSString *)userId realJid:(NSString *)realJid userType:(ChatType)userType msgType:(QIMMessageType)msgType forMsgId:(NSString *)mId willSave:(BOOL)willSave;
- (Message *)sendMessage:(Message *)msg withChatType:(ChatType)chatType channelInfo:(NSString *)channelInfo realFrom:(NSString *)realFrom realTo:(NSString *)realTo ochatJson:(NSString *)ochatJson;
- (Message *)createMessageWithMsg:(NSString *)msg extenddInfo:(NSString *)extendInfo userId:(NSString *)userId userType:(ChatType)userType msgType:(QIMMessageType)msgType;

- (Message *)createMessageWithMsg:(NSString *)msg extenddInfo:(NSString *)extendInfo userId:(NSString *)userId userType:(ChatType)userType msgType:(QIMMessageType)msgType backinfo:(NSString *)backInfo;
- (Message *)createMessageWithMsg:(NSString *)msg extenddInfo:(NSString *)extendInfo userId:(NSString *)userId userType:(ChatType)userType msgType:(QIMMessageType)msgType forMsgId:(NSString *)mId;
//- (Message *)sendMessage:(NSString *)msg ToUserId:(NSString *)userId;

//- (void)setNotReaderMsgCount:(int)count ForJid:(NSString *)jid;

- (void)synchronizeChatSessionWithUserId:(NSString *)userId WithChatType:(ChatType)chatType WithRealJid:(NSString *)realJid;

#pragma mark - 位置共享

- (Message *)sendShareLocationMessage:(NSString *)msg WithInfo:(NSString *)info ToJid:(NSString *)jid WihtMsgType:(int)msgType;
- (Message *)beginShareLocationToUserId:(NSString *)userId WithShareLocationId:(NSString *)shareLocationId;
- (Message *)beginShareLocationToGroupId:(NSString *)GroupId WithShareLocationId:(NSString *)shareLocationId;
- (BOOL)joinShareLocationToUsers:(NSArray *)users WithShareLocationId:(NSString *)shareLocationId;
- (BOOL)sendMyLocationToUsers:(NSArray *)users WithLocationInfo:(NSString *)locationInfo ByShareLocationId:(NSString *)shareLocationId;
- (BOOL)quitShareLocationToUsers:(NSArray *)users WithShareLocationId:(NSString *)shareLocationId;
- (NSString *)getShareLocationIdByJid:(NSString *)jid;
- (NSString *)getShareLocationFromIdByShareLocationId:(NSString *)shareLocationId;
- (NSArray *)getShareLocationUsersByShareLocationId:(NSString *)shareLocationId;


#pragma mark - 未读数

- (void)updateMsgReadCompensateSetWithMsgId:(NSString *)msgId WithAddFlag:(BOOL)flag WithState:(MessageState)state;

- (NSMutableSet *)getLastMsgCompensateReadSet;

/**
 *  返回未读消息数组
 */
- (NSArray *)getNotReaderMsgList;

/**
 清空所有未读消息
 */
- (void) clearAllNoRead;

/**
 清空HeadLine未读消息
 */
- (void)clearSystemMsgNotReadWithJid:(NSString *)jid;

/**
 根据Jid清空未读消息
 
 @param jid 用户Id
 */
- (void)clearNotReadMsgByJid:(NSString *)jid;

/**
 根据Jid & RealJid清空未读消息
 
 @param jid 用户Id
 @param realJid 真实用户Id
 */
- (void)clearNotReadMsgByJid:(NSString *)jid ByRealJid:(NSString *)realJid;

/**
 根据群Id清空未读消息
 
 @param groupId 群id
 */
- (void)clearNotReadMsgByGroupId:(NSString *)groupId;

/**
 获取Jid下的未读消息数
 
 @param jid Jid
 */
- (NSInteger)getNotReadMsgCountByJid:(NSString *)jid;

//自增未读数
- (void)increasedNotReadMsgCountByJid:(NSString *)jid WithReadJid:(NSString *)realJid;

- (void)increasedNotReadMsgCountByJid:(NSString *)jid;

//清除内存未读数
- (void)decrementNotReadMsgCountByJid:(NSString *)jid WithReadJid:(NSString *)realJid;

- (void)decrementNotReadMsgCountByJid:(NSString *)jid;

/**
 获取Jid & 真实Id下的未读消息数
 
 @param jid 用户Id
 @param realJid 真实用户Id
 */
- (NSInteger)getNotReadMsgCountByJid:(NSString *)jid WithRealJid:(NSString *)realJid;

- (void)updateAppNotReadCount;

/**
 获取App总未读数
 */
- (NSInteger)getAppNotReaderCount;

/**
 获取接收但不提醒的未读数
 */
- (NSInteger)getNotRemindNotReaderCount;

/**
 获取骆驼帮未读消息数
 */
- (void)getExploreNotReaderCount;

/**
 获取QChat商家未回复留言数
 */
- (NSInteger)getLeaveMsgNotReaderCount;

- (void)updateNotReadCountCacheByJid:(NSString *)jid WithRealJid:(NSString *)realJid;
- (void)updateMessageControlStateWithNewState:(MessageState)state ByMsgIdList:(NSArray *)MsgIdList;
- (void)updateMessageStateWithNewState:(MessageState)state ByMsgIdList:(NSArray *)MsgIdList;

- (void)updateNotReadCountCacheByJid:(NSString *)jid;

- (void)saveChatId:(NSString *)chatId ForUserId:(NSString *)userId;

- (void)setMsgSentFaild;


- (NSDictionary *)parseMessageByMsgRaw:(id)msgRaw;

- (NSDictionary *)parseOriginMessageByMsgRaw:(id)msgRaw;

- (NSArray *)getNotReadMsgIdListByUserId:(NSString *)userId WithRealJid:(NSString *)realJid;

- (void)getMsgListByUserId:(NSString *)userId WithRealJid:(NSString *)realJid WihtLimit:(int)limit WithOffset:(int)offset WihtComplete:(void (^)(NSArray *))complete;

- (void)getMsgListByUserId:(NSString *)userId FromTimeStamp:(long long)timeStamp WihtComplete:(void (^)(NSArray *))complete;

- (void)getMsgListByUserId:(NSString *)userId WithRealJid:(NSString *)realJid FromTimeStamp:(long long)timeStamp WihtComplete:(void (^)(NSArray *))complete;

- (void)getConsultServerMsgLisByUserId:(NSString *)userId WithVirtualId:(NSString *)virtualId WithLimit:(int)limit WithOffset:(int)offset WithComplete:(void (^)(NSArray *))complete;

- (NSArray *)getFSMsgByXmppId:(NSString *)xmppId;
- (NSDictionary *)getFSMsgByMsgId:(NSString *)msgId;

- (void)checkOfflineMsg;

- (NSMutableArray *)searchLocalMessageByKeyword:(NSString *)keyWord
                                         XmppId:(NSString *)xmppid
                                        RealJid:(NSString *)realJid;

- (NSArray *)getLocalMediasByXmppId:(NSString *)xmppId ByRealJid:(NSString *)realJid;

- (NSArray *)getMsgsForMsgType:(NSArray *)msgTypes ByXmppId:(NSString *)xmppId ByReadJid:(NSString *)realJid;

- (NSArray *)getMsgsByKeyWord:(NSString *)keyWork ByXmppId:(NSString *)xmppId ByReadJid:(NSString *)realJid;

- (NSArray *)getMsgsForMsgType:(NSArray *)msgTypes ByXmppId:(NSString *)xmppId;

@end
