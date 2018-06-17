start:
	gcc -Wall -g -c car.c -o car.o
	gcc -Wall -g -c main.c -o main.o
	gcc -Wall -g main.o car.o -lncurses -o main
	./main