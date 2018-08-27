//*************************************************************************************************
//  Copyright (c) 	深圳市赛元微电子有限公司
//	文件名称	:  S_TouchKeyCFG.c
//	作者		: 
//	模块功能	:  触控键配置文件
// 	版本		:
// 	更改记录	:
//	注意事项	:  用户需要配置的文件在S_TouchKeyCFG.h中
//  库版本标记	: 
//************************************************************************************************

#include "lib\S_TouchKeyCFG.h"

//===========================================================================
//寄存器定义
/*TouchKey*/
sfr     TKCON   = 0XE8;
sfr     TKCFG1  = 0XE2;
sfr     TKCFG0  = 0XE1;

/*PSW*/
sfr 	PSW	    = 	0xD0;	//程序状态字
sbit 	CY		= 	PSW^7;	//进位

//===========================================================================
//全局变量定义
unsigned	char	xdata	SOCAPI_TouchKeyStatus;					//API接口状态：bit7-一轮扫描完成标志  1:完成 	0：未完成
																	//			   bit6-通道触摸计数溢出标志 1:溢出	 0:未溢出
//===============================================================================
//全局变量声明：该区域不可修改
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

//自定义变量
unsigned 	int 	xdata  UpdateBaseLNum; 						// 单键长按计数器
unsigned 	int 	xdata  MultipleLNum;						// 多按键干扰计数

//外部变量接口
extern 	unsigned	char	data		CurrentChannelMax;		//当前选中的keysensor的个数
extern  bit bMultiple;	//多按键标志	
extern 	bit GetIsNeedUpdateBaseline(void);
extern  void SetNeedUpdateBaseline(void);
extern  unsigned  int SensorKeyFlag(void);
extern  void MultipleDeal(unsigned char CycleCnt);



//宏定义接口

//=================================================================================	
// 函数接口调用部分

//************************************************************************
// 函数功能:  按键最长的输出时间
// 输入: 无
// 输出: 复位时间
//这个返回值的设置， 是根据有多长时间启动TouchKeyRestart（）一次
//例如12ms 启动一次， 那900*12ms = 10800ms, 10.8s 此按键无效。
//************************************************************************
unsigned int SetOneKeyPushResetTime(void)   
{
	return SOCAPI_SET_KEY_CONTI_TIME;  
}

//************************************************************************
// 函数功能:  动态更新基线的时间
// 输入: 无
// 输出: 
//************************************************************************

unsigned int SetFlowResetTime(void)   
{
	return SOCAPI_SET_SYNC_UPDATE; 
}

//************************************************************************
// 函数功能: 更新速度 
// 输入: 无
// 输出:阈值
// 备注: 定义阈值大小， 可选的值0~255.一般设置为120，较大的参数数值
// 能够产生较慢的基本线更新速度。
//************************************************************************

int  GetBaselineUpdateThreshold(void)
{
	return SOCAPI_SET_UPDATE_SPEED; 
}

//************************************************************************
// 函数功能: 初始化自动校准次数 
// 输入: 无
// 输出:阈值
// 备注: 定义阈值大小， 可选的值0~100一般设置为48
//************************************************************************
unsigned char GetInitAutoUpdateTime(void)
{
	return SOCAPI_INIT_AUTO_UPDATE_TIME; 
}

//************************************************************************
// 函数功能: 进行CS 测试
// 输入: 无
// 输出: 
// 备注: 
//************************************************************************
char GetCsFunction(void)
{
	return SOCAPI_SET_CS_FUNCTION; 
}

//************************************************************************
//函数功能: 获取当前的finger 值
//输入: index 
//输出: 输出手指阈值
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
//函数功能:检测是否是弹簧滑条或者双键
//输入: 无 
//输出: =1 表示是滑条或者是双键
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
//函数功能:检测按键弹起次数
//输入: 无 
//输出: 返回按键弹起确认次数
//
//************************************************************************

unsigned char GetUpConfirmCnt(void)
{
	return ConfirmTouchCnt>>1;
}

//************************************************************************
//函数功能:获取按键抑制确认次数
//输入: 无 
//输出: 返回抑制次数
//
//************************************************************************

