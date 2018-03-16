all: e2013_a_10

menu: cksum.o
	gcc -m64 -g -Wall -o cksum cksum.o

cksum.o:cksum.c
	gcc -g -Wall -m64 -ansi -c -o cksum.o cksum.c

e2013_a_2: e2013_a_2.o
	gcc -m64 -g -Wall -o e2013_a_2 e2013_a_2.o

e2013_a_2.o:e2013_a_2.c
	gcc -g -Wall -m64 -ansi -c -o e2013_a_2.o e2013_a_2.c

e2013_a_8: e2013_a_8.o
	gcc -m64 -g -Wall -o e2013_a_8 e2013_a_8.o
e2013_a_8.o:e2013_a_8.c
	gcc -g -Wall -m64 -ansi -c -o e2013_a_8.o e2013_a_8.c

e2013_a_6: e2013_a_6.o
	gcc -m64 -g -Wall -o e2013_a_6 e2013_a_6.o
e2013_a_6.o:e2013_a_6.c
	gcc -g -Wall -m64 -ansi -c -o e2013_a_6.o e2013_a_6.c

e2031_a_4: e2031_a_4.o
	gcc -m64 -g -Wall -o e2031_a_4 e2031_a_4.o
e2031_a_4.o:e2031_a_4.c
	gcc -g -Wall -m64 -ansi -c -o e2031_a_4.o e2031_a_4.c

e2016_a_4: e2016_a_4.o
	gcc -m64 -g -Wall -o e2016_a_4 e2016_a_4.o
e2016_a_4.o:e2016_a_4.c
	gcc -g -Wall -m64 -ansi -c -o e2016_a_4.o e2016_a_4.c

e2013_a_10: e2013_a_10.o
		gcc -m64 -g -Wall -o e2013_a_10 e2013_a_10.o
e2013_a_10.o:e2013_a_10.c
		gcc -g -Wall -m64 -ansi -c -o e2013_a_10.o e2013_a_10.c


PHONY:clean


clean:
	rm -f *.o e2013_a_2 e2013_a_8 e2013_a_6 e2031_a_4 e2016_a_4 e2013_a_10
