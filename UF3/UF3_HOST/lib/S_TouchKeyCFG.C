//*************************************************************************************************
//  Copyright (c) 	��������Ԫ΢�������޹�˾
//	�ļ�����	:  S_TouchKeyCFG.c
//	����		: 
//	ģ�鹦��	:  ���ؼ������ļ�
// 	�汾		:
// 	���ļ�¼	:
//	ע������	:  �û���Ҫ���õ��ļ���S_TouchKeyCFG.h��
//  ��汾���	: 
//************************************************************************************************

#include "lib\S_TouchKeyCFG.h"

//===========================================================================
//�Ĵ�������
/*TouchKey*/
sfr     TKCON   = 0XE8;
sfr     TKCFG1  = 0XE2;
sfr     TKCFG0  = 0XE1;

/*PSW*/
sfr 	PSW	    = 	0xD0;	//����״̬��
sbit 	CY		= 	PSW^7;	//��λ

//===========================================================================
//ȫ�ֱ�������
unsigned	char	xdata	SOCAPI_TouchKeyStatus;					//API�ӿ�״̬��bit7-һ��ɨ����ɱ�־  1:��� 	0��δ���
																	//			   bit6-ͨ���������������־ 1:���	 0:δ���
//===============================================================================
//ȫ�ֱ��������������򲻿��޸�
unsigned 	int 	xdata	RawData [SOCAPI_SET_TOUCHKEY_TOTAL];			
unsigned 	int		xdata	BaseLine[SOCAPI_SET_TOUCHKEY_TOTAL];
unsigned  	int	 	xdata	FilterData[SOCAPI_SET_TOUCHKEY_TOTAL];												
unsigned	char  	idata	RestAreaCnt[SOCAPI_SET_TOUCHKEY_TOTAL]; 			
unsigned	char  	idata	TouchCnt[SOCAPI_SET_TOUCHKEY_TOTAL];				
unsigned	char  	idata	NoTouchCnt[SOCAPI_SET_TOUCHKEY_TOTAL];  			
unsigned	char	xdata	CurrentChannel[SOCAPI_SET_TOUCHKEY_TOTAL];						   
unsigned 	char	xdata	ConfirmTouchCnt=SOCAPI_SET_TOUCHKEY_CONFIRM_CNT;	
unsigned    char    idata   LowFingerDataCnt[SOCAPI_SET_TOUCHKEY_TOTAL]; 

int   	xdata 	DifferAccum[SOCAPI_SET_TOUCHKEY_TOTAL]; 
char	xdata	SetNoiseThreshold=SOCAPI_SET_NOISE_THRESHOLD;

//�Զ������
unsigned 	int 	xdata  UpdateBaseLNum; 						// ��������������
unsigned 	int 	xdata  MultipleLNum;						// �ఴ�����ż���

//�ⲿ�����ӿ�
extern 	unsigned	char	data		CurrentChannelMax;		//��ǰѡ�е�keysensor�ĸ���
extern  bit bMultiple;	//�ఴ����־	
extern 	bit GetIsNeedUpdateBaseline(void);
extern  void SetNeedUpdateBaseline(void);
extern  unsigned  int SensorKeyFlag(void);
extern  void MultipleDeal(unsigned char CycleCnt);



//�궨��ӿ�

//=================================================================================	
// �����ӿڵ��ò���

//************************************************************************
// ��������:  ����������ʱ��
// ����: ��
// ���: ��λʱ��
//�������ֵ�����ã� �Ǹ����ж೤ʱ������TouchKeyRestart����һ��
//����12ms ����һ�Σ� ��900*12ms = 10800ms, 10.8s �˰�����Ч��
//************************************************************************
unsigned int SetOneKeyPushResetTime(void)   
{
	return SOCAPI_SET_KEY_CONTI_TIME;  
}

//************************************************************************
// ��������:  ��̬���»��ߵ�ʱ��
// ����: ��
// ���: 
//************************************************************************

unsigned int SetFlowResetTime(void)   
{
	return SOCAPI_SET_SYNC_UPDATE; 
}

//************************************************************************
// ��������: �����ٶ� 
// ����: ��
// ���:��ֵ
// ��ע: ������ֵ��С�� ��ѡ��ֵ0~255.һ������Ϊ120���ϴ�Ĳ�����ֵ
// �ܹ����������Ļ����߸����ٶȡ�
//************************************************************************

