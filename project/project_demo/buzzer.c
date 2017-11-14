#include <msp430.h>
#include "libTimer.h"
#include "switches.h"
#include "buzzer.h"
#include "led.h"

double G, D, A, E, B;
double CC, FF;
int scale_count;

void buzzer_init()
{
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */

    scale_count = 0;
    set_notes();
    makeSounds();
}

void buzzer_set_period(short cycles)
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* one half cycle */
}

/* set initial note values */
void set_notes(){

  G = 1408.18; //G0
  D = 1879.69; //D0
  A = 1254.55; //A0
  E = 1674.62; //E0
  B = 1111.67; //B0
  CC = 2109.89; //C0
  FF = 1580.63; //F0

}

/* frequency notes are halved */
void downscale_notes(){

  G = G/2; //G(+1)
  D = D/2; //D(+1)
  A = A/2; //A(+1)
  E = E/2; //E(+1)
  B = B/2; //B(+1)
  CC = CC/2; //C(+1)
  FF = FF/2; //F(+1)

}


/* frequency notes are doubled */
void upscale_notes(){

  G = G*2; //G(+1)
  D = D*2; //D(+1)
  A = A*2; //A(+1)
  E = E*2; //E(+1)
  B = B*2; //B(+1)
  CC = CC*2; //C(+1)
  FF = FF*2; //F(+1)

}

void makeSounds() {

    /* sounds are played as btns are pressed */
    if(btn1){
      buzzer_set_period(G); //G
    }

    else if(btn2){
      buzzer_set_period(D); //D
    }

    else if(btn3){
      buzzer_set_period(A); //A
    }
    
    else if(btn4){
      buzzer_set_period(E); //E
    }

    /* adjacent btn (1&2, 2&3, 3&4) operations */
    if (btn1 && btn2){
        buzzer_set_period(B); //B
    }
    
    else if (btn2 && btn3){
        buzzer_set_period(CC); //C
    }
    
    else if (btn3 && btn4){
        buzzer_set_period(FF); //F
    }

    /* change frequency operations */
    if (btn1 && btn3){
      downscale_notes();
      makeSounds();
    }
    
    if(btn2 && btn4){
      upscale_notes();
      makeSounds();
    }
}
