all: clean task2a task2b task2c task3

task2a: task2a.o
	gcc -m64 -g -Wall -o task2a task2a.o 

task2a.o:task2a.c
	gcc -g -Wall -m64 -ansi -c -o task2a.o task2a.c 

task2b: task2b.o
	gcc -m64 -g -Wall -o task2b task2b.o 

task2b.o:task2b.c
	gcc -g -Wall -m64 -ansi -c -o task2b.o task2b.c
	
	
task2c: task2c.o
	gcc -m64 -g -Wall -o task2c task2c.o 

task2c.o:task2c.c
	gcc -g -Wall -m64 -ansi -c -o task2c.o task2c.c
	
	
task3: task3.o
	gcc -m64 -g -Wall -o task3 task3.o 

task3.o:task3.c
	gcc -g -Wall -m64 -ansi -c -o task3.o task3.c
	
	
PHONY:clean

clean:
	rm -f *.o clean task2a task2b task2c task3

 
