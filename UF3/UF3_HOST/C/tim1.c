#include "tim1.h"


void Tim1_Init(void)
{
	TMCON = 0X07;    //------111 ;Timer0、Tiemr1和Tiemr2选择时钟Fsys
	//T1设置
	TL1 = (65536 - 48000)%256;   //溢出时间：时钟为Fsys，则24000*（1/Fsys）=1ms;
	TH1 = (65536 - 48000)/256;
	TR1 = 0;
	ET1 = 1;//定时器1允许
	TR1 = 1;//打开定时器1
	
}