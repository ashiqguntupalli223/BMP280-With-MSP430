
#include "platform.h"


//------------------------------------------------------------------------------------------------------------------------------------------
void SetPinHigh(u8 Pin)
{
  switch(Pin)
  {//Case 1-7: BIT0:=Chip1      BIT1:=Chip2     BIT2:=Chip3
    case  1:   P1OUT|=BIT2;                                     break;
    case  2:                    P2OUT|=BIT2;                    break;
    case  3:   P1OUT|=BIT2;     P2OUT|=BIT2;                    break;
    case  4:                                    P6OUT|=BIT2;    break;
    case  5:   P1OUT|=BIT2;                     P6OUT|=BIT2;    break;
    case  6:                    P2OUT|=BIT2;    P6OUT|=BIT2;    break;
    case  7:   P1OUT|=BIT2;     P2OUT|=BIT2;    P6OUT|=BIT2;    break;
    
    //--------------------------------------------------------------------------
    
    case 10:   P1OUT|=BIT0;           break;//LED Red
    case 11:   P1OUT|=BIT1;           break;//Switch_1
    case 12:   P1OUT|=BIT2;           break;//ST_nCS_Tx         ISE_IS_LED1
    case 13:   P1OUT|=BIT3;           break;//ST_nS_Tx          ISE_CS_MEM
    case 14:   P1OUT|=BIT4;           break;//ST_nSD_Tx         ISE_LED_ISE
    case 15:   P1OUT|=BIT5;           break;//ST_LED1_Tx        ISE_I2C_A2
    case 16:   P1OUT|=BIT6;           break;//ST_LED2_Tx
    case 17:   P1OUT|=BIT7;           break;//?????
    case 20:   P2OUT|=BIT0;           break;//AS_Ant_SW         ISE_LED_SD
    case 21:   P2OUT|=BIT1;           break;//Switch_2
    case 22:   P2OUT|=BIT2;           break;//ST_nCS_Tag        ISE_LED_GPS
    case 23:   P2OUT|=BIT3;           break;//ST_nS_Tag         ISE_LED4
    case 24:   P2OUT|=BIT4;           break;//ST_nSD_Tag        ISE_I2CA1
    case 25:   P2OUT|=BIT5;           break;//ST_LED1_Tag       ISE_I2C_A0
    case 26:   P2OUT|=BIT6;           break;//ST_LED2_Tag       ISE_LED3
    case 27:   P2OUT|=BIT7;           break;//UCA0_CLK
    case 30:   P3OUT|=BIT0;           break;//DAC_CS            ISE_MOSI
    case 31:   P3OUT|=BIT1;           break;//DAC_LDAC1         ISE_MISO
    case 32:   P3OUT|=BIT2;           break;//DAC_RSTSEL        ISE_CLK
    case 33:   P3OUT|=BIT3;           break;//UCA0_MOSI         ISE_GPS_Tx
    case 34:   P3OUT|=BIT4;           break;//UCA0_MISO         ISE_GPS_Rx
    case 35:   P3OUT|=BIT5;           break;//DAC_WP
    case 36:   P3OUT|=BIT6;           break;//DAC_RESET
    case 37:   P3OUT|=BIT7;           break;//DAC_BTC/USB       ISE_CARD_DET
    case 40:   P4OUT|=BIT0;           break;//DAC_CLR           ISE_CS_CARD
    case 41:   P4OUT|=BIT1;           break;//Cap2              ISE_SDA_MSP430
    case 42:   P4OUT|=BIT2;           break;//Cap3              ISE_SCL_MSP430
    case 43:   P4OUT|=BIT3;           break;//R                 ISE_LED2
    case 44:   P4OUT|=BIT4;           break;//?????
    case 45:   P4OUT|=BIT5;           break;//?????
    case 46:   P4OUT|=BIT6;           break;//?????
    case 47:   P4OUT|=BIT7;           break;//LED_Green
    case 50:   P5OUT|=BIT0;           break;//?????
    case 51:   P5OUT|=BIT1;           break;//?????
    case 52:   P5OUT|=BIT2;           break;//?????
    case 53:   P5OUT|=BIT3;           break;//?????
    case 54:   P5OUT|=BIT4;           break;//?????
    case 55:   P5OUT|=BIT5;           break;//?????
    case 56:   P5OUT|=BIT6;           break;//?????
    case 57:   P5OUT|=BIT7;           break;//?????
    case 60:   P6OUT|=BIT0;           break;//ADC12
    case 61:   P6OUT|=BIT1;           break;//AS_IRQ
    case 62:   P6OUT|=BIT2;           break;//ST_nCS_Rx
    case 63:   P6OUT|=BIT3;           break;//ST_nS_Rx
    case 64:   P6OUT|=BIT4;           break;//ST_nSD_Rx
    case 65:   P6OUT|=BIT5;           break;//ST_LED1_Rx
    case 66:   P6OUT|=BIT6;           break;//ST_LED2_Rx
    case 67:   P6OUT|=BIT7;           break;//?????
    case 70:   P7OUT|=BIT0;           break;//PowerDetector
    case 71:   P7OUT|=BIT1;           break;//?????
    case 72:   P7OUT|=BIT2;           break;//?????
    case 73:   P7OUT|=BIT3;           break;//?????
    case 74:   P7OUT|=BIT4;           break;//Attenuator
    case 75:   P7OUT|=BIT5;           break;//?????
    case 76:   P7OUT|=BIT6;           break;//?????
    case 77:   P7OUT|=BIT7;           break;//?????
    case 80:   P8OUT|=BIT0;           break;//?????
    case 81:   P8OUT|=BIT1;           break;//Cap0  AS_nCS      ISE_Rst_I2C
    case 82:   P8OUT|=BIT2;           break;//Cap1  AS_EN_AS    ISE_LED_FRAM
    case 83:   P8OUT|=BIT3;           break;//?????
    case 84:   P8OUT|=BIT4;           break;//?????
    case 85:   P8OUT|=BIT5;           break;//?????
    case 86:   P8OUT|=BIT6;           break;//?????
    case 87:   P8OUT|=BIT7;           break;//?????
    
    
  default: break;
  }
}

