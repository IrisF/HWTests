int dataPin1 = 13;
int latchPin1 = 12;
int clockPin1 = 11;
int dataPin2 = 10;
int latchPin2 = 9;
int clockPin2 = 8;
int dataPin3 = 7;
int latchPin3 = 6;
int clockPin3 = 5;
int dataPin4 = 4;
int latchPin4 = 3;
int clockPin4 = 2;
int dataPin5 = 14;
int latchPin5 = 15;
int clockPin5 = 16;
int dataPin6 = 17;
int latchPin6 = 18;
int clockPin6 = 19;
int num0 = 0b00111111;
int num1 = 0b00000110;
int num2 = 0b01011011;
int num3 = 0b01001111;
int num4 = 0b01100110;
int num5 = 0b01101101;
int num6 = 0b01111101;
int num7 = 0b00000111;
int num8 = 0b01111111;
int num9 = 0b01101111;
int dot = 0b10000000;
int out = 0b00000000;
String user = "x";
String timeShown = "1 Sek";
int counter = 0;
int pos1[] = {num7,num4,num2,num0,num0,num7,num9,num3,num4,num8};
int pos2[] = {num9,num8,num2,num2,num3,num6,num9,num6,num7,num0};
int pos3[] = {num3,num3,num7,num3,num9,num2,num9,num5,num1,num4};
int pos4[] = {num8,num9,num3,num9,num8,num7,num1,num5,num3,num6};
int pos5[] = {num0,num0,num7,num9,num6,num0,num7,num8,num8,num0};
int pos6[] = {num2,num5,num9,num7,num5,num3,num2,num1,num4,num3};



void setup() {
  Serial.begin(9600);
  Serial.println("Nutzer: "+user + ", Zeit: " + timeShown);
  setupLatchPins();
  setupDataPins();
  setupClockPins();
  showBlank();
  delay(5000);
}

void setupLatchPins() {
  pinMode(latchPin1, OUTPUT);
  pinMode(latchPin2, OUTPUT);
  pinMode(latchPin3, OUTPUT);
  pinMode(latchPin4, OUTPUT);
  pinMode(latchPin5, OUTPUT);
  pinMode(latchPin6, OUTPUT);
}
void setupDataPins() {
  pinMode(dataPin1, OUTPUT);
  pinMode(dataPin2, OUTPUT);
  pinMode(dataPin3, OUTPUT);
  pinMode(dataPin4, OUTPUT);
  pinMode(dataPin5, OUTPUT);
  pinMode(dataPin6, OUTPUT);
}
void setupClockPins() {
  pinMode(clockPin1, OUTPUT);
  pinMode(clockPin2, OUTPUT);
  pinMode(clockPin3, OUTPUT);
  pinMode(clockPin4, OUTPUT);
  pinMode(clockPin5, OUTPUT);
  pinMode(clockPin6, OUTPUT);
}


void loop() {
  if(counter<10){
  showNum();
  delay(1000);
  showBlank();
  delay(5000);
  counter++;
  }
}

void showNum() {
  setLatchesLow();
  setShiftOut();
  setLatchesHigh();
}

void showBlank() {
  setLatchesLow();
  shiftOutBlank();
  setLatchesHigh();
}

void shiftOutBlank() {
  shiftOut(dataPin1, clockPin1, MSBFIRST, out);
  shiftOut(dataPin2, clockPin2, MSBFIRST, out);
  shiftOut(dataPin3, clockPin3, MSBFIRST, out);
  shiftOut(dataPin4, clockPin4, MSBFIRST, out);
  shiftOut(dataPin5, clockPin5, MSBFIRST, out);
  shiftOut(dataPin6, clockPin6, MSBFIRST, out);
}

void setLatchesLow() {
  digitalWrite(latchPin1, LOW);
  digitalWrite(latchPin2, LOW);
  digitalWrite(latchPin3, LOW);
  digitalWrite(latchPin4, LOW);
  digitalWrite(latchPin5, LOW);
  digitalWrite(latchPin6, LOW);
}

void setLatchesHigh() {
  digitalWrite(latchPin1, HIGH);
  digitalWrite(latchPin2, HIGH);
  digitalWrite(latchPin3, HIGH);
  digitalWrite(latchPin4, HIGH);
  digitalWrite(latchPin5, HIGH);
  digitalWrite(latchPin6, HIGH);
}

void setShiftOut() {
  shiftOut(dataPin1, clockPin1, MSBFIRST, pos1[counter]);
  shiftOut(dataPin2, clockPin2, MSBFIRST, pos2[counter]);
  shiftOut(dataPin3, clockPin3, MSBFIRST, pos3[counter]);
  shiftOut(dataPin4, clockPin4, MSBFIRST, pos4[counter]);
  shiftOut(dataPin5, clockPin5, MSBFIRST, pos5[counter]);
  shiftOut(dataPin6, clockPin6, MSBFIRST, pos6[counter]);
}


