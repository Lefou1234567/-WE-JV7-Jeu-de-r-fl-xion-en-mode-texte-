all: test.s
	echo "Compilation terminee"

test.s: test.o tools.o charray2D.o
	gcc test.o tools.o charray2D.o -o test.s

test.o: test.c tools.h charray2D.h
	gcc -c -O3 test.c

tools.o: tools.c tools.h
	gcc -c -O3 tools.c

charray2D.o: charray2D.c charray2D.h tools.h
	gcc -c -O3 charray2D.c

clean: 
	rm *~ ; rm .*~
