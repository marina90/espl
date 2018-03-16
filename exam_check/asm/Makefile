all: e2015_a_10

e2015_a_10: e2015_a_10.o
	ld -melf_i386 -o e2015_a_10 e2015_a_10.o -lc -I/lib/ld-linux.so.2

task3.o: task3.asm
	nasm -g -f elf -w+all -o task3.o task3.asm

funcA.o: funcA.asm
	nasm -g -f elf -w+all -o funcA.o funcA.asm

e2015_a_10.o: e2015_a_10.asm
	nasm -g -f elf -w+all -o  e2015_a_10.o e2015_a_10.asm


.PHONY: all clean
clean:
	rm -rf *.o task3
