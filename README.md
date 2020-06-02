***
### 安装
- 在`pubspec.yaml`中加入
```
 dependencies:
    ali_real_person: ^0.0.1
```

##使用方法（使用前请先完成Android & IOS 配置）

```
import 'package:ali_real_person/ali_real_person.dart';

//...

//在需要唤起实人认证处调用方法,需要入参token，token从服务端获取
  AliRealPerson.startRealPerson(token, (value) {
            //返回字符串
            // "1" 认证成功,
            // "2"  认证失败
            // "-1"  未认证
            if (value == "1") {
              print("认证通过");
            }
  });
```

***

## Android & IOS 配置
在阿里云实人认证控制台下载SDK,本插件中的版本为最新的4.0.4。如果更新了的话自行替换依赖库即可
![WX20200602-132227@2x.png](https://upload-images.jianshu.io/upload_images/5862096-b152fb34e2af911a.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

下载后解压，会得到一个`yw_1222_*.jpg`签名文件 和 `client.zip`压缩包
注意：Android debug包和release包在使用不同签名时不能混用同一张签名图片文件
***
### Android配置
- 将`yw_1222_*.jpg`签名图片文件导入到工程应用模块的res/drawable目录下
- 配置`app/build.gradle`  
```
   buildTypes {
        //...
        repositories {
            flatDir {
                dirs project(':ali_real_person').file('libs')
            }
        }
    }
```
- 在AndroidManifest.xml中配置以下内容（若有则忽略）
```
<!--        ....  -->
    <!--配置相机权限-->
<uses-permission android:name="android.permission.CAMERA"/>
    
<!--        ....  -->
<application
        android:label="@string/app_name"
        android:allowBackup="false"
        tools:replace="android:allowBackup"
        >
    <!--        ....  -->
</application>
```
> 目前实人SDK(4.0.4)依赖包不兼容较新的gradle 5.4.1及gradle tools 3.5版本。如果你的gradle版本过高参考以下方法进行降级

- 修改 `gradle` 版本改为5.1.1(含)以下， 位于`gradle-wrapper.properties`
```
distributionUrl=https\://services.gradle.org/distributions/gradle-5.1.1-all.zip
```
- 修改 `gradle tools`  版本改为3.4(含)以下
```
    dependencies {
        classpath 'com.android.tools.build:gradle:3.4.0'
        //....
    }
```

- [Android 常见问题](https://help.aliyun.com/document_detail/142591.html?spm=a2c4g.11186623.2.26.4e1a7274iikN7c#concept-2333222)

***
### IOS配置 
- 导入以下资源文件。导入时必须勾选Copy items if needed，表示自动复制一份相同的文件到工程中，并引用复制后的文件在工程目录中的位置。
```
yw_1222_0769.jpg
RPSDK.bundle
```
![image.png](https://upload-images.jianshu.io/upload_images/5862096-3b91e06495f815ca.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
导入完成后，您可以在Build Phases > Copy Bundle Resources看到资源文件。如果未看到资源文件，则说明导入过程中出现问题，请确认将所有资源文件拷贝到工程项目，并勾选正确应用目标。

- 配置相机权限，若有则忽略
```
	<key>NSCameraUsageDescription</key>
	<string>APP需要您授权才能访问相机</string>
```

> 以下两项每次执行完 `pod install` 都需要配置一下，否则无法运行，暂时我没找到怎么在podspec里面设置，后面如果找到再更新

- 修改插件Bundle 的前缀为项目Bundle 
`org.cocoapods.ali-real-person` 修改为 `your bundle.ali-real-person`

- 在`Build Settings - Other Linker Flags` 添加了 ` -ObjC`，注意大小写。


- [IOS 集成常见问题](https://help.aliyun.com/document_detail/142592.html?spm=a2c4g.11186623.2.19.55d81ba8CmNrGP#concept-2333223)

###最终效果图
![WechatIMG119.jpeg](https://upload-images.jianshu.io/upload_images/5862096-5e34794581ed692b.jpeg?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![WechatIMG120.jpeg](https://upload-images.jianshu.io/upload_images/5862096-7cbd3d542babd67b.jpeg?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
