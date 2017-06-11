/******************************************************************************
 *  i2c_gpio
 *  Keith Neufeld
 *  May 26, 2008
 *
 *  Prototype I2C interface to TI 9535 and 9555 GPIO expanders.
 *
 *  Arduino analog input 5 - I2C SCL
 *  Arduino analog input 4 - I2C SDA
 *
 ******************************************************************************/

#include <Wire.h>


//#define DEBUG_GPIO


//  I2C device address is 0 1 0 0   A2 A1 A0
#define DIP_ADDRESS (0x4 << 3 | 0x0)
#define LED_ADDRESS (0x4 << 3 | 0x7)


void setup() {
  
#ifdef DEBUG_GPIO
  Serial.begin(9600);
  //Serial.println(DIP_ADDRESS); delay(2000);
#endif

  Wire.begin();
  gpio_write(LED_ADDRESS, 0xffff);
  gpio_dir(LED_ADDRESS, 0x0000);
}


void loop() {
  int bits;
  
#ifdef DEBUG_GPIO
  Serial.println(0xff & gpio_read(DIP_ADDRESS));
#endif

  bits = gpio_read(DIP_ADDRESS) & 0x0f;
  //  mirror direction of bits for output display
  gpio_write(LED_ADDRESS,
      (
        ((bits & 1) << 3) | ((bits & 2) << 1) |
        ((bits & 4) >> 1) | ((bits & 8) >> 3)
      ) << 12);

#ifdef DEBUG_GPIO
  delay(200);
#endif
}


#define REGISTER_INPUT (0)
#define REGISTER_OUTPUT (2)
#define REGISTER_CONFIG (6)

int gpio_read(int address) {
  int data = 0;
  
  //  Send input register address
  Wire.beginTransmission(address);
  Wire.send(REGISTER_INPUT);
  Wire.endTransmission();
  
  //  Connect to device and request two bytes
  Wire.beginTransmission(address);
  Wire.requestFrom(address, 2);
  
  if (Wire.available()) {
    data = Wire.receive();
  }
  if (Wire.available()) {
    data |= Wire.receive() << 8;
  }
  
  Wire.endTransmission();
  
  return data;
}

void gpio_dir(int address, int dir) {
  //  Send config register address
  Wire.beginTransmission(address);
  Wire.send(REGISTER_CONFIG);
  
  //  Connect to device and send two bytes
  Wire.send(0xff & dir);  //  low byte
  Wire.send(dir >> 8);    //  high byte

  Wire.endTransmission();
}

void gpio_write(int address, int data) {
  //  Send output register address
  Wire.beginTransmission(address);
  Wire.send(REGISTER_OUTPUT);
  
  //  Connect to device and send two bytes
  Wire.send(0xff & data);  //  low byte
  Wire.send(data >> 8);    //  high byte

  Wire.endTransmission();
}
