//************************************************************
//  Copyright (c) ��������Ԫ΢�������޹�˾
//	�ļ�����	:
//	����		: 
//	ģ�鹦��	: 
//	�ֲ������б�:
//  ����������:
// 	�汾		:
// 	���ļ�¼	:romǰ256byte��ֹ���,����ڱ����ʱ������keil->option for Target->BL51 Locate->Code Range:0x100
//*************************************************************


#include "h\SC92F732X_C.h"

bit flag;
bit RI_FLAG=0;
unsigned char i;

void IOinit(void )
{	
	P1CON |=0X08;  	   //P13����Ϊ���	
	P1CON &=0XFB;  	   //P12����Ϊ����	
	P1PH  &=0XF7;	   //P13��������ر�
	P1PH  |=0X04;	   //P12���������
	P13=1;
	P12=1;
}

void init_uart_mode1(void)
{
    SCON=0X50;         //��ʽ1�������������
    PCON |=0X80;       //��ʽ1
	T2CON=0x35;	       //��ʱ��2����������
	T2MOD=0x03;        //16λ�Զ����ض�ʱ��ģʽ
	TMCON=0X04; 
	RCAP2H=(65536-20)/256;			
	RCAP2L=(65536-20)%256;
	TR2=0;
   	ET2=1;
   	TR2=1;
	EUART=1;
}

void uart()interrupt 4
{	
	if(TI)
	{
		TI=0;		           //�жϽ���Ҫ��TI��0
	}
	if(RI)			           //�����ж�
	{
		RI=0;		           //�жϽ���Ҫ��RI��0	
		RI_FLAG=1;
	}
}

void timer2()interrupt 5		//Timer2������ 5
{
}

void main()
{
	WDTCON  = 0x10;				//�忴�Ź���500ms���
	EA=1;  //�����жϣ�
	IOinit();
	init_uart_mode1();
	while(1)
	{
		WDTCON |= 0x10;			//�忴�Ź�		
		if(RI_FLAG)			    //�����ж�
		{
			RI_FLAG=0;
			i=SBUF;		        //��SBUF ���ݸ�ֵ��i		
			flag=1;		        //����һ֡����ʱ����з���
		}	

		if(flag==1)
		{
			EUART=0; 		    //��������֮ǰҪ�Ѵ����жϹص�
			flag=0;	 		    //�ý�����һ����ʱ��1
			SBUF=i;  		    //��i���ݷ��͵�SBUF��
			while(!TI);		    //�ȴ��������
			EUART=1; 		    //���жϽ�����һ�����ݵĽ���
		}
	}
}