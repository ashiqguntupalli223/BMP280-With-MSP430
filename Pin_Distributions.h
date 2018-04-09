//------------------------------------------------------------------------------------------------------------------------------------------
// Mult. ISE - Board

#define ISE_GPS_Rx      34
#define ISE_GPS_Tx      33
#define ISE_CLK         32
#define ISE_SCL_MSP430  42
#define ISE_SDA_MSP430  41
#define ISE_LED_SD      20
#define ISE_LED_GPS     22
#define ISE_MOSI        30
#define ISE_MISO        31
#define ISE_LED3        26
#define ISE_LED4        23
#define ISE_Rst_I2C     81
#define ISE_I2C_A0      25
#define ISE_I2C_A1      24
#define ISE_I2C_A2      15
#define ISE_LED_ISE     14
#define ISE_CS_MEM      13
#define ISE_LED1        12
#define ISE_LED2        43
#define ISE_CS_CARD     40
#define ISE_CARD_DET    37
#define ISE_LED_FRAM    82




//------------------------------------------------------------------------------------------------------------------------------------------
//µC-Functions
#define LED_red         10
#define LED_Red         10
#define LED_RED         10
#define LED_green       47
#define LED_Green       47
#define LED_GREEN       47
#define UCA0_CLK        27
#define UCA0_MISO       34
#define UCA0_MOSI       33
#define ADC12           60

//------------------------------------------------------------------------------------------------------------------------------------------
//ST Chips
#define ST_Chip1        0x01
#define ST_Chip2        0x02
#define ST_Chip3        0x04
#define ST_Chip12       0x03
#define ST_Chip13       0x05
#define ST_Chip23       0x06
#define ST_Chip123      0x07

#define ST_nCS_Chip1    12
#define ST_nS_Chip1     13
#define ST_nSD_Chip1    14
#define ST_LED1_Chip1   15
#define ST_LED2_Chip1   16

#define ST_nCS_Chip2    22
#define ST_nS_Chip2     23
#define ST_nSD_Chip2    24
#define ST_LED1_Chip2   25
#define ST_LED2_Chip2   26

#define ST_nCS_Chip3    62
#define ST_nS_Chip3     63
#define ST_nSD_Chip3    64
#define ST_LED1_Chip3   65
#define ST_LED2_Chip3   66

//------------------------------------------------------------------------------------------------------------------------------------------
//Mismatch
#define Cap2            41
#define Cap3            42
#define R               43

#define Cap0            81
#define Cap1            82

//------------------------------------------------------------------------------------------------------------------------------------------
#define PowerDetector   70

#define Attenuator      74

#define PhaseShifter    0xFF

//------------------------------------------------------------------------------------------------------------------------------------------
//DAC
#define DAC_CS          30//lv
#define DAC_LDAC1       31//zhong
#define DAC_RSTSEL      32//huang*0
#define DAC_WP          35//lang
#define DAC_RESET       36//cheng
#define DAC_BTCusb      37//
#define DAC_CLR         40//bai

//------------------------------------------------------------------------------------------------------------------------------------------
// AS3993
#define AS3993          81
#define AS_Ant_SW       20
#define AS_IRQ          61
#define AS_nCS          81
#define AS_EN           82

#define AS_Tune_1       41
#define AS_Tune_2       42

#define AS_I_Channel    15
#define AS_Q_Channel    14
#define AS_OAD1         13
#define AS_OAD2         12

#define AS_LED1         62
#define AS_LED2         63
#define AS_LED3         64
