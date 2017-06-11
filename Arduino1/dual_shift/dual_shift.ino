
//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595
int dataPin = 11;

//holders for infromation you're going to pass to shifting function
byte dataRED;
byte dataGREEN;

void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {   

  digitalWrite(latchPin, 0);

  shiftOut(dataPin, clockPin, MSBFIRST, 1);  
  digitalWrite(latchPin, 1);
  delay(1000);


  digitalWrite(latchPin, 0);

  shiftOut(dataPin, clockPin, MSBFIRST, 4);  
  digitalWrite(latchPin, 1);
  delay(1000);

}







