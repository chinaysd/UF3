#ifndef _PUSH_H_
#define _PUSH_H_


#include "h\SC92F732X_C.h"
#include "732X_IO.h"




#define IO_PUSHA1_PIN      P04
#define IO_PUSHA2_PIN      P05
#define IO_PUSHB1_PIN      P26
#define IO_PUSHB2_PIN      P27


#define PUSHA1_OPEN   IO_PUSHA1_PIN=1;
#define PUSHA1_CLOSE  IO_PUSHA1_PIN=0; 

#define PUSHA2_OPEN   IO_PUSHA2_PIN=1;
#define PUSHA2_CLOSE  IO_PUSHA2_PIN=0; 

#define PUSHB1_OPEN   IO_PUSHB1_PIN=1;
#define PUSHB1_CLOSE  IO_PUSHB1_PIN=0; 

#define PUSHB2_OPEN   IO_PUSHB2_PIN=1;
#define PUSHB2_CLOSE  IO_PUSHB2_PIN=0; 


void Push_Init(void);








#endif