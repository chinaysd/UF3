#include "test_led.h"

void Led_Init(void)
{
	//P0CON = 0xFF;  //设置P0为强推挽IO
	//P0PH  = 0x00;
	//P1CON = 0xFF;  //设置P1为强推挽IO
	//P1PH  = 0x00;
	P1CON |= 0X08;
	P13 = 1;
	//P2CON = 0xFF;  //设置P2为强推挽IO
	//P2PH  = 0x00;
}

void Led_Open(void)
{
	IO_LED1_OPEN;
}

void Led_Close(void)
{
	IO_LED1_CLOSE;
}

void Led_Reset(void)
{
	IO_LED1_RESET;
}