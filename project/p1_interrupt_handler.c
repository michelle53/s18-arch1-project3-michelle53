
#include <msp430.h>
#include "switches.h"
//#include "stateMachines.h"
#include "buzzer.h"
//#include "led.h"
#include "gamecontrol.h"

void __interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES) {	      /* did a button cause this interrupt? */
    P2IFG &= ~SWITCHES;		      /* clear pending sw interrupts */
    //    switch_update_interrupt_sense();
  }
}


void __interrupt_vec(WDT_VECTOR) WDT(){
  static char blink_count = 0, decisecond_count_2 = 0, decisecond_count = 0;
  static char counts =0;

  if(++decisecond_count == rateN) {
    buzzer_advance_frequency();
    blink_rectangle();
    decisecond_count = 0;
    int i = 0;
    for(i = 0; i < 6000; i++);
    //    if(bt1) scoreC = (score++) + "0";
  }
 
}
