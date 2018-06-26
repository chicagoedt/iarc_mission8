/* Main file that is executed by user
 * Does all autonomous movement decisions
 * Uses serial-comm.js for sensor communication
 * Uses drone-web-server.js for monitor streaming
 * Uses autocode.js for algorithmic decisions on movement
 */


 
//Runs monitoring script
 var monitor = require('./drone-web-server');
 
//Runs listening script
 
//Runs sensor com script
var serialcomm = require('./serial-comm');

//Runs algorithmic script
 var autonav = require('./autocode');
 