void SetPinLow(u8 Pin)
{
  switch(Pin)
  {//Case 1-7: BIT0:=Chip1       BIT1:=Chip2      BIT2:=Chip3
    case  1:   P1OUT&=~BIT2;                                       break;
    case  2:                     P2OUT&=~BIT2;                     break;
    case  3:   P1OUT&=~BIT2;     P2OUT&=~BIT2;                     break;
    case  4:                                      P6OUT&=~BIT2;    break;
    case  5:   P1OUT&=~BIT2;                      P6OUT&=~BIT2;    break;
    case  6:                     P2OUT&=~BIT2;    P6OUT&=~BIT2;    break;
    case  7:   P1OUT&=~BIT2;     P2OUT&=~BIT2;    P6OUT&=~BIT2;    break;
    
    //--------------------------------------------------------------------------
    case 10:   P1OUT&=~BIT0;           break;//LED Red
    case 11:   P1OUT&=~BIT1;           break;//Switch_1
    case 12:   P1OUT&=~BIT2;           break;//ST_nCS_Tx         ISE_IS_LED1
    case 13:   P1OUT&=~BIT3;           break;//ST_nS_Tx          ISE_CS_MEM
    case 14:   P1OUT&=~BIT4;           break;//ST_nSD_Tx         ISE_LED_ISE
    case 15:   P1OUT&=~BIT5;           break;//ST_LED1_Tx        ISE_I2C_A2
    case 16:   P1OUT&=~BIT6;           break;//ST_LED2_Tx
    case 17:   P1OUT&=~BIT7;           break;//?????
    case 20:   P2OUT&=~BIT0;           break;//AS_Ant_SW         ISE_LED_SD
    case 21:   P2OUT&=~BIT1;           break;//Switch_2
    case 22:   P2OUT&=~BIT2;           break;//ST_nCS_Tag        ISE_LED_GPS
    case 23:   P2OUT&=~BIT3;           break;//ST_nS_Tag         ISE_LED4
    case 24:   P2OUT&=~BIT4;           break;//ST_nSD_Tag        ISE_I2CA1
    case 25:   P2OUT&=~BIT5;           break;//ST_LED1_Tag       ISE_I2C_A0
    case 26:   P2OUT&=~BIT6;           break;//ST_LED2_Tag       ISE_LED3
    case 27:   P2OUT&=~BIT7;           break;//UCA0_CLK
    case 30:   P3OUT&=~BIT0;           break;//DAC_CS            ISE_MOSI
    case 31:   P3OUT&=~BIT1;           break;//DAC_LDAC1         ISE_MISO
    case 32:   P3OUT&=~BIT2;           break;//DAC_RSTSEL        ISE_CLK
    case 33:   P3OUT&=~BIT3;           break;//UCA0_MOSI         ISE_GPS_Tx
    case 34:   P3OUT&=~BIT4;           break;//UCA0_MISO         ISE_GPS_Rx
    case 35:   P3OUT&=~BIT5;           break;//DAC_WP
    case 36:   P3OUT&=~BIT6;           break;//DAC_RESET
    case 37:   P3OUT&=~BIT7;           break;//DAC_BTC/USB       ISE_CARD_DET
    case 40:   P4OUT&=~BIT0;           break;//DAC_CLR           ISE_CS_CARD
    case 41:   P4OUT&=~BIT1;           break;//Cap2              ISE_SDA_MSP430
    case 42:   P4OUT&=~BIT2;           break;//Cap3              ISE_SCL_MSP430
    case 43:   P4OUT&=~BIT3;           break;//R                 ISE_LED2
    case 44:   P4OUT&=~BIT4;           break;//?????
    case 45:   P4OUT&=~BIT5;           break;//?????
    case 46:   P4OUT&=~BIT6;           break;//?????
    case 47:   P4OUT&=~BIT7;           break;//LED_Green
    case 50:   P5OUT&=~BIT0;           break;//?????
    case 51:   P5OUT&=~BIT1;           break;//?????
    case 52:   P5OUT&=~BIT2;           break;//?????
    case 53:   P5OUT&=~BIT3;           break;//?????
    case 54:   P5OUT&=~BIT4;           break;//?????
    case 55:   P5OUT&=~BIT5;           break;//?????
    case 56:   P5OUT&=~BIT6;           break;//?????
    case 57:   P5OUT&=~BIT7;           break;//?????
    case 60:   P6OUT&=~BIT0;           break;//ADC12
    case 61:   P6OUT&=~BIT1;           break;//AS_IRQ
    case 62:   P6OUT&=~BIT2;           break;//ST_nCS_Rx
    case 63:   P6OUT&=~BIT3;           break;//ST_nS_Rx
    case 64:   P6OUT&=~BIT4;           break;//ST_nSD_Rx
    case 65:   P6OUT&=~BIT5;           break;//ST_LED1_Rx
    case 66:   P6OUT&=~BIT6;           break;//ST_LED2_Rx
    case 67:   P6OUT&=~BIT7;           break;//?????
    case 70:   P7OUT&=~BIT0;           break;//PowerDetector
    case 71:   P7OUT&=~BIT1;           break;//?????
    case 72:   P7OUT&=~BIT2;           break;//?????
    case 73:   P7OUT&=~BIT3;           break;//?????
    case 74:   P7OUT&=~BIT4;           break;//Attenuator
    case 75:   P7OUT&=~BIT5;           break;//?????
    case 76:   P7OUT&=~BIT6;           break;//?????
    case 77:   P7OUT&=~BIT7;           break;//?????
    case 80:   P8OUT&=~BIT0;           break;//?????
    case 81:   P8OUT&=~BIT1;           break;//Cap0  AS_nCS      ISE_Rst_I2C
    case 82:   P8OUT&=~BIT2;           break;//Cap1  AS_EN_AS    ISE_LED_FRAM
    case 83:   P8OUT&=~BIT3;           break;//?????
    case 84:   P8OUT&=~BIT4;           break;//?????
    case 85:   P8OUT&=~BIT5;           break;//?????
    case 86:   P8OUT&=~BIT6;           break;//?????
    case 87:   P8OUT&=~BIT7;           break;//?????

  default: break;
  }
}


