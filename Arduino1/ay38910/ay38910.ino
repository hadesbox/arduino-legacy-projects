//YM38910

//PINS for controlling  8 address/data thru  595 of AY38910  
////Pin connected to Data in (DS) of 74HC595
const int dataPin1 = 21;
//Pin connected to latch pin (ST_CP) of 74HC595
const int latchPin1 = 20;
//Pin connected to clock pin (SH_CP) of 74HC595
const int clockPin1 = 19;

//Pins for controlling latch of AY38910
const int pinBC11 =  18;     
const int pinBC21 =  17;    
const int pinBCDIR1 =  16;

const int dataPin2 = 2;
//Pin connected to latch pin (ST_CP) of 74HC595
const int latchPin2 = 3;
//Pin connected to clock pin (SH_CP) of 74HC595
const int clockPin2 = 4;

//Pins for controlling latch of AY38910
const int pinBC12 =  5;     
const int pinBC22 =  6;    
const int pinBCDIR2 =  7;

const int latchLeds = 29;
const int dataLeds = 27;
const int clockLeds = 31;



// Variables for the step sequencer without delay
long previousMillis = 0;       // will store last time LED was updated
long interval = 200;           // interval at which to blink (milliseconds)
int currentStep = 0;

int lastintervalchange=0;

//Button pins for reading with 4051
int butbit0=26;
int butbit1=28;
int butbit2=30;

int butLDR=22;                     // PIN analógico de la LDR
int butLDR2=24;                     // PIN analógico de la LDR
int butval = 0;                   // Vble que almacenará los valores de la LDR

unsigned int butLedOn=0;

int base=0;

int buttonArray[16][2]={
{3,butLDR},
{2,butLDR},
{1,butLDR},
{0,butLDR},
{7,butLDR},
{6,butLDR},
{5,butLDR},
{4,butLDR},
{3,butLDR2},
{2,butLDR2},
{1,butLDR2},
{0,butLDR2},
{7,butLDR2},
{6,butLDR2},
{5,butLDR2},
{4,butLDR2}
};  



int tp[] = { //MIDI to note number
  15289, 14431, 13621, 12856, 12135, 11454, 10811, 10204,//0-o7
  9631, 9091, 8581, 8099, 7645, 7215, 6810, 6428,//8-15
  6067, 5727, 5405, 5102, 4816, 4545, 4290, 4050,//16-23
  3822, 3608, 3405, 3214, 3034, 2863, 2703, 2551,//24-31
  2408, 2273, 2145, 2025, 1911, 1804, 1703, 1607,//32-39
  1517, 1432, 1351, 1276, 1204, 1136, 1073, 1012,//40-47
  956, 902, 851, 804, 758, 716, 676, 638,//48-55
  602, 568, 536, 506, 478, 451, 426, 402,//56-63
  379, 358, 338, 319, 301, 284, 268, 253,//64-71
  239, 225, 213, 201, 190, 179, 169, 159,//72-79
  150, 142, 134, 127, 119, 113, 106, 100,//80-87
  95, 89, 84, 80, 75, 71, 67, 63,//88-95
  60, 56, 53, 50, 47, 45, 42, 40,//96-103
  38, 36, 34, 32, 30, 28, 27, 25,//104-111
  24, 22, 21, 20, 19, 18, 17, 16,//112-119
  15, 14, 13, 13, 12, 11, 11, 10,//120-127
  0//off
};

int song[][3] ={
{48,36,64},
{48,36,59},
{48,36,55},
{48,36,52},
{48,36,64},
{48,36,59},
{48,36,55},
{48,36,52},
{51,39,64},
{51,39,59},
{51,39,55},
{51,39,52},
{51,39,64},
{51,39,59},
{51,39,55},
{51,39,52},
{58,46,64},
{58,46,60},
{58,46,55},
{58,46,52},
{58,46,64},
{58,46,60},
{58,46,55},
{58,46,52},
{56,44,64},
{56,44,60},
{56,44,55},
{56,44,52},
{56,44,64},
{56,44,60},
{56,44,55},
{56,44,52}
};


int buttonState = LOW;             // the accepted reading from the input pin
int lastButtonState = LOW;         // the button state after debounce filter
int lastButtonState2 = LOW;        // the previous reading from input pin
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 100;    // the debounce time; increase if the output flickers
int buttonCount = 0;               // the number of times the button has been pressed

int mode_play=0;

int but_change=0;

