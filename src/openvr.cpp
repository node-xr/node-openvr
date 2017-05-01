#include "openvr.h"

#include <node.h>
#include <openvr.h>
#include <v8.h>

/// inline IVRSystem *VR_Init( EVRInitError *peError, EVRApplicationType eApplicationType );
NAN_METHOD(VR_Init) {
  if (info.Length() != 2) {
    Nan::ThrowTypeError("Wrong number of arguments.");
    return;
  }

  if (!info[0]->IsNumber()) {
    Nan::ThrowTypeError("Argument[0] must be a number (EVRInitError).");
    return;
  }

  if (!info[1]->IsNumber()) {
    Nan::ThrowTypeError("Argument[1] must be a number (EVRApplicationType).");
    return;
  }

  uint32_t applicationType = info[1]->Uint32Value();
  // TODO: correctly compiling check for enum out-of-range.
  /*
  if (applicationType >= static_cast<uint32_t>(vr::EVRApplicationType::VRApplication_MAX)) {
    Nan::ThrowTypeError("Argument[1] was out of range (EVRApplicationType).");
    return;
  }
  */

  vr::EVRInitError error;
  vr::IVRSystem *system = vr::VR_Init(
    &error,
    static_cast<vr::EVRApplicationType>(applicationType)
  );

  auto message = Nan::New<v8::String>("I'm a Node Hero!").ToLocalChecked();
  info.GetReturnValue().Set(message);
}

/// inline IVRSystem *VR_Init( EVRInitError *peError, EVRApplicationType eApplicationType );
NAN_METHOD(VR_Shutdown) {
  if (info.Length() != 0) {
    Nan::ThrowTypeError("Wrong number of arguments.");
    return;
  }

  vr::VR_Shutdown();
}
