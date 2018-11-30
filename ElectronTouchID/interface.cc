#include <nan.h>
#include <string>

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;


extern "C" void is_supported();

void isSupported(const Nan::FunctionCallbackInfo<v8::Value>& info) {

}

void Init(v8::Local<v8::Object> exports) {
    exports->Set(Nan::New("isSupported").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(isSupported)->GetFunction());
}
