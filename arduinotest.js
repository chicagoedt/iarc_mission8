// $ node arduinotest.js COM#
// find the COM number that the arduino is connected to and type COM# after the node command

var serialport = require('serialport');
var portName = process.argv[2];

var myPort = new serialport(portName, {
    baudRate: 9600,
    parser: new serialport.parsers.Readline('\r\n')
});

myPort.on('open', onOpen);
myPort.on('data', onData);

function onOpen(){
    console.log('Open connection!');
}

function onData(data){
    console.log('on Data ' + data);
}
