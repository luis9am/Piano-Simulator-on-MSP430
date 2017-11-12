#include <msp430.h>
#include "libTimer.h"
#include "switches.h"
#include "buzzer.h"

void buzzer_init()
{
    /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */

    //buzzer_set_period(1000);	/* start buzzing!!! */
    makeSounds();
}

void buzzer_set_period(short cycles)
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* one half cycle */
}

void makeSounds() {
    //buzzer_set_period(1117.67); //B0
    //buzzer_set_period(1580.63); //F0
    if(btn1){

        buzzer_set_period(1408.18); //G0

    }
    else if(btn2){

        buzzer_set_period(1879.69); //D0

    }
    else if(btn3){

        buzzer_set_period(1254.55); //A0

    }
    else if(btn4){

        buzzer_set_period(1674.62); //E0

    }
}
    
    
  

