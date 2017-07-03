const chai = require('chai');
const dirtyChai = require('dirty-chai');
const expect = require('chai').expect;
const openvr = require('../index');

chai.use(dirtyChai);

describe('openvr', () => {
  describe('#VR_Init()', () => {
    it('should return an IVRSystem', () => {
      const system = openvr.VR_Init(openvr.EVRApplicationType.Utility);
      expect(system).to.be.ok();
      openvr.VR_Shutdown();
    });
  });

  describe('#VR_IsHmdPresent()', () => {
    it('should return a boolean', () => {
      const result = openvr.VR_IsHmdPresent();
      expect(result).to.be.a('boolean');
    });
  });

  describe('#VR_IsRuntimeInstalled', () => {
    it('should return a boolean', () => {
      const result = openvr.VR_IsRuntimeInstalled();
      expect(result).to.be.a('boolean');
    });
  });

  describe('#VR_RuntimePath', () => {
    it('should return a string', () => {
      const result = openvr.VR_RuntimePath();
      expect(result).to.be.a('string');
    });
  });

  describe('#VR_GetVRInitErrorAsSymbol', () => {
    it('should return a string', () => {
      const result = openvr.VR_GetVRInitErrorAsSymbol(openvr.EVRInitError.Unknown);
      expect(result).to.be.a('string');
    });
  });

  describe('#VR_GetVRInitErrorAsEnglishDescription', () => {
    it('should return a string', () => {
      const result = openvr.VR_GetVRInitErrorAsEnglishDescription(openvr.EVRInitError.Unknown);
      expect(result).to.be.a('string');
    });
  });

  describe('#VR_GetInitToken', () => {
    it('should return a string', () => {
      const result = openvr.VR_GetInitToken();
      expect(result).to.satisfy(Number.isInteger);
    });
  });
});

