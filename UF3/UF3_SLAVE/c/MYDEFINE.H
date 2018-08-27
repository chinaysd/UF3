#ifndef _MYDEFINE_H_
#define _MYDEFINE_H_

#include "h\SC92F732x_C.H"

#define		BS(SFR,NUM)		(SFR|=(1<<NUM))             //λ��1
#define		BC(SFR,NUM)		(SFR&=~(1<<NUM))	    //λ��0

#define		SET(SFR,NUM)	(SFR = NUM)

//=========================ǿ����IO����=========================================//

#define	 P00PM	 BS(P0CON,0)	 //����P00Ϊǿ����IO
#define	 P01PM	 BS(P0CON,1)	 //����P01Ϊǿ����IO
#define	 P02PM	 BS(P0CON,2)	 //����P02Ϊǿ����IO
#define	 P03PM	 BS(P0CON,3)	 //����P03Ϊǿ����IO
#define	 P04PM	 BS(P0CON,4)	 //����P04Ϊǿ����IO
#define	 P05PM	 BS(P0CON,5)	 //����P05Ϊǿ����IO
#define	 P06PM	 BS(P0CON,6)	 //����P06Ϊǿ����IO
#define	 P07PM	 BS(P0CON,7)	 //����P07Ϊǿ����IO

#define	 P10PM	 BS(P1CON,0)	 //����P10Ϊǿ����IO
#define	 P11PM	 BS(P1CON,1)	 //����P11Ϊǿ����IO
#define	 P12PM	 BS(P1CON,2)	 //����P12Ϊǿ����IO
#define	 P13PM	 BS(P1CON,3)	 //����P13Ϊǿ����IO
#define	 P14PM	 BS(P1CON,4)	 //����P14Ϊǿ����IO
#define	 P15PM	 BS(P1CON,5)	 //����P15Ϊǿ����IO
#define	 P16PM	 BS(P1CON,6)	 //����P16Ϊǿ����IO
#define	 P17PM	 BS(P1CON,7)	 //����P17Ϊǿ����IO

#define	 P20PM	 BS(P2CON,0)	 //����P20Ϊǿ����IO
#define	 P21PM	 BS(P2CON,1)	 //����P21Ϊǿ����IO
#define	 P22PM	 BS(P2CON,2)	 //����P22Ϊǿ����IO
#define	 P23PM	 BS(P2CON,3)	 //����P23Ϊǿ����IO
#define	 P24PM	 BS(P2CON,4)	 //����P24Ϊǿ����IO
#define	 P25PM	 BS(P2CON,5)	 //����P25Ϊǿ����IO
#define	 P26PM	 BS(P2CON,6)	 //����P26Ϊǿ����IO
#define	 P27PM	 BS(P2CON,7)	 //����P27Ϊǿ����IO

#define	 P50PM	 BS(P5CON,0)	 //����P50Ϊǿ����IO
#define	 P51PM	 BS(P5CON,1)	 //����P51Ϊǿ����IO

//=========================����̬IO����=========================================//

#define	 P00IM	 (BC(P0CON,0),BC(P0PH,0))	 //����P00Ϊ����̬IO
#define	 P01IM	 (BC(P0CON,1),BC(P0PH,1))	 //����P01Ϊ����̬IO
#define	 P02IM	 (BC(P0CON,2),BC(P0PH,2))	 //����P02Ϊ����̬IO
#define	 P03IM	 (BC(P0CON,3),BC(P0PH,3))	 //����P03Ϊ����̬IO
#define	 P04IM	 (BC(P0CON,4),BC(P0PH,4))	 //����P04Ϊ����̬IO
#define	 P05IM	 (BC(P0CON,5),BC(P0PH,5))	 //����P05Ϊ����̬IO
#define	 P06IM	 (BC(P0CON,6),BC(P0PH,6))	 //����P06Ϊ����̬IO
#define	 P07IM	 (BC(P0CON,7),BC(P0PH,7))	 //����P07Ϊ����̬IO

#define	 P10IM	 (BC(P1CON,0),BC(P1PH,0))	 //����P10Ϊ����̬IO
#define	 P11IM	 (BC(P1CON,1),BC(P1PH,1))	 //����P11Ϊ����̬IO
#define	 P12IM	 (BC(P1CON,2),BC(P1PH,2))	 //����P12Ϊ����̬IO
#define	 P13IM	 (BC(P1CON,3),BC(P1PH,3))	 //����P13Ϊ����̬IO
#define	 P14IM	 (BC(P1CON,4),BC(P1PH,4))	 //����P14Ϊ����̬IO
#define	 P15IM	 (BC(P1CON,5),BC(P1PH,5))	 //����P15Ϊ����̬IO
#define	 P16IM	 (BC(P1CON,6),BC(P1PH,6))	 //����P16Ϊ����̬IO
#define	 P17IM	 (BC(P1CON,7),BC(P1PH,7))	 //����P17Ϊ����̬IO

