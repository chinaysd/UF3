#include "tim1.h"


void Tim1_Init(void)
{
	TMCON = 0X07;    //------111 ;Timer0��Tiemr1��Tiemr2ѡ��ʱ��Fsys
	//T1����
	TL1 = (65536 - 48000)%256;   //���ʱ�䣺ʱ��ΪFsys����24000*��1/Fsys��=1ms;
	TH1 = (65536 - 48000)/256;
	TR1 = 0;
	ET1 = 1;//��ʱ��1����
	TR1 = 1;//�򿪶�ʱ��1
	
}