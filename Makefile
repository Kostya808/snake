All: snake

snake: main.o function.o 
	gcc -Wall -o snake main.o snake.o 

main.o: main.c
	gcc -Wall -o main.o -c main.c

function.o: function.c
	gcc -Wall -o function.o -c function.c

clean:
	rm -rf *.o