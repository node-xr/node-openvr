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
});
