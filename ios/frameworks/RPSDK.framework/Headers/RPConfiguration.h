//
//  RPConfiguration.h
//  ALRealIdentity
//
//  Created by  Hank Zhang on 2020/2/20.
//  Copyright © 2020 Alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 NS_ENUM(NSInteger, RPTransitionStyle)
 实人认证页面弹出风格
 */
typedef NS_ENUM(NSInteger, RPTransitionStyle) {

    /**
     present
     */
    RPTransitionStylePresent = 0,

    /**
     push
     */
    RPTransitionStylePush,
};

/**
 `RPViewControllerHandler` 活体检测视图控制器回调。

 @param viewController 活体检测视图控制器。
 */
typedef void (^RPViewControllerHandler)(UIViewController *viewController);

/**
 `RPConfiguration` 实人认证配置
 */
NS_SWIFT_NAME(RPConfiguration)
@interface RPConfiguration : NSObject

/**
 自定义UI path
 */
@property (nonatomic, copy) NSString *customUIPath;

/**
 是否默认关闭声音，默认开启声音。
 */
@property (nonatomic, assign) BOOL isMutedByDefault;

/**
 是否在主动退出时弹窗确认，默认打开弹窗。
 */
@property (nonatomic, assign) BOOL shouldAlertOnExit;

/**
 实人认证结束后是否恢复 webview 设置，默认恢复。
 */
@property (nonatomic, assign) BOOL shouldRestoreWebview;

/**
 活体检测页面是否等待服务端认证结果，默认不等待。
 此配置只适用于 native 接口，start 接口请在控制台配置。
 */
@property (nonatomic, assign) BOOL shouldWaitResult;

/**
 自定义活体检测页面展示方法。
 */
@property (nonatomic, copy, nullable) RPViewControllerHandler presentHandler;

/**
 自定义活体检测页面消失方法。
 */
@property (nonatomic, copy, nullable) RPViewControllerHandler dismissHandler;

/**
 页面弹出方式，默认为 present。
 */
@property (nonatomic, assign) RPTransitionStyle transitionStyle;

/**
 是否开启页面弹窗动画，默认开启动画。
 */
@property (nonatomic, assign) BOOL isTransitionAnimationEnabled;

/**
 实人认证默认配置

 @return 实人认证配置
 */
+ (instancetype)configuration;

/**
 请使用 [RPConfiguration configuration] 生成配置。

 @return 实人认证配置
 */
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
