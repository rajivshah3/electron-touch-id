#include <nan.h>
#include <string>
#include "ElectronTouchID.framework/Headers/ElectronTouchID-Swift.h"

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;


void isSupported(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  info.GetReturnValue().Set(Nan::New(is_supported()));
}

void Init(v8::Local<v8::Object> exports) {
    exports->Set(Nan::New("isSupported").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(isSupported)->GetFunction());
}
