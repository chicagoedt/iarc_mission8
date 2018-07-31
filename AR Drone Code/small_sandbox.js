var arDrone = require('ar-drone');
var client  = arDrone.createClient();

client.takeoff();
client.up(0); // this makes sure that it doesn't inscrease height during flight


// the code below is the algorithm to be used in the competion and the code for it to fly autonomously
/*
client
  .after(5000, function() {
    this.front(0.1);  // makes it move forward. it travels ***approximately*** 5 ft/sec
    console.log("launching");
  })
  .after(2000, function() { // hopefull this covers the area, otherwise we're fucked
    this.stop();
  });
  .after(5000, function() { 
    this.back(.1);
  });
  .after(2000, function() { 
    this.right(0.1);
  });
while(1>0){
  client
    .after(2000, function() { 
      this.front(0.1);
  });
    .after(2000, function() { 
      this.stop();
  });
    ..after(5000, function() { 
      this.back(.1);
  });
    .after(2000, function() { 
      this.right(0.1);
  });
}
*/

// the code below is used to test 
client
  .after(5000, function() {
    this.front(0.1);  // makes it move forward. it travels ***approximately*** 5 ft/sec
    console.log("launching");
  })
  .after(3000, function() {
    console.log("stopping");
    this.stop();
    this.land();
  });