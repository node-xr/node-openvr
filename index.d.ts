declare module "openvr" {
  enum EVRInitError {
    None = 0,
    Unknown = 1,
    Init_InstallationNotFound = 100,
    Init_InstallationCorrupt = 101,
    Init_VRClientDLLNotFound = 102,
    Init_FileNotFound = 103,
    Init_FactoryNotFound = 104,
    Init_InterfaceNotFound = 105,
    Init_InvalidInterface = 106,
    Init_UserConfigDirectoryInvalid = 107,
    Init_HmdNotFound = 108,
    Init_NotInitialized = 109,
    Init_PathRegistryNotFound = 110,
    Init_NoConfigPath = 111,
    Init_NoLogPath = 112,
    Init_PathRegistryNotWritable = 113,
    Init_AppInfoInitFailed = 114,
    Init_Retry = 115,
    Init_InitCanceledByUser = 116,
    Init_AnotherAppLaunching = 117,
    Init_SettingsInitFailed = 118,
    Init_ShuttingDown = 119,
    Init_TooManyObjects = 120,
    Init_NoServerForBackgroundApp = 121,
    Init_NotSupportedWithCompositor = 122,
    Init_NotAvailableToUtilityApps = 123,
    Init_Internal = 124,
    Init_HmdDriverIdIsNone = 125,
    Init_HmdNotFoundPresenceFailed = 126,
    Init_VRMonitorNotFound = 127,
    Init_VRMonitorStartupFailed = 128,
    Init_LowPowerWatchdogNotSupported = 129,
    Init_InvalidApplicationType = 130,
    Init_NotAvailableToWatchdogApps = 131,
    Init_WatchdogDisabledInSettings = 132,
    Init_VRDashboardNotFound = 133,
    Init_VRDashboardStartupFailed = 134,

    Driver_Failed = 200,
    Driver_Unknown = 201,
    Driver_HmdUnknown = 202,
    Driver_NotLoaded = 203,
    Driver_RuntimeOutOfDate = 204,
    Driver_HmdInUse = 205,
    Driver_NotCalibrated = 206,
    Driver_CalibrationInvalid = 207,
    Driver_HmdDisplayNotFound = 208,
    Driver_TrackedDeviceInterfaceUnknown = 209,
    Driver_HmdDriverIdOutOfBounds = 211,
    Driver_HmdDisplayMirrored = 212,

    IPC_ServerInitFailed = 300,
    IPC_ConnectFailed = 301,
    IPC_SharedStateInitFailed = 302,
    IPC_CompositorInitFailed = 303,
    IPC_MutexInitFailed = 304,
    IPC_Failed = 305,
    IPC_CompositorConnectFailed = 306,
    IPC_CompositorInvalidConnectResponse = 307,
    IPC_ConnectFailedAfterMultipleAttempts = 308,

    Compositor_Failed = 400,
    Compositor_D3D11HardwareRequired = 401,
    Compositor_FirmwareRequiresUpdate = 402,
    Compositor_OverlayInitFailed = 403,
    Compositor_ScreenshotsInitFailed = 404,

    VendorSpecific_UnableToConnectToOculusRuntime = 1000,

    VendorSpecific_HmdFound_CantOpenDevice = 1101,
    VendorSpecific_HmdFound_UnableToRequestConfigStart = 1102,
    VendorSpecific_HmdFound_NoStoredConfig = 1103,
    VendorSpecific_HmdFound_ConfigTooBig = 1104,
    VendorSpecific_HmdFound_ConfigTooSmall = 1105,
    VendorSpecific_HmdFound_UnableToInitZLib = 1106,
    VendorSpecific_HmdFound_CantReadFirmwareVersion = 1107,
    VendorSpecific_HmdFound_UnableToSendUserDataStart = 1108,
    VendorSpecific_HmdFound_UnableToGetUserDataStart = 1109,
    VendorSpecific_HmdFound_UnableToGetUserDataNext = 1110,
    VendorSpecific_HmdFound_UserDataAddressRange = 1111,
    VendorSpecific_HmdFound_UserDataError = 1112,
    VendorSpecific_HmdFound_ConfigFailedSanityCheck = 1113,

    Steam_SteamInstallationNotFound = 2000,
  }
  enum EVRApplicationType {
    Other = 0,
    Scene = 1,
    Overlay = 2,
    Background = 3,
    Utility = 4,
    VRMonitor = 5,
    SteamWatchdog = 6,
    Bootstrapper = 7,
  }
  enum EVREye {
    Left = 0,
    Right = 1,
  }
  enum ETrackingUniverseOrigin {
    Seated = 0,
    Standing = 1,
    RawAndUncalibrated = 2,
  }
  enum ETrackingResult {
    Uninitialized = 1,
    Calibrating_InProgress = 100,
    Calibrating_OutOfRange = 101,
    Running_OK = 200,
    Running_OutOfRange = 201,
  }
  enum ETrackedDeviceClass {
    Invalid = 0,
    HMD = 1,
    Controller = 2,
    GenericTracker = 3,
    TrackingReference = 4,
    DisplayRedirect = 5,
  }
  // @TODO : change original type name
  export type RenderSize = {
    width: number;
    height: number;
  };
  // @TODO : change original type name
  export type Rect = {
    left: number;
    right: number;
    top: number;
    bottom: number;
  };
  export type HmdVector3_t = [[number, number, number]];
  export type HmdMatrix44_t = [
    [number, number, number, number],
    [number, number, number, number],
    [number, number, number, number],
    [number, number, number, number]
  ];
  export type HmdMatrix34_t = [
    [number, number, number, number],
    [number, number, number, number],
    [number, number, number, number]
  ];
  export type DistortionCoordinates_t = {
    red: [number, number];
    green: [number, number];
    blue: [number, number];
  };
  // @TODO : change original type name
  export type VsyncSinceTime = {
    frame: number;
    seconds: number;
  };
  export type TrackedDevicePose_t = {
    mDeviceToAbsoluteTracking: HmdMatrix34_t;
    vVelocity: HmdVector3_t;
    vAngularVelocity: HmdVector3_t;
    eTrackingResult: ETrackingResult;
    bPoseIsValid: boolean;
    bDeviceIsConnected: boolean;
  };
  type MaybeTrackedDevicePose_t = TrackedDevicePose_t | undefined;
  // @TODO : change original type name
  export type TrackedDeviceResult = [
    MaybeTrackedDevicePose_t,
    MaybeTrackedDevicePose_t,
    MaybeTrackedDevicePose_t,
    MaybeTrackedDevicePose_t,
    MaybeTrackedDevicePose_t,
    MaybeTrackedDevicePose_t,
    MaybeTrackedDevicePose_t,
    MaybeTrackedDevicePose_t,
    MaybeTrackedDevicePose_t,
    MaybeTrackedDevicePose_t,
    MaybeTrackedDevicePose_t,
    MaybeTrackedDevicePose_t,
    MaybeTrackedDevicePose_t,
    MaybeTrackedDevicePose_t,
    MaybeTrackedDevicePose_t,
    MaybeTrackedDevicePose_t
  ];
  export class IVRSystem {
    GetRecommendedRenderTargetSize(
      pnWidth: number,
      pnHeight: number
    ): RenderRect;
    GetProjectionMatrix(
      eEye: EVREye,
      fNearZ: number,
      fFarZ: number
    ): HmdMatrix44_t;
    GetProjectionRaw(eEye: EVREye): Rect;
    ComputeDistortion(
      eEye: EVREye,
      fU: number,
      fV: number
    ): DistortionCoordinates_t;
    GetEyeToHeadTransform(eEye: EVREye): HmdMatrix34_t;
    GetTimeSinceLastVsync(): VsyncSinceTime;
    // @TODO: fix to correct number range
    GetD3D9AdapterIndex(): number;
    // @TODO: fix to correct number range
    GetDXGIOutputInfo(): number;
    IsDisplayOnDesktop(): boolean;
    SetDisplayVisibility(flag: boolean): boolean;
    GetDeviceToAbsoluteTrackingPose(
      origin: ETrackingUniverseOrigin,
      fPredictedSecondsToPhotonsFromNow: number
    ): TrackedDeviceResult;
    ResetSeatedZeroPose(): void;
    GetSeatedZeroPoseToStandingAbsoluteTrackingPose(): HmdMatrix34_t;
    GetRawZeroPoseToStandingAbsoluteTrackingPose(): HmdMatrix34_t;
    // @TODO change number[] or [nunber]
    GetSortedTrackedDeviceIndicesOfClass(device: ETrackedDeviceClass): number[];
    GetTrackedDeviceActivityLevel(index: number): number;
    ApplyTransform(
      pose: TrackedDevicePose_t,
      matrix: HmdMatrix34_t
    ): TrackedDevicePose_t;
    CaptureInputFocus(): boolean;
    ReleaseInputFocus(): boolean;
    AcknowledgeQuit_Exiting(): void;
    AcknowledgeQuit_UserPrompt(): void;
  }
  function VR_Init(type: EVRApplicationType): IVRSystem;
  function VR_Shutdown(): IVRSystem;
  function VR_IsHmdPresent(): boolean;
  function VR_IsRuntimeInstalled(): boolean;
  function VR_RuntimePath(): string;
  function VR_GetVRInitErrorAsSymbol(symbol: EVRInitError): string;
  function VR_GetVRInitErrorAsEnglishDescription(symbol: EVRInitError): string;
  function VR_GetInitToken(): number;
  export = {
    EVRInitError,
    EVRApplicationType,
    EVREye,
    ETrackingUniverseOrigin,
    ETrackingResult,
    ETrackedDeviceClass,
    // function
    VR_Init,
    VR_Shutdown,
    VR_IsHmdPresent,
    VR_IsRuntimeInstalled,
    VR_RuntimePath,
    VR_GetVRInitErrorAsSymbol,
    VR_GetVRInitErrorAsEnglishDescription,
    VR_GetInitToken,
  };
}
