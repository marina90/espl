all: my_echo


my_echo: my_echo.o
	gcc -g -m64 -Wall -o my_echo my_echo.o

# Depends on the source and header files
my_echo.o: my_echo
	gcc -m64 -g -Wall -ansi -c -o my_echo.o my_echo.c 

#tell make that "clean" is not a file name!
.PHONY: clean

#Clean the build directory
clean: 
	rm -f *.o my_echo