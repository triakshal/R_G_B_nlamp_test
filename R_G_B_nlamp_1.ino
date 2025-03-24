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
  delay(2);
  greensens = analogRead(greensenspos);
  delay(2);
  bluesens = analogRead(bluesenspos);

  int invred = (redsens >= 375) ? 0 : map(redsens, 0, 375, 255, 0);
  int invgreen = (greensens >= 375) ? 0 : map(greensens, 0, 375, 255, 0);
  int invblue = (bluesens >= 375) ? 0 : map(bluesens, 0, 375, 255, 0);
  
  Serial.print("redsens: ");
  Serial.println(redsens);
  Serial.print("invred: ");
  Serial.println(invred);
  

  analogWrite(redpos, invred);
  analogWrite(bluepos, invblue);
  analogWrite(greenpos, invgreen/1.5);

  delay(10);
}
