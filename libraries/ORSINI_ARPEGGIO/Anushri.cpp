/*
  Anushri.cpp - Global Anushri for Orsini CUnt

*/


#include "Anushri.h"



Anushri::Anushri()
{
        arp_loop_size=16;
        offset=0;
        MAP_VALUES[0][0]=2; //note MIN
        MAP_VALUES[0][1]=9; //note MAX
		 
        MAP_VALUES[1][0]=0; //direction MIN
        MAP_VALUES[1][1]=4; //direction MAX
		 
        MAP_VALUES[2][0]=0; //seqSelect MIN
        MAP_VALUES[2][1]=127; //SeqSelect MAX
		 
        MAP_VALUES[3][0]=1; //loop  MIN
        MAP_VALUES[3][1]=15; //loop  MAX
		 
        MAP_VALUES[4][0]=0; //offset MIN
        MAP_VALUES[4][1]=15; //offset MAX
        
        MAP_VALUES[5][0]=1; //divclokc MIN
        MAP_VALUES[5][1]=16; //divclock MAX
        
        /// WHEN SHIFT IS PRESSED
        MAP_VALUES[6][0]=0; //bd MIN
        MAP_VALUES[6][1]=255; //bd MAX
        
        MAP_VALUES[7][0]=0; //sd MIN
        MAP_VALUES[7][1]=255; //sd MAX
        
        MAP_VALUES[2][0]=0; //hh MIN
        MAP_VALUES[8][1]=255; //hh MAX
        
		MAP_VALUES[9][0]=-100; //xmap MIN
        MAP_VALUES[9][1]=100; //xmpa MAX
        
        MAP_VALUES[10][0]=-100; //offset MIN
        MAP_VALUES[10][1]=100; //offset MAX
        
        MAP_VALUES[11][0]=-100; //vel MIN
        MAP_VALUES[11][1]=100; //vel MAX  
        
        int BDcluster1[16] = {236,   0,   0, 138,   0,   0, 208,   0,  58,  28, 174,   0, 104,   0,  58,   0};
int SDcluster1[16] = { 10,  66,   0,   8, 232,   0,   0,  38,   0, 148,   0,  14, 198,   0, 114,   0};
int HHcluster1[16] = {154,  98, 244,  34, 160, 108, 192,  24, 160,  98, 228,  20, 160,  92, 194,  44};

int BDcluster2[16] = {246,  10,  88,  14, 214,  10,  62,   8, 250,   8,  40,  14, 198,  14, 160, 120};
int SDcluster2[16] = { 16, 186,  44,  52, 230,  12, 116,  18,  22, 154,  10,  18, 246,  88,  72,  58};
int HHcluster2[16] = {136, 130, 220,  64, 130, 120, 156,  32, 128, 112, 220,  32, 126, 106, 184,  88};

int BDcluster3[16] = {224,   0,  98,   0,   0,  68,   0, 198,   0, 136, 174,   0,  46,  28, 116,  12};
int SDcluster3[16] = {  0,  94,   0,   0, 224, 160,  20,  34,   0,  52,   0,   0, 194,   0,  16, 118};
int HHcluster3[16] = {228, 104, 138,  90, 122, 102, 108,  76, 196, 160, 182, 160,  96,  36, 202,  22};

int BDcluster4[16] = {240, 204,  42,   0,  86, 108,  66, 104, 190,  22, 224,   0,  14, 148,   0,  36};
int SDcluster4[16] = {  0,   0, 112,  62, 232, 180,   0,  34,   0,  48,  26,  18, 214,  18, 138,  38};
int HHcluster4[16] = {232, 186, 224, 182, 108,  60,  80,  62, 142,  42,  24,  34, 136,  14, 170,  26};

int BDcluster5[16] = {228,  14,  36,  24,  74,  54, 122,  26, 186,  14,  96,  34,  18,  30,  48,  12};
int SDcluster5[16] = {  2,   0,  46,  38, 226,   0,  68,   0,   2,   0,  92,  30, 232, 166, 116,  22};
int HHcluster5[16] = { 64,  12, 236, 128, 160,  30, 202,  74,  68,  28, 228, 120, 160,  28, 188,  82};

int BDcluster6[16] = {236,  24,  14,  54,   0,   0, 106,   0, 202, 220,   0, 178,   0, 160, 140,   8};
int SDcluster6[16] = {134,  82, 114, 160, 224,   0,  22,  44, 202, 220,   0, 178,   0, 160, 140,   8};
int HHcluster6[16] = {174,  86, 230,  58, 124,  64, 210,  58, 160,  76, 224,  22, 124,  34, 194,  26};

int BDcluster7[16] = {236,   0, 226,   0,   0,   0, 160,   0,   0,   0, 188,   0,   0,   0, 210,   0};
int SDcluster7[16] = {134,  82, 114, 160, 224,   0,  22,  44,  66,  40,   0,   0, 192,  22,  14, 158};
int HHcluster7[16] = {174,  86, 230,  58, 124,  64, 210,  58, 160,  76, 224,  22, 124,  34, 194,  26};

int BDcluster8[16] = {226,   0,  42,   0,  66,   0, 226,  14, 238,   0, 126,   0,  84,  10, 170,  22};
int SDcluster8[16] = {  0,   0,  54,   0, 182,   0, 128,  36,   6,  10,  84,  10, 238,   8, 158,  26};
int HHcluster8[16] = {240,  46, 218,  24, 232,   0,  96,   0, 240,  28, 204,  30, 214,   0,  64,   0};

int BDcluster9[16] = {228,   0, 212,   0,  14,   0, 214,   0, 160,  52, 218,   0,   0,   0, 134,  32};
int SDcluster9[16] = {104,   0,  22,  84, 230,  22,   0,  58,   6,   0, 138,  20, 220,  18, 176,  34};
int HHcluster9[16] = {230,  26,  52,  24,  82,  28,  52, 118, 154,  26,  52,  24, 202, 212, 186, 196}; 

byte seqSelect=1;
byte Sector;
}
/////SEQUNCIN NOTE
void Anushri::up(byte *seq, byte *scale, byte scaleSize){
	for(int i=0;i<16;i++){
		seq[i]=scale[(offset+(i%arp_loop_size))%(scaleSize)];
		
		
		
		//seq[i]=scale[random(16) ];
	}
}
void Anushri::down(byte *seq, byte *scale,  byte scaleSize){
	for(int i=0;i<16;i++){
				seq[i]=scale[((offset+(15-i))%arp_loop_size)%scaleSize];
	}
}

