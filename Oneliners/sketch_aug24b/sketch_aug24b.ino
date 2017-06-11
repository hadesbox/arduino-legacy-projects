// one-line algorithmic music
// see viznut's blog http://countercomplex.blogspot.com/2011/10/algorithmic-symphonies-from-one-line-of.html
// and http://www.youtube.com/watch?v=GtQdIYUtAHg&feature=related

// ported to arduino by stimmer
// Audio out on pin 10

int a0_pot=0,a1_pot=0;

void function1(long v, long t){putb(t*((t>>12|t>>8)&63&t>>4));}   // by viznut
void function2(long v, long t){putb(((-t&4095)*(255&t*(t&t>>13))>>12)+(127&t*(234&t>>8&t>>3)>>(3&t>>14)));} // by tejeez
void function3(long v, long t){putb(t*(t>>11&t>>8&123&t>>3));}    // by tejeez
void function4(long v, long t){putb(t*((t>>9|t>>13)&25&t>>6));}   // by visy
void function5(long v, long t){putb( (t*(t>>5|t>>8))>>(t>>16));}  // by tejeez
void function6(long v, long t){putb( ((t*(t>>8|t>>9)&46&t>>8))^(t&t>>13|t>>6));} // by xpansive
void function7(long v, long t){putb(((t&4096)?((t*(t^t%255)|(t>>4))>>1):(t>>3)|((t&8192)?t<<2:t)));} // by skurk (raer's version)
void function8(long v, long t){putb( (t>>7|t|t>>6)*10+4*(t&t>>13|t>>6));} // by viznut, xpansive, varjohukka
void function9(long v, long t){putb(t*5&(t>>7)|t*3&(t*4>>10));} // by miiro
void function10(long v, long t){putb((t|(t>>9|t>>7))*t&(t>>11|t>>9));} // by red
void function11(long v, long t){putb(v=(v>>1)+(v>>4)+t*(((t>>16)|(t>>6))&(69&(t>>9))));} // by pyryp
void function12(long v, long t){putb((t>>a0_pot|t|t>>(t>>16))*10+((t>>11)&7));}  //by viznut
void function13(long v, long t){putb((t*(4|7&t>>13)>>((~t>>11)&1)&128) + ((t)*(t>>11&t>>13)*((~t>>9)&3)&127));} // by stimmer

static void (*ptr[13])(long v, long t) = {function1,function2,function3,function4,function5,function6,function7,function8,function9,function10,function11,function12,function13};

void setup() {
  TCCR1B = (TCCR1B & 0xf8) | 1;
  analogWrite(10,1);
  analogWrite(10,1);
  pinMode(5,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
}

void putb(byte b) { OCR1B=b; }

void loop() {
  long v;
  
  digitalWrite(5, LOW);  
  
  for(long t=0;;t++){
        
    a0_pot = analogRead(0)/78;
    
    a1_pot = analogRead(1);

    if(t%(2048)<10){
      digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);
      digitalWrite(7,HIGH);
      digitalWrite(8,HIGH);
      digitalWrite(9,HIGH);
    }
    else{
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
    }
    
    ptr[a0_pot](v, t);
    
    digitalWrite(5,LOW);

  }






}


