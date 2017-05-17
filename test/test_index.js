const assert = require('assert');
const expect = require('chai').expect;
const openvr = require('../index');

describe('openvr', () => {
  describe('#VR_Init()', () => {
    it('should return an IVRSystem.', () => {
      const system = openvr.VR_Init(openvr.EVRApplicationType.VRApplication_Utility);
      expect(system).to.not.be.undefined;
      openvr.VR_Shutdown();
    });
  });
});

describe('IVRSystem', () => {
  var ivrsystem;
  before(() => {
    ivrsystem = openvr.VR_Init(openvr.EVRApplicationType.VRApplication_Utility);
  });
  after(() => {
    openvr.VR_Shutdown();
  });

  describe('#GetRecommendedRenderTargetSize', () => {
    it('should return an integer width and height.', () => {
      const result = ivrsystem.GetRecommendedRenderTargetSize();
      expect(result.width).to.satisfy(Number.isInteger);
      expect(result.height).to.satisfy(Number.isInteger);
    });
  });

  describe('#GetProjectionMatrix', () => {
    it('should return a 4x4 numeric matrix.', () => {
      const result = ivrsystem.GetProjectionMatrix(
        openvr.EVREye.Eye_Left, 0, 1000,
        openvr.EGraphicsAPIConvention.API_OpenGL);

      expect(result).to.have.lengthOf(4);
      expect(result[0]).to.have.lengthOf(4);
      expect(result[0][0]).to.be.a('number');
    });
  });

  describe('#GetProjectionRaw', () => {
    it('should return a map of bounds in each direction.', () => {
      const result = ivrsystem.GetProjectionRaw(openvr.EVREye.Eye_Left);

      expect(result['left']).to.be.a('number');
      expect(result['right']).to.be.a('number');
      expect(result['top']).to.be.a('number');
      expect(result['bottom']).to.be.a('number');
    });
  });

  describe('#ComputeDistortion', () => {
    it('should return a pair of numbers for each RGB.', () => {
      const result = ivrsystem.ComputeDistortion(
        openvr.EVREye.Eye_Left, 0.5, 0.5);

      expect(result['red']).to.have.lengthOf(2);
      expect(result['green']).to.have.lengthOf(2);
      expect(result['blue']).to.have.lengthOf(2);

      expect(result['red'][0]).to.be.a('number');
      expect(result['green'][0]).to.be.a('number');
      expect(result['blue'][0]).to.be.a('number');
    });
  });
});