//------------------------------------------------------------------------------------------------------------------------------------------
void SetupPins()
{
  P1DIR|=BIT0+BIT2+BIT3+BIT4+BIT5+BIT6;
  P2DIR|=BIT0+BIT2+BIT3+BIT4+BIT5+BIT6;
  P3DIR|=BIT0+BIT1+BIT2+BIT5+BIT6+BIT7;
  P4DIR|=BIT0+BIT1+BIT2+BIT3+BIT7;
  P6DIR|=BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;  
  P7DIR|=BIT0+BIT4;
  P8DIR|=BIT1+BIT2;
  
  P1OUT&=BIT1+BIT7;
  P2OUT&=BIT1+BIT7;
  P3OUT|=BIT0+BIT1+BIT2+BIT5+BIT6+BIT7;
  P4OUT&=BIT4+BIT5+BIT6;
  //P4OUT|=BIT0+BIT3;
  P6OUT&=BIT0+BIT7;
  P7OUT&=~(BIT4+BIT0);
  P8OUT&=~(BIT1+BIT2);
  
}


//------------------------------------------------------------------------------------------------------------------------------------------
void setPortDirect()
{
  spiUninstall();
  P3DIR|=BIT3;  // MOSI: Tx data input
  P3DIR&=~BIT4; // MISO: I-Channel subcarrier output
  P2DIR|=BIT7;  // SCLK: Enable Rx input
  P2OUT|=BIT7;
  P6DIR&=~BIT1; //  IRQ: Q-Channel subcarrier output
}

void setPortNormal()
{
  SetupSPI();
  
}
/*
void EN(u8 HighLow)
{
  if (HighLow==LOW)
    SetPinLow(AS_EN);
  else
    SetPinHigh(AS_EN);
}
//*/
//------------------------------------------------------------------------------------------------------------------------------------------
void SetupSPI()
{
  P3SEL = BIT3 + BIT4 ;                         // P3.3:=UCA0MOSI; P3.4:=UCA0MISO
  //P3DIR&=~BIT4;
  P2SEL = BIT7 ;                                // P2.7:=UCA0CLK
  
  UCA0CTL1  = UCSWRST ;                         // Reset
  UCA0CTL0 |= UCCKPH + /*UCCKPL+*/ UCMSB + UCMST + UCSYNC +UCMODE_1 ;
  UCA0CTL1 |= UCSSEL_2 ;                        // SMCLK=1048KHz
  
  UCA0BR0   = 0x10 ;                            // BaudRate : BRCLK=SMCLK/UCA0BR0
  UCA0BR1   = 0 ;
  UCA0MCTL  = 0 ;                               // No Modulation
  UCA0CTL1 &= ~UCSWRST ;                        // **Initialize USCI state machine**

}


//------------------------------------------------------------------------------------------------------------------------------------------
void spiUninstall()
{
  P3SEL=0;
  P2SEL=0;
}


//------------------------------------------------------------------------------------------------------------------------------------------
void WriteRead( u8 Chip, const u8* wbuf, u8 wlen, u8* rbuf, u8 rlen, u8 stopMode, u8 startMode )
{
    if (startMode != noSTART) 
      SetPinLow(Chip);//NCS_SELECT();

    spiTxRx(wbuf, 0, wlen);
    if (rlen)
        spiTxRx(0, rbuf, rlen);

    if (stopMode != noSTOP) 
      SetPinHigh(Chip);//NCS_DESELECT();
}


//------------------------------------------------------------------------------------------------------------------------------------------
void WriteReadIsr( u8 Chip, const u8* wbuf, u8 wlen, u8* rbuf, u8 rlen )
{
    SetPinLow(Chip);//NCS_SELECT();

    spiTxRx(wbuf, 0, wlen);
    spiTxRx(0, rbuf, rlen);

    SetPinHigh(Chip);//NCS_DESELECT();
}



//------------------------------------------------------------------------------------------------------------------------------------------
s8 spiTxRx(const u8* txData, u8* rxData, u16 length)
{
  u16 ii = 0;
  if (length == 0) return 0;  
  // Write one data before proceeding, this is possible because we have a FIFO
  // This could also be changed to a more efficient scheme always looking
  // at water levels. But this only makes sense at very high SPi speeds,
  // improvement for future 
  while ( !( /*iFG2 &&*/ UCA0IFG & UCTXIFG ) ) ;// Ready To Send?
  if (txData != 0)//NULL)
  {
    spiWriteBuf(txData[ii]);
    //UCA0TXBUF = txData[ii] ;        // Send Buffer
  }
  else
  {
    spiWriteBuf(0x00);
    //UCA0TXBUF = 0xFF ;             // Send Buffer
  }
  ii++;
  // Wriite the next byte, then receiive the previious byte 
  while (ii < length)
  {
    while ( !( /*ifG2 &&*/ UCA0IFG & UCRXIFG ) ) ;// Ready To Read?   
    if ((rxData != 0))//NULL))
     {
      rxData[ii - 1] = spiReadBuf();
      //rxData[ii - 1] = UCA0RXBUF;
     }
    else
     {
      spiReadBuf();
      // UCA0RXBUF;
     }    
    while ( !( /*ifG2 &&*/ UCA0IFG & UCTXIFG ) ) ;// Ready To Send?
    if (txData !=0)// NULL)
     {
      spiWriteBuf(txData[ii]);
      //UCA0TXBUF = txData[ii] ;            // Send Buffer
     }
    else
     {
      spiWriteBuf(0x00);	
      //UCA0TXBUF = 0xFF ;                // Send Buffer
     }
    ii++;
  }
  
  while ( !( /*ifG2 &&*/ UCA0IFG & UCRXIFG ) ) ;// Ready To Read?
  // Receiive the last byte, FifO should be empty for both diirectiions 
  if ((rxData != 0))//NULL))
   {
    rxData[ii - 1] = spiReadBuf();
    //	rxData[ii - 1] = UCA0RXBUF;
   }
  else
   {
    spiReadBuf();
    //	UCA0RXBUF;
   }
  
  return 1;//;ERR_NONE;
}



