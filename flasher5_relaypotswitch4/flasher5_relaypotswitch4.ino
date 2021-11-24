// light flasher
#include "CycleButton.h" // library for button cycling to switch case switcher

// constants won't change. Used here to set a pin number:
const int ledPin =  LED_BUILTIN;// the number of the LED pin
const int relay8 = 7;
const int relay7 = 8;
const int relay6 = 3;
const int relay5 = 6;
const int relay4 = 5;
const int relay3 = 4;
const int relay2 = 2;
const int relay1 = 9;

const int speedPot = A0;
const int switcher = 10;

// Variables will change:
int ledState = LOW;             // ledState used to set the LED
int mode = 0;                   // intial state of button

// Generally, you should use "unsigned long" for variables that hold time
unsigned long previousMillis = 0;        // will store last time LED was updated

//basic speed at start is .5 sec or 120 bpm
int long interval = 1000;           // interval at which to blink (milliseconds)
int long int_min = 50;              // minimum interval 
int long int_max = 2000;           // max interval
int rate = 1025;  //start at mid

int pot_min = 40;                   // tweak pot min for actual min not 0
int pot_max = 1020;                 // tweak pot max for actual max not 1023
int analogPot = 500;  //start at mid
int pStep = 0;

int modenum = 6;



// The button will automatically configure the button pin.
// The second number is the maximum value of the counter.
CycleButton button(switcher, modenum);



void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
  pinMode(relay8, OUTPUT);
  pinMode(relay7, OUTPUT);
  pinMode(relay6, OUTPUT);
  pinMode(relay5, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay1, OUTPUT);
  
  

  // set the read pins:
  pinMode (speedPot, INPUT);
}

