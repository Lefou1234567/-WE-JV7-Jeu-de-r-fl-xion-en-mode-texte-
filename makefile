all: test.s
	echo "Compilation terminee"

test.s: test.o tools.o charray2D.o gGrid.o
	gcc test.o tools.o charray2D.o gGrid.o -o test.s

test.o: test.c tools.h charray2D.h gGrid.h
	gcc -c -O3 test.c

tools.o: tools.c tools.h
	gcc -c -O3 tools.c

charray2D.o: charray2D.c charray2D.h tools.h
	gcc -c -O3 charray2D.c

gGrid.o: gGrid.c gGrid.h tools.h charray2D.h
	gcc -c -O3 gGrid.c

clean: 
	rm *~ ; rm .*~
