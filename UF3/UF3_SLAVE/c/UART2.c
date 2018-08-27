//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	:
//	作者		: 
//	模块功能	: 
//	局部函数列表:
//  最后更正日期:
// 	版本		:
// 	更改记录	:rom前256byte禁止查表,因此在编译的时候，设置keil->option for Target->BL51 Locate->Code Range:0x100
//*************************************************************


#include "h\SC92F732X_C.h"

bit flag;
bit RI_FLAG=0;
unsigned char i;

void IOinit(void )
{	
	P1CON |=0X08;  	   //P13设置为输出	
	P1CON &=0XFB;  	   //P12设置为输入	
	P1PH  &=0XF7;	   //P13上拉电阻关闭
	P1PH  |=0X04;	   //P12上拉电阻打开
	P13=1;
	P12=1;
}

void init_uart_mode1(void)
{
    SCON=0X50;         //方式1，允许接收数据
    PCON |=0X80;       //方式1
	T2CON=0x35;	       //定时器2产生波特率
	T2MOD=0x03;        //16位自动重载定时器模式
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
		TI=0;		           //中断进来要把TI清0
	}
	if(RI)			           //接收中断
	{
		RI=0;		           //中断进来要把RI清0	
		RI_FLAG=1;
	}
}

void timer2()interrupt 5		//Timer2向量号 5
{
}

void main()
{
	WDTCON  = 0x10;				//清看门狗，500ms溢出
	EA=1;  //开总中断；
	IOinit();
	init_uart_mode1();
	while(1)
	{
		WDTCON |= 0x10;			//清看门狗		
		if(RI_FLAG)			    //接收中断
		{
			RI_FLAG=0;
			i=SBUF;		        //把SBUF 数据赋值给i		
			flag=1;		        //收完一帧数据时则进行发送
		}	

		if(flag==1)
		{
			EUART=0; 		    //发送数据之前要把串口中断关掉
			flag=0;	 		    //让接收下一数据时置1
			SBUF=i;  		    //把i数据发送到SBUF中
			while(!TI);		    //等待发送完成
			EUART=1; 		    //打开中断进行下一个数据的接收
		}
	}
}