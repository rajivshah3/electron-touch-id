#include <nan.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <dlfcn.h>

using std::cerr;
using std::endl;
using std::string;

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;


// Adapted from https://github.com/noppoMan/node-native-extension-in-swift/blob/master/swift.cc

#ifndef __APPLE__
  cerr << "Unsupported Platform";
  exit(EXIT_FAILURE);
#endif

const string SWIFT_DYLIB_PATH = "../ElectronTouchID/.build/release/libElectronTouchID.dylib";

void *DLSymOrDie(void *lib, const string& func_name) {
  const auto func = dlsym(lib, func_name.c_str());
  const auto dlsym_error = dlerror();
  if (dlsym_error) {
    cerr << "Could not load symbol create: " << dlsym_error << endl;
    dlclose(lib);
    exit(EXIT_FAILURE);
  }
  return func;
}

void *DLOpenOrDie(const string& path) {
  const auto lib = dlopen(path.c_str(), RTLD_LAZY);
  if (!lib) {
    cerr << "Could not load library: " << dlerror() << endl;
    exit(EXIT_FAILURE);
  }
  return lib;
}

void isSupported(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  const auto swiftLib = DLOpenOrDie(SWIFT_DYLIB_PATH);
  const auto &_isSupported = DLSymOrDie(swiftLib, "is_supported");

  bool supported = _isSupported;

  info.GetReturnValue().Set(Nan::New(supported));
}

void authenticate(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  const auto swiftLib = DLOpenOrDie(SWIFT_DYLIB_PATH);
  const auto &_authenticate = DLSymOrDie(swiftLib, "authenticate");
  Nan::Utf8String nan_string(info[0]);
  std::string r(*nan_string);
  const char* reason = r.c_str();
  _authenticate;
}

void Init(v8::Local<v8::Object> exports) {
  exports->Set(Nan::New("isSupported").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(isSupported)->GetFunction());
  exports->Set(Nan::New("authenticate").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(authenticate)->GetFunction());
}

NODE_MODULE(module_name, Init)
