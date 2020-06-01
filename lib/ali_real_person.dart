import 'dart:async';

import 'package:flutter/services.dart';

class AliRealPerson {
  static const MethodChannel _channel = const MethodChannel('ali_real_person');
  static Function _callBack;

  static Future<dynamic> _handler(MethodCall methodCall) {
    if ("onRealPersonResult" == methodCall.method) {
      print("onRealPersonResult: " + methodCall.arguments);
      _callBack(methodCall.arguments);
    }
    return Future.value(true);
  }

  static Future<Null> startRealPerson(token, callBack) async {
    _channel.setMethodCallHandler(_handler);
    _callBack = callBack;
    await _channel.invokeMethod('startRealPerson', token);
  }
}
