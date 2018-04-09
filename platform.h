
//------------------------------------------------------------------------------------------------------------------------------------------
#include "global.h"
#include "config.h"

//------------------------------------------------------------------------------------------------------------------------------------------
#define noSTOP  0
#define doSTOP  1

#define noSTART 0
#define doSTART 1

//#define nS      0
//#define ShotDown     1

#define NewLine         1
#define noNewLine       0
#define Space           2

#define uca0    1
#define uca1    2
#define ucb0    4
#define ucb1    8
#define Port_USB        uca1
#define Port_Pins       uca0







//------------------------------------------------------------------------------------------------------------------------------------------
void setPortDirect();
void setPortNormal();
void EN(u8 HighLow);

void SetupSPI();
void spiUninstall();

void WriteRead( u8 Chip, const u8* wbuf, u8 wlen, u8* rbuf, u8 rlen, u8 stopMode, u8 startMode );
void WriteReadIsr( u8 Chip, const u8* wbuf, u8 wlen, u8* rbuf, u8 rlen );

s8 spiTxRx(const u8* txData, u8* rxData, u16 length);
void spiWriteBuf(u8 Byte);
u8 spiReadBuf();

void SetupPins();
void SetPinLow(u8 Pin);
void SetPinHigh(u8 Pin);

void SetupADC12();
u16 readADC12(u8 times);
u8 SPIwrite(u8 Chip, u8 Data);


//------------------------------------------------------------------------------------------------------------------------------------------
void SetupTimer(u8 Mode,u8 Pin_Timer);

//------------------------------------------------------------------------------------------------------------------------------------------
void SetupUART(u8 ucsi, u32 clk, u32 BaudRate);
void SendUART_Byte(u8 ucsi, u8 c);
void SendUART_String(u8 ucsi, u8 line1, u8* str, u8 line2);
void WriteUART(u8 usci, void* tx, uint32_t tlen);
void ReadUART(u8 usci, void* rx, uint32_t rlen);
u8 ReadUART_Byte(u8 usci);


//------------------------------------------------------------------------------------------------------------------------------------------
void SetupI2C_Master(u8 usci, u32 clk, u32 kHz);
u32 I2C_Master_Write(u8 usci, void* tx, u32 tlen, u8 addr);
u32 I2C_Master_Read(u8 usci, void* rx, u32 rlen, u8 addr);
u32 I2C_Master_ReadWrite(u8 usci, void* tx, uint32_t tlen, void* rx, uint32_t rlen, uint8_t addr);

u32 I2C_Master_Read_TimeOut(u8 usci, void* rx, u32 rlen, u8 addr);
u32 I2C_Master_Write_TimeOut(u8 usci, void* tx, u32 tlen, u8 addr);



/*
void UCB0_init(int divisor);
uint32_t UCB0(void* tx, uint32_t tlen, void* rx, uint32_t rlen, void* par);
*/