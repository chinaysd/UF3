#ifndef _MYDEFINE_H_
#define _MYDEFINE_H_

#include "h\SC92F732x_C.H"

#define		BS(SFR,NUM)		(SFR|=(1<<NUM))             //位置1
#define		BC(SFR,NUM)		(SFR&=~(1<<NUM))	    //位清0

#define		SET(SFR,NUM)	(SFR = NUM)

//=========================强推挽IO设置=========================================//

#define	 P00PM	 BS(P0CON,0)	 //设置P00为强推挽IO
#define	 P01PM	 BS(P0CON,1)	 //设置P01为强推挽IO
#define	 P02PM	 BS(P0CON,2)	 //设置P02为强推挽IO
#define	 P03PM	 BS(P0CON,3)	 //设置P03为强推挽IO
#define	 P04PM	 BS(P0CON,4)	 //设置P04为强推挽IO
#define	 P05PM	 BS(P0CON,5)	 //设置P05为强推挽IO
#define	 P06PM	 BS(P0CON,6)	 //设置P06为强推挽IO
#define	 P07PM	 BS(P0CON,7)	 //设置P07为强推挽IO

#define	 P10PM	 BS(P1CON,0)	 //设置P10为强推挽IO
#define	 P11PM	 BS(P1CON,1)	 //设置P11为强推挽IO
#define	 P12PM	 BS(P1CON,2)	 //设置P12为强推挽IO
#define	 P13PM	 BS(P1CON,3)	 //设置P13为强推挽IO
#define	 P14PM	 BS(P1CON,4)	 //设置P14为强推挽IO
#define	 P15PM	 BS(P1CON,5)	 //设置P15为强推挽IO
#define	 P16PM	 BS(P1CON,6)	 //设置P16为强推挽IO
#define	 P17PM	 BS(P1CON,7)	 //设置P17为强推挽IO

#define	 P20PM	 BS(P2CON,0)	 //设置P20为强推挽IO
#define	 P21PM	 BS(P2CON,1)	 //设置P21为强推挽IO
#define	 P22PM	 BS(P2CON,2)	 //设置P22为强推挽IO
#define	 P23PM	 BS(P2CON,3)	 //设置P23为强推挽IO
#define	 P24PM	 BS(P2CON,4)	 //设置P24为强推挽IO
#define	 P25PM	 BS(P2CON,5)	 //设置P25为强推挽IO
#define	 P26PM	 BS(P2CON,6)	 //设置P26为强推挽IO
#define	 P27PM	 BS(P2CON,7)	 //设置P27为强推挽IO

#define	 P50PM	 BS(P5CON,0)	 //设置P50为强推挽IO
#define	 P51PM	 BS(P5CON,1)	 //设置P51为强推挽IO

//=========================高阻态IO设置=========================================//

#define	 P00IM	 (BC(P0CON,0),BC(P0PH,0))	 //设置P00为高阻态IO
#define	 P01IM	 (BC(P0CON,1),BC(P0PH,1))	 //设置P01为高阻态IO
#define	 P02IM	 (BC(P0CON,2),BC(P0PH,2))	 //设置P02为高阻态IO
#define	 P03IM	 (BC(P0CON,3),BC(P0PH,3))	 //设置P03为高阻态IO
#define	 P04IM	 (BC(P0CON,4),BC(P0PH,4))	 //设置P04为高阻态IO
#define	 P05IM	 (BC(P0CON,5),BC(P0PH,5))	 //设置P05为高阻态IO
#define	 P06IM	 (BC(P0CON,6),BC(P0PH,6))	 //设置P06为高阻态IO
#define	 P07IM	 (BC(P0CON,7),BC(P0PH,7))	 //设置P07为高阻态IO

#define	 P10IM	 (BC(P1CON,0),BC(P1PH,0))	 //设置P10为高阻态IO
#define	 P11IM	 (BC(P1CON,1),BC(P1PH,1))	 //设置P11为高阻态IO
#define	 P12IM	 (BC(P1CON,2),BC(P1PH,2))	 //设置P12为高阻态IO
#define	 P13IM	 (BC(P1CON,3),BC(P1PH,3))	 //设置P13为高阻态IO
#define	 P14IM	 (BC(P1CON,4),BC(P1PH,4))	 //设置P14为高阻态IO
#define	 P15IM	 (BC(P1CON,5),BC(P1PH,5))	 //设置P15为高阻态IO
#define	 P16IM	 (BC(P1CON,6),BC(P1PH,6))	 //设置P16为高阻态IO
#define	 P17IM	 (BC(P1CON,7),BC(P1PH,7))	 //设置P17为高阻态IO

