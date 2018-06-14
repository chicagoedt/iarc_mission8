
#define frontTrig 2
#define frontEcho 3
#define backTrig 4
#define backEcho 5
#define leftTrig 6
#define leftEcho 7
#define rightTrig 8
#define rightEcho 9

#define limit 5

void setup() {
  Serial.begin(9600);
  pinMode(frontTrig, OUTPUT);
  pinMode(frontEcho, INPUT);
  pinMode(backTrig, OUTPUT);
  pinMode(backEcho, INPUT);
  pinMode(leftTrig, OUTPUT);
  pinMode(leftEcho, INPUT);
  pinMode(rightTrig, OUTPUT);
  pinMode(rightEcho, INPUT);
}

void loop() {
  //SETUP front
  long frontDuration, frontDistance;
  digitalWrite(frontTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(frontTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(frontTrig, LOW);
  frontDuration = pulseIn(frontEcho, HIGH);
  frontDistance = frontDuration * 0.034 / 2;
  
  //SETUP back
  long backDuration, backDistance;
  digitalWrite(backTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(backTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(backTrig, LOW);
  backDuration = pulseIn(backEcho, HIGH);
  backDistance = backDuration * 0.034 / 2;
  
  //SETUP left
  long leftDuration, leftDistance;
  digitalWrite(leftTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(leftTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(leftTrig, LOW);
  leftDuration = pulseIn(leftEcho, HIGH);
  leftDistance = leftDuration * 0.034 / 2;
  
  //SETUP right
  long rightDuration, rightDistance;
  digitalWrite(rightTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(rightTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(rightTrig, LOW);
  rightDuration = pulseIn(rightEcho, HIGH);
  rightDistance = rightDuration * 0.034 / 2;
  
/* 4 sensors detect */
 if(frontDistance < limit && backDistance < limit && leftDistance < limit && rightDistance < limit)
    Serial.println("E");

/* Three sensors detect */
  else if(backDistance < limit && leftDistance < limit && rightDistance < limit)
    Serial.println("F");
  else if(frontDistance < limit && leftDistance < limit && rightDistance < limit)
    Serial.println("B");
  else if(frontDistance < limit && backDistance < limit && rightDistance < limit)
    Serial.println("L");
  else if(frontDistance < limit && backDistance < limit && leftDistance < limit)
    Serial.println("R");
    
/* Two sensors detect */
  else if(frontDistance < limit && backDistance < limit)
    Serial.println("LR");
  else if(frontDistance < limit && leftDistance < limit)
    Serial.println("BR");
  else if(frontDistance < limit && rightDistance < limit)
    Serial.println("BL");
  else if(backDistance < limit && leftDistance < limit)
    Serial.println("FR");
  else if(backDistance < limit && rightDistance < limit)
    Serial.println("FL");
  else if(leftDistance < limit && rightDistance < limit)
    Serial.println("FB");
  
    
/* One sensor detect */
  else if(frontDistance < limit)
    Serial.println("BLR");
  else if(backDistance < limit)
    Serial.println("FLR");
  else if(leftDistance < limit)
    Serial.println("FBR");
  else if(rightDistance < limit)
    Serial.println("FBL");
    
/* No possible collisions detected, continue */
  else
    Serial.println("C"); 
  
}
