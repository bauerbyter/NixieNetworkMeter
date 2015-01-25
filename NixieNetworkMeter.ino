
/*
 *|12345|
 *|67890|
 *
 *1 = Linke Zahl 4.Byte
 *2 = Linke Zahl 1.Byte
 *3 = VCC
 *4 = Rechte Zahl 3.Byte
 *5 = Rechte Zahl 2.Byte
 *6 = Linke Zahl 2.Byte
 *7 = Linke Zahl 3.Byte
 *8 = Blaue LED
 *9 = Rechte Zahl 1.Byte
 *0 = Rechte Zahl 4.Byte
 */

int upLeftPins [] = {
  2,3,4,5};//LSB to MSB
int upRightPins [] = {
  7,9,8,10};
int downLeftPins [] = {
  11,12,14,15};
int downRightPins [] = {
 16,17,18,19};

const int LedPin = 6;


void setup() {
  Serial.begin(9600); 

  setupBCDPins(upLeftPins);
  setupBCDPins(upRightPins);
  setupBCDPins(downLeftPins);
  setupBCDPins(downRightPins);

  pinMode(LedPin, OUTPUT);
  digitalWrite(LedPin, HIGH);
}

void setupBCDPins(int bcdPins[4]){
  for(int i=0; i<4; i++){
    pinMode(bcdPins[i], OUTPUT);
    digitalWrite(bcdPins[i], LOW);
  }  
}

void loop() {
  for(int i = 0; i < 100; i++){
    setNixie(downLeftPins, downRightPins, i);
    setNixie(upLeftPins, upRightPins, i);
    delay(500);
  }
  bla();
}

void bla(){

  digitalWrite(downLeftPins[3], LOW);
  digitalWrite(downLeftPins[2], LOW);
  digitalWrite(downLeftPins[1], LOW);
  digitalWrite(downLeftPins[0], LOW);

  digitalWrite(downRightPins[3], LOW);
  digitalWrite(downRightPins[2], LOW);
  digitalWrite(downRightPins[1], LOW);
  digitalWrite(downRightPins[0], LOW);

}

void setNixie(int bcdPinsLeft[],int bcdPinsRight[], int number) {
  if(number > 99){
    number = 99;
  }
  int left = 0;
  int right = number % 10;
  if(number >= 10){
    left = number / 10;
  }
  Serial.print("left: ");
  Serial.println(left);
  Serial.print("right: ");
  Serial.println(right);

  digitalWrite(bcdPinsLeft[3], HIGH && (left & B00001000));
  digitalWrite(bcdPinsLeft[2], HIGH && (left & B00000100));
  digitalWrite(bcdPinsLeft[1], HIGH && (left & B00000010));
  digitalWrite(bcdPinsLeft[0], HIGH && (left & B00000001));

  digitalWrite(bcdPinsRight[3], HIGH && (right & B00001000));
  digitalWrite(bcdPinsRight[2], HIGH && (right & B00000100));
  digitalWrite(bcdPinsRight[1], HIGH && (right & B00000010));
  digitalWrite(bcdPinsRight[0], HIGH && (right & B00000001));
}








