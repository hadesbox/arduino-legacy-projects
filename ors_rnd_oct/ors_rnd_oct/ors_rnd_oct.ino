/*
Random piano Sequencer 
 
 Notes on this version: 
 - Sequencer looping
 
 Knobs: 
 0 = TEMPO
 1 = number of MODES changed each 128 note cycle
 2 = mode selection 
 5 & 6 = min and max velocity
 3 = loop length 
 
Schematic in pot_box_schematic 

/*
GLOBAL VARIABLES 
*/
byte MODE_CHOICE;
#define MODE_COUNT 14

byte ODDS_CHOICE;
#define ODDS_COUNT 6

byte noteplay;
#define ARRAY_SIZE 128

int TEMPO  = 60;
int MAX_TEMPO=0;
int MIN_TEMPO = 200;

int DENSITY =100; // 100 = average, 200 = low, 50 = high
int MAX_DENSITY = 200;
int MIN_DENSITY = 10;

boolean FILL=true;
boolean DEBUG = false; 
boolean PRINT_SETTINGS = true; 

#define greenLED1 7
#define clockout 3
const int clkIn = 2;           // the digital (clock) input

//  variables for interrupt handling of the clock input
volatile int clkState = LOW;
int clockTick[2] = {1, 1};

#define VOICE_COUNT 16 // maximum polyphony 

byte LONG_SHORT;
byte BASE_time; // multiplier for note lengths 

// holder for the SEQUENCE 
byte SEQUENCE[3][ARRAY_SIZE]; //0=note 1=octave 2=velocity  

// arrays to manage note length/endings 
byte NOTE_ON[VOICE_COUNT];
unsigned long NOTE_OFF[VOICE_COUNT];

// Length of the notes
int notelength; 
int lengthVal;
int MAX_LENGTH= 10;
int MIN_LENGTH = 1;


/*
LOOKUP TABLES 
*/

//QUANTISATION 
byte MODES[MODE_COUNT][12]= {
  {0,1,2,3,4,5,6,7,8,9,10,11    },   // chromatic 
  {0,2,4,6,8,10,12    }, //whole tone 
  { 0,3,5,6,7,10,12    }, // blues 
  { 0,1,3,5,7,9,10,12    }, // javanese
  { 0,2,3,5,7,8,10,12    }, // minor 
  { 0,2,3,5,7,8,11,12    }, // harmonic minor 
  {0,2,4,5,6,8,10,12    }, // arabian 
  { 0,2,4,5,8,9,11,12    }, // harmonic major 
  { 0,1,4,5,6,8,11,12    }, // persian 
  {  0,1,4,5,6,9,10,12   }, // oriental 
  {   0,1,4,5,7,8,10,12  }, // jewish 
  {   0,1,4,5,7,8,11,12  }, //  gypsy
  {   0,2,3,5,7,9,10,12  }, // dorian 
  {  0,2,4,5,7,8,11,12   }, // ethiopian 
 
//  {     }, //  
  
  
};  

/* Rhythm system: 
0 = 4/4
1 = clock divisions 
2 = samba
3 = 3/4
4 = cuban
5 = bossanova 
*/

