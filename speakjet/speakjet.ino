/*
Voice Box Demo Sketch
Written by Ryan Owens
SparkFun Electronics

Uses the Voice Box Shield from SparkFun to send the message "All your base are belong to us" and a series
of robot sounds to the SpeakJet chip on the shield. 

A speaker can be plugged directly into the SPK+ and - pins on the shield.

*/

//Soft serial library used to send serial commands on pin 2 instead of regular serial pin.
#include <SoftwareSerial.h>

// SpeakJet Control Codes
#define aP0 0
#define aP1 1
#define aP2 2
#define aP3 3
#define aP4 4
#define aP5 5
#define aP6 6
#define aFAST 7
#define aSLOW 8
#define aSTR 14
#define aSOFT 15
#define aPIT 22
#define aSPD 21
#define aVOL 20
#define aBND 23
#define aRST 31
#define aREPEAT 26

//Alophones
// SpeakJet speech element codes
#define aIY 128
#define aIH 129
#define aEY 130
#define aEH 131
#define aAY 132
#define aAX 133
#define aUX 134
#define aOH 135
#define aAW 136
#define aOW 137
#define aUH 138
#define aUW 139
#define aMM 140
#define aNE 141
#define aNO 142
#define aNGE 143
#define aNGO 144
#define aLE 145
#define aLO 146
#define aWW 147
#define aRR 148
#define aIYRR 149
#define aEYRR 150
#define aAXRR 151
#define aAWRR 152
#define aOWRR 153
#define aEYIY 154
#define aOHIY 155
#define aOWIY 156
#define aOHIH 157
#define aIYEH 158
#define aEHLL 159
#define aIYUW 160
#define aAXUW 161
#define aIHWW 162
#define aAYWW 163
#define aOWWW 164
#define aJH 165
#define aVV 166
#define aZZ 167
#define aZh 168
#define aDH 169
#define aBE 170
#define aBO 171
#define aEB 172
#define aOB 173
#define aDE 174
#define aDO 175
#define aED 176
#define aOD 177
#define aGE 178
#define aGO 179
#define aEG 180
#define aOG 181
#define aCH 182
#define aHE 183
#define aHO 184
#define aWH 185
#define aFF 186
#define aSE 187
#define aSO 188
#define aSH 189
#define aTH 190
#define aTT 191
#define aTU 192
#define aTS 193
#define aKE 194
#define aKO 195
#define aEK 196
#define aOK 197
#define aPE 198
#define aPO 199

#define aC1 33
#define aCs1 35 // C#1
#define aD1 37
#define aDs1 39 // D#1
#define aE1 41
#define aF1 44
#define aFs1 46 // F#1
#define aG1 49
#define aGs1 52 // G#1
#define aA1 55
#define aAs1 58 // A#1
#define aB1 62

#define aC2 65
#define aCs2 69
#define aD2 73
#define aDs2 78
#define aE2 82
#define aF2 87
#define aFs2 93
#define aG2 98
#define aGs2 104
#define aA2 110
#define aAs2 117
#define aB2 124

#define aC3 131
#define aCs3 139
#define aD3 147
#define aDs3 156
#define aE3 165
#define aF3 175
#define aFs3 185
#define aG3 196
#define aGs3 208
#define aA3 220
#define aAs3 233
#define aB3 247


//Define the Pin Numbers for the sketch.
#define E0  5
#define E1  6
#define E2  7 
#define E3  8
#define E4  9
#define E5  10
#define E6  11
#define E7  12

#define RDY  13
#define SPK  4

#define txPin  2

const int buttonBeep = 6;     // the number of the pushbutton pin
const int buttonAlo = 7;     // the number of the pushbutton pin
const int buttonBio= 8;     // the number of the pushbutton pin

int lastButtonState = LOW;   // the previous reading from the input pin
int buttonState;             // the current reading from the input pin
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 0;    // the debounce time; increase if the output flickers

