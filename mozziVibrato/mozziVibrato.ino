/*  Example playing a sinewave with vibrato,
    using Mozzi sonification library.
  
    Demonstrates simple FM using phase modulation.
  
    Circuit: Audio output on digital pin 9 (on a Uno or similar), or 
    check the README or http://sensorium.github.com/Mozzi/
  
    Mozzi help/discussion/announcements:
    https://groups.google.com/forum/#!forum/mozzi-users
  
    Tim Barrass 2012.
    This example code is in the public domain.
*/

#include <MozziGuts.h>
#include <Oscil.h>
#include <tables/cos2048_int8.h> // table for Oscils to play
#include <mozzi_midi.h> // for mtof

#define CONTROL_RATE 64 // powers of 2 please

Oscil<COS2048_NUM_CELLS, AUDIO_RATE> aCos(COS2048_DATA);
Oscil<COS2048_NUM_CELLS, AUDIO_RATE> aVibrato(COS2048_DATA);

const long intensity = 300;

int contador=0; //contador que va de 0 a 1000

void setup(){
  startMozzi(CONTROL_RATE);
  aCos.setFreq(mtof(84.f));
  aVibrato.setFreq(15.f);
}

void loop(){
  audioHook();
}

void updateControl(){
       contador = analogRead(0);   // read the input pin
}

int updateAudio(){

    long vibrato = ((contador * intensity) / 1000) * aVibrato.next();
    return aCos.phMod(vibrato); // phase modulation to modulate frequency
}
