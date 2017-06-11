#define VOICE_COUNT 16
byte NOTE_ON[VOICE_COUNT];
byte NOTE_CHAN[VOICE_COUNT];
bool midiIn=false;
unsigned long NOTE_OFF[VOICE_COUNT];
byte globalNote=0;
bool playing = false;
#define CLOCK_DIVIDER 6
int divider=1;
long _clockCounter = 0;
long step = 0;
byte clockInput=2;
boolean tickSent=false;
byte clockInState = LOW ;
long lastClock = millis();
void setupMidi(){
	MIDI.begin();
	MIDI.setHandleClock ( HandleClock );
	MIDI.setHandleStart ( restartSequence );
	MIDI.setHandleNoteOn ( onNoteOn );
	MIDI.setHandleNoteOff ( onNoteOff );


}

void clockIn(int dig){
	
	byte inClock=digitalRead(dig);
	if(inClock == LOW ){
		//clockInState = LOW ;
		//digitalWrite(7, LOW);
		tickSent=false;
	}else{
		
		if(!tickSent){
		HandleClock();
		SendMidiClockTick();
		//digitalWrite(7, HIGH);
		tickSent=true;
		}
		
		//clockInState == HIGH;
	}
	
}

void SendMidiClockTick(){

	MIDI.sendRealTime( Clock );
	
}

void restartSequence(){
	part.step=0;
	part.step=0;
	_clockCounter = 0;
	MIDI.sendRealTime( Start );
}


void midiLoop(){
	playNotes();
	//trace(66, 12 ); 
  	noteKill();
  	if(midiIn){
  	tickClockLed();
  	}
  	//partCheck();
}
void onNoteOn(byte channel, byte note, byte velocity){
	playing=true;
	digitalWrite(7, HIGH);
	globalNote=note;
}
void onNoteOff(byte channel, byte note, byte velocity){
	playing=false;
	digitalWrite(7, LOW);
	globalNote=0;
}

void playNotes(){

/*trace(56, part.mode.MAPPED_ARGS[map(analogRead(2), 0, 1023, 0,12)] ); 
trace(57, map(analogRead(2), 0, 1023, 0,12) ); */
//trace(58, shiftOn ); 

			if ((_clockCounter % (part.mode.clockDivider)) == 0 ) {
					part.step++;
					byte steper= part.step%16;
					byte note=part.LOOP[0][steper];
					byte vel=part.LOOP[2][steper];
					byte duration=part.LOOP[3][steper];
					byte chan=part.channel_select;
		
					// turn the LED on (HIGH is the voltage level)
					playNote(quantize(note, part.octave_select),vel,duration,chan);
					//trace(66, note ); 
					if(steper%16==0){
						//trace(66, note ); 
						part.newSequence();
					}
			}
			
			
   
    
}
//
void noteKill(){
unsigned long time=millis();
for (int i=0;i<VOICE_COUNT;i++){
if (NOTE_ON[i]>0 && NOTE_OFF[i]<time){  // if note value>0 and note off time < time
 
	byte pitch = NOTE_ON[i];
	byte velocity = 0;
	MIDI.sendNoteOff(pitch, velocity, NOTE_CHAN[i]);
	
	NOTE_ON[i]=0; //wipe NOTE_ON entry to signal no active note
}}}

void HandleClock() {
  midiLoop();	
  _clockCounter++;

}

void trace(byte cc, byte val){
	 MIDI.sendControlChange(cc,val,16);
}

void playNote(byte pitch, byte velocity, int duration, byte chan) {
unsigned long time = millis();
// find an empty note slot 
boolean found_slot = false;
for (int i=0;i<VOICE_COUNT;i++){
if (NOTE_ON[i] == 0){
  
  NOTE_ON[i] = pitch;
  NOTE_OFF[i] = time+duration;
 NOTE_CHAN[i] = chan;
  found_slot = true;
  
  break;
}
}

// RED LIGHT SHOWS NOTE BUFFER IS OVERFULL 
if (found_slot == false){
//digitalWrite (7, HIGH);
}
else{
//-  digitalWrite (7, LOW);
MIDI.sendNoteOn(pitch, velocity, chan);
																																												
};
 
  

  
}

void tickClockLed(){
byte div;
if(selected_part==0){
div=part.mode.clockDivider;
if(part.mode_select==0){
 	
 	digitalWrite(led, LOW);   
 
  }else{
  
    digitalWrite(led, HIGH);   
  }

}else{
div=part.mode.clockDivider;
  if(part.mode_select==0){
 	
 	digitalWrite(led, LOW);   
 
  }else{
  
    digitalWrite(led, HIGH);   
  } 
}
  if ((_clockCounter % (div)) == 0) {
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
// trace(10, 123 );
  }

  // reset trigger after number+2 CLOCK_DIVIDER ticks
  if (((_clockCounter+2) % (div)) == 0) {
    // wait for a second
    digitalWrite(led, LOW);   
   // turn the LED off by making the voltage LOW

  }
}
 byte quantize(int note,int octave){
     return octave*12+note; 
 
 }
