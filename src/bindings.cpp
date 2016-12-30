#include <node.h>
#include <nan.h>
#include <v8.h>

NAN_METHOD(nothing) {
  // Do nothing.
}

NAN_MODULE_INIT(Init) {
}

NODE_MODULE(openvr, Init);
