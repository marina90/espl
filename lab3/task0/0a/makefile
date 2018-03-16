all: bubble

bubble: bubble.o
	gcc -m64 -g -Wall -o bubble bubble.o

bubble.o: bubblesort.c
	gcc -g -Wall -m64 -ansi -c -o bubble.o bubblesort.c


PHONY:clean

clean:
	rm -f *.o bubble
