/*
  Anushri.h - Anushri Anushri for Orsini CUnt
*/
#ifndef Anushri_h
#define Anushri_h

#include "Arduino.h"


#define ARP_MODES 14

class Anushri
{
  public:
    Anushri();
    void up(byte*, byte*, byte);
    void down(byte*, byte*, byte);
    void upDown(byte*, byte*, byte);
	void randomArp(byte*, byte*, byte);
	void setVelUp(byte*, byte);
	void setVelDown(byte*, byte);
	void setVel(byte*, int, int, int, float , float);
	void setVelVal(byte*, byte);
	void setDurRand(byte*, byte);
     void setDurVal(byte*, byte);
    void makeDurations(byte*, byte);
    void makeVelocities(byte*, int, int ,int, float, float);
    void setArgument(byte, int);
       byte seqSelect;
       int Position ;
        int Sector ;                          // I have no idea what I'm doing... but it works... in a way.
float BDrum ;
float SDrum ;
float HHats ;
int BDcluster1[16]; 
int SDcluster1[16]; 
int HHcluster1[16]; 
int BDcluster2[16]; 
int SDcluster2[16]; 
int HHcluster2[16]; 
int BDcluster3[16]; 
int SDcluster3[16]; 
int HHcluster3[16]; 
int BDcluster4[16]; 
int SDcluster4[16]; 
int HHcluster4[16]; 
int BDcluster5[16]; 
int SDcluster5[16]; 
int HHcluster5[16]; 
int BDcluster6[16]; 
int SDcluster6[16]; 
int HHcluster6[16]; 

int BDcluster7[16]; 
int SDcluster7[16]; 
int HHcluster7[16]; 

int BDcluster8[16]; 
int SDcluster8[16]; 
int HHcluster8[16]; 

int BDcluster9[16]; 
int SDcluster9[16]; 
int HHcluster9[16]; 
    void makeSequence(byte*, byte*,  byte,  byte, byte, byte, byte);  	
  //   void makeVelocities(byte*, byte);  
//     void makeDurations(byte*,  byte);  		
       
    

  //  void updateSequence(byte*, byte*,  byte, byte, byte, byte, byte);  	     
    volatile byte arp_loop_size;
    volatile byte offset ;
    int MAP_VALUES[6][2]; //MIN , MAX for mapping the arguments;
     
    //WILL IT BE EVER CHANGING?
   	bool inLoop;
   	
  private:
	int pin;
	
	
	
	
		
};

#endif