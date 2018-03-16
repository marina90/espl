all: menu

menu: menu.o
	gcc -m64 -g -Wall -o menu menu.o 

menu.o:menu.c
	gcc -g -Wall -m64 -ansi -c -o menu.o menu.c 


PHONY:clean

clean:
	rm -f *.o menu

