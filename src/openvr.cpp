#include "openvr.h"

#include <node.h>
#include <openvr.h>
#include <v8.h>

/// inline IVRSystem *VR_Init( EVRInitError *peError, EVRApplicationType eApplicationType );
NAN_METHOD(VR_Init) {
  if (info.Length() != 2) {
    Nan::ThrowTypeError("Wrong number of arguments");
    return;
  }

  if (!info[0]->IsNumber()) {
    Nan::ThrowTypeError("Argument[0] must be a number (EVRInitError)");
    return;
  }

  if (!info[1]->IsNumber()) {
    Nan::ThrowTypeError("Argument[1] must be a number (EVRApplicationType)");
    return;
  }

  auto message = Nan::New<v8::String>("I'm a Node Hero!").ToLocalChecked();
  info.GetReturnValue().Set(message);
}

/// inline IVRSystem *VR_Init( EVRInitError *peError, EVRApplicationType eApplicationType );
NAN_METHOD(VR_Shutdown) {
  if (info.Length() != 0) {
    Nan::ThrowTypeError("Wrong number of arguments");
    return;
  }

  vr::VR_Shutdown();
}
