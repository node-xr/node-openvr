#include "ivrsystem.h"
#include "openvr.h"

#include <nan.h>

void Initialize(
  v8::Local<v8::Object> exports,
  v8::Local<v8::Value> module,
  v8::Local<v8::Context> context
) { 
  Nan::Set(
    exports,
    Nan::New("VR_Init").ToLocalChecked(),
    Nan::GetFunction(Nan::New<v8::FunctionTemplate>(VR_Init)).ToLocalChecked()
  );
  Nan::Set(
    exports,
    Nan::New("VR_Shutdown").ToLocalChecked(),
    Nan::GetFunction(Nan::New<v8::FunctionTemplate>(VR_Shutdown)).ToLocalChecked()
  );
  Nan::Set(
    exports,
    Nan::New("VR_IsHmdPresent").ToLocalChecked(),
    Nan::GetFunction(Nan::New<v8::FunctionTemplate>(VR_IsHmdPresent)).ToLocalChecked()
  );
  Nan::Set(
    exports,
    Nan::New("VR_IsRuntimeInstalled").ToLocalChecked(),
    Nan::GetFunction(Nan::New<v8::FunctionTemplate>(VR_IsRuntimeInstalled)).ToLocalChecked()
  );
  Nan::Set(
    exports,
    Nan::New("VR_RuntimePath").ToLocalChecked(),
    Nan::GetFunction(Nan::New<v8::FunctionTemplate>(VR_RuntimePath)).ToLocalChecked()
  );
  Nan::Set(
    exports,
    Nan::New("VR_GetVRInitErrorAsSymbol").ToLocalChecked(),
    Nan::GetFunction(Nan::New<v8::FunctionTemplate>(VR_GetVRInitErrorAsSymbol)).ToLocalChecked()
  );
  Nan::Set(
    exports,
    Nan::New("VR_GetVRInitErrorAsEnglishDescription").ToLocalChecked(),
    Nan::GetFunction(Nan::New<v8::FunctionTemplate>(VR_GetVRInitErrorAsEnglishDescription)).ToLocalChecked()
  );
  Nan::Set(
    exports,
    Nan::New("VR_GetInitToken").ToLocalChecked(),
    Nan::GetFunction(Nan::New<v8::FunctionTemplate>(VR_GetInitToken)).ToLocalChecked()
  );
  IVRSystem::Init(exports);
}

NODE_MODULE(openvr, Initialize);
