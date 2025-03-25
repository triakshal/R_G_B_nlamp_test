const int greenpos = 11;
const int redpos = 9;
const int bluepos = 10;

const int buttonPin = 13;

const int redsenspos = A0;


int redsens = 0;
int greensens = 0;
int bluesens = 0;

int light = LOW;
byte button = 0;
byte lastButton = 0;


void setup() {
  Serial.begin(9600);
  
  pinMode(greenpos, OUTPUT);
  pinMode(bluepos, OUTPUT);
  pinMode(redpos, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}



void loop() {

  button = digitalRead(buttonPin);
  if (button == LOW && lastButton == HIGH) { 
    light = !light; 
    delay(10); 
  }
  lastButton = button;


  if (light == LOW){
  redsens = analogRead(redsenspos);
  delay(1);
  greensens = analogRead(redsenspos);
  delay(1);
  bluesens = analogRead(redsenspos);

  int invred = (redsens >= 50) ? 0 : map(redsens, 0, 50, 255, 0);
  int invgreen = (redsens >= 50) ? 0 : map(redsens, 0, 220, 255, 0);
  int invblue = (redsens >= 50) ? 0 : map(redsens, 0, 220, 255, 0);
  

  
  invred = constrain(invred, 1, 255);

  analogWrite(redpos, invred);
  analogWrite(greenpos, invred);
  analogWrite(bluepos, invred);

 // delay(1); 
  }

  else{
    analogWrite(redpos, LOW);
    analogWrite(greenpos, LOW);
    analogWrite(bluepos, LOW);
  }
}