void setup(){
 
    pinMode(latchPin1, OUTPUT);
    pinMode(dataPin1, OUTPUT);  
    pinMode(clockPin1, OUTPUT);   
    
    pinMode(latchPin2, OUTPUT);
    pinMode(dataPin2, OUTPUT);  
    pinMode(clockPin2, OUTPUT);    
   
    pinMode(pinBC11, OUTPUT);
    pinMode(pinBC21, OUTPUT);
    pinMode(pinBCDIR1, OUTPUT);  
   
    pinMode(pinBC12, OUTPUT);
    pinMode(pinBC22, OUTPUT);
    pinMode(pinBCDIR2, OUTPUT);
    
    write_data(0x06, 0x00, 1); //Noise tone
    write_data(0x07, 0x38, 1); //Mixer
    write_data(0x08, 0x01, 1); //Volumen A
    write_data(0x09, 0x01, 1); //Volumen B
    write_data(0x0A, 0x01, 1); //Volumen C
    
    write_data(0x06, 0x00, 2); //Noise tone
    write_data(0x07, 0x38, 2); //Mixer
    write_data(0x08, 0x01, 2); //Volumen A
    write_data(0x09, 0x01, 2); //Volumen B
    write_data(0x0A, 0x01, 2); //Volumen C

    pinMode(latchLeds, OUTPUT);
    pinMode(dataLeds, OUTPUT);  
    pinMode(clockLeds, OUTPUT);       

    pinMode(butbit0, OUTPUT);    // s0
    pinMode(butbit1, OUTPUT);    // s1
    pinMode(butbit2, OUTPUT);    // s2
    
    
    Serial.begin(9600);

}

void set_chA1(int i)
{
  write_data(0x00, tp[i]&0xff,1);
  write_data(0x01, (tp[i] >> 8)&0x0f,1);    
}

void set_chB1(int i)
{
  write_data(0x02, tp[i]&0xff,1);
  write_data(0x03, (tp[i] >> 8)&0x0f,1);
}

void set_chC1(int i)
{
    write_data(0x04, tp[i]&0xff,1);
    write_data(0x05, (tp[i] >> 8)&0x0f,1);
}


void set_chA2(int i)
{
  write_data(0x00, tp[i]&0xff,2);
  write_data(0x01, (tp[i] >> 8)&0x0f,2);    
}

void set_chB2(int i)
{
  write_data(0x02, tp[i]&0xff,2);
  write_data(0x03, (tp[i] >> 8)&0x0f,2);
}

void set_chC2(int i)
{
    write_data(0x04, tp[i]&0xff,2);
    write_data(0x05, (tp[i] >> 8)&0x0f,2);
}

void mode_latch(int i){
  if(i==1){
    digitalWrite(pinBC11, HIGH);
    digitalWrite(pinBC21, HIGH);
    digitalWrite(pinBCDIR1, HIGH);
  }
  else{
    digitalWrite(pinBC12, HIGH);
    digitalWrite(pinBC22, HIGH);
    digitalWrite(pinBCDIR2, HIGH);    
  }

}

void mode_write(int i) {
  if(i==1){
    digitalWrite(pinBC11, LOW);
    digitalWrite(pinBC21, HIGH);
    digitalWrite(pinBCDIR1, HIGH);
  } else {
    digitalWrite(pinBC12, LOW);
    digitalWrite(pinBC22, HIGH);
    digitalWrite(pinBCDIR2, HIGH);
  }
}

void mode_inactive(int i){
  if(i==1){
    digitalWrite(pinBC11, LOW);
    digitalWrite(pinBC21, LOW);
    digitalWrite(pinBCDIR1, LOW);   
  }else{
    digitalWrite(pinBC12, LOW);
    digitalWrite(pinBC22, LOW);
    digitalWrite(pinBCDIR2, LOW);
  }
}

void write_data(unsigned char address, unsigned char data, int i)
{  

  mode_inactive(i);  
  //write address  
  
  if(i==1){
    digitalWrite(latchPin1, LOW);
    // shift out the bits:
    shiftOut(dataPin1, clockPin1, MSBFIRST, address);
    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin1, HIGH);
  }
  else {
    digitalWrite(latchPin2, LOW);
    // shift out the bits:
    shiftOut(dataPin2, clockPin2, MSBFIRST, address);
    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin2, HIGH);  
  }
  
  mode_latch(i);  
  mode_inactive(i);
  
  //write data
  mode_write(i);  
  
  if(i==1){
    digitalWrite(latchPin1, LOW);
    // shift out the bits:
    shiftOut(dataPin1, clockPin1, MSBFIRST, data);
    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin1, HIGH);
  }
  else{
    digitalWrite(latchPin2, LOW);
    // shift out the bits:
    shiftOut(dataPin2, clockPin2, MSBFIRST, data);
    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin2, HIGH);
  }
  
  mode_inactive(i);  
}

