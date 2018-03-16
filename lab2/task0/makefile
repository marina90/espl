all: counter

counter: count_words.o
	gcc -m64 -g -Wall -o counter count_words.o 

count_words.o:count-words.c
	gcc -g -Wall -m64 -ansi -c -o count_words.o count-words.c 


PHONY:clean

clean:
	rm -f *.o counter

