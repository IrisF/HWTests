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
int nextNumPin = 22;
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
int counter = 0;
int blinkTime1 = 500;
int blinkTime2 = 100;
int blinkTime3 = 20;
int iteration = 1;
int group = 1;
int startTime = 0;
int elapsedTime = 0;
boolean userDone = false;
int nextNum[6];
String nums[] = {"582056", "473437", "509287", "702895", "374473", "901856", "285639", "774373", "895842", "589602", "892526", "437447", "925876", "733474", "820195", "054285", "958122", "093562", "347443", "182695", "743377", "904658", "737344", "528029", "437343", "235698", "506288", "804996", "652729", "654678", "737344", "821566", "255896", "374437", "744347", "091558", "225789", "109256", "347433", "743374", "965082", "743773", "690282", "428900", "065523", "825210", "734774", "856223", "3.77433", "29.8065", "5462.08", "0.96532", "4.47373", "05.2526", "658.207", "7433.74", "9.52681", "1.29685", "28.7569", "3743.37", "47.7437", "5629.05", "780.269", "5683.20", "525.296", "34773.4", "743.473", "50.3256", "51895.8", "43.7743", "295.168", "86852.4", "734.377", "07.5698", "5168.09", "1.65098", "59.8904", "026.835", "72680.2", "26.5998", "743.477", "562.188", "4377.34", "5.36820", "3.77347", "50.2892", "9615.86", "73747.3", "7334.74", "55892.6", "3569.29", "73.7344", "824.569", "582.026", "73.3747", "5284.06"};


void setup() {
  Serial.begin(9600);
  setupLatchPins();
  setupDataPins();
  setupClockPins();
  setupControlPins();
  showBlank();
}

void setupControlPins() {
  pinMode(nextNumPin, INPUT);
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
  if (counter < 96) {
    checkForNextNum();
  }
}

void checkForNextNum() {
  int buttonState = digitalRead(nextNumPin);
  if (buttonState == HIGH) {
    showBlank();
    delay(500);
    calcVersionAndShowNum();
  }
}

void calcVersionAndShowNum() {
  if (group == 1) {
    calcAndShowUser(0);
  }
  if (group == 2) {
    calcAndShowUser(48);
  }
}

void calcAndShowUser(int startPos) {
  if(group ==2&& iteration==1){
    counter=startPos;
    iteration++;
  }
  if (counter < 48) {
    retrieveNumWithoutDot();
    if (counter < 24) {
      showNumPermanentaly(nextNum);
    } else {
      showNumForOneSecond(nextNum);
    }
  } else {
    retrieveNumWithDot();
    if (counter < 72) {
      showNumPermanentaly(nextNum);
    } else {
      showNumForOneSecond(nextNum);
    }
  }
  if(group==2&&counter==96){
    counter=0;
  }
  if(group==2&&counter==startPos&&iteration==2){
    counter=97;
  }

}
void retrieveNumWithDot() {
  String num = nums[counter];
  int numToBeShown[6];// = {};
  int arrayPos = 0;
  for (int i = 6; i >=0; i--) {
    if (num.charAt(i) != '.') {
      if (num.charAt(i + 1) == '.') {
        int n = transferNum(num.charAt(i));
        numToBeShown[arrayPos] = n + dot;
        arrayPos++;
      } else {
        int n = transferNum(num.charAt(i));
        numToBeShown[arrayPos] = n;
        arrayPos++;
      }
    }
  }
  fillNextNumArray(numToBeShown);
}

void retrieveNumWithoutDot() {
  String num = nums[counter];
  int numToBeShown[] = {transferNum(num.charAt(5)), transferNum(num.charAt(4)), transferNum(num.charAt(3)), transferNum(num.charAt(2)), transferNum(num.charAt(1)), transferNum(num.charAt(0))};
  fillNextNumArray(numToBeShown);
}

void fillNextNumArray(int numToBeShown[]){
  for(int i = 0; i< 6;i++){
    nextNum[i]= numToBeShown[i];
  }
}

int transferNum(char numToTransfer) {
  switch (numToTransfer) {
    case '0':
      return num0;
    case '1':
      return num1;
    case '2':
      return num2;
    case '3':
      return num3;
    case '4':
      return num4;
    case '5':
      return num5;
    case '6':
      return num6;
    case '7':
      return num7;
    case '8':
      return num8;
    case '9':
      return num9;
    default:
      break;
  }
}

void showNumPermanentaly(int num[]) {
  showNum(num);
}

void showNumForOneSecond(int num[]) {
  showNum(num);
  delay(1500);
  showBlank();
}

void showNum(int num[]) {
  setLatchesLow();
  setShiftOut(num);
  setLatchesHigh();
  Serial.println(nums[counter]);
  counter++;
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

void setShiftOut(int num[]) {
  shiftOut(dataPin1, clockPin1, MSBFIRST, num[0]);
  shiftOut(dataPin2, clockPin2, MSBFIRST, num[1]);
  shiftOut(dataPin3, clockPin3, MSBFIRST, num[2]);
  shiftOut(dataPin4, clockPin4, MSBFIRST, num[3]);
  shiftOut(dataPin5, clockPin5, MSBFIRST, num[4]);
  shiftOut(dataPin6, clockPin6, MSBFIRST, num[5]);
}