void loop() {
 
 
 mode = button.getValue(); // During each loop, the number of times the button is pressed is retrieved

  // get and map pot value to rate and interval
  analogPot = analogRead(speedPot);// get pot value
  rate = map(analogPot, pot_min, pot_max, int_min, int_max);// map pot value to range for interval
  interval = rate; // assign mapped rate to interval for timing

  while (mode == 0) {
    Serial.println((String)"mode:" + mode);
    AllHigh();
    mode = button.getValue();
  }
  while (mode == 1) {
    Serial.println((String)"mode:" + mode);
    AllLow();
    mode = button.getValue();
  }
  while (mode == 2) {
    

  analogPot = analogRead(speedPot);// get pot value
  rate = map(analogPot, pot_min, pot_max, int_min, int_max);// map pot value to range for interval
  interval = rate; // assign mapped rate to interval for timing
  mode = button.getValue();
  
  int pattern[2][8] = {{0,1,0,1,0,1,0,1},
                       {1,0,1,0,1,0,1,0}};
  int len = 2;

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    RelayWrite(pattern, pStep);
    //print rate down here so its not a billion times per second
 
    pStep +=1;
    if (pStep == len){ pStep = 0;}
    }
  }
    while (mode == 3) {
    

  analogPot = analogRead(speedPot);// get pot value
  rate = map(analogPot, pot_min, pot_max, int_min, int_max);// map pot value to range for interval
  interval = rate; // assign mapped rate to interval for timing
  mode = button.getValue();
  
  int pattern[2][8] = {{1,1,1,1,0,0,0,0},
                       {0,0,0,0,1,1,1,1}};
  int len = 2;

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    RelayWrite(pattern, pStep);
    //print rate down here so its not a billion times per second
 
    pStep +=1;
    if (pStep == len){ pStep = 0;}
    }
  }
      while (mode == 4) {
    

  analogPot = analogRead(speedPot);// get pot value
  rate = map(analogPot, pot_min, pot_max, int_min, int_max);// map pot value to range for interval
  interval = rate; // assign mapped rate to interval for timing
  mode = button.getValue();
  
  int pattern[4][8] = {{1,0,0,0,0,0,0,1},
                        {0,1,0,0,0,0,1,0},
                        {0,0,1,0,0,1,0,0},
                       {0,0,0,1,1,0,0,0}};
  int len = 4;

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    RelayWrite(pattern, pStep);
    //print rate down here so its not a billion times per second
 
    pStep +=1;
    if (pStep == len){ pStep = 0;}
    }
  }
        while (mode == 5) {
    

  analogPot = analogRead(speedPot);// get pot value
  rate = map(analogPot, pot_min, pot_max, int_min, int_max);// map pot value to range for interval
  interval = rate; // assign mapped rate to interval for timing
  mode = button.getValue();
  
  int pattern[8][8] = {{1,0,0,0,0,0,0,0},
                        {0,1,0,0,0,0,0,0},
                        {0,0,1,0,0,0,0,0},
                        {0,0,0,1,0,0,0,0},
                        {0,0,0,0,1,0,0,0},
                        {0,0,0,0,0,1,0,0},
                        {0,0,0,0,0,0,1,0},
                       {0,0,0,0,0,0,0,1}};
  int len = 8;

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    RelayWrite(pattern, pStep);
    //print rate down here so its not a billion times per second
 
    pStep +=1;
    if (pStep == len){ pStep = 0;}
    }
  }
    while (mode == 3) {
    

  analogPot = analogRead(speedPot);// get pot value
  rate = map(analogPot, pot_min, pot_max, int_min, int_max);// map pot value to range for interval
  interval = rate; // assign mapped rate to interval for timing
  mode = button.getValue();
  
  int pattern[2][8] = {{1,1,1,1,0,0,0,0},
                       {0,0,0,0,1,1,1,1}};
  int len = 2;

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    RelayWrite(pattern, pStep);
    //print rate down here so its not a billion times per second
 
    pStep +=1;
    if (pStep == len){ pStep = 0;}
    }
  }
      while (mode == 6) {
    

  analogPot = analogRead(speedPot);// get pot value
  rate = map(analogPot, pot_min, pot_max, int_min, int_max);// map pot value to range for interval
  interval = rate; // assign mapped rate to interval for timing
  mode = button.getValue();
  
  int pattern[8][8] = {{0,0,1,1,1,1,1,1},
                        {1,0,0,1,1,1,1,1},
                        {1,1,0,0,1,1,1,1},
                        {1,1,1,0,0,1,1,1},
                        {1,1,1,1,0,0,1,1},
                        {1,1,1,1,1,0,0,1},
                        {1,1,1,1,1,1,0,0},
                       {0,1,1,1,1,1,1,0}};
  int len = 8;

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    RelayWrite(pattern, pStep);
    //print rate down here so its not a billion times per second
 
    pStep +=1;
    if (pStep == len){ pStep = 0;}
    }
  }  
    
    
    
}
void patternWrite( byte patterns[], int len, int rate){
  for(int i = 0; i < len; ++i){
    
  }
}

void RelayWrite( int pins[][8], int row)
{
  
  digitalWrite(relay8, pins[row][7]);
  Serial.println((String)"relay8: " + pins[row][7]);
  digitalWrite(relay7, pins[row][6]);
  Serial.println((String)"relay:7 " + pins[row][6]);
  digitalWrite(relay6, pins[row][5]);
  Serial.println((String)"relay6: " + pins[row][5]);
  digitalWrite(relay5, pins[row][4]);
  Serial.println((String)"relay5: " + pins[row][4]);
  digitalWrite(relay4, pins[row][3]);
  Serial.println((String)"relay4: " + pins[row][3]);
  digitalWrite(relay3, pins[row][2]);
  Serial.println((String)"relay3: " + pins[row][2]);
  digitalWrite(relay2, pins[row][1]);
  Serial.println((String)"relay2: " + pins[row][1]);
  digitalWrite(relay1, pins[row][0]);
  Serial.println((String)"relay1: " + pins[row][0]); 
}



void AllHigh()
{
  digitalWrite(relay8, HIGH);
  digitalWrite(relay7, HIGH);
  digitalWrite(relay6, HIGH);
  digitalWrite(relay5, HIGH);
  digitalWrite(relay4, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay1, HIGH);  
}
void AllLow()
{
  digitalWrite(relay8, LOW);
  digitalWrite(relay7, LOW);
  digitalWrite(relay6, LOW);
  digitalWrite(relay5, LOW);
  digitalWrite(relay4, LOW);
  digitalWrite(relay3, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(relay1, LOW); 
}
