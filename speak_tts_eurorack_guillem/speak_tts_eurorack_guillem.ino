// SpeakJetTTS Eurorack Module
// code by vonkhades
// pcb design gb

//set up a SoftwareSerial port for Speakjet Shield
#include <SoftwareSerial.h>

//digital pin for TX TTS256
#define rxPin 5
//digital pin for RX TTS256
#define txPin 6

//D7-B half/ Busy
#define busyPin 7
//Trigger 1 pin
  #define pinTrigger1 8
//Trigger 2 pin
#define pinTrigger2 9
//Trigger 3 pin
#define pinTrigger3 10
//Trigger 4 pin
#define pinTrigger4 11
//Trigger 5 pin
#define pinTrigger5 12


//pin for sound potentiometer
#define pinSoundPot 0
//pin for sound CV
#define pinSoundCV 1
//pin for pitch potentiometer
#define pinPitchPot 2
//pin for pitch CV 
#define pinPitchCV 3
//pin for speed potentiometer
#define pinSpeedPot 4
//pin for speed CV
#define pinSpeedCV 5

SoftwareSerial sjSerial = SoftwareSerial(rxPin, txPin);
int is_busy = 0;

int trigger1 = LOW;
int lastTrigger1State = LOW;
int trigger2 = LOW;
int lastTrigger2State = LOW;
int trigger3 = LOW;
int lastTrigger3State = LOW;

int valSound = 0; 

#define len1 7
String arr1[len1] = {"freak", "geek", "nerd", "jerk", "fuck", "shit", "rat"};
//#define len2 10
//String arr2[len2] = {"satanicocatolico", "catolicosatanico", "opuspus", "mierda de pais", "mierda", "pais", "fascistas", "retrasados", "culo", "pis"};
#define len2 7
String arr2[len2] = {"a", "b", "d", "e", "h", "j", "z"};
#define len3 10
int arr3[len3] = {200, 201, 202, 203, 204, 205, 206, 207, 208, 209};


void setup(){
    // initialize the serial communications with the SpeakJet-TTS256
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  
  pinMode(busyPin, INPUT);
  pinMode(pinTrigger1, INPUT);
  pinMode(pinTrigger2, INPUT);
  pinMode(pinTrigger3, INPUT);
  pinMode(pinTrigger4, INPUT);
  pinMode(pinTrigger5, INPUT);
  
  pinMode(pinSoundPot, INPUT);
  pinMode(pinSoundCV, INPUT);
  pinMode(pinPitchPot, INPUT);
  pinMode(pinPitchCV, INPUT);
  pinMode(pinSpeedPot, INPUT);
  pinMode(pinSpeedCV, INPUT);
  
  sjSerial.begin(9600);// set the data rate for the SoftwareSerial port
  delay(1000); // wait a second for the Arduino resets to finish (speaks "ready")
}

void loop()
{
  
  is_busy = digitalRead(busyPin);   // read the busy pin, to check if speak jet is speaking or not
  
  if(true){ //if is not busy, then we can reproduce a word!
  
    trigger1 = digitalRead(pinTrigger1);
    trigger2 = digitalRead(pinTrigger2);
    trigger3 = digitalRead(pinTrigger2);
    
    if(trigger1 != lastTrigger1State && trigger1 == HIGH){
      valSound = analogRead(pinSoundPot) + analogRead(pinSoundCV);
      if(valSound > 1023){
        valSound=1023;
      }
      valSound = map(valSound, 0, 1023, 0, len1);
      sjSerial.println(arr1[valSound]);
    }
    else if(trigger2 != lastTrigger2State && trigger2 == HIGH){
      valSound = analogRead(pinSoundPot) + analogRead(pinSoundCV);
      if(valSound > 1023){
        valSound=1023;
      }
      valSound = map(valSound, 0, 1023, 0, len2);
      sjSerial.println(arr2[valSound]);
    }
    else if(trigger3 != lastTrigger3State && trigger3 == HIGH){
      valSound = analogRead(pinSoundPot) + analogRead(pinSoundCV);
      if(valSound > 1023){
        valSound=1023;
      }
      valSound = map(valSound, 0, 1023, 0, len2);
      sjSerial.print((char)arr3[valSound]);
      sjSerial.println();
    }
       
  }
  
  lastTrigger1State = trigger1;
  lastTrigger2State = trigger2;
  lastTrigger3State = trigger3;
  
}

