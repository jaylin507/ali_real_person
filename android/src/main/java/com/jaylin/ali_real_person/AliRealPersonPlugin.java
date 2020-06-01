package com.jaylin.ali_real_person;

import android.content.Context;

import androidx.annotation.NonNull;

import com.alibaba.security.cloud.CloudRealIdentityTrigger;
import com.alibaba.security.realidentity.ALRealIdentityCallback;
import com.alibaba.security.realidentity.ALRealIdentityResult;

import io.flutter.embedding.engine.plugins.FlutterPlugin;
import io.flutter.plugin.common.MethodCall;
import io.flutter.plugin.common.MethodChannel;
import io.flutter.plugin.common.MethodChannel.MethodCallHandler;
import io.flutter.plugin.common.MethodChannel.Result;
import io.flutter.plugin.common.PluginRegistry.Registrar;

/**
 * AliRealPersonPlugin
 */
public class AliRealPersonPlugin implements FlutterPlugin, MethodCallHandler {
    /// The MethodChannel that will the communication between Flutter and native Android
    ///
    /// This local reference serves to register the plugin with the Flutter Engine and unregister it
    /// when the Flutter Engine is detached from the Activity
    private MethodChannel channel;
    private Context context;

    @Override
    public void onAttachedToEngine(@NonNull FlutterPluginBinding flutterPluginBinding) {
        channel = new MethodChannel(flutterPluginBinding.getFlutterEngine().getDartExecutor(), "ali_real_person");
        channel.setMethodCallHandler(this);
        this.context = flutterPluginBinding.getApplicationContext();
        CloudRealIdentityTrigger.initialize(context);//CloudRealIdentityTrigger

    }

    // This static function is optional and equivalent to onAttachedToEngine. It supports the old
    // pre-Flutter-1.12 Android projects. You are encouraged to continue supporting
    // plugin registration via this function while apps migrate to use the new Android APIs
    // post-flutter-1.12 via https://flutter.dev/go/android-project-migration.
    //
    // It is encouraged to share logic between onAttachedToEngine and registerWith to keep
    // them functionally equivalent. Only one of onAttachedToEngine or registerWith will be called
    // depending on the user's project. onAttachedToEngine or registerWith must both be defined
    // in the same class.
    public static void registerWith(Registrar registrar) {
        final MethodChannel channel = new MethodChannel(registrar.messenger(), "ali_real_person");
        channel.setMethodCallHandler(new AliRealPersonPlugin());
    }

    @Override
    public void onMethodCall(@NonNull MethodCall call, @NonNull Result result) {
        if (call.method.equals("startRealPerson")) {
            CloudRealIdentityTrigger.start(context, call.arguments.toString(), new ALRealIdentityCallback() {
                @Override
                public void onAuditResult(ALRealIdentityResult alRealIdentityResult, String s) {
                    if (alRealIdentityResult == ALRealIdentityResult.AUDIT_PASS) {
                        // 认证通过。建议接入方调用实人认证服务端接口DescribeVerifyResult来获取最终的认证状态，并以此为准进行业务上的判断和处理。
                        channel.invokeMethod("onRealPersonResult", "1");
                    } else if (alRealIdentityResult == ALRealIdentityResult.AUDIT_FAIL) {
                        // 认证不通过。建议接入方调用实人认证服务端接口DescribeVerifyResult来获取最终的认证状态，并以此为准进行业务上的判断和处理。
                        channel.invokeMethod("onRealPersonResult", "2");
                    } else if (alRealIdentityResult == ALRealIdentityResult.AUDIT_NOT) {
                        channel.invokeMethod("onRealPersonResult", "-1");
                    }
                }
            });
        } else {
            result.notImplemented();
        }
    }

    @Override
    public void onDetachedFromEngine(@NonNull FlutterPluginBinding binding) {
        channel.setMethodCallHandler(null);
    }
}
