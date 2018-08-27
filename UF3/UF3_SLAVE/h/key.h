#ifndef _KEY_H_
#define _KEY_H_


#include "h\SC92F732X_C.h"
#include "732X_IO.h"

#define IO_KEY6_PIN     P25
#define IO_KEY5_PIN     P24

#define IO_KEY_CONTROL_PIN   P00

#define IO_KEY6_DOWN   IO_KEY6_PIN = 0;
#define IO_KEY6_UP     IO_KEY6_PIN = 1;

#define IO_KEY5_DOWN   IO_KEY5_PIN = 0;
#define IO_KEY5_UP     IO_KEY5_PIN = 1; 

#define IO_KEY_CONTROL_DOWN     IO_KEY_CONTROL_PIN = 0;
#define IO_KEY_CONTROL_UP       IO_KEY_CONTROL_PIN = 1;



void Key_Init(void);

#endif