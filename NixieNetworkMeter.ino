
/*
* ______
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


const int downLedPin = 0;
const int upLedPin = 0;


void setup() {
  for(int i=2; i<11; i++){
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }  
}

void loop() {
  //setNixie(downLeftNixie, 0);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW);
  digitalWrite(5, LOW); 
  
  digitalWrite(6, LOW);
  digitalWrite(7, LOW); 
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH); 
  
  digitalWrite(10, HIGH); 
}

/*void setNixie(int[] bcdPins, int number) {
  if(number > 10){
    number = 10;
  }
  digitalWrite(bcdPins[0], );
  

}*/

