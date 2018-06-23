start:
	gcc -Wall -g -c car.c -o car.o
	gcc -Wall -g -c border.c -o border.o
	gcc -Wall -g -c game.c -o game.o
	gcc -Wall -g -c main.c -o main.o
	gcc -Wall -g main.o border.o car.o game.o -lncurses -o main
	rm *.o
	./main