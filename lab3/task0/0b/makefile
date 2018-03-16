all: hexaPrint

hexaPrint: hexaPrint.o
	gcc -m64 -g -Wall -o hexaPrint hexaPrint.o

hexaPrint.o: hexaPrint.c
	gcc -g -Wall -m64 -ansi -c -o hexaPrint.o hexaPrint.c


PHONY:clean

clean:
	rm -f *.o hexaPrint
