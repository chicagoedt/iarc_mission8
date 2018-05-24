
#define frontTrig 1
#define frontEcho 2
#define backTrig 3
#define backEcho 4
#define leftTrig 5
#define leftEcho 6
#define rightTrig 7
#define rightEcho 8

#define limit 80

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
  //SETUP back
  //SETUP left
  //SETUP right

/* 4 sensors detect */
 if(front < limit && back < limit && left < limit && right < limit)
    Serial.println("E");

/* Three sensors detect */
  else if(back < limit && left < limit && right < limit)
    Serial.println("F");
  else if(front < limit && left < limit && right < limit)
    Serial.println("B");
  else if(front < limit && back < limit && right < limit)
    Serial.println("L");
  else if(front < limit && back < limit && left < limit)
    Serial.println("R");
    
/* Two sensors detect */
  else if(front < limit && back < limit)
    Serial.println("LR");
  else if(front < limit && left < limit)
    Serial.println("BR");
  else if(front < limit && right < limit)
    Serial.println("BL");
  else if(back < limit && left < limit)
    Serial.println("FR");
  else if(back < limit && right < limit)
    Serial.println("FL");
  else if(left < limit && right < limit)
    Serial.println("FB");
  
    
/* One sensor detect */
  else if(front < limit)
    Serial.println("BLR");
  else if(back < limit)
    Serial.println("FLR");
  else if(left < limit)
    Serial.println("FBR");
  else if(right < limit)
    Serial.println("FBL");
    
/* No possible collisions detected, continue */
  else
    Serial.println("C"); 
  
}
