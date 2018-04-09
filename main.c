#include "platform.h"
#include "SMCLK.h"
#include "Pin_Distributions.h"
#include "Config.h"
#include "global.h"
#include "BMP_280.h"
#include "shift.h"
 
u8 Transmit[10];
u8 Meas_Receive[8];
s32 raw_T_value;
s32 raw_P_value;
double Temperature;
double Pressure;
u8 slave_addr1= 0x76;
char connect='S';
char start='S'; 

s32 t_fine;
  u32 baudrate  =  115200;                                                      //bps
  u32 Freq_I2C  =     200;                                                      //kHz
  u32 Clock_Frequency=CLK_Default;
//  int divisor = 2; 
void main(void)
{
 
WDTCTL=WDTPW+WDTHOLD; // Stop WatchDogTimer
 Clock_Frequency=Set_clk_Freq_8MHz();
 SetupUART(Port_USB,Clock_Frequency,baudrate);
 SetupI2C_Master(ucb1,Clock_Frequency, Freq_I2C);
  
   Transmit[0]= 0xF4;
   Transmit[1]= 0X83;
   Transmit[2]= 0xF5;
   Transmit[3]= 0X10;
   Transmit[4]= 0xF7;
//  
//  // pin for SDA 4.1
//  setpinselhigh(I2C_SDA);
//  // pin for SCL 4.2
//  setpinselhigh(I2C_SCL);
//  // I2C initialistaion
  
  
  
  char c;
  while(1)
  {
    c=0x00;
    while(c==0x00)      c = ReadUART_Byte(uca1);                                //scan untill command received
    
    switch (c)
    {
     case 'E':
     SendUART_Byte(uca1,connect);                                        //For automatic port connection
     break;
     
   case '1':                                                             //continous measurement T and P
    while(1)
    {
  I2C_Master_Read_TimeOut(ucb1, Meas_Receive, 8, slave_addr1);
  I2C_Master_Write_TimeOut(ucb1, Transmit, 5, slave_addr1);
  I2C_Master_Read_TimeOut(ucb1, Meas_Receive, 8, slave_addr1);
     
          raw_T_value    = adc_T(Meas_Receive);                                               // Taking three bytes of raw data from temperature registers and storing it in the signed 32 bit     
          Temperature    = bmp280_compensate_T_double(raw_T_value);                           // assigning the 32 bit value to the temperature conversion
          raw_P_value    = adc_P(Meas_Receive);                                               // Taking three bytes of raw data from temperature registers and storing it in the signed 32 bit     
          Pressure   = bmp280_compensate_P_double(raw_P_value);                           // assigning the 32 bit value to the temperature conversion

           WriteUART(Port_USB,&start,1);  
           WriteUART(Port_USB,&Temperature,4);                        //Transmits the data from the sensors to PC    
           WriteUART(Port_USB,&Pressure,4);                        //Transmits the data from the sensors to PC  
          
           if(UCA1IFG&UCRXIFG)                                                  //if something received through backchannel uart
          {
            if (UCA1RXBUF == 'q')                                               // if 'q' is recieved the while is stopped, continous measuremnt is stopped
            break;
          }
        }
        break;
    
    case '2':  
    while(1)                                                                // continous measurement P
    {
  I2C_Master_Read_TimeOut(ucb1, Meas_Receive, 8, slave_addr1);
  I2C_Master_Write_TimeOut(ucb1, Transmit, 5, slave_addr1);
  I2C_Master_Read_TimeOut(ucb1, Meas_Receive, 8, slave_addr1);
      
          raw_P_value    = adc_P(Meas_Receive);                                               // Taking three bytes of raw data from temperature registers and storing it in the signed 32 bit     
          Pressure   = bmp280_compensate_P_double(raw_P_value);                           // assigning the 32 bit value to the temperature conversion
           WriteUART(Port_USB,&start,1);  
           WriteUART(Port_USB,&Pressure,4);                        //Transmits the data from the sensors to PC    
          
           if(UCA1IFG&UCRXIFG)                                                  //if something received through backchannel uart
          {
            if (UCA1RXBUF == 'q')                                               // if 'q' is recieved the while is stopped, continous measuremnt is stopped
            break;
          }
        }
        break;
    
    case '3':                                                   // continous measurment T
    while(1)
    {
  I2C_Master_Read_TimeOut(ucb1, Meas_Receive, 8, slave_addr1);
  I2C_Master_Write_TimeOut(ucb1, Transmit, 5, slave_addr1);
  I2C_Master_Read_TimeOut(ucb1, Meas_Receive, 8, slave_addr1);
      
          raw_T_value    = adc_T(Meas_Receive);                                               // Taking three bytes of raw data from temperature registers and storing it in the signed 32 bit     
          Temperature    = bmp280_compensate_T_double(raw_T_value);                           // assigning the 32 bit value to the temperature conversion
     
           WriteUART(Port_USB,&start,1);  
           WriteUART(Port_USB,&Temperature,4);                        //Transmits the data from the sensors to PC 
           
          
           if(UCA1IFG&UCRXIFG)                                                  //if something received through backchannel uart
          {
            if (UCA1RXBUF == 'q')                                               // if 'q' is recieved the while is stopped, continous measuremnt is stopped
            break;
          }
        }
        break;
    
    case '4':                                                            // single measurement T 
    
  I2C_Master_Read_TimeOut(ucb1, Meas_Receive, 8, slave_addr1);
  I2C_Master_Write_TimeOut(ucb1, Transmit, 5, slave_addr1);
  I2C_Master_Read_TimeOut(ucb1, Meas_Receive, 8, slave_addr1);
     
          raw_T_value    = adc_T(Meas_Receive);                                               // Taking three bytes of raw data from temperature registers and storing it in the signed 32 bit     
          Temperature    = bmp280_compensate_T_double(raw_T_value);                           // assigning the 32 bit value to the temperature conversion
           WriteUART(Port_USB,&start,1);  
           WriteUART(Port_USB,&Temperature,4);                        //Transmits the data from the sensors to PC    
                
        break;
        
    case '5':                                 // single measurment P
    
  I2C_Master_Read_TimeOut(ucb1, Meas_Receive, 8, slave_addr1);
  I2C_Master_Write_TimeOut(ucb1, Transmit, 5, slave_addr1);
  I2C_Master_Read_TimeOut(ucb1, Meas_Receive, 8, slave_addr1);
      
          raw_P_value    = adc_P(Meas_Receive);                                               // Taking three bytes of raw data from temperature registers and storing it in the signed 32 bit     
          Pressure   = bmp280_compensate_P_double(raw_P_value);                           // assigning the 32 bit value to the temperature conversion
           WriteUART(Port_USB,&start,1);  
           WriteUART(Port_USB,&Pressure,4);                        //Transmits the data from the sensors to PC    

        break;
        
     case '6':                                               // single measurement T and P
    
  I2C_Master_Read_TimeOut(ucb1, Meas_Receive, 8, slave_addr1);
  I2C_Master_Write_TimeOut(ucb1, Transmit, 5, slave_addr1);
  I2C_Master_Read_TimeOut(ucb1, Meas_Receive, 8, slave_addr1);
      
          raw_T_value    = adc_T(Meas_Receive);                                               // Taking three bytes of raw data from temperature registers and storing it in the signed 32 bit     
          Temperature    = bmp280_compensate_T_double(raw_T_value);                           // assigning the 32 bit value to the temperature conversion
          raw_P_value    = adc_P(Meas_Receive);                                               // Taking three bytes of raw data from temperature registers and storing it in the signed 32 bit     
          Pressure   = bmp280_compensate_P_double(raw_P_value);                           // assigning the 32 bit value to the temperature conversion
           WriteUART(Port_USB,&start,1);  
           WriteUART(Port_USB,&Temperature,4);                        //Transmits the data from the sensors to PC 
           WriteUART(Port_USB,&Pressure,4);                        //Transmits the data from the sensors to PC    

        break;

  }
}
}