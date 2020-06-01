#import "AliRealPersonPlugin.h"
#import <RPSDK/RPSDK.h>

@implementation AliRealPersonPlugin

  FlutterMethodChannel* channel;

+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
  channel = [FlutterMethodChannel
      methodChannelWithName:@"ali_real_person"
            binaryMessenger:[registrar messenger]];
  AliRealPersonPlugin* instance = [[AliRealPersonPlugin alloc] init];
  [registrar addMethodCallDelegate:instance channel:channel];
    [RPSDK setup];
}

- (void)handleMethodCall:(FlutterMethodCall*)call result:(FlutterResult)result {
  if ([@"startRealPerson" isEqualToString:call.method]) {
    UIViewController * currentController = [self currentViewController];
    [RPSDK startWithVerifyToken:call.arguments
                 viewController: currentController
                     completion:^(RPResult * _Nonnull result) {
        // 建议接入方调用实人认证服务端接口DescribeVerifyResult，
        // 来获取最终的认证状态，并以此为准进行业务上的判断和处理。
        NSLog(@"实人认证结果：%@", result);
        switch (result.state) {
            case RPStatePass:
                // 认证通过。
                [channel invokeMethod:@"onRealPersonResult" arguments:@"1"];
                break;
            case RPStateFail:
                // 认证不通过。
                 [channel invokeMethod:@"onRealPersonResult" arguments:@"2"];
                break;
            case RPStateNotVerify:
                // 未认证。
                // 通常是用户主动退出或者姓名身份证号实名校验不匹配等原因导致。
                // 具体原因可通过result.errorCode和result.message来区分（详见错误码说明）。
                [channel invokeMethod:@"onRealPersonResult" arguments:@"-1"];
                break;
        }
    }];
  } else {
    result(FlutterMethodNotImplemented);
  }
}

//获取Window当前显示的ViewController
- (UIViewController*)currentViewController{
    //获得当前活动窗口的根视图
    UIViewController* vc = [UIApplication sharedApplication].keyWindow.rootViewController;
    while (1)
    {
        //根据不同的页面切换方式，逐步取得最上层的viewController
        if ([vc isKindOfClass:[UITabBarController class]]) {
            vc = ((UITabBarController*)vc).selectedViewController;
        }
        if ([vc isKindOfClass:[UINavigationController class]]) {
            vc = ((UINavigationController*)vc).visibleViewController;
        }
        if (vc.presentedViewController) {
            vc = vc.presentedViewController;
        }else{
            break;
        }
    }
    return vc;
}


@end
