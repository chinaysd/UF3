#ifndef _TEST_LED_H_
#define _TEST_LED_H_




#include "SC92F837X_C.h"

#define   LED_ENABLE     1
#define   LED_DISABLE    0

#if LED_ENABLE
#define IO_LED1_PIN     P01
#define IO_LED2_PIN     P20
#define IO_LED3_PIN     P21
#define IO_LED4_PIN     P12

#define IO_LED1_OPEN    IO_LED1_PIN = 1;
#define IO_LED2_OPEN    IO_LED2_PIN = 1;
#define IO_LED3_OPEN    IO_LED3_PIN = 1;
#define IO_LED4_OPEN    IO_LED4_PIN = 1;

#define IO_LED1_CLOSE    IO_LED1_PIN = 0;
#define IO_LED2_CLOSE    IO_LED2_PIN = 0;
#define IO_LED3_CLOSE    IO_LED3_PIN = 0;
#define IO_LED4_CLOSE    IO_LED4_PIN = 0;

#define IO_LED1_RESET    IO_LED1_PIN = ~IO_LED1_PIN;

#endif


void Led_Init(void);
void Led_Open(void);
void Led_Close(void);
void Led_Reset(void);





#endif