void Anushri::upDown(byte *seq, byte *scale,  byte scaleSize){
	for(int i=0;i<arp_loop_size;i++){
		seq[i]=scale[ ((offset+(i))%arp_loop_size) % scaleSize  ];
	}
	for(int i=arp_loop_size;i<15;i++){
		seq[i]=scale[ (offset+(	-i)%arp_loop_size) % scaleSize ];
	}
}

void Anushri::randomArp(byte *seq, byte *scale,  byte scaleSize){
	for(int i=0;i<16;i++){
		seq[i]=scale[(offset+random(15-offset)) % scaleSize];
	}
}

void  Anushri::makeSequence( byte *sequence, byte *scal, byte scalSize, byte direction, byte octave, byte arp_size, byte offst){
 arp_loop_size = arp_size;
 offset= offst;
 seqSelect=octave;
       
 switch(direction){
 case 0:
 
			up( sequence, scal,   scalSize);
		break;
		case 1:
			down( sequence, scal, scalSize );
		break;
		case 2:
			upDown( sequence, scal , scalSize);
		break;
		case 3:
			randomArp( sequence, scal, scalSize );
		break;

}



}



//VELOCITIES
void Anushri::setVel(byte *seq,  int BDfreq, int SDfreq, int HHfreq, float Xmap, float Ymap){
	
   // 
//    //BDfreq = analogRead(0);                              // read bass drum density pot
//    BDfreq = map(analogRead(0), 0, 1023, 0, 255);                // remap it to values similar to those in cluster configurations
//    SDfreq = analogRead(1);                              // read snare drum density pot
//    SDfreq = map(SDfreq, 0, 1023, 0, 255);                // remap it to values similar to those in cluster configurations
//    HHfreq = analogRead(2);                              // read hi hat density pot
//    HHfreq = map(HHfreq, 0, 1023, 0, 255);                // remap it to values similar to those in cluster configurations
// 
//    Xmap = analogRead(3);                                // read the X-pot for cluster navigation
//    Xmap = map(Xmap, 0, 1023, -100, 100);                 // remap around zero
//    Ymap = analogRead(4);                                // read the Y-pot for cluster navigation
//    Ymap = map(Ymap, 0, 1023, -100, 100);                 // remap around zero
//          
//    if (Xmap < 0 && Ymap < 0) Sector = 1;
//    if (Xmap < 0 && Ymap > 0) Sector = 2;
//    if (Xmap >= 0 && Ymap >= 0) Sector = 3;
//    if (Xmap >= 0 && Ymap <= 0) Sector = 4;               // determine sector - which 4 clusters do we want to interpolate
// 
//    Xmap = abs(Xmap / 100);
//    Ymap = abs(Ymap / 100);                               // get rid off negative values and make it smaller
// 
//    
//    if (Sector == 1) {
//      SDrum = ( ( (SDcluster1[Position] * Xmap) + (SDcluster2[Position] * (1 - Xmap) ) ) * Ymap ) + ( ( (SDcluster4[Position] * Xmap) + (SDcluster5[Position] * (1 - Xmap) ) ) * ( 1 - Ymap) );
//      BDrum = ( ( (BDcluster1[Position] * Xmap) + (BDcluster2[Position] * (1 - Xmap) ) ) * Ymap ) + ( ( (BDcluster4[Position] * Xmap) + (BDcluster5[Position] * (1 - Xmap) ) ) * ( 1 - Ymap) );
//      HHats = ( ( (HHcluster1[Position] * Xmap) + (HHcluster2[Position] * (1 - Xmap) ) ) * Ymap ) + ( ( (HHcluster4[Position] * Xmap) + (HHcluster5[Position] * (1 - Xmap) ) ) * ( 1 - Ymap) );
//    }
// 
//    if (Sector == 2) {
//      SDrum = ( ( (SDcluster4[Position] * Xmap) + (SDcluster5[Position] * (1 - Xmap) ) ) * (1 - Ymap ) ) + ( ( (SDcluster7[Position] * Xmap) + (SDcluster8[Position] * (1 - Xmap) ) ) * Ymap );
//      BDrum = ( ( (BDcluster4[Position] * Xmap) + (BDcluster5[Position] * (1 - Xmap) ) ) * (1 - Ymap ) ) + ( ( (BDcluster7[Position] * Xmap) + (BDcluster8[Position] * (1 - Xmap) ) ) * Ymap );
//      HHats = ( ( (HHcluster4[Position] * Xmap) + (HHcluster5[Position] * (1 - Xmap) ) ) * (1 - Ymap ) ) + ( ( (HHcluster7[Position] * Xmap) + (HHcluster8[Position] * (1 - Xmap) ) ) * Ymap );
//    }
// 
//    if (Sector == 3) {
//      SDrum = ( ( (SDcluster5[Position] * ( 1 - Xmap ) ) + (SDcluster6[Position] * Xmap ) ) * ( 1 - Ymap ) ) + ( ( (SDcluster8[Position] * ( 1 - Xmap )) + (SDcluster9[Position] * Xmap ) ) * Ymap );
//      BDrum = ( ( (BDcluster5[Position] * ( 1 - Xmap ) ) + (BDcluster6[Position] * Xmap ) ) * ( 1 - Ymap ) ) + ( ( (BDcluster8[Position] * ( 1 - Xmap )) + (BDcluster9[Position] * Xmap ) ) * Ymap );
//      HHats = ( ( (HHcluster5[Position] * ( 1 - Xmap ) ) + (HHcluster6[Position] * Xmap ) ) * ( 1 - Ymap ) ) + ( ( (HHcluster8[Position] * ( 1 - Xmap )) + (HHcluster9[Position] * Xmap ) ) * Ymap );
//    }   
// 
//    if (Sector == 4) {
//      SDrum = ( ( (SDcluster2[Position] * ( 1 - Xmap ) ) + (SDcluster3[Position] * Xmap ) ) * Ymap ) + ( ( (SDcluster5[Position] * ( 1 - Xmap ) ) + (SDcluster6[Position] * Xmap ) ) * ( 1 - Ymap) );
//      BDrum = ( ( (BDcluster2[Position] * ( 1 - Xmap ) ) + (BDcluster3[Position] * Xmap ) ) * Ymap ) + ( ( (BDcluster5[Position] * ( 1 - Xmap ) ) + (BDcluster6[Position] * Xmap ) ) * ( 1 - Ymap) );
//      HHats = ( ( (HHcluster2[Position] * ( 1 - Xmap ) ) + (HHcluster3[Position] * Xmap ) ) * Ymap ) + ( ( (HHcluster5[Position] * ( 1 - Xmap ) ) + (HHcluster6[Position] * Xmap ) ) * ( 1 - Ymap) );
//    }
// 
//   ///////////////////////////////// above are the equations for interpolating between values. Nothing fancy.
//     switch(seqSelect){
//     case 1:
//         if (BDrum > BDfreq) seq[i] = map((offset+i) % arp_loop_size, 0, 16, 0, vel) ; else 0;    
//         break;
//     case 2:
//         if (SDrum > SDfreq) seq[i] = map((offset+i) % arp_loop_size, 0, 16, 0, vel) ; else 0;    
//         break;
//     case 3:
//         if (HHats > HHfreq) seq[i] = map((offset+i) % arp_loop_size, 0, 16, 0, vel) ; else 0;    
//         break;
//     }

  
   
}

