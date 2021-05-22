#include "openvr.h"
#include "ivrsystem.h"

#include <node.h>
#include <openvr.h>
#include <v8.h>

using namespace v8;

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

  uint32_t applicationType = Nan::To<int32_t>(info[0]).ToChecked();
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
    Nan::ThrowError(vr::VR_GetVRInitErrorAsEnglishDescription(error));
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
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  vr::VR_Shutdown();
}

//=============================================================================
/// VR_INTERFACE bool VR_CALLTYPE VR_IsHmdPresent();
NAN_METHOD(VR_IsHmdPresent)
{
  if (info.Length() != 0)
  {
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  const auto result = vr::VR_IsHmdPresent();
  info.GetReturnValue().Set(Nan::New<Boolean>(result));
}

//=============================================================================
/// VR_INTERFACE bool VR_CALLTYPE VR_IsRuntimeInstalled();
NAN_METHOD(VR_IsRuntimeInstalled)
{
  if (info.Length() != 0)
  {
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  const auto result = vr::VR_IsRuntimeInstalled();
  info.GetReturnValue().Set(Nan::New<Boolean>(result));
}

//=============================================================================
/// VR_INTERFACE const char *VR_CALLTYPE VR_RuntimePath();
NAN_METHOD(VR_RuntimePath)
{
  if (info.Length() != 0)
  {
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  const char *result = vr::VR_RuntimePath();
  info.GetReturnValue().Set(Nan::New<String>(result).ToLocalChecked());
}

//=============================================================================
/// VR_INTERFACE const char *VR_CALLTYPE VR_GetVRInitErrorAsSymbol( EVRInitError error );
NAN_METHOD(VR_GetVRInitErrorAsSymbol)
{
  if (info.Length() != 1)
  {
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  if (!info[0]->IsNumber())
  {
    Nan::ThrowTypeError("Argument[0] must be a number (EVRInitError).");
    return;
  }

  uint32_t nError = Nan::To<int32_t>(info[0]).ToChecked();
  vr::EVRInitError eError = static_cast<vr::EVRInitError>(nError);
  const char *result = vr::VR_GetVRInitErrorAsSymbol(eError);
  info.GetReturnValue().Set(Nan::New<String>(result).ToLocalChecked());
}

//=============================================================================
/// VR_INTERFACE const char *VR_CALLTYPE VR_GetVRInitErrorAsEnglishDescription( EVRInitError error );
NAN_METHOD(VR_GetVRInitErrorAsEnglishDescription)
{
  if (info.Length() != 1)
  {
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  if (!info[0]->IsNumber())
  {
    Nan::ThrowTypeError("Argument[0] must be a number (EVRInitError).");
    return;
  }

  uint32_t nError = Nan::To<int32_t>(info[0]).ToChecked();
  vr::EVRInitError eError = static_cast<vr::EVRInitError>(nError);
  const auto result = vr::VR_GetVRInitErrorAsEnglishDescription(eError);
  info.GetReturnValue().Set(Nan::New<String>(result).ToLocalChecked());
}

//=============================================================================
/// VR_INTERFACE uint32_t VR_CALLTYPE VR_GetInitToken();
NAN_METHOD(VR_GetInitToken)
{
  if (info.Length() != 0)
  {
    Nan::ThrowTypeError("Wrong number of arguments.");
    return;
  }

  const auto result = vr::VR_GetInitToken();
  info.GetReturnValue().Set(Nan::New<Number>(result));
}
