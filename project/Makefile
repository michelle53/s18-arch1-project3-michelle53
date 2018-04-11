COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as
AR		= msp430-elf-ar

all: game.elf 

#additional rules for files
game.elf: ${COMMON_OBJECTS} led.o gamecontrol.o p1_interrupt_handler.o  buzzer.o switches.o game.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lLcd -lp2sw -lTimer



load: game.elf
	mspdebug rf2500 "prog game.elf"

clean:
	rm -f *.o *.elf



