#include <msp430.h>
#include <libTimer.h>
#include "buzzer.h"		/* for setPeriod */
#include "led.h"		/* for led_control() */
#include "switches.h"

int 
main() 
{
    configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
    switch_init();          /* Utilize switches */
    led_init();             /* Utilize led */
    buzzer_init();          /* Utilize buzzer */
    //enableWDTInterrupts();	/* enable wd timer */
    or_sr(0x18);		/* CPU off, GIE on */
}




