#include "ivrsystem.h"

#include <node.h>
#include <openvr.h>
#include <v8.h>

IVRSystem::IVRSystem(vr::IVRSystem *self)
: self_(self)
{
  // Do nothing.
}

IVRSystem::~IVRSystem()
{
  // Do nothing.
}
