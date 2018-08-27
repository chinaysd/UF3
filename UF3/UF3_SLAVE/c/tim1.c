#include "tim1.h"


void Tim1_Init(void)
{
   	//TMCON=0x07;							//------111 ;Timer0?Tiemr1?Tiemr2????Fsys
	  //TMOD=0x11;  						//0001 0001  ;Timer0?Timer1??????1  
		TH0=(65536-6000)/256;       			//?????24M???Fsys?24M*6000=250us;
	  TH0=(65536-6000)%256;
 	  TR0=0;					
   	ET0=1;								//Timer0??
   	TR0=1;
}