byte ODDS[ODDS_COUNT][ARRAY_SIZE]={
{
95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5
},{
95,5,95,5,95,5,95,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,5,5,5,5,95,5,5,5,5,5,5,5,95,5,5,5,5,5,5,5,95,5,5,5,5,5,5,5,95,95,95,95,95,95,95,95,95,5,95,5,95,5,95,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,95,5,5,5,5,5,5,5,95,5,5,5,5,5,5,5,95,5,5,5,5,5,5,5,95,5,5,5,5,5,5,5,95,95,95,95,95,95,95,95,
},{
95,5,95,5,5,95,5,95,5,95,5,5,95,5,95,5,95,5,95,5,5,95,5,95,5,95,5,5,95,5,95,5,95,5,95,5,5,95,5,95,5,95,5,5,95,5,95,5,95,5,95,5,5,95,5,95,5,95,5,5,95,5,95,5,95,5,95,5,5,95,5,95,5,95,5,5,95,5,95,5,95,5,95,5,5,95,5,95,5,95,5,5,95,5,95,5,95,5,95,5,5,95,5,95,5,95,5,5,95,5,95,5,95,5,95,5,5,95,5,95,5,95,5,5,95,5,95,5,
},{
90,20,20,90,20,20,90,20,20,90,20,20,90,20,20,90,20,20,90,20,20,90,20,20,90,20,20,90,20,20,20,20,90,20,20,90,20,20,90,20,20,90,20,20,90,20,20,90,20,20,90,20,20,90,20,20,90,20,20,90,20,20,20,20,90,20,20,90,20,20,90,20,20,90,20,20,90,20,20,90,20,20,90,20,20,90,20,20,90,20,20,90,20,20,20,20,90,20,20,90,20,20,90,20,20,90,20,20,90,20,20,90,20,20,90,20,20,90,20,20,90,20,20,90,20,20,20,20
},{
95,5,95,95,5,95,95,5,95,5,95,95,5,95,95,5,95,5,95,95,5,95,95,5,95,5,95,95,5,95,95,5,95,5,95,95,5,95,95,5,95,5,95,95,5,95,95,5,95,5,95,95,5,95,95,5,95,5,95,95,5,95,95,5,95,5,95,95,5,95,95,5,95,5,95,95,5,95,95,5,95,5,95,95,5,95,95,5,95,5,95,95,5,95,95,5,95,5,95,95,5,95,95,5,95,5,95,95,5,95,95,5,95,5,95,95,5,95,95,5,95,5,95,95,5,95,95,5,
},{
95,5,5,95,5,5,95,5,5,5,95,5,5,95,5,5,95,5,5,95,5,5,95,5,5,5,95,5,5,95,5,5,95,5,5,95,5,5,95,5,5,5,95,5,5,95,5,5,95,5,5,95,5,5,95,5,5,5,95,5,5,95,5,5,95,5,5,95,5,5,95,5,5,5,95,5,5,95,5,5,95,5,5,95,5,5,95,5,5,5,95,5,5,95,5,5,95,5,5,95,5,5,95,5,5,5,95,5,5,95,5,5,95,5,5,95,5,5,95,5,5,5,95,5,5,95,5,5,  
}};


void setup() {
  //  Set MIDI baud rate: 
  Serial.begin(31250); // midi 
   randomSeed((analogRead(9)+analogRead(10)+analogRead(11))/3);
 // set up the digital led
 pinMode(greenLED1,OUTPUT);
 // set up the digital (clock) output
 pinMode(clockout,OUTPUT);
 // set up the digital (clock) input
 pinMode(clkIn, INPUT);
   
 attachInterrupt(0, isr, RISING);
}
  



/*
MAIN LOOP 
*/

