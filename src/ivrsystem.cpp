#include "ivrsystem.h"
#include "util.h"

#include <array>
#include <node.h>
#include <openvr.h>

using namespace v8;

using TrackedDevicePoseArray = std::array<vr::TrackedDevicePose_t, vr::k_unMaxTrackedDeviceCount>;
using TrackedDeviceIndexArray = std::array<vr::TrackedDeviceIndex_t, vr::k_unMaxTrackedDeviceCount>;

//=============================================================================
NAN_MODULE_INIT(IVRSystem::Init)
{
  // Create a function template that is called in JS to create this wrapper.
  Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(New);

  // Declare human-readable name for this wrapper.
  tpl->SetClassName(Nan::New("IVRSystem").ToLocalChecked());

  // Declare the stored number of fields (just the wrapped C++ object).
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  // Assign all the wrapped methods of this object.
  Nan::SetPrototypeMethod(tpl, "GetRecommendedRenderTargetSize", GetRecommendedRenderTargetSize);
  Nan::SetPrototypeMethod(tpl, "GetProjectionMatrix", GetProjectionMatrix);
  Nan::SetPrototypeMethod(tpl, "GetProjectionRaw", GetProjectionRaw);
  Nan::SetPrototypeMethod(tpl, "ComputeDistortion", ComputeDistortion);
  Nan::SetPrototypeMethod(tpl, "GetEyeToHeadTransform", GetEyeToHeadTransform);
  Nan::SetPrototypeMethod(tpl, "GetTimeSinceLastVsync", GetTimeSinceLastVsync);
  Nan::SetPrototypeMethod(tpl, "GetD3D9AdapterIndex", GetD3D9AdapterIndex);
  Nan::SetPrototypeMethod(tpl, "GetDXGIOutputInfo", GetDXGIOutputInfo);
  Nan::SetPrototypeMethod(tpl, "IsDisplayOnDesktop", IsDisplayOnDesktop);
  Nan::SetPrototypeMethod(tpl, "SetDisplayVisibility", SetDisplayVisibility);
  Nan::SetPrototypeMethod(tpl, "GetDeviceToAbsoluteTrackingPose", GetDeviceToAbsoluteTrackingPose);
  Nan::SetPrototypeMethod(tpl, "ResetSeatedZeroPose", ResetSeatedZeroPose);
  Nan::SetPrototypeMethod(tpl, "GetSeatedZeroPoseToStandingAbsoluteTrackingPose", GetSeatedZeroPoseToStandingAbsoluteTrackingPose);
  Nan::SetPrototypeMethod(tpl, "GetRawZeroPoseToStandingAbsoluteTrackingPose", GetRawZeroPoseToStandingAbsoluteTrackingPose);
  Nan::SetPrototypeMethod(tpl, "GetSortedTrackedDeviceIndicesOfClass", GetSortedTrackedDeviceIndicesOfClass);
  Nan::SetPrototypeMethod(tpl, "GetTrackedDeviceActivityLevel", GetTrackedDeviceActivityLevel);
  Nan::SetPrototypeMethod(tpl, "ApplyTransform", ApplyTransform);

  /// virtual vr::TrackedDeviceIndex_t GetTrackedDeviceIndexForControllerRole( vr::ETrackedControllerRole unDeviceType ) = 0;
  /// virtual vr::ETrackedControllerRole GetControllerRoleForTrackedDeviceIndex( vr::TrackedDeviceIndex_t unDeviceIndex ) = 0;

  Nan::SetPrototypeMethod(tpl, "GetTrackedDeviceClass", GetTrackedDeviceClass);

  /// virtual bool IsTrackedDeviceConnected( vr::TrackedDeviceIndex_t unDeviceIndex ) = 0;
  /// virtual bool GetBoolTrackedDeviceProperty( vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, ETrackedPropertyError *pError = 0L ) = 0;
  /// virtual float GetFloatTrackedDeviceProperty( vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, ETrackedPropertyError *pError = 0L ) = 0;
  /// virtual int32_t GetInt32TrackedDeviceProperty( vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, ETrackedPropertyError *pError = 0L ) = 0;
  /// virtual uint64_t GetUint64TrackedDeviceProperty( vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, ETrackedPropertyError *pError = 0L ) = 0;
  /// virtual HmdMatrix34_t GetMatrix34TrackedDeviceProperty( vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, ETrackedPropertyError *pError = 0L ) = 0;
  /// virtual uint32_t GetStringTrackedDeviceProperty( vr::TrackedDeviceIndex_t unDeviceIndex, ETrackedDeviceProperty prop, VR_OUT_STRING() char *pchValue, uint32_t unBufferSize, ETrackedPropertyError *pError = 0L ) = 0;
  /// virtual const char *GetPropErrorNameFromEnum( ETrackedPropertyError error ) = 0;
  /// virtual bool PollNextEvent( VREvent_t *pEvent, uint32_t uncbVREvent ) = 0;
  /// virtual bool PollNextEventWithPose( ETrackingUniverseOrigin eOrigin, VREvent_t *pEvent, uint32_t uncbVREvent, vr::TrackedDevicePose_t *pTrackedDevicePose ) = 0;
  /// virtual const char *GetEventTypeNameFromEnum( EVREventType eType ) = 0;
  /// virtual HiddenAreaMesh_t GetHiddenAreaMesh( EVREye eEye ) = 0;
  /// virtual bool GetControllerState( vr::TrackedDeviceIndex_t unControllerDeviceIndex, vr::VRControllerState_t *pControllerState ) = 0;
  /// virtual bool GetControllerStateWithPose( ETrackingUniverseOrigin eOrigin, vr::TrackedDeviceIndex_t unControllerDeviceIndex, vr::VRControllerState_t *pControllerState, TrackedDevicePose_t *pTrackedDevicePose ) = 0;
  /// virtual void TriggerHapticPulse( vr::TrackedDeviceIndex_t unControllerDeviceIndex, uint32_t unAxisId, unsigned short usDurationMicroSec ) = 0;
  /// virtual const char *GetButtonIdNameFromEnum( EVRButtonId eButtonId ) = 0;
  /// virtual const char *GetControllerAxisTypeNameFromEnum( EVRControllerAxisType eAxisType ) = 0;

  Nan::SetPrototypeMethod(tpl, "CaptureInputFocus", CaptureInputFocus);
  Nan::SetPrototypeMethod(tpl, "ReleaseInputFocus", ReleaseInputFocus);
  Nan::SetPrototypeMethod(tpl, "IsInputFocusCapturedByAnotherProcess", IsInputFocusCapturedByAnotherProcess);

  /// virtual uint32_t DriverDebugRequest( vr::TrackedDeviceIndex_t unDeviceIndex, const char *pchRequest, char *pchResponseBuffer, uint32_t unResponseBufferSize ) = 0;
  /// virtual vr::EVRFirmwareError PerformFirmwareUpdate( vr::TrackedDeviceIndex_t unDeviceIndex ) = 0;

  Nan::SetPrototypeMethod(tpl, "AcknowledgeQuit_Exiting", AcknowledgeQuit_Exiting);
  Nan::SetPrototypeMethod(tpl, "AcknowledgeQuit_UserPrompt", AcknowledgeQuit_UserPrompt);

  // Set a static constructor function to reference the `New` function template.
  constructor().Reset(Nan::GetFunction(tpl).ToLocalChecked());
}

