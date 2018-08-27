//*************************************************************************************************
//  Copyright (c) 	深圳市赛元微电子有限公司
//	文件名称	:  S_TouchKeyCFG.h
//	作者		: 
//	模块功能	:  触控键配置文件
// 	版本		:
// 	更改记录	:
//	注意事项	:  用户配置文件，用户可修改
//************************************************************************************************
#ifndef __S_TOUCHKEYCFG_H__
#define __S_TOUCHKEYCFG_H__

//==========================================================================
//触控按键基本配置部分，用户可修改
//触控按键寄存器设置
//==========================================================================
//TKCFG1:
// bit[4] =    PRS             调频开关
// bit[3:0] =  Not define      未定义
//TKCFG2:
// bit[5:4] =  CMPFLTS         滤波设置
// bit[3:0] =  CTIME           充放电频率
//TKCFG3:
// bit[6:4] =  SVSS            充电稳压源电压
// bit[3:0] =  VREF            参考电压
//-----------------------------------------------------------------------
#define			SOCAPI_SET_TKCFG1						    0x00 	//默认设置：0x00//SFR:TKCFG1配置；bit7-bit4(PRS);bit3-bit0(NULL)					
#define			SOCAPI_SET_TKCFG2							0x15    //默认设置：0x15//SFR:TKCFG2配置: bit7-bit4(CMPFLTS);bit3-bit0(CTIME)		
#define			SOCAPI_SET_TKCFG3							0x36    //默认设置：0x36//SFR:TKCFG3配置: bit7-bit4(SVSS);bit3-bit0(VREF)	
//---------------------------------------------------------------------------

//触控按键的个数，通道设置，每bit控制一个通道
#define		    SOCAPI_SET_TOUCHKEY_TOTAL					4		//用户实际使用的按键通道的数量,如用户使用TK8~TK15共8个键,只填8； 
#define			SOCAPI_SET_TOUCHKEY_CHANNEL					0x80C2  //bit15~bit0对应TK15~TK0;  对应为置1则为TK，对应位置0则为IO

//触控按键的程序检测确认次数
#define			SOCAPI_SET_TOUCHKEY_CONFIRM_CNT				8 	 	//确认按键次数(4~30之间，检测次数越大，反应越慢)

//触控按键的噪音值
#define			SOCAPI_SET_NOISE_THRESHOLD					30		//设置噪音阈值范围:16~40

//每一路通道触控按键的手指阈值，范围0~65535，此为有效差值=（baseline-Finger）*0.6，数值越大，灵敏度越低，反之亦然。
//baseline为手指没按下的rawdata值,Finger为手指按下后的rawdata值
//乘以0.6是留点余量，因为每个人的手指接触面积不一样,用户也可根据触摸效果适当的增加或减小。
//用户只需要设置实际使用的通道手指阈值，其余没用到的通道可以随机数; 

#define			SOCAPI_KEY0_FINGER_THRESHOLD				1000 
#define			SOCAPI_KEY1_FINGER_THRESHOLD				200//100
#define			SOCAPI_KEY2_FINGER_THRESHOLD				300
#define			SOCAPI_KEY3_FINGER_THRESHOLD				350

#define			SOCAPI_KEY4_FINGER_THRESHOLD				300 
#define			SOCAPI_KEY5_FINGER_THRESHOLD				300
#define			SOCAPI_KEY6_FINGER_THRESHOLD				300//300//375//300 
#define			SOCAPI_KEY7_FINGER_THRESHOLD				300//490//1000

#define			SOCAPI_KEY8_FINGER_THRESHOLD				1000
#define			SOCAPI_KEY9_FINGER_THRESHOLD				1000
#define			SOCAPI_KEY10_FINGER_THRESHOLD				1000
#define			SOCAPI_KEY11_FINGER_THRESHOLD				1000

#define			SOCAPI_KEY12_FINGER_THRESHOLD				1000 
#define			SOCAPI_KEY13_FINGER_THRESHOLD				1000 
#define			SOCAPI_KEY14_FINGER_THRESHOLD				1000 
#define			SOCAPI_KEY15_FINGER_THRESHOLD				300//480//1000


//=0 表示单键, = 1 表示双键或者滑条	 2014-11-28
#define 		SOCAPI_SET_SLIDE_KEY_FUNCTION				0		//0:表示单键, 1:表示组合双键或者滑条

//---------------------------------------------------------------------------
//-------------------以下参数不允许用户修改----------------------------------
#define 		SOCAPI_SET_UPDATE_SPEED						120		//白噪声下基线更新速度,设置范围0~255.默认120
#define			SOCAPI_SET_KEY_CONTI_TIME					50000//5000	//按键有效的最长输出时间,设置范围0~5000，默认1000，输出时间= 1000*单位每轮扫描时间（如10ms）=10S
#define			SOCAPI_SET_SYNC_UPDATE						450		//动态更新基线的时间,设置范围0~1000，默认450
#define			SOCAPI_INIT_AUTO_UPDATE_TIME				48		//初始化自动校准次数，设置范围0--100，默认48
#define			SOCAPI_AUTO_UPDATE_TIME						2		//多键强制基线复位速度，设置范围2-5，默认2	如复位时间=2*8*每轮扫描时间（10ms）=80ms
#define			SOCAPI_MAX_KEY_NUM_INVALID					3		//强制更新基线按键限制个数，默认3
#define			SOCAPI_INHIBITION_ZONE					    7		//抑制区间，设置范围5-10，默认7,即（7*10）%=70% ，连水时加大该参数
#define  		SOCAPI_FINGER_MAX_VALUE						2000	//抗干扰消顶参数，默认2000
#define			SOCAPI_SET_CS_FUNCTION						1		//0:表示不进行CS测试,1: 表示进行CS测试,默认0
#define			SOCAPI_MAX_KEY_MUTIPLE						300		//多键干扰计数，达到计数值更新基线，默认300*单位每轮扫描时间（如10ms）=1.5S

#endif //__S_TOUCHKEYCFG_H__
//===========================================================================