unsigned char GetTKYzCnt(void)
{
	return (ConfirmTouchCnt/3);
}

//************************************************************************
//函数功能:获取按键抑制区间
//输入: 无 
//输出: 返回抑制区间
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
// 函数名	：void CurrentSensorChoose(void)
// 作者		：
// 功能		：当前通道选择
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：
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
			CurrentChannel[Ctk_Channel_mark] = i;						//选择触摸当前的通道
			Ctk_Channel_mark++;
			if(Ctk_Channel_mark >= SOCAPI_SET_TOUCHKEY_TOTAL)
				break;
		}		
	}
	CurrentChannelMax = Ctk_Channel_mark;							//当前选择的按键数 
}

//*************************************************************
// 函数名	：void TouchKeyCFGInit(void)
// 作者		：
// 功能		：初始化TK 寄存器等
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：
//**************************************************************
void TouchKeyCFGInit(void)
{
	CurrentSensorChoose(); 
	TKCON = 0x80;									//打开Touch Key电源;选择内建稳压源;    
    TKCFG0 = ((SOCAPI_SET_TKCFG3&0x0f)<<4)|(SOCAPI_SET_TKCFG2&0x0f);
    TKCFG1 = ((SOCAPI_SET_TKCFG1&0x10)<<3)|(SOCAPI_SET_TKCFG2&0x30)|((SOCAPI_SET_TKCFG3&0x70)>>4);   
	UpdateBaseLNum = 0; 
}

//*************************************************************
//			检测按键接口
//输入: 无
//输出:按键通道， 返回的是一个int , 通道数。 
//备注: 这个函数完成了几个内容
//  1, 调用触控库检测函数SensorKeyFlag()
// 2,  分析得出16个通道，哪个通道有按下，按下bit 位设置为1，否则为0
// 3,  检测是否需要立即更新baseline:  大于MAX_KEY_RESET_BASELINE 个按键按下时立即更新baseline
// 4,  双键或者单键按下时， 时间大于SetOneKeyPushResetTime()结果时更新baseline 
//*************************************************************
unsigned int TouchKeyScan(void)
{
	unsigned char t;
	unsigned char MultipleCnt = 0;//按键计数
	unsigned int Keyvalue; 
	unsigned int KeyData = 0; 	

	if(GetIsNeedUpdateBaseline() == 0)				//检测是否需要更新baseline 
	{
		Keyvalue = SensorKeyFlag();					//Sensor判断, 这里如果bMultiple = 1 表示中间有干扰
	  												//分析按键，得出标准的16通道bit 位
		for(t=0;t<CurrentChannelMax;t++)
		{
			Keyvalue = Keyvalue>>1;
			if(CY)
			{
				KeyData |= (0x01 << (CurrentChannel[t])); 	
				MultipleCnt++;							
			}
		}

		if(MultipleCnt >= 2) 	 									//进入多按键处理
		{
			
			bMultiple = 1;
			
			if(MultipleCnt >= SOCAPI_MAX_KEY_NUM_INVALID)
			{
				SetNeedUpdateBaseline(); 							// 立即更新baseline ,例如亚克力板盖上去
			}
			else
			{		
				#if (SOCAPI_SET_SLIDE_KEY_FUNCTION)   //弹簧滑条的滑条键按下则不认为是多键
					bMultiple=0; 
				#endif  
			}			
		}			

		if(bMultiple == 0)							//进入按键判断
		{		
			if(KeyData != 0x0)					    //单个按键达到多长时间就update baseline ,松手检测
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
		    //考虑基线更新		
			MultipleLNum++; 
			KeyData = 0x00;
		}

		if(UpdateBaseLNum > SetOneKeyPushResetTime())	  //按键超出最长输出时间更新基线
		{
 			SetNeedUpdateBaseline(); 
			UpdateBaseLNum = 0;
		}
		if(MultipleLNum > SOCAPI_MAX_KEY_MUTIPLE)		  //干扰计数大于最大计数更新基线
 		{
			SetNeedUpdateBaseline(); 
			MultipleLNum = 0;
		}
	
	}			
	else
	{
		MultipleDeal(SOCAPI_AUTO_UPDATE_TIME);										//基线复位处理
	}
	
	return KeyData;
}