#define	 P20IM	 (BC(P2CON,0),BC(P2PH,0))	 //设置P20为高阻态IO
#define	 P21IM	 (BC(P2CON,1),BC(P2PH,1))	 //设置P21为高阻态IO
#define	 P22IM	 (BC(P2CON,2),BC(P2PH,2))	 //设置P22为高阻态IO
#define	 P23IM	 (BC(P2CON,3),BC(P2PH,3))	 //设置P23为高阻态IO
#define	 P24IM	 (BC(P2CON,4),BC(P2PH,4))	 //设置P24为高阻态IO
#define	 P25IM	 (BC(P2CON,5),BC(P2PH,5))	 //设置P25为高阻态IO
#define	 P26IM	 (BC(P2CON,6),BC(P2PH,6))	 //设置P26为高阻态IO
#define	 P27IM	 (BC(P2CON,7),BC(P2PH,7))	 //设置P27为高阻态IO

#define	 P50IM	 (BC(P5CON,0),BC(P5PH,0))	 //设置P50为高阻态IO
#define	 P51IM	 (BC(P5CON,1),BC(P5PH,1))	 //设置P51为高阻态IO

//=========================带上拉IO输入设置=========================================//

#define	 P00IH	 (BC(P0CON,0),BS(P0PH,0))	 //设置P00为带上拉IO
#define	 P01IH	 (BC(P0CON,1),BS(P0PH,1))	 //设置P01为带上拉IO
#define	 P02IH	 (BC(P0CON,2),BS(P0PH,2))	 //设置P02为带上拉IO
#define	 P03IH	 (BC(P0CON,3),BS(P0PH,3))	 //设置P03为带上拉IO
#define	 P04IH	 (BC(P0CON,4),BS(P0PH,4))	 //设置P04为带上拉IO
#define	 P05IH	 (BC(P0CON,5),BS(P0PH,5))	 //设置P05为带上拉IO
#define	 P06IH	 (BC(P0CON,6),BS(P0PH,6))	 //设置P06为带上拉IO
#define	 P07IH	 (BC(P0CON,7),BS(P0PH,7))	 //设置P07为带上拉IO

#define	 P10IH	 (BC(P1CON,0),BS(P1PH,0))	 //设置P10为带上拉IO
#define	 P11IH	 (BC(P1CON,1),BS(P1PH,1))	 //设置P11为带上拉IO
#define	 P12IH	 (BC(P1CON,2),BS(P1PH,2))	 //设置P12为带上拉IO
#define	 P13IH	 (BC(P1CON,3),BS(P1PH,3))	 //设置P13为带上拉IO
#define	 P14IH	 (BC(P1CON,4),BS(P1PH,4))	 //设置P14为带上拉IO
#define	 P15IH	 (BC(P1CON,5),BS(P1PH,5))	 //设置P15为带上拉IO
#define	 P16IH	 (BC(P1CON,6),BS(P1PH,6))	 //设置P16为带上拉IO
#define	 P17IH	 (BC(P1CON,7),BS(P1PH,7))	 //设置P17为带上拉IO

#define	 P20IH	 (BC(P2CON,0),BS(P2PH,0))	 //设置P20为带上拉IO
#define	 P21IH	 (BC(P2CON,1),BS(P2PH,1))	 //设置P21为带上拉IO
#define	 P22IH	 (BC(P2CON,2),BS(P2PH,2))	 //设置P22为带上拉IO
#define	 P23IH	 (BC(P2CON,3),BS(P2PH,3))	 //设置P23为带上拉IO
#define	 P24IH	 (BC(P2CON,4),BS(P2PH,4))	 //设置P24为带上拉IO
#define	 P25IH	 (BC(P2CON,5),BS(P2PH,5))	 //设置P25为带上拉IO
#define	 P26IH	 (BC(P2CON,6),BS(P2PH,6))	 //设置P26为带上拉IO
#define	 P27IH	 (BC(P2CON,7),BS(P2PH,7))	 //设置P27为带上拉IO

#define	 P50IH	 (BC(P5CON,0),BS(P5PH,0))	 //设置P50为带上拉IO
#define	 P51IH	 (BC(P5CON,1),BS(P5PH,1))	 //设置P51为带上拉IO

///COM设置，比如设置:COM0为P00,COM1为P01,COM2为P02,COM3为P03,COM4为P04
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


///SEG设置,根据LCD设置SEG，不使用的SEG注释掉，如23PIN LCD，5个COM21个SEG，注释掉22-26SEG
//举例：如果SEG1为P05,则设置SEG1  P0,SEGLCDNUM  5；
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