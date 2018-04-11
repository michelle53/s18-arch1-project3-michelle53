
#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"
#include "switches.h"
#include "gamecontrol.h"
#include <lcdutils.h>
#include <lcddraw.h>
#include <stdio.h>
#include <stdlib.h>

//char *scoreC = "0";
//int score = 0;

void main(void){
  configureClocks();
  enableWDTInterrupts();
  switch_init();
  lcd_init();
  led_init();
  buzzer_init();
  or_sr(0x8);
  u_char width = screenWidth, height = screenHeight;
  u_int score = 0;
  int trueB = 1;
  clearScreen(COLOR_BLUE);

  drawString5x7(10,10, "Score ", COLOR_GREEN, COLOR_BLUE);

}
