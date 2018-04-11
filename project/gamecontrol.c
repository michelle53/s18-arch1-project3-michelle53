#include <msp430.h>
#include "switches.h"
#include "led.h"
#include <lcdutils.h>
#include <lcddraw.h>
#include <stdio.h>
#include <stdlib.h>
#include "gamecontrol.h"

int score = 0;
void update_score(){
    score++;
    char scoreC[10];
    itoa(score, scoreC, 10);
    drawString5x7(20,20, scoreC, COLOR_GREEN, COLOR_BLUE);

}

void blink_rectangle(){
  fillRectangle(30, 30, 10, 10, COLOR_YELLOW);
  if(bt1){
    update_score();
    green_on = 1;
    red_on = 0;
    led_update();
  }
  //  clearScreen(COLOR_BLUE);
  int i = 0;
  for(i = 0; i < 6000; i++);
  fillRectangle(30, 30, 10, 10, COLOR_RED);
 if(bt1){
    update_score();
    green_on = 0;
    red_on = 1;
    led_update();
  }
 
}