//Leds writing function
void ledsWrite() {
  // the bits you want to send. Use an unsigned int,
  // so you can use all 16 bits:
  unsigned int bitsToSend = 0;    

  // turn off the output so the pins don't light up
  // while you're shifting bits:
  digitalWrite(latchLeds, LOW);

  // turn on the next highest bit in bitsToSend:
  bitsToSend = butLedOn;
  bitWrite(bitsToSend, currentStep, HIGH);

  // break the bits into two bytes, one for 
  // the first register and one for the second:
  byte registerOne = highByte(bitsToSend);
  byte registerTwo = lowByte(bitsToSend);

  // shift the bytes out:
  shiftOut(dataLeds, clockLeds, MSBFIRST, registerOne);
  shiftOut(dataLeds, clockLeds, MSBFIRST, registerTwo);

  // turn on the output so the LEDs can light up:
  digitalWrite(latchLeds, HIGH);
}

void playStep(int pos){
     set_chA1(song[pos][0]);
     set_chB1(song[pos][1]+1);
     set_chC1(song[pos][2]-4);
     set_chA2(song[pos][0]+4);
     set_chB2(song[pos][0]+20);
     set_chC2(song[pos][0]+40);
}


int readButton(int pos, int value, int ld){
    int r0 = bitRead(value,0);
    int r1 = bitRead(value,1);
    int r2 = bitRead(value,2);   

    digitalWrite(butbit0, r0);
    digitalWrite(butbit1, r1);
    digitalWrite(butbit2, r2);
    
    int val = digitalRead(ld);        // Lee el valor del sensor LDR      

    //bitWrite(butLedOn,pos,val);
    
    return val;
}

void debouncePlay(int reading){
  
  // Check to see if you just pressed the button 
  // and you've waited long enough since the last press to ignore any noise: 
  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState2) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  } 
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:
    buttonState = reading;
  }
  lastButtonState2 = reading;

  // If the accepted button state is different than the last button state,
  // increment the counter one time. Also print number of counts to serial output.
  if(buttonState != lastButtonState) {
     lastButtonState = reading;
     buttonCount++;
     
    if(buttonCount % 4==2) {
      mode_play=1;

      mute_all();      
      
      
    }
    else {
      mode_play=0;
    }     
    
  }

}


void mute_all(){
    write_data(0x07, 0x3F, 1); //Mixer
    write_data(0x07, 0x3F, 2); //Mixer

    set_chA1(128);
    set_chB1(128);
    set_chC1(128);
    set_chA2(128);
    set_chB2(128);
    set_chC2(128); 
      
    write_data(0x06, 0x00, 1); //Noise tone
    write_data(0x07, 0x38, 1); //Mixer
    write_data(0x08, 0x01, 1); //Volumen A
    write_data(0x09, 0x01, 1); //Volumen B
    write_data(0x0A, 0x01, 1); //Volumen C
    
    write_data(0x06, 0x00, 2); //Noise tone
    write_data(0x07, 0x38, 2); //Mixer
    write_data(0x08, 0x01, 2); //Volumen A
    write_data(0x09, 0x01, 2); //Volumen B
    write_data(0x0A, 0x01, 2); //Volumen C  
  
}

