#include "openvr.h"
#include "ivrsystem.h"

#include <node.h>
#include <openvr.h>
#include <v8.h>

//=============================================================================
// inline IVRSystem *VR_Init( EVRInitError *peError, EVRApplicationType eApplicationType );
NAN_METHOD(VR_Init)
{
  if (info.Length() != 1)
  {
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  if (!info[0]->IsNumber())
  {
    Nan::ThrowTypeError("Argument[0] must be a number (EVRApplicationType).");
    return;
  }

  uint32_t applicationType = info[0]->Uint32Value();
  // TODO: is there a better way to do this?
  constexpr uint32_t applicationTypeMax = vr::VRApplication_Max;
  if (applicationType >= applicationTypeMax)
  {
    Nan::ThrowTypeError("Argument[0] was out of enum range (EVRApplicationType).");
    return;
  }

  // Perform the actual wrapped call.
  vr::EVRInitError error;
  vr::IVRSystem *system = vr::VR_Init(
    &error,
    static_cast<vr::EVRApplicationType>(applicationType)
  );

  // If the VR system failed to initialize, immediately raise a node exception.
  if (system == nullptr)
  {
    Nan::ThrowError(VR_GetVRInitErrorAsSymbol(error));
    return;
  }

  // Wrap the resulting system in the correct wrapper and return it.
  auto result = IVRSystem::NewInstance(system);
  info.GetReturnValue().Set(result);
}

//=============================================================================
// inline IVRSystem *VR_Init( EVRInitError *peError, EVRApplicationType eApplicationType );
NAN_METHOD(VR_Shutdown)
{
  if (info.Length() != 0)
  {
    Nan::ThrowTypeError("Wrong number of arguments.");
    return;
  }

  vr::VR_Shutdown();
}
