bazinga:that.o
	gcc that.o
that.o:that.c
	gcc -c that.c
run:bazinga
	./a.out
