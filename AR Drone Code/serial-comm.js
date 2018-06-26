// $ node serial-comm.js COM#
// find the COM number that the arduino is connected to and type COM# after the node command


var arDrone = require('ar-drone');
var client  = arDrone.createClient();

client.takeoff();



var serialport = require('serialport');
var portName = ""; //change so we can use diff ones


var myPort = new serialport(portName, {
  baudRate: 9600,
  parser: new serialport.parsers.Readline('\r\n')
});


myPort.on('open', onOpen);
//myPort.on('data', onData); //change so it runs with the right data input

/* Runs when a new connection is made with the port
 * Lets user know an open connection has been made
 */
function onOpen(){
  console.log('Open connection: ' + portName);
  data = 10;
}

/* Runs when data is inputted by the port
 * Detects if the data given is less than the trigger
 *   and moves drone accordingly
 */
const trigger = 10;
function onDataNumbers(data){
  console.log('Data: ' + data);
  client.stop();
  if(data < trigger && data != 0) {
    console.log('COLLISION WILL HAPPEN');
    //run normal mission
    client.front(.2);
    client.after(3000, function() { //delay in ms
      client.stop();
    });
  }
}

/* Runs when data is inputted by the port
 * Detects what direction the drone should move given by data
 */
function onDataDirection(data) {
  console.log('Dir: ' + data);
  client.stop();
  //interpret serial direction

  client.after(3000, function() {
    client.stop();
  }); //adds delay in ms
}
