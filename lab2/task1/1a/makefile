all: address

address: addresses.o
	gcc -m64 -g -Wall -o address addresses.o 

addresses.o:addresses.c
	gcc -g -Wall -m64 -ansi -c -o addresses.o addresses.c 


PHONY:clean

clean:
	rm -f *.o address