int cvPin = A0;    // select the input pin for the potentiometer



//Create a SoftSerial Objet
SoftwareSerial speakjet = SoftwareSerial(0, txPin);

//The message array contains the command for sounds to be sent in order to inunciate the words "All your base belong to us." Check the SpeakJet Manual for more information
//on producing words
                                                  //All              Your         Base                 Are     Belong                       to          us
char message[] = {20, 96, 21, 114, 22, 88, 23, 5, 8, 135, 8, 146, 5, 128, 153, 5, 170, 154, 8, 188, 5, 152, 5, 170, 8,128,146,8,135,8,144,5,8,191,162,5,8,134,187};

//The sounds array contains the commands to send robot sounds to the SpeakJet chip.
//char sounds[] = {200, 201, 202, 203, 220, 221, 222};
char sounds[] = {230, 231, 232, 233, 234, 235, 236};

char w_robot[] = {aRR, aFAST, aOW, aFAST, aOWWW, aSOFT, aBO, aOH, aTT};
char w_shadow[] ={aSH, aAY, aDO, aFAST, aOW, aFAST, aOWWW};
char w_popcorn[] ={aPO, aOH, aPO, aKO, aOWRR, aNE};
char w_number[] ={aNE, aUX, aMM, aSOFT, aBO, aRR};
char w_network[] ={aNE, aEH, aTT, aFAST, aWW, aFAST, aAXRR, aEK};
char w_memory[] ={aMM, aEH, aMM, aFAST, aAXRR, aIY};

char daisy1[] = {20,96,21,114,22,88,23,5,31,aSPD,114,aPIT,aD3,aDE,aSPD,22,aEYIY,aSPD,114,aPIT,aB2,aZZ,aSPD,5,aIY,aSPD,114,2,1,aPIT,aG2,aDE,aSPD,22,aEYIY,aSPD,114,aPIT,aD2,aZZ,aSPD,5,aIY,aSPD,114,2,1};
// give me your answer do
char daisy2[] = {aPIT,aE2,aGE,aIH,aVV,0,aPIT,aF2,aMM,aIY,0,aPIT,aG2,aIYEH,aOWRR,0,aPIT,aE2,aAY,aNO,2,2,aPIT,aG2,aSO,aEYRR,0,aPIT,aD2,aDO,aSPD,2,aIHWW,aSPD,114,2,1};

// i'm half crazy
byte daisy3[] = {aPIT,aA2,aSPD,69,aOHIH,aSPD,114,aMM,2,1,aPIT,aD3,aSTR,aHO,aSPD,17,aAY,aSPD,114,aFF,2,aPIT,aB2,aKO,aRR,aSPD,49,aEYIY,aSPD,114,1,aPIT,aG2,aZZ,aSPD,5,aIY,aSPD,114,2,1};
// all for the love of you
byte daisy4[] = {aPIT,aE2,aSPD,104,aAW,aSPD,114,aLO,0,aPIT,aF2,aFF,aSPD,120,aOW,aSPD,117,aAXRR,aSPD,114,0,aPIT,aG2,aTH,aUX,0,aPIT,aA2,aLO,aUX,aVV,2,2,aPIT,aB2,aUX,aVV,0,aPIT,aA2,aIYEH,aSPD,36,aIHWW,aSPD,114,3,1};
// it won't be a stylish marriage
byte daisy5[] = {aPIT,aB2,aIH,aTT,0,aPIT,aC3,aWW,aOW,aNE,aTT,aPIT,aB2,aBE,aIY,aPIT,aA2,aUX,aPIT,aD3,aSE,aTU,aSPD,87,aOHIH,aSPD,114,aPIT,aB2,aLE,aIH,aSH,aPIT,aA2,aMM,aEYRR,aPIT,aG2,aSPD,0,aIH,aIH,aSPD,114,aJH};

