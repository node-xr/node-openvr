const chai = require('chai');
const dirtyChai = require('dirty-chai');
const expect = require('chai').expect;
const openvr = require('../index');

chai.use(dirtyChai);

describe('openvr', () => {
  describe('#VR_Init()', () => {
    it('should return an IVRSystem', () => {
      const system = openvr.VR_Init(openvr.EVRApplicationType.VRApplication_Utility);
      expect(system).to.be.ok();
      openvr.VR_Shutdown();
    });
  });
});

describe('IVRSystem', () => {
  let ivrsystem;
  before(() => {
    ivrsystem = openvr.VR_Init(openvr.EVRApplicationType.VRApplication_Utility);
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
        openvr.EVREye.Eye_Left, 0, 1000,
        openvr.EGraphicsAPIConvention.API_OpenGL);

      expect(result).to.have.lengthOf(4);
      expect(result[0]).to.have.lengthOf(4);
      expect(result[0][0]).to.be.a('number');
    });
  });

  describe('#GetProjectionRaw', () => {
    it('should return a map of bounds in each direction', () => {
      const result = ivrsystem.GetProjectionRaw(openvr.EVREye.Eye_Left);

      expect(result.left).to.be.a('number');
      expect(result.right).to.be.a('number');
      expect(result.top).to.be.a('number');
      expect(result.bottom).to.be.a('number');
    });
  });

  describe('#ComputeDistortion', () => {
    it('should return a pair of numbers for each RGB', () => {
      const result = ivrsystem.ComputeDistortion(
        openvr.EVREye.Eye_Left, 0.5, 0.5);

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
        openvr.EVREye.Eye_Left);

      expect(result).to.have.lengthOf(3);
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
});
