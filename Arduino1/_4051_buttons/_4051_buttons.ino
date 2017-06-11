int r0 = 0;      //value of select pin at the 4051 (s0)
int r1 = 0;      //value of select pin at the 4051 (s1)
int r2 = 0;      //value of select pin at the 4051 (s2)
int count = 0;   //which y pin we are selecting

int bit0=26;
int bit1=28;
int bit2=30;

int LDR=22;                     // PIN analógico de la LDR
int LDR2=24;                     // PIN analógico de la LDR
int val = 0;                   // Vble que almacenará los valores de la LDR

int buttonArray[16][2]={
{3,LDR},
{3,LDR2},  
{2,LDR},
{2,LDR2},  
{1,LDR},
{1,LDR2},  
{0,LDR},
{0,LDR2},  
{7,LDR},
{7,LDR2},  
{6,LDR},
{6,LDR2},  
{5,LDR},
{5,LDR2},  
{4,LDR},
{4,LDR2}
};  

void setup(){
  Serial.begin(9600);                              
  pinMode(bit0, OUTPUT);    // s0
  pinMode(bit1, OUTPUT);    // s1
  pinMode(bit2, OUTPUT);    // s2
}

int readButton(int value, int ld){
    r0 = bitRead(value,0);
    r1 = bitRead(value,1);
    r2 = bitRead(value,2);   

    digitalWrite(bit0, r0);
    digitalWrite(bit1, r1);
    digitalWrite(bit2, r2);

    val = digitalRead(ld);        // Lee el valor del sensor LDR      
    Serial.print("Valor de ");
    Serial.print(value);
    Serial.print(" es: ");    
    Serial.println(val);    
    return val;   
}


void loop () {  
  for(int i=0;i<16;i++){
    readButton(buttonArray[i][0],buttonArray[i][1]);
  }  
  delay(1000);
}
