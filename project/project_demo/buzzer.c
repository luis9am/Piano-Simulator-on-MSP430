#include <msp430.h>
#include "libTimer.h"
#include "switches.h"
#include "buzzer.h"
#include "led.h"

void buzzer_init()
{
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

void makeSounds() { /* sounds are by string */
  
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
    else if (btn1 && btn2){

        buzzer_set_period(1117.67); //B0

    }
    else if (btn2 && btn3){

        buzzer_set_period(2109.89); //C0

    }
    else if (btn3 && btn4){

        buzzer_set_period(1580.63); //F0

    }
}
