// set pin numbers:
const int ledPin1 =  13;      // the number of the LED pin
const int ledPin2 =  12;      // the number of the LED pin
const int ledPin3 =  11;      // the number of the LED pin
const int ledPin4 =  10;      // the number of the LED pin

int leds[] = {ledPin1,ledPin2,ledPin3,ledPin4};


// Variables will change:
int ledState = LOW;            // ledState used to set the LED
long previousMillis = 0;       // will store last time LED was updated
long interval = 400;           // interval at which to blink (milliseconds)

int current_led = 0;
void setup() {
  // set the digital pin as output:
  pinMode(ledPin1, OUTPUT); 
  pinMode(ledPin2, OUTPUT);      
  pinMode(ledPin3, OUTPUT);      
  pinMode(ledPin4, OUTPUT);        
}

void loop()
{
  unsigned long currentMillis = millis();
  
  if(currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   

    // set the LED with the ledState of the variable:
    if(current_led==4) {
      digitalWrite(leds[0], LOW);
      digitalWrite(leds[1], LOW);
      digitalWrite(leds[2], LOW);
      digitalWrite(leds[3], LOW);
      current_led=0;
    }
    else {
      digitalWrite(leds[current_led], HIGH);
      current_led++;
    }  
    
  }
}

