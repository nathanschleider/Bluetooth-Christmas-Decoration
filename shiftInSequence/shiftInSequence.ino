// Define Connections

const int latchPin = 10;
const int clockPin = 11;
const int dataPin = 12;
const int delayTime = 150;
uint16_t numberToDisplay = 0;
int indexRaise = 0;
int reg1 = 0;
int reg2 = 0;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 
  for (int i = 0; i < 16; i++){
    numberToDisplay = intPower(2,i);
    Serial.println(numberToDisplay);
    if (numberToDisplay > 256){
      reg2 = 0;
      reg1 = numberToDisplay/512;
    }
    else {
      reg2 = numberToDisplay;
      reg1 = 0;
    }
	Serial.println("reg1");
    Serial.println(reg1);
    Serial.println("reg2");
    Serial.println(reg2);
    digitalWrite(latchPin, LOW);

    shiftOut(dataPin, clockPin, MSBFIRST, reg1);
    shiftOut(dataPin, clockPin, MSBFIRST, reg2);

    digitalWrite(latchPin, HIGH);
    if (numberToDisplay != 256){
      delay(delayTime);
    }
  }
  for (int i = 15; i >= 1; i--){
    numberToDisplay = intPower(2,i);
    Serial.println(numberToDisplay);
    if (numberToDisplay > 256){
      reg2 = 0;
      reg1 = numberToDisplay/512;
    }
    else {
      reg2 = numberToDisplay;
      reg1 = 0;
    }
	Serial.println("reg1");
    Serial.println(reg1);
    Serial.println("reg2");
    Serial.println(reg2);
    digitalWrite(latchPin, LOW);

    shiftOut(dataPin, clockPin, MSBFIRST, reg1);
    shiftOut(dataPin, clockPin, MSBFIRST, reg2);

    digitalWrite(latchPin, HIGH);
    if (numberToDisplay != 1){
      delay(delayTime);
    }
  }
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