//=============================================================================
Local<Object> IVRSystem::NewInstance(vr::IVRSystem *system)
{
  Nan::EscapableHandleScope scope;
  Local<Function> cons = Nan::New(constructor());
  Local<Value> argv[1] = { Nan::New<External>(system) };
  return scope.Escape(Nan::NewInstance(cons, 1, argv).ToLocalChecked());
}

//=============================================================================
IVRSystem::IVRSystem(vr::IVRSystem *self)
: self_(self)
{
  // Do nothing.
}

//=============================================================================
NAN_METHOD(IVRSystem::New)
{
  if (!info.IsConstructCall())
  {
    Nan::ThrowError("Use the `new` keyword when creating a new instance.");
    return;
  }

  if (info.Length() != 1 || !info[0]->IsExternal())
  {
    Nan::ThrowTypeError("Argument[0] must be an `IVRSystem*`.");
    return;
  }

  auto wrapped_instance = static_cast<vr::IVRSystem*>(
    Local<External>::Cast(info[0])->Value());
  IVRSystem *obj = new IVRSystem(wrapped_instance);
  obj->Wrap(info.This());
  info.GetReturnValue().Set(info.This());
}

//=============================================================================
// virtual void GetRecommendedRenderTargetSize( uint32_t *pnWidth, uint32_t *pnHeight ) = 0;
NAN_METHOD(IVRSystem::GetRecommendedRenderTargetSize)
{
  IVRSystem* obj = ObjectWrap::Unwrap<IVRSystem>(info.Holder());

  if (info.Length() != 0)
  {
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  uint32_t nWidth, nHeight;
  obj->self_->GetRecommendedRenderTargetSize(&nWidth, &nHeight);

  Local<Object> result = Nan::New<Object>();
  {
    Local<String> width_prop = Nan::New<String>("width").ToLocalChecked();
    Nan::Set(result, width_prop, Nan::New<Number>(nWidth));

    Local<String> height_prop = Nan::New<String>("height").ToLocalChecked();
    Nan::Set(result, height_prop, Nan::New<Number>(nHeight));
  }
  info.GetReturnValue().Set(result);
}

//=============================================================================
/// virtual HmdMatrix44_t GetProjectionMatrix( EVREye eEye, float fNearZ, float fFarZ ) = 0;
NAN_METHOD(IVRSystem::GetProjectionMatrix)
{
  IVRSystem* obj = ObjectWrap::Unwrap<IVRSystem>(info.Holder());

  if (info.Length() != 3)
  {
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  if (!info[0]->IsNumber())
  {
    Nan::ThrowTypeError("Argument[0] must be a number (EVREye).");
    return;
  }

  uint32_t nEye = Nan::To<int32_t>(info[0]).ToChecked();
  if (nEye >= 2)
  {
    Nan::ThrowTypeError("Argument[0] was out of enum range (EVREye).");
    return;
  }

  if (!info[1]->IsNumber())
  {
    Nan::ThrowTypeError("Argument[1] must be a number.");
    return;
  }

  if (!info[2]->IsNumber())
  {
    Nan::ThrowTypeError("Argument[2] must be a number.");
    return;
  }

  vr::EVREye eEye = static_cast<vr::EVREye>(nEye);
  float fNearZ = static_cast<float>(Nan::To<int32_t>(info[1]).ToChecked());
  float fFarZ = static_cast<float>(Nan::To<int32_t>(info[2]).ToChecked());
  vr::HmdMatrix44_t matrix = obj->self_->GetProjectionMatrix(eEye, fNearZ, fFarZ);

  info.GetReturnValue().Set(encode(matrix));
}

//=============================================================================
/// virtual void GetProjectionRaw( EVREye eEye, float *pfLeft, float *pfRight, float *pfTop, float *pfBottom ) = 0;
NAN_METHOD(IVRSystem::GetProjectionRaw)
{
  IVRSystem* obj = ObjectWrap::Unwrap<IVRSystem>(info.Holder());

  if (info.Length() != 1)
  {
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  if (!info[0]->IsNumber())
  {
    Nan::ThrowTypeError("Argument[0] must be a number (EVREye).");
    return;
  }

  uint32_t nEye = Nan::To<int32_t>(info[0]).ToChecked();
  if (nEye >= 2)
  {
    Nan::ThrowTypeError("Argument[0] was out of enum range (EVREye).");
    return;
  }

  vr::EVREye eEye = static_cast<vr::EVREye>(nEye);
  float fLeft, fRight, fTop, fBottom;
  obj->self_->GetProjectionRaw(eEye, &fLeft, &fRight, &fTop, &fBottom);

  Local<Object> result = Nan::New<Object>();
  {
    Local<String> left_prop = Nan::New<String>("left").ToLocalChecked();
    Nan::Set(result, left_prop, Nan::New<Number>(fLeft));

    Local<String> right_prop = Nan::New<String>("right").ToLocalChecked();
    Nan::Set(result, right_prop, Nan::New<Number>(fRight));

    Local<String> top_prop = Nan::New<String>("top").ToLocalChecked();
    Nan::Set(result, top_prop, Nan::New<Number>(fTop));

    Local<String> bottom_prop = Nan::New<String>("bottom").ToLocalChecked();
    Nan::Set(result, bottom_prop, Nan::New<Number>(fBottom));
  }
  info.GetReturnValue().Set(result);
}

//=============================================================================
/// virtual bool ComputeDistortion( EVREye eEye, float fU, float fV, DistortionCoordinates_t *pDistortionCoordinates ) = 0;
NAN_METHOD(IVRSystem::ComputeDistortion)
{
  IVRSystem* obj = ObjectWrap::Unwrap<IVRSystem>(info.Holder());

  if (info.Length() != 3)
  {
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  if (!info[0]->IsNumber())
  {
    Nan::ThrowTypeError("Argument[0] must be a number (EVREye).");
    return;
  }

  uint32_t nEye = Nan::To<int32_t>(info[0]).ToChecked();
  if (nEye >= 2)
  {
    Nan::ThrowTypeError("Argument[0] was out of enum range (EVREye).");
    return;
  }

  if (!info[1]->IsNumber())
  {
    Nan::ThrowTypeError("Argument[1] must be a number.");
    return;
  }

  if (!info[2]->IsNumber())
  {
    Nan::ThrowTypeError("Argument[2] must be a number.");
    return;
  }

  vr::EVREye eEye = static_cast<vr::EVREye>(nEye);
  float fU = static_cast<float>(Nan::To<int32_t>(info[1]).ToChecked());
  float fV = static_cast<float>(Nan::To<int32_t>(info[2]).ToChecked());
  vr::DistortionCoordinates_t distortionCoordinates;
  bool success = obj->self_->ComputeDistortion(eEye, fU, fV, &distortionCoordinates);

  if (!success)
  {
    Nan::ThrowError("Distortion coordinates not suitable.");
    return;
  }
  info.GetReturnValue().Set(encode(distortionCoordinates));
}

//=============================================================================
/// virtual HmdMatrix34_t GetEyeToHeadTransform( EVREye eEye ) = 0;
NAN_METHOD(IVRSystem::GetEyeToHeadTransform)
{
  IVRSystem* obj = ObjectWrap::Unwrap<IVRSystem>(info.Holder());

  if (info.Length() != 1)
  {
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  if (!info[0]->IsNumber())
  {
    Nan::ThrowTypeError("Argument[0] must be a number (EVREye).");
    return;
  }

  uint32_t nEye = Nan::To<int32_t>(info[0]).ToChecked();
  if (nEye >= 2)
  {
    Nan::ThrowTypeError("Argument[0] was out of enum range (EVREye).");
    return;
  }

  vr::EVREye eEye = static_cast<vr::EVREye>(nEye);
  vr::HmdMatrix34_t matrix = obj->self_->GetEyeToHeadTransform(eEye);

  info.GetReturnValue().Set(encode(matrix));
}

//=============================================================================
/// virtual bool GetTimeSinceLastVsync( float *pfSecondsSinceLastVsync, uint64_t *pulFrameCounter ) = 0;
NAN_METHOD(IVRSystem::GetTimeSinceLastVsync)
{
  IVRSystem* obj = ObjectWrap::Unwrap<IVRSystem>(info.Holder());

  if (info.Length() != 0)
  {
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  float fSecondsSinceLastVsync;
  uint64_t ulFrameCounter;
  obj->self_->GetTimeSinceLastVsync(&fSecondsSinceLastVsync, &ulFrameCounter);

  Local<Object> result = Nan::New<Object>();
  {
    Local<String> seconds_prop = Nan::New<String>("seconds").ToLocalChecked();
    Nan::Set(result, seconds_prop, Nan::New<Number>(fSecondsSinceLastVsync));

    // We can't return a 64-bit int, so we just have to return a 32-bit
    // truncation and hope that clients can deal with eventual overflow.
    Local<String> frame_prop = Nan::New<String>("frame").ToLocalChecked();
    Nan::Set(result, frame_prop, Nan::New<Number>(static_cast<uint32_t>(ulFrameCounter)));
  }
  info.GetReturnValue().Set(result);
}

//=============================================================================
/// virtual int32_t GetD3D9AdapterIndex() = 0;
NAN_METHOD(IVRSystem::GetD3D9AdapterIndex)
{
  IVRSystem* obj = ObjectWrap::Unwrap<IVRSystem>(info.Holder());

  if (info.Length() != 0)
  {
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  uint32_t uIndex = obj->self_->GetD3D9AdapterIndex();
  info.GetReturnValue().Set(Nan::New<Number>(uIndex));
}

//=============================================================================
/// virtual void GetDXGIOutputInfo( int32_t *pnAdapterIndex ) = 0;
NAN_METHOD(IVRSystem::GetDXGIOutputInfo)
{
  IVRSystem* obj = ObjectWrap::Unwrap<IVRSystem>(info.Holder());

  if (info.Length() != 0)
  {
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  int32_t nAdapterIndex;
  obj->self_->GetDXGIOutputInfo(&nAdapterIndex);
  info.GetReturnValue().Set(Nan::New<Number>(nAdapterIndex));
}

//=============================================================================
/// virtual bool IsDisplayOnDesktop() = 0;
NAN_METHOD(IVRSystem::IsDisplayOnDesktop)
{
  IVRSystem* obj = ObjectWrap::Unwrap<IVRSystem>(info.Holder());

  if (info.Length() != 0)
  {
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  bool bIsVisibleOnDesktop = obj->self_->IsDisplayOnDesktop();
  info.GetReturnValue().Set(Nan::New<Boolean>(bIsVisibleOnDesktop));
}

//=============================================================================
/// virtual bool SetDisplayVisibility( bool bIsVisibleOnDesktop ) = 0;
NAN_METHOD(IVRSystem::SetDisplayVisibility)
{
  IVRSystem* obj = ObjectWrap::Unwrap<IVRSystem>(info.Holder());

  if (info.Length() != 1)
  {
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  if (!info[0]->IsBoolean())
  {
    Nan::ThrowTypeError("Argument[0] must be a boolean.");
    return;
  }

  bool bIsVisibleOnDesktop = Nan::To<bool>(info[0]).FromJust();
  bool bSuccess = obj->self_->SetDisplayVisibility(bIsVisibleOnDesktop);
  info.GetReturnValue().Set(Nan::New<Boolean>(bSuccess));
}

//=============================================================================
/// virtual void GetDeviceToAbsoluteTrackingPose( ETrackingUniverseOrigin eOrigin, float fPredictedSecondsToPhotonsFromNow, VR_ARRAY_COUNT(unTrackedDevicePoseArrayCount) TrackedDevicePose_t *pTrackedDevicePoseArray, uint32_t unTrackedDevicePoseArrayCount ) = 0;
NAN_METHOD(IVRSystem::GetDeviceToAbsoluteTrackingPose)
{
  IVRSystem* obj = ObjectWrap::Unwrap<IVRSystem>(info.Holder());

  if (info.Length() != 2)
  {
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  if (!info[0]->IsNumber())
  {
    Nan::ThrowTypeError("Argument[0] must be a number (ETrackingUniverseOrigin).");
    return;
  }

  uint32_t nOrigin = Nan::To<int32_t>(info[0]).ToChecked();
  if (nOrigin >= 3)
  {
    Nan::ThrowTypeError("Argument[0] was out of enum range (ETrackingUniverseOrigin).");
    return;
  }

  if (!info[1]->IsNumber())
  {
    Nan::ThrowTypeError("Argument[1] must be a number.");
    return;
  }

  vr::ETrackingUniverseOrigin eOrigin = static_cast<vr::ETrackingUniverseOrigin>(nOrigin);
  float fPredictedSecondsToPhotonsFromNow = static_cast<float>(Nan::To<int32_t>(info[1]).FromJust());
  TrackedDevicePoseArray trackedDevicePoseArray;
  obj->self_->GetDeviceToAbsoluteTrackingPose(
    eOrigin, fPredictedSecondsToPhotonsFromNow, trackedDevicePoseArray.data(),
    static_cast<uint32_t>(trackedDevicePoseArray.size())
  );

  info.GetReturnValue().Set(encode(trackedDevicePoseArray));
}

//=============================================================================
/// virtual void ResetSeatedZeroPose() = 0;
NAN_METHOD(IVRSystem::ResetSeatedZeroPose)
{
  IVRSystem* obj = ObjectWrap::Unwrap<IVRSystem>(info.Holder());

  if (info.Length() != 0)
  {
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  obj->self_->ResetSeatedZeroPose();
}

//=============================================================================
/// virtual HmdMatrix34_t GetSeatedZeroPoseToStandingAbsoluteTrackingPose() = 0;
NAN_METHOD(IVRSystem::GetSeatedZeroPoseToStandingAbsoluteTrackingPose)
{
  IVRSystem* obj = ObjectWrap::Unwrap<IVRSystem>(info.Holder());

  if (info.Length() != 0)
  {
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  vr::HmdMatrix34_t matrix = obj->self_->GetSeatedZeroPoseToStandingAbsoluteTrackingPose();
  info.GetReturnValue().Set(encode(matrix));
}

//=============================================================================
/// virtual HmdMatrix34_t GetRawZeroPoseToStandingAbsoluteTrackingPose() = 0;
NAN_METHOD(IVRSystem::GetRawZeroPoseToStandingAbsoluteTrackingPose)
{
  IVRSystem* obj = ObjectWrap::Unwrap<IVRSystem>(info.Holder());

  if (info.Length() != 0)
  {
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  vr::HmdMatrix34_t matrix = obj->self_->GetRawZeroPoseToStandingAbsoluteTrackingPose();
  info.GetReturnValue().Set(encode(matrix));
}

//=============================================================================
/// virtual uint32_t GetSortedTrackedDeviceIndicesOfClass( ETrackedDeviceClass eTrackedDeviceClass, VR_ARRAY_COUNT(unTrackedDeviceIndexArrayCount) vr::TrackedDeviceIndex_t *punTrackedDeviceIndexArray, uint32_t unTrackedDeviceIndexArrayCount, vr::TrackedDeviceIndex_t unRelativeToTrackedDeviceIndex = k_unTrackedDeviceIndex_Hmd ) = 0;
NAN_METHOD(IVRSystem::GetSortedTrackedDeviceIndicesOfClass)
{
  IVRSystem* obj = ObjectWrap::Unwrap<IVRSystem>(info.Holder());

  if (info.Length() < 1 || info.Length() > 2)
  {
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  if (!info[0]->IsNumber())
  {
    Nan::ThrowTypeError("Argument[0] must be a number (ETrackedDeviceClass).");
    return;
  }

  uint32_t nTrackedDeviceClass = Nan::To<int32_t>(info[0]).ToChecked();
  if (nTrackedDeviceClass >= 6)
  {
    Nan::ThrowTypeError("Argument[0] was out of enum range (ETrackedDeviceClass).");
    return;
  }

  vr::TrackedDeviceIndex_t unRelativeToTrackedDeviceIndex = 0;
  if (!info[1]->IsUndefined())
  {
    if (!info[1]->IsNumber())
    {
      Nan::ThrowTypeError("Argument[1] must be a number.");
      return;
    }
    else
    {
      unRelativeToTrackedDeviceIndex = Nan::To<int32_t>(info[1]).ToChecked();
    }
  }

  vr::ETrackedDeviceClass eTrackedDeviceClass =
    static_cast<vr::ETrackedDeviceClass>(nTrackedDeviceClass);
  TrackedDeviceIndexArray trackedDeviceIndexArray;
  uint32_t nDeviceIndices = obj->self_->GetSortedTrackedDeviceIndicesOfClass(
    eTrackedDeviceClass, trackedDeviceIndexArray.data(),
    static_cast<uint32_t>(trackedDeviceIndexArray.size()),
    unRelativeToTrackedDeviceIndex
  );

  info.GetReturnValue().Set(encode(trackedDeviceIndexArray, nDeviceIndices));
}

//=============================================================================
/// virtual EDeviceActivityLevel GetTrackedDeviceActivityLevel( vr::TrackedDeviceIndex_t unDeviceId ) = 0;
NAN_METHOD(IVRSystem::GetTrackedDeviceActivityLevel)
{
  IVRSystem* obj = ObjectWrap::Unwrap<IVRSystem>(info.Holder());

  if (info.Length() != 1)
  {
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  if (!info[0]->IsNumber())
  {
    Nan::ThrowTypeError("Argument[0] must be a number.");
    return;
  }

  uint32_t unDeviceId = Nan::To<int32_t>(info[0]).ToChecked();
  vr::EDeviceActivityLevel deviceActivityLevel =
    obj->self_->GetTrackedDeviceActivityLevel(unDeviceId);
  info.GetReturnValue().Set(Nan::New<Number>(
    static_cast<uint32_t>(deviceActivityLevel)));
}

//=============================================================================
/// virtual void ApplyTransform( TrackedDevicePose_t *pOutputPose, const TrackedDevicePose_t *pTrackedDevicePose, const HmdMatrix34_t *pTransform ) = 0;
NAN_METHOD(IVRSystem::ApplyTransform)
{
  IVRSystem* obj = ObjectWrap::Unwrap<IVRSystem>(info.Holder());

  if (info.Length() != 2)
  {
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  if (!info[0]->IsObject())
  {
    Nan::ThrowTypeError("Argument[0] must be a tracked device pose.");
    return;
  }

  if (!info[1]->IsArray())
  {
    Nan::ThrowTypeError("Argument[1] must be a 3x4 matrix.");
    return;
  }

  const auto trackedDevicePose = decode<vr::TrackedDevicePose_t>(info[0]);
  const auto transform = decode<vr::HmdMatrix34_t>(info[1]);
  vr::TrackedDevicePose_t outputPose;
  obj->self_->ApplyTransform(&outputPose, &trackedDevicePose, &transform);
  info.GetReturnValue().Set(encode(outputPose));
}

//=============================================================================
/// virtual ETrackedDeviceClass GetTrackedDeviceClass( vr::TrackedDeviceIndex_t unDeviceIndex ) = 0;
NAN_METHOD(IVRSystem::GetTrackedDeviceClass)
{
  IVRSystem* obj = ObjectWrap::Unwrap<IVRSystem>(info.Holder());

  if (info.Length() != 1)
  {
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  if (!info[0]->IsNumber())
  {
    Nan::ThrowTypeError("Argument[0] must be a number.");
    return;
  }

  uint32_t unDeviceIndex = Nan::To<int32_t>(info[0]).ToChecked();
  vr::ETrackedDeviceClass trackedDeviceClass =
    obj->self_->GetTrackedDeviceClass(unDeviceIndex);
  info.GetReturnValue().Set(Nan::New<Number>(
    static_cast<uint32_t>(trackedDeviceClass)));
}

//=============================================================================
/// virtual bool CaptureInputFocus() = 0;
NAN_METHOD(IVRSystem::CaptureInputFocus)
{
  IVRSystem* obj = ObjectWrap::Unwrap<IVRSystem>(info.Holder());

  if (info.Length() != 0)
  {
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  const auto result = obj->self_->CaptureInputFocus();
  info.GetReturnValue().Set(Nan::New<Boolean>(result));
}

//=============================================================================
/// virtual void ReleaseInputFocus() = 0;
NAN_METHOD(IVRSystem::ReleaseInputFocus)
{
  IVRSystem* obj = ObjectWrap::Unwrap<IVRSystem>(info.Holder());

  if (info.Length() != 0)
  {
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  obj->self_->ReleaseInputFocus();
}

//=============================================================================
/// virtual bool IsInputFocusCapturedByAnotherProcess() = 0;
NAN_METHOD(IVRSystem::IsInputFocusCapturedByAnotherProcess)
{
  IVRSystem* obj = ObjectWrap::Unwrap<IVRSystem>(info.Holder());

  if (info.Length() != 0)
  {
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  const auto result = obj->self_->IsInputFocusCapturedByAnotherProcess();
  info.GetReturnValue().Set(Nan::New<Boolean>(result));
}

//=============================================================================
/// virtual void AcknowledgeQuit_Exiting() = 0;
NAN_METHOD(IVRSystem::AcknowledgeQuit_Exiting)
{
  IVRSystem* obj = ObjectWrap::Unwrap<IVRSystem>(info.Holder());

  if (info.Length() != 0)
  {
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  obj->self_->AcknowledgeQuit_Exiting();
}

//=============================================================================
/// virtual void AcknowledgeQuit_UserPrompt() = 0;
NAN_METHOD(IVRSystem::AcknowledgeQuit_UserPrompt)
{
  IVRSystem* obj = ObjectWrap::Unwrap<IVRSystem>(info.Holder());

  if (info.Length() != 0)
  {
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  obj->self_->AcknowledgeQuit_UserPrompt();
}
