#ifndef switches_included
#define switches_included

//checking LED
#define SW1 BIT0 //switch1 is p2.0
#define SW2 BIT1 //switch2 is p2.1
#define SW3 BIT2 //switch3 is p2.2
#define SW4 BIT3 //switch4 is p2.3 
#define SWITCHES (SW1 | SW2 | SW3 | SW4)


/*Checks if button is pressed*/
#define bt1 ((P2IN & SW1) != SW1) //for SW1
#define bt2 ((P2IN & SW2) != SW2) //for SW2
#define bt3 ((P2IN & SW3) != SW3) //for SW3
#define bt4 ((P2IN & SW4) != SW4) //for SW4

void switch_init();
//void update_score();

extern int stateS1, stateS2, stateS3, stateS4; //buzzer and led states
extern int dim; //dimness of leds
extern int score;
extern char *scoreC;

#endif // included
