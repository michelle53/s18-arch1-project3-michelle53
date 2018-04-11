#ifndef buzzer_included
#define buzzer_included


/*#define G 10204
#define A 9090
#define B 8099
#define C1 7644
#define D 6810
#define E 6067
#define F 5727
#define G2 5102
#define A2 4545
#define B2 4049
#define C2 3822
#define D2 3405
#define E2 3033
#define F2 2863
#define G3 2551
#define A3 2272
*/

/*int notesBA[] = {6067, 6067, 6067, 6067, 7644, 6810,  6067, 6067, 6067, 6067, 7644, 6810,  6067,6067, 6067, 6067, 7644, 6810,  6067, 6067, 5102, 6067, 6067, 6067, 6067, 7644, 6810, 6067, 6067, 6067, 6067, 7644, 6810, 6067, 6067, 6067, 6067, 7644, 6810,  4545, 5102, 4545, 5102, 6067, 5102,   6067, 5726, 5102, 4545,4049, 3033, 3214, 4049, 6067, 4049,4545, 5102, 5726, 6067, 5726, 5102, 4545, 4049, 4545, 5102, 6067, 5726, 5102, 5726, 6067, 7215, 5726, 6000, 5726, 5102, 4545, 4049, 3033, 3214, 4049, 6067};

int typeBA[] = { half, fourth, half, fourth, fourth, fourth,  half, fourth, half, fourth, fourth, fourth,  half, fourth, half, fourth, fourth, fourth, half, fourth, fourth,  half, fourth, half, fourth, fourth, fourth,  half, fourth, half, fourth, fourth, fourth,  half, fourth, half, fourth, fourth, fourth, half, half, half, half, half, half, half, half, half, half, one, half, half, one, one, half, half, half, half, half, half, half, half, one, half, half, half, half, half, half, half, half, half, half, half, half, half, half, one, half, half, one, one};
*/


void buzzer_init();
void buzzer_advance_frequency();
void buzzer_set_period(short cycle);

extern int rateN, current;

#endif // included
