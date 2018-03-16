all: lab0

lab0: numbers.o main.o add.o
	gcc -m64 -g -Wall -o lab0 numbers.o main.o add.o 

numbers.o:numbers.c
	gcc -g -Wall -m64 -ansi -c -o numbers.o numbers.c 

main.o:main.c
	gcc -g -Wall -m64 -ansi -c -o main.o main.c

add.o: add.s
	nasm -g -f elf -w+all -o add.o add.s

PHONY:clean

clean:
	rm -f *.o lab0

