all: func.o
	gcc func.o main.c -o crud ; rm -rf *.o

func.o: ./src/func.h
	gcc -c ./src/func.c

run: crud
	./crud
