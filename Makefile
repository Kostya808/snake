All: snake

snake: main.o function.o 
	g++ -Wall -o snake main.o function.o -lncurses 

main.o: main.cpp
	g++ -Wall -o main.o -c main.cpp

function.o: function.cpp
	g++ -Wall -o function.o -c function.cpp

clean:
	rm -rf *.o