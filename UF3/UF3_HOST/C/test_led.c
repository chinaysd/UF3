#include "test_led.h"

void Led_Init(void)
{
	//P0CON = 0xFF;  //����P0Ϊǿ����IO
	//P0PH  = 0x00;
	//P1CON = 0xFF;  //����P1Ϊǿ����IO
	//P1PH  = 0x00;
	P1CON |= 0X08;
	P13 = 1;
	//P2CON = 0xFF;  //����P2Ϊǿ����IO
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