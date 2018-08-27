#ifndef	_SENSORMETHOD_C_H
#define	_SENSORMETHOD_C_H
//�ⲿ����
extern	unsigned	char	xdata	SOCAPI_TouchKeyStatus;			//API�ӿ�״̬��bit7-һ��ɨ����ɱ�־								
extern 	unsigned 	char	xdata	ConfirmTouchCnt;								
extern 	unsigned 	int		xdata 	RawData[];			 				
extern 	unsigned 	int		xdata	BaseLine[];	
extern	unsigned  	int	 	xdata  	FilterData[];					 
extern	unsigned 	int 	xdata 	CurrentSensorKey;		 				
extern 	unsigned	char  	idata 	RestAreaCnt[]; 					 
extern 	unsigned	char  	idata 	TouchCnt[];
extern 	unsigned	char  	idata 	NoTouchCnt[];  			  
extern  unsigned	char 	xdata 	CurrentChannel[];			 
extern 	int                 xdata 	DifferAccum[];
extern 	char	            xdata	SetNoiseThreshold;	
extern unsigned  char       idata   LowFingerDataCnt[]; 

//SOCAPI_TouchKeyStatus
#define  bSensorCycleDone			0x80							//��ʾһ��ɨ����ɱ�־��				
#define  bSensorTimeOut				0x40							//���������־

//�ⲿ���ú���
extern	void  TouchKeyInit(void);								//����������ʼ��
extern	void  TouchKeyRestart(void);							//��ǰͨ��ʹ��
extern	unsigned int  TouchKeyScan(void);							//��������ɨ��
////�������µı�־�� ÿbit ��ʾһ��ͨ����0 ��ʾû�а���

#endif 