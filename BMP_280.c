
#include "BMP_280.h"


      
      uint16_t dig_T1;
      int16_t  dig_T2;
      int16_t  dig_T3;
      
      
      uint16_t dig_P1;
      int16_t  dig_P2;
      int16_t  dig_P3;
      int16_t  dig_P4;
      int16_t  dig_P5;
      int16_t  dig_P6;
      int16_t  dig_P7;
      int16_t  dig_P8;
      int16_t  dig_P9;

void Initialize()

{
   dig_T1= 27504;
   dig_T2= 26435;
   dig_T3= -1000;
   dig_P1 = 36477;
   dig_P2= -10685;
   dig_P3= 3024;
   dig_P4= 2855;
   dig_P5= 140;
   dig_P6 = -7;
   dig_P7= 15500;
   dig_P8= -14600;
   dig_P9= 6000;
 }  

        
// Returns temperature in DegC, double precision. Output value of “51.23” equals 51.23 DegC.***************************************//
// t_fine carries fine temperature as global value


double bmp280_compensate_T_double(s32 adc_T)
{
extern s32 t_fine;
double var1, var2, T;
var1 = (((double)(adc_T))/16384.0 - (27504/1024.0))* (26435);
var1=var1;
var2 = ((((double)adc_T/131072.0 - (27504/8192.0)) *(((double)adc_T)/131072.0 - (27504/8192.0))) * (-1000));
var2=var2;
t_fine = (s32)(var1 + var2);
t_fine=t_fine;
T = (var1 + var2) / 5120.0;
T=T;
return T;
}

//******Returns pressure in Pa as double. Output value of “96386.2” equals 96386.2 Pa = 963.862 hPa*******************************//
double bmp280_compensate_P_double(s32 adc_P)
{
 extern s32 t_fine;
double var1, var2, p;
var1 = ((double)t_fine/2.0) - 64000.0;
var2 = var1 * var1 * (-7) / 32768.0;
var2 = var2 + var1 * (140) * 2.0;
var2 = (var2/4.0)+((2855) * 65536.0);
var1 = ((3024) * var1 * var1 / 524288.0 + (-10685) * var1) / 524288.0;
var1 = (1.0 + var1 / 32768.0)*(36477);
if (var1 == 0.0)
{
return 0;                                                  // avoid exception caused by division by zero
}
p = 1048576.0 - (double)adc_P;
p = (p - (var2 / 4096.0)) * 6250.0 / var1;
var1 = (6000) * p * p / 2147483648.0;
var2 = p * (-14600) / 32768.0;
p = p + (var1 + var2 + (15500)) / 16.0;
return p;
}

