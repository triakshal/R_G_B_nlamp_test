const int greenpos = 9;
const int redpos = 10;
const int bluepos = 11;
const int greensenspos = A1;
const int redsenspos = A0;
const int bluesenspos = A2;


int redsens = 0;
int greensens = 0;
int bluesens = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(greenpos, OUTPUT);
  pinMode(bluepos, OUTPUT);
  pinMode(redpos, OUTPUT);
}



void loop() {

  redsens = analogRead(redsenspos);
  delay(1);
  greensens = analogRead(greensenspos);
  delay(1);
  bluesens = analogRead(bluesenspos);

  int invred = (redsens >= 50) ? 0 : map(redsens, 0, 50, 255, 0);
  int invgreen = (redsens >= 50) ? 0 : map(greensens, 0, 220, 255, 0);
  int invblue = (redsens >= 50) ? 0 : map(bluesens, 0, 220, 255, 0);
  

  
  invred = constrain(invred, 1, 255);

  analogWrite(redpos, invred);
  analogWrite(greenpos, invred);
  analogWrite(bluepos, invred);

  delay(5);
}