void loop() {
  
  unsigned long currentMillis = millis();

  if(mode_play==0){
    if(currentMillis - previousMillis > interval) {
      playStep(currentStep);
      previousMillis = currentMillis;   
      if(currentStep>=15) {
        currentStep=0;
      }
      else {
        currentStep++;
      }
    }
  }
  else{
    
    butLedOn=0;
   
    currentStep=16;  
/*
    set_chA1(128);
    set_chB1(128);
    set_chC1(128);
    set_chA2(128);
    set_chB2(128);
    set_chC2(128);    
    */
    

  }
  
  for(int i=0;i<16;i++){    
    int butonval = readButton(i,buttonArray[i][0],buttonArray[i][1]);
    if(i==0){      
      debouncePlay(butonval);       
    }
    else if(i==5){
      if(butonval==HIGH && currentMillis-lastintervalchange>200){
         base=base-5;
         if(base<-60){
           base=-60;
         }
         lastintervalchange=millis();
         Serial.println("scale -------");
      }
    }    
    else if(i==6){
      if(butonval==HIGH && currentMillis-lastintervalchange>200){
         base=base+5;
         if(base>60){
           base=60;
         }         
         lastintervalchange=millis();
         Serial.println("scale +++++++");
      }
    }    
    else if(i==7){
      if(butonval==HIGH && currentMillis-lastintervalchange>25){
         interval++;
         lastintervalchange=millis();
      }
    }
    else if(i==15){
      if(butonval==HIGH && currentMillis-lastintervalchange>25){
         interval--;
         lastintervalchange=millis();
      }
    } 
    else if(i>=8 && i<=14 &&mode_play==1){
 
      if(butonval==HIGH){
          if(but_change!=i){
            set_chA1(65+i+base);
            set_chB1(65+i+1+base);
            set_chC1(65+i+2+base);
            set_chA2(65+i+3+base);
            set_chB2(65+i+4+base);
            set_chC2(65+i+5+base);             
            but_change=i;
            Serial.println(i);
          }
      }
    } 
 
    
    bitWrite(butLedOn,i,butonval);    
  }
  
  ledsWrite();  
}  




//Another tune
  
/*
  for(int i=0;i<8;i++){
   set_chA(48);
   delay(100);
   set_chA(60);   
   delay(100);
  }  

  for(int i=0;i<4;i++){
   set_chA(53);
   delay(100);
   set_chA(65);
   delay(100);
  }
  
  for(int i=0;i<4;i++){
   set_chA(55);
   delay(100);
   set_chA(67);
   delay(100);
  }
*/
  
/*
  //Gunshot like sound KICK 
  write_data(0x06, 0x11);
  write_data(0x07, 0x07);
  write_data(0x08, 0x10);
  write_data(0x09, 0x10);
  write_data(0x0a, 0x10);
  write_data(0x0c, 0x10);
  write_data(0x0d, 0x00);
  delay(500);  
  
  write_data(0x06, 0x00);
  write_data(0x07, 0x07);
  write_data(0x08, 0x10);
  write_data(0x09, 0x10);
  write_data(0x0a, 0x10);
  write_data(0x0c, 0x38);
  write_data(0x0d, 0x00);
  delay(500);  

  // iterate over the 16 outputs of the two shift registers


  for (int thisLed = 0; thisLed < 16; thisLed++) {
    
    volumeValue = analogRead(volumePin);
    volumeValue = (volumeValue * 15) / 1023;
    //write_data(0x08, volumeValue&0x0f);
    
    // read the state of the pushbutton value:
    btn1State = digitalRead(btn1Pin);
    if (btn1State == HIGH) {
       currentLoop++;
      if(currentLoop>2)
        currentLoop=0;
    } 

    btn2State = digitalRead(btn2Pin);
    if (btn2State == HIGH) {
      currentLoop--;
      if(currentLoop<0)
        currentLoop=2;
    }
    
    tempoValue = analogRead(tempoPin);    

    // write data to the shift registers:

    ledsWrite(thisLed, HIGH);
    
    int _note = thisLed+(16*currentLoop) - 20;
    
    set_chA(song[_note][0]);
    
    if(thisLed == 7 || thisLed == 15){
      //Gunshot like sound KICK 
      volumeValue = analogRead(volumePin);
      
      Serial.println(volumeValue);
      
      volumeValue = (volumeValue * 255) / 1023;
      //write_data(0x08, volumeValue&0x0f);      
      
      write_data(0x09, 0x10);
      
      Serial.println(volumeValue);
      write_data(0x06, volumeValue&0x0f);
      write_data(13, 0x00);
    }
//    else if(thisLed == 3 || thisLed == 11){     
//      write_data(0x09, 0x10);
//      write_data(0x0a, 0x10);
//      write_data(12, 0x38);
//      write_data(13, 0x00);      
//    }
    
    delay(tempoValue);
    // if this is not the first LED, turn off the previous LED:
    if (thisLed > 0) {
      ledsWrite(thisLed - 1, LOW);
    } 
    // if this is  the first LED, turn off the highest LED:
    else {
      ledsWrite(15, LOW);
    } 
    // pause between LEDs:
    delay(10);
  }
  
 } 
*/  
  


