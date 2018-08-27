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
#include"intrins.h"

#define WRITE_EEPROM 0X02   //OPTION IAPS1 IAPS0置1
#define WRITE_ROM    0X00	//OPTION IAPS1 IAPS0置0
typedef enum{ IAPHOLD4MS=0x02,IAPHOLD2MS=0x06,IAPHOLD1MS=0x0a }deHoldtimer;
unsigned char ReadData;

//*************************************************************
// 函数名	：
// 作者		：
// 功能		：IAP写
// 参数		：有
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：
//**************************************************************
void IapWrite(unsigned char Data,unsigned int Addr,unsigned char Region,deHoldtimer eHoldtimer)
{
	IAPDAT = Data;
	IAPADH = (unsigned char)((Addr >> 8));
    IAPADL = (unsigned char)Addr;
	
	IAPADE = Region;
    IAPKEY = 240 ;
	IAPCTL = eHoldtimer;
	
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
	IAPADE = WRITE_ROM; 
}

//*************************************************************
// 函数名	：
// 作者		：
// 功能		：IAP读
// 参数		：有
// 返回值	：有
// 调用全局变量：无
// 修改全局变量：无
// 备注		：
//**************************************************************
unsigned char IapRead(unsigned int Addr,unsigned char Region)
{
    unsigned char code *IapAddr=0x00;
	unsigned char Temp;
	 
	IAPADE = Region;
	Temp = *(IapAddr+Addr);
	IAPADE = WRITE_ROM;

	return Temp;
}

void main()
{
	WDTCON  = 0x10;				    //清看门狗，500ms溢出
	while(1)
	{
		WDTCON |= 0x10;				//清看门狗
		IapWrite(0x55,0x01,WRITE_EEPROM,IAPHOLD4MS);
		ReadData=IapRead(0x01,WRITE_EEPROM);		
	}
}

