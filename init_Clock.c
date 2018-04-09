#include "io430.h"
#include "test.h"


//Function initialize clock frequency (posiible range of frequency from 2.5MHz)
//to 54.1 MHz. Clock frequency can be chosen with clk variable in range from 2500
//to 54000. Recommended clk values are 4000, 8000, 12000, 16000... (n*4000) ...52000, because 
//reference frequency equals to 32768 and this values gives no remainder. Other clk will give 
//approximated value of frequency



unsigned long clkHz = 0;
unsigned long cycles_delay =0;
unsigned int clk_multipl = 0;


void init_Clock(unsigned long clkKHz)
  {
    //P2DIR |= BIT2;                                              // with pin 2.2 can measure clock
    //P2SEL |= BIT2;
         
    UCSCTL3 = SELREF_2;                                         // Set DCO FLL reference = REFO
    UCSCTL4 |= SELA_2;                                          // Set ACLK = REFO
    UCSCTL0 = 0x0000;                                           // Set lowest possible DCOx, MODx

    clkHz = clkKHz*1024;
    clk_multipl = clkHz/32768;
    
    do
      {
        UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + DCOFFG);             // Clear XT2,XT1,DCO fault flags
        SFRIFG1 &= ~OFIFG;                                      // Clear fault flags
      }while (SFRIFG1&OFIFG);                                   // Test oscillator fault flag
	
    __bis_SR_register(SCG0);                                    // Disable the FLL control loop
    UCSCTL1 = DCORSEL_5;                                        // Select DCO range 16MHz operation
    UCSCTL2 |= clk_multipl - 1;                                             // Set DCO Multiplier for 8MHz
                                                                // (N + 1) * FLLRef = Fdco
                                                                // (249 + 1) * 32768 = 8MHz
    __bic_SR_register(SCG0);                                    // Enable the FLL control loop
    cycles_delay=clkHz/32;   
    __delay_cycles(250000);   //how to put cycles_delay         // Worst-case settling time for the DCO when the DCO range bits have been
                                                                // changed is n x 32 x 32 x f_MCLK / f_FLL_reference. See UCS chapter in 5xx
                                                                // UG for optimization.
                                                                // 32 x 32 x 8 MHz / 32,768 Hz = 250000 = MCLK cycles for DCO to settle
  }