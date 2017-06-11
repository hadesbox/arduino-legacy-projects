

int pin_totest = 13;

int pin_state = LOW;

void setup(){
  
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);

  pinMode(pin_totest,OUTPUT);

}

void loop(){
  
  int aval = analogRead(A1);
  
  pin_state = !pin_state;

  digitalWrite(pin_totest,pin_state);
  delay(aval);  
  
}

