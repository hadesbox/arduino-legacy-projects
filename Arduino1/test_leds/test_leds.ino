const int pinDA0 =  1;   
const int pinDA1 =  2;  
const int pinDA2 =  3;
const int pinDA3 =  4;   
const int pinDA4 =  5;  
const int pinDA5 =  6;  
const int pinDA6 =  7;   
const int pinDA7 =  8;   

const int pinBC1 =  9;     
const int pinBC2 =  10;    
const int pinBCDIR =  11;

void write_data(unsigned char address)
{ 
  digitalWrite(pinBC1, (address >> 0)&0x01);
  digitalWrite(pinBC2, (address >> 1)&0x01);
  digitalWrite(pinBCDIR, (address >> 2)&0x01);

  digitalWrite(pinDA0, (address >> 0)&0x01);
  digitalWrite(pinDA1, (address >> 1)&0x01);
  digitalWrite(pinDA2, (address >> 2)&0x01);
  digitalWrite(pinDA3, (address >> 3)&0x01);
  digitalWrite(pinDA4, (address >> 4)&0x01);
  digitalWrite(pinDA5, (address >> 5)&0x01);
  digitalWrite(pinDA6, (address >> 6)&0x01);
  digitalWrite(pinDA7, (address >> 7)&0x01);
  delay(500);  
  digitalWrite(pinBC1,LOW);
  digitalWrite(pinBC2,LOW);
  digitalWrite(pinBCDIR,LOW);
}

void setup() {
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

}

void loop() {
  // put your main code here, to run repeatedly
  
  for(int i=0; i<256;i++){    
    write_data(i);
  }
  
}
