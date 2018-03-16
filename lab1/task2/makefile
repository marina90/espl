all: char2ascii

char2ascii: char2ascii.o
	gcc -m64 -g -Wall -o char2ascii char2ascii.o 

char2ascii.o:char2ascii.c
	gcc -g -Wall -m64 -ansi -c -o char2ascii.o char2ascii.c 


PHONY:clean

clean:
	rm -f *.o char2ascii

