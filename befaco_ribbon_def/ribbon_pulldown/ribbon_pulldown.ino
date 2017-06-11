const int pin_gate1 = 0;
const int pin_gate2 = 1;
const int pin_cv1 = 2;
const int pin_cv2 = 3;

int val=0;

void setup() {
  digitalWrite(   , LOW);
  digitalWrite(pin_gate2, LOW);
  digitalWrite(pin_cv1, LOW);
  digitalWrite(pin_cv2, LOW);
  pinMode(pin_gate1, INPUT);
  pinMode(pin_gate2, INPUT);
  pinMode(pin_cv1, INPUT);
  pinMode(pin_cv2, INPUT);
  Serial.begin(57600);
}

void loop()
{
  val = analogRead(pin_cv1);
  Serial.print(val);
  Serial.print("  ");
  val = analogRead(pin_cv2);
  Serial.print(val);
  Serial.print("  ");
  val = analogRead(pin_gate1);
  Serial.print(val);
  Serial.print("  ");
  val = analogRead(pin_gate2);
  Serial.print(val);
  Serial.print("  ");
}
