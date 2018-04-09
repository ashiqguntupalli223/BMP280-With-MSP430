#include "SMCLK.h"

///////////////////////////////////////Clock 8 Mhz//////////////////////////////////////////////////////
u32 Set_clk_Freq_8MHz(void)                                                                              //                           
  {                                                                                                   //    
    UCSCTL3 = SELREF_2;                       // Set DCO FLL reference = REFO                         //  
    UCSCTL4 |= SELA_2;                        // Set ACLK = REFO                                      //
    UCSCTL0 = 0x0000;                         // Set lowest possible DCOx, MODx                       //  
                                                                                                      //
    do                                                                                                //  
      {                                                                                               //          
        UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + DCOFFG); // Clear XT2,XT1,DCO fault flags                  //  
        SFRIFG1 &= ~OFIFG;                          // Clear fault flags                              //  
      }while (SFRIFG1&OFIFG);                       // Test oscillator fault flag                     // 
                                                                                                      //
    __bis_SR_register(SCG0);                  // Disable the FLL control loop                         //  
    UCSCTL1 = DCORSEL_5;                      // Select DCO range 16MHz operation                     //  
    UCSCTL2 |= 249;                           // Set DCO Multiplier for 8MHz                          //  
                                              // (N + 1) * FLLRef = Fdco                              //  
                                              // (249 + 1) * 32768 = 8MHz                             //  
    __bic_SR_register(SCG0);                  // Enable the FLL control loop                          //  
                                                                                                      //
    __delay_cycles(250000);  // Worst-case settling time for the DCO when the DCO range bits have been//
                             // changed is n x 32 x 32 x f_MCLK / f_FLL_reference.                    //  
                             // See UCS chapter in 5xx UG for optimization.                           //  
                             // 32 x 32 x 8 MHz / 32,768 Hz = 250000 = MCLK cycles for DCO to settle  //  
    return CLK_8MHz;
  }                                                                                                   //                                  
                                                                                                      //
/////////////////////////////////Clock 12 Mhz///////////////////////////////////////////////////////////
u32 Set_clk_Freq_12MHz(void)                                                                             //
  {                                                                                                   //
                                                                                                      //
    UCSCTL3 |= SELREF_2;                      // Set DCO FLL reference = REFO                         //
    UCSCTL4 |= SELA_2;                        // Set ACLK = REFO                                      //
                                                                                                      //
    __bis_SR_register(SCG0);                  // Disable the FLL control loop                         //
    UCSCTL0 = 0x0000;                         // Set lowest possible DCOx, MODx                       //
    UCSCTL1 = DCORSEL_5;                      // Select DCO range 24MHz operation                     //
    UCSCTL2 = FLLD_1 + 374;                   // Set DCO Multiplier for 12MHz                         //
                                              // (N + 1) * FLLRef = Fdco                              //
                                              // (374 + 1) * 32768 = 12MHz                            //
                                              // Set FLL Div = fDCOCLK/2                              //
    __bic_SR_register(SCG0);                  // Enable the FLL control loop                          //
                                                                                                      //
    // Worst-case settling time for the DCO when the DCO range bits have been                         //
    // changed is n x 32 x 32 x f_MCLK / f_FLL_reference. See UCS chapter in 5xx                      //
    // UG for optimization.                                                                           //
    // 32 x 32 x 12 MHz / 32,768 Hz = 375000 = MCLK cycles for DCO to settle                          //
    __delay_cycles(375000);                                                                           //
	                                                                                              //
    // Loop until XT1,XT2 & DCO fault flag is cleared                                                 //
    do                                                                                                //
    {                                                                                                 //
      UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + DCOFFG);                                                     //
                               // Clear XT2,XT1,DCO fault flags                                       //
      SFRIFG1 &= ~OFIFG;       // Clear fault flags                                                   //
    }while (SFRIFG1&OFIFG);    // Test oscillator fault flag                                          //
	                       // UG for optimization.                                                //
                               // 32 x 32 x 8 MHz / 32,768 Hz = 250000 = MCLK cycles for DCO to settle//
    return CLK_12MHz;
  }                                                                                                   //
                                                                                                      //
                                                                                                      //
