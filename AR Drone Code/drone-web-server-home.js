var express = require('express');
var arDrone = require('ar-drone');
var http    = require('http');
var client = arDrone.createClient({ip:"192.168.1.69"});
var app = express();
app.use(express.static('public'));
var path = require('path');
var fs = require('fs');


app.get('/', function (req, res) {
 res.sendFile(path.join(__dirname + '/index.html'));
});

app.get('/land', function(req, res) {
 var tts = require('./TextToSpeechService.js');  
 tts.Synthesize("I am now landing");
 client.stop(0);
 client.land();
 
 console.log("Drone is now landing");
});

app.get('/takeoff', function(req, res) {
 console.log("Drone Taking Off!");
 var tts = require('./TextToSpeechService.js');
 tts.Synthesize("Time To Take off!") 
 client.takeoff();
 
});
app.get('/flip',function(req,res){
 var tts = require('./TextToSpeechService.js');  
 tts.Synthesize("Flip Forward Look Out!");
 client.animate('flipAhead', 1000);
 console.log("Flip Forward!");
});
app.get('/spin',function(req,res){
 client.calibrate(0);
 console.log("Drone Calibrating! Stand Clear!");
});


app.get('/photos', function(req, res) {
   console.log("Drone Taking Pictures");
   var tts = require('./TextToSpeechService.js');
   tts.Synthesize("Say Cheese!")    
   var pngStream = client.getPngStream();
   var period = 2000; // Save a frame every 2000 ms.
   var lastFrameTime = 0;
   pngStream
     .on('error', console.log)
     .on('data', function(pngBuffer) {
        var now = (new Date()).getTime();
        if (now - lastFrameTime > period) {
           lastFrameTime = now;
           fs.writeFile(__dirname + '/public/DroneImage.png', pngBuffer, function(err) {
           if (err) {
             console.log("Error saving PNG: " + err);
           } else {
             console.log("Saved Frame");  
          }
      });
     }
  });
 });

app.get('/clockwise', function(req, res) {
 client.clockwise(0.5);
 console.log("Drone Turning Clockwise");
}); 



app.listen(3000, function () {
});
