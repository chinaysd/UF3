#include "system.h"

unsigned long get_key_data,MyKey_Buf_Data;
unsigned char key_press;

unsigned char flag1 = 0;   //中断标志位
unsigned int u8time_cnt_50ms;
unsigned char u8time_cnt_flag;

#if 1
void send_data(unsigned char mydata)
{
	//u8time_cnt_flag = 1;
	//if(u8time_cnt_50ms > 2)
	//{
	//	u8time_cnt_50ms = 0;
	//	u8time_cnt_flag = 0;
		SSDAT = mydata;
	  while(!flag1);
	  flag1 = 0;
	//}
				
}
#endif

void System_Init(void)
{
	Led_Init();	
	Tim1_Init();		
	Uart1_Init(6,38400);	
	TouchKeyInit();
	EA = 1;	
}


void System_Handle(void)
{	
	#if 1
	if(SOCAPI_TouchKeyStatus&0x80)
	{
			SOCAPI_TouchKeyStatus &= 0x7f;
			get_key_data = TouchKeyScan();
			TouchKeyRestart();
	}
	
	if(get_key_data!=0)
	{
		MyKey_Buf_Data = get_key_data;
		if(0x0002 == MyKey_Buf_Data)
		{
			if(!key_press)
			{
				key_press = 1;
				
				send_data(0x10);
				Led_Open();
			}			
		}
		else if(0x0040 == MyKey_Buf_Data)
		{
			if(!key_press)
			{
				key_press = 1;
				Led_Open();
				send_data(0x30);
			}
		}
		else if(0x0080 == MyKey_Buf_Data)
		{
			if(!key_press)
			{
				key_press = 1;
				Led_Open();
				send_data(0x20);
			}
		}
		else if(0x8000 == MyKey_Buf_Data)
		{
			if(!key_press)
			{
				key_press = 1;
				Led_Open();
				send_data(0x40);
			}
		}
		else
		{
			Led_Close();
			key_press = 0;
	    send_data(0x80);
		}			
	}
	else
	{
		Led_Close();
		key_press = 0;
		send_data(0x80);
		//TouchKeyRestart();
	}
 #endif
}

void timer1() interrupt 3
{
  TL1 = (65536 - 48000)%256;
	TH1 = (65536 - 48000)/256;
	//Led_Reset();
	if(u8time_cnt_flag)
	{
		u8time_cnt_50ms++;
	}
}
void Uart1_Int() interrupt 7   //Uart1中断函数
{
	if(SSCON0&0x02)    //接收标志位判断
	{
		SSCON0&=0xFD;
	}
	if((SSCON0&0x01))  //发送标志位判断
	{
		SSCON0&=0xFE;
	}
	flag1 = 1;
	
}