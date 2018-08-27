#include "system.h"


void main(void)
{
	System_Init();
	
	#if 1
	while(1)
	{
		System_Handle();
	}
	#endif
}