describe('IVRSystem', () => {
  let ivrsystem;
  before(() => {
    ivrsystem = openvr.VR_Init(openvr.EVRApplicationType.Utility);
  });
  after(() => {
    openvr.VR_Shutdown();
  });

  describe('#GetRecommendedRenderTargetSize', () => {
    it('should return an integer width and height', () => {
      const result = ivrsystem.GetRecommendedRenderTargetSize();
      expect(result.width).to.satisfy(Number.isInteger);
      expect(result.height).to.satisfy(Number.isInteger);
    });
  });

  describe('#GetProjectionMatrix', () => {
    it('should return a 4x4 numeric matrix', () => {
      const result = ivrsystem.GetProjectionMatrix(
        openvr.EVREye.Left, 0, 1000);

      expect(result).to.be.an('array');
      expect(result).to.have.lengthOf(4);
      expect(result[0]).to.be.an('array');
      expect(result[0]).to.have.lengthOf(4);
      expect(result[0][0]).to.be.a('number');
    });
  });

  describe('#GetProjectionRaw', () => {
    it('should return a map of bounds in each direction', () => {
      const result = ivrsystem.GetProjectionRaw(openvr.EVREye.Left);

      expect(result.left).to.be.a('number');
      expect(result.right).to.be.a('number');
      expect(result.top).to.be.a('number');
      expect(result.bottom).to.be.a('number');
    });
  });

  describe('#ComputeDistortion', () => {
    it('should return a pair of numbers for each RGB', () => {
      const result = ivrsystem.ComputeDistortion(
        openvr.EVREye.Left, 0.5, 0.5);

      expect(result.red).to.have.lengthOf(2);
      expect(result.green).to.have.lengthOf(2);
      expect(result.blue).to.have.lengthOf(2);

      expect(result.red[0]).to.be.a('number');
      expect(result.green[0]).to.be.a('number');
      expect(result.blue[0]).to.be.a('number');
    });
  });

  describe('#GetEyeToHeadTransform', () => {
    it('should return a 3x4 numeric matrix', () => {
      const result = ivrsystem.GetEyeToHeadTransform(
        openvr.EVREye.Left);

      expect(result).to.be.an('array');
      expect(result).to.have.lengthOf(3);
      expect(result[0]).to.be.an('array');
      expect(result[0]).to.have.lengthOf(4);
      expect(result[0][0]).to.be.a('number');
    });
  });

  describe('#GetTimeSinceLastVsync', () => {
    it('should return seconds and a frame number', () => {
      const result = ivrsystem.GetTimeSinceLastVsync();

      expect(result.frame).to.satisfy(Number.isInteger);
      expect(result.seconds).to.be.a('number');
    });
  });

  describe('#GetD3D9AdapterIndex', () => {
    it('should return an integer adapter index', () => {
      const result = ivrsystem.GetD3D9AdapterIndex();

      expect(result).to.satisfy(Number.isInteger);
    });
  });

  describe('#GetDXGIOutputInfo', () => {
    it('should return an integer adapter index', () => {
      const result = ivrsystem.GetDXGIOutputInfo();

      expect(result).to.satisfy(Number.isInteger);
    });
  });

  describe('#IsDisplayOnDesktop', () => {
    it('should return a boolean value', () => {
      const result = ivrsystem.IsDisplayOnDesktop();

      expect(result).to.be.a('boolean');
    });
  });

  describe('#SetDisplayVisibility', () => {
    it('should take a boolean and return a boolean', () => {
      const result = ivrsystem.SetDisplayVisibility(false);

      expect(result).to.be.a('boolean');
    });
  });

  describe('#GetDeviceToAbsoluteTrackingPose', () => {
    it('should return an array of tracking poses', () => {
      const result = ivrsystem.GetDeviceToAbsoluteTrackingPose(
        openvr.ETrackingUniverseOrigin.Standing, 0.0);

      expect(result).to.be.an('array');
      expect(result).to.have.lengthOf(16); // vr::k_unMaxTrackedDeviceCount

      expect(result[0].deviceToAbsoluteTracking).to.be.an('array');
      expect(result[0].deviceToAbsoluteTracking).to.have.lengthOf(3);
      expect(result[0].deviceToAbsoluteTracking[0]).to.be.an('array');
      expect(result[0].deviceToAbsoluteTracking[0]).to.have.lengthOf(4);
      expect(result[0].deviceToAbsoluteTracking[0][0]).to.be.a('number');

      expect(result[0].velocity).to.have.lengthOf(3);
      expect(result[0].velocity[0]).to.be.a('number');

      expect(result[0].angularVelocity).to.have.lengthOf(3);
      expect(result[0].angularVelocity[0]).to.be.a('number');

      expect(result[0].trackingResult).to.satisfy(Number.isInteger);
      expect(result[0].poseIsValid).to.be.a('boolean');
      expect(result[0].deviceIsConnected).to.be.a('boolean');
    });
  });

  describe('#ResetSeatedZeroPose', () => {
    it('should be a function', () => {
      expect(ivrsystem.ResetSeatedZeroPose).is.a('function');
    });
  });

  describe('#GetSeatedZeroPoseToStandingAbsoluteTrackingPose', () => {
    it('returns a 3x4 matrix', () => {
      const result = ivrsystem.GetSeatedZeroPoseToStandingAbsoluteTrackingPose();

      expect(result).to.be.an('array');
      expect(result).to.have.lengthOf(3);
      expect(result[0]).to.be.an('array');
      expect(result[0]).to.have.lengthOf(4);
      expect(result[0][0]).to.be.a('number');
    });
  });

  describe('#GetRawZeroPoseToStandingAbsoluteTrackingPose', () => {
    it('returns a 3x4 matrix', () => {
      const result = ivrsystem.GetRawZeroPoseToStandingAbsoluteTrackingPose();

      expect(result).to.be.an('array');
      expect(result).to.have.lengthOf(3);
      expect(result[0]).to.be.an('array');
      expect(result[0]).to.have.lengthOf(4);
      expect(result[0][0]).to.be.a('number');
    });
  });

  describe('#GetSortedTrackedDeviceIndicesOfClass', () => {
    it('returns a list of integer indices', () => {
      const result = ivrsystem.GetSortedTrackedDeviceIndicesOfClass(
        openvr.ETrackedDeviceClass.HMD,
      );

      expect(result).to.be.an('array');
      expect(result).to.have.lengthOf(1);
      expect(result[0]).to.be.a('number');
    });

    it('can take an optional relative index', () => {
      const result = ivrsystem.GetSortedTrackedDeviceIndicesOfClass(
        openvr.ETrackedDeviceClass.HMD, 0,
      );

      expect(result).to.be.an('array');
      expect(result).to.have.lengthOf(1);
      expect(result[0]).to.be.a('number');
    });
  });

  describe('#GetTrackedDeviceActivityLevel', () => {
    it('should take an integer and return an integer', () => {
      const result = ivrsystem.GetTrackedDeviceActivityLevel(0);

      expect(result).to.satisfy(Number.isInteger);
    });
  });

  describe('#ApplyTransform', () => {
    it('should take a tracked pose and return it if an identity transform is applied', () => {
      const trackedPose = ivrsystem.GetDeviceToAbsoluteTrackingPose(
        openvr.ETrackingUniverseOrigin.Standing, 0.0)[0];
      const identityTransform = [
        [1, 0, 0, 0],
        [0, 1, 0, 0],
        [0, 0, 1, 0],
      ];
      const result = ivrsystem.ApplyTransform(trackedPose, identityTransform);

      expect(result).to.deep.equal(trackedPose);
    });
  });

  describe('#CaptureInputFocus', () => {
    it('should return a boolean', () => {
      const result = ivrsystem.CaptureInputFocus();
      expect(result).to.be.a('boolean');
    });
  });

  describe('#ReleaseInputFocus', () => {
    it('should be able to be called', () => {
      ivrsystem.ReleaseInputFocus();
    });
  });

  describe('#IsInputFocusCapturedByAnotherProcess', () => {
    it('should return a boolean', () => {
      const result = ivrsystem.IsInputFocusCapturedByAnotherProcess();
      expect(result).to.be.a('boolean');
    });
  });

  describe('#AcknowledgeQuit_Exiting', () => {
    it('should be an available function', () => {
      expect(ivrsystem.AcknowledgeQuit_Exiting).is.a('function');
    });
  });

  describe('#AcknowledgeQuit_UserPrompt', () => {
    it('cannot be tested because it requires a dialog popup', () => {
      expect(ivrsystem.AcknowledgeQuit_UserPrompt).is.a('function');
    });
  });
});
