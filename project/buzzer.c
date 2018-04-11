
#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "switches.h"
//#include "songs.h"
	
int rateN = 25;
int current = 0;

#define F 25
#define H 50
#define O 75

/*int notesPP[] = {C2, G2, C2, G2, C2, D2, E2, D2, C2, G2, C2, G2, C2, D2, E2, D2, C2, G2, C2, G2, C2, D2, E2, D2, C2, G2, C2, G2, C2, D2, E2, D2, C2, C2, C2, C2, B2, G2, E2, B2, C2, C2, C2, C2, B2, C2, D2, 0, E2};
 */


int notesPP[] = {3822,5102,3822,5102,3822,3405,2551,4049,3822,5102,3822,5102,3822,3405,2551,4049,3822,5102,3822,5102,3822,3405,2551,4049,3822,5102,3822,5102,3822,3405,2551,4049,   0,3822,3822,3822,3822,4049,5102,6067,3405,3822,3822,3822,3822,4049,3822,3405,0,3033, 0,3822,3822,3822,3822,4049,5102,6067,3405,3822,3822,3822,3822,4049,3822,3405,0,3033};

int typePP[] = {H,F,H,F,H,H,H,O, H,F,H,F,H,H,H,O, H,F,H,F,H,H,H,O, H,F,H,F,H,H,H,O,    H,H,H,H,H,F,F,H,H,H,H,H,H,F,F,H,F,H, H,H,H,H,H,F,F,H,H,H,H,H,H,F,F,H,F,H};



void buzzer_init(){
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

    // buzzer_advance_frequency();
}

/*Plays little strange song*/
void buzzer_advance_frequency() { 
  /*  period += rate;
  if ((rate > 0 && (period > MAX_PERIOD)) ||
      (rate < 0 && (period < MIN_PERIOD))){
    rate = -rate;
    period += (rate << 1);
  }
  buzzer_set_period(period);
  
  */
  buzzer_set_period(notesPP[current]);
  rateN = typePP[current];
  current++;
  if (current > sizeof(notesPP)) current = 0;
}

void buzzer_set_period(short cycles){
  CCR0 = cycles; 
  CCR1 = cycles >> 1;
}


    
    
  