//------------------------------------------------------------------------------------------------------------------------------------------
void spiWriteBuf(u8 Byte)
{
  UCA0TXBUF = Byte; 
}

u8 spiReadBuf()
{
  return UCA0RXBUF;
}



//------------------------------------------------------------------------------------------------------------------------------------------
void SetupADC12()
{// ADC Setting: P6.0
  REFCTL0 &= ~REFMSTR;                      // Reset REFMSTR to hand over control to 
                                            // ADC12_A ref control registers
  ADC12CTL0 = ADC12ON+ADC12SHT02+ADC12REFON+ADC12REF2_5V;
  ADC12MCTL0 = ADC12SREF_1;                 // Vr+=Vref+ and Vr-=AVss
  
  //ADC12CTL0 = ADC12SHT01+ADC12ON;       // Sampling time, ADC12 On
  ADC12CTL1 = ADC12SHP;                 // Use sampling timer
  ADC12IE   = 0x00;                     // Disable Interrupt
  ADC12CTL0|= ADC12ENC;                 // 
  P6SEL    |= BIT0;                     // P6.0-->ADC12
}


//------------------------------------------------------------------------------------------------------------------------------------------
u16 readADC12(u8 times)
{
  u32 Voltage=0;
  for(u8 iiiii=0;iiiii<times;iiiii++)
  {
    ADC12CTL0 |= ADC12SC;                 // Measure 1 Time
    while((ADC12IFG & BIT0) == 0);        // Measure done?
    Voltage+=ADC12MEM0;                     // Get Result
  }
  return (u16)((Voltage+(times>>1))/times);
}

//------------------------------------------------------------------------------------------------------------------------------------------
u8 SPIwrite(u8 Chip, u8 Data)
{
  while ( !( /*IFG2 &&*/ UCA0IFG & UCTXIFG ) ) ;        // Ready To Send?  
  SetPinHigh(Chip);                                     // Set SEN High
  UCA0TXBUF = Data;                                     // Send Buffer := Data
  while ( !( /*IFG2 &&*/ UCA0IFG & UCTXIFG ) ) ;        // Ready To Send? --> Send done
  while ( !( /*IFG2 &&*/ UCA0IFG & UCRXIFG ) ) ;        // Ready To Read?    
  SetPinLow(Chip);                                      // Set SEN Low
  return UCA0RXBUF;                                     // Return
}

//------------------------------------------------------------------------------------------------------------------------------------------
void SetupTimer(u8 Mode,u8 Pin_Timer)
{
  TA0CTL=MC_0+TACLR;
  //P1SEL|=BIT1;
  switch(Pin_Timer)
  {
    case 15:
      P1DIR&=~BIT5;
      P1SEL|=BIT5;          // P1.5 :: TA0.4
      TA0CCTL4=CAP+SCS+CCIE+CM_3+CCIFG;
      TA0CCR4=0xFFFF; // Time Out
      //TA0CCTL1=CCIE;
      break;
    case 14:
      P1DIR&=~BIT4;
      P1SEL|=BIT4;          // P1.4 :: TA0.3
      TA0CCTL3=CAP+SCS+CCIE+CM_3+CCIFG;
      TA0CCR3=0xFFFF; // Time Out
      //TA0CCTL1=CCIE;
      break;
    case 13:
      P1DIR&=~BIT3;
      P1SEL|=BIT3;          // P1.3 :: TA0.2
      TA0CCTL2=CAP+SCS+CCIE+CM_3+CCIFG;
      TA0CCR2=0xFFFF; // Time Out
      //TA0CCTL1=CCIE;
      break;
    case 12:
      P1DIR&=~BIT2;
      P1SEL|=BIT2;          // P1.2 :: TA0.1
      TA0CCTL1=CAP+SCS+CCIE+CM_3+CCIFG;
      TA0CCR1=0xFFFF; // Time Out
      //TA0CCTL2=CCIE;
      break;
    default: break;
  }
  TA0CCR0=0xFFFF;
  
  #if (UseLinkFrequency==LinkFrequency_40kHz)
    TA0CTL = TASSEL__SMCLK + MC_1 + TACLR + ID__4 + TAIE;// Timer for FM0 & Miller_2    //MC_1
  #else
      TA0CTL = TASSEL__SMCLK + MC_1 + TACLR + ID__1 + TAIE;// Timer for FM0 & Miller_2    //MC_1
  #endif
  
  #if ( (UseCodeMode>Miller_2) && (UseLinkFrequency<LinkFrequency_256kHz) )
     TA0EX0|=0x03;
  #endif
  
  //__DINT();
}
//*/

