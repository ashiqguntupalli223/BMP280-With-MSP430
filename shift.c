#include "shift.h"


 u8 reg_r_value[8];
 u8 receive[8];
 u16 temp;
 u16 press;
 s32 adc_T_value;
 s32 adc_P_value;
 
s32 adc_T(u8 *reg_r_value)
{
 
  receive[0]= reg_r_value[0];
  receive[1]= reg_r_value[1];
  receive[2]= reg_r_value[2];
  receive[3]= reg_r_value[3];
//  receive[4]= reg_r_value[4];

  
  
  temp = receive[3];

  temp= temp<<8;
  temp=temp;
  temp |= receive[2];
 
  adc_T_value  =  temp;
  adc_T_value  =  adc_T_value <<8;
  adc_T_value |=  receive[1];
  adc_T_value  =  adc_T_value>>4;
  adc_T_value  =  adc_T_value;
  
  return adc_T_value;

}

s32 adc_P(u8 *reg_r_value)
{
  
  receive[4]= reg_r_value[4];
  receive[5]= reg_r_value[5];
  receive[6]= reg_r_value[6];
  receive[7]= reg_r_value[7];
  
  press = receive[6];

  press= press<<8;
  press=press;
  press |= receive[5];
 
  adc_P_value  =  press;
  adc_P_value  =  adc_P_value <<8;
  adc_P_value |=  receive[4];
  adc_P_value  =  adc_P_value>>4;
  adc_P_value  =  adc_P_value;
 
  return adc_P_value;
 
} 
  
  
  
  
  
  
  
  
  
  