const assert = require('assert');
const openvr = require('../index');

describe('openvr', () => {
  describe('#VR_Init()', () => {
    it('should return an IVRSystem.', () => {
      const system = openvr.VR_Init(openvr.EVRApplicationType.VRApplication_Utility);
      assert.ok(system);
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
    it('should return a width and height.', () => {
      const result = ivrsystem.GetRecommendedRenderTargetSize();
      assert.ok(result.width);
      assert.ok(result.height);
    });
  });
});
