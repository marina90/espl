all: char2

char2: char2.o
	gcc -m64 -g -Wall -o char2 char2.o 

char2.o:char2.c
	gcc -g -Wall -m64 -ansi -c -o char2.o char2.c 


PHONY:clean

clean:
	rm -f *.o char2

