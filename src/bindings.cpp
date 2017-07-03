#include "ivrsystem.h"
#include "openvr.h"

#include <nan.h>

void Initialize(v8::Local<v8::Object> exports) {
  exports->Set(Nan::New("VR_Init").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(VR_Init)->GetFunction());
  exports->Set(Nan::New("VR_Shutdown").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(VR_Shutdown)->GetFunction());
  exports->Set(Nan::New("VR_IsHmdPresent").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(VR_IsHmdPresent)->GetFunction());
  exports->Set(Nan::New("VR_IsRuntimeInstalled").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(VR_IsRuntimeInstalled)->GetFunction());
  exports->Set(Nan::New("VR_RuntimePath").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(VR_RuntimePath)->GetFunction());
  exports->Set(Nan::New("VR_GetVRInitErrorAsSymbol").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(VR_GetVRInitErrorAsSymbol)->GetFunction());
  exports->Set(Nan::New("VR_GetVRInitErrorAsEnglishDescription").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(VR_GetVRInitErrorAsEnglishDescription)->GetFunction());
  exports->Set(Nan::New("VR_GetInitToken").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(VR_GetInitToken)->GetFunction());

  IVRSystem::Init(exports);
}

NODE_MODULE(openvr, Initialize);
