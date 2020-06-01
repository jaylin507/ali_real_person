//
//  RPSDK+Deprecated.h
//  ALRealIdentity
//
//  Created by  Hank Zhang on 2019/12/5.
//  Copyright © 2019 Alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RPSDKInterface.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark - 已废弃，预计于 2020.5.10 删除，请尽快迁移至新接口

typedef NS_ENUM(NSInteger, RPSDKEnv) {
    RPSDKEnvDaily,
    RPSDKEnvPre,
    RPSDKEnvOnline
} DEPRECATED_ATTRIBUTE;

typedef NS_ENUM(NSInteger, RPVerifyState) {
    RPVerifyStateNotVerify = -1,
    RPVerifyStatePass = 1,
    RPVerifyStateFail = 2,
} DEPRECATED_ATTRIBUTE;

typedef void (^RPCompletedHandler)(RPVerifyState verifyState, NSString * _Nullable code) DEPRECATED_ATTRIBUTE;

@interface RPSDK (Deprecated)

@property (class, nonatomic, assign) BOOL isPresentationAnimationEnabled
DEPRECATED_MSG_ATTRIBUTE("请替换为 RPConfiguration 的 isTransitionAnimationEnabled 属性。");

+ (void)initialize:(RPSDKEnv)env
DEPRECATED_MSG_ATTRIBUTE("RPSDK 不再需要初始化操作，请删除此方法调用。");

+ (void)initialize
DEPRECATED_MSG_ATTRIBUTE("RPSDK 不再需要初始化操作，请删除此方法调用。");

+ (void)initializeHasWV:(RPSDKEnv)env
DEPRECATED_MSG_ATTRIBUTE("RPSDK 不再需要初始化操作，请删除此方法调用。");

+ (void)setAppName:(NSString*)appName
        appVersion:(NSString*)appVersion
DEPRECATED_MSG_ATTRIBUTE("RPSDK 不再需要设置应用名和版本，请删除此方法调用。");

+ (void)start:(NSString *)verifyToken
  rpCompleted:(RPCompletedHandler)rpCompleted
       withVC:(UINavigationController *)nav
DEPRECATED_MSG_ATTRIBUTE("请替换为 [RPSDK startWithVerifyToken:viewController:completion:] 方法。");

+ (void)startVerifyByNative:(NSString*)verifyToken
                rpCompleted:(RPCompletedHandler)rpCompleted
                     withVC:(UIViewController*)nav
DEPRECATED_MSG_ATTRIBUTE("请替换为 [RPSDK startByNativeWithVerifyToken:viewController:completion:] 方法。");

+ (void)startVerifyByURL:(NSString *)urlString
             rpCompleted:(RPCompletedHandler)rpCompleted
                  withVC:(UINavigationController *)nav
DEPRECATED_MSG_ATTRIBUTE("请替换为 [RPSDK startByURL:viewController:completion:] 方法。");

+ (void)setLocalAccelerate:(bool)open
DEPRECATED_MSG_ATTRIBUTE("RPSDK 不提供本地加速，请删除此方法调用。");

+ (NSString *)getSubCode
DEPRECATED_MSG_ATTRIBUTE("请从 RPResult 查看结果，此方法将返回空字符串，请删除此方法调用。");

+ (NSString *)getSubMessage
DEPRECATED_MSG_ATTRIBUTE("请从 RPResult 查看结果，此方法将返回空字符串，请删除此方法调用。");

@end

NS_ASSUME_NONNULL_END
