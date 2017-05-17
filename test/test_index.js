const assert = require('assert');
const openvr = require('../index');

describe('openvr', function() {
  describe('#VR_Init()', function() {
    it('should return an IVRSystem.', function() {
      const system = openvr.VR_Init(openvr.EVRApplicationType.VRApplication_Utility);
      assert.ok(system);
      openvr.VR_Shutdown();
    });
  });
});
