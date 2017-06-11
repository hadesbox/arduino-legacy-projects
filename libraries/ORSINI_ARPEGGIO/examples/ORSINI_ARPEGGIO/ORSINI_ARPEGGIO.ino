#include <Part.h>
#include <MIDI.h>

int led = 7;
byte selected_part=  0;
byte shiftOn=0;

bool changeAnalogBool[6]={false , false , false , false , false , false };// changed
int changeAnalogVal[6]={analogRead(0), analogRead(2), analogRead(3), analogRead(4), analogRead(5), analogRead(6) };//lastval, changed


//Part[3] parts={part(5), part(5), part(5)};


Part part;

// the setup routine runs once when you press reset:
void setup() { 
	setupMidi();  
	part.init(1);
	part.myPart=0;
	
  pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {

	MIDI.read();
	control();
	clockIn(8);
 	
 // wait for a second
  //trace(56, map(freeRam(), 0,2048,0,127));
 //   Serial.println(freeRam());
}

int freeRam () {
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}