void loop() {


  byte playsteps = 16; // how many MODES to play in each loop 


  // FIRST PLAY, FILL UP THE SEQUENCE  
  if(FILL == true)
  {

    // CHOOSE INITIAL VARIABLES 
  
    // Random or fixed scale selection 
    MODE_CHOICE=random(MODE_COUNT);
    //MODE_CHOICE=3;

    // Random or fixed rhythm selection 
    ODDS_CHOICE = random(ODDS_COUNT);
    //MODE_CHOICE = 4;

    // select density
    DENSITY = (random(MAX_DENSITY-MIN_DENSITY))+MIN_DENSITY;

    //EXPERIMENTAL 
    // Choose divider for long/short stresses 
    LONG_SHORT = random(16);
    BASE_time = random(16);


    // FILL THE LOOP 
    for(int seqstep=0;seqstep<ARRAY_SIZE;seqstep++)
    {
      byte newnote=random(7);
      byte newoctave = random(5)+3;
      if(random(DENSITY)<ODDS[ODDS_CHOICE][seqstep])
      {
        SEQUENCE[0][seqstep]= newnote; // note 
        SEQUENCE[1][seqstep]= newoctave;  // octave 
        SEQUENCE[2][seqstep]= random(ODDS[ODDS_CHOICE][seqstep]+27); // velocity 
      }
    }
    
    FILL = false;
  }
  else
  {
    // AFTER FIRST FILL, STEP THROUGH THE SEQUENCE  
    
    for(int seqstep=0;seqstep<playsteps;seqstep++)
    {
      byte randomNote = 0;
      // ROUTINES TO CHECK THE KNOBS  
      
      // ClockIn
      // pot zero = TEMPO 
      TEMPO = map(analogRead(0),0,1024,MIN_TEMPO,MAX_TEMPO);
      
      // Knob 0
      // NOTELENGTH SETTING
      lengthVal = map(analogRead(3),0,1024,MIN_LENGTH,MAX_LENGTH);
      notelength = random (lengthVal) * TEMPO;
     
      // Knob 1
      // SCALE SELECTION KNOB 
      MODE_CHOICE = map(analogRead(4),0,1024,0,MODE_COUNT);
            
      // Knob 2
      // LOOP KNOB 
      playsteps = (analogRead(5)/128)*8;
            
      // Knob 3 and 4
      // VELOCITY HIGH/LOW KNOBS 
      byte velocity = SEQUENCE[2][seqstep];
      if (velocity>0)
      {
        byte minvelocity = map(analogRead(6),0,1024,1,127);
        byte maxvelocity = map(analogRead(7),0,1024,minvelocity,127);
        if (velocity<=minvelocity){velocity=minvelocity;};
        if (velocity>=maxvelocity){velocity=maxvelocity;};
      }
      
      
      // Knob 6 - Octave
      byte octaveRange = map (analogRead(1),0,1024,0,7);
      byte octaveCenter = map (analogRead(2),0,1024,0,7);
      byte octaveWidth = random (octaveRange);
      byte octave = octaveCenter + octaveWidth; 
     
      if (octave > 8) octave = 8;
      
       
      // PLAY THE NOTE        
      playNote(0x90, quantize(MODE_CHOICE, SEQUENCE[0][seqstep], octave) ,velocity,notelength);
      
      if (seqstep%4==0)
      {
        digitalWrite(greenLED1, HIGH);
        digitalWrite(clockout, HIGH);
      }
      else
      {
        digitalWrite(greenLED1, LOW);
        digitalWrite(clockout, LOW);
      }
        
      noteKill();
      delay(TEMPO);
      
      
    }  

  } 
  
}


/*
FUNCTIONS 
*/

// midi note player 

void playNote(byte cmd, byte pitch, byte velocity, int duration) 
{
  unsigned long time = millis();

  // find an empty note slot 
  boolean found_slot = false;

  for (int i=0;i<VOICE_COUNT;i++)
  {
    if (NOTE_ON[i] == 0)
    {
      NOTE_ON[i] = pitch;
      NOTE_OFF[i] = time+duration;
      found_slot = true;
      break;
    }
  }


  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);

  
}

// Check for held Notes that should be killed, and kill them. 

void noteKill(){
unsigned long time=millis();
for (int i=0;i<VOICE_COUNT;i++){
if (NOTE_ON[i]>0 && NOTE_OFF[i]<time){  // if note value>0 and note off time < time
 
 byte pitch = NOTE_ON[i];
 byte velocity = 0;
  Serial.write(0x90);
  Serial.write(pitch);
  Serial.write(velocity);
  
      NOTE_ON[i]=0; //wipe NOTE_ON entry to signal no active note
}}}


// Quantizer 

byte quantize(int scale, int note, int octave){
  return octave*12+MODES[scale][note]; 
}


//  =================== convenience routines ===================

//  isr() - quickly handle interrupts from the clock input
//  ------------------------------------------------------
void isr()
{
  // Note: you don't want to spend a lot of time here, because
  // it interrupts the activity of the rest of your program.
  // In most cases, you just want to set a variable and get
  // out.
  clkState = HIGH;
}







