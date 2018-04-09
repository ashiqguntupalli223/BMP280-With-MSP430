#ifndef CLOCK_H_
#define CLOCK_H_
#include "global.h"

#define CLK_Default      1048576
#define CLK_8MHz         8192000
#define CLK_12MHz       12288000
#define CLK_25MHz       25001984

#define clk_used CLK_8MHz
#define cycles_01Hz      (u32)(9.999*clk_used)
#define cycles_05Hz      (u32)(4.999*clk_used)
#define cycles_1Hz       (u32)(0.999*clk_used)
#define cycles_5Hz      (u32)(0.499*clk_used)
#define cycles_10Hz      (u32)(0.099*clk_used)

u32 Set_clk_Freq_8MHz(void);                                                                                                       
u32 Set_clk_Freq_12MHz(void);
u32 Set_clk_Freq_25MHz(void);  
void SetVcoreUp (unsigned int level);

#endif