//------------------------------------------------------------------------------------------------------------------------------------------
void SetupUART(u8 ucsi, u32 clk, u32 BaudRate)
{
  u16 t0=(u16)((double)clk/BaudRate+0.5),t1=0;
  while(t0>255)
  {
    t0>>=4;
    t1=UCOS16;
  }
  
  if (ucsi&uca1)
  {
    P4SEL = BIT4+BIT5;                        // P4.4 , P4.5 = USCI_A1 TXD/RXD : USB
    UCA1CTL1 |= UCSWRST;                      // **Put state machine in reset**
    UCA1CTL1 |= UCSSEL_2;                     // SMCLK
    UCA1BR0 = t0;                             // 1MHz 115200 (see User's Guide)
    UCA1BR1 = 0;                              // 1MHz 115200
    UCA1MCTL |= UCBRS_1 + UCBRF_0+t1;         // Modulation UCBRSx=1, UCBRFx=0
    UCA1CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
    UCA1IE |= UCRXIE;                         // Enable USCI_A0 RX interrupt
  }
  
  if(ucsi&uca0)
  {
    P3SEL = BIT3+BIT4;                        // P3.3 , P3.4 = USCI_A0 TXD/RXD : Pins
    UCA0CTL1 |= UCSWRST;                      // **Put state machine in reset**
    UCA0CTL1 |= UCSSEL_2;                     // SMCLK
    UCA0BR0 = t0;                             // 1MHz 115200 (see User's Guide)
    UCA0BR1 = 0;                              // 1MHz 115200
    UCA0MCTL |= UCBRS_1 + UCBRF_0+t1;         // Modulation UCBRSx=1, UCBRFx=0
    UCA0CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
    UCA0IE |= UCRXIE;                         // Enable USCI_A0 RX interrupt
  }
      
}

//------------------------------------------------------------------------------------------------------------------------------------------
void SendUART_Byte(u8 ucsi, u8 c)
{
  if (ucsi&uca1)
  {
    while (!(UCA1IFG&UCTXIFG));             // USCI_A1 TX buffer ready?
    UCA1TXBUF = c;
    while (!(UCA1IFG&UCTXIFG));             // wait till done
  }
  if (ucsi&uca0)
  {
    while (!(UCA0IFG&UCTXIFG));             // USCI_A0 TX buffer ready?
    UCA0TXBUF = c;
    while (!(UCA0IFG&UCTXIFG));             // USCI_A0 TX buffer ready?
  }
}

//------------------------------------------------------------------------------------------------------------------------------------------
void SendUART_String(u8 ucsi, u8 line1, u8* str, u8 line2)
{
  unsigned int i=0;
  
  if(line1==NewLine)  {    SendUART_Byte(ucsi,'\r');  SendUART_Byte(ucsi,'\n');  }      // New Line "CR LF"
    else if(line1==Space) SendUART_Byte(ucsi,' ');
    
  while( str[i]!='\0' )
  {
    SendUART_Byte(ucsi,str[i]);
    i++;
  }
  
  if(line2==NewLine)  {    SendUART_Byte(ucsi,'\r');  SendUART_Byte(ucsi,'\n');  }      // New Line "CR LF"
    else if(line2==Space) SendUART_Byte(ucsi,' ');
}




//------------------------------------------------------------------------------------------------------------------------------------------
void SetupI2C_Master(u8 usci, u32 clk, u32 kHz)
{
  u16 fr_div=(u16)((clk+kHz*500)/kHz/1000);
  if ( fr_div == 0 )     fr_div = 1;
  
  if(usci&ucb0)
  {
    P3SEL |= BIT0 + BIT1;                         // Assign I2C pins to USCI_B0
    UCB0CTL1 |= UCSWRST;                          // Enable SW reset
    UCB0CTL0 = UCMST + UCMODE_3 + UCSYNC;         // I2C Master, synchronous mode
    UCB0CTL1 = UCSSEL_2 + UCSWRST;                // Use SMCLK, keep SW reset
    UCB0BR0 = fr_div;                             // SMCLK/fr_div
    UCB0BR1 = 0;
    UCB0CTL1 &= ~UCSWRST;                         // Clear SW reset, resume operation
    UCB0IE |= UCRXIE + UCTXIE;                    // Enable RX and TX interrupt
  }
  
  if(usci&ucb1)
  {
    P4SEL |= 0x06;                                // Assign I2C pins to USCI_B1
    UCB1CTL1 |= UCSWRST;                          // Enable SW reset
    UCB1CTL0 = UCMST + UCMODE_3 + UCSYNC;         // I2C Master, synchronous mode
    UCB1CTL1 = UCSSEL_2 + UCSWRST;                // Use SMCLK, keep SW reset
    UCB1BR0 = fr_div;                             // SMCLK/fr_div
    UCB1BR1 = 0;
    UCB1CTL1 &= ~UCSWRST;                         // Clear SW reset, resume operation
    //UCB1IE |= UCRXIE + UCTXIE;                    // Enable RX and TX interrupt
  }
}




//------------------------------------------------------------------------------------------------------------------------------------------
u32 I2C_Master_Write(u8 usci, void* tx, u32 tlen, u8 addr)
{
  u32 r_val=0;
  
  if(usci&ucb1)
  {
    UCB1I2CSA = addr;                             // Assing slave address
    
    while ((UCB1IFG & UCSTPIFG));                 // Check if Stop condition on
    UCB1CTL1 |= UCTR + UCTXSTT;                   // Start writing through I2C
    while (!(UCB1IFG & UCTXIFG));                 // Wait until TX buffer ready
    for(uint32_t i = 0; i < tlen; i++)
    {
      UCB1TXBUF = *((uint8_t*)tx + i);            // Write string in  TX buffer of I2C
      while (!(UCB1IFG & UCTXIFG));               // Wait until TX buffer ready
      if( i == tlen - 1)                          // If only one byte left to write
      {
        UCB1CTL1 |= UCTXSTP;                      // I2C stop condition
        UCB1IFG &= ~UCTXIFG;                      // Clear USCI_B0 TX int flag
      }
      r_val++;                                    // Increment return value
    }
  }
  
  if(usci&ucb0)
  {
    r_val=0;
    UCB0I2CSA = addr;                             // Assing slave address
    while ((UCB0IFG & UCSTPIFG));                 // Check if Stop condition on
    UCB0CTL1 |= UCTR + UCTXSTT;                   // Start writing through I2C
    while (!(UCB0IFG & UCTXIFG));                 // Wait until TX buffer ready
    for(uint32_t i = 0; i < tlen; i++)
    {
      UCB0TXBUF = *((uint8_t*)tx + i);            // Write string in  TX buffer of I2C
      while (!(UCB0IFG & UCTXIFG));               // Wait until TX buffer ready
      if( i == tlen - 1)// If only one byte left to write
      {
        UCB0CTL1 |= UCTXSTP;                      // I2C stop condition
        UCB0IFG &= ~UCTXIFG;                      // Clear USCI_B0 TX int flag
      }
      r_val++;                                    // Increment return value
    }
  }
  
  return r_val;
}


