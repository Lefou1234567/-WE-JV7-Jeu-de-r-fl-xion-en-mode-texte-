all: test.s
	echo "Compilation terminee"

test.s: test.o
	gcc test.o -o test.s

test.o: test.c
	gcc -c -O3 test.c
