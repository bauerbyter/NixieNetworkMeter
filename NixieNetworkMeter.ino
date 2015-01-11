
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
  0,0,0,0};//LSB to MSB
int upRightPins [] = {
  0,0,0,0};
int downLeftPins [] = {
  0,0,0,0};
int downRightPins [] = {
  0,0,0,0};

const int downLedPin = 0;
const int upLedPin = 0;


void setup() {
  Serial.begin(9600); 
  
  setupBCDPins(upLeftPins);
  setupBCDPins(upRightPins);
  setupBCDPins(downLeftPins);
  setupBCDPins(downRightPins);
}

void setupBCDPins(int bcdPins[4]){
  for(int i=0; i<4; i++){
    pinMode(bcdPins[i], OUTPUT);
    digitalWrite(i, LOW);
  }  
}

void loop() {

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
  
  digitalWrite(bcdPinsLeft[0], HIGH && (left & B00001000));
  digitalWrite(bcdPinsLeft[1], HIGH && (left & B00000100));
  digitalWrite(bcdPinsLeft[2], HIGH && (left & B00000010));
  digitalWrite(bcdPinsLeft[3], HIGH && (left & B00000001));
  
  digitalWrite(bcdPinsRight[0], HIGH && (right & B00001000));
  digitalWrite(bcdPinsRight[1], HIGH && (right & B00000100));
  digitalWrite(bcdPinsRight[2], HIGH && (right & B00000010));
  digitalWrite(bcdPinsRight[3], HIGH && (right & B00000001));
  
  Serial.println(bcdPinsLeft[3] + " " + bcdPinsLeft[2]+ " " + bcdPinsLeft[1]+ " " + bcdPinsLeft[0]);
  Serial.println(bcdPinsRight[3] + " " + bcdPinsRight[2]+ " " + bcdPinsRight[1]+ " " + bcdPinsRight[0]);
  
  
}



