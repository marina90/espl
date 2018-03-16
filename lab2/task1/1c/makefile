all: 1c

1c: 1c.o
	gcc -m64 -g -Wall -o 1c 1c.o 

1c.o:1c.c
	gcc -g -Wall -m64 -ansi -c -o 1c.o 1c.c 


PHONY:clean

clean:
	rm -f *.o 1c

