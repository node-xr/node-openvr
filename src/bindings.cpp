#include "openvr.h"

#include <nan.h>

void Initialize(v8::Local<v8::Object> exports) {
  exports->Set(Nan::New("VR_Init").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(VR_Init)->GetFunction());
  exports->Set(Nan::New("VR_Shutdown").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(VR_Shutdown)->GetFunction());
  //IVRSystem::Init(exports);
}

NODE_MODULE(openvr, Initialize);
