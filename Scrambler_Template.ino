/*
  Showing number 0-9 on a Common Anode 7-segment LED display
  Displays the numbers 0-9 on the display, with one second inbetween.
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---
    D
  This example code is in the public domain.
 */
 
// Pin 2-8 is connected to the 7 segments of the display.
long randNum; 
int pinA = 6;
int pinB = 7;
int pinC = 8;
int pinD = 9;
int pinE = 10;
int pinF = 11;
int pinG = 12;
int D1 = 2;
int D2 = 3;
int D3 = 4;
int D4 = 5; 

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pins as outputs.
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);   
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT);  

  Serial.begin(9600);
  randomSeed(analogRead(0)); // nothing connected to 0 so read sees noise
}

void loop() {
  //***OPEN THE "NUMBER CODEX FILE" FOR THE CODE FOR EACH NUMBER***
  
  /* Digit Code Example for the Number 1: 
   *  
  randNum = random(0,2); // chooses a random number between 0 inclusive and 2 exclusive.
  if (randNum == 1) {digitalWrite(pinA, HIGH);}
  else {digitalWrite (pinD, LOW);}
  
  randNum = random(0,2); // chooses a random number between 0 inclusive and 2 exclusive.
  if (randNum == 1) {digitalWrite(pinB, HIGH);}
  else {digitalWrite (pinB, LOW);}
  
  randNum = random(0,2); // chooses a random number between 0 inclusive and 2 exclusive.
  if (randNum == 1) {digitalWrite(pinC, HIGH);}
  else {digitalWrite (pinC, LOW);}
  
  randNum = random(0,2); // chooses a random number between 0 inclusive and 2 exclusive.
  if (randNum == 1) {digitalWrite(pinD, HIGH);}
  else {digitalWrite (pinD, LOW);}
  
  randNum = random(0,2); // chooses a random number between 0 inclusive and 2 exclusive.
  if (randNum == 1) {digitalWrite(pinE, HIGH);}
  else {digitalWrite (pinE, LOW);}
  
  randNum = random(0,2); // chooses a random number between 0 inclusive and 2 exclusive.
  if (randNum == 1) {digitalWrite(pinF, HIGH);}
  else {digitalWrite (pinF, LOW);} 
     
  digitalWrite(pinG, LOW);   
  delay(1000);               // wait for a second
   */

  // Number will be displayed as the First digit:
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
  
  // Insert Code for First Digit Below: 

  //----------------------------------------------------------------------------------------
  
  // Number will be displayed as the Second digit:  
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
  
  // Insert Code for the Second Digit Below:  

  //------------------------------------------------------------------------------------------
  
  // Number will be displayed as the Third digit:
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
  digitalWrite(D4, HIGH); 

  // Insert Code for the Third Digit Below: 
  
  //------------------------------------------------------------------------------------------

  // Number will be displayed as the Fourth digit:
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, LOW);

  // Insert Code for the Fourth Digit Below:

  
}