void setup()  
{
  //Configure the pins for the SpeakJet module
  pinMode(txPin, OUTPUT);
  pinMode(SPK, INPUT);
  
  //Set up a serial port to talk from Arduino to the SpeakJet module on pin 3.
  speakjet.begin(9600);    
  
  //Configure the Ready pin as an input
  pinMode(RDY, INPUT);
  
  //Configure Reset line as an output
       
  //Configure all of the Event pins as outputs from Arduino, and set them Low.
  for(int i=E0; i<=E7; i++)
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  
  //All I/O pins are configured. Reset the SpeakJet module
  delay(1000);

  pinMode(buttonBio, INPUT);  
  pinMode(buttonAlo, INPUT);
  pinMode(buttonBeep, INPUT);
  lastDebounceTime = millis();
  
  
}

void loop()
{  
  
  delay(5000);
  for (int i=0; i<sizeof(daisy1); i++){
    speakjet.print(daisy1[i]);
  }
  delay(5000);
  SJBusy();
  for (int i=0; i<sizeof(daisy2); i++){
    speakjet.print(daisy2[i]);
  }
  SJBusy();
  for (int i=0; i<sizeof(daisy3); i++){
    speakjet.print(daisy3[i]);
  }
  SJBusy();
  for (int i=0; i<sizeof(daisy4); i++){
    speakjet.print(daisy4[i]);
  }
  SJBusy();
  for (int i=0; i<sizeof(daisy5); i++){
    speakjet.print(daisy5[i]);
  }
  SJBusy();
  
  
  //Send "All Your Base are Belong to Us" to the SpeakJet module
  //speakjet.print(message);
  //Wait before sending the next string.
  //delay(3000);    
  //Send the robotic sounds to the module.
/*
    if(digitalRead(buttonBeep)){
      //launchSound(200, 9, cvPin);
      launchWordSound(cvPin);
    }
    else if(digitalRead(buttonAlo)){
      launchSound(128, 71, cvPin);
    }
    else if(digitalRead(buttonBio)){
      launchSound(230, 9, cvPin);
    }
 /*   

/*
  speakjet.print((char)22);
  speakjet.println((char)i);
  speakjet.println((char)146);
  Serial.println(i);
  SJBusy();     
*/


}

void sayWord(char wordToSay[]){
    speakjet.print((char)22);
    speakjet.print((char)85);
  for (int i=0; i<sizeof(wordToSay); i++){
    speakjet.print(wordToSay[i]);
  }
  
}

void launchWordSound(int pinToRead){
      int sensorValue_pitch = analogRead(cvPin)/4;
      //int sensorValue_cv = 220+(9*analogRead(cvPin)/1023);    
      int value = 1+ 5*analogRead(pinToRead)/1023;
            
      if(value==1){
        sayWord(w_shadow);
      }
      else if(value==2){
        sayWord(w_robot);
      }
      else if(value==3){
        sayWord(w_popcorn);
      }
      else if(value==4){
        sayWord(w_number);
      }
      else if(value==5){
        sayWord(w_network);
      }
      else if(value==6){
        sayWord(w_memory);
      }
      
      SJBusy();
}


void launchSound(int baseval, int maxval, int pinToRead){
      int sensorValue_pitch = analogRead(cvPin)/4;
      //int sensorValue_cv = 220+(9*analogRead(cvPin)/1023);    
      int sensorValue_cv = baseval+(maxval*analogRead(pinToRead)/1023);    
/*
      speakjet.print((char)22);
      speakjet.println((char)sensorValue_pitch);
*/
      speakjet.println((char)sensorValue_cv);
      SJBusy();
}

void SJBusy(){
  delay(20); // wait 12ms minimum before checking SpeakJet busy pin
  while(digitalRead(SPK)){
    delay(250); // wait here while SpeakJet is busy (pin 4 is true)
  }
  delay(250); // a bit more delay is needed for some reason
}