//------------------------------------------------------------------------------------------------------------------------------------------
u32 I2C_Master_Read(u8 usci, void* rx, u32 rlen, u8 addr)
{
  uint32_t r_val = 0;
  
  if(usci&ucb1)
  {
    UCB1I2CSA = addr;                             // Assing slave address
    if (rlen != 0)
    {
      while ((UCB1CTL1 & UCTXSTP));                 // Check if Stop condition on
      UCB1CTL1 &= ~UCTR;                            // Set writing bit in register to 0
      UCB1CTL1 |= UCTXSTT;                          // Start reading through I2C
      while (!(UCB1CTL1 & UCTXSTT));
      if (rlen == 1)
      {
        while (!(UCB1IFG & UCRXIFG))
        {
          if((UCB1CTL1 & UCTXSTT)==0)
            UCB1CTL1 |= UCTXSTP;
        }
        while (UCB1CTL1 & UCTXSTP);
        *((uint8_t*)rx) = UCB1RXBUF;
        return 1;
      }
      for (uint8_t i = 0; i < rlen-1; i++)
      {
        while (!(UCB1IFG & UCRXIFG));
        *((uint8_t*)rx + i) = UCB1RXBUF;
        r_val ++;
      }
      UCB1CTL1 |= UCTXSTP;
      while (UCB1CTL1 & UCTXSTP);
      *((uint8_t*)rx+rlen-1) = UCB1RXBUF;
    }
  }
  
  if(usci&ucb0)
  {
    r_val = 0;
    UCB0I2CSA = addr;                             // Assing slave address
    while ((UCB0IFG & UCSTPIFG));                 // Check if Stop condition on
    UCB0CTL1 &= ~UCTR;                            // Set writing bit in register to 0
    UCB0CTL1 |= UCTXSTT;                          // Start reading through I2C
    while (!(UCB0IFG & UCRXIFG));                 // Wait until RX buffer ready
    for(uint32_t i = 0; i < rlen; i++)
    {
      if( i == rlen - 1)                          // If only one byte left to read
        UCB0CTL1 |= UCTXSTP;                      // set I2C stop condition
      *((uint8_t*)rx + i) = UCB0RXBUF;            // Copy RX buffer to string
      while (!(UCB0IFG & UCRXIFG));               // Wait until RX buffer ready
      r_val++;                                    // Increment return value
    }
  }
  
  return r_val;
}





//------------------------------------------------------------------------------------------------------------------------------------------
u32 I2C_Master_ReadWrite(u8 usci, void* tx, uint32_t tlen,void* rx, uint32_t rlen, uint8_t addr)
{
  uint32_t r_val = 0;
  
  if(usci&ucb1)
  {
    UCB1I2CSA = addr;                               //Assing slave addres
    if( tlen !=0)
    {
      while ((UCB1IFG & UCSTPIFG));                 // Check if Stop condition on
      UCB1CTL1 |= UCTR + UCTXSTT;                   // Start writing through I2C
      while (!(UCB1IFG & UCTXIFG));                 // Wait until TX buffer ready
      for(uint32_t i = 0; i < tlen; i++)
      {
        UCB1TXBUF = *((uint8_t*)tx + i);            // Write string in  TX buffer of I2C
        while (!(UCB1IFG & UCTXIFG));               // Wait until TX buffer ready
        if( i == tlen - 1)
        {                        // If only one byte left to write
          if( rlen == 0)
            UCB1CTL1 |= UCTXSTP;                    // I2C stop condition
          UCB1IFG &= ~UCTXIFG;                      // Clear USCI_B1 TX int flag
        }
        r_val++;                                      // Increment return value
      }
    }
    if (rlen != 0)
    {
      while ((UCB1CTL1 & UCTXSTP));                 // Check if Stop condition on
      UCB1CTL1 &= ~UCTR;                            // Set writing bit in register to 0
      UCB1CTL1 |= UCTXSTT;                          // Start reading through I2C
      while (!(UCB1CTL1 & UCTXSTT));
      if (rlen == 1)
      {
        while (!(UCB1IFG & UCRXIFG))
        {
          if((UCB1CTL1 & UCTXSTT)==0)
            UCB1CTL1 |= UCTXSTP;
        }
        while (UCB1CTL1 & UCTXSTP);
        *((uint8_t*)rx) = UCB1RXBUF;
        r_val++;
        return r_val;
      }
      for (uint8_t i = 0; i < rlen-1; i++)
      {
        while (!(UCB1IFG & UCRXIFG));
        *((uint8_t*)rx + i) = UCB1RXBUF;
        r_val++;
      }
      UCB1CTL1 |= UCTXSTP;   
      while (UCB1CTL1 & UCTXSTP);
      *((uint8_t*)rx+rlen-1) = UCB1RXBUF;
      r_val++;
    }
  }
  
  if(usci&ucb0)
  {
    r_val = 0;
    UCB0I2CSA = addr;                               //Assing slave addres
    if( tlen !=0)
    {
      while ((UCB0IFG & UCSTPIFG));                 // Check if Stop condition on
      UCB0CTL1 |= UCTR + UCTXSTT;                   // Start writing through I2C
      while (!(UCB0IFG & UCTXIFG));                 // Wait until TX buffer ready
      for(uint32_t i = 0; i < tlen; i++)
      {
        UCB0TXBUF = *((uint8_t*)tx + i);            // Write string in  TX buffer of I2C 
        while (!(UCB0IFG & UCTXIFG));               // Wait until TX buffer ready
        if( i == tlen - 1)
        {                        // If only one byte left to write
          if( rlen == 0)
            UCB0CTL1 |= UCTXSTP;                    // I2C stop condition
          UCB0IFG &= ~UCTXIFG;                      // Clear USCI_B1 TX int flag
        }
        r_val++;                                      // Increment return value
      }
    }
    if (rlen != 0)
    {
      while ((UCB0CTL1 & UCTXSTP));                 // Check if Stop condition on
      UCB0CTL1 &= ~UCTR;                            // Set writing bit in register to 0
      UCB0CTL1 |= UCTXSTT;                          // Start reading through I2C
      while (!(UCB0CTL1 & UCTXSTT));
      if (rlen == 1)
      {
        while (!(UCB0IFG & UCRXIFG))
        {
          if((UCB0CTL1 & UCTXSTT)==0)
            UCB0CTL1 |= UCTXSTP;
        }
        while (UCB0CTL1 & UCTXSTP);
        *((uint8_t*)rx) = UCB0RXBUF;
        r_val++;
        return r_val;
      }
      for (uint8_t i = 0; i < rlen-1; i++)
      {
        while (!(UCB0IFG & UCRXIFG));
        *((uint8_t*)rx + i) = UCB0RXBUF;
        r_val++;
      }
      UCB0CTL1 |= UCTXSTP;
      while (UCB0CTL1 & UCTXSTP);
      *((uint8_t*)rx+rlen-1) = UCB0RXBUF;
      r_val++;
    }
  }
  
  return r_val;
}




