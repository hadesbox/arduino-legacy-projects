const int pin_gate1 = 12;
const int pin_gate2 = 13;
const int pin_cv1 = 9;
const int pin_cv2 = 10;


void setup() {
  pinMode(pin_gate1, OUTPUT);
  pinMode(pin_gate2, OUTPUT);
  pinMode(pin_cv1, OUTPUT);
  pinMode(pin_cv2, OUTPUT);
}

void loop()
{
  digitalWrite(pin_gate1,HIGH);
  digitalWrite(pin_gate2,HIGH);
  analogWrite(pin_cv1,255);
  analogWrite(pin_cv2,255);
  delay(500);
  digitalWrite(pin_gate1,LOW);
  digitalWrite(pin_gate2,LOW);
  analogWrite(pin_cv1,0);
  analogWrite(pin_cv2,0);
  delay(500);

}
