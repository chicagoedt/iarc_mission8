/* Code used to communicate with Arduino boards to quadcopters */

var SerialPort = require("serialport");
var serialport = new SerialPort("/dev/cu.usbmodem1411");


serialport.on('open', function() {
	baudRate: 9600
	console.log('Serial Port Opened');
	serialport.on('data', function(data) {
		console.log(data[0]);
	});

});
