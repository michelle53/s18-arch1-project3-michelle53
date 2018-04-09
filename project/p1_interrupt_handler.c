
#include <msp430.h>
#include "switches.h"
//#include "stateMachines.h"
#include "buzzer.h"
//#include "led.h"


void __interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES) {	      /* did a button cause this interrupt? */
    P2IFG &= ~SWITCHES;		      /* clear pending sw interrupts */
  }
}


void __interrupt_vec(WDT_VECTOR) WDT(){
  static char blink_count = 0, decisecond_count_2 = 0, decisecond_count = 0;
  if(++decisecond_count == rateN) {
    buzzer_advance_frequency();
    decisecond_count = 0;
  }
}
