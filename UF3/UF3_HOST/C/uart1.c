#include "uart1.h"


void Uart1_Init(int Freq,long int baud)
{
	OTCON = 0xC0;    //���нӿ�SSIѡ��Uart1ͨ��
	SSCON0 = 0x50;   //����ͨ�ŷ�ʽΪģʽһ���������
	SSCON1 = Freq*1000000/baud;   //�����ʵ�λ����
	SSCON2 = (Freq*1000000/baud)>>8;   //�����ʸ�λ����
	IE1 = 0x01;      //����SSI�ж�
  //EA = 1;	
}



