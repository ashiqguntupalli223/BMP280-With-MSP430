#define U32 unsigned long int
#define S32 long int
#define U16 unsigned short int
#define S16 short int
#define U8  unsigned char
#define S8  char

#define u32 unsigned long int
#define s32 long int
#define u16 unsigned short int
#define s16 short int
#define u8  unsigned char
#define s8  char
/*
#define uint32_t u32
#define uint16_t u16
#define uint8_t  u8
#define sint32_t s32
#define sint16_t s16
#define sint8_t  s8
*/
#define HIGH    1
#define LOW     0

#include "io430.h"
//#include <msp430.h>
//#include "Register.h"
//#include "Pin_Distributions.h"
//#include "platform.h"
#include "stdint.h"

void Dec2Str(s32 dec, u8* str);
void Double2Str(double x, u8* str);

void bin2Chars(int value, u8 *destbuf);
void bin2Hex(char value, u8 *destbuf);


void delay(u16 kCycles);