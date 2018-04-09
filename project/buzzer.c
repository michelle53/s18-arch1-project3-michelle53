#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "switches.h"
//#include "songs.h"
	
int rateN = 25;
int current = 0;
#define fourth 50
#define half 75
#define one  120

int notesBA[] = {6067, 6067, 6067, 6067, 7644, 6810,  6067, 6067, 6067, 6067, 7644, 6810,  6067,6067, 6067, 6067, 7644, 6810,  6067, 6067, 5102, 6067, 6067, 6067, 6067, 7644, 6810, 6067, 6067, 6067, 6067, 7644, 6810, 6067, 6067, 6067, 6067, 7644, 6810,  4545, 5102, 4545, 5102, 6067, 5102,   6067, 5726, 5102, 4545,4049, 3033, 3214, 4049, 6067, 4049,4545, 5102, 5726, 6067, 5726, 5102, 4545, 4049, 4545, 5102, 6067, 5726, 5102, 5726, 6067, 7215, 5726, 6000, 5726, 5102, 4545, 4049, 3033, 3214, 4049, 6067};

int typeBA[] = { half, fourth, half, fourth, fourth, fourth,  half, fourth, half, fourth, fourth, fourth,  half, fourth, half, fourth, fourth, fourth, half, fourth, fourth,  half, fourth, half, fourth, fourth, fourth,  half, fourth, half, fourth, fourth, fourth,  half, fourth, half, fourth, fourth, fourth, half, half, half, half, one, half, half, one, one, half, half, half, half, half, half, half, half, one, half, half, half, half, half, half, half, half, half, half, half, half, half, half, one, half, half, one, one};


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

    buzzer_advance_frequency();
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
  buzzer_set_period(notesBA[current]);
  rateN = typeBA[current];
  current++;
  //  if (current > 37) current = 0;
}

void buzzer_set_period(short cycles){
  CCR0 = cycles; 
  CCR1 = cycles >> 1;
}


    
    
  

