#ifndef _HARDWARE_H_
#define _HARDWARE_H_

#include <inttypes.h>
#include <avr/interrupt.h>
#include <Arduino.h>

void Hardware_Setup();
void dacOut(uint16_t outVal);

#endif


