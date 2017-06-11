

int current_pin = 0;
int min_pin = 3;
int max_pin = 4;

void setup(){

  pinMode(A0,INPUT);
  for(int i=min_pin; i<=max_pin; i++){
    pinMode(i,OUTPUT);
  }
  
}



void loop(){
  

  if(current_pin > max_pin){
    current_pin=min_pin;
  }
  
  for(int i=min_pin; i<=max_pin; i++){
    digitalWrite(i,LOW);
  }
  
  digitalWrite(current_pin,HIGH);
  int aval = analogRead(A0);

  delay(aval);  
    
  current_pin++;
  
}