int  GetBaselineUpdateThreshold(void)
{
	return SOCAPI_SET_UPDATE_SPEED; 
}

//************************************************************************
// ��������: ��ʼ���Զ�У׼���� 
// ����: ��
// ���:��ֵ
// ��ע: ������ֵ��С�� ��ѡ��ֵ0~100һ������Ϊ48
//************************************************************************
unsigned char GetInitAutoUpdateTime(void)
{
	return SOCAPI_INIT_AUTO_UPDATE_TIME; 
}

//************************************************************************
// ��������: ����CS ����
// ����: ��
// ���: 
// ��ע: 
//************************************************************************
char GetCsFunction(void)
{
	return SOCAPI_SET_CS_FUNCTION; 
}

//************************************************************************
//��������: ��ȡ��ǰ��finger ֵ
//����: index 
//���: �����ָ��ֵ
//************************************************************************
int code FingerThresholdtmp[16]={\
		SOCAPI_KEY0_FINGER_THRESHOLD,\
		SOCAPI_KEY1_FINGER_THRESHOLD,\
		SOCAPI_KEY2_FINGER_THRESHOLD,\
		SOCAPI_KEY3_FINGER_THRESHOLD,\
		SOCAPI_KEY4_FINGER_THRESHOLD,\
		SOCAPI_KEY5_FINGER_THRESHOLD,\
		SOCAPI_KEY6_FINGER_THRESHOLD,\
		SOCAPI_KEY7_FINGER_THRESHOLD,\
		SOCAPI_KEY8_FINGER_THRESHOLD,\
		SOCAPI_KEY9_FINGER_THRESHOLD,\
		SOCAPI_KEY10_FINGER_THRESHOLD,\
		SOCAPI_KEY11_FINGER_THRESHOLD,\
		SOCAPI_KEY12_FINGER_THRESHOLD,\
		SOCAPI_KEY13_FINGER_THRESHOLD,\
		SOCAPI_KEY14_FINGER_THRESHOLD,\
		SOCAPI_KEY15_FINGER_THRESHOLD,		
	};

int  GetCurrFingerValue(unsigned char i)
{
	return FingerThresholdtmp[CurrentChannel[i]]; 
}
//************************************************************************
//��������:����Ƿ��ǵ��ɻ�������˫��
//����: �� 
//���: =1 ��ʾ�ǻ���������˫��
//
//************************************************************************
unsigned char IsDoubleKeyOrSlideKey(void)
{
#if (SOCAPI_SET_SLIDE_KEY_FUNCTION)
	return 1;
#else
	return 0; 
#endif 

}
//************************************************************************
//��������:��ⰴ���������
//����: �� 
//���: ���ذ�������ȷ�ϴ���
//
//************************************************************************

unsigned char GetUpConfirmCnt(void)
{
	return ConfirmTouchCnt>>1;
}

//************************************************************************
//��������:��ȡ��������ȷ�ϴ���
//����: �� 
//���: �������ƴ���
//
//************************************************************************

unsigned char GetTKYzCnt(void)
{
	return (ConfirmTouchCnt/3);
}

//************************************************************************
//��������:��ȡ������������
//����: �� 
//���: ������������
//
//************************************************************************
int GetTKYzThreshold(unsigned char i)
{	
	int SetFingerThresholdtmp; 
	
	SetFingerThresholdtmp = GetCurrFingerValue(i); 
	SetFingerThresholdtmp = SetFingerThresholdtmp*SOCAPI_INHIBITION_ZONE/10;
	return SetFingerThresholdtmp;
}

//*************************************************************
// ������	��void CurrentSensorChoose(void)
// ����		��
// ����		����ǰͨ��ѡ��
// ����		����
// ����ֵ	����
// ����ȫ�ֱ�������
// �޸�ȫ�ֱ�������
// ��ע		��
//**************************************************************
void CurrentSensorChoose(void)
{
	unsigned char  	i;
	unsigned char  	Ctk_Channel_mark = 0;
	unsigned int	CurrentSensorKey; 
	
	CurrentSensorKey = SOCAPI_SET_TOUCHKEY_CHANNEL; 
		
	for(i=0;i<16;i++)
	{
		CurrentSensorKey=CurrentSensorKey>>1;
		if(CY)
		{
			CurrentChannel[Ctk_Channel_mark] = i;						//ѡ������ǰ��ͨ��
			Ctk_Channel_mark++;
			if(Ctk_Channel_mark >= SOCAPI_SET_TOUCHKEY_TOTAL)
				break;
		}		
	}
	CurrentChannelMax = Ctk_Channel_mark;							//��ǰѡ��İ����� 
}

