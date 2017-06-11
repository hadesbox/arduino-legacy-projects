// Hardware Setup

#include "Hardware.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Hardware_Setup()
{ 
  /*
  //Timer2 setup  This is the audio rate timer, fires an interrupt at 15625 Hz sampling rate
   TIMSK2 = 1<<OCIE2A;  // interrupt enable audio timer
   OCR2A = 127;
   TCCR2A = 2;               // CTC mode, counts up to 127 then resets
   TCCR2B = 0<<CS22 | 1<<CS21 | 0<<CS20;   // different for atmega8 (no 'B' i think)
   */

  SPCR = 0x50;   // set up SPI port  SPCR = 01010000, 
  SPSR = 0x01;  //
  DDRB |= 0x2E;       // PB output for DAC CS, and SPI port
  PORTB |= (1<<1);   // CS high

  sei();			// global interrupt enable
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Here are the two bytes that go to the DAC over SPI
uint8_t dacSPI0;
uint8_t dacSPI1;

void dacOut(uint16_t outVal){
  
  //DAC TEST
 //outVal = 2033;
  
  // format data for SPI port
  dacSPI0 = (outVal >> 8) & 0x00FF;
  dacSPI0 |= 0x10;
  dacSPI1 = outVal & 0x00FF;
  PORTB &= ~(1<<1); // Frame sync low
  //dacSPI0 |= 0x50;    // buffered, gain x 2


  // transmit value out the SPI port
  PORTB &= ~(1<<1); // Frame sync low
  SPDR = dacSPI0;  //The SPI Data Register - Writing to the register initiates data transmission.
  while (!(SPSR & (1<<SPIF))){}; //Wait for data to be sent over SPI, flag raised
  SPDR = dacSPI1;
  while (!(SPSR & (1<<SPIF))){};
  PORTB |= (1<<1); // Frame sync high
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////






