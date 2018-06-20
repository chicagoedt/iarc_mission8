/* Web server code for drone, used for website and autonomous flying */
var express = require('express');
var arDrone = require('ar-drone'); // converts parrot sdk to node js
var http = require('http');
var client = arDrone.createClient();
var app = express();
app.use(express.static('public'));
var path = require('path');
var fs = require('fs');
var nameToFind = "";

app.get('/', function (req, res) {
    res.sendFile(path.join(__dirname + '/index.html'));
});

app.get('/land', function (req, res) {

    client.stop(0);
    client.land();

    console.log("Drone is now landing");
});

app.get('/takeoff', function (req, res) {
    console.log("Drone Taking Off!");

    client.takeoff();

});

app.get('/calibrate', function (req, res) {
    client.calibrate(0);
    console.log("Drone Calibrating! Stand Clear!");
});
app.get('/flip', function (req, res) {

    client.animate('flipAhead', 1000);
    console.log("Flip Forward!");
});
app.get('/spin', function (req, res) {
    client.calibrate(0);
    console.log("Drone Rotating Clockwise Stand Clear!");
});
app.get('/camerabottom', function (req, res) {
    client.config('video:video_channel', 3);
    console.log("pointing below");
});
app.get('/cameraforward', function (req, res) {
    client.config('video:video_channel', 0);

    console.log("pointing forward");
});


app.get('/photos', function (req, res) {
    console.log("Drone Taking Pictures");

    var pngStream = client.getPngStream();
    var period = 2000; // Save a frame every 2000 ms.
    var lastFrameTime = 0;
    pngStream
      .on('error', console.log)
      .on('data', function (pngBuffer) {
          var now = (new Date()).getTime();
          if (now - lastFrameTime > period) {
              lastFrameTime = now;
              fs.writeFile(__dirname + '/public/DroneImage.png', pngBuffer, function (err) {
                  if (err) {
                      console.log("Error saving PNG: " + err);
                  } else {
                      console.log("Saved Frame");
                  }
              });
          }
      });
});

/*
 This is a new router function in our file.
 You can see EXACTLY what is sent to the back-end there is a console.log line 
 which prints the value of the parameter inputspeech which is passed in with the request.  
*/
app.get('/audio', function (req, res) {
    console.log(req.query.inputspeech);
    nameToFind = req.query.inputspeech;
    if (name == "hello") {
        var tts = require('./TextToSpeechService.js');
        tts.Synthesize("Hello");
    }
});



app.get('/audio', function (req, res) {
    console.log(req.query.inputspeech);
    nameToFind = req.query.inputspeech;
    console.log("Drone Taking Off");
    client.takeoff();
    console.log("Drone Taking Pictures");
    var pngStream = client.getPngStream();
    var period = 5000; // Save a frame every 5000 ms.
    var lastFrameTime = 0;
    pngStream
     .on('error', console.log)
     .on('data', function (pngBuffer) {
         var now = (new Date()).getTime();
         if (now - lastFrameTime > period && found == false) {
             lastFrameTime = now;
             fs.writeFile(__dirname + '/Public/DroneImage.png', pngBuffer, function (err) {
                 if (err) {
                     console.log("Error saving PNG: " + err);
                 } else {
                     console.log("Saved Frame");
                     mapPersonList(myGroup);
                     identifyPATH(__dirname + '/Public/DroneImage.png', myGroup);
                 }
             });
         }
     });
});



app.get('/clockwise', function (req, res) {
    client.clockwise(0.5);
    console.log("Drone Turning Clockwise");
});



app.listen(3000, function () {
});

