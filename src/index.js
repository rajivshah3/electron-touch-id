const electronTouchID = require('../build/Release/electron-touch-id.node');

console.log(electronTouchID.authenticate());
console.log(electronTouchID.isSupported());
