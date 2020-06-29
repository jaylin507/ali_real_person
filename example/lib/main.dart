import 'package:flutter/material.dart';
import 'package:ali_real_person/ali_real_person.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatefulWidget {
  @override
  _MyAppState createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  @override
  void initState() {
    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Plugin example app'),
        ),
        body: Center(
          child: GestureDetector(
            onTap: () {
              var token = "xxxxx";
              AliRealPerson.startRealPerson(token, (value) {
                //返回字符串
                // "1" 认证成功,
                // "2"  认证失败
                // "-1"  未认证
                if (value == "1") {
                  print("认证通过");
                }
              });
            },
            child: Text('Click Run Ali RealPerson'),
          ),
        ),
      ),
    );
  }
}
