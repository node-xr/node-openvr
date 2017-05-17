#ifndef NODE_OPENVR_H
#define NODE_OPENVR_H

#include <nan.h>

/// inline IVRSystem *VR_Init( EVRInitError *peError, EVRApplicationType eApplicationType );
NAN_METHOD(VR_Init);

/// inline void VR_Shutdown();
NAN_METHOD(VR_Shutdown);

/// VR_INTERFACE bool VR_CALLTYPE VR_IsHmdPresent();
/// VR_INTERFACE bool VR_CALLTYPE VR_IsRuntimeInstalled();
/// VR_INTERFACE const char *VR_CALLTYPE VR_RuntimePath();
/// VR_INTERFACE const char *VR_CALLTYPE VR_GetVRInitErrorAsSymbol( EVRInitError error );
/// VR_INTERFACE const char *VR_CALLTYPE VR_GetVRInitErrorAsEnglishDescription( EVRInitError error );
/// VR_INTERFACE void *VR_CALLTYPE VR_GetGenericInterface( const char *pchInterfaceVersion, EVRInitError *peError );
/// VR_INTERFACE bool VR_CALLTYPE VR_IsInterfaceVersionValid( const char *pchInterfaceVersion );
/// VR_INTERFACE uint32_t VR_CALLTYPE VR_GetInitToken();

#endif // NODE_OPENVR_H
