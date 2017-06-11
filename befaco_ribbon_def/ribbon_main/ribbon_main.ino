

//funciones clear bit y set bit
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))

// constants won't change. Used here to 
// set pin numbers:
const int pin_clock =  11;      // the number of the LED pin
const int pin_entrada = 0 ;  //pin de entrada del ribbon
const int numlectura = 50;  //definimos el tamaño de readings (un array de 10 valores)
const int pin_gate1 = 12;
const int pin_gate2 = 13;
const int pin_cv1 = 9;
const int pin_cv2 = 10;

volatile int timer_16d;

volatile boolean pin_salida_clock=0;  // almacen del estado actual de la salida de sincronia
unsigned long previous_micros = 0;        // will store last time LED was updated
unsigned long current_micros;
int lectura_alta;
int lectura_baja;
int lectura_suma;
int timer_3=0;
int timer_4=0;
int lectura_l[numlectura];   // creamos un array de 10 valores 
int lectura_r[numlectura];   // creamos un array de 10 valores 
int index_l = 0;             // el indice de la posicin del array
int index_r = 0;             // el indice de la posicin del array
unsigned int total_l = 0;    // the running total
unsigned int total_r = 0;    // the running total
int average_l = 0;           // la media de los valores almacenados
int average_r = 0;           // la media de los valores almacenados

int cv1_val=0;
int cv2_val=0;
int cv1_val_past=0;
int cv2_val_past=0;

void setup() {
  // set the digital pin as output:
  pinMode(pin_clock, OUTPUT); 
  pinMode (pin_entrada,INPUT);
  Serial.begin(57600);
  // set prescale to 16 (1MHz ADC clock)
  sbi(ADCSRA,ADPS2) ;
  cbi(ADCSRA,ADPS1) ;
  cbi(ADCSRA,ADPS0) ;
  pinMode(pin_gate1, OUTPUT);
  pinMode(pin_gate2, OUTPUT);
  pinMode(pin_cv1, OUTPUT);
  pinMode(pin_cv2, OUTPUT);

  Setup_timer1();
  
  for (int thisReading = 0; thisReading < numlectura; thisReading++)
  {
    lectura_l[thisReading] = 0;
    lectura_r[thisReading] = 0;
  }  

}

void loop()
{

  if (pin_salida_clock) //procedemos a la lectura del valor alto
  {
    current_micros= micros();
    if (current_micros>(previous_micros+350))
    {

      total_l= total_l - lectura_l[index_l]; // subtract the last reading:
      lectura_l[index_l]=analogRead(pin_entrada);
      total_l= total_l + lectura_l[index_l]; // add the reading to the total:  
      index_l++;
      if (index_l >= numlectura) index_l = 0;

      average_l = total_l / numlectura; // calculate the average:
      //para depurar a pelo el CV1 del ribbon
      //average_l = analogRead(pin_entrada);
    }
  }

  if (!pin_salida_clock)//procedemos a la lectura del valor bajo
  {
    current_micros= micros();
    if (current_micros>(previous_micros+350))
    {

      total_r= total_r - lectura_r[index_r]; // subtract the last reading:
      lectura_r[index_r]=analogRead(pin_entrada);
      total_r= total_r + lectura_r[index_r]; // add the reading to the total:   
      index_r++;
      if (index_r >= numlectura) index_r = 0;
      average_r = total_r / numlectura; // calculate the average:

      //para depurar a pelo el CV2 del ribbon
      //average_r=analogRead(pin_entrada);
    }
  }

  if(average_l>0){
    cv1_val = 1023-average_l;
    cv2_val = average_r;
  }
  else{
    cv1_val = cv1_val_past;
    cv2_val = cv2_val_past;  
  }

  lectura_suma=average_l+average_r;

  if (timer_3 > 100) {
    timer_3= 0;
    Serial.print("average_l: ");
    Serial.print(average_l,DEC);
    Serial.print("    average_r: ");
    Serial.print(average_r,DEC);
    Serial.print("    cv1_val: ");
    Serial.print(cv1_val,DEC);
    Serial.print("    cv2_val: ");
    Serial.print(cv2_val,DEC);
    Serial.print("    suma: ");
    Serial.println(lectura_suma,DEC);
  }
  
  if (timer_4 > 200) {
    timer_4= 0;
    if(average_l>0){
      cv1_val_past = 1023-average_l;
      cv2_val_past = average_r;
    }
  }
  
  if(lectura_suma > 1250){
    digitalWrite(pin_gate1, HIGH);
    digitalWrite(pin_gate2, HIGH);
  }
  else if(lectura_suma > 0){
    digitalWrite(pin_gate1, HIGH);
    digitalWrite(pin_gate2, LOW);
  }
  else{
    digitalWrite(pin_gate1, LOW);
    digitalWrite(pin_gate2, LOW);
  }

}

void Setup_timer1() {
  OCR1A = 0x0000;
  OCR1B = 0x0000;
  TCCR1A = 0xA3;   // Mode PWM Phase Correct
  TCCR1B = 0x01;   // Prescaler clkI/O/8
  TCNT1 = 0x0000;
  TIMSK1 = 0x01;
}

//interrumpimos 
ISR(TIMER1_OVF_vect) {
  cli();
  OCR1A = cv1_val;// pwm en pin 9 de 10bits
  OCR1B = cv2_val;// pwm en pin 10 de 10bits
  if(timer_16d++ > 2){ //3 ciclos son 480u segundos
    previous_micros=micros();
    timer_16d=0;
    pin_salida_clock =  !pin_salida_clock; // invierto conforme se invierte OC2A para saber el estado actual de la salida
    digitalWrite(pin_clock, pin_salida_clock);
    timer_3++;
    timer_4++;
  }
  sei();
}

