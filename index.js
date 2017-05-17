const openvr = require('bindings')('openvr');

openvr.EVRInitError = {
  'VRInitError_None': 0,
  'VRInitError_Unknown': 1,

  'VRInitError_Init_InstallationNotFound': 100,
  'VRInitError_Init_InstallationCorrupt': 101,
  'VRInitError_Init_VRClientDLLNotFound': 102,
  'VRInitError_Init_FileNotFound': 103,
  'VRInitError_Init_FactoryNotFound': 104,
  'VRInitError_Init_InterfaceNotFound': 105,
  'VRInitError_Init_InvalidInterface': 106,
  'VRInitError_Init_UserConfigDirectoryInvalid': 107,
  'VRInitError_Init_HmdNotFound': 108,
  'VRInitError_Init_NotInitialized': 109,
  'VRInitError_Init_PathRegistryNotFound': 110,
  'VRInitError_Init_NoConfigPath': 111,
  'VRInitError_Init_NoLogPath': 112,
  'VRInitError_Init_PathRegistryNotWritable': 113,
  'VRInitError_Init_AppInfoInitFailed': 114,
  'VRInitError_Init_Retry': 115,
  'VRInitError_Init_InitCanceledByUser': 116,
  'VRInitError_Init_AnotherAppLaunching': 117,
  'VRInitError_Init_SettingsInitFailed': 118,
  'VRInitError_Init_ShuttingDown': 119,
  'VRInitError_Init_TooManyObjects': 120,
  'VRInitError_Init_NoServerForBackgroundApp': 121,
  'VRInitError_Init_NotSupportedWithCompositor': 122,
  'VRInitError_Init_NotAvailableToUtilityApps': 123,
  'VRInitError_Init_Internal': 124,
  'VRInitError_Init_HmdDriverIdIsNone': 125,
  'VRInitError_Init_HmdNotFoundPresenceFailed': 126,
  'VRInitError_Init_VRMonitorNotFound': 127,
  'VRInitError_Init_VRMonitorStartupFailed': 128,
  'VRInitError_Init_LowPowerWatchdogNotSupported': 129,
  'VRInitError_Init_InvalidApplicationType': 130,
  'VRInitError_Init_NotAvailableToWatchdogApps': 131,
  'VRInitError_Init_WatchdogDisabledInSettings': 132,
  'VRInitError_Init_VRDashboardNotFound': 133,
  'VRInitError_Init_VRDashboardStartupFailed': 134,

  'VRInitError_Driver_Failed': 200,
  'VRInitError_Driver_Unknown': 201,
  'VRInitError_Driver_HmdUnknown': 202,
  'VRInitError_Driver_NotLoaded': 203,
  'VRInitError_Driver_RuntimeOutOfDate': 204,
  'VRInitError_Driver_HmdInUse': 205,
  'VRInitError_Driver_NotCalibrated': 206,
  'VRInitError_Driver_CalibrationInvalid': 207,
  'VRInitError_Driver_HmdDisplayNotFound': 208,
  'VRInitError_Driver_TrackedDeviceInterfaceUnknown': 209,
  'VRInitError_Driver_HmdDriverIdOutOfBounds': 211,
  'VRInitError_Driver_HmdDisplayMirrored': 212,

  'VRInitError_IPC_ServerInitFailed': 300,
  'VRInitError_IPC_ConnectFailed': 301,
  'VRInitError_IPC_SharedStateInitFailed': 302,
  'VRInitError_IPC_CompositorInitFailed': 303,
  'VRInitError_IPC_MutexInitFailed': 304,
  'VRInitError_IPC_Failed': 305,
  'VRInitError_IPC_CompositorConnectFailed': 306,
  'VRInitError_IPC_CompositorInvalidConnectResponse': 307,
  'VRInitError_IPC_ConnectFailedAfterMultipleAttempts': 308,

  'VRInitError_Compositor_Failed': 400,
  'VRInitError_Compositor_D3D11HardwareRequired': 401,
  'VRInitError_Compositor_FirmwareRequiresUpdate': 402,
  'VRInitError_Compositor_OverlayInitFailed': 403,
  'VRInitError_Compositor_ScreenshotsInitFailed': 404,

  'VRInitError_VendorSpecific_UnableToConnectToOculusRuntime': 1000,

  'VRInitError_VendorSpecific_HmdFound_CantOpenDevice': 1101,
  'VRInitError_VendorSpecific_HmdFound_UnableToRequestConfigStart': 1102,
  'VRInitError_VendorSpecific_HmdFound_NoStoredConfig': 1103,
  'VRInitError_VendorSpecific_HmdFound_ConfigTooBig': 1104,
  'VRInitError_VendorSpecific_HmdFound_ConfigTooSmall': 1105,
  'VRInitError_VendorSpecific_HmdFound_UnableToInitZLib': 1106,
  'VRInitError_VendorSpecific_HmdFound_CantReadFirmwareVersion': 1107,
  'VRInitError_VendorSpecific_HmdFound_UnableToSendUserDataStart': 1108,
  'VRInitError_VendorSpecific_HmdFound_UnableToGetUserDataStart': 1109,
  'VRInitError_VendorSpecific_HmdFound_UnableToGetUserDataNext': 1110,
  'VRInitError_VendorSpecific_HmdFound_UserDataAddressRange': 1111,
  'VRInitError_VendorSpecific_HmdFound_UserDataError': 1112,
  'VRInitError_VendorSpecific_HmdFound_ConfigFailedSanityCheck': 1113,

  'VRInitError_Steam_SteamInstallationNotFound': 2000,
}

openvr.EVRApplicationType = {
	'VRApplication_Other': 0,
	'VRApplication_Scene': 1,
	'VRApplication_Overlay': 2,
	'VRApplication_Background': 3,
	'VRApplication_Utility': 4,
	'VRApplication_VRMonitor': 5,
	'VRApplication_SteamWatchdog': 6,
};

openvr.EVREye = {
	'Eye_Left': 0,
	'Eye_Right': 1,
};

openvr.EGraphicsAPIConvention = {
	'API_DirectX': 0,
	'API_OpenGL': 1,
};

module.exports = openvr;
