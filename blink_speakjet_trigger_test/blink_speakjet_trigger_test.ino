

int pinTrigger5 = 8;

int pinLED = 9;

void setup(){
  
  pinMode(pinTrigger5, INPUT);
  pinMode(pinLED, OUTPUT);
  
  delay(1000);

}


void loop(){
  
  int trigger5 = digitalRead(pinTrigger5);
  if(trigger5 == HIGH){
    digitalWrite(pinLED, HIGH);
    delay(5);
  }
  digitalWrite(pinLED, LOW);

}
