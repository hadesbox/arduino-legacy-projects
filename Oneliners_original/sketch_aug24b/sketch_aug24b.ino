// one-line algorithmic music
// see viznut's blog http://countercomplex.blogspot.com/2011/10/algorithmic-symphonies-from-one-line-of.html
// and http://www.youtube.com/watch?v=GtQdIYUtAHg&feature=related

// ported to arduino by stimmer
// Audio out on pin 10

int a0_pot=0,a1_pot=0;

void setup() {
  TCCR1B = (TCCR1B & 0xf8) | 1;
  analogWrite(10,1);
  analogWrite(10,1);
  pinMode(5,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
}

void putb(byte b)
{

  OCR1B=b;
}

void loop() {
  long v;
  
  digitalWrite(5, LOW);  
  
  for(long t=0;;t++){
        
    a0_pot = analogRead(0);
    a1_pot = analogRead(1);

    if(t%(2048)<10){
      digitalWrite(5,HIGH);
    }
    else{
      digitalWrite(5,LOW);
    }
    
    // uncomment ONE line below
    // or try making one of your own...

    if(a0_pot<80){
      putb(t*((t>>12|t>>8)&63&t>>4));   // by viznut
    }
    else if(a0_pot>80 && a0_pot<160){
      putb(((-t&4095)*(255&t*(t&t>>13))>>12)+(127&t*(234&t>>8&t>>3)>>(3&t>>14))); // by tejeez
    }
    else if(a0_pot>160 && a0_pot<240){
      putb(t*(t>>11&t>>8&123&t>>3));    // by tejeez
    }
    else if(a0_pot>240 && a0_pot<320){
      putb(t*((t>>9|t>>13)&25&t>>6));   // by visy
    }
    else if(a0_pot>320 && a0_pot<400){
      putb( (t*(t>>5|t>>8))>>(t>>16));  // by tejeez
    }
    else if(a0_pot>400 && a0_pot<480){
      putb( ((t*(t>>8|t>>9)&46&t>>8))^(t&t>>13|t>>6)); // by xpansive
    }
    else if(a0_pot>480 && a0_pot<560){
      putb(((t&4096)?((t*(t^t%255)|(t>>4))>>1):(t>>3)|((t&8192)?t<<2:t))); // by skurk (raer's version)
    }
    else if(a0_pot>560 && a0_pot<640){
      putb( (t>>7|t|t>>6)*10+4*(t&t>>13|t>>6)); // by viznut, xpansive, varjohukka
    }
    else if(a0_pot>640 && a0_pot<720){
      putb(t*5&(t>>7)|t*3&(t*4>>10)); // by miiro
    }
    else if(a0_pot>720 && a0_pot<800){
      putb((t|(t>>9|t>>7))*t&(t>>11|t>>9)  ); // by red
    }
    else if(a0_pot>800 && a0_pot<880){
      putb(v=(v>>1)+(v>>4)+t*(((t>>16)|(t>>6))&(69&(t>>9)))  ); // by pyryp
    }
    else if(a0_pot>880 && a0_pot<960){
      putb((t>>a0_pot|t|t>>(t>>16))*10+((t>>11)&7)  );  //by viznut
    }
    else if(a0_pot>960){
      putb((t*(4|7&t>>13)>>((~t>>11)&1)&128) + ((t)*(t>>11&t>>13)*((~t>>9)&3)&127)); // by stimmer
    }
    digitalWrite(5,LOW);

  }






}


