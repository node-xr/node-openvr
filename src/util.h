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
  v8::Local<v8::Array> result = Nan::New<v8::Array>();

  for (unsigned int rowIdx = 0; rowIdx < 4; ++rowIdx)
  {
    v8::Local<v8::Array> row = Nan::New<v8::Array>();
    for (unsigned int colIdx = 0; colIdx < 4; ++colIdx)
    {
      Nan::Set(row, colIdx, Nan::New<v8::Number>(value.m[rowIdx][colIdx]));
    }
    Nan::Set(result, rowIdx, row);
  }

  return scope.Escape(result);
}

#endif // NODE_UTIL_H
