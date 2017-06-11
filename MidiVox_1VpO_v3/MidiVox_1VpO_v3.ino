///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MidiVox CV for 1 volt per octave synthesizers version 3 - narbotic.com/midivox
// 2/5/2012 - Collin Cunningham/Narb-Inst
// For use with Arduino 1.0 IDE
//
// HARDWARE WIRING:
// connect MidiVox/Arduino GND to synth GND
// remove 909Ω resistor below MCP4921
// connect MCP4921 (DAC output) to synth CV input
// connect pin 5 to synth Gate input (V-Trigger standard)
// or conect pin 4 to synth Gate (S-Trigger standard)
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void(* resetFunc) (void) = 0;               //declare soft reset function @ address 0

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {

  pinMode(7, OUTPUT);       //set output pin for DATA LED
  pinMode(13, OUTPUT);
  pinMode(6, INPUT);        //set input pin for software reset switch
  pinMode(5, OUTPUT);       //set output pin for V-Trigger Gate
  pinMode(4, OUTPUT);       //set output pin for S-Trigger Gate
  //digitalWrite(7, LOW);     //DATA LED normally low
  digitalWrite(6, HIGH);    //internal pull-up to avoid unwanted resets
  //digitalWrite(5, LOW);     //V-Trigger Gate normally low
  digitalWrite(4, HIGH);    //S-Trigger Gate normally high


  

  MIDI_Setup();             //establish midi callback functions
  Hardware_Setup();         //set up variables + i/o for DAC
  //dacOut(0);                //clear any preexisting DAC output



}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {

  MIDI_Read();

  if ((digitalRead(6)) == LOW) resetFunc();   //trigger soft reset if switch is pressed 

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// all the juicy stuff is over in MIDISetup
/*
void flashLED(){
  digitalWrite(7, HIGH);
  delay(300);
  digitalWrite(7, LOW);
  delay(300);
  digitalWrite(7, HIGH);
  delay(300);
  digitalWrite(7, LOW);
  delay(300);
  digitalWrite(7, HIGH);
  delay(300);
  digitalWrite(7, LOW);
}*/



