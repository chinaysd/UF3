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
#include"intrins.h"

#define WRITE_EEPROM 0X02   //OPTION IAPS1 IAPS0��1
#define WRITE_ROM    0X00	//OPTION IAPS1 IAPS0��0
typedef enum{ IAPHOLD4MS=0x02,IAPHOLD2MS=0x06,IAPHOLD1MS=0x0a }deHoldtimer;
unsigned char ReadData;

//*************************************************************
// ������	��
// ����		��
// ����		��IAPд
// ����		����
// ����ֵ	����
// ����ȫ�ֱ�������
// �޸�ȫ�ֱ�������
// ��ע		��
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
// ������	��
// ����		��
// ����		��IAP��
// ����		����
// ����ֵ	����
// ����ȫ�ֱ�������
// �޸�ȫ�ֱ�������
// ��ע		��
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
	WDTCON  = 0x10;				    //�忴�Ź���500ms���
	while(1)
	{
		WDTCON |= 0x10;				//�忴�Ź�
		IapWrite(0x55,0x01,WRITE_EEPROM,IAPHOLD4MS);
		ReadData=IapRead(0x01,WRITE_EEPROM);		
	}
}