#define	 P20IM	 (BC(P2CON,0),BC(P2PH,0))	 //����P20Ϊ����̬IO
#define	 P21IM	 (BC(P2CON,1),BC(P2PH,1))	 //����P21Ϊ����̬IO
#define	 P22IM	 (BC(P2CON,2),BC(P2PH,2))	 //����P22Ϊ����̬IO
#define	 P23IM	 (BC(P2CON,3),BC(P2PH,3))	 //����P23Ϊ����̬IO
#define	 P24IM	 (BC(P2CON,4),BC(P2PH,4))	 //����P24Ϊ����̬IO
#define	 P25IM	 (BC(P2CON,5),BC(P2PH,5))	 //����P25Ϊ����̬IO
#define	 P26IM	 (BC(P2CON,6),BC(P2PH,6))	 //����P26Ϊ����̬IO
#define	 P27IM	 (BC(P2CON,7),BC(P2PH,7))	 //����P27Ϊ����̬IO

#define	 P50IM	 (BC(P5CON,0),BC(P5PH,0))	 //����P50Ϊ����̬IO
#define	 P51IM	 (BC(P5CON,1),BC(P5PH,1))	 //����P51Ϊ����̬IO

//=========================������IO��������=========================================//

#define	 P00IH	 (BC(P0CON,0),BS(P0PH,0))	 //����P00Ϊ������IO
#define	 P01IH	 (BC(P0CON,1),BS(P0PH,1))	 //����P01Ϊ������IO
#define	 P02IH	 (BC(P0CON,2),BS(P0PH,2))	 //����P02Ϊ������IO
#define	 P03IH	 (BC(P0CON,3),BS(P0PH,3))	 //����P03Ϊ������IO
#define	 P04IH	 (BC(P0CON,4),BS(P0PH,4))	 //����P04Ϊ������IO
#define	 P05IH	 (BC(P0CON,5),BS(P0PH,5))	 //����P05Ϊ������IO
#define	 P06IH	 (BC(P0CON,6),BS(P0PH,6))	 //����P06Ϊ������IO
#define	 P07IH	 (BC(P0CON,7),BS(P0PH,7))	 //����P07Ϊ������IO

#define	 P10IH	 (BC(P1CON,0),BS(P1PH,0))	 //����P10Ϊ������IO
#define	 P11IH	 (BC(P1CON,1),BS(P1PH,1))	 //����P11Ϊ������IO
#define	 P12IH	 (BC(P1CON,2),BS(P1PH,2))	 //����P12Ϊ������IO
#define	 P13IH	 (BC(P1CON,3),BS(P1PH,3))	 //����P13Ϊ������IO
#define	 P14IH	 (BC(P1CON,4),BS(P1PH,4))	 //����P14Ϊ������IO
#define	 P15IH	 (BC(P1CON,5),BS(P1PH,5))	 //����P15Ϊ������IO
#define	 P16IH	 (BC(P1CON,6),BS(P1PH,6))	 //����P16Ϊ������IO
#define	 P17IH	 (BC(P1CON,7),BS(P1PH,7))	 //����P17Ϊ������IO

#define	 P20IH	 (BC(P2CON,0),BS(P2PH,0))	 //����P20Ϊ������IO
#define	 P21IH	 (BC(P2CON,1),BS(P2PH,1))	 //����P21Ϊ������IO
#define	 P22IH	 (BC(P2CON,2),BS(P2PH,2))	 //����P22Ϊ������IO
#define	 P23IH	 (BC(P2CON,3),BS(P2PH,3))	 //����P23Ϊ������IO
#define	 P24IH	 (BC(P2CON,4),BS(P2PH,4))	 //����P24Ϊ������IO
#define	 P25IH	 (BC(P2CON,5),BS(P2PH,5))	 //����P25Ϊ������IO
#define	 P26IH	 (BC(P2CON,6),BS(P2PH,6))	 //����P26Ϊ������IO
#define	 P27IH	 (BC(P2CON,7),BS(P2PH,7))	 //����P27Ϊ������IO

#define	 P50IH	 (BC(P5CON,0),BS(P5PH,0))	 //����P50Ϊ������IO
#define	 P51IH	 (BC(P5CON,1),BS(P5PH,1))	 //����P51Ϊ������IO

///COM���ã���������:COM0ΪP00,COM1ΪP01,COM2ΪP02,COM3ΪP03,COM4ΪP04
#define  COM0     		P0
#define  COM0LCDNUM     0
#define  COM0LCDVO     	P0VO
#define  COM0PM     	P00PM

#define  COM1     		P0
#define  COM1LCDNUM     1
#define  COM1LCDVO     	P0VO
#define  COM1PM     	P01PM

#define  COM2     		P0
#define  COM2LCDNUM     2
#define  COM2LCDVO     	P0VO
#define  COM2PM     	P02PM

#define  COM3     		P0
#define  COM3LCDNUM     3
#define  COM3LCDVO     	P0VO
#define  COM3PM    	 	P03PM

