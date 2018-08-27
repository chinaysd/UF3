
//************************************************************
//  Copyright (c) 深圳市赛元微电子有限公司
//	文件名称	: ADC.c
//	作者		: 
//	模块功能	: ADC转换的使用
//	局部函数列表:
//  最后更正日期:
// 	版本		:
// 	更改记录	:rom前256byte禁止查表,因此在编译的时候，设置keil->option for Target->BL51 Locate->Code Range:0x100
//*************************************************************
#include "h\SC92F732X_C.h"
unsigned int	 adcdat;
//*************************************************************
// 函数名	：void ADC_init(void)
// 作者		：
// 功能		：ADC转换初始化
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：
//**************************************************************	
void ADC_init()
{
	ADCCON =0X80;  //选择AIN0作为输入通道，2M采样频率,打开ADC电源
//	ADCCON =0X81;  //选择AIN1作为输入通道，2M采样频率,打开ADC电源
//	ADCCON =0X82;  //选择AIN2作为输入通道，2M采样频率,打开ADC电源
//	ADCCON =0X83;  //选择AIN3作为输入通道，2M采样频率,打开ADC电源
//	ADCCON =0X84;  //选择AIN4作为输入通道，2M采样频率,打开ADC电源
//	ADCCON =0X85;  //选择AIN5作为输入通道，2M采样频率,打开ADC电源
//	ADCCON =0X86;  //选择AIN6作为输入通道，2M采样频率,打开ADC电源
//	ADCCON =0X87;  //选择AIN7作为输入通道，2M采样频率,打开ADC电源
//	ADCCON =0X88;  //选择AIN8作为输入通道，2M采样频率,打开ADC电源
//	ADCCON =0X89;  //选择AIN9作为输入通道，2M采样频率,打开ADC电源
	ADCCFG0=0X01;  //选择AIN0为ADC输入；
	ADCCFG1=0X00;
//	ADCCFG0=0X02;  //选择AIN1为ADC输入；
//	ADCCFG1=0X00;
//	ADCCFG0=0X04;  //选择AIN2为ADC输入；
//	ADCCFG1=0X00;
//	ADCCFG0=0X08;  //选择AIN3为ADC输入；
//	ADCCFG1=0X00;
//	ADCCFG0=0X10;  //选择AIN4为ADC输入；
//	ADCCFG1=0X00;
//	ADCCFG0=0X20;  //选择AIN5为ADC输入；
//	ADCCFG1=0X00;
//	ADCCFG0=0X40;  //选择AIN6为ADC输入；
//	ADCCFG1=0X00;
//	ADCCFG0=0X80;  //选择AIN7为ADC输入；
//	ADCCFG1=0X00;
//	ADCCFG0=0X00;  //选择AIN8为ADC输入；
//	ADCCFG1=0X01;
//	ADCCFG0=0X00;  //选择AIN9为ADC输入；
//	ADCCFG1=0X02;						
}
//*************************************************************
// 函数名	：void  ADC_Convert(void)
// 作者		：
// 功能		：ADC转换过程
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：
//**************************************************************	
void  ADC_Convert(void)						
{													
	ADCCON =0XC0 |0x00;                           //启动ADC转换	
	P00=0;
	while(!(ADCCON&0x10));	         		 //等待 ADC转换完成;
	P00=1;
	adcdat=ADCVH;		   					 //ADC高8位存入8位寄存器
	adcdat = (adcdat<<8)+ADCVL;			     //取得adc的值
	adcdat =  adcdat>>4;
	ADCCON &= 0xEF;   						 //转换完毕，清EOC	
		
}
void delay()
{
	unsigned int i;
	i=10000;
	while(i--);
}
//*************************************************************
// 函数名	：void main()
// 作者		：
// 功能		：主函数
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：
//**************************************************************
unsigned char adc_cnt=0;
unsigned int adc_8chi=0;
void main()
{											 	
	WDTCON  = 0x10;				             //清看门狗，500ms溢出
	ADC_init();
//	P0VO=0X1F;
//	OTCON=0X04;
	P0CON=0XFF;
	P00=1;
	while(1)
	{
//		adc_8chi=0;
//		for(adc_cnt=0;adc_cnt<8;adc_cnt++)
//		{
			
			ADC_Convert();		                 //ADC转换
//			adc_8chi +=adcdat;
//			WDTCON |= 0x10;			             //清看门狗
//		}
//		adc_8chi =adc_8chi>>3;
		WDTCON |= 0x10;			             //清看门狗
		delay();
//		ADCCON =0X00;
	}	 	
}