all: libPacman.a pacmandemo.elf

CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as
AR              = msp430-elf-ar

abPacman_decls.h abPacman.h chordVec.h libPacman.a: makePacmans.c abPacman.o  _abPacman.h Makefile 
	cc -o makePacmans makePacmans.c
	rm -rf pacmans; mkdir pacmans
	./makePacmans
	cat _abPacman.h abPacman_decls.h > abPacman.h
	(cd pacmans; $(CC) -I.. -I../../h -mmcu=${CPU} -Os -c *.c)
	$(AR) crs libPacman.a pacmans/*.o abPacman.o

abCircle.o: _abPacMan.h abPacman.c 

install: libPacman.a abPacman.h chordVec.h
	mkdir -p ../h ../lib
	cp libPacman.a ../lib
	cp abPacman.h chordVec.h ../h


clean:
	rm -f libPacman.a abPacman.h abPacman_decls.h chordVec.h *.o *.elf makePacmans
	rm -rf pacmans

pacmandemo.elf: pacmandemo.o libPacman.a
	$(CC) $(CFLAGS) $(LDFLAGS) $^  -lLcd -lTimer -lShape -o $@


load: pacmandemo.elf
	mspdebug rf2500 "prog $^"