//------------------------------------------------------------------------------------------------------------------------------------------
void WriteUART(u8 usci, void* tx, uint32_t tlen)
{
  u32 i;
  
  if(usci&uca1)
  {
    for( i = 0; i < tlen; i++)
    {                  // loop until tlen reached
      while (!(UCA1IFG&UCTXIFG));                 // TX buffer ready?
      UCA1TXBUF = *((uint8_t*)tx + i);            // copy data to TX buffer
    }
    while (!(UCA1IFG&UCTXIFG));// Wait till Tx Done
  }
  
  if(usci&uca0)
  {
    for( i = 0; i < tlen; i++)
    {                  // loop until tlen reached
      while (!(UCA0IFG&UCTXIFG));                 // TX buffer ready?
      UCA0TXBUF = *((uint8_t*)tx + i);            // copy data to TX buffer
    }
    while (!(UCA0IFG&UCTXIFG));// Wait till Tx Done
  }
}



//------------------------------------------------------------------------------------------------------------------------------------------
void ReadUART(u8 usci, void* rx, uint32_t rlen)
{
  u32 i;
  
  if(usci&uca1)
  {
    for( i = 0; i < rlen; i++)
    {                  // loop until rlen reached
      while (!(UCA1IFG & UCRXIFG));               // RX buffer ready?
      *((uint8_t*)rx + i) = UCA1RXBUF;            // copy data from RX buffer
    }
  }
  
  if(usci&uca0)
  {
    for( i = 0; i < rlen; i++)
    {                  // loop until rlen reached
      while (!(UCA0IFG & UCRXIFG));               // RX buffer ready?
      *((uint8_t*)rx + i) = UCA0RXBUF;            // copy data from RX buffer
    }
  }
}


//------------------------------------------------------------------------------------------------------------------------------------------
u8 ReadUART_Byte(u8 usci)
{
  if(usci&uca1)
  {
      while (!(UCA1IFG & UCRXIFG));               // RX buffer ready?
      return UCA1RXBUF;            // copy data from RX buffer
  }
  
  if(usci&uca0)
  {
      while (!(UCA0IFG & UCRXIFG));               // RX buffer ready?
      return UCA0RXBUF;            // copy data from RX buffer
  }
  
  return 0x00;
}


//------------------------------------------------------------------------------------------------------------------------------------------
u32 I2C_Master_Read_TimeOut(u8 usci, void* rx, u32 rlen, u8 addr)
{
  uint32_t r_val = 0,to;
  
  if(usci&ucb1)
  {
    UCB1I2CSA = addr;                             // Assing slave address
    if (rlen != 0)
    {
      to=0;
      while ((UCB1CTL1 & UCTXSTP)&&(to<TimeOut))        to++;                 // Check if Stop condition on
      UCB1CTL1 &= ~UCTR;                            // Set writing bit in register to 0
      UCB1CTL1 |= UCTXSTT;                          // Start reading through I2C
      //to=0;
      while( (!(UCB1CTL1 & UCTXSTT))&&(to<TimeOut) )    to++;
      if (rlen == 1)
      {
        //to=0;
        while( (!(UCB1IFG & UCRXIFG))&&(to<TimeOut) )
        {
          to++;
          if((UCB1CTL1 & UCTXSTT)==0)
            UCB1CTL1 |= UCTXSTP;
        }
        //to=0;
        while( (UCB1CTL1 & UCTXSTP)&&(to<TimeOut) )     to++;
        *((uint8_t*)rx) = UCB1RXBUF;
        return 1;
      }
      for (uint8_t i = 0; i < rlen-1; i++)
      {
        //to=0;
        while( (!(UCB1IFG & UCRXIFG))&&(to<TimeOut) )   to++;
        *((uint8_t*)rx + i) = UCB1RXBUF;
        r_val ++;
      }
      UCB1CTL1 |= UCTXSTP;
      //to=0;
      while( (UCB1CTL1 & UCTXSTP)&&(to<TimeOut) )       to++;;
      *((uint8_t*)rx+rlen-1) = UCB1RXBUF;
    }
    
  }
  
  if(usci&ucb0)
  {
    r_val = 0;
    UCB0I2CSA = addr;                             // Assing slave address
    to=0;
    while ((UCB0IFG & UCSTPIFG)&&(to<TimeOut))          to++;                 // Check if Stop condition on
    UCB0CTL1 &= ~UCTR;                            // Set writing bit in register to 0
    UCB0CTL1 |= UCTXSTT;                          // Start reading through I2C
    //to=0;
    while( (!(UCB0IFG & UCRXIFG))&&(to<TimeOut) )       to++;                 // Wait until RX buffer ready
    for(uint32_t i = 0; i < rlen; i++)
    {
      if( i == rlen - 1)                          // If only one byte left to read
        UCB0CTL1 |= UCTXSTP;                      // set I2C stop condition
      *((uint8_t*)rx + i) = UCB0RXBUF;            // Copy RX buffer to string
      //to=0;
      while( (!(UCB0IFG & UCRXIFG))&&(to<TimeOut))      to++;               // Wait until RX buffer ready
      r_val++;                                    // Increment return value
    }
  }
  
  if(to==TimeOut)
    return 0;
  else
    return r_val;
}


