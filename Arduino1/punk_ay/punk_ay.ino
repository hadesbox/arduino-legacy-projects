//PINS for controlling  8 address/data thru  595 of AY38910  
////Pin connected to Data in (DS) of 74HC595
const int dataPin = 5;
//Pin connected to latch pin (ST_CP) of 74HC595
const int latchPin = 6;
//Pin connected to clock pin (SH_CP) of 74HC595
const int clockPin = 7;

//Pins for controlling latch of AY38910
const int pinBC1 =  10;     
const int pinBC2 =  11;    
const int pinBCDIR =  12;

const int tempoPin = A2;    // select the input pin for the potentiometer
int tempoValue = 0;  // variable to store the value coming from the sensor

const int volumePin = A1;    // select the input pin for the potentiometer
long volumeValue = 0;  // variable to store the value coming from the sensor

long previousMillis = 0;        // will store last time LED was updated

//Pins for controlling the 2 595 of the leds
////Pin connected to DS of 74HC595
const int dataLeds = 2;
//Pin connected to ST_CP of 74HC595
const int latchLeds = 3;
//Pin connected to SH_CP of 74HC595
const int clockLeds = 4;

int current_step = 0;

int tp[] = { //MIDI to note number
  15289, 14431, 13621, 12856, 12135, 11454, 10811, 10204,//0-7
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

int loopA[][16] ={
{60,60,60,60,69,69,69,69,65,65,65,65,60,60,72,72},
{1,9,17,128,33,41,49,128,1,9,128,25,33,49,57,40}
};


void setup(){
 
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);  
    pinMode(clockPin, OUTPUT);
    
    pinMode(latchLeds, OUTPUT);
    pinMode(dataLeds, OUTPUT);  
    pinMode(clockLeds, OUTPUT);    
   
    pinMode(pinBC1, OUTPUT);
    pinMode(pinBC2, OUTPUT);
    pinMode(pinBCDIR, OUTPUT);     
  
      
    write_data(0x06, 0x00); //Noise tone

    write_data(0x07, 0x3c); //Mixer
    write_data(0x08, 0x0f); //Volumen A
    write_data(0x09, 0x0f); //Volumen B    

}

void set_chA(int i)
{
  write_data(0x00, tp[i]&0xff);
  write_data(0x01, (tp[i] >> 8)&0x0f);    
}

void set_chB(int i)
{
  write_data(0x02, tp[i]&0xff);
  write_data(0x03, (tp[i] >> 8)&0x0f);
}

void mode_latch(){
    digitalWrite(pinBC1, HIGH);
    digitalWrite(pinBC2, HIGH);
    digitalWrite(pinBCDIR, HIGH);
}

void mode_write(){
    digitalWrite(pinBC1, LOW);
    digitalWrite(pinBC2, HIGH);
    digitalWrite(pinBCDIR, HIGH);
}

void mode_inactive(){
    digitalWrite(pinBC1, LOW);
    digitalWrite(pinBC2, LOW);
    digitalWrite(pinBCDIR, LOW);    
}

void write_data(unsigned char address, unsigned char data)
{  

  mode_inactive();  
  //write address
  
  digitalWrite(latchPin, LOW);
  // shift out the bits:
  shiftOut(dataPin, clockPin, MSBFIRST, address);  

  //take the latch pin high so the LEDs will light up:
  digitalWrite(latchPin, HIGH);
  
  mode_latch();  
  mode_inactive();
  
  //write data
  mode_write();  
  
  digitalWrite(latchPin, LOW);
  // shift out the bits:
  shiftOut(dataPin, clockPin, MSBFIRST, data);  

  //take the latch pin high so the LEDs will light up:
  digitalWrite(latchPin, HIGH);
  
  mode_inactive();  
}

//Leds writing function
void ledsWrite(int whichPin, int whichState) {
  // the bits you want to send. Use an unsigned int,
  // so you can use all 16 bits:
  unsigned int bitsToSend = 0;    

  // turn off the output so the pins don't light up
  // while you're shifting bits:
  digitalWrite(latchLeds, LOW);

  // turn on the next highest bit in bitsToSend:
  bitWrite(bitsToSend, whichPin, whichState);

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


void loop(){
  
  tempoValue = analogRead(tempoPin);    
  
  unsigned long currentMillis = millis();
  
  if(currentMillis - previousMillis > tempoValue) {
    previousMillis = currentMillis; 
    current_step++;
    if(current_step>=16)
      current_step=0;  
    ledsWrite(current_step, HIGH);
    int _note = current_step;
    set_chA(loopA[0][_note]);
    set_chB(loopA[1][_note]);
  }  

}

