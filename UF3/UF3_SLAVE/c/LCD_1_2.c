//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: LCD_1_2.C
//	作者		: 
//	模块功能	: 1/2bias LCD 驱动  1/4duty 83hz
//	局部函数列表:
//  最后更正日期: 2015/12/8
// 	版本		: V1.0
// 	更改记录	: 73X rom前256byte禁止查表,因此在编译的时候，
////设置keil->option for Target->BL51 Locate->Code Range:0x100
//*************************************************************
#include "mydefine.h"
unsigned char Handle_com=0;
unsigned  int  LcdData[4][2]={0X0F0F,0X0F0F,0X0F0F,0X0F0F,0X0F0F,0X0F0F,0X0F0F,0X0F0F};
//*************************************************************
// 函数名	：void ScanCom(void)
// 功能		：LCD COM扫描
// 参数		：无
// 返回值	：无
// 备注		：
//**************************************************************
void ScanCom(void)
{
	switch(Handle_com)
	{
		case 0:			
			  	  COM0SETVDD;
				  COM1SET1_2VDD;
				  COM2SET1_2VDD;
				  COM3SET1_2VDD;
				  COM4SET1_2VDD;						
			      break;
		case 1:
				  COM0SET1_2VDD;  
				  COM1SETVDD;			  
				  COM2SET1_2VDD;
				  COM3SET1_2VDD;
				  COM4SET1_2VDD;
				  break;
		case 2:		  
				  COM0SET1_2VDD;
				  COM1SET1_2VDD;
				  COM2SETVDD;
				  COM3SET1_2VDD;
				  COM4SET1_2VDD;		
				  break;
		case 3:
				  COM0SET1_2VDD;
				  COM1SET1_2VDD;
				  COM2SET1_2VDD;
				  COM3SETVDD;
				  COM4SET1_2VDD;
				  break;	
		case 4:
			  	  COM0SETGND;
				  COM1SET1_2VDD;
				  COM2SET1_2VDD;
				  COM3SET1_2VDD;
				  COM4SET1_2VDD;			
				  break;
		case 5:
				  COM0SET1_2VDD;  
				  COM1SETGND;			  
				  COM2SET1_2VDD;
				  COM3SET1_2VDD;
				  COM4SET1_2VDD;
				  break;
		case 6:				  
				  COM0SET1_2VDD;
				  COM1SET1_2VDD;
				  COM2SETGND;
				  COM3SET1_2VDD;		
				  break;
		case 7:
				  COM0SET1_2VDD;
				  COM1SET1_2VDD;
				  COM2SET1_2VDD;
				  COM3SETGND;
				  COM4SET1_2VDD;	
				  break;

		default:
				break;
	}
}
//*************************************************************
// 函数名	：void SEGSet(long int num)
// 功能		：LCD SEG 扫描
// 参数		：int num,int num1
// 返回值	：无
// 备注		：根据宏选择SEG个数，最大26SEG
//**************************************************************
void SEGSet(unsigned int num,unsigned int num1)
{
	#ifdef  SEG1
	(num&BIT0)?(BS(SEG1,SEG1LCDNUM)):(BC(SEG1,SEG1LCDNUM));
	#endif
	#ifdef  SEG2
    (num&BIT1)?(BS(SEG2,SEG2LCDNUM)):(BC(SEG2,SEG2LCDNUM));
	#endif
	#ifdef  SEG3
	(num&BIT2)?(BS(SEG3,SEG3LCDNUM)):(BC(SEG3,SEG3LCDNUM));
	#endif
	#ifdef  SEG4
	(num&BIT3)?(BS(SEG4,SEG4LCDNUM)):(BC(SEG4,SEG4LCDNUM));
	#endif
	#ifdef  SEG5
	(num&BIT4)?(BS(SEG5,SEG5LCDNUM)):(BC(SEG5,SEG5LCDNUM));
	#endif
	#ifdef  SEG6
	(num&BIT5)?(BS(SEG6,SEG6LCDNUM)):(BC(SEG6,SEG6LCDNUM));
	#endif
	#ifdef  SEG7
	(num&BIT6)?(BS(SEG7,SEG7LCDNUM)):(BC(SEG7,SEG7LCDNUM));
	#endif
	#ifdef  SEG8
	(num&BIT7)?(BS(SEG8,SEG8LCDNUM)):(BC(SEG8,SEG8LCDNUM));
	#endif
	#ifdef  SEG9
	(num&BIT8)?(BS(SEG9,SEG9LCDNUM)):(BC(SEG9,SEG9LCDNUM));
	#endif
	#ifdef  SEG10
	(num&BIT9)?(BS(SEG10,SEG10LCDNUM)):(BC(SEG10,SEG10LCDNUM));
	#endif

	#ifdef  SEG11
	(num&BIT10)?(BS(SEG11,SEG11LCDNUM)):(BC(SEG11,SEG11LCDNUM));
	#endif
	#ifdef  SEG12
    (num&BIT11)?(BS(SEG12,SEG12LCDNUM)):(BC(SEG12,SEG12LCDNUM));
	#endif
	#ifdef  SEG13
	(num&BIT12)?(BS(SEG13,SEG13LCDNUM)):(BC(SEG13,SEG13LCDNUM));
	#endif
	#ifdef  SEG14
	(num&BIT13)?(BS(SEG14,SEG14LCDNUM)):(BC(SEG14,SEG14LCDNUM));
	#endif
	#ifdef  SEG15
	(num&BIT14)?(BS(SEG15,SEG15LCDNUM)):(BC(SEG15,SEG15LCDNUM));
	#endif
	#ifdef  SEG16
	(num&BIT15)?(BS(SEG16,SEG16LCDNUM)):(BC(SEG16,SEG16LCDNUM));
	#endif
	#ifdef  SEG17
	(num1&BIT0)?(BS(SEG17,SEG17LCDNUM)):(BC(SEG17,SEG17LCDNUM));
	#endif
	#ifdef  SEG18
	(num1&BIT1)?(BS(SEG18,SEG18LCDNUM)):(BC(SEG18,SEG18LCDNUM));
	#endif
	#ifdef  SEG19
	(num1&BIT2)?(BS(SEG19,SEG19LCDNUM)):(BC(SEG19,SEG19LCDNUM));
	#endif
	#ifdef  SEG20
	(num1&BIT3)?(BS(SEG20,SEG20LCDNUM)):(BC(SEG20,SEG20LCDNUM));
	#endif
	#ifdef  SEG21
	(num1&BIT4)?(BS(SEG21,SEG21LCDNUM)):(BC(SEG21,SEG21LCDNUM));
	#endif
	#ifdef  SEG22
    (num1&BIT5)?(BS(SEG22,SEG22LCDNUM)):(BC(SEG22,SEG22LCDNUM));
	#endif
	#ifdef  SEG23
	(num1&BIT6)?(BS(SEG23,SEG23LCDNUM)):(BC(SEG23,SEG23LCDNUM));
	#endif
	#ifdef  SEG24
	(num1&BIT7)?(BS(SEG24,SEG24LCDNUM)):(BC(SEG24,SEG24LCDNUM));
	#endif
	#ifdef  SEG25
	(num1&BIT8)?(BS(SEG25,SEG25LCDNUM)):(BC(SEG25,SEG25LCDNUM));
	#endif
	#ifdef  SEG26
	(num1&BIT9)?(BS(SEG26,SEG26LCDNUM)):(BC(SEG26,SEG26LCDNUM));
	#endif	
}
//*************************************************************
// 函数名	：void LCD_Display(void)
// 功能		：LCD显示函数
// 参数		：无
// 返回值	：无
// 备注		：
//**************************************************************
void LCD_Display(void)
{ 	
		if(++Handle_com >7)			 
		{
			Handle_com=0;
		}
		ScanCom();		  					//调用子函数，扫描COM口		
	  
	    if(Handle_com<4)
		{
		   	SEGSet(~LcdData[Handle_com][0],~LcdData[Handle_com][1]); //正周期
		}
		else
		{
		 	SEGSet(LcdData[Handle_com-4][0],LcdData[Handle_com-4][1]); //负周期
		}
 }
