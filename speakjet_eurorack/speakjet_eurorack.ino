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


/*Pin configuration*/
#define pinReady 2
#define pinSpeaking  7
#define pinTX 6
#define pinReset  3

#define pinTrigger1 9  
#define pinTrigger2 8
#define pinTrigger3 10
#define pinTrigger4 11
#define pinTrigger5 12

#define pinSoundPot 2
#define pinPitchPot 4
#define pinSpeedPot 0

#define pinSoundCV 3
#define pinPitchCV 5
#define pinSpeedCV 1

#define pinLED 4

//Create a SoftSerial Objet
SoftwareSerial speakjet = SoftwareSerial(0, pinTX);

char w_robot[] = {aRR, aFAST, aOW, aFAST, aOWWW, aSOFT, aBO, aOH, aTT};
char w_shadow[] ={aSH, aAY, aDO, aFAST, aOW, aFAST, aOWWW};
char w_popcorn[] ={aPO, aOH, aPO, aKO, aOWRR, aNE};
char w_number[] ={aNE, aUX, aMM, aSOFT, aBO, aRR};
char w_network[] ={aNE, aEH, aTT, aFAST, aWW, aFAST, aAXRR, aEK};
char w_memory[] ={aMM, aEH, aMM, aFAST, aAXRR, aIY};


/*
//The message array contains the command for sounds to be sent in order to inunciate the words "All your base belong to us." Check the SpeakJet Manual for more information
//on producing words
                                                  //All              Your         Base                 Are     Belong                       to          us
char message[] = {20, 96, 21, 114, 22, 88, 23, 5, 8, 135, 8, 146, 5, 128, 153, 5, 170, 154, 8, 188, 5, 152, 5, 170, 8,128,146,8,135,8,144,5,8,191,162,5,8,134,187};

//The sounds array contains the commands to send robot sounds to the SpeakJet chip.
char sounds[] = {200, 201, 202, 203, 220, 221, 222};

char sounds2[] = {200};
*/

void setup()  
{
  //Configure the pins for the SpeakJet module
  pinMode(pinTX, OUTPUT);
  pinMode(pinLED, OUTPUT);
  pinMode(pinSpeaking, INPUT);
  
  pinMode(pinSoundPot, INPUT);
  pinMode(pinSpeedPot, INPUT);
  pinMode(pinPitchPot, INPUT);
  
  pinMode(pinSoundCV, INPUT);
  pinMode(pinSpeedCV, INPUT);
  pinMode(pinPitchCV, INPUT);
  
  pinMode(pinTrigger1, INPUT);
  pinMode(pinTrigger2, INPUT);
  pinMode(pinTrigger3, INPUT);
  pinMode(pinTrigger4, INPUT);
  pinMode(pinTrigger5, INPUT);
  
  //Set up a serial port to talk from Arduino to the SpeakJet module on pin 3.
  speakjet.begin(9600);    
  
  //Configure the Ready pin as an input
  pinMode(pinReady, INPUT);
  
  //Configure Reset line as an output
  pinMode(pinReset, OUTPUT);
  
  //All I/O pins are configured. Reset the SpeakJet module
  digitalWrite(pinReset, LOW);
  delay(100);
  digitalWrite(pinReset, HIGH);
  
}

void loop()
{ 

  //Send the robotic sounds to the module.
  if(digitalRead(pinTrigger1) == HIGH){
    playSoundRange(128, 199);
  }
  else if(digitalRead(pinTrigger2) == HIGH){
    playSoundRange(200, 219);
  }
  else if(digitalRead(pinTrigger3) == HIGH){
    playSoundRange(220, 229);
  } 
  else if(digitalRead(pinTrigger4) == HIGH){
    playSoundRange(230, 239);
    //playWord();
  }  
  else if(digitalRead(pinTrigger5) == HIGH){
    playSoundRange(128, 199);
  }

}


void playSoundRange(int minVal, int maxVal){
  digitalWrite(pinLED, HIGH);
  int p_value = analogRead(pinPitchCV) + analogRead(pinPitchPot);
  //if(p_value > 1023) p_value = 1023;
  int s_value = analogRead(pinSoundCV) + analogRead(pinSoundPot);
  if(s_value > 1023){
    char playthis[] = {22, map(p_value, 0, 1023, 0, 254), maxVal};
    speakjet.print(maxVal);
  }
  else{
    //char playthis = {map(s_value, 0, 1023, minVal, maxVal)};
    char playthis[] = {22, map(p_value, 0, 1023, 0, 254), map(s_value, 0, 1023, minVal, maxVal)};
    speakjet.print(playthis);
  }  
  SJBusy();
  digitalWrite(pinLED, LOW);  
}


void playWord(){
  digitalWrite(pinLED, HIGH);
  //int s_value = analogRead(pinSoundCV) + analogRead(pinSoundPot);
  int s_value = analogRead(pinSoundPot);
  
  int n_value = map(s_value, 0, 1023, 0, 5);
  
  if(n_value == 0){
    speakjet.println(w_robot);
  }
  else if(n_value == 1){
    speakjet.print(w_shadow);
  }
  else if(n_value == 2){
    speakjet.println(w_popcorn);
  }
  else if(n_value == 3){
    speakjet.println(w_network);
  }
  else if(n_value == 4){
    speakjet.println(w_number);
  }
  else if(n_value == 5){
    speakjet.println(w_memory);
  }  
  
  SJBusy();
  digitalWrite(pinLED, LOW);  
}


void SJBusy(){
  delay(5); // wait before checking SpeakJet busy pin
  while(digitalRead(pinSpeaking)){
    delay(1); // wait here while SpeakJet is busy
  }
}
