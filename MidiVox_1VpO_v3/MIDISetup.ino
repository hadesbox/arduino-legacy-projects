//MIDI Setup

#include "MIDISetup.h"
#include "Midi.h"

int PBBuf = 64;
int duty = 0;
int dutyCount = 0;
uint16_t noteVal;
uint16_t noteOut;
int noteBuf[5]={
  255,255,255,255,255};  // set up keyboard buffer for 5 notes

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class MyMidi :
public Midi {
public:
  // Need this to compile; it just hands things off to the Midi class.
  MyMidi(HardwareSerial &s) : 
  Midi(s) {
  }
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  void handleNoteOn(unsigned int channel, unsigned int note, unsigned int velocity)
  {
    if (velocity && note)           
    {
      note_insert(note);
    }
    else if (!velocity)  // Noteon with 0 velocity counts as a note off message
    {
      note_delete(note);
    }
  }
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  void handleNoteOff(unsigned int channel, unsigned int note, unsigned int velocity)
  {
    note_delete(note);
  }

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  void handlePitchChange(unsigned int pitch){      // Pitch Bend data
    //nothing yet
  }

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  void handleControlChange(unsigned int channel, unsigned int controller, unsigned int value)
  {
  }
};

MyMidi midi(Serial);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////PLAYNOTE///////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void playNote()  // play the note
{ 
  
  if (noteBuf[0]!=255)
  {
    PORTD |= (1<<7);                 // DATA LED ON
    PORTD |= (1<<5);                 // V-Trigger Gate HIGH
    PORTD &= ~(1<<4);                // S-Trigger Gate LOW
    
    noteVal = (noteBuf[0]);
  }
  else
  {   
    PORTD &= ~(1<<7);                //DATA LED OFF
    PORTD &= ~(1<<5);                // V-Trigger Gate LOW
    PORTD |= (1<<4);                 // S-Trigger Gate HIGH
    
    //noteVal = 0;   //kill the V-out if no note is on  
  }
  
  noteVal -= 33; 
  noteOut = noteVal * 58;            //Convert to DAC CV
  
  dacOut(noteOut);                  //tell the hardware section to get busy sending noteOut to DAC

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// insertion note into note_buff
void note_insert(byte note)
{
  for(int nloop=4; nloop>0; nloop--) {
    noteBuf[nloop]=noteBuf[nloop-1];              //move each note in the buffer up one position
  }
  noteBuf[0]=note;                                //place our new note in the beginning of the note buffer
  playNote();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// delete note into note_buff.  It should first find the notes position and then delete it.
void note_delete(byte note)
{
  int nloop, pos;
  for (nloop=0; nloop<=4;nloop++)
  {  
    if (noteBuf[nloop] == note) {
      pos=nloop;
      break;  
    }
  }
  for(nloop=pos; nloop<=4;nloop++) {
    noteBuf[nloop]=noteBuf[nloop+1];
  }
  noteBuf[nloop-1]=255;
  playNote();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MIDI_Setup(){
  midi.begin(1);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MIDI_Read(){
  midi.poll();

}
