// Define Connections

const int latchPin = 10;
const int clockPin = 11;
const int dataPin = 12;
const int delayTime = 150;
int numberToDisplay = 0;
int indexRaise = 0;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  indexRaise = random(0,16);
  Serial.println(indexRaise);
  numberToDisplay = intPower(2,indexRaise);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, numberToDisplay);
  digitalWrite(latchPin, HIGH);
  delay(delayTime);
  //numberToDisplay = 1;
  
  // for (int numberToDisplay = 1; numberToDisplay < 256; numberToDisplay=numberToDisplay*2){
  //   Serial.println(numberToDisplay);

  //   digitalWrite(latchPin, LOW);

  //   shiftOut(dataPin, clockPin, MSBFIRST, numberToDisplay);

  //   digitalWrite(latchPin, HIGH);
  //   if (numberToDisplay != 128){
  //     delay(delayTime);
  //   }
  // }
  // for (int numberToDisplay = 128; numberToDisplay >= 1; numberToDisplay=numberToDisplay/2){
  //   Serial.println(numberToDisplay);

  //   digitalWrite(latchPin, LOW);

  //   shiftOut(dataPin, clockPin, MSBFIRST, numberToDisplay);

  //   digitalWrite(latchPin, HIGH);
  //   if (numberToDisplay != 1){
  //     delay(delayTime);
  //   }
  // }
}

int intPower (int base, int power) {
  if (power == 0){
    return 1;
  }
  int result = 1;
  for (int i = 0; i < power; i++){
     result = result * base;
  }
  return result;
}