//
//  QIMManager+Login.h
//  qunarChatIphone
//
//  Created by 李露 on 2018/4/3.
//

#import "QIMManager.h"

@interface QIMManager (Login)

/**
 获取当前登录状态
 */
- (BOOL)isLogin;

/**
 注册用户

 @param userName 用户名
 @param pwd 密码
 */
- (void)registerWithUserName:(NSString *)userName WithPassWord:(NSString *)pwd;

- (void)registerFaild;

/**
 缓存用户登录

 @param userName 用户名称
 @param pwd 用户密码
 @param navDict 用户导航信息缓存
 */
- (void)loginWithUserName:(NSString *)userName WithPassWord:(NSString *)pwd WithLoginNavDict:(NSDictionary *)navDict;
- (void)addUserCacheWithUserId:(NSString *)userId WithUserFullJid:(NSString *)userFullJid WithNavDict:(NSDictionary *)navDict;

/**
 用户登录

 @param userName 用户名
 @param pwd 用户密码
 */
- (void)loginWithUserName:(NSString *)userName WithPassWord:(NSString *)pwd;


/**
 获取本地已缓存用户列表
 */
- (NSArray *)getLoginUsers;


/**
 清空KeyChain中用户缓存信息
 */
- (void)clearLogginUser;


- (void)saveUserInfoWithName:(NSString *)userName passWord:(NSString *)pwd;

/**
 退出登录
 */
- (void)quitLogin;

/**
 前台登录
 */
- (BOOL)forgelogin;

- (NSString *)getFormStringByDiction:(NSDictionary *)diction;

/**
 重新登录
 */
- (void)relogin;

/**
 取消登录
 */
- (void)cancelLogin;

- (void)sendHeartBeat;

/**
 是否为自动登录
 */
- (BOOL)isAutoLogin;

/**
 设置自动登录
 */
- (void)setAutoLogin:(BOOL)flag;

- (NSDictionary *)QChatLoginWithUserId:(NSString *)userId rsaPassword:(NSString *)password type:(NSString *)type;

@end