//------------------------------------------------------------------------------------------------------------------------------------------
u32 I2C_Master_Write_TimeOut(u8 usci, void* tx, u32 tlen, u8 addr)
{
  u32 r_val=0;
  u32 to;
  
  if(usci&ucb1)
  {
    to=0;
    
    UCB1I2CSA = addr;                             // Assing slave address
    
    while ((UCB1IFG & UCSTPIFG)&&(to<TimeOut))  to++;                 // Check if Stop condition on
    UCB1CTL1 |= UCTR + UCTXSTT;                   // Start writing through I2C
    while( (!(UCB1IFG & UCTXIFG))&&(to<TimeOut)) to++;                 // Wait until TX buffer ready
    for(uint32_t i = 0; i < tlen; i++)
    {
      UCB1TXBUF = *((uint8_t*)tx + i);            // Write string in  TX buffer of I2C
      while( (!(UCB1IFG & UCTXIFG)) &&(to<TimeOut)) to++;               // Wait until TX buffer ready
      if( i == tlen - 1)                          // If only one byte left to write
      {
        UCB1CTL1 |= UCTXSTP;                      // I2C stop condition
        UCB1IFG &= ~UCTXIFG;                      // Clear USCI_B0 TX int flag
      }
      r_val++;                                    // Increment return value
    }
  }
  
  if(usci&ucb0)
  {
    to=0;
    r_val=0;
    UCB0I2CSA = addr;                             // Assing slave address
    while ((UCB0IFG & UCSTPIFG)&&(to<TimeOut)) to++;                 // Check if Stop condition on
    UCB0CTL1 |= UCTR + UCTXSTT;                   // Start writing through I2C
    while( (!(UCB0IFG & UCTXIFG))&&(to<TimeOut)) to++;                 // Wait until TX buffer ready
    for(uint32_t i = 0; i < tlen; i++)
    {
      UCB0TXBUF = *((uint8_t*)tx + i);            // Write string in  TX buffer of I2C
      while( (!(UCB0IFG & UCTXIFG))&&(to<TimeOut)) to++;               // Wait until TX buffer ready
      if( i == tlen - 1)// If only one byte left to write
      {
        UCB0CTL1 |= UCTXSTP;                      // I2C stop condition
        UCB0IFG &= ~UCTXIFG;                      // Clear USCI_B0 TX int flag
      }
      r_val++;                                    // Increment return value
    }
  }
  
  if(to<TimeOut)
    return r_val;
  else return 0;
}

/*
//initialize UCB0 SPI. Pins 3.0 and 3.1 used as MOSI(SIMO) and MISO(SOMI), 3.2 connected to a clock signal
void UCB0_init(int divisor) {
  P3SEL |= BIT0+BIT1;                                   // P3.0,1 option select for SIMO and SOMI
  P3SEL |= BIT2;                                        // P3.2 option select for UCB0CLK
  
  UCB0CTL1 |= UCSWRST;                                  // **Put state machine in reset**
  UCB0CTL0 |= UCMST + UCSYNC + UCMSB + UCCKPL;          // 3-pin, 8-bit SPI master
                                                        // Clock polarity high, MSB
  UCB0CTL1 |= UCSSEL_2;                                 // SMCLK
  UCB0BR0 = divisor;                                       // Buad-rate of SPI (divide current clock by UCA0BR0 to get the baud-rate)
  UCB0BR1 = 0;                                          //
  UCB0CTL1 &= ~UCSWRST;                                 // **Initialize USCI state machine**
  UCB0IE |= UCRXIE;                                     // Enable USCI_A0 RX interrupt
  
}

//function used to read and write throught UCB0
uint32_t UCB0(void* tx, uint32_t tlen, void* rx, uint32_t rlen, void* par) {
  uint32_t i;
  *(((SPI_CS*)par)->PxOUT) &=~ ((SPI_CS*)par)->BITx;    //use a SPI_CS structure to enable CS (low)
  
  for(i = 0; i < tlen; i++) {
    while (!(UCB0IFG&UCTXIFG));               // TX buffer ready?
    UCB0TXBUF = *((uint8_t*)tx + i);
    while (!(UCB0IFG&UCRXIFG));               // RX buffer ready?
    *((uint8_t*)tx + i) = UCB0RXBUF;
  }
  
  for(i = 0; i < rlen; i++) {
    while (!(UCB0IFG&UCTXIFG));               // TX buffer ready?
    UCB0TXBUF = *((uint8_t*)rx + i);
    while (!(UCB0IFG&UCRXIFG));               // RX buffer ready?
    *((uint8_t*)rx + i) = UCB0RXBUF;
  }
  
  *(((SPI_CS*)par)->PxOUT) |= ((SPI_CS*)par)->BITx;     //use a SPI_CS structure to disable CS (high)
  
  return tlen + rlen;
}*/