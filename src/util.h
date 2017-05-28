#ifndef NODE_UTIL_H
#define NODE_UTIL_H

#include <nan.h>
#include <openvr.h>
#include <v8.h>

//=============================================================================
template<typename T>
v8::Local<v8::Object> convert(const T &value);

//=============================================================================
template<>
v8::Local<v8::Object> convert(const vr::HmdMatrix44_t &value)
{
  Nan::EscapableHandleScope scope;
  auto result = Nan::New<v8::Array>();

  for (uint32_t rowIdx = 0; rowIdx < 4; ++rowIdx)
  {
    auto row = Nan::New<v8::Array>();
    for (uint32_t colIdx = 0; colIdx < 4; ++colIdx)
    {
      Nan::Set(row, colIdx, Nan::New<v8::Number>(value.m[rowIdx][colIdx]));
    }
    Nan::Set(result, rowIdx, row);
  }

  return scope.Escape(result);
}

//=============================================================================
template<>
v8::Local<v8::Object> convert(const vr::HmdMatrix34_t &value)
{
  Nan::EscapableHandleScope scope;
  auto result = Nan::New<v8::Array>();

  for (uint32_t rowIdx = 0; rowIdx < 3; ++rowIdx)
  {
    auto row = Nan::New<v8::Array>();
    for (uint32_t colIdx = 0; colIdx < 4; ++colIdx)
    {
      Nan::Set(row, colIdx, Nan::New<v8::Number>(value.m[rowIdx][colIdx]));
    }
    Nan::Set(result, rowIdx, row);
  }

  return scope.Escape(result);
}

//=============================================================================
template<>
v8::Local<v8::Object> convert(const vr::HmdVector3_t &value)
{
  Nan::EscapableHandleScope scope;
  auto result = Nan::New<v8::Array>();

  for (uint32_t idx = 0; idx < 3; ++idx)
    Nan::Set(result, idx, Nan::New<v8::Number>(value.v[idx]));

  return scope.Escape(result);
}

//=============================================================================
template<>
v8::Local<v8::Object> convert(const vr::DistortionCoordinates_t &value)
{
  Nan::EscapableHandleScope scope;
  auto result = Nan::New<v8::Object>();

  // Extract red values.
  {
    auto red = Nan::New<v8::Array>();
    Nan::Set(red, 0, Nan::New<v8::Number>(value.rfRed[0]));
    Nan::Set(red, 1, Nan::New<v8::Number>(value.rfRed[1]));

    auto red_prop = Nan::New<v8::String>("red").ToLocalChecked();
    Nan::Set(result, red_prop, red);
  }

  // Extract green values.
  {
    auto green = Nan::New<v8::Array>();
    Nan::Set(green, 0, Nan::New<v8::Number>(value.rfGreen[0]));
    Nan::Set(green, 1, Nan::New<v8::Number>(value.rfGreen[1]));

    auto green_prop = Nan::New<v8::String>("green").ToLocalChecked();
    Nan::Set(result, green_prop, green);
  }

  // Extract blue values.
  {
    auto blue = Nan::New<v8::Array>();
    Nan::Set(blue, 0, Nan::New<v8::Number>(value.rfBlue[0]));
    Nan::Set(blue, 1, Nan::New<v8::Number>(value.rfBlue[1]));

    auto blue_prop = Nan::New<v8::String>("blue").ToLocalChecked();
    Nan::Set(result, blue_prop, blue);
  }

  return scope.Escape(result);
}

//=============================================================================
template<>
v8::Local<v8::Object> convert(const vr::TrackedDevicePose_t &value)
{
  Nan::EscapableHandleScope scope;
  auto result = Nan::New<v8::Object>();

  auto deviceToAbsoluteTracking_prop =
    Nan::New<v8::String>("deviceToAbsoluteTracking").ToLocalChecked();
  Nan::Set(
    result, deviceToAbsoluteTracking_prop,
    convert(value.mDeviceToAbsoluteTracking)
  );

  auto velocity_prop =
    Nan::New<v8::String>("velocity").ToLocalChecked();
  Nan::Set(result, velocity_prop, convert(value.vVelocity));

  auto angularVelocity_prop =
    Nan::New<v8::String>("angularVelocity").ToLocalChecked();
  Nan::Set(result, angularVelocity_prop, convert(value.vAngularVelocity));

  auto trackingResult_prop =
    Nan::New<v8::String>("trackingResult").ToLocalChecked();
  Nan::Set(
    result, trackingResult_prop,
    Nan::New<v8::Number>(static_cast<uint32_t>(value.eTrackingResult))
  );

  auto poseIsValid_prop =
    Nan::New<v8::String>("poseIsValid").ToLocalChecked();
  Nan::Set(
    result, poseIsValid_prop,
    Nan::New<v8::Boolean>(value.bPoseIsValid)
  );

  auto deviceIsConnected_prop =
    Nan::New<v8::String>("deviceIsConnected").ToLocalChecked();
  Nan::Set(
    result, deviceIsConnected_prop,
    Nan::New<v8::Boolean>(value.bDeviceIsConnected)
  );

  return scope.Escape(result);
}

//=============================================================================
template<size_t N>
v8::Local<v8::Object> convert(const std::array<vr::TrackedDevicePose_t, N> &value)
{
  Nan::EscapableHandleScope scope;
  auto result = Nan::New<v8::Array>();

  for (uint32_t idx = 0; idx < N; ++idx)
    Nan::Set(result, idx, convert(value[idx]));

  return scope.Escape(result);
}

#endif // NODE_UTIL_H
