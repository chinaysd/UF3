#include "h\SC92F732X_C.h"
#include "732X_IO.h"
#include "MYDEFINE.H"
#include"intrins.h"
#include "push.h"
#include "tim1.h"
#include "key.h"

unsigned char u8time_cnt_flag;
unsigned long int u8time_cnt,auto_stop_cnt30s,cnt,cnt1,cnt2;
unsigned int i;
unsigned char PUSHA1_FLAG,PUSHA2_FLAG,PUSHB1_FLAG,PUSHB2_FLAG,PUSH_STOP_FLAG,auto_stop_flag,auto_close_flag;

void UARTwork(void)
{
		P1CON=0X080;
		P1PH=0X04;	 //TXΪǿ�������RXΪ���������룻
		P13=1;		 //TX��ʼ�ߵ�ƽ��
		SCON=0X50;   //��ʽ1�������������
		PCON |=0X80; //��ʽ1
		T2CON=0x00;  //ʹ�ö�ʱ��1��UARTʱ��
		TMOD=0X20;   //��ʱ��1  8λ�Զ�����0x20
		TMCON=0X02;  //��ʱ��1   Fsys��0x02
		TL1=217;		
		TH1=217;		//UART ������24M�����=38400��
		TR1=0;
		ET1=1;		   //Timer1ʹ��
		TR1=1;		   //����Timer0
		EUART=1;	   //����UART�ж�
		EA=1;		   //�����ж�
}

void uart()interrupt 4
{	
	if(TI)
	{
		TI=0;		           //�жϽ���Ҫ��TI��0
		SBUF=0X68;			   //����0X68
	}
	if(RI)			           //�����ж�
	{
		RI=0;		           //�жϽ���Ҫ��RI��0	
		i=SBUF;  		    //��i���ݷ��͵�SBUF��
		if(i == 0x10)
		{
			
			PUSHA1_FLAG = 1;
			PUSHA2_FLAG = 0;
			PUSHB1_FLAG = 0;
			PUSHB2_FLAG = 0;		
		}
		else if(i == 0x20)
		{
			PUSHA1_FLAG = 0;
			PUSHA2_FLAG = 1;
			PUSHB1_FLAG = 0;
			PUSHB2_FLAG = 0;
		}
		else if(i == 0x30)
		{
			PUSHA1_FLAG = 0;
			PUSHA2_FLAG = 0;
			PUSHB1_FLAG = 1;
			PUSHB2_FLAG = 0;
		}
		else if(i == 0x40)
		{	
			PUSHA1_FLAG = 0;
			PUSHA2_FLAG = 0;
			PUSHB1_FLAG = 0;
			PUSHB2_FLAG = 1;
		}
		else if(i == 0x55)
		{
			//P2 = 0X00;
			//P0 = 0X00;
			PUSHA1_FLAG = 0;
			PUSHA2_FLAG = 0;
			PUSHB1_FLAG = 0;
			PUSHB2_FLAG = 0;
		}
		else
		{
			PUSHA1_FLAG = 0;
			PUSHA2_FLAG = 0;
			PUSHB1_FLAG = 0;
			PUSHB2_FLAG = 0;
		}
	}
}