////////////////////////////////Clock 25Mhz ////////////////////////////////////////////////////////////
u32 Set_clk_Freq_25MHz(void)                                                                             //  
{                                                                                                     //  
  // Increase Vcore setting to level3 to support fsystem=25MHz                                        //  
  // NOTE: Change core voltage one level at a time..                                                  //  
  SetVcoreUp (0x01);                                                                                  //  
  SetVcoreUp (0x02);                                                                                  //  
  SetVcoreUp (0x03);                                                                                  //  
                                                                                                      //  
  UCSCTL3 = SELREF_2;                       // Set DCO FLL reference = REFO                           //  
  UCSCTL4 |= SELA_2;                        // Set ACLK = REFO                                        //  
                                                                                                      //  
  __bis_SR_register(SCG0);                  // Disable the FLL control loop                           //  
  UCSCTL0 = 0x0000;                         // Set lowest possible DCOx, MODx                         //  
  UCSCTL1 = DCORSEL_7;                      // Select DCO range 50MHz operation                       //  
  UCSCTL2 = FLLD_0 + 762;                   // Set DCO Multiplier for 25MHz                           //  
                                            // (N + 1) * FLLRef = Fdco                                //  
                                            // (762 + 1) * 32768 = 25MHz                              //  
                                            // Set FLL Div = fDCOCLK/2                                //  
  __bic_SR_register(SCG0);                  // Enable the FLL control loop                            //  
                                                                                                      //  
  // Worst-case settling time for the DCO when the DCO range bits have been                           //  
  // changed is n x 32 x 32 x f_MCLK / f_FLL_reference. See UCS chapter in 5xx                        //  
  // UG for optimization.                                                                             //  
  // 32 x 32 x 25 MHz / 32,768 Hz ~ 780k MCLK cycles for DCO to settle                                //  
  __delay_cycles(782000);                                                                             //  
                                                                                                      //  
  // Loop until XT1,XT2 & DCO stabilizes - In this case only DCO has to stabilize                     //  
  do                                                                                                  //  
  {                                                                                                   //  
    UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + DCOFFG);                                                       //  
                                            // Clear XT2,XT1,DCO fault flags                          //  
    SFRIFG1 &= ~OFIFG;                      // Clear fault flags                                      //  
  }while (SFRIFG1&OFIFG);                   // Test oscillator fault flag                             //
  UCSCTL4 = UCSCTL4&(~(SELS_7|SELM_7))|SELS_3|SELM_3;  
  return CLK_25MHz;
}                                                                                                     //  
//////////////////////Set core voltage//////////////////////////////////////////////////////////////////
void SetVcoreUp (unsigned int level)                                                                  //                  
{                                                                                                     //                  
  // Open PMM registers for write                                                                     //  
  PMMCTL0_H = PMMPW_H;                                                                                // 
  // Set SVS/SVM high side new level                                                                  // 
  SVSMHCTL = SVSHE + SVSHRVL0 * level + SVMHE + SVSMHRRL0 * level;                                    // 
  // Set SVM low side to new level                                                                    // 
  SVSMLCTL = SVSLE + SVMLE + SVSMLRRL0 * level;                                                       // 
  // Wait till SVM is settled                                                                         // 
  while ((PMMIFG & SVSMLDLYIFG) == 0);                                                                // 
  // Clear already set flags                                                                          // 
  PMMIFG &= ~(SVMLVLRIFG + SVMLIFG);                                                                  // 
  // Set VCore to new level                                                                           // 
  PMMCTL0_L = PMMCOREV0 * level;                                                                      // 
  // Wait till new level reached                                                                      // 
  if ((PMMIFG & SVMLIFG))                                                                             // 
    while ((PMMIFG & SVMLVLRIFG) == 0);                                                               // 
  // Set SVS/SVM low side to new level                                                                // 
  SVSMLCTL = SVSLE + SVSLRVL0 * level + SVMLE + SVSMLRRL0 * level;                                    // 
  // Lock PMM registers for write access                                                              // 
  PMMCTL0_H = 0x00;                                                                                   // 
}                                                                                                     // 
////////////////////////////////////////////////////////////////////////////////////////////////////////

void TestMCLK()
{
  P1SEL &= ~BIT1;  
  P1DIR |= BIT1;  
    
  P1SEL |= BIT0; //ACLK  
  P1DIR |= BIT0;  
  P2SEL |= BIT2; //SMCLK  
  P2DIR |= BIT2;  
  P7SEL |= BIT7; //MCLK  
  P7DIR |= BIT7;  
}

