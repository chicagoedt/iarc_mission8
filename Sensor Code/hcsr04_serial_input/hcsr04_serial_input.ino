const int trigPin = 9; //pin connected to arduino, sensor trigger
const int echoPin = 10; //pin connected to arduino, sensor echo

long duration;
int distCm, distInch;

void setup() {
  Serial.begin(9600);
  /* Set up for pins */
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distCm = duration * 0.034/2;
  distInch = duration * 0.0133/2;
//  
//  Serial.print("Distance in cm: ");
//  Serial.println(distCm);
//
//  Serial.print("Distance in inches: ");
  Serial.println(distInch);

  delay(1000);
}