#define  COM4     		P0
#define  COM4LCDNUM     4
#define  COM4LCDVO     	P0VO
#define  COM4PM     	P04PM


///SEG����,����LCD����SEG����ʹ�õ�SEGע�͵�����23PIN LCD��5��COM21��SEG��ע�͵�22-26SEG
//���������SEG1ΪP05,������SEG1  P0,SEGLCDNUM  5��
#define  SEG1     		P0
#define  SEG1LCDNUM     5
#define  SEG2     		P0
#define  SEG2LCDNUM     6
#define  SEG3     		P0
#define  SEG3LCDNUM     7
#define  SEG4     		P2
#define  SEG4LCDNUM     0
#define  SEG5     		P2
#define  SEG5LCDNUM     1
#define  SEG6     		P2
#define  SEG6LCDNUM     2
#define  SEG7     		P2
#define  SEG7LCDNUM     3
#define  SEG8     		P2
#define  SEG8LCDNUM     4
#define  SEG9     		P2
#define  SEG9LCDNUM     5
#define  SEG10     		P2
#define  SEG10LCDNUM    6

#define  SEG11     		P2
#define  SEG11LCDNUM    7
#define  SEG12     		P1
#define  SEG12LCDNUM    7
#define  SEG13     		P1
#define  SEG13LCDNUM    6
#define  SEG14     		P1
#define  SEG14LCDNUM    5
#define  SEG15     		P1
#define  SEG15LCDNUM    4
#define  SEG16     		P1
#define  SEG16LCDNUM    3
#define  SEG17     		P1
#define  SEG17LCDNUM    0
#define  SEG18     		P5
#define  SEG18LCDNUM    0
#define  SEG19     		P5
#define  SEG19LCDNUM    1
/*
#define  SEG20     		P5
#define  SEG20LCDNUM    0
#define  SEG21     		P5
#define  SEG21LCDNUM    1


#define  SEG21LCDNUM    5
#define  SEG22     		P3
#define  SEG22LCDNUM    0
#define  SEG23     		P3
#define  SEG23LCDNUM    1
#define  SEG24     		P3
#define  SEG24LCDNUM    2
#define  SEG25     		P3	 
#define  SEG25LCDNUM    3
#define  SEG26     		P3
#define  SEG26LCDNUM    4	 */

#define   COM0SETVDD  (BS(COM0,COM0LCDNUM),BC(COM0LCDVO,COM0LCDNUM),COM0PM)
#define   COM1SETVDD  (BS(COM1,COM1LCDNUM),BC(COM1LCDVO,COM1LCDNUM),COM1PM)
#define   COM2SETVDD  (BS(COM2,COM2LCDNUM),BC(COM2LCDVO,COM2LCDNUM),COM2PM)
#define   COM3SETVDD  (BS(COM3,COM3LCDNUM),BC(COM3LCDVO,COM3LCDNUM),COM3PM)
#define   COM4SETVDD  (BS(COM4,COM4LCDNUM),BC(COM4LCDVO,COM4LCDNUM),COM4PM)

#define   COM0SETGND  (BC(COM0,COM0LCDNUM),BC(COM0LCDVO,COM0LCDNUM),COM0PM)
#define   COM1SETGND  (BC(COM1,COM1LCDNUM),BC(COM1LCDVO,COM1LCDNUM),COM1PM)
#define   COM2SETGND  (BC(COM2,COM2LCDNUM),BC(COM2LCDVO,COM2LCDNUM),COM2PM)
#define   COM3SETGND  (BC(COM3,COM3LCDNUM),BC(COM3LCDVO,COM3LCDNUM),COM3PM)
#define   COM4SETGND  (BC(COM4,COM4LCDNUM),BC(COM4LCDVO,COM4LCDNUM),COM4PM)

#define   COM0SET1_2VDD  (BS(COM0LCDVO,COM0LCDNUM))
#define   COM1SET1_2VDD  (BS(COM1LCDVO,COM1LCDNUM))
#define   COM2SET1_2VDD  (BS(COM2LCDVO,COM2LCDNUM))
#define   COM3SET1_2VDD  (BS(COM3LCDVO,COM3LCDNUM))
#define   COM4SET1_2VDD  (BS(COM4LCDVO,COM4LCDNUM))

#define    	BIT0          	0x01
#define    	BIT1           	0x02
#define    	BIT2           	0x04
#define    	BIT3           	0x08
#define    	BIT4           	0x10
#define    	BIT5           	0x20
#define    	BIT6           	0x40
#define    	BIT7           	0x80
#define    	BIT8           	0x100
#define    	BIT9           	0x200
#define    	BIT10          	0x400
#define    	BIT11           0x800
#define    	BIT12           0x1000
#define    	BIT13           0x2000
#define    	BIT14           0x4000
#define    	BIT15           0x8000

extern void LCD_Display();

#endif 