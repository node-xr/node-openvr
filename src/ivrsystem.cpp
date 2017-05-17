#include "ivrsystem.h"
#include "util.h"

#include <node.h>
#include <openvr.h>

using namespace v8;

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
  /// virtual HmdMatrix44_t GetProjectionMatrix( EVREye eEye, float fNearZ, float fFarZ ) = 0;
  /// virtual void GetProjectionRaw( EVREye eEye, float *pfLeft, float *pfRight, float *pfTop, float *pfBottom ) = 0;
  /// virtual bool ComputeDistortion( EVREye eEye, float fU, float fV, DistortionCoordinates_t *pDistortionCoordinates ) = 0;
  ///	virtual HmdMatrix34_t GetEyeToHeadTransform( EVREye eEye ) = 0;
  /// virtual bool GetTimeSinceLastVsync( float *pfSecondsSinceLastVsync, uint64_t *pulFrameCounter ) = 0;
  /// virtual int32_t GetD3D9AdapterIndex() = 0;
  /// virtual void GetDXGIOutputInfo( int32_t *pnAdapterIndex ) = 0;
  /// virtual bool IsDisplayOnDesktop() = 0;
  /// virtual bool SetDisplayVisibility( bool bIsVisibleOnDesktop ) = 0;
  /// virtual void GetDeviceToAbsoluteTrackingPose( ETrackingUniverseOrigin eOrigin, float fPredictedSecondsToPhotonsFromNow, VR_ARRAY_COUNT(unTrackedDevicePoseArrayCount) TrackedDevicePose_t *pTrackedDevicePoseArray, uint32_t unTrackedDevicePoseArrayCount ) = 0;
  /// virtual void ResetSeatedZeroPose() = 0;
  /// virtual HmdMatrix34_t GetSeatedZeroPoseToStandingAbsoluteTrackingPose() = 0;
  /// virtual HmdMatrix34_t GetRawZeroPoseToStandingAbsoluteTrackingPose() = 0;
  /// virtual uint32_t GetSortedTrackedDeviceIndicesOfClass( ETrackedDeviceClass eTrackedDeviceClass, VR_ARRAY_COUNT(unTrackedDeviceIndexArrayCount) vr::TrackedDeviceIndex_t *punTrackedDeviceIndexArray, uint32_t unTrackedDeviceIndexArrayCount, vr::TrackedDeviceIndex_t unRelativeToTrackedDeviceIndex = k_unTrackedDeviceIndex_Hmd ) = 0;
  /// virtual EDeviceActivityLevel GetTrackedDeviceActivityLevel( vr::TrackedDeviceIndex_t unDeviceId ) = 0;
  /// virtual void ApplyTransform( TrackedDevicePose_t *pOutputPose, const TrackedDevicePose_t *pTrackedDevicePose, const HmdMatrix34_t *pTransform ) = 0;
  /// virtual vr::TrackedDeviceIndex_t GetTrackedDeviceIndexForControllerRole( vr::ETrackedControllerRole unDeviceType ) = 0;
  /// virtual vr::ETrackedControllerRole GetControllerRoleForTrackedDeviceIndex( vr::TrackedDeviceIndex_t unDeviceIndex ) = 0;
  /// virtual ETrackedDeviceClass GetTrackedDeviceClass( vr::TrackedDeviceIndex_t unDeviceIndex ) = 0;
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
  /// virtual HiddenAreaMesh_t GetHiddenAreaMesh( EVREye eEye, EHiddenAreaMeshType type = k_eHiddenAreaMesh_Standard ) = 0;
  /// virtual bool GetControllerState( vr::TrackedDeviceIndex_t unControllerDeviceIndex, vr::VRControllerState_t *pControllerState, uint32_t unControllerStateSize ) = 0;
  /// virtual bool GetControllerStateWithPose( ETrackingUniverseOrigin eOrigin, vr::TrackedDeviceIndex_t unControllerDeviceIndex, vr::VRControllerState_t *pControllerState, uint32_t unControllerStateSize, TrackedDevicePose_t *pTrackedDevicePose ) = 0;
  /// virtual void TriggerHapticPulse( vr::TrackedDeviceIndex_t unControllerDeviceIndex, uint32_t unAxisId, unsigned short usDurationMicroSec ) = 0;
  /// virtual const char *GetButtonIdNameFromEnum( EVRButtonId eButtonId ) = 0;
  /// virtual const char *GetControllerAxisTypeNameFromEnum( EVRControllerAxisType eAxisType ) = 0;
  /// virtual bool CaptureInputFocus() = 0;
  /// virtual void ReleaseInputFocus() = 0;
  /// virtual bool IsInputFocusCapturedByAnotherProcess() = 0;
  /// virtual uint32_t DriverDebugRequest( vr::TrackedDeviceIndex_t unDeviceIndex, const char *pchRequest, char *pchResponseBuffer, uint32_t unResponseBufferSize ) = 0;
  /// virtual vr::EVRFirmwareError PerformFirmwareUpdate( vr::TrackedDeviceIndex_t unDeviceIndex ) = 0;
  /// virtual void AcknowledgeQuit_Exiting() = 0;
  /// virtual void AcknowledgeQuit_UserPrompt() = 0;

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

  uint32_t nWidth;
  uint32_t nHeight;
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
/// virtual HmdMatrix44_t GetProjectionMatrix( EVREye eEye, float fNearZ, float fFarZ, EGraphicsAPIConvention eProjType ) = 0;
NAN_METHOD(IVRSystem::GetProjectionMatrix)
{
  IVRSystem* obj = ObjectWrap::Unwrap<IVRSystem>(info.Holder());

  if (info.Length() != 4)
  {
    Nan::ThrowError("Wrong number of arguments.");
    return;
  }

  if (!info[0]->IsNumber())
  {
    Nan::ThrowTypeError("Argument[0] must be a number (EVREye).");
    return;
  }

  uint32_t nEye = info[0]->Uint32Value();
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

  if (!info[3]->IsNumber())
  {
    Nan::ThrowTypeError("Argument[3] must be a number (EVREye).");
    return;
  }

  uint32_t nProjType = info[3]->Uint32Value();
  if (nProjType >= 2)
  {
    Nan::ThrowTypeError("Argument[3] was out of enum range (EGraphicsAPIConvention).");
    return;
  }

  vr::EVREye eEye = static_cast<vr::EVREye>(nEye);
  float fNearZ = static_cast<float>(info[1]->NumberValue());
  float fFarZ = static_cast<float>(info[2]->NumberValue());
  vr::EGraphicsAPIConvention eProjType = static_cast<vr::EGraphicsAPIConvention>(nProjType);
  vr::HmdMatrix44_t matrix = obj->self_->GetProjectionMatrix(eEye, fNearZ, fFarZ, eProjType);

  info.GetReturnValue().Set(convert(matrix));
}

//=============================================================================
IVRSystem::IVRSystem(vr::IVRSystem *self)
: self_(self)
{
  // Do nothing.
}
