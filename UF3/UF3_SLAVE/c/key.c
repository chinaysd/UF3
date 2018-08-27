#include "key.h"



void Key_Init(void)
{
	P00IH;
	P24IH;
	P25IH;
	
  IO_KEY6_UP;
	IO_KEY5_UP;
	IO_KEY_CONTROL_UP;
}

