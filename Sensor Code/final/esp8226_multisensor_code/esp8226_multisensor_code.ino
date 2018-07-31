#include <ESP8266WiFi.h>


/* Sensor Echo Trig Pin Setup */
//FRONT
const int trigPin1=2;
const int echoPin1=0;

//RIGHT
const int trigPin2=15;
const int echoPin2=13;

//BACK
const int trigPin3=10;
const int echoPin3=9;

//LEFT
const int trigPin4=4;
const int echoPin4=5;


/* Threshold Setup */
//Time in millseconds
int delayTime = 200;
const int numberInterval = 5; 
const int maxThreshold = 30; // distance in cm



long duration1, distance1;
long duration2, distance2;
long duration3, distance3;
long duration4, distance4;

  int topTotal, topAverage;
  int rightTotal, rightAverage;
  int bottomTotal, bottomAverage;
  int leftTotal, leftAverage;
  
/* .ESP 2866 Setup */
const char* ssid = "NETGEAR05";
const char* password = "noisysheep052";
WiFiServer server(80); //5555


void setup() {  
  Serial.begin (9600);

  Serial.print("wtf");
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);

  //Serial.begin(115200);
  delay(10);

  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("wifi connected");

  //Start server
  server.begin();
  Serial.println("Server started");
  //Print IP
  Serial.print("Use this URL to connect: http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop() {
  WiFiClient client = server.available();
  if(!client) {
    return;
  }

  //Waits until client sends data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  
  // Read the first line of the request 
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  
  topTotal = 0;
  rightTotal = 0;
  bottomTotal = 0;
  leftTotal = 0;
  
  for (int i = 0; i < numberInterval; i++) {
    
    digitalWrite(trigPin1, LOW);
    delayMicroseconds(2); 
    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(10); 
    digitalWrite(trigPin1, LOW);
    duration1 = pulseIn(echoPin1, HIGH);
    distance1 = (duration1/2) / 29.1;

    topTotal += distance1;
    
    /*
     if (distance1 >= 500 || distance1 <= 0){
      Serial.println("Out of range");
    }
    else {
      Serial.print ( "Sensor1  ");
      Serial.print ( distance1);
      Serial.println("cm");
    }
    */
    
    delay(delayTime);
    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2, LOW);
    duration2 = pulseIn(echoPin2, HIGH);
    distance2= (duration2/2) / 29.1;

    rightTotal += distance2;
    
  /*
     if (distance2 >= 500 || distance2 <= 0){
      Serial.println("Out of range");
    }
    else {
      Serial.print("Sensor2  ");
      Serial.print(distance2);
      Serial.println("cm");
    }
   */
   
   
    delay(delayTime);
    digitalWrite(trigPin3, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin3, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin3, LOW);
    duration3 = pulseIn(echoPin3, HIGH);
    distance3= (duration3/2) / 29.1;

    bottomTotal += distance3;
    
    /*
     if (distance3 >= 500 || distance3 <= 0){
      Serial.println("Out of range");
    }
    else {
      Serial.print("Sensor3  ");
      Serial.print(distance3);
      Serial.println("cm");
    }
    */
    
    delay(delayTime);  
    digitalWrite(trigPin4, LOW);
    delayMicroseconds(2); 
    digitalWrite(trigPin4, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin4, LOW);
    duration4 = pulseIn(echoPin4, HIGH);
    distance4= (duration4/2) / 29.1;

    leftTotal += distance4;
    
    /*
     if (distance4 >= 500 || distance4 <= 0){
      Serial.print("Sensor4  ");
      Serial.print(distance3);
      Serial.println("cm");
    }
    else {
      Serial.print("Sensor4  ");
      Serial.print(distance4);
      Serial.print("cm");
    }
    */
    delay(delayTime);
  
  topAverage = topTotal / numberInterval;
  rightAverage = rightTotal / numberInterval;
  bottomAverage = bottomTotal / numberInterval;
  leftAverage  = leftTotal / numberInterval;

  }
  
  if (topAverage < maxThreshold) {
    Serial.print("TOP");
    Serial.print(maxThreshold + 10 - topAverage);
  }

  if (rightAverage < maxThreshold) {
    Serial.print("RIGHT");
    Serial.print(maxThreshold + 10 - rightAverage);
  }    
  
  if (bottomAverage < maxThreshold) {
      Serial.print("BOTTOM");
      Serial.print(maxThreshold + 10 - bottomAverage);
  }

  if (leftAverage < maxThreshold) {
      Serial.print("LEFT");
      Serial.print(maxThreshold + 10 - leftAverage);
  }


}
