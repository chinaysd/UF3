#include "uart1.h"


void Uart1_Init(int Freq,long int baud)
{
	OTCON = 0xC0;    //串行接口SSI选择Uart1通信
	SSCON0 = 0x50;   //设置通信方式为模式一，允许接收
	SSCON1 = Freq*1000000/baud;   //波特率低位控制
	SSCON2 = (Freq*1000000/baud)>>8;   //波特率高位控制
	IE1 = 0x01;      //开启SSI中断
  //EA = 1;	
}



