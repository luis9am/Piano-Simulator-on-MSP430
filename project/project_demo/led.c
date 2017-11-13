#include <msp430.h>
#include "led.h"
#include "switches.h"


static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_update();
}

void led_update()
{
  if (switch_state_changed) {
    char ledFlags = 0; /* flags start at 0 */
    
    ledFlags ^= (switch_state_changed) ? LED_RED : 0;
    ledFlags ^= (switch_state_changed) ? 0 : LED_GREEN;
    
    P1OUT &= (0xff - LEDS) | ledFlags; // clear bit for off leds
    P1OUT ^= ledFlags;		     // set bit for on leds
  }
  switch_state_changed = 0;
}
