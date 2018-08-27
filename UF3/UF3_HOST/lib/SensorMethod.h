#ifndef	_SENSORMETHOD_C_H
#define	_SENSORMETHOD_C_H
//外部变量
extern	unsigned	char	xdata	SOCAPI_TouchKeyStatus;			//API接口状态：bit7-一轮扫描完成标志								
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
#define  bSensorCycleDone			0x80							//表示一轮扫描完成标志。				
#define  bSensorTimeOut				0x40							//触控溢出标志

//外部调用函数
extern	void  TouchKeyInit(void);								//触摸按键初始化
extern	void  TouchKeyRestart(void);							//当前通道使能
extern	unsigned int  TouchKeyScan(void);							//触摸按键扫描
////按键按下的标志， 每bit 表示一个通道，0 表示没有按下

#endif 
