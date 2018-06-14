// FRONT
int trigPin1=2;
int echoPin1=3;

//RIGHT
int trigPin2=4;
int echoPin2=5;

//BACK
int trigPin3=6;
int echoPin3=7;

//LEFT
int trigPin4=8;
int echoPin4=9;

//Time in millseconds
int delayTime = 200;  

const int numberIntervals = 5; 
const int maxThreshhold = 30; // distance in cm

int topTotal, topAverage;
int rightTotal, rightAverage;
int bottomTotal, bottomAverage;
int leftTotal, leftAverage;

void setup() {
  
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
   pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
   pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
   pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
   pinMode(trigPin5, OUTPUT);
  pinMode(echoPin5, INPUT);

}

void loop() {
   topTotal = 0;
   rightTotal = 0;
   bottomTotal = 0;
   leftTotal = 0;

   
  for (int i = 0; i < numberIntervals; i++) {
    
    long duration1, distance1;
    digitalWrite(trigPin1, LOW);  // Added this line
    delayMicroseconds(2); // Added this line
    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(10); // Added this line
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
  long duration2, distance2;
    digitalWrite(trigPin2, LOW);  // Added this line
    delayMicroseconds(2); // Added this line
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10); // Added this line
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
    long duration3, distance3;
    digitalWrite(trigPin3, LOW);  // Added this line
    delayMicroseconds(2); // Added this line
    digitalWrite(trigPin3, HIGH);
    delayMicroseconds(10); // Added this line
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
  
    long duration4, distance4;
    digitalWrite(trigPin4, LOW);  // Added this line
    delayMicroseconds(2); // Added this line
    digitalWrite(trigPin4, HIGH);
    delayMicroseconds(10); // Added this line
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
  }
  topAverage = topTotal / numberIntervals;
  rightAverage = rightTotal / numberInterval;
  bottomAverage = bottomTotal / numberIntervals;
  leftAverage  = leftTotal / numberIntervals;

  }
  if (topAverage < maxThreshold) {
    Serial.print("TOP");
    Serial.print(maxThreshhold + 10 - topAverage);
  }

  if (rightAverage < maxThreshhold) {
    Serial.print("RIGHT");
    Serial.print(maxThreshhold + 10 - rightAverage);
  }    
  
  if (bottomAverage < maxThreshhold) {
      Serial.print("BOTTOM");
      Serial.print(maxThreshhold + 10 - bottomAverage);
  }

  if (leftAverage < maxThreshhold) {
      Serial.print("LEFT");
      Serial.print(maxThreshold + 10 - leftAverage);
  }
}
