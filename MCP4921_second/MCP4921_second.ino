#include <SPI.h>

const int chipSelectPin = 9;
const int analogInPin = A0;
int sensorValue = 0;
int outputValue = 0;
byte outputValueByte0 = 0;
byte outputValueByte1 = 0;

void setup() 
{
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV4);
  pinMode(chipSelectPin, OUTPUT);
  digitalWrite(chipSelectPin, HIGH);
}

void loop() 
{
  sensorValue = analogRead(analogInPin);
  sendToDAC(sensorValue);
  
}

void sendToDAC(int sensorValue)
{
  outputValue = map(sensorValue, 0, 1023, 0, 4095);
  outputValueByte0 = byte(outputValue);
  outputValue = outputValue >> 8;
  outputValueByte1 = byte(outputValue | 0b00110000);

  digitalWrite(chipSelectPin, LOW);
  SPI.transfer(outputValueByte1);
  SPI.transfer(outputValueByte0);
  digitalWrite(chipSelectPin, HIGH);  
}
