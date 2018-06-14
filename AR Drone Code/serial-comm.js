// $ node serial-comm.js COM#
// find the COM number that the arduino is connected to and type COM# after the node command


var arDrone = require('ar-drone');
var client  = arDrone.createClient();

client.takeoff();



var serialport = require('serialport');
var portName = process.argv[2];

var myPort = new serialport(portName, {
    baudRate: 9600,
    parser: new serialport.parsers.Readline('\r\n')
});

myPort.on('open', onOpen);
myPort.on('data', onData);

function onOpen(){
    console.log('Open connection: ' + portName);
    data = 10;
}

function onData(data){
    console.log('On Data ' + data);
    client.stop();
    if(data < 10 && data != 0) {
    	console.log('COLLISION WILL HAPPEN');
    	//run normal mission
    	client.front(.2);
    	client.after(3000, function() { //delay in ms
				client.stop();
			});
    }
}
