const openvr = require('bindings')('openvr');

function test() {
  return openvr;
}

function banana() {

}

module.exports = {
  test,
  banana,
};
