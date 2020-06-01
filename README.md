# ali_real_person
flutter插件。

只有插件，无文档和example 

先这样，后面再整理使用文档和example



人脸识别插件使用

IOS
修改插件Bundle 的前缀为项目Bundle 
`org.cocoapods.ali-real-person` 修改为 `your bundle.ali-real-person`

导入以下资源文件。导入时必须勾选Copy items if needed，表示自动复制一份相同的文件到工程中，并引用复制后的文件在工程目录中的位置。
yw_1222_0769.jpg
RPSDK.bundle



message: 1. 请确认当前项目的 Bundle ID 与上传的 ipa 文件 Bundle ID 一致。
2. 如果项目的 Bundle ID 有更新，需要重新下载 SDK 并替换 yw_1222_0769.jpg 文件。
3. 请确认在 Build Settings - Other Linker Flags 添加了 -ObjC，注意大小写。
4. 请确认项目正确导入了 SGMain.framework，并且为实人认证依赖的版本。
5. 请确认 yw_1222_0769.jpg 文件在传输过程中没有被通讯工具压缩。
6. 如果您使用私有 pod 方式接入，请使用主工程的 Bundle ID 作为 pod 工程 Bundle ID 的前缀。


Android

将签名图片文件导入到工程应用模块的res/drawable目录下。如果没有这个目录，请先在工程中创建，否则将无法正常工作。
android:allowBackup="false"
tools:replace="android:allowBackup”

gradle需要5.1.1以下


## Getting Started

This project is a starting point for a Flutter
[plug-in package](https://flutter.dev/developing-packages/),
a specialized package that includes platform-specific implementation code for
Android and/or iOS.

For help getting started with Flutter, view our 
[online documentation](https://flutter.dev/docs), which offers tutorials, 
samples, guidance on mobile development, and a full API reference.
