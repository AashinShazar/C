 CC = gcc
 CFLAGS = -lncurses  -I$(IDIR) -std=c99 -Wall
 
 IDIR = ./include/
 SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c
  
 all: tracker run clean
 
 tracker: 
	$(CC) $(SOURCES) $(CFLAGS) -o $@ 
	
run: 
	./tracker ./assets/test.txt
	
clean:
	rm tracker
