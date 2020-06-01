//
//  RPResult.h
//  ALRealIdentity
//
//  Created by  Hank Zhang on 2019/10/14.
//  Copyright © 2019 Alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class RPResult;

/**
 NS_ENUM(NSInteger, RPPhase)
 实人认证阶段
 */
typedef NS_ENUM(NSInteger, RPPhase) {

    /**
     活体检测即将开始
     */
    RPPhaseBiometricsWillStart,

    /**
     活体检测已经开始
     */
    RPPhaseBiometricsDidStart,

    /**
     活体检测成功
     */
    RPPhaseBiometricsDidSucceed,

    /**
     活体检测失败
     */
    RPPhaseBiometricsDidFail,

    /**
     提交服务端认证开始
     */
    RPPhaseVerificationDidStart,

    /**
     提交服务端认证开始
     */
    RPPhaseVerificationDidFinish,
};

/**
 NS_ENUM(NSInteger, RPState)
 实人认证结果状态
 */
typedef NS_ENUM(NSInteger, RPState) {
    
    /**
     未认证
     */
    RPStateNotVerify = -1,
    
    /**
     认证通过
     */
    RPStatePass = 1,
    
    /**
     认证失败
     */
    RPStateFail = 2,
};

/**
 `RPProgress` 实人认证过程回调。

 @param phase 实人认证阶段。
 */
typedef void (^RPProgress)(RPPhase phase);

/**
 `RPCompletion` 实人认证结果回调。
 
 @param result 实人认证结果。
 */
typedef void (^RPCompletion)(RPResult *result);

/**
 `RPResult` 实人认证结果
 */
NS_SWIFT_NAME(RPResult)
@interface RPResult : NSObject

/**
 实人认证结果状态
 */
@property (nonatomic, assign) RPState state;

/**
 实人认证结果错误代码，可选值
 */
@property (nonatomic, copy, nullable) NSString *errorCode;

/**
 实人认证结果信息，可选值
 */
@property (nonatomic, copy, nullable) NSString *message;

@end

NS_ASSUME_NONNULL_END