void Anushri::setVelUp(byte *seq, byte vel){
	for(int i=0;i<16;i++){
		seq[i]=map((offset+i) % arp_loop_size, 0, 16, 0, vel) ;
	}

}

void Anushri::setVelDown(byte *seq, byte vel){
	for(int i=0;i<16;i++){
		seq[i]=map((offset+i) % arp_loop_size, 0, 16, vel, 0) ;
	}

}
void Anushri::setVelVal(byte *seq, byte vel){
	for(int i=0;i<16;i++){
		seq[i]=vel;
	}

}


///DURATIONS
void Anushri::setDurVal(byte *seq, byte dur){
	for(int i=0;i<16;i++){
		seq[i]=dur ;
	}

}

void Anushri::setDurRand(byte *seq, byte dur){
	for(int i=0;i<16;i++){
		seq[i]=dur ;
	}
}

void  Anushri::makeVelocities( byte *sequence, int BDfreq, int SDfreq, int HHfreq, float Xmap, float Ymap){
	
   // //BDfreq = analogRead(0);                              // read bass drum density pot
//    BDfreq = map(analogRead(0), 0, 1023, 0, 255);                // remap it to values similar to those in cluster configurations
//    SDfreq = analogRead(1);                              // read snare drum density pot
//    SDfreq = map(SDfreq, 0, 1023, 0, 255);                // remap it to values similar to those in cluster configurations
//    HHfreq = analogRead(2);                              // read hi hat density pot
//    HHfreq = map(HHfreq, 0, 1023, 0, 255);                // remap it to values similar to those in cluster configurations
// 
//    Xmap = analogRead(3);                                // read the X-pot for cluster navigation
//    Xmap = map(Xmap, 0, 1023, -100, 100);                 // remap around zero
//    Ymap = analogRead(4);                                // read the Y-pot for cluster navigation
//    Ymap = map(Ymap, 0, 1023, -100, 100);                 // remap around zero
    for(int i=0;i<16;i++){
	Position=i;
   if (Xmap < 0 && Ymap < 0) Sector = 1;
   if (Xmap < 0 && Ymap > 0) Sector = 2;
   if (Xmap >= 0 && Ymap >= 0) Sector = 3;
   if (Xmap >= 0 && Ymap <= 0) Sector = 4;               // determine sector - which 4 clusters do we want to interpolate

   Xmap = abs(Xmap / 100);
   Ymap = abs(Ymap / 100);                               // get rid off negative values and make it smaller

   
   if (Sector == 1) {
     SDrum = ( ( (SDcluster1[Position] * Xmap) + (SDcluster2[Position] * (1 - Xmap) ) ) * Ymap ) + ( ( (SDcluster4[Position] * Xmap) + (SDcluster5[Position] * (1 - Xmap) ) ) * ( 1 - Ymap) );
     BDrum = ( ( (BDcluster1[Position] * Xmap) + (BDcluster2[Position] * (1 - Xmap) ) ) * Ymap ) + ( ( (BDcluster4[Position] * Xmap) + (BDcluster5[Position] * (1 - Xmap) ) ) * ( 1 - Ymap) );
     HHats = ( ( (HHcluster1[Position] * Xmap) + (HHcluster2[Position] * (1 - Xmap) ) ) * Ymap ) + ( ( (HHcluster4[Position] * Xmap) + (HHcluster5[Position] * (1 - Xmap) ) ) * ( 1 - Ymap) );
   }

   if (Sector == 2) {
     SDrum = ( ( (SDcluster4[Position] * Xmap) + (SDcluster5[Position] * (1 - Xmap) ) ) * (1 - Ymap ) ) + ( ( (SDcluster7[Position] * Xmap) + (SDcluster8[Position] * (1 - Xmap) ) ) * Ymap );
     BDrum = ( ( (BDcluster4[Position] * Xmap) + (BDcluster5[Position] * (1 - Xmap) ) ) * (1 - Ymap ) ) + ( ( (BDcluster7[Position] * Xmap) + (BDcluster8[Position] * (1 - Xmap) ) ) * Ymap );
     HHats = ( ( (HHcluster4[Position] * Xmap) + (HHcluster5[Position] * (1 - Xmap) ) ) * (1 - Ymap ) ) + ( ( (HHcluster7[Position] * Xmap) + (HHcluster8[Position] * (1 - Xmap) ) ) * Ymap );
   }

   if (Sector == 3) {
     SDrum = ( ( (SDcluster5[Position] * ( 1 - Xmap ) ) + (SDcluster6[Position] * Xmap ) ) * ( 1 - Ymap ) ) + ( ( (SDcluster8[Position] * ( 1 - Xmap )) + (SDcluster9[Position] * Xmap ) ) * Ymap );
     BDrum = ( ( (BDcluster5[Position] * ( 1 - Xmap ) ) + (BDcluster6[Position] * Xmap ) ) * ( 1 - Ymap ) ) + ( ( (BDcluster8[Position] * ( 1 - Xmap )) + (BDcluster9[Position] * Xmap ) ) * Ymap );
     HHats = ( ( (HHcluster5[Position] * ( 1 - Xmap ) ) + (HHcluster6[Position] * Xmap ) ) * ( 1 - Ymap ) ) + ( ( (HHcluster8[Position] * ( 1 - Xmap )) + (HHcluster9[Position] * Xmap ) ) * Ymap );
   }   

   if (Sector == 4) {
     SDrum = ( ( (SDcluster2[Position] * ( 1 - Xmap ) ) + (SDcluster3[Position] * Xmap ) ) * Ymap ) + ( ( (SDcluster5[Position] * ( 1 - Xmap ) ) + (SDcluster6[Position] * Xmap ) ) * ( 1 - Ymap) );
     BDrum = ( ( (BDcluster2[Position] * ( 1 - Xmap ) ) + (BDcluster3[Position] * Xmap ) ) * Ymap ) + ( ( (BDcluster5[Position] * ( 1 - Xmap ) ) + (BDcluster6[Position] * Xmap ) ) * ( 1 - Ymap) );
     HHats = ( ( (HHcluster2[Position] * ( 1 - Xmap ) ) + (HHcluster3[Position] * Xmap ) ) * Ymap ) + ( ( (HHcluster5[Position] * ( 1 - Xmap ) ) + (HHcluster6[Position] * Xmap ) ) * ( 1 - Ymap) );
   }

  ///////////////////////////////// above are the equations for interpolating between values. Nothing fancy.
    switch(seqSelect){
    case 1:
        if (BDrum > BDfreq) sequence[i] = map((offset+i) % arp_loop_size, 0, 16, 0, 127) ; else 0;    
        break;
    case 2:
        if (SDrum > SDfreq) sequence[i] = map((offset+i) % arp_loop_size, 0, 16, 0, 127) ; else 0;    
        break;
    case 3:
        if (HHats > HHfreq) sequence[i] = map((offset+i) % arp_loop_size, 0, 16, 0, 127) ; else 0;    
        break;
    }
    }

}

void  Anushri::makeDurations( byte *sequence, byte dur){
	setDurVal(sequence, dur);
	//byte for_case=map(vel, 0, 127, 0, 3); //if read > 127/4 the val is good one 
// 	switch(par5){
// 			 case 0:
// 				setVelVal( sequence, dur );
// 			break;
// 			case 1:
// 				setVelRand( sequence, dur );
// 			break;
// 			case 2:
// 				setVelUp( sequence, dur );
// 			break;
// 			case 3:
// 				setVelDown( sequence, dur );
// 			break;
// 
// 	}
}
// void  Anushri::updateSequence(byte *sequence, byte *scal, byte direction, byte arp_size, byte scl_shft, byte par4 , byte par5){
// 	switch(direction){
// 			case 0:
// 				up( sequence, scal);
// 			break;
// 			case 1:
// 				down( sequence, scal);
// 			break;
// 			case 2:
// 				upDown( sequence, scal);
// 			break;
// 			case 3:
// 				randomArp( sequence, scal);
// 			break;
// 
// 	}
// 
// }



// byte Anushri::quantize(int scale, int note, int octave){
//     return octave*12+MODES[scale][note]; 
// 
// }