//*************************************************************
// ������	��void TouchKeyCFGInit(void)
// ����		��
// ����		����ʼ��TK �Ĵ�����
// ����		����
// ����ֵ	����
// ����ȫ�ֱ�������
// �޸�ȫ�ֱ�������
// ��ע		��
//**************************************************************
void TouchKeyCFGInit(void)
{
	CurrentSensorChoose(); 
	TKCON = 0x80;									//��Touch Key��Դ;ѡ���ڽ���ѹԴ;    
    TKCFG0 = ((SOCAPI_SET_TKCFG3&0x0f)<<4)|(SOCAPI_SET_TKCFG2&0x0f);
    TKCFG1 = ((SOCAPI_SET_TKCFG1&0x10)<<3)|(SOCAPI_SET_TKCFG2&0x30)|((SOCAPI_SET_TKCFG3&0x70)>>4);   
	UpdateBaseLNum = 0; 
}

//*************************************************************
//			��ⰴ���ӿ�
//����: ��
//���:����ͨ���� ���ص���һ��int , ͨ������ 
//��ע: �����������˼�������
//  1, ���ô��ؿ��⺯��SensorKeyFlag()
// 2,  �����ó�16��ͨ�����ĸ�ͨ���а��£�����bit λ����Ϊ1������Ϊ0
// 3,  ����Ƿ���Ҫ��������baseline:  ����MAX_KEY_RESET_BASELINE ����������ʱ��������baseline
// 4,  ˫�����ߵ�������ʱ�� ʱ�����SetOneKeyPushResetTime()���ʱ����baseline 
//*************************************************************
unsigned int TouchKeyScan(void)
{
	unsigned char t;
	unsigned char MultipleCnt = 0;//��������
	unsigned int Keyvalue; 
	unsigned int KeyData = 0; 	

	if(GetIsNeedUpdateBaseline() == 0)				//����Ƿ���Ҫ����baseline 
	{
		Keyvalue = SensorKeyFlag();					//Sensor�ж�, �������bMultiple = 1 ��ʾ�м��и���
	  												//�����������ó���׼��16ͨ��bit λ
		for(t=0;t<CurrentChannelMax;t++)
		{
			Keyvalue = Keyvalue>>1;
			if(CY)
			{
				KeyData |= (0x01 << (CurrentChannel[t])); 	
				MultipleCnt++;							
			}
		}

		if(MultipleCnt >= 2) 	 									//����ఴ������
		{
			
			bMultiple = 1;
			
			if(MultipleCnt >= SOCAPI_MAX_KEY_NUM_INVALID)
			{
				SetNeedUpdateBaseline(); 							// ��������baseline ,�����ǿ��������ȥ
			}
			else
			{		
				#if (SOCAPI_SET_SLIDE_KEY_FUNCTION)   //���ɻ����Ļ�������������Ϊ�Ƕ��
					bMultiple=0; 
				#endif  
			}			
		}			

		if(bMultiple == 0)							//���밴���ж�
		{		
			if(KeyData != 0x0)					    //���������ﵽ�೤ʱ���update baseline ,���ּ��
			{
				UpdateBaseLNum++; 
			}
			else	
			{
				UpdateBaseLNum = 0; 	
			} 
		}	
		else
		{   
		    //���ǻ��߸���		
			MultipleLNum++; 
			KeyData = 0x00;
		}

		if(UpdateBaseLNum > SetOneKeyPushResetTime())	  //������������ʱ����»���
		{
 			SetNeedUpdateBaseline(); 
			UpdateBaseLNum = 0;
		}
		if(MultipleLNum > SOCAPI_MAX_KEY_MUTIPLE)		  //���ż����������������»���
 		{
			SetNeedUpdateBaseline(); 
			MultipleLNum = 0;
		}
	
	}			
	else
	{
		MultipleDeal(SOCAPI_AUTO_UPDATE_TIME);										//���߸�λ����
	}
	
	return KeyData;
}