/*************************************************************
˵����main()

***************************************************************/
void main()
{
	Key_Init();
	Push_Init();
	Tim1_Init();
	UARTwork();

	while(1)
	{
		WDTCON |= 0x10;		    //�忴�Ź�		
		if(0 == IO_KEY_CONTROL_PIN)
		{
			auto_close_flag = 1;
			u8time_cnt_flag = 0;
			auto_stop_flag  = 0;
			
			u8time_cnt = 0;
			cnt2 = 0;
			cnt1 = 0;
			cnt  = 0;
			auto_stop_cnt30s = 0;
			
			if((0 == IO_KEY6_PIN)&&(0 == IO_KEY5_PIN))
			{
				if(PUSHA1_FLAG)
				{
				PUSHA1_OPEN;
				PUSHA2_CLOSE;
				PUSHB1_CLOSE;
				PUSHB2_CLOSE;
				}
				else if(PUSHA2_FLAG)
				{
				PUSHA1_CLOSE;
				PUSHA2_OPEN;
				PUSHB1_CLOSE;
				PUSHB2_CLOSE;
				}
				else if(PUSHB1_FLAG)
				{
				PUSHA1_CLOSE;
				PUSHA2_CLOSE;
				PUSHB1_OPEN;
				PUSHB2_CLOSE;
				}
				else if(PUSHB2_FLAG)
				{
				PUSHA1_CLOSE;
				PUSHA2_CLOSE;
				PUSHB1_CLOSE;
				PUSHB2_OPEN;
				}
				else if((0 == PUSHA1_FLAG)&&(0 == PUSHA2_FLAG)&&(0 == PUSHB1_FLAG)&&(0 == PUSHB2_FLAG))
				{
				PUSHA1_CLOSE;
				PUSHA2_CLOSE;
				PUSHB1_CLOSE;
				PUSHB2_CLOSE;
				}	
				else
				{
				PUSHA1_CLOSE;
				PUSHA2_CLOSE;
				PUSHB1_CLOSE;
				PUSHB2_CLOSE;
				}
			}
			else if((1 == IO_KEY6_PIN)&&(1 == IO_KEY5_PIN))
			{
				if(PUSHA1_FLAG)
				{
				PUSHA2_OPEN;
				PUSHA1_CLOSE;
				PUSHB1_CLOSE;
				PUSHB2_CLOSE;
				}
				else if(PUSHA2_FLAG)
				{
				PUSHA2_CLOSE;
				PUSHA1_OPEN;
				PUSHB1_CLOSE;
				PUSHB2_CLOSE;
				}
				else if(PUSHB1_FLAG)
				{
				PUSHA1_CLOSE;
				PUSHA2_CLOSE;
				PUSHB2_OPEN;
				PUSHB1_CLOSE;
				}
				else if(PUSHB2_FLAG)
				{
				PUSHA1_CLOSE;
				PUSHA2_CLOSE;
				PUSHB2_CLOSE;
				PUSHB1_OPEN;
				}
				else if((0 == PUSHA1_FLAG)&&(0 == PUSHA2_FLAG)&&(0 == PUSHB1_FLAG)&&(0 == PUSHB2_FLAG))
				{
				PUSHA1_CLOSE;
				PUSHA2_CLOSE;
				PUSHB1_CLOSE;
				PUSHB2_CLOSE;
				}	
				else
				{
				PUSHA1_CLOSE;
				PUSHA2_CLOSE;
				PUSHB1_CLOSE;
				PUSHB2_CLOSE;
				}
			}
			else if((1 == IO_KEY6_PIN)&&(0 == IO_KEY5_PIN))
			{
				if(PUSHA1_FLAG)
				{
				PUSHA2_OPEN;
				PUSHA1_CLOSE;
				PUSHB1_CLOSE;
				PUSHB2_CLOSE;
				}
				else if(PUSHA2_FLAG)
				{
				PUSHA2_CLOSE;
				PUSHA1_OPEN;
				PUSHB1_CLOSE;
				PUSHB2_CLOSE;
				}
				else if(PUSHB1_FLAG)
				{
				PUSHA1_CLOSE;
				PUSHA2_CLOSE;
				PUSHB1_OPEN;
				PUSHB2_CLOSE;
				}
				else if(PUSHB2_FLAG)
				{
				PUSHA1_CLOSE;
				PUSHA2_CLOSE;
				PUSHB1_CLOSE;
				PUSHB2_OPEN;
				}
				else if((0 == PUSHA1_FLAG)&&(0 == PUSHA2_FLAG)&&(0 == PUSHB1_FLAG)&&(0 == PUSHB2_FLAG))
				{
				PUSHA1_CLOSE;
				PUSHA2_CLOSE;
				PUSHB1_CLOSE;
				PUSHB2_CLOSE;
				}	
				else
				{
				PUSHA1_CLOSE;
				PUSHA2_CLOSE;
				PUSHB1_CLOSE;
				PUSHB2_CLOSE;
				}
			}
			else if((0 == IO_KEY6_PIN)&&(1 == IO_KEY5_PIN))
			{
				if(PUSHA1_FLAG)
				{
				PUSHA1_OPEN;
				PUSHA2_CLOSE;
				PUSHB1_CLOSE;
				PUSHB2_CLOSE;
				}
				else if(PUSHA2_FLAG)
				{
				PUSHA1_CLOSE;
				PUSHA2_OPEN;
				PUSHB1_CLOSE;
				PUSHB2_CLOSE;
				}
				else if(PUSHB1_FLAG)
				{
				PUSHA1_CLOSE;
				PUSHA2_CLOSE;
				PUSHB2_OPEN;
				PUSHB1_CLOSE;
				}
				else if(PUSHB2_FLAG)
				{
				PUSHA1_CLOSE;
				PUSHA2_CLOSE;
				PUSHB2_CLOSE;
				PUSHB1_OPEN;
				}
				else if((0 == PUSHA1_FLAG)&&(0 == PUSHA2_FLAG)&&(0 == PUSHB1_FLAG)&&(0 == PUSHB2_FLAG))
				{
				PUSHA1_CLOSE;
				PUSHA2_CLOSE;
				PUSHB1_CLOSE;
				PUSHB2_CLOSE;
				}	
				else
				{
				PUSHA1_CLOSE;
				PUSHA2_CLOSE;
				PUSHB1_CLOSE;
				PUSHB2_CLOSE;
				}
			}
		}
		else
		{
			 if(0 == cnt2)
			 {
				 cnt2++;
				 PUSHA1_CLOSE;
				 PUSHA2_CLOSE;
				 PUSHB1_CLOSE;
				 PUSHB2_CLOSE;
			 }
       if(auto_close_flag)
			 {
					u8time_cnt_flag = 1;
					if(u8time_cnt > 10000)   //3S
					{
						cnt1++;
						u8time_cnt = 0;
						if(cnt1 > 5)
						{
							cnt1 = 0;
							u8time_cnt_flag = 0;
						  u8time_cnt = 0;
						  PUSHA2_OPEN;
						  auto_stop_flag = 1;
						}
					}
					if(auto_stop_cnt30s > 60000)//30S
					{
						cnt++;
						auto_stop_cnt30s = 0;
						if(cnt > 2)
						{
							cnt = 0;
							auto_stop_flag = 0;
						  auto_stop_cnt30s = 0;
						  PUSHA2_CLOSE;
						  auto_close_flag = 0;
						}
					}
			 }
			 if(0 == IO_KEY5_PIN)
			 {
				 if(PUSHB1_FLAG)
				 {
					 PUSHB1_OPEN;
				 }
				 else if(PUSHB2_FLAG)
				 {
					 PUSHB2_OPEN;
				 }
				 else if((0 == PUSHB1_FLAG)&&(0 == PUSHB2_FLAG))
				 {
					 PUSHB1_CLOSE;
					 PUSHB2_CLOSE;
				 }
			 }
			 else if(1 == IO_KEY5_PIN)
			 {
				 if(PUSHB1_FLAG)
				 {
					 PUSHB2_OPEN;
				 }
				 else if(PUSHB2_FLAG)
				 {
					 PUSHB1_OPEN;
				 }
				 else if((0 == PUSHB1_FLAG)&&(0 == PUSHB2_FLAG))
				 {
					 PUSHB1_CLOSE;
					 PUSHB2_CLOSE;
				 }
			 }  
		}
	}
}
void timer0()interrupt 1				//Timer0??? 1
{
	TH0=(65536-600)/256;   				//??????
	TL0=(65536-600)%256;
	if(u8time_cnt_flag)
	{
		u8time_cnt++;
	}
	if(auto_stop_flag)
	{
		auto_stop_cnt30s++;
	}
}
