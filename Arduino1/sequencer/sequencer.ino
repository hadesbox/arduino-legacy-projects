//YM38910

const int pinDA0 =  1;   
const int pinDA1 =  2;  
const int pinDA2 =  3;
const int pinDA3 =  4;   
const int pinDA4 =  5;  
const int pinDA5 =  6;  
const int pinDA6 =  7;   
const int pinDA7 =  8;   

int potPin = 2;


const int pinBC1 =  9;     
const int pinBC2 =  10;    
const int pinBCDIR =  11;

long previousMillis = 0;
long interval = 500; 
int lastplayedstep=0;

int tp[] = {//MIDI note number
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

int song[][2] ={
  {
    60,500  }
  ,
  {
    62,500    }
  ,
  {
    64,500    }
  ,
  {
    65,500    }
  ,
  {
    64,500    }
  ,
  {
    62,500    }
  ,
  {
    60,500    }
  ,
  {
    128,500    }
  ,
  {
    64,500    }
  ,
  {
    65,500    }
  ,
  {
    67,500    }
  ,
  {
    69,500    }
  ,
  {
    67,500    }
  ,
  {
    65,500    }
  ,
  {
    64,500    }
  ,
  {
    128,500    }
  ,  
  {
    60,500    }
  ,
  {
    128,500    }
  ,
  {
    60,500    }
  ,
  {
    128,500    }
  ,
  {
    60,500    }
  ,
  {
    128,500    }
  ,
  {
    60,500    }
  ,
  {
    128,500    }
  ,  
  {
    60,128    }
  ,
  {
    128,128    }
  ,
  {
    60,128    }
  ,
  {
    128,128    }
  ,
  {
    62,128    }
  ,
  {
    128,128    }
  ,
  {
    62,128    }
  ,
  {
    128,128    }
  ,
  {
    64,128    }
  ,
  {
    128,128    }
  ,
  {
    64,128    }
  ,
  {
    128,128    }
  ,
  {
    65,128    }
  ,
  {
    128,128    }
  ,
  {
    65,128    }
  ,
  {
    128,128    }
  ,
  {
    64,250    }
  ,
  {
    128,250    }
  ,
  {
    62,250    }
  ,
  {
    128,250    }
  ,
  {
    60,250    }
  ,
  {
    128,1000    }  
};


void setup(){ 

  Serial.begin(9600);
  Serial.println("Hello world");
  delay(2000);// Give reader a chance to see the output.


  pinMode(13, OUTPUT);     

  //init pins
  pinMode(pinDA0, OUTPUT);
  pinMode(pinDA1, OUTPUT);
  pinMode(pinDA2, OUTPUT);
  pinMode(pinDA3, OUTPUT);
  pinMode(pinDA4, OUTPUT);
  pinMode(pinDA5, OUTPUT);
  pinMode(pinDA6, OUTPUT);
  pinMode(pinDA7, OUTPUT);

  pinMode(pinBC1, OUTPUT);
  pinMode(pinBC2, OUTPUT);
  pinMode(pinBCDIR, OUTPUT);    

  write_data(0x06, 0x00);     //set noise to Zero

  write_data(0x07, 0x3e); // Enable Channel A
  //write_data(0x07, 0x3c);   // Enable Channels A & B

  write_data(0x08, 0x0f);      //set max volume channel A
  write_data(0x09, 0x0f);      //set max volume channel B

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
  digitalWrite(pinDA0, (address >> 0)&0x01);
  digitalWrite(pinDA1, (address >> 1)&0x01);
  digitalWrite(pinDA2, (address >> 2)&0x01);
  digitalWrite(pinDA3, (address >> 3)&0x01);
  digitalWrite(pinDA4, (address >> 4)&0x01);
  digitalWrite(pinDA5, (address >> 5)&0x01);
  digitalWrite(pinDA6, (address >> 6)&0x01);
  digitalWrite(pinDA7, (address >> 7)&0x01);
  mode_latch();  
  mode_inactive();

  //write data
  mode_write();  
  digitalWrite(pinDA0, (data >> 0)&0x01);
  digitalWrite(pinDA1, (data >> 1)&0x01);
  digitalWrite(pinDA2, (data >> 2)&0x01);
  digitalWrite(pinDA3, (data >> 3)&0x01);
  digitalWrite(pinDA4, (data >> 4)&0x01);
  digitalWrite(pinDA5, (data >> 5)&0x01);
  digitalWrite(pinDA6, (data >> 6)&0x01);
  digitalWrite(pinDA7, (data >> 7)&0x01); 
  mode_inactive();  
}

int get_normalized(int maxVal,int value){
  int res = (value * maxVal ) / 1023;
  return res;
}

void loop() {  


  int val = analogRead(potPin);
  int calculated = get_normalized(10,val);
  Serial.println(calculated);

  /*
  unsigned long currentMillis = millis();
   
   if(currentMillis - previousMillis > interval) {
   previousMillis = currentMillis;       
   set_chA(song[lastplayedstep][0]);
   
   digitalWrite(13,HIGH);
   
   if(lastplayedstep>45)   
   lastplayedstep=0;
   else 
   lastplayedstep++;  
   
   }  */

  //Here is your test song converted to array, Alan!
  /*
  for(int i=0;i< 47;i++){
   set_chA(song[i][0]);
   delay(song[i][1]);   
   }*/

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
   }*/


  //Gunshot like sound KICK 
  /*  
   write_data(0x06, 0x11);
   write_data(0x07, 0x07);
   write_data(0x08, 0x10);
   write_data(0x09, 0x10);
   write_data(0x0a, 0x10);
   write_data(0x0c, 0x10);
   write_data(0x0d, 0x00);
   delay(500);
   
   //Explossion like snare
   write_data(0x06, 0x00);
   write_data(0x07, 0x07);
   write_data(0x08, 0x10);
   write_data(0x09, 0x10);
   write_data(0x0a, 0x10);
   write_data(0x0c, 0x38);
   write_data(0x0d, 0x00);
   delay(500);
   */




}



